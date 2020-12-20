import time


class MLFQ():
    def __init__(self):
        self.queue1 = RRQueue(quantum=4)
        self.queue2 = RRQueue(quantum=8)
        self.queue3 = FCFSQueue()

    def addTask(self, Task):
        self.queue1.enqueue(Task)

    def execuate(self):
        if(self.queue1.empty()):
            if (self.queue2.empty()):
                if (self.queue3.empty()):
                    return
                else:
                    self.queue3.execuate()
            else:
                task = self.queue2.execuate()
                if task:
                    self.queue3.enqueue(task)
        else:
            task = self.queue1.execuate()
            if task:
                self.queue2.enqueue(task)


class Task():
    def __init__(self, name, execuate_time):
        self.execuate_time = execuate_time
        self.name = name


class RRQueue():
    def __init__(self, quantum):
        self.items: Task = []
        self.quantum = quantum
        self.current_execuate_time = 0

    def enqueue(self, item: Task):
        self.items.append(item)

    def empty(self):
        return not len(self.items)

    def execuate(self):
        if self.empty():
            return
        current_item = self.items[0]
        current_item.execuate_time = current_item.execuate_time - 1
        if current_item.execuate_time == 0:
            self.current_execuate_time = 0
            print('Task {}, finished'.format(self.items[0].name))
            self.items.pop(0)
            return None

        self.current_execuate_time = self.current_execuate_time + 1
        if self.current_execuate_time == self.quantum:
            item = self.items[0]
            self.items.pop(0)
            self.current_execuate_time = 0
            return item

        return None


class FCFSQueue():
    def __init__(self):
        self.items: Task = []

    def enqueue(self, item: Task):
        self.items.append(item)

    def empty(self):
        return not len(self.items)

    def execuate(self):
        if self.empty():
            return
        current_item = self.items[0]
        current_item.execuate_time = current_item.execuate_time - 1
        if current_item.execuate_time == 0:
            print('Task {}, finished'.format(self.items[0].name))
            self.items.pop(0)


s = MLFQ()


def init_task():
    name = input("Enter Task Name: ")
    execuate_time = input("Enter task execuate time: ")
    s.addTask(Task(name, execuate_time))


if __name__ == '__main__':
    while(1):
        name = input("Enter Task Name(Enter 'end' to start scheduling): ")
        if name == 'end':
            break
        execuate_time = input("Enter task execuate time: ")
        s.addTask(Task(name, int(execuate_time)))

    while(1):
        time.sleep(0.5)
        s.execuate()

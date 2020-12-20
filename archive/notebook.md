## 代码结构：

原本的 pok 内核中支持 RMS 以及 Round Robin 调度算法，在作业中需要增加 EDF，FP 以及 Weighted Round Bobin 算法，主要修改文件是 kernel/core/sche.c 文件。

### EDF 调度算法：

```c
#ifdef POK_NEEDS_SCHED_EDF
uint32_t pok_sched_part_edf(const uint32_t index_low, const uint32_t index_high, const uint32_t prev_thread, const uint32_t current_thread) {
	uint32_t res;

	res = index_low;
	uint32_t current_earliest_deadline = POK_THREAD_MAX_DEADLINE; 
	uint32_t current_earliest_deadline_thread = res;

	do {
		if (pok_threads[res].deadline < current_earliest_deadline && pok_threads[res].state == POK_STATE_RUNNABLE) {
			current_earliest_deadline = pok_threads[res].deadline;
			current_earliest_deadline_thread = res;
		}
		res++;
	} while(res < index_high);

	res = current_earliest_deadline_thread;

	if ((res == index_low) && (pok_threads[res].state != POK_STATE_RUNNABLE)) {
		res = IDLE_THREAD;
	}

	return res;
}
#endif
```

自己定义了最大的 deadline 值，每次时钟周期调用该函数的时候都会遍历所有的线程找到能够运行而且 deadline 最近的去执行。

测试的时候将修改两个任务的 deadline， 第一个任务 deadline 改为 5000， 第二个任务 deadline 改为 3000，测试结果达到预期。 

![./img/edf.png](EDF 测试结果)

### FP 调度算法

```c
#ifdef POK_NEEDS_SCHED_FP
uint32_t pok_sched_part_fp(const uint32_t index_low, const uint32_t index_high, const uint32_t prev_thread, const uint32_t current_thread) {
	uint32_t res;

	res = index_low;
	uint32_t highest_priority_thread = res;
	uint32_t current_highest_priority = POK_THREAD_MAX_PRIORITY;

	do {
		if (pok_threads[res].priority < current_highest_priority && pok_threads[res].state == POK_STATE_RUNNABLE) {
			highest_priority_thread = res;
			current_highest_priority = pok_threads[res].priority;
		}
		res++;
	} while (res < index_high);

	res = highest_priority_thread;

	if ((res == index_low) && (pok_threads[res].state != POK_STATE_RUNNABLE)) {
		res = IDLE_THREAD;
	}

	return res;
}
#endif
```

POK 有自己定义的最大的优先级，在每次时钟周期调用这个函数的时候会比较所有线程找到优先级最高的线程去执行。

测试的时候修改两个任务的优先级，第一个改为42， 第二个改为22， 测试结果达到预期。

![./img/fp.png](FP 测试结果)

### WRR 调度算法

```c
#ifdef POK_NEEDS_SCHED_WRR
uint32_t pok_sched_part_wrr(const uint32_t index_low, const uint32_t index_high, const uint32_t prev_thread, const uint32_t current_thread) {
	uint32_t res;
	uint32_t from;
	from = prev_thread;

	if (current_thread == IDLE_THREAD) {
		res = prev_thread;
	} else {
		res = current_thread;
	}

	if ((pok_threads[current_thread].remaining_time_capacity > 0) && (pok_threads[current_thread].state == POK_STATE_RUNNABLE)){
		return current_thread;
	}

	res = index_low;
	uint32_t index = index_low;
	uint32_t total = 0;

	do {
		if (pok_threads[index].state != POK_STATE_RUNNABLE){
			continue;
		}
		pok_threads[index].current_weight = pok_threads[index].weight;
		total += pok_threads[index].weight;
		if (res == index_low || pok_threads[res].current_weight < pok_threads[index].current_weight) {
			res = index;
		}
		index++;
	} while (index < index_high);
	pok_threads[res].current_weight -= total;

	return res;
}
#endif
```

参考 nginx 使用的 WRR 调度算法。

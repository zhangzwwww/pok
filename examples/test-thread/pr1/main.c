/*
 *                               POK header
 * 
 * The following file is a part of the POK project. Any modification should
 * made according to the POK licence. You CANNOT use this file or a part of
 * this file is this part of a file for your own project
 *
 * For more information on the POK licence, please see our LICENCE FILE
 *
 * Please follow the coding guidelines described in doc/CODING_GUIDELINES
 *
 *                                      Copyright (c) 2007-2009 POK team 
 *
 * Created by julien on Thu Jan 15 23:34:13 2009 
 */

#include <libc/stdio.h>
#include <core/thread.h>
#include <core/partition.h>
#include <core/semaphore.h>
#include <types.h>
#include "activity.h"
uint8_t N = 4;
int main()
{
  N = 4;
  printf("\nEDF Testing in PR1: ");
  uint32_t tid;
  pok_ret_t ret;
  pok_thread_attr_t attr;

  // attr.priority = 42;
  // attr.period = 20;
  // attr.time_capacity = 5;
  attr.deadline = 100;
  attr.entry = t1;
  ret = pok_thread_create(&tid, &attr);

  attr.deadline = 20;
  attr.entry = t2;
  ret = pok_thread_create(&tid, &attr);

  attr.deadline = 60;
  attr.entry = t3;
  ret = pok_thread_create(&tid, &attr);

  pok_partition_set_mode(POK_PARTITION_MODE_NORMAL);
  pok_thread_wait_infinite();

  return (0);
}

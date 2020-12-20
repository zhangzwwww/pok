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

#include <core/thread.h>
#include <core/partition.h>
#include <types.h>
#include "activity.h"

int main()
{
  printf("\nWRR Testing in PR4: ");
  uint32_t tid;
  int ret;
  pok_thread_attr_t attr;

  attr.entry = t1_job;
  // attr.period = 20;
  // attr.deadline = 1000;
  // attr.time_capacity = 5;
  attr.weight = 4;
  ret = pok_thread_create(&tid, &attr);

  attr.weight = 3;
  attr.entry = t2_job;
  ret = pok_thread_create(&tid, &attr);

  attr.weight = 2;
  attr.entry = t3_job;
  ret = pok_thread_create(&tid, &attr);

  pok_partition_set_mode(POK_PARTITION_MODE_NORMAL);
  pok_thread_wait_infinite();

  return (1);
}

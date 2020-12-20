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

uint8_t sid;

int main ()
{
  uint8_t tid;
  pok_ret_t ret;
  pok_thread_attr_t     tattr;

<<<<<<< Updated upstream
  tattr.weight = 4;
=======
  ret = pok_sem_create(&sid , 0, 50, POK_SEMAPHORE_DISCIPLINE_FIFO);
  printf("[P1] pok_sem_create return=%d, mid=%d\n", ret, sid);

  tattr.weight = 2;
>>>>>>> Stashed changes
  tattr.entry = pinger_job;

  ret = pok_thread_create(&tid , &tattr);
  printf("[P1] pok_thread_create (1) return=%d\n", ret);

<<<<<<< Updated upstream
  tattr.weight = 3;
=======
  tattr.weight = 4;
>>>>>>> Stashed changes
  tattr.entry = pinger_job2;

  ret = pok_thread_create(&tid , &tattr);
  printf("[P1] pok_thread_create (2) return=%d\n", ret);

<<<<<<< Updated upstream
=======
  tattr.weight = 5;
  tattr.entry = pinger_job3;

  ret = pok_thread_create(&tid, &tattr);
  printf("[P1] pok_thread_create (3) return=%d\n", ret);


>>>>>>> Stashed changes
  pok_partition_set_mode (POK_PARTITION_MODE_NORMAL);
  pok_thread_wait_infinite ();

   return (0);
}

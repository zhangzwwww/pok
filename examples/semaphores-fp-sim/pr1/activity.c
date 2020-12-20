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
#include <core/semaphore.h>
#include <types.h>

extern uint8_t sid;
uint8_t val;
static int thread_num;

void* pinger_job ()
{
   pok_ret_t ret;
   for (int i = 0; i < 4; i++)
   {
      printf ("P1T1\n");
      pok_thread_sleep (50000);
   }
}

void* pinger_job2 ()
{
   pok_ret_t ret;
   for (int i = 0; i < 4; i++)
   {
      printf ("P1T2\n");
      pok_thread_sleep (50000);
   }
}

void* pinger_job3 () {
   pok_ret_t ret;
   for (int i = 0; i < 4; i++)
   {
      printf ("P1T3\n");
      pok_thread_sleep (50000);
   }
}

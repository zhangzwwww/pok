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
static const uint64_t sleep_val = 500000;
extern const uint8_t N;
void *t1_job()
{
   uint8_t i;
   for (i = 0; i < N; i++)
   {
      printf("T1 ");
      pok_thread_sleep(sleep_val);
   }
   return NULL;
}

void *t2_job()
{
   uint8_t i;
   for (i = 0; i < N; i++)
   {
      printf("T2 ");
      pok_thread_sleep(sleep_val);
   }
   return NULL;
}

void *t3_job()
{
   uint8_t i;
   for (i = 0; i < N; i++)
   {
      printf("T3 ");
      pok_thread_sleep(sleep_val);
   }
   return NULL;
}

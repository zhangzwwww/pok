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
const uint64_t sleep_val = 50000;
static const int n = 3;
void *t1_job()
{
   int i;
   for (i = 0; 1; i++)
   {
      printf("A ");
      pok_thread_sleep(sleep_val);
   }
   return NULL;
}

void *t2_job()
{
   int i;
   for (i = 0; 1; i++)
   {
      printf("B ");
      pok_thread_sleep(sleep_val);
   }
   return NULL;
}

void *t3_job()
{
   int i;
   for (i = 0; 1; i++)
   {
      printf("C ");
      pok_thread_sleep(sleep_val);
   }
   return NULL;
}

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
<<<<<<< Updated upstream
=======
uint8_t thread_num = 0;
>>>>>>> Stashed changes

void* pinger_job ()
{
      for (int i = 0; i < 5; i++){
<<<<<<< Updated upstream
     	 printf ("P1T1");
=======
     	 printf ("T1\n");
>>>>>>> Stashed changes
      	 pok_thread_sleep (50000);
      }
}

void* pinger_job2 ()
{
	for (int i = 0; i < 5; i++) {
<<<<<<< Updated upstream
      printf ("P1T2");
      pok_thread_sleep (50000);
}
}
=======
      printf ("T2\n");
      pok_thread_sleep (50000);
}
}
void* pinger_job3 ()
{
	for (int i = 0; i < 5; i++) {
      printf ("T3\n");
      pok_thread_sleep (50000);
}
}

>>>>>>> Stashed changes

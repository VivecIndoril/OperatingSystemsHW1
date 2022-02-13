/**
 *
 * Operating System Concepts
 * Copyright John Wiley & Sons, 2013.
 */

#include "pid.h"
#include <pthread.h>
#include <stdio.h>

/**
 * Allocates the pid map.
 */
int allocate_map(void) 
{
	//for loop to initialize the pid_map array to be all 0's rather than empty
	for(int i=0; i<=PID_MAX-PID_MIN; i++)
	{
		pid_map[i]=0;
	}
	//conditional to check for successful full generation of pid_map array
	if(pid_map[PID_MAX-PID_MIN] == 0)
	{
		//upon verification of successful full gen., initialize last pid in use to 0
		last=0;
		return 1;
	}
	else
	{
		return -1;
	}

}

/**
 * Allocates a pid
 */
int allocate_pid(void)
{
	
	for(int i=0; i<=PID_MAX-PID_MIN; i++)
	{
		if(pid_map[i]!=1)
		{
			pid_map[i]=1;
			last=i+PID_MIN;
			return last;
		}
	}
	return -1;

}

/**
 * Releases a pid
 */
void release_pid(int pid)
{
	//set pid to 0 at given pid_map index while accounting for index offset caused by PID_MIN being 300 rather than 0
	pid_map[pid-PID_MIN]=0;
}

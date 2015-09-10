//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Gary Muller
// Fall 2015
// CS 420 Assignment 1
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//A program that will spawn three child processes, print out the Parent and Child PIDs
//it will utilize fork() and execv() to spawn the processes 
//specific implementations mean that this code will likely only run on RHEL
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Header files - Standard libraries and classes
#include <unistd.h>
#include <stdio.h>
//

//Global Variables and Defines
#define SPAWN_PROCESS_NAME "child2replacement.exe"
//



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//Main Declaration
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argv, char* argc[])
{
	//create variables
	pid_t childPID = 0;
	pid_t parentPID = getpid();
	int childCount;

	//for loop to create 
	for (childCount = 0; childCount < 3; childCount++)
	{
		childPID = fork();

		if (childPID == 0)
		{
			printf("I am child #%d, my pid is %l; my parent's pid is %l\n", childCount+1, getpid(), parentPID); //print the statement that it is a child and the PID
			if (childCount != 1)
			{
				execv(SPAWN_PROCESS_NAME, NULL); //if its process two replace the process with the execv() command
			}
			
		}
		else if (childPID > 0)
		{
			printf("Parent, my pid is %l: Spawned child #%d whose pid is %l\n", parentPID, childCount+1, childPID);//print the statement that it is a parent and the PID
			childPID = 0;
		}
		else(childPID < 0)
		{
			printf("oops");
		}
	}


}




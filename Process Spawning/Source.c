//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Gary Muller
// Fall 2015
// CS 420 Assignment 1
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//A program that will spawn three child processes, print out the Parent and Child PIDs
//it will utilize fork() and execl() to spawn the processes 
//specific implementations mean that this code will likely only run on RHEL
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Header files - Standard libraries and classes
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
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
	//pid_t parentPID = getpid();
	int childCount;

	//for loop to create child processes
	for (childCount = 1; childCount <= 3; childCount++)
	{
		childPID = fork();//statement to create child process

		if (childPID == 0)//if child process
		{
			printf("\tI am child #%d, my pid is %d; my parent's pid is %d\n", childCount, getpid(), getppid()); //print the statement that it is a child and the PID
			if (childCount == 2)//if this is child two(2) replace it 
			{
				execl(SPAWN_PROCESS_NAME, NULL); //if its process two replace the process with the execv() command
			}//if for child 2 replace
			
			childCount = 4;
		}//if child
		else if (childPID > 0)//if parent process
		{
			printf("Parent, my pid is %d: Spawned child #%d whose pid is %d\n", getpid(), childCount, childPID);//print the statement that it is a parent and the PID
			childPID = 0; //reset PID to 0 so next child spawned doesnt think its a parent
		}//elseif
		else if (childPID < 0)//if there is an error in process creation of the child
		{
			printf("oops");
		}//else

	}//for

	return 1;
}//main




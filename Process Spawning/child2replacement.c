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
//Child 2 Replacement Code 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Header files - Standard libraries and classes
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
//



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//Main Declaration
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(int argv, char* argc[])
{
	printf("\t\nProcess #%d, now running program \"child2Replacement.exe\"\n", getpid());//print out the PID of the process after using execv()

	return 1;
}
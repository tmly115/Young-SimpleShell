/* 
 * ---------------------------------------------------------------------------
 * Simple Shell shell_commands.h
 * 2019 (c) Thomas Young
 * --------------------------------------------------------------------------- 
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Displays a help message listing the built-in shell commands */

void shell_help(void){
	printf("--SimpleShell Help--\n");
	printf("Command:\tWhat it does:\n");
	printf("goto\t\tChanges the shell's directory or folder	to that specified.\n\t\tTakes one argument which is file path.\n");
	printf("wai\t\tAKA Where am I. Displays the current location of the shell\n\t\tin the filesystem. Takes no arguments.\n");
	printf("exit\t\tExit's the shell.\n");
	printf("help\t\tDisplays this  help message on the built-in commands.\n");
}

void shell_goto(char **args){
	if(args[1] == NULL){
		printf("No path specified\n");
		return;
	}
	else if(chdir(args[1]) != 0){
		printf("Failed to navigate to path: %s\n", args[1]);
	}
}

char* shell_wai(){
	char *location = (char*) malloc(FILENAME_MAX +1);;
	getcwd(location, FILENAME_MAX);
	return location;
}


void shell_exit(void){
	printf("------------------------------------------------------------\n");
	exit(0);
}

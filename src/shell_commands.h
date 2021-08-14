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

#define HELPTMSG 4

void shell_help(void){
	char const *command_whatis[HELPTMSG] = {
		"goto\t\t Changes the shell's directory or folder to that specified.\n\t\t Takes one argument which is file path.\n",
		"wai\t\t AKA Where am I. Displays the current location of the shell\n\t\t in the filesystem. Takes no arguments.\n",
		"exit\t\t Exit's the shell.\n",
		"help\t\t Displays this help message on the built-in commands.\n"
	};

	printf("Command\t- Description:\n");

	int i;
	for(i = 0;i < HELPTMSG;i++) printf("%s",command_whatis[i]);
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

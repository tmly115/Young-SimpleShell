/* 
 * ---------------------------------------------------------------------------
 * Simple Shell main.c
 * 2019 (c) Thomas Young
 * --------------------------------------------------------------------------- 
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

int dir_on_prompt = 0;
/* Function declarations for shell_config.h */

void generate_new_config_file(void);
int config_shell(void);

/* Function declarations for main.c */

char **change_args(char **args);
void simpleshell(void);
int shell_process_line(char **args);
int execute(char **args);
char **readline(void);

#include "shell_commands.h"
#include "shell_config.h"

#define VERSION_NUMBER "0.1.1"
#define MAX_ARGS 64
#define MAX_COMMAND_LENGTH 4096

/* Calls the main shell Function */

 int main(void){
	
	simpleshell();

	return 0;
}	 

/* Loops the input and process function indefinetly*/

void simpleshell(void){
	
	printf("Simple Shell. Version: %s. Thomas Young (c) 2019\n", VERSION_NUMBER);
	printf("A Young Enterprise Application.\n");

	config_shell();

	char **args;

	while(1){

		if(dir_on_prompt){
			printf("%s ", shell_wai());
		}
		printf(">");

		args = readline();
		if(args == NULL){
			continue;  
		}
		else{

			/* If realine fails it returns a 1 in the first entry of args */
			
			if(strcmp(args[0], "1") == 0){
				continue;
			} 
			else {
				shell_process_line(args);
			}

			free(args);
		}
	}
}

/* Checks to see if the user specified a shell command, if so it is executed with the arguments being passed
 * to the function, if not, it is passed to a fucntion that will look for and then execute programs */

int shell_process_line(char **args){

		if(strcmp(args[0], "help") == 0){
			shell_help();
		}
		else if(strcmp(args[0], "goto") == 0){
			shell_goto(args);
		} 
		else if(strcmp(args[0], "wai") == 0){
			printf("%s\n", shell_wai());
		} 
		else if(strcmp(args[0], "exit") == 0){
			shell_exit();
		}
		else {
			if(execute(args) != 0){
				exit(1);
			}	
		}
	return 0;
}

/* Moves the arguments forward so it can be passed to function run to execute with the correct 
 * program arguments */

char **change_args(char **args){
	if (*args == NULL){
		return args;
	}
	else{
		return args + 1;
	}
}

int execute(char **args){

	pid_t pid = fork();
	if(pid < 0){
		printf("ssl: Failed to fork to execute program. I'm afraid it's all over...\n");
		return 0;
	} else if(pid == 0){ /*Is child process*/
		if(execvp(args[0], args) == -1){
			printf("ssl: Couldn't execute program\n");
			exit(0);
		}
	}

	wait(NULL);

	return 0;
}

char **readline(void){

	char **args = malloc(64 * sizeof(char *));
	char command[MAX_COMMAND_LENGTH];

	char c;

	int count = 0;

	while(1){
		
		c = getchar();

		if( c == '\n' && (count < 1) ){
			return NULL;

		} else if(c == '\n'){
			command[count] = '\0'; 
			break;

		} else if(c == EOF){
			printf("exit\n");
			shell_exit();

		} else if(count >= MAX_COMMAND_LENGTH){
			printf("Oh no! The shell can only take commands up to 4096 characters long!\n");
			args[0] = "1";
			return args;
		
		} else {
			command[count] = c;
		}
		count++;
	}
	
	count = 0;

	char *argument = strtok(command, " ");

	while(argument != NULL && count < MAX_ARGS - 1){
		args[count] = argument;
		argument = strtok(NULL, " "); 
		count++;
	}
	args[count] = NULL;

	return args;
}
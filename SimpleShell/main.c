#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <string.h>

void simpleshell(void);

char *processline(char *line);
char **readline(void);

void shell_execute(char **args);

void shell_help(void);
void shell_goto(char **args);
void shell_wai(void);


 int main(void){
	
	simpleshell();

	return EXIT_SUCCESS;
}	 

void simpleshell(void){
	
	printf("Simple Shell. Build: DEV. Thomas Young (c) 2019\n");
	printf("A Young Enterprise Application.\n");

	int i = 0;
	char *command;
	char **args;

	while(1){
		printf(">");
		args = readline();
		if(args[0] == NULL){
			continue;
		}			

		if(strcmp(args[0], "help") == 0){
			shell_help();

		} else if(strcmp(args[0], "goto") == 0){
			shell_goto(args);
		} else if(strcmp(args[0], "wai") == 0){
			shell_wai();
		}
	}
	return;
}

void shell_help(void){
	printf("--SimpleShell Help--\n");
	printf("Command:\tWhat it does:\n");
	printf("goto\t\tChanges the shell's directory or folder	to that specified, takes one argument which is file path.\n");
	printf("wai\t\tAKA Where am I. Displays the current location of the shell in the filesystem, takes no arguments.\n");
	printf("run\t\tExecutes a given program, takes one argument which is the path to this.\n");
	printf("help\t\tDisplays this text on the basic built-in commands of SimpleShell.\n");
	return;
}

void shell_execute(char **args){


	return;
}

void shell_goto(char **args){
	if(args[1] == NULL) {
		printf("goto: ERROR, no file path specified...\n");
	} else if(chdir(args[1]) != 0){
		printf("Failed to navigate to path: %s\n", args[1]);
	}
	return;
}

void shell_wai(void){
	char location[255];
	getcwd(location, sizeof(location));
	printf("Current Location: %s\n", location);
	return;
}

char **readline(void){
	char **args = malloc(32 * sizeof(char *));
	char *command;	

	char c;
	char buffer[1024];

	int count = 0;

	while(1){
		
		c = getchar();
		
		if(c == EOF || c == '\n'){
			buffer[count] = '\0';
			command = buffer; 
			break;

		} else if(count > 1023){
			printf("Oh no! The shell can only take commands up to 1024 characters long!\n");
			return ;
		
		} else {
			buffer[count] = c;
		}
		count++;
	}
	
	count = 0;

	char *argument = strtok(command, " ");

	while(argument != NULL){
		args[count] = argument;
		argument = strtok(NULL, " "); 
		count++;
	
	}
	args[count] = NULL;
	return args;
}	

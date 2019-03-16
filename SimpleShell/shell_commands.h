/* 
 * ---------------------------------------------------------------------------
 * Simple Shell shell_commands.h
 * 2019 (c) Thomas Young
 * --------------------------------------------------------------------------- 
 */

/* Displays a help message listing the built-in shell commands */

void shell_help(void){
	printf("--SimpleShell Help--\n");
	printf("Command:\tWhat it does:\n");
	printf("goto\t\tChanges the shell's directory or folder	to that specified.\n\t\tTakes one argument which is file path.\n");
	printf("wai\t\tAKA Where am I. Displays the current location of the shell\n\t\tin the filesystem. Takes no arguments.\n");
	printf("run\t\tExecutes a given program, takes one argument which is the\n\t\tpath to the program to be executed.\n");
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

void shell_wai(void){
	char *location;
	getcwd(location, sizeof(location));
	printf("Current Location: %s\n", location);
}

/* Executes the program appending the path infront so it can be executed by excvp() */

int shell_run(char **args){

	args = change_args(args);

	pid_t pid = fork();
	if(pid < 0){
		printf("ssl: Failed to fork to execute program. I'm afraid it's all over...\n");
		return 0;
	} else if(pid == 0){		//Is child process
		if(execv(args[0], args) == -1){
			printf("ssl: Couldn't execute program\n");
		}
	}

	wait(NULL);

	return 0;
}

void shell_exit(void){
	printf("------------------------------------------------------------\n");
	exit(0);
}
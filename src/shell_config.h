/* 
 * ---------------------------------------------------------------------------
 * Simple Shell shell_config.h
 * 2019 (c) Thomas Young
 * --------------------------------------------------------------------------- 
 */

#include <stdio.h>
#include <stdlib.h>

#define CONFIG_PATH "config.cfg"
#define MAX_FILE_LINE_LENGTH 64

/* Generate's the config file if one is not present */

void generate_new_config_file(void){

	FILE *fp = fopen(CONFIG_PATH, "w");

	fprintf(fp, "mod = false\n");
	fprintf(fp, "mod_text = esl\n");
	fprintf(fp, "shell_prompt = default\n");

	fclose(fp);
}

/* Read's the a line of the file and store's it in a char array on the heep */

char *read_file_line(FILE *fp){

	char *file_line;
	char c;

	int count;

	while(1){

	}
}

/* Read's and seperate's 6each line of the config file so it can be parsed by the program */

void process_file(FILE *fp){
	
}

/* Load's data from the config file and change's the shell's charectoristics accordingly */

int config_shell(void){
	
	FILE *fp = fopen(CONFIG_PATH, "r");

	if(fp == NULL){
		printf("ssl: Config file not found, generating new one...\n");
		fclose(fp);
		generate_new_config_file();
		return 0;
	}

	fclose(fp);

	return 0;
}
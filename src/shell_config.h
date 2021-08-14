/* 
 * ---------------------------------------------------------------------------
 * Simple Shell shell_config.h
 * 2019 (c) Thomas Young
 * --------------------------------------------------------------------------- 
 */

#include <stdio.h>
#include <stdlib.h>
#include <libconfig.h>

/*
Please visit the next website for more information

https://iq.opengenus.org/detect-operating-system-in-c/
*/
#ifdef __linux__
  #define CONFIG_PATH "/opt/yss/config.cfg"
/*
#elif _WIN32
	#define CONFIG_PATH "C:/..."
#elif BSD 
	#define CONFIG_PATH "/..."
#elif _POSIX_VERSION
	#define CONFIG_PATH "directory"
*/ /*etc..*/
#endif

static config_t config_file;

/* Generate's the config file if one is not present */
void config_file_init(void){

	config_init(&config_file);
	
	/*If config read causes an error*/
	if(!config_read_file(&config_file, CONFIG_PATH)){

		fprintf(stderr, "%s:%d - %s\n", config_error_file(&config_file),
            config_error_line(&config_file), config_error_text(&config_file));

		config_destroy(&config_file);
	}

}

/* Get's the configurations of respective settings from CONFIG_PATH */
int config_shell(void){

	config_file_init();

	/*Just an idea of how we would get the respective settings. Could use an array in the future*/
	config_setting_t *dir_on_prompt_setting = config_lookup(&config_file, "dir_on_prompt");

	/*Asigns the bool setting to global variable*/
	dir_on_prompt = config_setting_get_bool(dir_on_prompt_setting);
	
	/*To avoid memory leak*/
	config_destroy(&config_file);
}

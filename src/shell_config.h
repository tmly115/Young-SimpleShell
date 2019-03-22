/* 
 * ---------------------------------------------------------------------------
 * Simple Shell shell_config.h
 * 2019 (c) Thomas Young
 * --------------------------------------------------------------------------- 
 */

#include <stdio.h>
#include <stdlib.h>
#include <libconfig.h>

#define CONFIG_PATH "config.cfg"

static config_t *config_file;

/* Generate's the config file if one is not present */
void generate_new_config_file(void){
	
	//If config read causes an error,  && because file doesn't exist (I/O error)
	if(!config_read_file(config_file,CONFIG_PATH) && config_error_type(config_file)==1){

		printf("Configuration file does not exist, creating default config file\n");
		//initialize object
		config_init(config_file);
		//config_write_file() (to write initial configuration)
	}

}

/* Get's the configurations of respective settings from CONFIG_PATH */
int config_shell(void){

	generate_new_config_file();

	//Just an idea of how we would get the respective settings. Could use an array in the future
	config_setting_t *mod_setting=config_lookup(config_file,"mod");
	config_setting_t *mod_text_setting=config_lookup(config_file,"mod_text");
	config_setting_t *shell_prompt_setting=config_lookup(config_file,"shell_prompt");

	////Uncomment to print values
	//printf("Mod value is %d\n",config_setting_get_bool(mod_setting));
	//printf("Mod text value is %s\n",config_setting_get_string(mod_text_setting));
	//printf("Shell prompt value is %s\n",config_setting_get_string(shell_prompt_setting));
	
	//To avoid memory leak
	config_destroy(config_file);

}

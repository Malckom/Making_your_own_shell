#ifndef HEADER_FILE
#define HEADER_FILE
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

typedef struct custom_args
{
	char *lineptr_cpy;
	char **argv;
} custom_args;
/**
 * struct env_var - structure to hold environment variables
 * @key: pointer to hold the variable name
 * @value: pointer to hold the variable value
 *
 */

typedef struct env_var
{
	char *key;
	char *value;
} env_var;

/**
 * struct Command - structure to store command with it's
 *	corresponding handler function
 * @command: pointer to the command
 * @handler: function pointer to handle the command
 */
void bring_line(char **lineptr, size_t *n, char *buffer, size_t j);
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);
typedef struct Command
{
	char *command;
	void (*handler)(char **);

} Command;

extern char **environ;

void print_env(char **env);
env_var *get_env(char *variable);
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);
/*lists*/
typedef struct sep_list_s
{
	char separator;
	struct sep_list_s *next;
} sep_list;

typedef struct line_list_s
{
	char *line;
	struct line_list_s *next;
} line_list;

typedef struct r_var_list
{
	int len_var;
	char *val;
	int len_val;
	struct r_var_list *next;
} r_var;
sep_list *add_sep_node_end(sep_list **head, char sep);
void free_sep_list(sep_list **head);
line_list *add_line_node_end(line_list **head, char *line);
void free_line_list(line_list **head);
r_var *add_rvar_node(r_var **head, int lvar, char *val, int lval);
void free_rvar_list(r_var **head);
/* argv_handler.c */
int get_argument_count(char **argv);
custom_args *init_argv(char *lineptr);

char *str_tok(char *str, char *delim);

/* get_callback.c */
void (*get_callback(char *command))(char **);

/* command_handler.c */
char *execute_set_env(char **argv);
void handle_exit(custom_args *, env_var *, char *, int *);
void check_for_exit(custom_args *argv, env_var *path,
		char *lineptr, int *exit_status);

char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, const char *src);
int _strlen(const char *s);
char *_strdup(const char *str);
char *_memcpy(char *dest, const char *src, unsigned int n);
int _atoi(char *s);
int _strcmp(char *s1, char *s2);
char *get_line_number(void);
void *_realloc(void *ptr, size_t size);
void print_err(char *program_name);
void _itoa(int n, char *str, int base);
void free_struct(custom_args *argv, env_var *path);
void signal_handler(int signum);
char *find_path(char *path_cpy, env_var *var, char *filename);
char *find_executable(env_var *var, char *filename);

void change_directory(char **argv);
void free_resources(env_var *path, custom_args *argv);
int _setenv(const char *name, const char *value, int overwrit);
int _unsetenv(const char *name);

/*memory_functions.c */
void free_argv(custom_args *argv);
/*
char *copy_info(char *name, char *value);
void set_env(char *name, char *value, custom_args *custom);
int _setenv(custom_args *custom);
int _unsetenv(custom_args *custom);
*/
/*
void _alias(custom_params *params);
void set_alias(char *name, custom_params *params);
void make_alias(char *name, char *val, custom_params *params);
void print_alias(char *name, custom_params *params);
void print_all_aliases(custom_params *params);
void print_list_alias(list_t *head);
*/

#endif

#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <limits.h>

/* Read/Write Buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* Command chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* Convert_number() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* 1 if using System getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;


/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 * struct passinfo - pseudo-argument to pass into a function
 * which allows uniform prototype for function pointer struct
 * @arg: string generated from getline containing arguments
 * @argv: array of strings generated from arg
 * @argc: argument count
 * @path: string path for the current command
 * @line_count: the error count
 * @err_num: error code for exit()
 * @linecount_flag: if on count this line of input
 * @fname: program filename
 * @env: linked list local copy of environ
 * @environ: custom modified copy of environ from LL env
 * @alias: alias node
 * @history: history node
 * @status: return status of the last executed command
 * @env_changed: on if environ was changed
 * @cmd_buf_type: CMD_type ||, &&, ;
 * @cmd_buf: address of pointer to cmd_buf, on if chaining
 * @histcount: history line number count
 * @readfd: fd from which to read line input
*/
typedef struct passinfo
{
	char *arg;
	char *path;
	char *fname;
	char **argv;
	char **environ;
	unsigned int line_count;
	int argc;
	int err_num;
	int status;
	int linecount_flag;
	int env_changed;
	list_t *env;
	list_t *history;
	list_t *alias;

	char **cmd_buf; /* pointer to CMD ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int histcount;
	int readfd;	
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}

/**
 * struct builtin - builtin string and related function
 * @type: builtin command flag
 * @func: function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;


/* toem_s_loop.c */
int find_builtin(info_t *);
int hsh(info_t *, char **);
void find_cmd(info_t *);
void fork_cmd(info_t *);

/* toem_s_parser.c */
char *find_path(info_t *, char *, char *);
char *dup_chars(char *, int, int);
int is_cmd(info_t *, char *);

/* loophsh.c */
int loophsh(char **);

/* toem_s_errors.c */
void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

/* toem_s_string.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

/* toem_s_string1.c */
char *_strcpy(char *, char *);
char *_strdup(const char *);
int _putchar(char);
void _puts(char *);

/* toem_s_exits.c */
char *_strchr(char *, char);
char *_strncat(char *, char *, int);
char *_strncpy(char *, char *, int);

/* toem_s_tokenizer.c */
char **strtow(char *, char *);
char **strtow2(char *, char);

/* toem_s_realloc.c */
char *_memset(char *, char, unsigned int);
void *_realloc(void *, unsigned int, unsigned int);
void ffree(char **);

/* toem_memory.c */
int bfree(void **);

/* toem_atoi.c */
int _atoi(char *);
int _isalpha(int);
int interactive(info_t *);
int is_delim(char, char *);

/* toem_s_errors1.c */
int _erratoi(char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void print_error(info_t *, char *);
void remove_comments(char *);

/* toem_s_builtin.c */
int _mycd(info_t *);
int _myexit(info_t *);
int _myhelp(info_t *);

/* toem_s_builtin1.c */
int _myalias(info_t *);
int _myhistory(info_t *);

/*toem_s_getline.c */
int _getline(info_t *, char **, size_t *);
ssize_t get_input(info_t *);
void sigintHandler(int);

/* toem_s_getinfo.c */
void clear_info(info_t *);
void free_info(info_t *, int);
void set_info(info_t *, char **);

/* toem_s_environ.c */
char *_getenv(info_t *, const char *);
int _myunsetenv(info_t *);
int _myenv(info_t *);
int _mysetenv(info_t *);
int populate_env_list(info_t *);

/* toem_s_getenv.c */
char **get_environ(info_t *);
int _setenv(info_t *, char *, char *);
int _unsetenv(info_t *, char *);

/* toem_s_history.c */
char *get_history_file(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);
int renumber_history(info_t *info);
int read_history(info_t *info);
int write_history(info_t *info);

/* toem_s_lists.c */
int delete_node_at_index(list_t **, unsigned int);
list_t *add_node_end(list_t **, const char *, int);
list_t *add_node(list_t **, const char *, int);
size_t print_list_str(const list_t *);
void free_list(list_t **);

/* toem_s_lists1.c */
char **list_to_strings(list_t *);
list_t *node_starts_with(list_t *, char *, char);
size_t list_len(const list_t *);
size_t print_list(const list_t *);
ssize_t get_node_index(list_t *, list_t *);

/* toem_s_vars.c */
int replace_vars(info_t *);
int is_chain(info_t *, char *, size_t *);
int replace_string(char **, char *);
int replace_alias(info_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);

#endif


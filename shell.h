#ifndef HEADER_H
#define HEADER_H

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}

extern char **environ;

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;


typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} info_t;

int intactive(info_t *);
int s_delim(char, char *);
int isalpha(int);
int atoi(char *);
/*5-shell*/
int erra_toi(char *);
void printerror(info_t *, char *);
int fprint_d(int, int);
char *convert_numb(long int, int, int);
void remove_com(char *);

/*6-shell*/

char **getstr_environ(info_t *);
int _rmunsetenv(info_t *, char *);
int _setenvmd(info_t *, char *, char *);

/*7-shell*/

list_t *add_node(list_t **, const char *, int);
list_t *addnode_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int dlte_node_at_index(list_t **, unsigned int);
void freeall_list(list_t **);
/*8-shell*/
size_t list_len(const list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);

/*9-shell*/
int _strlen(char *);
int _strcmp(char *, char *);
char *startswith(const char *, const char *);
char *_strcat(char *, char *);
/*exit.c*/
char *_stringcpy(char *, char *, int);
char *_stringcat(char *, char *, int);
char *_stringchar(char *, char);

char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);

ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);

int bfree(void **);

int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

void clear_info(info_t *);
void set_info(info_t *, char **);
void free_info(info_t *, int);

int is_cmd(info_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_t *, char *, char *);

char **strtow(char *, char *);
char **strtow2(char *, char);



int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_alias(info_t *);
int replace_vars(info_t *);
int replace_string(char **, char *);

char *get_history_file(info_t *info);
int write_history(info_t *info);
int read_history(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);
int renumber_history(info_t *info);
/*2-shell */
int myexit(info_t *);
int mycd(info_t *);
int _mychelp(info_t *);

int hsh(info_t *, char **);
int find_builtin(info_t *);
void find_cmd(info_t *);
void fork_cmd(info_t *);

int _myhistory(info_t *);
int _myalias(info_t *);
/*3-shell*/
char *getenva(info_t *, const char *);
int cmyenv(info_t *);
int mysetenvi(info_t *);
int _dmyunsetenv(info_t *);
int populate_envlist(info_t *);

/*4-shell*/
void _eputsd(char *);
int eputchar(char *);
int put_fd(char *, int *);
int _edputsfd(char **, int *);



#endif

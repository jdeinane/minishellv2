/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 21:59:31 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/22 16:19:03 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <signal.h>
# include <stdbool.h>
# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <readline/readline.h>
# include <readline/history.h>

# define MAX_PATH 4096
# define MAX_ARGS 512
# define VAR_MAX_SIZE 1024

# define OLD_PWD "OLDPWD"
# define PWD "PWD"

# define STDOUT STDOUT_FILENO
# define STDIN  STDIN_FILENO
# define STDERR STDERR_FILENO

# define CMD_NOT_EXEC   126
# define CMD_NOT_FOUND  127

typedef struct s_redirect
{
	bool	error;
	int		fd_in;
	int		fd_out;
	int		stdin_backup;
	int		stdout_backup;
	int		cmd_index;
	char	*in_file;
	char	*out_file;
	char	*append_file;
	char	*heredoc_eof;
}	t_redirect;

typedef struct s_data
{
	char		**env;
	char		*user_input;
	char		*work_dir;
	char		*old_work_dir;
}	t_data;

typedef struct s_cmd
{
	char	*path;
	char	**args;
	char	**redirections;
}	t_cmd;

typedef struct s_pipe
{
	int	*fd;
}	t_pipe;

typedef struct s_commands
{
	pid_t			*pid;
	int				num_cmds;
	int				num_exec;
	int				*operators;
	int				exit_value;
	char			**cmds;
	char			**tokens;
	char			**paths;
	t_pipe			*pipe;
	t_redirect		*io;
	t_cmd			*cmd;
}	t_commands;

typedef struct s_tokenizer
{
	char	**tokens;
	char	*start;
	char	current_quote;
	bool	in_quote;
	int		count;
	int		size;
}	t_tokenizer;

extern int	g_status_code;

// BUILTINS
int	builtin_cd(char **av, char **envp);


// ENV
char		**copy_env(char **envp);
int			env_var_count(char **envp);
int			get_env_var_index(char **envp, char *var_name);
char		*get_env_var(char **envp, char *var_name);
int			set_env_var(char **envp, const char *name, const char *value);
int			unset_env_var(char **envp, const char *var_name);

// INIT
bool		*init_data(t_data *data, char **envp);
void		init_commands(t_data *data, t_commands *cmds);
void		init_redirections(t_commands *cmds);
void		init_pipe(t_commands *cmds);

// LEXER
char		*trim_input(const char *input);

// MAIN
int			main(int ac, char **av, char **envp);
void		minishell(int ac, char **av, char **envp);

// UTILS
int			is_space(int c);
char		**get_paths(char **envp);
void		*ft_memcpy(void *dest, const void *src, size_t n);
char		*ft_strcat(char *dest, const char *src);
char		*ft_strchr(const char *s, int c);
int			ft_strcmp(char *s1, char *s2);
int			ft_isalnum(int c);
char		*ft_strcpy(char *dest, const char *src);
char		*ft_strdup(const char *src);
size_t		ft_strlen(char const *s);
char		*ft_strndup(const char *s1, size_t n);
int			ft_strncmp(const char *s1, const char *s2, unsigned int n);
void		ft_putchar(char c);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
char		*ft_strpbrk(const char *str, const char *accept);
size_t		ft_strspn(const char *str, const char *accept);
char		*ft_strtok(char *str, const char *delim);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_calloc(size_t nmemb, size_t size);
int			ft_isdigit(int c);
bool		is_numeric(const char *str);

#endif
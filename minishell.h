#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

extern	int	g_exit_status;

enum	e_redir
{
	R_IN,
	R_OUT,
	R_HEREDOC,
	R_APPEND,
	R_MAX
};	

typedef struct s_redir
{
	enum e_redir	type;
	char	*target;
	bool	quoted;
}	t_redir;

typedef struct s_cmd
{
	char	*cmd;
	char	**argv;
	t_dlist	*redirs;	
}	t_cmd;

typedef struct	s_data
{
	char *line;
	t_dlist	*pipeline;
	t_cmd	**cmds;
	size_t	n_cmds;
}	t_data;

/*				*/
bool	ft_tokenize(t_data *data);

/*		ft_is.c			*/
enum e_redir	ft_get_redir_type(char *str);
bool	ft_is_pipe(char *str);
bool	ft_is_redir(char *str);
bool	ft_is_operator(char *str);

/*		ft_cmds_init.c		*/
bool	ft_init_cmds(t_data *data);

#endif

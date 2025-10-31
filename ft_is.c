#include "minishell.h"

enum e_redir	ft_get_redir_type(char *str)
{
	if (!str)
		return (R_MAX);
	if (str[0] == '<')
	{
		if (!str[1])
			return (R_IN);
		if (str[1] == '<' && !str[2])
			return (R_HEREDOC);
	}
	if (str[0] == '>')
	{
		if (!str[1])
			return (R_OUT);
		if (str[1] == '>' && !str[2])
			return (R_APPEND);
	}
	return (R_MAX);
}

bool	ft_is_pipe(char *str)
{
	return (str && str[0] == '|' && str[1] == '\0');
}

bool	ft_is_redir(char *str)
{
	return (ft_get_redir_type(str) != R_MAX);
}


bool	ft_is_operator(char *str)
{
	return (ft_is_pipe(str) || ft_is_redir(str));
}


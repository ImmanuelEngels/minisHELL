#include "minishell.h"

bool	ft_tokenend(unsigned char s, unsigned char e)
{
	if (s == '|' || e == '|')
		return (true);
	else if (s == '<' || e == '<')
		return (s != e);
	else if (s == '>' || e == '>')
		return (s != e);
	return (ft_isspace(e));
}

bool	ft_add_token(t_data *data, size_t s, size_t e)
{
	char *line;
	t_dlist	*n_node;

	
	line = ft_substr(data->line, s, e - s);
	if (!line)
		return (ft_dlstclear(&data->pipeline, free), false);
	n_node = ft_dlstnew(line);
	if (!n_node)
		return (free(line), ft_dlstclear(&data->pipeline, free), false);
	ft_dlstadd_back(&data->pipeline, n_node);
	return (true);
}

bool	ft_find_tokenend(char *line, size_t s, size_t *e)	
{
	char	quote;

	if (line[s] == '\'' || line[s] == '\"')
		quote = line[s];
	else
		quote = 0;
	while (line[*e]) 
	{
		if (!quote && (line[*e] == '\'' || line[*e] == '\"'))
			quote = line[*e];
		else if (quote == line[*e])
			quote = 0;
		else if (!quote && ft_tokenend(line[s], line[*e]))
			return (true);
		(*e)++;
	}
	return (quote == 0);	
}

bool	ft_tokenize(t_data *data)
{
	size_t s;
	size_t e;

	e = 0;
	while (data->line[e])
	{
		s = e;
		while (ft_isspace(data->line[s]))	
			s++;
		if (!data->line[s])
			break;
		e = s + 1;
		if (!ft_find_tokenend(data->line, s, &e))
			return (false);
		if (!ft_add_token(data, s, e))
			return (false);
	}
	return (true);
}


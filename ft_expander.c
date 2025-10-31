#include "minishell.h"

char	*ft_get_varname(char *str, size_t start, size_t *end)
{
	if (!str[*end] || (!ft_isalpha(str[*end]) && str[*end] != '_'))
	{
		if (str[*end] == '?')
		{
			(*end)++;
			return (ft_strdup("?"));
		}
		return (ft_strdup(""));
	}
	while (str[*end] && (ft_isalnum(str[*end]) || str[*end] == '_'))
		(*end)++;
	return (ft_substr(str, start, *end - start));
}

bool	ft_default_ifs(unsigned char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char	ft_is_quoted(char *str, size_t i, bool init)
{
	static	char quote;

	if (init)
		quote = 0;
	else
	{
		if (quote && quote == str[i])
			quote = 0;
		else if (!quote && (str[i] == '\'' || str[i] == '\"'))		
			quote = str[i];
	}
	return (quote);
}

char *ft_getenv(char *name, char **env)
{
	size_t	len;
	size_t	i; 

	len= ft_strlen(name);
	i = 0;
	while (env && env[i])
	{
		if (!ft_strncmp(env[i], name, len) && env[i][len] == '=')
			return ft_strdup(env[i] + len + 1);
		i++;
	}
	return ft_strdup("");
}

bool	ft_ifs_noquote(t_dlist *pipeline)
{
	char	*left;
	char	*right;
	char	*str;
	size_t	e;
	t_dlist	*n_node;

	while (pipeline)
	{
		e = 0;
		str = (char *)pipeline->content;
		while (str[e] && !ft_is_quoted(str, e, false) && ft_default_ifs(str[e]))
			e++;
		if (str[e])
		{
			left = ft_substr(str, 0, e);
			if (!left)
				return (false);
			right = ft_delsubstr(str, left, e, 0);
			if (!right)
				return (free(left), false);
			n_node = ft_dlstnew(right);
			if (!n_node)
				return (free(left), free(right), false);
			pipeline->content = left;
			free(str);
			ft_dlstadd_after(pipeline, n_node);
		}
		pipeline = pipeline->next;
	}
	return (true);
}

static char *ft_expand_replace(char *str, size_t i, size_t end, char *name, char **env)
{
	char *tmp;
	char *value;

	if (ft_strncmp(name, "?", 1) == 0)
		value = ft_itoa(g_exit_status);
	else
		value = ft_getenv(name, env);
	if (!value)
		return (NULL);
	tmp = ft_delsubstr(str, str + i, end - i, i);
	if (!tmp)
		return (free(value), NULL);
	free(str);
	str = tmp;
	tmp = ft_insertsubstr(str, value, ft_strlen(value), i);
	free(value);
	free(str);
	return (tmp);
}

static char *ft_expand_at(char *str, size_t i, char **env)
{
	size_t  end;
	char    *name;
	char    *expanded;

	end = i + 1;
	name = ft_get_varname(str, i + 1, &end);
	if (!name)
		return (NULL);

	expanded = ft_expand_replace(str, i, end, name, env);
	free(name);
	return (expanded);
}

bool ft_expand(char **content, char **env, char quote)
{
	size_t  i;
	char    *expanded;
	char	*str;

	i = 0;
	str = *content;
	ft_is_quoted("INIT", 0, true);
	while (str[i])
	{
		if (str[i] == '$' && quote == ft_is_quoted(str, i, false))
		{
			expanded = ft_expand_at(str, i, env);
			if (!expanded)
				return (false);
			str = expanded;
			i = 0;
		}
		else
		i++;
	}
	*content = str;
	return (true);
}


bool	ft_expand_pipeline(t_data *data, t_dlist *pipeline)
{
	while (pipeline)
	{
		if (ft_expand(pipeline, pipeline->content, data->env, 0));
			return (false);
		pipeline = pipeline->next;
	}
	pipeline = data->pipeline;
	while (pipeline)
	{
		if (ft_expand(pipeline, pipeline->content, data->env, '"'));
			return (false);
		pipeline = pipeline->next;
	}
}

bool	ft_expand_targets(t_data *data, t_dlist *targets)
{
	while (targets)
	{
		if (ft_expand(targets, targets->content, data->env, 0));
			return (false);
		targets= targets->next;
	}
	targets= data->targets;
	while (targets)
	{
		if (ft_expand(targets, targets->content, data->env, '"'));
			return (false);
		targets= targets->next;
	}
}


#include "minishell.h"

size_t	ft_count_cmds(t_dlist *lst)
{
	size_t	count;

	count = 1;
	while (lst)
	{
		if (((char *)lst->content)[0] == '|')
			count++;
		lst = lst->next;
	}
	return (count);
}

bool ft_get_redir_lst(t_dlist *op, t_data *data, t_cmd *cmd)
{
	t_dlist *target_node;
	t_redir *redir;
	enum e_redir type;

	if (!op || !op->next || ft_is_operator((char *)op->next->content))
		return false;
	type = ft_get_redir_type((char *)op->content);
	if (type == R_MAX)
		return false;
	target_node = op->next;
	redir = malloc(sizeof(t_redir));
	if (!redir)
		return false;
	redir->type = type;
	redir->target = (char *)target_node->content;
	redir->quoted = (ft_strchr(redir->target, '\'') || ft_strchr(redir->target, '"'));
	ft_dlst_unwrap(&data->pipeline, op);
	ft_dlstdelone(op, free);
	ft_dlst_unwrap(&data->pipeline, target_node);
	target_node->content = redir;
	ft_dlstadd_back(&cmd->redirs, target_node);
	return true;
}

bool	ft_init_redirs(t_data *data)
{
	size_t i;
	t_dlist	*tmp;

	tmp = data->pipeline;
	i = 0;
	while (i < data->n_cmds && tmp)
	{
		if (((char *)tmp->content)[0] == '|')	
		{
			i++;
			tmp = tmp->next;
		}
		else if (ft_is_operator((char *)tmp->content))
		{
			if (!ft_get_redir_lst(tmp, data, data->cmds[i]))
				return (false);
			tmp = data->pipeline;
			i = 0;
		}
		else
			tmp = tmp->next;
	}
	return (true);
}

t_cmd *ft_cmd_new(void)
{
	t_cmd *cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return NULL;
	cmd->argv = NULL;
	cmd->redirs = NULL;
	return cmd;
}

bool	ft_init_cmds(t_data *data)
{
	size_t i;

	if (!data->pipeline)
		return (false);
	if (((char *)data->pipeline->content)[0] == '|')
		return (false);
	if (ft_is_operator((char *)ft_dlstlast(data->pipeline)->content))
		return (false);
	data->n_cmds = ft_count_cmds(data->pipeline);
	data->cmds = malloc(sizeof(t_cmd *) * (data->n_cmds + 1));
	if (!data->cmds)
		return (false);
	i = 0;
	while (i < data->n_cmds)
	{
		data->cmds[i] = ft_cmd_new();
		if (!data->cmds[i])
			return (false);
		i++;
	}
	if (!ft_init_redirs(data))
		return (false);
	return (true);
}


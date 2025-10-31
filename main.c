#include "minishell.h"

int	main(void)
{
	t_data *data = malloc(sizeof(t_data));
	if (!data)
		return 1;
	data->pipeline = NULL;
	data->line = readline("minishell>");
	if (!data->line)
		return (free(data), 1);
	if (ft_tokenize(data))
	{
		t_dlist *tmp = data->pipeline;
		for (;tmp; tmp = tmp->next)
			printf("[%s]\n", (char*)tmp->content);
	}
	ft_dlstclear(&data->pipeline, free);;
	free(data->line);
	free(data);
	return (0);
}


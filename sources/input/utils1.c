/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvznuzda <pashavznuzdajev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:54:20 by pvznuzda          #+#    #+#             */
/*   Updated: 2022/11/20 22:20:10 by pvznuzda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
	split = NULL;
}

void	free_list(t_list *list)
{
	t_list	*current;
	t_list	*temp;

	if (!list)
		return ;
	current = list;
	while (current)
	{
		free(current->content);
		temp = current;
		current = current->next;
		free(temp);
	}
}

int	check_arguments(int argc, char **argv)
{
	int	arg_len;
	int	fd;

	if (argc > 2)
		return (-1);
	arg_len = ft_strlen(argv[1]);
	if (arg_len < 4)
		return (-1);
	if (ft_strncmp((argv[1] + arg_len - 3), ".rt", 4))
		return (-1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	return (fd);
}

int	read_into_list(int fd, t_list **line_list)
{
	t_list	*new_item;
	char	*line;
	int		eof;

	eof = 0;
	while (!eof)
	{
		line = get_next_line(fd);
		if (!line)
			eof = 1;
		else if (ft_strncmp(line, "\n", 2))
		{
			new_item = ft_lstnew((void *)(ft_strdup(line)));
			if (!new_item->content)
			{
				close(fd);
				return (-1);
			}
			ft_lstadd_back(line_list, new_item);
		}
		free(line);
	}
	close(fd);
	return (0);
}

char	*get_identifier(char *line)
{
	char	*identifier;
	int		i;

	i = 0;
	while (line[i] != ' ')
	{
		if (line[i] == '\0')
		{
			ft_printf("No spaces\n");
			return (NULL);
		}
		i++;
	}
	identifier = ft_substr(line, 0, i);
	if (!identifier)
		return (NULL);
	return (identifier);
}

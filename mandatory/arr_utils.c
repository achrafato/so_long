/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:53:41 by aibn-che          #+#    #+#             */
/*   Updated: 2024/02/18 21:51:31 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*str_dup(char *str)
{
	int		i;
	char	*new_str;

	new_str = malloc(sizeof(char) * (str_len(str) + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	**to2arr(t_lm *head)
{
	char	**arr;
	int		j;

	j = 0;
	arr = malloc(sizeof(char *) * (stack_len(head) + 1));
	if (!arr)
		return (NULL);
	while (head)
	{
		arr[j++] = str_dup(head->line);
		head = head->next;
	}
	arr[j] = NULL;
	return (arr);
}

int	item_count(char **arr)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	free_to_d_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i++]);
	}
	free(arr);
}

int	map_height(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		i++;
	}
	return (i);
}

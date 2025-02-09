/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:52:06 by aibn-che          #+#    #+#             */
/*   Updated: 2024/02/19 17:59:14 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	stack_len(t_lm *head)
{
	int	i;

	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}

t_lm	*last_node(t_lm *top)
{
	while (top->next)
	{
		top = top->next;
	}
	return (top);
}

t_lm	*new_node(char *str)
{
	t_lm	*new;

	new = malloc(sizeof(t_lm));
	if (!new)
		return (NULL);
	new->line = str;
	new->len = str_len(str);
	new->next = NULL;
	return (new);
}

void	push(char *str, t_lm **map)
{
	t_lm	*newnode;
	t_lm	*last;

	newnode = new_node(str);
	if (!map || !(*map))
		*map = newnode;
	else
	{
		last = last_node(*map);
		last->next = newnode;
	}
}

void	free_linked_list(t_lm **head)
{
	t_lm	*current;

	while (*head)
	{
		current = *head;
		free(current->line);
		*head = (*head)->next;
		free(current);
	}
}

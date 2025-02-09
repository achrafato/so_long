/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cordinations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:23:48 by aibn-che          #+#    #+#             */
/*   Updated: 2024/02/18 20:13:42 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	exit_cordination(char **arr, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == 'E')
			{
				*x = i;
				*y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	door_cordination(char **arr, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == 'E')
			{
				*x = i;
				*y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	position_cordination( char **arr, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == 'P')
			{
				*x = i;
				*y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

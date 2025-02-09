/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:04:18 by aibn-che          #+#    #+#             */
/*   Updated: 2024/02/18 21:54:18 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/so_long.h"

static int	len_num(int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

static void	handle_sign(long *n, int *sign, int *i)
{
	if (*n < 0)
	{
		*n *= -1;
		*sign = -1;
		(*i)++;
	}
}

char	*ft_itoa(int a)
{
	int		i;
	char	*s_num;
	int		sign;
	long	n;

	n = (long)a;
	i = len_num(n);
	sign = 1;
	handle_sign(&n, &sign, &i);
	s_num = malloc(sizeof(char) * (i + 1));
	if (!s_num)
		return (NULL);
	s_num[i--] = '\0';
	while (i >= 0)
	{
		s_num[i--] = (n % 10) + '0';
		n /= 10;
	}
	if (sign == -1)
		s_num[0] = '-';
	return (s_num);
}

// int	main(void)
// {
// 	printf("%s", ft_itoa(-2147483648LL));
// 	return (0);
// }
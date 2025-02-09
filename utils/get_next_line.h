/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:52:29 by aibn-che          #+#    #+#             */
/*   Updated: 2024/02/18 21:54:31 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// #define ENEME
// utils
int		str_len(char *str);
char	*str_join(char **s1, char *s2);
int		encounter_space(char *str);
char	*substring(char *s, int index);
void	handle_nl(char **container, char *buffer, char **keeper);
void	mingle_data(char **container, char **buffer, char **keeper);

// main
char	*get_next_line(int fd);

#endif
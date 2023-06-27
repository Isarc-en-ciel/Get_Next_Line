/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 19:01:57 by iwaslet           #+#    #+#             */
/*   Updated: 2023/06/27 18:16:28 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*read_it(char *temp, char *buffer, int fd);
char	*grab_line(char *str);
char	*new_buffer(char *str);
char	*ft_letgo(char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_calloc(size_t size);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);

#endif
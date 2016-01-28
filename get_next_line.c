/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 11:36:21 by rabougue          #+#    #+#             */
/*   Updated: 2016/01/27 16:03:09 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"
#include "stdio.h"

int	get_next_line(int const fd, char **line)
{
	char		buf[BUFF_SIZE];
	char		*content;
	int i;

	i = 0;
	//content = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (read(fd, buf, BUFF_SIZE) != -1)
	{
		while (content[i] != '\n')
		{
			i++;
		}
		content = ft_strchr(buf, '\n');
		*line = ft_strjoin(buf, content);
		ft_putstr(content);
	}
	return (0);
}

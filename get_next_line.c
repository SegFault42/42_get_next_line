/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 16:30:51 by rabougue          #+#    #+#             */
/*   Updated: 2016/02/09 22:40:48 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

static int	split_stat(char **line, char **stat)
{
	char	*content2;
	int		len;

	if (!(*stat))
		return (0);
	if ((content2 = ft_strchr(*stat, '\n')))
	{
		len = content2 - *stat;
		*line = ft_strsub(*stat, 0, len);
		if (ft_strlen(++content2))
			*stat = ft_strdup(content2);
		else
			*stat = NULL;
	}
	else if (ft_strlen(*stat))
	{
		*line = *stat;
		*stat = NULL;
	}
	return (content2 ? 1 : 0);
}

static int	read_file(char *buf, char **line, char **stat)
{
	char	*content;

	if ((content = ft_strchr(buf, '\n')))
	{
		content[0] = '\0';
		*line = ft_strjoin(*line, buf);
		if (ft_strlen(++content))
			*stat = ft_strdup(content);
	}
	else
		*line = ft_strjoin(*line, buf);
	return (content ? 1 : 0);
}

int			get_next_line(int const fd, char **line)
{
	static char	*stat = NULL;
	char		*buf;
	int			ret;

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	*line = NULL;
	buf = ft_strnew(BUFF_SIZE);
	if (split_stat(line, &stat) == 1)
		return (1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (read_file(buf, line, &stat) == 1)
			break ;
	}
	if (ret > 0 || *line)
		return (1);
	return (ret);
}

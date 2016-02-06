#include "./get_next_line.h"

static int	split_stat(char **line, char **stat)
{
	char	*content2;
	int		len;

	if (*stat && (content2 = ft_strchr(*stat, '\n')))
	{
		len = content2 - *stat;
		*line = ft_strsub(*stat, 0, len);
		*stat = ft_strdup(++content2);
		return (1);
	}
	else
	{
		*line = *stat;
		*stat = NULL;
	}
	return (0);
}

static int	read_file(char *buf, char **line, char **stat)
{
	char	*content;

	if ((content = ft_strchr(buf, '\n')))
	{
		content[0] = '\0';
		*line = ft_strjoin(*line, buf);
		*stat = ft_strdup(++content);
		return(1);
	}
	else
		*line = ft_strjoin(*line, buf);
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	static char	*stat = NULL;
	char	*buf;
	int		ret;

	if (fd < 0 || line == NULL)
		return (-1);
	*line = NULL;
	buf = ft_strnew(BUFF_SIZE); // Ne pas oublier de le free
	if (split_stat(line, &stat) == 1)
		return(1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (read_file(buf, line, &stat) == 1)
			return (1);
	}
	if (*line && stat)
		return(1);
	return (ret);
}

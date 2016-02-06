#include "./get_next_line.h"

int	get_next_line(int const fd, char **line)
{
	char	*content;
	static char	*stat = NULL;
	char	*buf;
	int		ret;
	int		len;
	int		i = 1;

	*line = NULL;
	buf = ft_strnew(BUFF_SIZE); // Ne pas oublier de le free
	if (stat != NULL)
	{
		*line = stat;
		stat = NULL;
	}
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if ((content = ft_strchr(buf, '\n')))
		{
			content[0] = '\0';
			len = content - buf;
			*line = ft_strjoin(*line, buf);
			stat = ft_strdup(++content);
			printf("*line = %s | stat = %s\n", *line, stat);
			return(1);
		}
		else
			*line = ft_strjoin(*line, buf);
		printf("Boucle %d | *line = %s\n", i++, *line );
	}
	if (*line != NULL)
		return(1);
	return (ret);
}

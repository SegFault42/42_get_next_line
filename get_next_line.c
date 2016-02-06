#include "./get_next_line.h"
#include "stdio.h"

int	get_next_line(int const fd, char **line)
{
	char	*content;
	static char	*stat = NULL;
	char	*buf;
	int		ret;
	int		len;
	int		i = 1;

	*line = "\0";
	buf = ft_strnew(BUFF_SIZE); // Ne pas oublier de le free
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		printf("ret = %d | ", ret);
		if ((content = ft_strchr(buf, '\n')))
		{
			ft_debug();
			content[0] = '\0';
			len = content - buf;
			*line = ft_strjoin(*line, buf);
			stat = ft_strdup(++content);
			*line = NULL;
		}
		else
			*line = ft_strjoin(*line, buf);
		printf("Boucle %d | *line = %s\n", i++, *line );
	}
		ft_putendl(*line);
	return (ret);
}

#include "./get_next_line.h"
#include "stdio.h"

int	get_next_line(int const fd, char **line)
{
	char	*content;
	static char	*stat = NULL;
	char	*buf;
	int		ret;
	int		len;

	*line = "\0";
	buf = ft_strnew(BUFF_SIZE); // Ne pas oublier de le free
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if ((content = ft_strchr(buf, '\n')))
		{
			content[0] = '\0';
			len = content - buf;
			*line = ft_strjoin(*line, buf);
			stat = ft_strdup(++content);
			printf("*line = %s\nstat = %s\n", *line, stat);
			*line = NULL;
		}
		else
			*line = ft_strjoin(*line, buf);
	}
		/*ft_putendl(content);*/
	return (ret);
}

/*3*/

/*0	1	2	3	4	5	6*/
/*a	b	c	\0	d	e	\0*/

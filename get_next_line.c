#include "./get_next_line.h"
#include "stdio.h"

int	get_next_line(int const fd, char **line)
{
	char		buf[BUFF_SIZE];
	static char		*content;
	char			*str;
	int len;

	str = "\0";
	while ((len = read(fd, buf, BUFF_SIZE)) > 0)
	{
		ft_putnbr(len);
		buf[len] = '\0';
		if ((content = ft_strchr(buf, '\n')))
		{
			content++;
			content = ft_strdup(content);
			*line = ft_strjoin(str, buf);
			return (1);
		}
		str = ft_strjoin(str, buf);
		ft_putendl(*line);
	}
	return (0);
}

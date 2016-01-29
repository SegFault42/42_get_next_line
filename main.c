#include "./get_next_line.h"

int	open_file()
{
	int		fd;
	char	*line;

	if ((fd = open("file", O_RDONLY)) == -1)
	{
		ft_putendl("Cannot open the file !");
		return (EXIT_FAILURE);
	}
	get_next_line(fd, &line);
	return (0);
}

int	main()
{
	int		fd;
	char	*line;

	open_file();
	get_next_line(fd, &line);
	return (0);
}

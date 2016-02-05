#include "./get_next_line.h"

int	open_file(char *file)
{
	int		fd;
	char	*line;

	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_putendl("Cannot open the file !");
		return (EXIT_FAILURE);
	}
	get_next_line(fd, &line);
	return (fd);
}

int	main(int ac, char **av)
{
	int		fd;
	char	*line;

	if (ac == 2)
		open_file(av[1]);
	else
	{
		ft_putendl("Error !");
		return (0);
	}
	return (0);
}

#include "./get_next_line.h"

int	open_file(char *file)
{
	int		fd;
	int		i = 0;
	int		j;
	char	*line;
	
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_putendl("Cannot open the file !");
		return (EXIT_FAILURE);
	}
	while ((j = get_next_line(fd, &line)) == 1)
		printf("%d : %s\n", ++i, line);
	if (j == -1)
	 printf("Erreur de lecture");
	return (fd);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		open_file(av[1]);
	else
	{
		ft_putendl("Error !");
		return (0);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 11:36:53 by rabougue          #+#    #+#             */
/*   Updated: 2016/01/27 11:49:01 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

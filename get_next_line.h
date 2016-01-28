/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 18:26:48 by rabougue          #+#    #+#             */
/*   Updated: 2016/01/27 12:27:46 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include "./libft/libft.h"
#include <fcntl.h>
#include <unistd.h>

#define BUFF_SIZE 100

int get_next_line(int const fd, char ** line);

#endif

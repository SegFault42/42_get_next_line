/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 18:26:48 by rabougue          #+#    #+#             */
/*   Updated: 2016/01/30 11:23:22 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include "./libft/includes/libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>


#define BUFF_SIZE 9

int get_next_line(int const fd, char ** line);

#endif

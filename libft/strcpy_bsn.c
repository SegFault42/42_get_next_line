/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcpy_bsn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 10:24:39 by rabougue          #+#    #+#             */
/*   Updated: 2016/02/09 22:19:14 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strcpy_bsn(char *str)
{
	int		i;
	char	*str2;

	i = 0;
	if (!(str2 = (char *)malloc(sizeof(char) * strlen(str) + 1)))
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
	{
		str2[i] = str[i];
		i++;
	}
	str2[i] = '\0';
	return (str2);
}

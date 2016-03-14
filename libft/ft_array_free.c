/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfouquet <lfouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/19 13:27:52 by bchevali          #+#    #+#             */
/*   Updated: 2016/03/07 20:02:05 by lfouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_array_free(char **array)
{
	char	**save;

	save = array;
	while (*array)
	{
		free(*array);
		++array;
	}
	free(save);
}

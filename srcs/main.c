/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 14:17:03 by bchevali          #+#    #+#             */
/*   Updated: 2016/03/18 13:40:16 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

static void		usage(char *name)
{
	ft_putstr_fd("usage: ", 2);
	ft_putstr_fd(name, 2);
	ft_putendl_fd(" \"args1 args2 ..\"", 2);
}

int				main(int ac, char **av)
{
	if (ac > 1)
		ft_select(av);
	else
		usage(av[0]);
	return (0);
}

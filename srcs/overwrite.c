/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overwrite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 19:37:51 by bchevali          #+#    #+#             */
/*   Updated: 2016/03/18 17:16:03 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

int				open_tty(void)
{
	static int	fd = 0;

	if (!fd)
		fd = open("/dev/tty", O_WRONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Open \"/dev/tty\" error", 2);
		exit(0);
	}
	return (fd);
}

int				fputchar(int c)
{
	ft_putchar_fd(c, open_tty());
	return (0);
}

static void		print_dlist(t_dlist *dlist, void *data)
{
	t_dlist		*ptr;

	ptr = (t_dlist*)data;
	if (dlist == ptr)
		tputs(tgetstr("us", 0), 1, fputchar);
	if (!dlist->select)
		tputs(tgetstr("mr", 0), 1, fputchar);
	ft_putendl_fd(dlist->content, open_tty());
	tputs(tgetstr("me", 0), 1, fputchar);
	tputs(tgetstr("ue", 0), 1, fputchar);
}		

void			overwrite(t_dlist *dlist, t_dlist *ptr)
{
	t_dlist		*tmp;
	size_t		c;

	tmp = dlist;
	c = ft_lstd_size(dlist);
	ft_lstd_foreach(dlist, print_dlist, ptr);
	while (c--)
		tputs(tgetstr("up", 0), 1, fputchar);
}
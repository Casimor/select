/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 16:00:06 by bchevali          #+#    #+#             */
/*   Updated: 2016/03/30 15:43:28 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void		up_key(t_dlist **dlist, t_dlist **ptr)
{
	(void)dlist;
	*ptr = (*ptr)->previous;
}

void		down_key(t_dlist **dlist, t_dlist **ptr)
{
	(void)dlist;
	*ptr = (*ptr)->next;
}

void		space_key(t_dlist **dlist, t_dlist **ptr)
{
	t_dlist *tmp;

	tmp = *dlist;
	while (tmp != *ptr)
		tmp = tmp->next;
	if (tmp->select)
		tmp->select = 0;
	else
		tmp->select = 1;
	*ptr = (*ptr)->next;
}

void		del_key(t_dlist **dlist, t_dlist **ptr)
{
	t_dlist		*tmp;

	tmp = *dlist;
	while (tmp != *ptr)
		tmp = tmp->next;
	ft_lstd_delone(tmp, dlist);
	if (tmp->next)
		*ptr = (*ptr)->next;
	// ft_lstd_delone(tmp, ptr);
	if (!*dlist)
	{
		tputs(tgetstr("ve", 0), 1, fputchar);
		exit(0);
	}
	overwrite(*dlist, *ptr);
}

void		enter_key(t_dlist *dlist)
{
	t_dlist		*tmp;
	size_t		c;

	tmp = dlist;
	c = ft_lstd_size(dlist);
	while (c--)
		tputs(tgetstr("dl", 0), 1, fputchar);
	while (dlist->next != tmp)
	{
		if (!dlist->select)
		{
			ft_putstr_fd(dlist->content, open_tty());
			ft_putchar_fd(' ', open_tty());
			c = 1;
		}
		dlist = dlist->next;
	}
	if (c != 1)
	{
		tputs(tgetstr("ve", 0), 1, fputchar);
		exit(0);
	}
	if (!dlist->select)
		ft_putstr_fd(dlist->content, open_tty());
	ft_putchar_fd('\n', open_tty());
}

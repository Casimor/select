/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 16:00:06 by bchevali          #+#    #+#             */
/*   Updated: 2016/03/18 17:15:37 by bchevali         ###   ########.fr       */
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

void		enter_key(t_dlist *dlist)
{
	t_dlist		*tmp;

	tmp = dlist;
	while (dlist->next != tmp)
	{
		if (!dlist->select)
		{
			ft_putstr_fd(dlist->content, open_tty());
			ft_putchar_fd(' ', open_tty());
		}
		dlist = dlist->next;
	}
	if (!dlist->select)
		ft_putstr_fd(dlist->content, open_tty());
	ft_putchar_fd('\n', open_tty());
}

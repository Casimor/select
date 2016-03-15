/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overwrite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 19:37:51 by bchevali          #+#    #+#             */
/*   Updated: 2016/03/15 20:05:17 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

extern t_data	g_dt;

void		overwrite(t_dlist *dlist)
{
	t_dlist		*tmp;

	tmp = dlist;
	while (tmp != dlist->next)
	{
		printf("%s\n", tmp->content);
		tmp = tmp->next;
	}
}
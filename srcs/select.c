/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 15:12:14 by bchevali          #+#    #+#             */
/*   Updated: 2016/03/15 20:02:29 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

t_data	g_dt;

static t_dlist		*stock_av(char **av)
{
	t_dlist		*dlst;
	int			i;

	i = 1;
	dlst = NULL;
	while (av[i])
	{
		ft_lstd_pushback(&dlst, ft_lstd_new(av[i], ft_strlen(av[i]) + 1));
		++i;
	}
	return (dlst);
}

static int			init_term(t_term *term)
{
	const char			*var_term;

	var_term = getenv("TERM");
	if (!tgetent(0, var_term))
	{
		ft_putendl_fd("./ft_select: \'TERM\' not found", 2);
		return (0);
	}
	tcgetattr(0, term);
	term->c_lflag &= ~(ICANON);
	term->c_lflag &= ~(ECHO);
	tcsetattr(0, 0, term);
	ft_memcpy(&g_dt.term_save, term, sizeof(t_term));
	return (1);
}

static int			fputchar(int c)
{
	ft_putchar(c);
	return (0);
}



void				ft_select(char **av)
{
	t_term		term;
	t_dlist		*dlst;

	if (!init_term(&term))
		return ;
	dlst = stock_av(av);
	g_dt.dlist = dlst;
	g_dt.ptr = dlst;
	init_signal();
	tputs(tgetstr("vi", 0), 1, fputchar);
	overwrite(dlst);
	tputs(tgetstr("ve", 0), 1, fputchar);
}
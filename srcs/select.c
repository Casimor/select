/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 15:12:14 by bchevali          #+#    #+#             */
/*   Updated: 2016/03/14 18:42:42 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

static int		get_term(t_term *term)
{
	const char			*var_term;

	var_term = getenv("TERM");
	if (var_term)
	{
		if (tgetent(0, var_term))
		{
			if (tcgetattr(0, term) != -1)
				return (1);
		}
	}
	return (0);
}

static void		init_term(t_term *term)
{
	term->c_lflag &= ~(ICANON);
	term->c_lflag &= ~(ECHO);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	tcsetattr(0, TCSADRAIN, term);
}

int				fputchar(int c)
{
	ft_putchar(c);
	return (0);
}

void			ft_select(char **av)
{
	t_term		term;
//	t_dlist		dlst;

	(void)av;
	if (!get_term(&term))
		return ;
	init_term(&term);
	// init signaux
	char		*res;

	res = tgetstr("cl", NULL);
	tputs(res, 0, fputchar);
}
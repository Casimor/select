/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 15:12:14 by bchevali          #+#    #+#             */
/*   Updated: 2016/03/18 17:09:20 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

t_data	g_dt;

static const t_key	g_tab[] = {
	{UP_KEY, up_key},
	{DOWN_KEY, down_key},
	{LEFT_KEY, up_key},
	{RIGHT_KEY, down_key},
	{SP_KEY, space_key},
	// {BS_KEY, del_key},
	// {DEL_KEY, del_key},
};

static void				check_key(char *key, t_dlist **dlist, t_dlist **ptr)
{
	size_t		i;

	i = 0;
	while (i < sizeof(g_tab) / sizeof(t_key))
	{
		if (!ft_strcmp(g_tab[i].str, key))
		{
			g_tab[i].f(dlist, ptr);
			return ;
		}
		++i;
	}
}			

static void				read_input(t_dlist *dlist)
{
	char		buf[5];
	int			ret;
	t_dlist		*ptr;

	ptr = dlist;
	overwrite(dlist, ptr);
	while ((ret = read(0, buf, 4)) > 0)
	{
		buf[ret] = '\0';
		check_key(buf, &dlist, &ptr);
		overwrite(dlist, ptr);
		if (!ft_strcmp(buf, ESC_KEY))
			return ;
		if (!ft_strcmp(buf, NL_KEY))
		{
			enter_key(dlist);
			return ;
		}
	}
}

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

void				ft_select(char **av)
{
	t_term		term;
	t_dlist		*dlst;

	if (!init_term(&term))
		return ;
	dlst = stock_av(av);
	init_signal();
	tputs(tgetstr("vi", 0), 1, fputchar);
	read_input(dlst);
	tputs(tgetstr("ve", 0), 1, fputchar);
}
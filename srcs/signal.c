/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 16:23:53 by bchevali          #+#    #+#             */
/*   Updated: 2016/03/21 17:34:40 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

extern t_data	g_dt;

static void		ft_sigint(int sig)
{
	(void)sig;
	tcsetattr(0, 0, &g_dt.term_save);
	tputs(tgetstr("ve", 0), 1, fputchar);
	exit(0);
}

static void		ft_sigtstp(int sig)
{
	(void)sig;
}

static void		ft_sigcont(int sig)
{
	(void)sig;
}

void			init_signal(void)
{
	signal(SIGINT, ft_sigint);
	signal(SIGTSTP, ft_sigtstp);
	signal(SIGCONT, ft_sigcont);
}
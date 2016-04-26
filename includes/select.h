/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 14:18:15 by bchevali          #+#    #+#             */
/*   Updated: 2016/03/24 16:12:25 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECT_H
# define SELECT_H


# include <term.h>
# include <fcntl.h>
# include <sys/ioctl.h>
# include "../libft/libft.h"

// care
# include <stdio.h>
// care

# define UP_KEY			"\33\133\101"
# define DOWN_KEY		"\33\133\102"
# define RIGHT_KEY		"\33\133\103"
# define LEFT_KEY		"\33\133\104"
# define ESC_KEY		"\33"
# define SP_KEY			"\40"
# define NL_KEY			"\12"
# define DEL_KEY		"\177"
# define BS_KEY			"\33\133\63\176"
# define DEFAULT_TERM	"xterm-256color"

typedef struct	termios	t_term;

typedef	struct	s_data
{
	t_term		term_save;
	t_dlist		*ptr;
	t_dlist		*dlist;
}				t_data;

typedef struct		s_key
{
	char			*str;
	void			(*f)(t_dlist **, t_dlist **);
}					t_key;

void			ft_select(char **av);
void			init_signal(void);
void			overwrite(t_dlist *dlist, t_dlist *ptr);
int				fputchar(int c);
int				open_tty(void);


/*
** Keys Functions
*/
void		up_key(t_dlist **dlist, t_dlist **ptr);
void		down_key(t_dlist **dlist, t_dlist **ptr);
void		space_key(t_dlist **dlist, t_dlist **ptr);
void		del_key(t_dlist **dlist, t_dlist **ptr);
void		enter_key(t_dlist *dlist);


#endif
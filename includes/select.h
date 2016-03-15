/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 14:18:15 by bchevali          #+#    #+#             */
/*   Updated: 2016/03/15 13:56:52 by bchevali         ###   ########.fr       */
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

# define DEFAULT_TERM "xterm-256color"


typedef struct	termios	t_term;

typedef	struct	s_data
{
	t_term		term_save;
}				t_data;

void		ft_select(char **av);


#endif
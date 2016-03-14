/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 14:18:15 by bchevali          #+#    #+#             */
/*   Updated: 2016/03/14 17:07:20 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECT_H
# define SELECT_H


# include <term.h>
# include <fcntl.h>
# include <sys/ioctl.h>
# include "../libft/libft.h"

typedef struct	termios	t_term;

// care
# include <stdio.h>
// care

void		ft_select(char **av);


#endif
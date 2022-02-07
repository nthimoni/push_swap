/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 22:34:21 by nthimoni          #+#    #+#             */
/*   Updated: 2022/02/03 22:14:32 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	error_msg(char	*msg, t_list *a, t_list *b)
{
	if (msg)
		ft_putendl_fd(msg, 2);
	if (a)
		ft_lstclear(&a, NULL);
	if (b)
		ft_lstclear(&b, NULL);
	exit(-1);
}

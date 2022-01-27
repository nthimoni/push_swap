/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 22:34:21 by nthimoni          #+#    #+#             */
/*   Updated: 2022/01/27 22:42:59 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	error_msg(char	*msg, t_list *a, t_list *b)
{
	if (msg)
		ft_printf("%s\n", msg);
	if (a)
		ft_lstclear(&a, NULL);
	if (b)
		ft_lstclear(&b, NULL);
	exit(-1);
}

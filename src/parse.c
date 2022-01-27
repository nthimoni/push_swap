/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:55:05 by nthimoni          #+#    #+#             */
/*   Updated: 2022/01/27 22:17:41 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int is_valid(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			if (i != 0 || (s[i] != '+' && s[i] != '-'))
				return (0);
		i++;
	}
	return (1);
}

int	parse(t_list **a, int argc, char *argv[])
{
	t_list	*elem;

	argc--;
	while (argc > 0)
	{
		if (!is_valid(argv[argc]))
			return (-1);
		elem = ft_lstnew(ft_atoi(argv[argc]));
		if (!elem)
			return (-1);
		ft_lstadd_front(a, elem);
		argc--;
	}
	return (0);
}

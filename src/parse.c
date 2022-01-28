/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:55:05 by nthimoni          #+#    #+#             */
/*   Updated: 2022/01/28 16:57:53 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "constantes.h"
#include <limits.h>

static int is_valid(char *s)
{
	int		i;
	size_t	len;

	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			if (i != 0 || (s[i] != '+' && s[i] != '-'))
				return (0);
		i++;
	}
	len = ft_strlen(s);
	if (len > MAX_LEN)
		return (0);
	if (ft_atol(s) > INT_MAX)
		return (0);
	if (ft_atol(s) < INT_MIN)
		return (0);
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

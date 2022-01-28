/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:37:26 by nthimoni          #+#    #+#             */
/*   Updated: 2022/01/28 20:08:40 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

static	void	swap(t_list *s)
{
	int	tmp;

	if (!s || !s->next)
		return ;
	tmp = s->content;
	s->content = s->next->content;
	s->next->content = tmp;
}

void	ss(t_list *a, t_list *b, char *msg)
{
	swap(a);
	swap(b);
	if (msg)
		ft_printf("%s\n", msg);
}

void	p(t_list **from, t_list **to, char *msg)
{
	t_list *tmp;
	tmp = (*from)->next;
	ft_lstadd_front(to, *from);
	*from = tmp;
	if (msg)
		ft_printf("%s\n", msg);
}

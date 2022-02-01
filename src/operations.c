/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:37:26 by nthimoni          #+#    #+#             */
/*   Updated: 2022/01/29 19:29:03 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

void	swap(t_list *s1, t_list *s2, char *msg)
{
	int	tmp;

	if (s1 && s1->next)
	{
		tmp = s1->content;
		s1->content = s1->next->content;
		s1->next->content = tmp;
	}
	if (s2)
		swap(s2, NULL, msg);
	if (msg && !s2)
		ft_printf("%s\n", msg);
}

void	push(t_list **from, t_list **to, char *msg)
{
	t_list *tmp;

	tmp = (*from)->next;
	ft_lstadd_front(to, *from);
	*from = tmp;
	if (msg)
		ft_printf("%s\n", msg);
}

void	rev_rotate(t_list **s1, t_list **s2, char *msg)
{
	t_list	**pre;
	t_list	*last;

	if (s1 && *s1 && (*s1)->next)
	{
		last = *s1;
		pre = &(*s1)->next;
		while (last->next)
		{
			pre = &last->next;
			last = last->next;
		}
		last->next = *s1;
		*s1 = last;
		*pre = NULL;
	}
	if (s2)
		rev_rotate(s2, NULL, msg);
	if (msg && !s2)
		ft_printf("%s\n", msg);
}

void	rotate(t_list **s1, t_list **s2, char *msg)
{
	t_list	*last;

	if (s1 && *s1 && (*s1)->next)
	{
		last = ft_lstlast(*s1);
		last->next = *s1;
		*s1 = (*s1)->next;
		last->next->next = NULL;
	}
	if (s2)
		rotate(s2, NULL, msg);
	if (msg && !s2)
		ft_printf("%s\n", msg);
}

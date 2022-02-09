/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <nthimoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 07:10:51 by nthimoni          #+#    #+#             */
/*   Updated: 2022/02/09 07:18:31 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include "error.h"
#include "operations.h"
#include "sort.h"
#include "buffer.h"


void	print(int a)
{
	ft_printf("%d ", a);
}

void	print_st(t_list *a, t_list *b)
{
	ft_printf("a : ");
	ft_lstiter(a, print);
	ft_printf("\n");
	ft_printf("b : ");
	ft_lstiter(b, print);
	ft_printf("\n");
}

void	operation(char	*op, t_list **a, t_list **b)
{
	int	len;

	len = ft_strlen(op) - 1;
	ft_printf(" %d \n", !ft_strncmp(op, "rr", len));
	if (!ft_strncmp(op, "ra", len) || !ft_strncmp(op, "rr", len))
		rotate(a, NULL, -5);
	if (!ft_strncmp(op, "rb", len) || !ft_strncmp(op, "rr", len))
		rotate(b, NULL, -5);
	if (!ft_strncmp(op, "rra", len) || !ft_strncmp(op, "rrr", len))
		rev_rotate(a, NULL, -5);
	if (!ft_strncmp(op, "rrb", len) || !ft_strncmp(op, "rrr", len))
		rev_rotate(b, NULL, -5);
	if (!ft_strncmp(op, "sa", len) || !ft_strncmp(op, "ss", len))
		swap(*a, NULL, -5);
	if (!ft_strncmp(op, "sb", len) || !ft_strncmp(op, "ss", len))
		swap(*b, NULL, -5);
	if (!ft_strncmp(op, "pa", len))
		push(b, a, -5);
	if (!ft_strncmp(op, "pb", len))
		push(a, b, -5);
}

void	verdict(t_list **a, t_list **b)
{
	t_list *tmp;

	if (*b != NULL)
	{
		ft_printf("KO\n");
		return ;
	}
	tmp = *a;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
		{
			ft_printf("KO\n");
			return ;	
		}
		tmp = tmp->next;
	}
	ft_printf("OK\n");
}

int main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	char	*line;

	a = NULL;
	b = NULL;
	if (parse(&a, argc, argv) != 0)
		error_msg("Error", a, b);
	line = get_next_line(0);
	while (line)
	{
		operation(line, &a, &b);
		free(line);
		print_st(a, b);
		line = get_next_line(0);
	}
	verdict(&a, &b);
	ft_lstclear(&a, NULL);
	ft_lstclear(&b, NULL);	
}

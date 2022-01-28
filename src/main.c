/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:35:20 by nthimoni          #+#    #+#             */
/*   Updated: 2022/01/29 00:37:06 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include "error.h"
#include "operations.h"


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

int main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (parse(&a, argc, argv) != 0)
		error_msg("Erroor during parsing", a, b);
	print_st(a, b);
	rotate(&a, &b, "rr");
	print_st(a, b);
	push(&a, &b, "pb");
	print_st(a, b);
	push(&a, &b, "pb");
	print_st(a, b);
	push(&a, &b, "pb");
	print_st(a, b);
	push(&b, &a, "pa");
	print_st(a, b);
	swap(a, b, "ss");
	print_st(a, b);
	swap(a, NULL, "sa");
	print_st(a, b);
	rotate(&a, NULL, "ra");
	print_st(a, b);
	rotate(&a, &b, "rr");
	print_st(a, b);
	rotate(&a, &b, "rr");
	print_st(a, b);
	push(&b, &a, "pa");
	print_st(a, b);
	rotate(&a, &b, "rr");
	print_st(a, b);
	ft_lstclear(&a, NULL);
	ft_lstclear(&b, NULL);
}

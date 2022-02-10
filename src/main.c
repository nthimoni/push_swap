/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:35:20 by nthimoni          #+#    #+#             */
/*   Updated: 2022/02/10 20:16:13 by nthimoni         ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	size_t	len;

	a = NULL;
	b = NULL;
	if (parse(&a, argc, argv) != 0)
		error_msg("Error", a, b);
	len = ft_lstsize(a);
	if (len == 2 && a->content > a->next->content)
		swap(a, NULL, SA);
	else if (len <= 5 && len >= 3)
		sort_five(&a, &b, len);
	else if (len > 5)
		sort_more(&a, &b, len);
	put_buff(FLUSH);
	ft_lstclear(&a, NULL);
	ft_lstclear(&b, NULL);
}

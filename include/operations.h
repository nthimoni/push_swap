/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 18:19:13 by nthimoni          #+#    #+#             */
/*   Updated: 2022/02/10 20:20:50 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "libft.h"

void	swap(t_list *a, t_list *b, int op);
void	push(t_list **from, t_list **tpush, int op);
void	rotate(t_list **s1, t_list **s2, int op);
void	rev_rotate(t_list **s1, t_list **s2, int op);
int		find_min(t_list *s);
int		find_max(t_list *s);
void	put_nb_top_a(t_list **s, int a);
void	put_nb_top_b(t_list **s, int a);
int		get_sup(t_list *s, int a);
void	insert_fastest_a(t_list **a, t_list **b);
int		count_put_on_top(t_list *s, int a);
void	push_chunk_b(int min, int max, t_list **a, t_list **b);

#endif

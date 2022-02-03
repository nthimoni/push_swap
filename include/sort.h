/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 21:32:35 by nthimoni          #+#    #+#             */
/*   Updated: 2022/02/03 02:02:32 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

#include "libft.h"

typedef struct s_chunk
{
	int	chunk_count;
	int	*chunk;
} 	t_chunk;

void	sort_five(t_list **a, t_list **b, size_t len);
void	sort_more(t_list **a, t_list **b, size_t len);
t_chunk	def_chunk(int chunk_count, t_list *a, size_t len);

#endif

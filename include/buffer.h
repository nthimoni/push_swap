/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 03:16:58 by nthimoni          #+#    #+#             */
/*   Updated: 2022/02/10 20:21:15 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_H
# define BUFFER_H

# define SWAP_BUF_SIZE 300

# define FLUSH -2
# define SA 1
# define SB 2
# define SS 4
# define RA 8
# define RB 16
# define RR 32
# define PA 64
# define PB 128
# define RRA 256
# define RRB 512
# define RRR 1024

void	put_buff(int op);

typedef struct s_rotbuf
{
	int	r_from;
	int	r_to;
	int	rr_from;
	int	rr_to;
}	t_rotbuf;

#endif

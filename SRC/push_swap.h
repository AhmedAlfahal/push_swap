/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:49:14 by aalfahal          #+#    #+#             */
/*   Updated: 2023/03/12 17:22:39 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

typedef struct s_ps
{
	char			**split;
	char			*joined;
	int				c_min;
	int				c_max;
	int				c_size;
	int				dvsr;
	int				size;
	struct s_stack	*s;
	struct s_list	*clone;
}				t_ps;

typedef struct s_stack
{
	struct s_list	*stack_a;
	struct s_list	*stack_b;
}				t_stack;

/**********************************--Moves--***********************************/

void	swap(t_list **stack, int msg);
void	rotate(t_list **stack, int msg);
void	reverse_rotate(t_list **stack, int msg);
void	push(t_list **first, t_list **second, int msg);

/**********************************--Parsing--*********************************/

void	checking_digits(t_ps *ps);

/**********************************--Freeing--*********************************/

void	clean_exit(t_ps *ps, int stack, int join, int ex);
void	free_2d_array(t_ps *ps, int stack);
void	free_stack(t_list **stack);

/**********************************--Sorting--*********************************/

int		is_sorted(t_list *ps, int stackk);
void	sort(t_ps *ps);
void	sort_3nums(t_ps *ps);
void	sort_4to10nums(t_ps *ps, int nums);
void	sort_small(t_ps *ps);
void	sorting_qrt(t_ps *ps, int min, int max);
int		sorted_index(t_list *stack, int val);
int		get_larg(t_list *stack);

#endif
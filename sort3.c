/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:08:20 by aalfahal          #+#    #+#             */
/*   Updated: 2023/02/24 12:44:19 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3nums(t_ps *ps)
{
	if (ps->s->stack_a->content > ps->s->stack_a->next->content \
		&& ps->s->stack_a->next->content > ps->s->stack_a->next->next->content)
	{
		swap(&ps->s->stack_a, 1);
		reverse_rotate(&ps->s->stack_a, 1);
	}
	else if (ps->s->stack_a->content > ps->s->stack_a->next->content \
	&& ps->s->stack_a->next->content < ps->s->stack_a->next->next->content \
	&& ps->s->stack_a->content > ps->s->stack_a->next->next->content)
		rotate(&ps->s->stack_a, 1);
	else if (ps->s->stack_a->content > ps->s->stack_a->next->content \
	&& ps->s->stack_a->next->content < ps->s->stack_a->next->next->content)
		swap(&ps->s->stack_a, 1);
	else if (ps->s->stack_a->content < ps->s->stack_a->next->content \
	&& ps->s->stack_a->next->content > ps->s->stack_a->next->next->content \
	&& ps->s->stack_a->content < ps->s->stack_a->next->next->content)
	{
		reverse_rotate(&ps->s->stack_a, 1);
		swap(&ps->s->stack_a, 1);
	}
	else if (ps->s->stack_a->content < ps->s->stack_a->next->content \
	&& ps->s->stack_a->next->content > ps->s->stack_a->next->next->content \
	&& ps->s->stack_a->content > ps->s->stack_a->next->next->content)
		reverse_rotate(&ps->s->stack_a, 1);
}

void	sort_4to10nums(t_ps *ps, int nums)
{
	while (ft_lstsize(ps->s->stack_b) != nums)
	{
		if (get_larg(ps->s->stack_a) == ps->s->stack_a->content)
			push(&ps->s->stack_a, &ps->s->stack_b, 2);
		else if (sorted_index(ps->s->stack_a, get_larg(ps->s->stack_a)) \
		> ft_lstsize(ps->s->stack_a) / 2)
			reverse_rotate(&ps->s->stack_a, 1);
		else
			rotate(&ps->s->stack_a, 1);
	}
	sort_3nums(ps);
	while (nums-- > 0)
	{
		push(&ps->s->stack_b, &ps->s->stack_a, 1);
		rotate(&ps->s->stack_a, 1);
	}
}

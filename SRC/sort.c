/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 19:27:46 by aalfahal          #+#    #+#             */
/*   Updated: 2023/02/24 17:28:49 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_dev_size(t_ps *ps)
{
	ps->size = ft_lstsize(ps->clone);
	if (ps->size <= 10)
		sort_small(ps);
	if (ps->size > 250)
		ps->dvsr = 8;
	else if (ps->size >= 50 && ps->size <= 250)
		ps->dvsr = 4;
	else if (ps->size < 50)
		ps->dvsr = 1;
}

static void	setting_vals(t_list *tmp, int *val, int index)
{
	while (index >= 0)
	{
		if (index == 0)
			*val = tmp->content;
		tmp = tmp->next;
		index--;
	}
}

static void	sort_clone(t_ps *ps)
{
	t_list	*tmp1;
	t_list	*tmp2;
	int		tmp;

	tmp1 = ps->clone;
	tmp2 = NULL;
	tmp = tmp1->content;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		tmp = tmp1->content;
		while (tmp2)
		{
			if (tmp2->content < tmp)
			{
				tmp1->content = tmp2->content;
				tmp2->content = tmp;
				tmp = tmp1->content;
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}

int	is_sorted(t_list *ps, int stackk)
{
	t_list	*stack;

	stack = ps;
	if (stackk == 1)
	{
		while (stack->next)
		{
			if (stack->content > stack->next->content)
				return (0);
			stack = stack->next;
		}
	}
	else if (stackk == 2)
	{
		while (stack->next)
		{
			if (stack->content < stack->next->content)
				return (0);
			stack = stack->next;
		}
	}
	return (1);
}

void	sort(t_ps *ps)
{
	t_list	*tmp;
	int		index;
	int		i;

	sort_clone(ps);
	set_dev_size(ps);
	ps->c_size = ps->size / ps->dvsr;
	tmp = ps->clone;
	i = ps->dvsr;
	setting_vals(tmp, &ps->c_min, ps->size - ps->c_size);
	setting_vals(tmp, &ps->c_max, ps->size - 1);
	sorting_qrt(ps, ps->c_min, ps->c_max);
	while (--i > 0)
	{
		index = (ps->size * i) / ps->dvsr;
		setting_vals(tmp, &ps->c_min, index - ps->c_size);
		setting_vals(tmp, &ps->c_max, index);
		sorting_qrt(ps, ps->c_min, ps->c_max);
	}
	clean_exit(ps, 3, 0, 0);
}

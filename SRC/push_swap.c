/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:49:06 by aalfahal          #+#    #+#             */
/*   Updated: 2023/02/19 22:23:08 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		i;
	t_ps	ps;
	t_stack	s;

	i = 1;
	ps.joined = NULL;
	s.stack_a = NULL;
	s.stack_b = NULL;
	ps.s = &s;
	ps.clone = NULL;
	ps.split = NULL;
	if (ac >= 2)
	{
		while (av[i])
		{
			if (!ft_isalnum(av[i]))
				clean_exit(&ps, 0, 1, 1);
			ps.joined = ft_strjoin(ps.joined, av[i++]);
		}
		ps.split = ft_split(ps.joined, ' ');
		checking_digits(&ps);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lowerfirst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouajjou <iouajjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:04:04 by iouajjou          #+#    #+#             */
/*   Updated: 2023/12/01 15:52:11 by iouajjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	lower_value(t_pile *pile)
{
	int	lower;

	lower = pile->head;
	pile = pile->next;
	while (pile)
	{
		if (lower > pile->head)
			lower = pile->head;
		pile = pile->next;
	}
	return (lower);
}

int get_last_elem(t_pile *pile)
{
	int last;

	while (pile)
	{
		last = pile->head;
		pile = pile->next;
	}
	return (last);
}

int choose_rotate(t_pile *pile, size_t size)
{
	size_t	count;

	count = 1;
	while (pile->head != lower_value(pile))
	{
		pile = pile->next;
		count++;
		if (count > (size / 2))
			return (1);
	}
	return (0);
}

void	sortlower(t_pile **pile_a, t_pile **pile_b, size_t size)
{
	(void) size;
	while (!testpile(*pile_a))//(pile_size(*pile_a) > size / 2)
	{
		if (lower_value(*pile_a) == (*pile_a)->head)
		{
			push(pile_a, pile_b);
			ft_printf("pb\n");
		}
		else if ((*pile_a)->next && lower_value(*pile_a) == (*pile_a)->next->head)
		{
			swap(pile_a);
			ft_printf("sa\n");
		}
		else
		{
			if (choose_rotate(*pile_a, size))
			{
				reverse_rotate(pile_a);
				ft_printf("rra\n");
			}
			else
			{
				rotate(pile_a);
				ft_printf("ra\n");
			}
		}
	}
	while (pile_size(*pile_b) > 0)
	{
		push(pile_b, pile_a);
		ft_printf("pa\n");
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouajjou <iouajjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:45:31 by iouajjou          #+#    #+#             */
/*   Updated: 2024/02/05 17:28:55 by iouajjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ishalf(size_t index, size_t size)
{
	if (index == size / 2)
		return (1);
	if (index == (size / 2) + 1)
		return (1);
	if (index == (size / 2) - 1)
		return (1);
	return (0);
}

void	sort_two(t_stack **stack)
{
	rotate(stack);
	ft_printf("ra\n");
}

void	sort_three(t_stack **stack)
{
	while (!is_sort(*stack))
	{
		if ((*stack)->nb > (*stack)->next->nb
			&& (*stack)->nb > (*stack)->next->next->nb)
		{
			rotate(stack);
			ft_printf("ra\n");
		}
		else if ((*stack)->nb > (*stack)->next->nb)
		{
			swap(stack);
			ft_printf("sa\n");
		}
		else if ((*stack)->nb > (*stack)->next->next->nb)
		{
			reverse(stack);
			ft_printf("rra\n");
		}
		else
		{
			rotate(stack);
			ft_printf("ra\n");
		}
	}
}

void	clean(t_stack **stack, t_stack **bstack)
{
	size_t	size;

	size = sizestack(*stack);
	while (sizestack(*stack) > 3)
	{
		if (ishalf((*stack)->index, size))
		{
			rotate(stack);
			ft_printf("ra\n");
		}
		else
		{
			push(stack, bstack);
			ft_printf("pb\n");
		}
	}
	if (sizestack(*stack) == 2)
		sort_two(stack);
	sort_three(stack);
}

void	sort(t_stack **stack)
{
	t_stack	*bstack;

	bstack = NULL;
	clean(stack, &bstack);
	if (bstack)
	{
		repush(stack, &bstack);
		freestack(bstack);
	}
}

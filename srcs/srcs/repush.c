/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repush.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouajjou <iouajjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:29:55 by iouajjou          #+#    #+#             */
/*   Updated: 2024/02/05 17:28:55 by iouajjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_cost(t_stack *stack, t_stack *bstack)
{
	t_stack	*head;
	int		pos;

	head = bstack;
	pos = 0;
	while (bstack)
	{
		if (bstack->target > (int)sizestack(stack) / 2)
			bstack->cost_a = ((int)sizestack(stack) - bstack->target) * (-1);
		else
			bstack->cost_a = bstack->target;
		if (pos > (int)sizestack(head) / 2)
			bstack->cost_b = ((int)sizestack(head) - pos) * (-1);
		else
			bstack->cost_b = pos;
		bstack = bstack->next;
		pos++;
	}
}

t_stack	*get_minus_cost(t_stack *bstack)
{
	t_stack	*minus;

	minus = bstack;
	bstack = bstack->next;
	while (bstack)
	{
		if (abs(bstack->cost_a) + abs(bstack->cost_b) < abs(minus->cost_a)
			+ abs(minus->cost_b))
			minus = bstack;
		bstack = bstack->next;
	}
	return (minus);
}

void	push_minus(t_stack **stack, t_stack **bstack)
{
	t_stack	*minus;

	minus = get_minus_cost(*bstack);
	while (minus->cost_b < 0 && minus->cost_a < 0)
	{
		reverse_both(stack, bstack);
		ft_printf("rrr\n");
		minus->cost_b++;
		minus->cost_a++;
	}
	while (minus->cost_b > 0 & minus->cost_a > 0)
	{
		rotate_both(stack, bstack);
		ft_printf("rr\n");
		minus->cost_b--;
		minus->cost_a--;
	}
	do_simple(minus, stack, bstack);
	push(bstack, stack);
	ft_printf("pa\n");
}

int	to_end(t_stack *stack)
{
	int	rota;
	int	value;
	int	pos;

	pos = 0;
	rota = 0;
	value = stack->nb;
	while (stack)
	{
		if (stack->nb < value)
		{
			value = stack->nb;
			rota = pos;
		}
		pos++;
		stack = stack->next;
	}
	return (rota);
}

void	repush(t_stack **stack, t_stack **bstack)
{
	int	rota;

	while (*bstack)
	{
		get_all_target(*stack, *bstack);
		get_cost(*stack, *bstack);
		push_minus(stack, bstack);
	}
	rota = to_end(*stack);
	if (rota > (int)sizestack(*stack))
		rota = ((int)sizestack(*stack) - rota) * (-1);
	while (rota > 0)
	{
		rotate(stack);
		rota--;
		ft_printf("ra\n");
	}
	while (rota < 0)
	{
		reverse(stack);
		rota++;
		ft_printf("rra\n");
	}
}

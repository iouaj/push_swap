/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouajjou <iouajjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:53:03 by iouajjou          #+#    #+#             */
/*   Updated: 2023/12/01 14:37:40 by iouajjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int isint(char *value, char *maxi)
{
	size_t	i;

	i = 0;
	while (value[i])
		i++;
	if (i > 10)
		return (0);
	if (i < 10)
		return (1);
	i = 0;
	while (i < 10)
	{
		if (value[i] > maxi[i])
			return (0);
		if (value[i] < maxi[i])
			return (1);
		i++;
	}
	return (1);
}

int	isnb(char *value)
{
	size_t	i;

	i = 0;
	if (!value)
		return (0);
	if (value[0] == '-')
		i++;
	while (value[i])
	{
		if (!ft_isdigit(value[i]))
			return (0);
		i++;
	}
	if (value[0] == '-')
		return (isint(value + 1, "2147483648"));
	return (isint(value, "2147483647"));
}

void printpile(t_pile *pile)
{
	while (pile)
	{
		ft_printf("Pile : %d\n", pile->head);
		pile = pile->next;
	}
}

int	testpile(t_pile *pile)
{
	int temp;

	if (!pile)
		return (0);
	while (pile->next)
	{
		temp = pile->head;
		if (temp > pile->next->head)
			return (0);
		pile = pile->next;
	}
	return (1);
}

int main(int argc, char *argv[])
{
	size_t	i;
	t_pile	*pile_a;
	t_pile	*pile_b;

	pile_a = NULL;
	pile_b = NULL;
	if (argc == 1)
		return (0);
	i = argc - 1;
	while (i > 0)
	{
		if (!addpile(&pile_a, newpile(argv[i])))
		{
			freepile(pile_a);
			return (0);
		}
		i--;
	}
	if (testpile(pile_a))
	{
		freepile(pile_a);
		return (0);
	}
	// printpile(pile_a);
	// ft_printf("===ROTATE===\n");
	// swap(&pile_a);
	// printpile(pile_a);
	// ft_printf("==PILE B==\n");
	// printpile(pile_b);
	sortlower(&pile_a, &pile_b, pile_size(pile_a));
	// if (testpile(pile_a))
	// 	ft_printf("W");
	//printpile(pile_a);
	freepile(pile_a);
	return (0);
}

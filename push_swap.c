/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouajjou <iouajjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:53:03 by iouajjou          #+#    #+#             */
/*   Updated: 2023/11/17 18:28:21 by iouajjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_pile *newpile(char value)
{
	t_pile *new;

	if (!ft_isdigit(value))
		return (NULL);
	new = malloc(sizeof(t_pile));
	new->head = value - 48;
	new->next = NULL;
	return (new);
}

void addpile(t_pile **pile, t_pile *new)
{
	new->next = *pile;
	*pile = new;
}

void printpile(t_pile *pile)
{
	while (pile)
	{
		ft_printf("%d", pile->head);
		pile = pile->next;
	}
}

int main(int argc, char *argv[])
{
	size_t	i;
	t_pile	*pile;

	pile = NULL;
	if (argc == 1)
		return (0);
	i = 1;
	while (i < argc)
	{
		addpile(&pile, newpile(argv[i][0]));
		i++;
	}
	printpile(pile);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouajjou <iouajjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:04:03 by iouajjou          #+#    #+#             */
/*   Updated: 2023/11/29 18:15:57 by iouajjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int inpile(t_pile *pile, int value)
{
	while (pile)
	{
		if (pile->head == value)
			return (1);
		pile = pile->next;
	}
	return (0);
}

t_pile	*newpile(char *value)
{
	t_pile	*new;

	if (!isnb(value))
		return (NULL);
	new = malloc(sizeof(t_pile));
	new->head = ft_atoi(value);
	new->next = NULL;
	return (new);
}

size_t	pile_size(t_pile *pile)
{
	size_t	i;

	i = 0;
	while (pile)
	{
		i++;
		pile = pile->next;
	}
	return (i);
}

void freepile(t_pile *pile)
{
	t_pile	*temp;

	while (pile)
	{
		temp = pile->next;
		free(pile);
		pile = temp;
	}
}

int	addpile(t_pile **pile, t_pile *new)
{
	if (!new || inpile(*pile, new->head))
	{
		freepile(*pile);
		ft_putendl_fd("Error", 2);
		exit(EXIT_FAILURE);
		return (0);
	}
	new->next = *pile;
	*pile = new;
	return (1);
}

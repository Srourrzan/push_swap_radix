/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:29:56 by rsrour            #+#    #+#             */
/*   Updated: 2024/12/28 15:25:58 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_node(int content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

void	insert_node_back(t_list **root, int content)
{
	t_list	*node;
	t_list	*currt;

	node = create_node(content);
	if(!node)
		return ;
	if (*root == NULL)
	{
		*root = node;
		return ;
	}
	currt = *root;
	while (currt->next != NULL)
	{
		currt = currt->next;
	}
	currt->next = node;
}

void	insert_node_front(t_list **root, int content)
{
	t_list	*node;

	node = create_node(content);
	if (!*root)
		*root = node;
	node->next = *root;
	*root = node;
}

int		len_list(t_list **root)
{
	int		len;
	t_list		*curr;

	len = 0;
	if (!root || !(*root))
		return (0);
	curr = *root;
	while(curr)
	{
		curr = curr->next;
		len++;
	}
	return (len);
}

void	delete_list(t_list **root)
{
	t_list	*curr = *root;
	t_list  *pre_node;

	while (curr != NULL)
	{
		pre_node = curr;
		curr = curr->next;
		free(pre_node);
	}
	*root = NULL;
}

// int	main()
// {
// 	t_list *root = NULL;
// 	insert_node_back(&root, 6);
// 	printf("root cont = %d\n", root->content);
// 	return(0);
// }
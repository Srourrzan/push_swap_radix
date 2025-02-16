/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:29:56 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/16 16:35:17 by codespace        ###   ########.fr       */
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

int insert_node_back(t_list **root, int content)
{
    t_list  *node;
    t_list  *currt;

    node = create_node(content);
    if (!node)
    {
        delete_list(root);
        return (0);  // Return 0 for failure
    }
    if (*root == NULL)
    {
        *root = node;
        return (1);  // Return 1 for success
    }
    currt = *root;
    while (currt->next != NULL)
        currt = currt->next;
    currt->next = node;
    return (1);
}

void	insert_node_front(t_list **root, int content)
{
	t_list	*node;

	node = create_node(content);
	if (!*root)
	{
		*root = node;
		return;
	}
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

// void	delete_list(t_list **root)
// {
// 	t_list	*curr = *root;
// 	t_list  *pre_node;

// 	while (curr != NULL)
// 	{
// 		pre_node = curr;
// 		curr = curr->next;
// 		free(pre_node);
// 	}
// 	*root = NULL;
// }

void delete_list(t_list **root)
{
    t_list *current;
    t_list *next;

    if (!root || !*root)
        return;
        
    current = *root;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *root = NULL;
}
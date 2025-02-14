/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:29:58 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/13 23:58:04 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

typedef struct	s_info
{
	t_list			*head;
	int				size;
}					t_info;

typedef struct	s_status
{
	int				status_1;
	int				status_2;
}				t_status;

t_list				*create_node(int content);
void				insert_node_back(t_list **root, int content);
void				insert_node_front(t_list **root, int content);
void				delete_list(t_list **root);
void				ft_putchar(char ch, int fd);
void				ft_putnbr(int nbr, int fd);
void				ft_display_stack(t_list **root, char name, int fd);
void				ft_putstr(char *src, int fd);
void				ft_display_stacks(t_list **a, t_list **b, int fd);
void				ft_correct_space_display(t_list *node, int fd);
void				ft_fill_stack(t_list **root, char **numbers, int argc, int fd);

void				swap(t_list **root);
void				ss(t_list **root_a, t_list **root_b);
int    				ft_ascend_swap(t_list **a, t_list **b, int counter, int fd);
int					ft_decscend_swap(t_list ** a, t_list **b, int counter, int fd);

void				push(t_list **src_list, t_list **dst_list);
int 				ft_ascend_push(t_list **a, t_list **b, int counter, int fd);
int					ft_descend_push(t_list **a, t_list **b, int counter, int fd);

void				rotate(t_list **root);
void				rr(t_list **root_a, t_list **root_b);
void				reverse_rotate(t_list **root);
void				rrr(t_list **root_a, t_list **root_b);
int					ft_dascend_rotate(t_list **a, t_list **b, int counter, int fd);
int 				ft_ascend_reverse_rotate(t_list **a, t_list **b, int counter, int fd);
int 				ft_descend_reverse_rotate(t_list **a, t_list **b, int counter, int fd);

int					ft_atoi(char *src, t_list **root, char **dup_num);            
int     			ft_is_number(char *src);
int     			ft_is_dup(char **dup_num, char *number);
void				ft_exit(t_list **root, char **arr, int exit_number);
int					len_list(t_list **root);
int     			ft_strcmp(const char *s1, const char *s2);
char 				*ft_strdup(const char *s);
int					ft_strlen(const char *s);
void				ft_init_array(char **src, int size);
void    			ft_free_str_array(char **arr);

void				ft_sort_list(t_info **a_info, t_list **b, int fd);
int					ft_ascend_check(t_list  **a);
int					ft_descend_check(t_list **b);
int					ft_sort_list_ascend(t_list **a, t_list **b, int counter, int fd);
int					ft_sort_list_descend(t_list **b, t_list **a, int counter, int fd);

t_info  			*ft_stack_info(t_list *stack);

// int    ft_split_stack(t_list **stack_a, int counter, int fd);
// t_list    *ft_merge_stack(t_list **stack_1, t_list **stack_2, int fd);

// //divide methods
// int 	ft_ascend_rr_splited_stack(t_list **head, t_list **midd, int counter, int fd);

#endif
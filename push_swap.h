/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:29:58 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/16 16:38:02 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	int				index;
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
int					insert_node_back(t_list **root, int content);
void				insert_node_front(t_list **root, int content);
void				delete_list(t_list **root);
void				ft_putchar(char ch, int fd);
void				ft_putnbr(int nbr, int fd);
void				ft_putstr(char *src, int fd);
void				ft_fill_stack(t_list **root, char **numbers, int argc);

void				swap(t_list **root);
void				ss(t_list **root_a, t_list **root_b);

void				push(t_list **src_list, t_list **dst_list);
void 				ft_ascend_push(t_list **a, t_list **b, int fd);
void				ft_descend_push(t_list **a, t_list **b, int fd);

void				rotate(t_list **root);
void				rr(t_list **root_a, t_list **root_b);
void				reverse_rotate(t_list **root);
void				rrr(t_list **root_a, t_list **root_b);

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

void				ft_sort_list(t_info *a_info, t_list **b);
int					ft_ascend_check(t_list  **a);

t_info  			*ft_stack_info(t_list *stack);
void				ft_three_sort(t_info *a_info);
void    			ft_three_stack_conditions(t_info *a_info, int n1, int n2, int n3);
void    			ft_five_sort(t_info *a_info, t_list **b);
int    				ft_find_min_index(t_list **root);
void    			ft_move_min_to_top(t_info *a_info, int size);

void    			ft_large_sort(t_info *a_info, t_list **b);

#endif
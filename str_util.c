/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 20:20:45 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/13 20:20:53 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     ft_strcmp(const char *s1, const char *s2)
{
    unsigned int    iter;

    iter = 0;
    while((s1[iter] && s2[iter]) && s1[iter] == s2[iter])
        iter++;
    return (s1[iter] - s2[iter]);
}

char    *ft_strdup(const char *s)
{
    int     iter;
    int     len;
    char    *buff;

    iter = 0;
    len = ft_strlen(s);
    buff = malloc(sizeof(char *) * (len + 1));
    if(!buff)
        return NULL;
    while(s[iter] != '\0')
    {
        buff[iter] = s[iter];
        iter++;
    }
    buff[iter] = '\0';
    return(buff);
}

int     ft_strlen(const char *s)
{
    int     len;

    len = 0;
    while (s[len] != '\0')
        len++;
    return (len);
}

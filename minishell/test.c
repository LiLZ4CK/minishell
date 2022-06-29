/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:53:58 by zwalad            #+#    #+#             */
/*   Updated: 2022/06/29 16:21:15 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
int main(int ac, char **av)
{
    char *str = "/bin/echo";
    char *sstr[]= {"bin/echo", "fs;dsss", NULL};
    execve(str, sstr, NULL);
}
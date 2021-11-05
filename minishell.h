/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:13:12 by oidrissi          #+#    #+#             */
/*   Updated: 2021/11/05 15:29:55 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H


#include <stdio.h>
#include <strings.h>
#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

#define BUFFER_SIZE 1024
#define RIGHT 10
#define LEFT 11
#define DOUBLE_RIGHT 12
#define DOUBLE_LEFT 13

typedef struct s_redir
{
	char	*file;
	int		type;
	struct s_redir *next;
}	t_redir;

typedef struct s_cmd
{
    char **args;
    t_redir red;
    struct s_cmd *next;
	struct s_cmd *prev;
}   t_cmd;

#endif
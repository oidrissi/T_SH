/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 16:16:50 by oidrissi          #+#    #+#             */
/*   Updated: 2021/11/01 13:38:05 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minishell.h"
#include <stdio.h>

// Order tokens in 2d array
// Enter value : char *readline_result;
// return value : char **list_token;

char    *in_quotes(char *s)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (s[i] == '\"')
        {
			t_sh->quotes = 1;
            return (&s[i]);
        else if (s[i] == '\'')
            return (&s[i]);
        i++;
    }
    return (NULL);
}



// char    **ft_tokenizer(char *rdline_res)
// {
//     char **list_token;
//     int i;
    
//     i = 0;
//     list_token = malloc(sizeof(t_token *));
//     while(rdline_res[i][j])
//     {
//         if (in_quote(&token) && has_a_match(&token, &i))
            
//     }
// }

int main(int ac, char **av)
{
    char str[] = "My name is \"hello\" World";
    char *s = in_quotes(str);
    printf("%s\n", s);
}
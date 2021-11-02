/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 16:16:50 by oidrissi          #+#    #+#             */
/*   Updated: 2021/11/02 21:55:28 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minishell.h"
#include <stdio.h>
#include <strings.h>
#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>

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
        // {
			// t_sh->quotes = 1;
            return (&s[i]);
        else if (s[i] == '\'')
            return (&s[i]);
        i++;
    }
    return (NULL);
}

int    length_quote(char *s)
{
    int i;
    char *v;
    
    v = in_quotes(s);
    i = 1;
    while (v[i])
    {
        if (v[i] == '\"')
            return (i);
        i++;
    }
    return (0);
}

int ft_strlen(char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

char    *trim_quote(char *s)
{
    unsigned int i;
    char *v;

    v = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
    s = in_quotes(s);
    i = 0;
    while (i <= length_quote(s))
    {
        v[i] = s[i];
        i++;
    }
    v[i] = '\0';
    return (v);
}

// char **split()
// {
    
// }



int count_cmds(char *s)
{
    int i;
    int j;
    int word;
    
    word = 1;
    i = 0;
    j = 0;
    // if (s[i])
    while (s[i])
    {
        if (s[i] == '|' && s[i + 1])
        {
            while (j != i)
            {
                if (s[j] != ' ')
                    break;
                j++;
            }
            if (j == i)
                return -1;
            // while (j != i)
            // {
                
            //     j++;   
            // }
            word++;
        }   
        i++;
    }
    return (word);
}

static	char	**ft_free(char **f, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
		free(f[i++]);
	free(f);
	return (NULL);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*p;
	int				i;
	unsigned int	bigg;

	i = 0;
	bigg = start;
	if (!s || start > ft_strlen(s))
	{
		p = malloc(1 * sizeof(char));
		p[0] = '\0';
		return (p);
	}
	p = malloc((len + 1) * sizeof(char));
	if (p == 0)
		return (NULL);
	while ((start < (unsigned int)len + bigg && s[start]))
	{
		p[i] = s[start];
		start++;
		i++;
	}
	p[i] = '\0';
	return (p);
}

int ft_cmd_len(char *s, char c)
{
    int i;

    i = 0;
    while (s[i] && s[i] != c)
        i++;
    return (i);
}

int is_between_quotes(char *s)
{
    int i;

    i = 0;
	j = 0;
    while (s[i])
    {
        if (s[i] == '\"')
		{
			ft_substr(s, i, )
			i++;
			while (s[i])
				i++;
		}
		i++;   
    }
}

char **commands(char *s)
{
    int i;
    int j;
    char **cmds;
    int nb_elems;
    int cmd_len;

    i = 0;
    j = 0;
    nb_elems = count_cmds(s);
    if (nb_elems == -1)
        return NULL;
    cmds = (char **)malloc(sizeof(char *) * (nb_elems + 1));
    printf("%d\n", nb_elems);
    while (i < nb_elems)
    {
        while (s[j] == '|' && )
            j++;
        cmd_len = ft_cmd_len((char *)s + j, '|');
        cmds[i] = ft_substr(s, j, cmd_len);
        if  (!cmds)
            return (ft_free(cmds, i));
        i++;
        j += cmd_len + 1;
    }
    cmds[nb_elems] = NULL;
    return (cmds);
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

// int check_error(char *s)

int main(int ac, char **av)
{
    char *ret;
    char *prompt;
    char **tokens;
    int		i;
    
    prompt = ">";
    while (1)
    {
	    i = 0;
        ret = readline(prompt);
        if (*ret)
            add_history(ret);
        tokens = commands(ret);
        if (!tokens)
        {
            write(1, "error\n", 6);
            continue ;
        }
        while (tokens[i])
        {
            printf("Token is: %s\n", tokens[i]);
            i++;
        }
    }
}
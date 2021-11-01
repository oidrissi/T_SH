/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:26:28 by oidrissi          #+#    #+#             */
/*   Updated: 2021/10/21 16:15:28 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minishell.h"
#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <stdbool.h>

#define BUFFER_SIZE 4096
#define TRUE 1
#define FALSE 0

typedef struct  s_work
{
    int sgl;
    int dbl;
}   t_work;

t_work work;

char    *ft_putstr(char *s)
{
    int i;

    i = 0;
    while (s[i])
    {
        write(1, &s[i], 1);
        i++;
    }
    return (NULL);
}

int    ft_strlen(char *s)
{
    int i;

    if (!s)
        return (0);
    i = 0;
    while (s[i])
        i++;
    return (i);
}

void    display_prompt(void)
{
    char    *cwd;
    char    buff[BUFFER_SIZE + 1];
    // char    *parsed_cwd;

    cwd = getcwd(buff, BUFFER_SIZE);
    // parsed_cwd = parse_hm_path(cwd, 0);
    // ft_putstr(cwd);
    // free(parsed_cwd);
    ft_putstr("\033[32mS\033[0m\033[32mH\033[0m\033[32mE");
	ft_putstr("\033[0m\033[32mL\033[0m\033[32mL\033[0m$ ");
}

bool is_out_of_quotes(char *s, int i)
{
    while (s[i])
	{
		if (s[i] == '\"')
			return (FALSE);
		i++;
	}
    return (TRUE);
}

int is_in_quotes(char *s, int *i)
{
    if (s[*i] == '\"')
    {
        *i += 1;
        while (s[*i] != '\"')
            i++;
        return (1);
    }
    return (0);
}

char    *ft_substr(char *s, int start, size_t len)
{
    int i;
    char *new;

    if (!s)
        return (NULL);
    i = 0;
    new = malloc(sizeof(char *) * len + 1);
    if (!new)
        return (NULL);
    while (len)
    {
        new[i++] = s[start++];
        len--;
    }
    new[i] = '\0';
    return (new);
}

// char    *skip_space(char *s, int *i)
// {
    
// }

int		ft_countwords(char *s, char c)
{
	int words;
	int word;
	int i;
	
	i = 0;
	words = 1;
	while (s[i])
	{
        while (s[i] == '\'')
		{
			work.sgl++;
			i++;
		}
        while (s[i] == '\"')
        {
            work.dbl++;
            i++;
        }
        if (s[i] == c && (work.sgl % 2 == 0) && (work.dbl % 2) == 0)
            words++;
        i++;
	}
	return (words);
}

int     ft_word_len(char *s, char c)
{
    int i;
    int len;

    i = 0;
    while (s[i])
    {
        while (s[i] == '\'')
		{
			work.sgl++;
			i++;
		}
        while (s[i] == '\"')
        {
            work.dbl++;
            i++;
        }
        if (s[i] == c && (work.sgl % 2 == 0) && (work.dbl % 2) == 0)
            len = i + 1;
        i++;
    }
    return (len);
}

char    **ft_split(char *s, char c, t_work work)
{
    int i;
    int j;
    char **new;
    int len_s;
	int words;
    static int start;
    
    start = 0;
    i = 0;
    j = 0;
    int dbl = 0;
    int sgl = 0;
    words = ft_countwords(s, c);
    new = (char **)malloc(sizeof(char *) * (words + 1));
	// printf("Number of words : %d\n", words);
    while (i < words)
    {
        // while (s[j] != c)
        //     j++;
        // while (s[j] == c)
        //     j++;
        while(s[j] == c)
        len_s = ft_word_len((char *)s + j, c);
        printf("%d\n", len_s);
        if (j <= 0)
            new[i] = ft_substr(s, j, len_s);
        else
            new[i] = ft_substr(s, j - 1, len_s + 1);
        // new[i] = ft_substr(s, j, len_s + 1);
        // new[i][j] = '\0';
        i++;
        j += len_s + 1;
    }
	new[words] = NULL;
    return (new);
}

int main(int ac, char **av)
{
    char *ret;
    char *prompt;
    char **tokens;
    int		i;
    
    work.sgl = 0;
    work.dbl = 0;
	i = 0;
    prompt = "\033[32mS\033[0m\033[32mH\033[0m\033[32mE\033[0m\033[32mL\033[0m\033[32mL\033[0m$ ";
    while (1)
    {
        ret = readline(prompt);
        tokens = ft_split(ret, ' ', work);
        while (tokens[i])
        {
			printf("%s\n", tokens[i]);
            i++;
        }
        // display_prompt();
        // while (tokens[i])
    }
        // display_prompt();
}
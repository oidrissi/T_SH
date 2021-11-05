/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 16:16:50 by oidrissi          #+#    #+#             */
/*   Updated: 2021/11/05 15:45:05 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_strlen(char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

int count_cmds(char *s, char c)
{
    int i;
    int j;
    int sgl;
    int dbl;
    int command;
    
    sgl = 0;
    dbl = 0;
    command = 1;
    i = 0;
    j = 0;
    while (s[i])
    {
        if (s[i] == '\"')
		{
            dbl++;
			i++;
		}
        if (s[i] == '\'')
		{
            sgl++;
			i++;
		}
		if (s[i] == c && s[i + 1] && (dbl % 2 == 0) && (sgl % 2 == 0))
        {
            while (j != i)
            {
                if (s[j] != ' ')
                    break;
                j++;
            }
            if (j == i)
                return (-1);
            command++;
        }
        i++;
    }
    return (command);
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
	int sgl;
	int dbl;
	
	sgl = 0;
	dbl = 0;
    i = 0;
    while (s[i])
	{
		if (s[i] == '\"')
		{
            dbl++;
			i++;
		}
        if (s[i] == '\'')
		{
            sgl++;
			i++;
		}
		if (s[i] == c && (sgl % 2 != 0) && (dbl % 2 != 0))
			i++;
		else if (s[i] == c && (sgl % 2 == 0) && (dbl % 2 == 0))
			return (i);
		i++;	
	}
    return (i);
}

char **commands(char *s, char c)
{
    int i;
    int j;
    char **cmds;
    int nb_elems;
    int cmd_len;
    int insgl = 0;
    int indbl = 0;

    i = 0;
    j = 0;
    nb_elems = count_cmds(s, c);
    printf("Number of elements is %d\n", nb_elems);
    if (nb_elems == -1)
        return NULL;
    cmds = (char **)malloc(sizeof(char *) * (nb_elems + 1));
    while (i < nb_elems)
    {
		while (s[j] == ' ')
			j++;
		if (s[j] == c && s[j + 1] == c)
			return (NULL);
        while (s[j] == c)
            j++;
		
        cmd_len = ft_cmd_len((char *)s + j, c);
        cmds[i] = ft_substr(s, j, cmd_len);
        if  (!cmds)
            return (ft_free(cmds, i));
        i++;
        j += cmd_len + 1;
    }
    cmds[nb_elems] = NULL;
    return (cmds);
}

int main(int ac, char **av)
{
    char *ret;
    char *prompt;
    t_cmd cmd;
    int		i;
    
    prompt = ">";
    while (1)
    {
	    i = 0;
        ret = readline(prompt);
        if (*ret)
            add_history(ret);
        cmd.args = commands(ret, '|');
        if (!cmd.args)
        {
            write(1, "error\n", 6);
            continue ;
        }
        while (cmd.args[i])
        {
			printf("%s\n", cmd.args[i]);
			i++;
        }
    }
}
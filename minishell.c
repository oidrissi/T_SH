#include <stdio.h>
#include <readline/readline.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

size_t ft_strlen(char *s)
{
    int i;

    if (!s)
        return (0);
    i = 0;
    while (s[i])
        i++;
    return (i);
}

char	*ft_substring(char *s, unsigned int start, size_t len)
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

int 	out_of_quotes(char *s)
{
	int i = 0;


	while (s[i])
	{
		if (s[i] != '\'' || s[i] != '\"')
			return (1);
		i++;
	}
	return (0);
}

int		ft_countwords(char *s, char c)
{
	int words;
	int word;
	int i;
	
	word = 1;
	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != '\"')
		{
			if (s[i] == c)
				word = 1;
			else if (word == 1)
			{
				word = 0;
				words++;
			}
			i++;
		}
		else if (s[i] == '\"')
		{
			i++;
			while (s[i] && s[i] != '\"')
				i++;
			words++;
		}
		i++;
	}
	return (words);
}

// char *join_between_quotes(char *s)
// {
// 	int i = 0;
// 	while (s[i])
// 	{
// 		if (s[i] == )
// 	}
// }

char **ft_split_with_quotes(char *s, char c)
{
	char **ret;
	int i;
	int insgl = 0;
	int indbl = 0;
	int last = 0;
	i = 0;

	while (s[i])
	{
		while (s[i] == '\'')
		{
			insgl++;
			i++;
		}
		while (s[i] == '\"')
		{
			indbl++;
			i++;
		}
		if (s[i] == c && (insgl %2 == 0) && (indbl % 2 == 0))
			// printf("No quotes");
			ft_substring(s, 0, i);
		else
			printf("%c", s[i]);
		i++;
	}
	return NULL;
}

// static	size_t ft_db_quotes_len(char *s)
// {
// 	size_t i;
// 	size_t count;

// 	i = 0;
// 	count = 0;
// 	while (s[i])
// 	{
// 		if (s[i] == '\"' && s[i + 1] != '\0')
// 		{	
// 			i++;
// 			while (s[i] != '\"')
// 			{
// 				i++;
// 				if (s[i] == ' ')
// 					i++;
// 			}
// 			count += 1;
// 		}
// 		else if (s[i] == ' ' && s[i + 1] != '\"')
// 			count += 1;
// 		i++;
// 	}
// 	return (count);
// }

static	size_t	ft_word_len(char *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	if (out_of_quotes(s))
	{
		while (s[i] != c && s[i])
		{
			i++;
			len++;                                                                                                                                                                  
		}
	}
	else
	{
		while (s[i])
		{
			i++;
			len++;
		}
	}
	return (len);
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

// char	*in_quotes(char *s)
// {
// 	int i = 0;
// 	int start;
// 	char *new;
// 	char *new_db;

// 	new = malloc(sizeof(char ) * ft_strlen(s) + 1);
// 	while (s[i])
// 	{
// 		if (s[i] == '\'')
// 		{
// 			start = i;
// 			i += 1;
// 			// if (s[i] == '\'')
// 				//special case
// 			while (s[i] != '\'')
// 				i++;
// 			new = ft_substring(s, start, i);
// 			new[i] = '\0';
// 			// token->single_quotes += 1
// 			return (new);
// 		}
// 		else if (s[i] == '\"')
// 		{
// 			i +=1;
// 			while (s[i] != '\'')
// 				i++;
// 			return (s);
// 			// token->db_quotes += 1;
// 		}
// 		i++;
// 	}
// 	return NULL;
// }

// char 	**ft_tokenizer(char *s)
// {
// 	int i;
// 	int j;
// 	int **new;

// 	i = 0;
// 	j = 0;
// 	new = malloc(sizeof(char *) * (ft_strlen(s)));
// 	while (s[i])
// 	{
// 		if (out_of_quotes(s) != NULL)
// 			*new[i] = ;
// 		// printf("%s", s);
// 		// new[i] = ft_substr(s, 0, j);
// 		i++;
// 	}
// 	return NULL;
// }

char	**ft_split(char *s, char c)
{
	size_t		i;
	size_t		countw;
	size_t		l_count;
	size_t		j;
	char		**p;

	i = 0;
	j = 0;
	l_count = 0;
	// if (is_quotes(s))
	// countw = ft_db_quotes_len(s);
	countw = ft_countwords((char *)s, c);
	printf("Number of words %zu: \n", countw);
	p = (char **)malloc(sizeof(char *) * (countw + 1));
	int insgl = 0;
	int indbl = 0;
	int last = 0;
	i = 0;
	while (i < countw)
	{
		while (s[j] == c)
			j++;
		l_count = ft_word_len((char *)s + j, c);
		// printf("Length of words %zu: \n", l_count);
		p[i] = ft_substring(s, j, l_count);
		if (!p)
			return (ft_free(p, i));
		i++;
		j += l_count + 1;
	}
	p[countw] = NULL;
	return (p);
}

void	free_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

// int	is_builtin(char *token)
// {
// 	if (strncmp(token, "echo"))
// 		ft_echo(g_info);
// 	if (strncmp(token, "cd"))
// 		ft_cd(g_info);
// 	if (strncmp(token, "pwd"))
// 		ft_pwd(g_info);
// 	if (strncmp(token, "export"))
// 		ft_export(g_info);
// 	if (strncmp(token, "unset"))
// 		ft_unset(g_info);
// 	if (strncmp(token, "env"))
// 		ft_env(g_info);
// 	if (strncmp(token, "exit"))
// 		ft_exit(g_info);
// 	return (0);
// }

int is_quotes(char **tokens, int i, int j)
{
	if (tokens[i][j] == '\"')
	{
		printf("Double Quotes found\n");
	}
	if (tokens[i][j] == '\'')
		printf("Single Quotes found\n");
	return (0);
}

int is_redir(char **tokens, int i, int j)
{
	if (tokens[i][j] == '>')
	{
		j += 1;
		if (tokens[i][j] == '>')
			printf("Double Right redir found\n");
		else
			printf("Right redir found\n");
	}	
	if (tokens[i][j] == '<')
	{
		j += 1;
		if (tokens[i][j] == '>')
			printf("Double Left redir found\n");
		else
			printf("Left redir found\n");
	}
	return (0);
}

int main(int ac, char **av, char **envp)
{
    char *ret_read;
    char *prompt;
    char **tokens;
    int i;
    int pipe = 0;
    i = 0;
    prompt = ">";
    while (1)
    {
        ret_read = readline(prompt);
		// *tokens = in_quotes(ret_read);
		// printf("%s", *tokens);
        if (!ret_read)
            return (0) ;
		// tokens = ft_tokenizer(ret_read);
        tokens = ft_split(ret_read, ' ');
        while (tokens[i])
        {
			// Parsing tokens
			int j = 0;
			// is_quotes(tokens, i, j);
			is_redir(tokens, i, j);
            if (tokens[i][j] == '|')
            {
				j += 1;
                pipe = 1; // need to execute the pipe everytime incremented set by one
				if (pipe == 1 && tokens[i][j] != '|')
					pipe = 0;
				else
					break ;
                printf("pipe found\n");
            }
			// if (is_builtin(tokens[i]))
			// {
			// 	continue ;
			// }
            // // free(tokens[i]);
			else
            	printf("Token %d is %s |\n", i, tokens[i]);
            i++;
        }
        i = 0;
        free(tokens);
    }
    free(ret_read);
    return (0);
}
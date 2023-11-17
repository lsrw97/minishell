#include <stdio.h>
#include "parser.h"
#include <unistd.h>

int	checkquotes(char *str)
{
	int sq;
	int dq;
	char *tmp;

	sq = 1;
	dq = 1;
	tmp = str;
	if (!tmp[0] || !tmp--)
		return (0);
	while (*(++tmp))
	{
		if (tmp[0] == '\"' && sq == 1)
		{
			if (dq == 1)
				dq = 0;
			else if (tmp[1] == ' ' || tmp[1] == '\0')
				dq = 1;
		}
		if (tmp[0] == '\'' && dq == 1)
		{
			if (sq == 1)
				sq = 0;
			else if (tmp[1] == ' ' || tmp[1] == '\0')
				sq = 1;
		}
	}
	return (sq && dq);
}

int	wordlendel(char *str, char del)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != del && str[len])
		len++;
	return (len);
}

// this Funktion will count total amount of strings. Considered "" and ''

static int	totalstrings(char *str)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] != '\"' && str[i] != '\'' && str[i] != '>' && str[i] != '<' && str[i] != '|' && str[i])
		{
			while (str[i] != ' ' && str[i] != '>' && str[i] != '<' && str[i] != '|' && str[i])
				i++;
			total++;
		}
		if (str[i] == '\"')
		{
			i++;
			while (str[i] != '\"' && str[i]) // '0123"hello" my name is "Albert     and I love  " pan   cakes      '
				i++;
			total++;
			i++;
		}
		if (str[i] == '\'')
		{
			i++;
			while (str[i] != '\'' && str[i]) // '0123"hello" my name is "Albert     and I love  " pan   cakes      '
				i++;
			total++;
			i++;
		}
		if ((str[i] == '>' && str[i + 1] == '>') || (str[i] == '<' && str[i + 1] == '<'))
		{
			i+= 2;
			total++;
		}
		else if (str[i] == '>' || str[i] == '<' || str[i] == '|')
		{
			i++;
			total++;
		}
	}
	return (total);
}

void	fillsplit(char **split, char *str)
{
	int	i;
	int	j;
	int	x;

	x = 0;
	j = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] != '\"' && str[i] != '\'' && str[i] != '>' && str[i] != '<' && str[i] != '|' && str[i])
		{
			split[j] = malloc(wordlendel(&str[i], ' ') + 1);
			// printf("wordlen: %d\n\n", wordlendel(&str[i], ' ') + 1);
			while (str[i] != ' ' && str[i] != '>' && str[i] != '<' && str[i] != '|' && str[i])
			{
				split[j][x++] = str[i++];
				// printf("split[j]: %s, j: %d, i: %d, x: %d\n", split[j], j, i, x);
			}
			split[j][x] = '\0';
			j++;
			x = 0;
		}
		if (str[i] == '\"')
		{
			i++;
			split[j] = malloc(wordlendel(&str[i], '\"') + 2);
			// printf("wordlen: %d\n\n", wordlendel(&str[i], '\"') + 1);
			while (str[i] != '\"' && str[i]) // '0123"hello" my name is "Albert     and I love  " pan   cakes      '
			{
				split[j][x++] = str[i++];
				// printf("split[j]: %s, j: %d, i: %d\n", split[j], j, i);
			}			
			split[j][x++] = '\"';
			split[j][x] = '\0';
			// printf("split[j]: %s, j: %d\n", split[j], j);
			x = 0;
			j++;
			i++;
		}
		if (str[i] == '\'')
		{
			i++;
			split[j] = malloc(wordlendel(&str[i], '\'') + 1);
			// printf("wordlen: %d\n\n", wordlendel(&str[i], '\'') + 1);
			while (str[i] != '\'' && str[i]) // '0123"hello" my name is "Albert     and I love  " pan   cakes      '
			{
				split[j][x++] = str[i++];
				// printf("split[j]: %s, j: %d, i: %d\n", split[j], j, i);
			}			
			split[j][x] = '\0';
			// printf("split[j]: %s, j: %d\n", split[j], j);
			x = 0;
			j++;
			i++;
		}
		if ((str[i] == '>' && str[i + 1] == '>'))
		{
			split[j] = malloc(3);
			split[j][0] = '>';
			split[j][1] = '>';
			split[j][2] = '\0';
			printf("split[j]: %s, j: %d, i: %d\n", split[j], j, i);
			i += 2;
			j++;
		}
		else if ((str[i] == '<' && str[i + 1] == '<'))
		{
			split[j] = malloc(3);
			split[j][0] = '<';
			split[j][1] = '<';
			split[j][2] = '\0';
			i += 2;
			j++;
		}
		else if (str[i] == '>')
		{
			split[j] = malloc(2);
			split[j][0] = '>';
			split[j][1] = '\0';
			i++;
			j++;
		}
		else if (str[i] == '<')
		{
			split[j] = malloc(2);
			split[j][0] = '<';
			split[j][1] = '\0';
			i++;
			j++;
		}
		else if (str[i] == '|')
		{
			split[j] = malloc(2);
			split[j][0] = '|';
			split[j][1] = '\0';
			i++;
			j++;
		}
	}
}

char	**minisplit(char *str)
{
	int		count;
	char	**split;

	if (!str || !ft_strlen(str))
		return (NULL);
	count = totalstrings(str);
	printf("COUNT: %d\n", count);

	split = malloc(sizeof(char *) * (count + 1));
	split[count] = NULL;
	if (!split)
		return (NULL);
	fillsplit(split, str);
	return (split);
}

int	checkforenv(char **envp, char *env)
{
	int	i;
	int	len;

	len = ft_strlen(env);
	i = -1;
	while (envp[++i])
	{
		if (!ft_strncmp(envp[i], env, len) && envp[i][len] == '=')
			return (i);
	}
	return (-1);
}

int	envlength(char *env)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (env[i] != '=')
		i++;
	while (env[++i])
		j++;
	return (j);
}

s_string	*newnode(char *value, s_string *prev)
{
	s_string	*list;

	list = malloc(sizeof(s_string));
	if (!list)
		return (NULL);
	list->value = value;
	list->next = NULL;
	list->prev = prev;
	return (list);
}
    // COMMAND,		// 0	cat, /bin/cat
    // REDIRECTION,	// 1	> >> < <<
    // PIPE,			// 2	|
    // ARGUMENT,		// 3	word

// Command can be represented as path, absolute or relative or name.


void	freesplit(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

char	*strappendpath(char *str, char *value)
{
	int		i;
	int 	len;
	char	*string;
	int		j;

	j = -1;
	len = ft_strlen(str) + ft_strlen(value) + 2;
	string = malloc(len);
	i = -1;
	while (str[++i])
		string[++j] = str[i];
	string[++j] = '/';
	i = -1;
	while (value[++i])
		string[++j] = value[i];
	string[++j] = '\0';
	free(str);
	return (string);
}

int	checkforargument(char *value, char **envp)
{
	char	**paths;
	char	*str;

	int i = -1;
	if (access(value, X_OK) == 0)
	{
		freesplit(paths);
		return (1);
	}
	paths = ft_split(envp[checkforenv(envp, "PATH")], ':');
	// str = ft_strjoin(paths[i], "/");
	// str = ft_strjoin(paths[i], value);
	while (paths[++i])
		paths[i] = strappendpath(paths[i], value);
	i = -1;
	paths[0] = paths[0] + 5;
	// while (paths[++i])
	// 	printf("%s\n", paths[i]);

	while (paths[++i])
	{
		if (access(paths[i], X_OK) == 0)
		{
			paths[0] = paths[0] - 5;
			freesplit(paths);
			return (1);
		}
	}
	paths[0] = paths[0] - 5;
	freesplit(paths);
	return 0;
}

void	tokenisation(s_string *node)
{
	if (node->value == "|")
		node->nodeType = PIPE;
	else if (node->value[0] == '>' || ft_strncmp(node->value, ">>", 2) || node->value[0] == '<' || ft_strncmp(node->value, "<<", 2))
		node->nodeType = REDIRECTION;
	else if (checkfor)
}

void	modifynode(s_string *node)
{
	tokenisation(node);
}

s_string	*createlist(char **split)
{
	int			i;
	s_string 	*tmp;
	s_string	*stack;

	stack = newnode(split[0], NULL);
	tmp = stack;
	i = 0;
	while (split[++i])
	{
		tmp->next = newnode(split[i], tmp);
		tmp = tmp->next;
	}
	tmp->next = NULL;
	return (stack);
}

int main(int argc, char **argv, char **envp)
{
    if (argc != 2)
        return 0;
	char *s = "echo   my name is grep>><<><>0    \"|\' grep\' $PATH rwx \"| \'grep x@\' > file";
	// if(!checkquotes(s))
	// 	return 0; 
	s_string *list;
	list = NULL;
	int i = -1;
	char **ss = minisplit(s);
	while (ss[++i])
		printf("%s \n", ss[i]);
	i = -1;
	// while (envp[++i])
	// 	printf("%s\n", envp[i]);
	// printf("%d, len: %d\n", checkforenv(envp, "PATH"), envlength(envp[3]));
	printf("\n\n");
	// list = createlist(ss);
	// printf("%s\n", list->value);
	// while (list)
	// {
	// 	printf("%s\n", list->value);
	// 	list = list->next;
	// }
	freesplit(ss);
	printf("%d\n", checkforargument("cat", envp));
}

// How do I dereferenciate if ' or "" ?
// during the minisplit

// but do I already expand the var in the string? 
// yes you need to check if the var exists or not and then determine the length of the var.
// then you can allocate the right amount of memory and fill the word
// gleich in eine liste implementieren. 
// Das einzige ist wir müssen im "" die vars handlen

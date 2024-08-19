/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanda-s <joanda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:03:27 by joanda-s          #+#    #+#             */
/*   Updated: 2024/08/19 20:42:13 by joanda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"
#include "../libs/builtins.h"

char	*ft_strjoinn(char *s1, char *s2)
{
	int	i;
	int	j;
	char	*final;

	i = -1;
	j = -1;
	/*if (s1 == NULL)
		final = ft_calloc(sizeof(char), ft_strlen(s2) + 1);
	else if (s2 == NULL)
		final = ft_calloc(sizeof(char), ft_strlen(s1) + 1);*/
	if (s1 != NULL && s2 != NULL)
		final = ft_calloc(sizeof(char), ft_strlen(s1) + ft_strlen(s2) + 2);
	if (s1 == NULL || s1[0] == '\0')
		return (s2);
	if (s2 == NULL || s2[0] == '\0')
		return (s1);
	while (s1[++i] != '\0')
		final[i] = s1[i];
	final[i] = ' ';
	i++;
	while (s2[++j] != '\0')
		final[i++] = s2[j];
	final[i] = '\0';
	return (final);
}

int	varlen(char *str, int k)
{
	while (str[k] && str[k] != '$')
		k++;
	return (k);
}

int	pid_dollar(char *str, int j)
{
	int	x;

	j--;
	if (j < 0)
		return (0);
	x = 0;
	while (j >= 0 && str[j] == '$')
	{
		x++;
		j--;
	}
	return (x);
}

void	expansions(char *argv, t_shell *utils)
{
	int		i;
	int		j;
	int		k;
	int		l;
	int		x;
	int		dollar;
	char	**split;
	char	*o_que_quiser;
	char	*o_que_quiser2;
	char	*output;

	i = 0;
	k = 0;
	l = 0;
	split = ft_split(argv, ' ');
	o_que_quiser2 = NULL;
	//printf("...1\n");
	while (split[i])
	{
		j = 0;
		while (split[i][j] && split[i][j] != '$')
			j++;
		x = j;
		//printf("...3\n");
		if (split[i][j] == '$')
		{
			j++;
			if (split[i][j] == '$')
			{
				while (split[i][j] == '$')
				{
					dollar = pid_dollar(split[i], j);
					if (dollar % 2 != 0)
						ft_putstr_fd(ft_getpid(), 1);
					j++;
				}
				//ft_putendl_fd("", 1);
			}
			else
			{
				k = j;
				while (ft_isalnum((int)split[i][k]) == 1)
					k++;
				//printf("...6\n");
				o_que_quiser = ft_substr(split[i], j, k - j);
				//printf("...7\n");
				while (utils->envr[l])
				{
					if (ft_strncmp(o_que_quiser, utils->envr[l], ft_strlen3(utils->envr[l])) == 0 && ft_strlen3(o_que_quiser) == ft_strlen3(utils->envr[l]))
						break ;
					//printf("...8\n");
					l++;
				}
				//printf("...9\n");
				if (utils->envr[l])
				{
					if (x != 0)
						o_que_quiser2 = ft_substr(split[i], 0, x);
					//j = 0;
					//while (split[i][j])
					//{
					//	while (split[i][j] && split[i][j] != '$')
					//		j++;
					//	if (split[i][j])
					//	{
					//		while(split[i][j])
					//		split[i][j] = '\0';
					//		j++;
					//	}
					//}
					//printf("...10\n");
					free(split[i]);
																						/*
																						
																						
																						AQUI O, ADICIONAR, LOGICA DE MANTER SPLIT SEM DAR FREE, E OUTRA
																							VARIAVEL QUE NAO O SPLIT RECEBER 
																						 ft_strjoinn(o_que_quiser2, ft_substr(utils->envr[l], ft_strlen3(o_que_quiser) + 1, ft_strlen(utils->envr[l]) - ft_strlen(o_que_quiser) - 1));
	
	
																							*/
					split[i] = ft_strjoinn(o_que_quiser2, ft_substr(utils->envr[l], ft_strlen3(o_que_quiser) + 1, ft_strlen(utils->envr[l]) - ft_strlen(o_que_quiser) - 1));
					free(o_que_quiser2);
					//printf("...12\n");
				}
				else
				{
					j = 0;
					while (split[i][j])
					{
						while (split[i][j] && split[i][j] != '$')
							j++;
						if (split[i][j])
						{
							while (split[i][j])
							{
								split[i][j] = '\0';
								j++;
							}
						}
					}
				}
			}
		}
		i++;
		l = 0;
		//printf("...13\n");
	}
	i = 0;
	while (split[i])
	{
		//printf("...14\n");
		if (i == 0)
		{
			//printf("...15\n");
			//printf("split[i] -> %s\n", split[i]);
			//printf("split[i + 1] -> %s\n", split[i + 1]);
			if (dollar % 2 != 0)
			{
				output = ft_strjoinn(split[i] + dollar + 1, split[i + 1]);
				ft_putendl_fd("", 1);
			}
			else
				output = ft_strjoinn(split[i] + dollar, split[i + 1]);
			//printf("output -> %s\n", output);
			//printf("...16\n");
			if (split[i + 1] == NULL)
				i += 1;
			else
				i += 2;
		}
		else
		{
			//printf("split[%d] -> %s\n", i, split[i]);
			output = ft_strjoinn(output, split[i]);
			i++;
		}
		//printf("...17\n");
	}
	//printf("...18\n");
	if (output == NULL && echo_flag(argv) == 1)
		ft_putendl_fd("", 1);
	else if (output != NULL)
		ft_putendl_fd(output, 1);
	free_dptr(split, 0);
	//printf("...19\n");
}
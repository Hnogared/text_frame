/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnogared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 21:42:43 by hnogared          #+#    #+#             */
/*   Updated: 2023/05/25 17:41:36 by hnogared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	ft_whitespace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int		len1;
	int		len2;
	char	*result;
	char	*temp;

	len1 = 0;
	len2 = 0;
	if (str1)
		len1 = strlen(str1);
	if (str2)
		len2 = strlen(str2);
	result = (char *) calloc(len1 + len2 + 2, sizeof(char));
	if (!result)
		return (NULL);
	temp = result;
	while (str1 && *str1)
		*temp++ = *str1++;
	while (str2 && *str2)
		*temp++ = *str2++;
	return (result);
}

char	*get_args(int argc, char **argv)
{
	int		i;
	char	*temp;
	char	*temp2;

	i = 0;
	temp = NULL;
	temp2 = NULL;
	while (++i < argc)
	{
		if (temp2)
		{
			temp = temp2;
			temp2 = ft_strjoin(temp2, " ");
			free(temp);
			if (!temp2)
				return (NULL);
		}
		temp = temp2;
		temp2 = ft_strjoin(temp2, argv[i]);
		if (temp)
			free(temp);
		if (!temp2)
			return (NULL);
	}
	return (temp2);
}

int	get_width(char *str)
{
	int		max;
	char	*temp;

	max = 0;
	while (*str && ft_whitespace(*str))
		str++;
	while (*str)
	{
		temp = str;
		while (*temp && !ft_whitespace(*temp))
			temp++;
		if (temp - str > max)
			max = temp - str;
		str += temp - str + 1;
	}
	return (max);
}

void	print_framed(char *str, char frame, int width)
{
	int	i;
	int	j;

	i = 0;
	while (i++ < width + 4)
		printf("%c", frame);
	printf("\n");
	while (*str && ft_whitespace(*str))
		str++;
	while (*str)
	{
		j = 0;
		printf("%c ", frame);
		while (*str && !ft_whitespace(*str))
		{
			printf("%c", *str++);
			j++;
		}
		printf("%-*s %c\n", width - j, "", frame);
		while (*str && ft_whitespace(*str))
			str++;
	}
	while (width-- + 4)
		printf("%c", frame);
	printf("\n");
}

int	main(int argc, char **argv)
{
	int		width;
	char	*str;

	if (argc > 2)
	{
		str = get_args(--argc, ++argv);
		if (str)
		{
			width = get_width(str);
			if (width)
				print_framed(str, argv[0][0], width);
			free(str);
		}
	}
	return (0);
}

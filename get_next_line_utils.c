/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_utils.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yictseng <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/24 14:57:42 by yictseng     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 19:03:58 by yictseng    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int        ft_strchr(const char *str, int charset)
{
    int i;
    
    i = 0;
    if (!str)
        return (0);
    while (str[i])
    {
        if (str[i] == charset)
            return (i + 1);
        i++;
    }
    return (0);
}

char    *ft_strdup(const char *s1)
{
    int        i;
    int        len;
    char    *dst;
    
    i = 0;
    len = ft_strlen(s1);
    if (!(dst = (char *)malloc(sizeof(char) * (len + 1))))
        return (NULL);
    while (s1[i])
    {
        dst[i] = s1[i];
        i++;
    }
    dst[i] = '\0';
    return (dst);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *dst;
    int        i;
    int        j;
    
    if (!s1)
        return (ft_strdup(s2));
    if (!s2)
        return (ft_strdup(s1));
    if (!(dst = (char *)malloc(sizeof(char) *
                               (ft_strlen(s1) + ft_strlen(s2) + 1))))
        return (NULL);
    i = 0;
    while (s1[i])
    {
        dst[i] = s1[i];
        i++;
    }
    j = 0;
    while (s2[j])
    {
        dst[i + j] = s2[j];
        j++;
    }
    dst[i + j] = '\0';
    return (dst);
}

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    char    *substr;
    size_t    i;
    size_t    maxsize;
    
    i = -1;
    if (s == 0)
        return (NULL);
    maxsize = (start >= ft_strlen(s)) ? 0 : len;
    if (!(substr = malloc((maxsize + 1) * sizeof(char))))
        return (NULL);
    while (++i < maxsize && s[start + i])
        substr[i] = s[start + i];
    substr[i] = '\0';
    return (substr);
}

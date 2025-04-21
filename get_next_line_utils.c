#include "get_next_line.h"

size_t  ft_strlen(const char *s)
{
    size_t i;

    i = 0;
    if (!s)
        return (0);
    while (s[i])
        i++;
    return (i);
}

char    *ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*str;
	size_t		j;
	size_t		s_len;

	j = 0;
	i = start;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s[i] && j < len)
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*result;
	size_t	i;
	size_t	j;

	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!result)
		return (NULL);
	while (i < len1 && s1 != NULL)
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len2 && s2 != NULL)
	{
		result[i++] = s2[j++];
	}
	result[i] = '\0';
	return (result);
}

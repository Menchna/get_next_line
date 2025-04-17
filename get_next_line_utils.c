#include "get_next_line.h"

size_t ft_strlen(const char *s)
{
    size_t i;

    i = 0;
    if (!s)
        return (0);
    while (s[i])
        i++;
    return (i);
}

char *ft_strchr(const char *s, int c)
{
    if (!s)
        return (NULL);
    while (*s)
    {
        if (*s == (char)c)
            return ((char *)s);
        s++;
    }
    if (*s == (char)c)
        return ((char *)s);
    return (NULL);
}

char *ft_substr(char *s, unsigned int start, size_t len)
{
    char    *substr;
    size_t  i;
    size_t  s_len;

    if (!s)
        return (NULL);
    s_len = ft_strlen(s);
    if (start >= s_len)
        return (NULL);
    if (len > s_len - start)
        len = s_len - start;
    substr = (char *)malloc(sizeof(char) * (len + 1));
    if (!substr)
        return (NULL);
    i = 0;
    while (i < len && s[start + i])
    {
        substr[i] = s[start + i];
        i++;
    }
    substr[i] = '\0';
    return (substr);
}

char *ft_strjoin(char *s1, char *s2)
{
    char    *joined;
    size_t  i;
    size_t  j;
    size_t  s1_len;
    size_t  s2_len;

    s1_len = ft_strlen(s1);
    s2_len = ft_strlen(s2);
    joined = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
    if (!joined)
        return (NULL);
    i = 0;
    while (i < s1_len)
    {
        joined[i] = s1[i];
        i++;
    }
    j = 0;
    while (j < s2_len)
    {
        joined[i + j] = s2[j];
        j++;
    }
    joined[i + j] = '\0';
    free(s1);
    return (joined);
}
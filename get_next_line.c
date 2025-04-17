#include "get_next_line.h"

char *extract_line(char **storage)
{
    char    *line;
    char    *newline_pos;
    char    *temp;
    size_t  line_len;

    if (!*storage || **storage == '\0')
    {
        free(*storage);
        *storage = NULL;
        return (NULL);
    }

    newline_pos = ft_strchr(*storage, '\n');
    
    if (newline_pos)
    {
        line_len = newline_pos - *storage + 1;
        
        line = ft_substr(*storage, 0, line_len);
        
        temp = ft_substr(*storage, line_len, ft_strlen(*storage) - line_len);
        free(*storage);
        *storage = temp;
    }
    else
    {
        line = *storage;
        *storage = NULL;
    }
    
    return (line);
}

char *get_next_line(int fd)
{
    static char *storage[MAX_FD];  // Array to store leftover data for each fd
    char        *buffer;           // Temporary buffer for reading
    int         bytes_read;        // Number of bytes read by read()

    if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX_FD)
        return (NULL);

    buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (NULL);

    bytes_read = 1;
    while (bytes_read > 0 && !ft_strchr(storage[fd], '\n'))
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read < 0)
        {
            free(buffer);
            return (NULL);
        }
        
		buffer[bytes_read] = '\0';
        
        if (bytes_read > 0)
        {
            if (!storage[fd])
                storage[fd] = ft_substr(buffer, 0, bytes_read);
            else
                storage[fd] = ft_strjoin(storage[fd], buffer);
        }
    }
    
    free(buffer);
    
    return (extract_line(&storage[fd]));
}
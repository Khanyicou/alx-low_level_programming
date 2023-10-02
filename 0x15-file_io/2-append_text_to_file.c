#include <string.h>
#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: The name of the file.
 * @text_content: The text to append.
 * Return: 1 on success.
 */
int append_text_to_file(const char *filename, char *text_content)
{
int fd, write_count;

if (filename == NULL)
return (-1);

fd = open(filename, O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR);
if (fd == -1)
return (-1);

if (text_content != NULL)
{

write_count = write(fd, text_content, strlen(text_content));
if (write_count == -1)
{
close(fd);
return (-1);
}
}

if (close(fd) == -1)
return (-1);

return (1);
}

#include "main.h"
#include <string.h>

/**
 * create_file - Creates a file and writes content to it.
 * @filename: The name of the file
 * @text_content: The content
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
int fd, write_count;
mode_t file_perms = S_IRUSR | S_IWUSR;

if (filename == NULL)
return (-1);

fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, file_perms);
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

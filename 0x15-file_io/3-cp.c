#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdarg.h>

/**
 * error_exit - Print an error message and exit with a specific code.
 * @exit_code: The exit code.
 * @format: The error message
 * @...: The error message arguments.
 */
void error_exit(int exit_code, const char *format, ...)
{
va_list args;

va_start(args, format);
vdprintf(STDERR_FILENO, format, args);
va_end(args);
exit(exit_code);
}

/**
 * main - Copy the content of a file to another file.
 * @argc: The number of arguments.
 * @argv: The array of arguments.
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
int fd_from, fd_to, bytes_read, bytes_written;
char buffer[1024];

if (argc != 3)
error_exit(97, "Usage: cp file_from file_to\n");

fd_from = open(argv[1], O_RDONLY);
if (fd_from == -1)
error_exit(98, "Error: Can't read from file %s\n", argv[1]);

fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
if (fd_to == -1)
error_exit(99, "Error: Can't write to %s\n", argv[2]);

while ((bytes_read = read(fd_from, buffer, sizeof(buffer))) > 0)
{
bytes_written = write(fd_to, buffer, bytes_read);
if (bytes_written == -1 || bytes_written != bytes_read)
error_exit(99, "Error: Can't write to %s\n", argv[2]);
}

if (bytes_read == -1)
error_exit(98, "Error: Can't read from file %s\n", argv[1]);

if (close(fd_from) == -1)
error_exit(100, "Error: Can't close fd %d\n", fd_from);

if (close(fd_to) == -1)
error_exit(100, "Error: Can't close fd %d\n", fd_to);

return (0);
}

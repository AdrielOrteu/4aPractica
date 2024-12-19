#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 128  // Define a buffer size

int main() {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    // Read from standard input (fd = 0 for stdin)
    printf("Enter some text (Ctrl+D to end):\n");
    while ((bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE - 1)) > 0) {
        // Null-terminate the buffer for safe printing
        buffer[bytes_read] = '\0';
        printf("You entered: %s", buffer);
    }

    if (bytes_read == -1) {
        perror("Error reading from standard input");
        return 1;
    }

    printf("\nEnd of input.\n");
    return 0;
}

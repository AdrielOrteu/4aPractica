#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define PERMISOS 0664

int main (int argc, char *argv[]) {
  int fd = open(argv[1], O_CREAT | O_WRONLY | O_TRUNC, PERMISOS);
  if (fd == -1) {
    perror("Error al crear el archivo");
    return -1;
  }
  else {
    char buffer;
//    char sentence [];
// STD_FILENO es igual a 0, q es el fd del stdIn
    while (read(STDIN_FILENO, &buffer, 1) > 0) {
      if (write(fd, &buffer, 1) == -1) {
        perror("Error al escribir");
        close(fd);
        return -1;
      }
      printf("%c", buffer);
    }
    close(fd);
    return 0;
  }
}

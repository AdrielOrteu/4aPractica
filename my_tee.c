#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(const char argc, int *argv[]){
  int fd1;
  fd1 = open(argv[1], O_WRONLY);
//  fd2 = open(argv[2], );
  if (fd1 == -1){
    close(fd1);
//    close(fd2);
    perror("my_tee");
  }else{
    char letra;
    while (read(STDIN_FILENO, &letra, 1) > 0) {
      if(write(fd1, &letra, 1) == -1) {
        perror("Error d'escriptura");
        close(fd1);
//        close(fd2);
        exit(-1);
      }
    }
    
    close(fd1);
    close(fd2);
  }


ssize_t read(int fd, void argc, size_t *argv[])

ssize_t write(int fd, void argc, size_t count)

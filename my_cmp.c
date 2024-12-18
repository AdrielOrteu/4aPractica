#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

int main( int argc, char *argv[] ){
  int fd1, fd2;
  fd1 = open(argv[1], O_RDONLY);
  fd2 = open(argv[2], O_RDONLY);
  if (fd1 == -1 || fd2 == -1){
    close(fd1);
    close(fd2);
    perror("my_cmp");
  }else{
    printf("%d %d\n", fd1, fd2);
    // loop structure that returns a way to identify characters [non_keyword]:
    int byte_num = 1;
    int line_num = 1:
    char file1_ch;
    char file2_ch;
    ssize_t_read(fd1, file1_ch, 1);
    ssize_t_read(fd2, file2_ch, 1);
    while (byte_num < file_size && file1_ch == file2_ch) {
      ssize_t_read(fd1, file1_ch, 1);
      ssize_t_read(fd2, file2_ch, 1);
      if (non_keyword == "\n"){
        line_num ++;
      }else{
        bytes ++;
      }
    }
  }
}

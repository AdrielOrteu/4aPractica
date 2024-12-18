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

    int byte_num = 1;
    int line_num = 1;
    char file1_ch;
    char file2_ch;
    read(fd1, &file1_ch, 1);
    read(fd2, &file2_ch, 1);

    while (file1_ch != 0 && file1_ch == file2_ch) {
      if (file1_ch == '\n'){
        line_num ++;
      }
      byte_num ++;
      read(fd1, &file1_ch, 1);
      read(fd2, &file2_ch, 1);
    }
    printf("%s %s differ: byte %d, line %d\n", argv[1], argv[2], byte_num, line_num);
  }
}

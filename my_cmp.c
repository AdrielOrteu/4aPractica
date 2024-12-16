#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main( int argc, char *argv[] ){
  int r;
  r = open(argv[1], O_RDONLY);
  printf("%d\n", r);
}

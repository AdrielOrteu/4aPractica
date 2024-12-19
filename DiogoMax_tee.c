#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main (int argc, char*argv[] ){
	if (argc != 2){
		perror("Només es pot escriure el nom del fitxer com argument");
		exit(-1);
	}
	int fd = open(argv[1], O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd == -1){
		perror("No es pot crear el arxiu");
		exit(-1);
	}
	char buf[1];
	while (read(0, buf, 1) > 0){
		if(write(fd, buf, 1) == -1){
			perror("Error a l'escriptura en l'arxiu");
			exit(-1);
		}
	}
}

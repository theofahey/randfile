#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
unsigned int * randomf(){
	int f = open("/dev/random", O_RDONLY, 0);
    unsigned int * arr = malloc(40);
    int k = read(f,arr,40);
	return arr;
}
int main(){
    int i;
    int d;
    unsigned int * arr = randomf();
    printf("Random Numbers List: \n");
	for (i = 0; i < 10; i++){
		printf("Random Number %d: %u\n",i+1,arr[i]);
	}
    printf("Writing numbers to file text.txt...\n");
    int fd = open("text.txt", O_WRONLY,0);
    write(fd,arr,40);
    printf("Reading numbers from file text.txt...\n");
    int fd2 = open("text.txt", O_RDONLY,0);
    unsigned int arr2[10];
    read(fd2,arr2,40);
    for (d=0; d < 10; d++){
        printf("Random Number %d: %u\n",d+1,arr2[d]);
    }
	return 0;
}

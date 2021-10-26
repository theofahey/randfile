#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
int randomf(int * a){
	int f = open("/dev/random", O_RDONLY, 0);
	read(f,a,4);
	return f;
}
int main(){
	int arr[10];
	for (int i = 0; i < 10; i++){
		randomf(arr[i]);
		printf("%d\n",arr[i]);
	}
	
	return 0;
}

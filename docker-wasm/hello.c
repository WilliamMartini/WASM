#include<stdio.h>


int main(int argc, char **argv) {

if (argc <= 1){
	printf("Usage: wasmer run hello.wasm someText\n");
} else {
	for(int i = 1; i < argc; i++)
		printf("%s ", argv[i]);
}


return 0;
}

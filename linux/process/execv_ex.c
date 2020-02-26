#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
int main(int argc, char *argv[]) 
{
    char * const args[] = {argv[1], NULL};
    execvp(args[0],args); 

    printf("Parent done...\n"); 

    return 0; 
} 

#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
int main() 
{ 
  
    // make two process which run same 
    // program after this instruction 
    if(fork() == 0) {
        //parent code
        printf("Hello from Parent, pid = %d \t ppid=%d\n", getpid(), getppid());
    }else{
        //child code
        printf("Hello from child, pid = %d \t ppid=%d\n", getpid(), getppid());
    }
    //common code
        printf("Common code\n"); 
    return 0; 
} 

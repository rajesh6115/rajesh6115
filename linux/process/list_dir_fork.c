#include <stdio.h> 
#include <stdlib.h>
#include <sys/types.h> 
#include <unistd.h> 
#include <dirent.h> 
#include <string.h>

int list_dir(const char *path) {
    struct dirent *d;  // Pointer for directory entry

    DIR *dir = opendir(path);

    if (dir == NULL)  // opendir returns NULL if couldn't open directory
    {
        printf("Could not open current directory %s \n",  path );
        return 0;
    }
    while ((d = readdir(dir)) != NULL) {
        if( (strcmp(d->d_name, ".") == 0) || (strcmp(d->d_name, "..") == 0)) {
            continue;
        }
        printf("pid=%d type=%d name=%s/%s\n", getpid(), d->d_type, path, d->d_name);
        if(d->d_type == DT_DIR) {
                char dir_path[512] = {0x00};
                sprintf(dir_path, "%s/%s", path, d->d_name);
            if(fork() != 0) {
                //child code
                list_dir(dir_path);
                exit(0);
            }
        }
    }

    closedir(dir);
}

int main(int argc, char*argv[]) 
{
    list_dir(argv[1]);
    /* 
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
    */
    return 0; 
} 

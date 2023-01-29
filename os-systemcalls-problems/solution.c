#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    if(pid<0){
    fprintf(stderr,"Fork failed");
    return 1;
    }
    if (pid == 0) {
        execlp("/bin/ps","ps", "-U", "0", NULL);
    } else {
        wait(NULL);
        printf("Child Complete");
    }
    return 0;
}

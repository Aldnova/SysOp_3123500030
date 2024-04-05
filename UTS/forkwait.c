#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        
        printf("Child proses dengan PID %d.\n", getpid());
    } else if (pid > 0) {
        
        printf("Parent proses dengan PID %d menunggu child selesai.\n", getpid());
        wait(NULL); 
        printf("Child selesai, parent berlanjut.\n");
    } else {
        
        printf("Gagal membuat proses child.\n");
    }

    return 0;
}

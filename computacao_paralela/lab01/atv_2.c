#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

#define N 4

int main()
{
    int i;
    pid_t pid;

    for (i = 0; i < N; i++)
    {
        pid = fork();
        if (pid == -1)
        {
            perror("fork");
            return 1;
        }
        if (pid == 0)
        {
            printf("Filho %d: Meu PID é %d, PID do pai é %d\n", i + 1, getpid(), getppid());
            return 0;
        }
    }

    for (i = 0; i < N; i++)
    {
        wait(NULL);
    }

    printf("Processo pai: Todos os filhos terminaram.\n");
    return 0;
}
//
//	EE 4374 Assignment # 2 Command Executer
//	Author: Jesus Garcia
//
#include <stdio.h>
#include <stdlib.h>
#include "jgarcia_argtok.h"
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void checkforbackground(char **args);

int execBackground(char **args)
{
    int i;
    // check for the ampersand at the end of the set of tokens
    i = 0;
    while (args[i] != 0)
    {
        i++;
    }                          // traverse to the end of the tokens
    if (args[i - 1][0] == '&') // check the last token
    {
        free(args[i - 1]);
        args[i - 1] = NULL; // remove the ampersand

        return 1;
    }
    else
    {
        return 0;
    }
}
int executeCmd(char **args)
{
    if (execBackground(args) == 1)
    {
        checkforbackground(args);
    }
    else
    {
        pid_t pid;
        pid = fork();

        if (pid < 0)
        {
            return -1;
        }
        else if (pid == 0)
        {
            execvp(args[0], args);
        }
        else
        {
            waitpid(pid,NULL,0);
        }
    }
    return 0;
}
void checkforbackground(char **args)
{

    pid_t pid;
    pid = fork();
    if (pid < 0)
    {
        fprintf(stderr, "wrong");
    }
    else if (pid == 0)
    {
        printf("\n");
        execvp(args[0], args);
    }
}

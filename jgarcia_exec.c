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
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

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

        pid_t pid;
        pid = fork();
        if (pid < 0)
        {
            return 1;
        }
        else if (pid == 0)
        {
            execvp(args[0], args);
        }
        else
        {
            wait(NULL);
        }

        return 1;
    }
    else
    {
        return 0;
    }
}
int executeCmd(char **args)
{
    //when I put the fork() and exec it finally runs normal
    pid_t pid = fork();
    if (pid < 0)
    {
        return -1;
    }
    else if (pid == 0)
    {
        execvp(args[0], args);
        execBackground(args);
    }

    return 0;
}

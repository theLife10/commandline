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
        printf("the child\n");
        if (pid < 0)
        {
            return 1;
        }
        else if (pid == 0)
        {
            //execvp(args[0], args);
            //           execvp(args[0], args); /* execute the command  */
            if (execvp(args[0], args) < 0)
            {
            }
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
    execBackground(args);

    //when I put the fork() and exec it finally runs normal
    pid_t pid = fork();
    printf("the parent\n");
    //this method executes in background i think

    if (pid < 0)
    {
        return -1;
    }
    else if (pid == 0)
    {
        execvp(args[0], args);
    }

    return 0;
}

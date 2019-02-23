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

    //   execvp(args[0],&(args[0]));
    //  execlp("wc", args[0], args[1], NULL);
    //execlp("mkdir",args[0],args[1],NULL);
    //execlp("cat",args[0],args[1],NULL);
    //execlp("ls",args[0],args[1],NULL);

    //when I put the fork() and exec it finally runs normal
    pid_t pid = fork();
    if (pid < 0)
    {
        return -1;
    }
    else if (pid == 0)
    {
        execl("/bin/ls", args[0], args[1], NULL);
    }

    return 0;
}

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
    while(args[i] != 0)
    {
         i++;
    }                       // traverse to the end of the tokens
    if(args[i-1][0] == '&') // check the last token
    {
        free(args[i-1]);
        args[i-1] = NULL;  // remove the ampersand
        return 1;
    }
    else
    {
        return 0;
    }
}
int executeCmd(char **args)
{
    /*
        once this execvp executs a 
        command successfully it terminates
        the terminal. We want it to keep on running
        after execvp already executes a command
        this only works with one command line only like
        ls, date, pwd
    */
    
 //   execvp(args[0],&(args[0]));
    /*
        this works for:
        ls -l
        ls -a
    */
  //  execlp("wc", args[0], args[1], NULL);
  //execlp("mkdir",args[0],args[1],NULL);
  //execlp("cat",args[0],args[1],NULL);
    //execlp("ls",args[0],args[1],NULL);


    //when I put the fork() and exec it finally runs normal
      pid_t pid;
          pid = fork();
          if(pid < 0){
                fprintf(stderr,"FORK Failed\n");
                return 1;
          }
          else if (pid == 0){
                
                execvp(args[0],args);
          }

    return 0;
}

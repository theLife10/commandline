//
//	EE 4374 Assignment # 2 Shell (Test Function)
//	Author: Jesus Garcia
//

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "jgarcia_argtok.h"
#include "jgarcia_exec.h"
#include "history.h"

int main()
{
	int i;
	int inputSize;
	char buff[128]; // Character buffer
	char **args;
	char *historyargs;
	List *history;
	history = init_history();

	write(1, "Welcome to the Student Shell (type 'x' to exit)\n", 48);
	while (1)
	{
		// Request a line of input
		write(1, "\nshell ->  ", 10);
		// Read the line
		inputSize = read(0, buff, 128);
		// Strip off carriage return
		buff[inputSize - 1] = '\0';
		int bufferposition = 0;

		if (buff[0] == '\0')
			continue;

		if ((buff[0] == 'x') && (buff[1] == '\0'))
		{
			exit(0);
		}
        //currently working on this
		if ((buff[0] == '!'))
		{
			//	bufferposition = buff[1] - '0';
			historyargs = get_history(history, bufferposition);
			//executeCmd(historyargs);
		}

		// make the argument vector
		args = argtok(buff);

		add_history(history, *args);

		// execute the command
		executeCmd(args);
	}

	return 0;
}

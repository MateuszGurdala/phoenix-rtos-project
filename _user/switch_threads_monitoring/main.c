#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <phoenix/monitor.h>
#include <monitor/switch_threads_monitoring.h>

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		printf("Invalid number of arguments.\n");
		printf("switch_threads_monitoring(unsigned pid)\n");
		return 1;
	}

	if(!isdigit(*argv[1]))
	{
		printf("Invalid arguments.\n");
		printf("switch_threads_monitoring(unsigned pid)\n");
		return 1;
	}

	return switch_threads_monitoring(atoi(argv[1]));
}

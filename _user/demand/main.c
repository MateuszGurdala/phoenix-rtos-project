#include <stdio.h>
#include <stdlib.h>
#include <phoenix/monitor.h>
#include <sys/msg.h>
#include <monitor/get_ondemand_data.h>

int main(int argc, char **argv)
{

	if (argc != 2)
	{
		printf("ERROR: ARGUMENTS\n");
		printf("demand FILENAME.od\n");
		return 1;
	}

//	get_ondemand_data(argv[1]);

	return 0;
}

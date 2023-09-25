#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <sys/threads.h>
#include <phoenix/monitor.h>

#define O_RDONLY 0x0001

int main(int argc, char **argv)
{
	char cport;
	int fildes, port;
	msg_t msg = {
		.type = mtRead,
		.i.data = NULL,
		.i.size = 0,
		.o.data = NULL,
		.o.size = 0
	};

	if (argc != 2) {

		printf("ERROR: ARGUMENTS\n");
		printf("demand FILENAME.od\n");
		return 1;
	}

	fildes = sys_open("/monitor/port", O_RDONLY);
	sys_read(fildes, &cport, 1);
	sys_close(fildes);

	port = cport - '0';

	strcpy(&msg.i.raw, argv[1]);

	return msgSend(port, &msg);
}

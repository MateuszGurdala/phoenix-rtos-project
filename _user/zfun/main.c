#include <stdio.h>
#include <stdlib.h>
#include <monitor/log_data.h>
#include <monitor/monitorsrv_set_port.h>
#include <arpa/inet.h>

#define O_RDONLY   0x0001
#define O_WRONLY   0x0002
#define O_RDWR     0x0004
#define O_APPEND   0x0008
#define O_CREAT    0x0100
#define O_TRUNC    0x0200
#define O_EXCL     0x0400
#define O_SYNC     0x0800
#define O_NONBLOCK 0x1000
#define O_NOCTTY   0x2000
#define O_CLOEXEC  0x4000

void test_log_data(int argc, char **argv)
{
	m_data data = {
		.mtype = mdt_msg,
		.data.msg = ""
	};

	if (argc == 2) {
		if (atoi(argv[1]) == 1) {
			memcpy(data.data.msg, "Jeden", 6);
		}
		else {
			memcpy(data.data.msg, "Nie jeden", 10);
		}
		log_data(mbuff_msg, data);
	}
}

void test_file_nc()
{
	int fildes;
	char data[] = "x\n";
	int count = 0;

	sys_close(sys_open("/monitor/test.txt", O_CREAT));
	printf("File created.\n");

	while (1) {
		fildes = sys_open("/monitor/test.txt", O_WRONLY);
		data[0] = count + '0';  // Just some C magic
		count += 1;
		sys_write(fildes, &data, 3);
		sys_close(fildes);
		system("nc 10.0.2.2:3171 < /monitor/test.txt");
		printf("Data sent.\n");
	}
}

void test_file()
{
	int fildes;
	fildes = sys_open("/monitor/test.txt", O_APPEND);
	printf("%i\n", fildes);
	fildes = sys_open("/monitor/test.txt", O_CREAT);
	printf("%i\n", fildes);
	sys_close(fildes);
	fildes = sys_open("/monitor/test.txt", O_APPEND);
	printf("%i\n", fildes);
	sys_close(fildes);
}

int socket_test()
{
	struct sockaddr_in server_address;
	int socket = sys_socket(AF_INET, SOCK_STREAM, 0);

	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(3171);
	int pton = inet_pton(AF_INET, "10.0.2.2", &server_address.sin_addr);

	int conn = sys_connect(socket, (struct sockaddr *)&server_address, sizeof(struct sockaddr));

	printf("socket: %i\n", socket);
	printf("pton: %i\n", pton);
	printf("conn: %i\n", conn);

	char *msg = "XDD\n";
	int msg_size = 5;
	if (conn == 0) {
		int send = sys_sendto(socket, msg, msg_size, 0, NULL, 0);
		printf("send: %i\n", send);
	}
	sys_shutdown(socket, 2);
	return 0;
}

int main(int argc, char **argv)
{
	// socket_test();
	test_log_data(argc, argv);
	// test_file_nc();
	// test_file();

	// printf("%64i", sizeof(m_data));
	return 0;
}

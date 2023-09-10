#include <stdio.h>
#include <stdlib.h>
#include <monitor/log_data.h>
#include <phoenix/monitor.h>

int main(int argc, char **argv)
{
	const long int cns = 0;
	const int cs = 1;

	int s = cs;
	long int ns = cns;

	m_data mdata = {
		.mtype = mdt_msg,
		.data.msg = "Real Time Data"
	};

	if (argc == 2) {
		for (size_t i = 0; i < atoi(argv[1]); i++) {
			log_data(mbuff_rtmsg, mdata);
		}
	}
	else {
		while (1) {
			log_data(mbuff_rtmsg, mdata);
			nsleep(&s, &ns);
			s = cs;
			ns = cns;
		}
	}

	return 0;
}

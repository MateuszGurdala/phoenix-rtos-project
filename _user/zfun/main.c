#include <stdio.h>
#include <stdlib.h>
#include <monitor/log_data.h>

int main(int argc, char **argv)
{
	m_data data = {
		.mtype = mdt_msg,
		.data.msg = ""
	};

	if (argc == 2) {
		if (atoi(argv[1]) == 1)
			memcpy(data.data.msg, "Jeden", 6);
		else
			memcpy(data.data.msg, "Nie jeden", 10);

		log_data(mbuff_msg, data);
	}

	return 0;
}

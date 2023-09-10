#include <stdio.h>
#include <stdlib.h>
#include <phoenix/monitor.h>
#include <monitor/enable_threads_monitoring.h>

int main(int argc, char **argv)
{
	return enable_threads_monitoring();
}

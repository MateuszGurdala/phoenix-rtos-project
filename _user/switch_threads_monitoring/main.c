#include <stdio.h>
#include <stdlib.h>
#include <phoenix/monitor.h>
#include <monitor/switch_threads_monitoring.h>

int main(int argc, char **argv)
{
	return switch_threads_monitoring();
}

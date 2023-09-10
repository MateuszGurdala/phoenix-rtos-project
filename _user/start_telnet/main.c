/*
 * Phoenix-RTOS
 *
 * Hello World
 *
 * Example of user application
 *
 * Copyright 2021 Phoenix Systems
 * Author: Hubert Buczynski
 *
 * This file is part of Phoenix-RTOS.
 *
 * %LICENSE%
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	system("/sbin/ifconfig");
	system("/sbin/ifconfig en1 10.0.2.15");
	system("/usr/sbin/telnetd");

	return 0;
}

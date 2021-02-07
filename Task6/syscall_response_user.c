#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <fcntl.h>
#include <ctype.h>
#include <termios.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <sys/mman.h>

void delay(int n);
int main()
{
	int test_no;
	
	
	for(test_no=0;test_no < 50;test_no++)
	{
		syscall(439);
		delay(10000);
//		printf("\nHELLLO");
	}
	return 0;
}


void delay(int n)
{
	int i;
	for(i=0;i< (n*1000);n++)
	{
		;

	}

	return;	
}



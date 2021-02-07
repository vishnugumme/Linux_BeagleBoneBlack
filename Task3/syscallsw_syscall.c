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


#define GPIO1_START_ADDR 0x4804C000
#define GPIO1_END_ADDR   0x4804e000
#define GPIO1_SIZE (GPIO1_END_ADDR - GPIO1_START_ADDR)

#define GPIO_SETDATAOUT 0x194
#define GPIO_CLEARDATAOUT 0x190
#define GPIO_OE 0x134
#define GPIO_49 (1<<17)
#define USR_LED3 (1<<24)

int main()
{

volatile void *gpio_addr;
volatile unsigned int *gpio_setdataout_addr;
volatile unsigned int *gpio_cleardataout_addr;
volatile unsigned int *gpio_oe_addr;
int value;

 
int fd = open("/dev/mem", O_RDWR);
gpio_addr = mmap(0, GPIO1_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, GPIO1_START_ADDR);

gpio_setdataout_addr   = gpio_addr + GPIO_SETDATAOUT;
gpio_cleardataout_addr = gpio_addr + GPIO_CLEARDATAOUT;
gpio_oe_addr = gpio_addr + GPIO_OE;

*gpio_oe_addr &= ~(GPIO_49);

*gpio_setdataout_addr |= GPIO_49;  

syscall(437);
 



return 0;
}

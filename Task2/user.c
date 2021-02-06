#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>
#include <termios.h>
#include <sys/mman.h>
 
#define REG_CURRENT_TASK _IOW('a','a',int32_t*)
 
#define SIGETX 44

#define GPIO1_START_ADDR 0x4804C000
#define GPIO1_END_ADDR   0x4804e000
#define GPIO1_SIZE (GPIO1_END_ADDR - GPIO1_START_ADDR)

#define GPIO_SETDATAOUT 0x194
#define GPIO_CLEARDATAOUT 0x190
#define GPIO_OE 0x134
#define GPIO_49 (1<<17)
#define USR_LED3 (1<<24)

#define DEV "/dev/myled"
 
static int done = 0;
int check = 0;
 

void sig_event_handler(int n, siginfo_t *info, void *unused)
{
    if (n == SIGETX) {
        check = info->si_int;
        printf ("Received signal from kernel : Value =  %u\n", check);
    }
}
 
int main()
{
    int fd;
    int32_t value, number;
    struct sigaction act;
    volatile void *gpio_addr;
    volatile unsigned int *gpio_setdataout_addr;
    volatile unsigned int *gpio_cleardataout_addr;
    volatile unsigned int *gpio_oe_addr;
    
    int n = 0;

  
int fd1 = open("/dev/mem", O_RDWR);
gpio_addr = mmap(0, GPIO1_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd1, GPIO1_START_ADDR);

gpio_setdataout_addr   = gpio_addr + GPIO_SETDATAOUT;
gpio_cleardataout_addr = gpio_addr + GPIO_CLEARDATAOUT;
gpio_oe_addr = gpio_addr + GPIO_OE;

*gpio_oe_addr &= ~(GPIO_49);
 
    

    /* install custom signal handler */
    sigemptyset(&act.sa_mask);
    act.sa_flags = (SA_SIGINFO | SA_RESTART);
    act.sa_sigaction = sig_event_handler;
    sigaction(SIGETX, &act, NULL);
 
    printf("Installed signal handler for SIGETX = %d\n", SIGETX);
 
    printf("\nOpening Driver\n");
    fd = open(DEV, O_RDONLY);        //
    if(fd < 0) {
            printf("Cannot open device file...\n");
            return 0;
    }
 
    while (1)
    {
   
    while(!done) 
    {
        
    }
    done = 0;
    *gpio_setdataout_addr = GPIO_49;
    
    printf("interrupt : %d\n",n);
    n++;
    
    *gpio_cleardataout_addr = GPIO_49;
 
    }
    printf("Closing Driver\n");
    close(fd);
}











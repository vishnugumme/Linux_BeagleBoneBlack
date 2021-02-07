#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/gpio.h>
#include <asm/io.h>


asmlinkage long sys_syscall_response(void)
{
            gpio_direction_output(49, 1);
            gpio_direction_output(56, 1);
            gpio_direction_output(56, 0);
            
            gpio_direction_output(56, 1);
            gpio_direction_output(56, 0);
          
            gpio_direction_output(56, 1);
            gpio_direction_output(56, 0);
           

            gpio_direction_output(56, 1);
            gpio_direction_output(56, 0);


            gpio_direction_output(56, 1);
            gpio_direction_output(56, 0);

            gpio_direction_output(56, 1);

            gpio_direction_output(49, 0);

	    return 0;
}


#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/gpio.h>                 // Required for the GPIO functions
#include <linux/interrupt.h>            // Required for the IRQ code
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Vishnu Gumme , Saishn Kalaskar");
MODULE_DESCRIPTION("GPIO interrupt Loadable kernel module for the BBB");

static unsigned int gpio_output= 49;     
static unsigned int gpio_input = 48;
static unsigned int user_led = 56; //53-56
static unsigned int irqNumber;     
static bool	    ledOn = 0;      
unsigned int m=0;
static irq_handler_t  gpio_irq_handler(unsigned int irq, void *dev_id, struct pt_regs *regs);

int init_module(void)   //init function to be called at the time of insmod
{
   int result = 0;
   printk(KERN_INFO "GPIO_TEST: Initializing the GPIO_TEST\n");
   // Is the GPIO a valid GPIO number (e.g., the BBB has 4x32 but not all available)
   if (!gpio_is_valid(gpio_output)){
      printk(KERN_INFO "GPIO_TEST: invalid LED GPIO\n");
      return -ENODEV;
   }
   // Going to set up the LED. It is a GPIO in output mode and will be on by default
   ledOn = true;
   gpio_request(gpio_output, "sysfs");          // gpio_output is hardcoded to 49, request it
   gpio_direction_output(gpio_output, ledOn);   // Set the gpio to be in output mode and on
   gpio_set_value(gpio_output, ledOn);          // Not required as set by line above (here for reference)
   gpio_export(gpio_output, false);             // Causes gpio49 to appear in /sys/class/gpio
			                    // the bool argument prevents the direction from being changed
   gpio_request(gpio_input, "sysfs");       // Set up the gpio_input
   gpio_direction_input(gpio_input);        // Set the button GPIO to be an input
   gpio_export(gpio_input, false);          // Causes gpio115 to appear in /sys/class/gpio
			                    // the bool argument prevents the direction from being changed
   // Perform a quick test to see that the button is working as expected on LKM load
   printk(KERN_INFO "GPIO_TEST: Status of Input signal: %d\n", gpio_get_value(gpio_input));

   // GPIO numbers and IRQ numbers are not the same! This function performs the mapping for us
   irqNumber = gpio_to_irq(gpio_input);
   printk(KERN_INFO "GPIO_TEST: Input Pin is mapped to IRQ: %d\n", irqNumber);

   // This next call requests an interrupt line
   result = request_irq(irqNumber,             // The interrupt number requested
                        (irq_handler_t) gpio_irq_handler, // The pointer to the handler function below
                        IRQF_TRIGGER_RISING,   // Interrupt on rising edge (button press, not release)
                        "gpio_irq_handler",    // Used in /proc/interrupts to identify the owner
                        NULL);                 // The *dev_id for shared interrupt lines, NULL is okay

   printk(KERN_INFO "GPIO_TEST: The interrupt request result is: %d\n", result);
   return result;
}

void cleanup_module(void) //exit function to be called at the time of rmmod
{
   printk(KERN_INFO "GPIO_TEST: The button state is currently: %d\n", gpio_get_value(gpio_input));
   gpio_set_value(gpio_output, 0);              // Turn the LED off, makes it clear the device was unloaded
   gpio_unexport(gpio_output);                  // Unexport the LED GPIO
   free_irq(irqNumber, NULL);               // Free the IRQ number, no *dev_id required in this case
   gpio_unexport(gpio_input);               // Unexport the Button GPIO
   gpio_free(gpio_output);                      // Free the LED GPIO
   gpio_free(gpio_input);                   // Free the Button GPIO
   printk(KERN_INFO "GPIO_TEST: Goodbye from the LKM!\n");
}

static irq_handler_t gpio_irq_handler(unsigned int irq, void *dev_id, struct pt_regs *regs)
{
   gpio_direction_output(gpio_output, 1);
   ledOn = !ledOn;
   gpio_direction_output(user_led, ledOn);
   printk(KERN_INFO "GPIO_TEST: Interrupt!");
   gpio_direction_output(gpio_output, 0);
   return (irq_handler_t) IRQ_HANDLED;      // Announce that the IRQ has been handled correctly
}


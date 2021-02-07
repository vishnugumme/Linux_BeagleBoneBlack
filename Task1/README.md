## Task1
It is the task to get a time required to start the service to the interrupt. Follow the following steps to observe live response time graph.
1. Hardware setup is of setup-1 of project as mentioned in the [link](http://shukra.cedt.iisc.ernet.in/edwiki/Real-time_response_of_the_Embedded_Linux_system_on_BeagleBone_Black_Wireless).<br>
2.To build the loadable interrupt kernel module follow [Task1](Task1). <br>
  * To clean up the module directory
      `make clean`
  * To build the loadable module of interrupt
     `./build.sh` : with this intrrupt_module.ko file will be generated.
  * To dynamically load module in Linux Kernel on BBB
     `sudo insmod intrrupt_module.ko`
  * To remove the inserted module on BBB
     `sudo rmmod intrrupt_module`
  Cross build the module and dynamically load into the kernel of BBB.
4. To get the response plot nn linux Machine from Tiva board through UART, follow [link](../plot/). Before plotting get ready the connection between gtkterm and Tiva board UART using tty/ACMO and direct output from gtkterm to [file](plot/realtime.txt).<br>
3. Import [project](atomthreads_on_tivac_interrupt_latency) in Code Composer Studio version above 10. Run in debug mode.<br>
5. Press SW1 or SW2 button on Tiva Borad.<br> 
6. Observe the plot.<br>
7. For load conditions, run object file on BBB from [folder](Page_Fault/) for page fault loading and transfer large file from linux machine to BBB with `sudo scp large_file debian@BBB_ip:/home/folder`.<br> 
8. Observe the Plot with loading conditions.<br>





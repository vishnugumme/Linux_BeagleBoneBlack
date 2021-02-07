# Linux_BeagleBoneBlack
The project aims to extract the timing parameters that shows the real-time responsiveness of the Embedded Linux system ported on BeagleBone Black Wireless.
## Introduction
To find information about the project at [Shukra DESE link](http://shukra.cedt.iisc.ernet.in/edwiki/Real-time_response_of_the_Embedded_Linux_system_on_BeagleBone_Black_Wireless).
## Implementation
1. Setup the software part of BBB , follow [link](http://shukra.dese.iisc.ac.in/edwiki/EmSys:Embedded_Systems_Design_II_Embedded_Linux).
2. Whenever to tranfer cross compiled files to BBB, we can use SSH utility or network mount folder using sshfs utility.
### Task1
It is the task to get a time required to start the service to the interrupt. Follow the following steps to observe live response time graph.

1.To build the loadable interrupt kernel module follow [Task1](Task1). insert module in BBB.<br>
2. Import [project](atomthreads_on_tivac_interrupt_latency) in Code Composer Studio version above 10. Run in debug mode.<br>
3. To get the response plot On linux Machine from Tiva board UART output, follow [link](plot/). Before plotting get ready the connection between gtkterm and Tiva board UART using tty/ACMO and direct output from gtkterm to [file](plot/realtime.txt).<br>
4. Press SW1 or SW2 button on Tiva Borad.<br> 
5. Observe the plot.<br>
6. For load conditions, run object file on BBB from [folder](Page_Fault/) for page fault loading and transfer large file from linux machine to BBB with `sudo scp large_file debian@BBB_ip:/home/folder`.<br> 
7. Observe the Plot with loading conditions.<br>
### Task2
It is the total time to finish the interrupt service part and user application service part and giving response back to the external event.
Follow same steps as Task1 excepts following step numbers.
1. To build the loadable interrupt signal kernel module follow [Task2](Task2/). insert module in BBB. Also run the object file `sudo ./user` same as in the folder[Task2](Task2/) after cross compiling this file.<br>
### Task3

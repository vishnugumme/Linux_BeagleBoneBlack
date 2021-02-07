## Task2
It is the total time to finish the interrupt service part and user application service part and giving response back to the external event.
Follow the following steps to observe live response time graph.
1. Setup hardware with setup-1 of project as mentioned in the [link](http://shukra.cedt.iisc.ernet.in/edwiki/Real-time_response_of_the_Embedded_Linux_system_on_BeagleBone_Black_Wireless).<br>
2.To build the loadable interrupt signal kernel module follow [Task2](Task2). <br>
  * To clean up the module directory
      `make clean`
  * To build the loadable module of interrupt
     `./build.sh` : with this interrupt_signal.ko file will be generated.
  * To dynamically load module in Linux Kernel on BBB
     `sudo insmod interrupt_signal.ko`
  * To remove the inserted module on BBB
     `sudo rmmod intrrupt_signal`
  * To build user code run<br>
     1. `export CC=/opt/gcc-arm-8.3-2019.03-x86_64-arm-linux-gnueabihf/bin/arm-linux-gnueabihf- `<br>
     2. `${CC}gcc user.c -o user`<br>

  Cross build the module,user code, transfer both to BBB, dynamically load into the kernel and run `sudo ./user`.<br>
  
4. To get the response plot on linux Machine via UART of Tiva board, follow [link](../plot/).<br>
3. Import [project](../Task1/atomthreads_on_tivac_interrupt_latency) in Code Composer Studio version above 10. Run in debug mode.<br>
5. Press SW1 or SW2 button on Tiva Borad.<br> 
6. Observe the plot.<br>
7. For load conditions, for page_fault load follow [link](Page_Fault/) and for networking load you can transfer large file from linux machine to BBB with `sudo scp large_file debian@BBB_ip:/home/folder` shell command.<br> 
8. Observe the Plot with loading conditions.<br>

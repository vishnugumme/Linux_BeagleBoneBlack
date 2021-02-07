* To build user code run the command in terminal in Linux Machine
1. `export CC=/opt/gcc-arm-8.3-2019.03-x86_64-arm-linux-gnueabihf/bin/arm-linux-gnueabihf- `<br>
2. `${CC}gcc page_fault_buffer.c -o page_fault_buffer`<br>
3. `${CC}gcc page_fault_buffer_300MB.c -o page_fault_buffer_300MB`<br>
4. `${CC}gcc page_fault_buffer_500MB.c -o page_fault_buffer_500MB` <br>

* Run the object file on BBB<br>
`sudo ./page_fault_buffer`<br>





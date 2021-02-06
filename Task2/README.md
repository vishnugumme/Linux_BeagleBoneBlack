
* To clean up the module directory
`make clean`
* To build the loadable module of interrupt
`./build.sh`
with this intrrupt_signal.ko file will be generated.
* To insert module on BBB
`sudo insmod interrupt_signal.ko`
* To remove the inserted module on BBB
`sudo rmmod intrrupt_signal`
* To build user code run
`export CC=/opt/gcc-arm-8.3-2019.03-x86_64-arm-linux-gnueabihf/bin/arm-linux-gnueabihf- `
`${CC}gcc user.c -o user`


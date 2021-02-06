
* To clean up the module directory
`make clean`
* To build the loadable module of interrupt
`./build.sh`
with this intrrupt_signal.ko file will be generated.
* To insert module on BBB
`sudo insmod interrupt_signal.ko`
* TO remove the inserted module on BBB
`sudo rmmod intrrupt_signal`

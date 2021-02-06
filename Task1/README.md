* To clean up the module directory
`make clean`
* To build the loadable module of interrupt
`./build.sh`
with this intrrupt_module.ko file will be generated.
* To insert module on BBB
`sudo insmod intrrupt_module.ko`
* TO remove the inserted module on BBB
`sudo rmmod intrrupt_module`

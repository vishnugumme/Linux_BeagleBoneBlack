# File Details
**realtime.txt**
: This files contains colomn of the response time, written by gtkerm, this data is output from Tiva board UART.<br>
**realtime.p**
: This is script for the gnuplot, to plot the live graph from the live data stored in realtime.txt
# Connection b/w Tiva Board to gtkterm
  1. Open gtkterm
  2. Open Port tty/ACM0 with 115200-8-N-1
  3. Direct log to file realtime.txt.
# To Start the graph 
`$ gnuplot` : start gnuplot<br>
`load(realtime.p)`: start the script running<br>

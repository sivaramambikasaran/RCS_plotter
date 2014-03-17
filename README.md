RCS plotter
===========

This generates a vector graphics plot of the Radar Cross Section for an object. It needs an input file with angle in radians and the corresponding value of the radar cross section.

1) Let the input file be "RCS_input.txt". This file should be as follows, where the first column is angle in radians and the second column is the RCS.

	7.853982e-02 	 6.507411e+00 
	8.028515e-02 	 7.091329e+00 
	8.203047e-02 	 7.712130e+00 
	8.377580e-02 	 8.371069e+00 
	8.552113e-02 	 9.069380e+00 
	8.726646e-02 	 9.808279e+00 
	8.901179e-02 	 1.058895e+01 
	and so on...

2) Make sure you have the permission to run the script.

	chmod 755 RCS.sh

3) Now run the script.

	./RCS.sh

4) You will be prompted to enter the name of the input file,

	Enter the name of the input file:

5) Key in the name of the input file, in our case, it is "RCS_input.txt", without quotes.

6) You will then prompted to enter the legend,

	Enter legend:

7) Key in the legend name you want to, for instance, 'test'.

8) And thats it. The script with now write a tex file named 'RCS_plot.tex' and compile the tex file and if everything goes well, you will have a file named 'RCS_plot.pdf' containing the figure


<img style="float: right" src="https://github.com/sivaramambikasaran/RCS_plotter/raw/master/RCS_plot.png" />

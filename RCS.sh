#/bin/bash

g++ -O3 rcs.cc -o rcs
echo "Enter the name of the input file: "
read filename
./rcs $filename
pdflatex RCS_plot.tex
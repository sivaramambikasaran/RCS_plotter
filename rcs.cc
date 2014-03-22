#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
#include <cmath>

using namespace std;

//	Read the values from the file.
void read_RCS_values(string file, vector<double>& theta, vector<double>& RCS) {
	fstream myfile;
	myfile.open(file.c_str(), ios::in);
	double a, b;
	if (myfile.is_open()) {
		while (myfile >> a >> b) {
			theta.push_back(a);
			RCS.push_back(10*log10(b));
		}
	}
}

void compute_Plot_RCS(vector<double> theta, vector<double> RCS, string filename) {
	int N						=	theta.size();
	cout << "Data size is: " << N << endl;
	const double PI				=	3.141592653589793238462643;
	const double PI_over_180	=	PI/180.0;
	const double one80_over_PI	=	180.0/PI;

//	double mintheta	=	floor(one80_over_PI**std::min_element(theta.begin(), theta.end()));
	double mintheta		=	0;
//	double maxtheta	=	ceil(one80_over_PI**std::max_element(theta.begin(), theta.end()));
	double maxtheta		=	180;
	
	double minRCS	= 	floor(*std::min_element(RCS.begin(), RCS.end()));
	double maxRCS	= 	ceil(*std::max_element(RCS.begin(), RCS.end()));

	ofstream myfile;
	myfile.open(filename.c_str(), ios::out | ios::app);
	myfile <<"\\begin{tikzpicture}[scale=1]" << endl;
	myfile <<"\\begin{polaraxis}[xmin=" << mintheta <<", xmax=" << maxtheta << ", ymin=" << 10*floor(minRCS/10) << ",y coord trafo/.code=\\pgfmathparse{#1- "<< 10*floor(minRCS/10) << "}, y coord inv trafo/.code=\\pgfmathparse{#1+ " << 10*floor(minRCS/10) << "}, ytick = {" << 10*floor(minRCS/10) << "," << 10*floor(minRCS/10)+10 << ",...," << 10*ceil(maxRCS/10) << "}, every axis/.append style={font=\\tiny},] ";
	myfile << "\\addplot [thin, color = red] coordinates {" << endl;
	for (int k=0; k<N; ++k) {
		myfile << "(" << one80_over_PI*theta[k] << "," << RCS[k] << ")" << endl;
	}
	myfile << "};" << endl;
	myfile <<"\\end{polaraxis}" << endl;
	myfile <<"\\end{tikzpicture}" << endl;
	myfile.close();
}

void create_Tex_Beginning(string filename) {
	ofstream myfile;
	myfile.open(filename.c_str(), ios::out);
	myfile << "\\documentclass{standalone}" << endl;
	myfile << "\\usepackage{tikz}" << endl;
	myfile << "\\usepackage{pgfplots}" << endl;
	myfile << "\\pgfplotsset{compat = newest}" << endl;
	myfile << "\\usepgfplotslibrary{polar}" << endl;
	myfile << "\\begin{document}" << endl;
	myfile.close();
}

void finish_Tex_File(string filename) {
	ofstream myfile;
	myfile.open(filename.c_str(), ios::out | ios::app);
	myfile << "\\end{document}" << endl;
	myfile.close();
}

int main(int argc, char* argv[]) {
	assert(argc>1 && "Enter the file name:");
	string input_File_Name	=	argv[1];

	cout << "read_RCS_values" << endl;
	vector<double> theta;
	vector<double> RCS;
	read_RCS_values(input_File_Name, theta, RCS);

	cout << "create_Tex_Beginning" << endl;
	string RCS_plot_file = "RCS_plot.tex";
	create_Tex_Beginning(RCS_plot_file);

	cout << "compute_Plot_RCS" << endl;
	compute_Plot_RCS(theta, RCS, RCS_plot_file);

	cout << "finish_Tex_File" << endl;
	finish_Tex_File(RCS_plot_file);
}
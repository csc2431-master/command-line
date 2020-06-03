#include <iostream>
#include <string>
#include <cstdlib>

using std::cout;
using std::endl;
using std::string;
using std::stoi;
using std::stod;
using std::cerr;


bool IsInteger(const string& str);
bool IsDouble(const string& str);

/**
 * This is a main function to show how to work with
 * command line parameters
 * @param argc this parameter holds the number (count) of arguments. Every program
 * 				has at least argc = 1, the name of the program. If additional
 * 				parameters are sent then argc > 1.
 * @param argv this is an array of C-Strings that hold the actual parameters. This
 * 				array will have at least one string, the name of the program, if
 * 				additional parameters are sent are going to be stored in argv[1],
 * 				argv[2], ..., argv[argc - 1]
 * @return the exit code for the operating system. Returning 0 means that the program
 * 				exited successfully.
 */

int main(int argc, char* argv[]) {
	// Printing the command line parameters
	for (int i = 0; i < argc; ++i) {
		cout << "Parameter " << i << " :" << argv[i] << endl;
	}

	// Validate the number of command line parameters
	if (argc != 4){ // How many parameters are expected??
		cerr << "Not enough or too many arguments" << endl;
		return 1;
	}
	string action = argv[1];
	if (action != "-add" && action != "-multiply"){
		cerr << "Wrong operation, use -add or -multiply" << endl;
		return 1;
	}
	if (!IsInteger(argv[2]) || !IsDouble(argv[3])){
		cerr << "The numeric parameters must be an integer and a real" << endl;
		return 1;
	}
	int times = stoi(argv[2]);
	double value = stod(argv[3]);

	if (action == "-add"){
		double add = 0;
		for (int i = 0; i < times; ++i) {
			add += value;
		}
		cout << add << endl;
	}else if (action == "-multiply"){
		double multiply = 1;
		for (int i = 0; i < times; ++i) {
			multiply *= value;
		}
		cout << multiply << endl;
	}else{
		cerr << "This should never happen" << endl;
		return -1;
	}


	return 0;
}
bool IsInteger(const string& str){
	int value = atoi(str.c_str());
	if (str != "0" && value == 0)
		return false;
	else // It could increase robustness if we traverse and check with isdigit
		return true;
}
bool IsDouble(const string& str){
	double value = atof(str.c_str());
	if (str != "0.0" && value == 0)
		return false;
	else
		return true;
}

#include <sstream>
#include <string>
#include "common.h"

using namespace std;

int main(int argc, char *argv[]){
    //Read the input file

    string fileName = argv[1];
    stringstream len_s(argv[2]);
    string type = argv[3];

    int len = 0;
    int arr[len];
    string buff;
    string delimiter = ", ";

    len_s >> len;
    
    ifstream infile(fileName.c_str());
    if (infile.is_open()) {
	getline(infile, buff);
    }
    else {
        cout << "Unable to open file";
    }

    for (int i = 0; i < len; i++) {
	stringstream token(buff.substr(0, buff.find(delimiter)));
	buff.erase(0, buff.find(delimiter) + delimiter.length());
	token >> arr[i];
    }
    infile.close();

    //Start the sorting algorithms. 
    clock_t time_req = clock();

    if (!type.compare("brick")) {
	time_req = clock();
	brickSort(arr, len);
    }
    else if (!type.compare("radix")) {

	time_req = clock();
	radixSort(arr, len);
    }
    else if (!type.compare("merge")) {
	time_req = clock();
	mergeSort(arr, len);
    }
    else if (!type.compare("quick")) {
	time_req = clock();
	quickSort(arr, len);
    }
    else if (!type.compare("bitonic")) {
	time_req = clock();
	bitonicSort(arr, len);
    }
    else {
	cout << "Error, wrong sort" << endl;
    }   


    // Print the execution time    
    cout << "Time taken is: " << (float) (clock() - time_req) / CLOCKS_PER_SEC << " seconds." << endl;

    //Output final array to file
    string ans = "";
    for (int i = 0; i < len; i++) {
	stringstream int_s;
	int_s << arr[i];	
	ans.append(int_s.str());

	if (i != len - 1) {
	    ans.append(", ");
	}
    }
    
    string prefix = "out_";
    type = prefix.append(type.append(".txt"));
    ofstream outfile(type.c_str());
    outfile << ans;
    outfile.close();

    return 0;
}

#include <sstream>
#include <string>
#include "common.h"

using namespace std;

int main(int argc, char *argv[]){
    //Read the input file

    char* fileName = argv[1];
    stringstream len_s(argv[2]);
    string type = argv[3];

    int len = 0;
    int arr[len];
    string buff;
    string delimiter = ", ";

    len_s >> len;
    
    ifstream myfile(fileName);
    if (myfile.is_open()) {
	getline(myfile, buff);
    }
    else {
        cout << "Unable to open file";
    }

    for (int i = 0; i < len; i++) {
	stringstream token(buff.substr(0, buff.find(delimiter)));
	buff.erase(0, buff.find(delimiter) + delimiter.length());
	token >> arr[i];
    }

    //Start the sorting algorithms. 
    clock_t time_req = clock();

    if (!type.compare("brickSort")) {
	time_req = clock();
	brickSort(arr, len);
    }
    else if (!type.compare("radixSort")) {

	time_req = clock();
	radixSort(arr, len);
    }
    else if (!type.compare("mergeSort")) {
	time_req = clock();
	mergeSort(arr, len);
    }
    else if (!type.compare("quickSort")) {
	time_req = clock();
	quickSort(arr, len);
    }
    else if (!type.compare("bitonicSort")) {
	time_req = clock();
	bitonicSort(arr, len);
    }
    else {
	cout << "Error, wrong sort" << endl;
    }   


    // Print the execution time    
    cout << (float) (clock() - time_req) / CLOCKS_PER_SEC << "\n";

    return 0;
}

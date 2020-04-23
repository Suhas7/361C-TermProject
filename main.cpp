#include <sstream>
#include <string>
#include "common.h"
#include <string.h>
#include <stdio.h>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]){
    //Read the input file
    string fileName = argv[1];
    string type = argv[2];
    char* token;
    int len = 0;
    int index = 0;
    string buff;
    string delimiter = ", ";

    ifstream infile(fileName.c_str());
    if (infile.is_open()) {
	getline(infile, buff);
    }
    else {
        cout << "Unable to open file";
    }
    infile.close();

    const char* tmp = buff.c_str();
    char* line_num_counter = (char * )malloc(buff.length() + 1);
    char* line_element = (char * )malloc(buff.length() + 1);
    memcpy(line_num_counter, tmp, buff.length() + 1);
    memcpy(line_element, tmp, buff.length() + 1);

    token = strtok(line_num_counter, ",");
    while (token != NULL) {
	len++;
	token = strtok(NULL, ",");
    }

    int arr[len];
    token = strtok(line_element, ",");
    while (token != NULL) {
	arr[index] = atoi(token);
	token = strtok(NULL, ",");
 	index++;
    }	


    //Start the sorting algorithms. 
    double time_start = 0;

    if (!type.compare("brick")) {
	time_start = omp_get_wtime();
	brickSort(arr, len);
    }
    else if (!type.compare("radix")) {

	time_start = omp_get_wtime();
	radixSort(arr, len);
    }
    else if (!type.compare("merge")) {
	time_start = omp_get_wtime();
	mergeSort(arr, len);
    }
    else if (!type.compare("quick")) {
	time_start = omp_get_wtime();
	quickSort(arr, len);
    }
    else if (!type.compare("bitonic")) {
	time_start = omp_get_wtime();
	bitonicSort(arr, len);
    }
    else {
	cout << "Error, wrong sort" << endl;
    }   


    // Print the execution time    
    cout << "Time taken is: " << (float) (omp_get_wtime() - time_start) << " seconds." << endl;

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

    for (int i = 0; i < len-1; i++) {
	if(arr[i] > arr[i+1]) cout << "ERROR" << endl; 
    }
    return 0;
}

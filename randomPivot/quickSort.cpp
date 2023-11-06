#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>
#include <chrono>

using namespace std;
namespace fs = std::filesystem;

int SWAP_COUNT = 0;
string RESULT_FILENAME = "resultsRandomPivot.csv";
string DATABASE_NAME = "database";
string DATABASE_TEST_NAME = "database_test";
string DATABASE_PATH = "./" + DATABASE_NAME;
string PATH[] = {
    DATABASE_PATH + "/Aleatorios",
    DATABASE_PATH + "/Ordenados",
    DATABASE_PATH + "/Decrescentes",
    DATABASE_PATH + "/ParcialmenteOrdenados"
};

void swap(int * a, int * b) {
    int t = * a;
    * a = * b;
    * b = t;
	SWAP_COUNT++;
}

int selectRandomPivot(int start, int end) {
    return start + rand() % (end - start);
}

int partition(vector < int > & arr, int start, int end) {

	// Select pivot randomly
	int pivotIndex = selectRandomPivot(start, end);
	int pivot = arr[pivotIndex];

	swap(&arr[pivotIndex], &arr[end]);

	int i = (start - 1);

	for (int j = start; j < end; j++) {
		if (arr[j] < pivot)	{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	
	swap(&arr[i + 1], &arr[end]);
	
	return (i + 1);
}

void quickSort(vector < int > & arr, int start, int end)
{
	if (start >= end) return;	// Base case

	int p = partition(arr, start, end);
	
	// Sorting the left part
	quickSort(arr, start, p - 1);
	
	// Sorting the right part
	quickSort(arr, p + 1, end);
}

bool getFileContent(string fileName, vector < int > & data) {

    ifstream in (fileName);

    if (! in .is_open()) {
        cerr << "Cannot open the File : " << fileName << endl;
        return false;
    }

    int num;

    while ( in >> num) {
        data.push_back(num);
    }

    in .close();

    return true;
}

void printArray(vector < int > & data) {
    cout << "Sorted array: \n";
	for (const auto & i: data) {
        cout << i << ", ";
    }
    cout << endl << endl;
}

int main() {

	ofstream csvFile;
    csvFile.open(RESULT_FILENAME);

    const int dataSets = sizeof(PATH)/sizeof(*PATH);
    const int numTests = 32;
    

    for (int i = 0; i < dataSets; i++) {
        
        const string path = PATH[i];
        
        csvFile << "Dataset: " << path.substr(DATABASE_PATH.length() + 1) << ", ";
        csvFile << "\n";

        for (const auto & entry: fs::directory_iterator(path)) {
        
            csvFile << "Size: " << (entry.path().string()).substr(path.length() + 1) << ", ";
            csvFile << "\n";
            csvFile << "Tempo(ms)" << ", " << "Swaps" << ", ";
            csvFile << "\n";

            for (int test = 0; test < numTests; test++) {
                
                srand((unsigned)time(NULL));
                vector < int > data;
                getFileContent(entry.path().string(), data);
                int dataSize = data.size();

                auto start = std::chrono::high_resolution_clock::now();
                quickSort(data, 0, dataSize - 1);
                auto end = std::chrono::high_resolution_clock::now();

                std::chrono::duration < double, std::milli > float_ms = end - start;

                // printArray(data);

                csvFile << float_ms.count() << ", ";
                csvFile << SWAP_COUNT << ", ";
                csvFile << "\n";

                SWAP_COUNT = 0;
            }

            csvFile << "\n\n";
        }
    }

	cout << "Execution Completed Successfully!!" << endl;
	return 0;
}
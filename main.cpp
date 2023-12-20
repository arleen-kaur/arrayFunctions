#include <iostream>
#include <fstream>
using namespace std;
//include any standard libraries needed


//  - Passes in an array along with the size of the array.
//  - Returns the mean of all values stored in the array.
double mean(const double array[], int arraySize);

//  - Passes in an array, the size of the array by reference, and the index of a value to be removed from the array.
//  - Removes the value at this index by shifting all of the values after this value up, keeping the same relative order of all values not removed.
//  - Reduces arraySize by 1.
void remove(double array[], int &arraySize, int index);


// - Passes in an array and the size of the array.
// - Outputs each value in the array separated by a comma and space, with no comma, space or newline at the end.
void display(const double array[], int arraySize);


const int ARR_CAP = 100;

int main(int argc, char *argv[]) {
   if (argc !=2) {
      return 1;
   }
   ifstream inFS;
   
   // verify file name provided on command line
   inFS.open(argv[1]);
   if (!inFS.is_open()) {
      cout << "Could not open file " << argv[1] << "." << endl;
      return 1;
   }
   // open file and verify it opened
      
   // Declare an array of doubles of size ARR_CAP.

    double ARR[ARR_CAP];
      int i = 0;
      while (i < ARR_CAP && inFS >> ARR[i]) {
         i++;
      }
   // Fill the array with up to ARR_CAP doubles from the file entered at the command line.

    cout << "Mean: " << mean(ARR, i) << endl;
   // Call the mean function passing it this array and output the 
   // value returned.
    
    int userIndex;
    cout << "Enter index of value to be removed (0 to  " << i - 1 << "):" << endl;
    cin >> userIndex;
   // Ask the user for the index (0 to size - 1) of the value they want to remove.
   cout << "Before removing value: ";
   display(ARR, i);
   cout << endl;
	
   // Call the display function to output the array.
   remove(ARR, i, userIndex);
   cout << "After removing value: ";
   
   // Call the remove function to remove the value at the index
   // provided by the user.
  
    display (ARR, i);
    cout << endl;
   // Call the display function again to output the array
   // with the value removed.

   // Call the mean function again to get the new mean
   cout << "Mean: " << mean(ARR, i) << endl;

	return 0;
}

double mean(const double array[], int arraySize) {
   if (arraySize > 0) {
      double sum = 0.0;
         for (int i = 0; i < arraySize; i++) {
            sum = array[i] + sum;
         }
         return sum / arraySize;
   } else {
      return 1;
   }
}
void remove(double array[], int &arraySize, int index) {
   if ((arraySize > 0) && (index < arraySize))  {
      for (int i = index; i < arraySize - 1; i++) {
            array[i] = array [i + 1];
         }
         arraySize = arraySize - 1;
   }
}
void display(const double array[], int arraySize) {
   for (int i = 0; i < arraySize; i++) {
      cout << array[i];
      if (i != arraySize - 1) {
         cout << ", ";
      }
   }
}
#include <iostream>
#include <string>

using namespace std;

int main() {
    int arraySize;
    cout << "Enter the number of countries you want to input: ";
    cin >> arraySize;

    string countries[arraySize]; 

    cout << "Enter country names, each on a new line:" << endl;

    string dummy;
    getline(cin, dummy); 
    for (int i = 0; i < arraySize; i++) {
        getline(cin, countries[i]);
    }

    if (arraySize >= 4) {
        cout <<"The country at the custom index 0 is: " << countries[3] << endl;
    } else {
        cout << "Not enough countries in the list" << endl;
    }
    return 0;
}


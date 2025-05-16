#include<iostream>
#include<string>
using namespace std;



























// Menu display functions
void displayMainMenu() {
    cout << "\nFile Management System\n";
    cout << "1. Create File\n";
    cout << "2. Delete File\n";
    cout << "3. List Files\n";
    cout << "4. Search File\n";
    cout << "5. Sort Files\n";
    cout << "6. File Operations\n";
    cout << "7. Delete All Files\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}

void displayCreateMenu() {
    cout << "\nCreate File Options:\n";
    cout << "1. At the beginning\n";
    cout << "2. At a specific position\n";
    cout << "3. At the end\n";
    cout << "0. Back to main menu\n";
    cout << "Enter your choice: ";
}

void displayDeleteMenu() {
    cout << "\nDelete File Options:\n";
    cout << "1. From the beginning\n";
    cout << "2. From a specific position\n";
    cout << "3. From the end\n";
    cout << "4. By filename\n";
    cout << "0. Back to main menu\n";
    cout << "Enter your choice: ";
}

void displaySortMenu() {
    cout << "\nSort Files By:\n";
    cout << "1. Name\n";
    cout << "2. Size\n";
    cout << "3. Date Modified\n";
    cout << "0. Back to main menu\n";
    cout << "Enter your choice: ";
}

void displayFileOperationsMenu() {
    cout << "\nFile Operations:\n";
    cout << "1. Read File\n";
    cout << "2. Append to File\n";
    cout << "3. Overwrite File\n";
    cout << "4. File Statistics\n";
    cout << "5. Display File Content from Memory\n";
    cout << "6. Search Files by Prefix\n";
    cout << "0. Back to main menu\n";
    cout << "Enter your choice: ";
}
int main() {




    return 0;
}
#include<iostream>
#include<string>
using namespace std;

struct FileNode {
    string filename;
    string content;
    size_t size;
   
    FileNode* prev;
    FileNode* next;
    
};












void removeFileFromBeginning() {
        if (isEmpty()) {
            cout << "List is empty.\n";
            return;
        }

        FileNode* temp = head;
        
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        
        cout << "File '" << temp->filename << "' removed from beginning of list.\n";
        delete temp;
        size--;
    }
  

    void removeFileFromEnd() {
        if (isEmpty()) {
            cout << "List is empty.\n";
            return;
        }

        FileNode* temp = tail;
        
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        
        cout << "File '" << temp->filename << "' removed from end of list.\n";
        delete temp;
        size--;
    }
    void removeFileFromPosition(int position) {
        if (position < 0 || position >= size) {
            cout << "Invalid position.\n";
            return;
        }

        if (position == 0) {
            removeFileFromBeginning();
            return;
        }

        if (position == size - 1) {
            removeFileFromEnd();
            return;
        }

        FileNode* current = head;
        
        for (int i = 0; i < position; i++) {
            current = current->next;
        }
        
        current->prev->next = current->next;
        current->next->prev = current->prev;
        
        cout << "File '" << current->filename << "' removed from position " << position << ".\n";
        delete current;
        size--;
    }

   void removeFile(const string& filename) {
        if (isEmpty()) {
            cout << "List is empty.\n";
            return;
        }

        if (head->filename == filename) {
            removeFileFromBeginning();
            return;
        }

        if (tail->filename == filename) {
            removeFileFromEnd();
            return;
        }

        FileNode* current = head->next;
        while (current && current->filename != filename) {
            current = current->next;
        }

        if (current) {
            current->prev->next = current->next;
            if (current->next) {
                current->next->prev = current->prev;
            }
            cout << "File '" << current->filename << "' removed.\n";
            delete current;
            size--;
        } else {
            cout << "File '" << filename << "' not found.\n";
        }
    }




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
    
    int choice, subChoice, position;
    string filename, content;

    while (true) {
        displayMainMenu();
        cin >> choice;
        

        switch (choice) {
            case 1: // Create File
                while (true) {
                    displayCreateMenu();
                    cin >> subChoice;
                    
                    
                    if (subChoice == 0) break;
                    
                    cout << "Enter filename: ";
                    getline(cin, filename);
                    
                    switch (subChoice) {
                        case 1:
                            
                            break;
                        case 2:
                            cout << "Enter position: ";
                            cin >> position;
                           
                            break;
                        case 3:
                            
                            break;
                        default:
                            cout << "Invalid choice.\n";
                    }
                }
                break;
                
            case 2: // Delete File
                while (true) {
                    displayDeleteMenu();
                    cin >> subChoice;
                   
                    
                    if (subChoice == 0) break;
                    
                    switch (subChoice) {
                        case 1:
                  
                            break;
                        case 2:
                            cout << "Enter position: ";
                            cin >> position;
                            
                            
                            break;
                        case 3:
                            
                        
                            break;
                        case 4:
                            cout << "Enter filename to delete: ";
                            getline(cin, filename);
                            
                            break;
                        default:
                            cout << "Invalid choice.\n";
                    }
                }
                break;
                
            case 3: // List Files
               
                break;
                
            case 4: // Search File
                cout << "Enter filename to search: ";
                getline(cin, filename);
               
                break;
                
            case 5: // Sort Files
                while (true) {
                    displaySortMenu();
                    cin >> subChoice;
                    
                    
                    if (subChoice == 0) break;
                    
                    
                }
                break;
                
            case 6: // File Operations
                while (true) {
                    displayFileOperationsMenu();
                    cin >> subChoice;
                    
                    
                    if (subChoice == 0) break;
                    
                    switch (subChoice) {
                        case 1:
                            cout << "Enter filename to read: ";
                            getline(cin, filename);
                           
                            break;
                        case 2:
                            cout << "Enter filename to append: ";
                            getline(cin, filename);
                            cout << "Enter content to append: ";
                            getline(cin, content);
                            
                            break;
                        case 3:
                            cout << "Enter filename to overwrite: ";
                            getline(cin, filename);
                            cout << "Enter new content: ";
                            getline(cin, content);
                            
                            break;
                        case 4:
                            cout << "Enter filename for statistics: ";
                            getline(cin, filename);
                           
                            break;
                        case 5:
                            cout << "Enter filename to display from memory: ";
                            getline(cin, filename);
                            
                            break;
                        case 6:
                            
                            break;
                        default:
                            cout << "Invalid choice.\n";
                    }
                }
                break;
                
            case 7: // Delete All Files
                
                break;
                
            case 0:
                cout << "Exiting program.\n";
                return 0;
                
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
     return 0;
}
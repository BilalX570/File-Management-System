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


struct FileList {
    FileNode* head;
    FileNode* tail;
    int size;

    FileList() : head(nullptr), tail(nullptr), size(0) {}
    
    

    bool isEmpty() const {
        return head == nullptr;
    }

    int getSize() const {
        return size;
    }

    bool contains(const string& filename) const {
        FileNode* current = head;
        while (current) {
            if (current->filename == filename) return true;
            current = current->next;
        }
        return false;
    }

 void addFileAtBeginning(const string& filename, const string& content) {
        if (contains(filename)) {
            cout << "File '" << filename << "' already exists in the list.\n";
            return;
        }

        FileNode* newNode = new FileNode(filename, content);
        
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }
 
    void addFileAtEnd(const string& filename, const string& content) {
        if (contains(filename)) {
            cout << "File '" << filename << "' already exists in the list.\n";
            return;
        }

        FileNode* newNode = new FileNode(filename, content);
        
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    void addFileAtPosition(const string& filename, int position, const string& content) {
        if (position < 0 || position > size) {
            cout << "Invalid position.\n";
            return;
        }

        if (position == 0) {
            addFileAtBeginning(filename, content);
            return;
        }

        if (position == size) {
            addFileAtEnd(filename, content);
            return;
        }

        FileNode* newNode = new FileNode(filename, content);
        
        FileNode* current = head;
        for (int i = 0; i < position - 1; i++) {
            current = current->next;
        }
        
        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
        
        size++;
    }


// Get file content
    string getFileContent(const string& filename) const {
        FileNode* fileNode = getFileNode(filename);
        return fileNode ? fileNode->content : "";
    }

// Update file content and statistics
    void updateFileContent(const string& filename, const string& content) {
        FileNode* fileNode = getFileNode(filename);
        if (fileNode) {
            fileNode->content = content;
            fileNode->updateFileStats();
        }
    }

// Display file statistics
    void fileStatistics(const string& filename) {
        if (fileList.contains(filename)) {
            displayFileStats(filename);
        } else {
            cout << "File not found in managed list.\n";
        }
    }

    // Display file content from memory
    void displayFileContent(const string& filename) {
        FileNode* fileNode = fileList.getFileNode(filename);
        if (fileNode) {
            cout << "Content of " << filename << " from memory:\n";
            cout << fileNode->content;
        } else {
            cout << "File not found in memory.\n";
        }
    }


    // Search files by prefix
    void searchFilesByPrefix() {
        string prefix;
        cout << "Enter filename prefix to search: ";
        getline(cin, prefix);
        fileList.searchByPrefix(prefix);
    }
// Display file statistics
    void displayFileStats(const string& filename) {
        FileNode* fileNode = fileList.getFileNode(filename);
        if (fileNode) {
            cout << "File: " << filename << "\n";
            cout << "Type: " << fileTypeToString(fileNode->type) << "\n";
            cout << "Size: " << fileNode->size << " bytes\n";
            cout << "Last Modified: " << ctime(&fileNode->lastModified);
            int lineCount = count(fileNode->content.begin(), fileNode->content.end(), '\n');
            cout << "Lines: " << lineCount << "\n";
        } else {
            cout << "File not found in memory.\n";
        }
    }
 // Append content to a file
    void updateFile(const string& filename, const string& content) {
        if (!fileList.contains(filename)) {
            cout << "File doesn't exist. Create it first.\n";
            return;
        }

        ofstream file(filename, ios::app);
        if (file.is_open()) {
            file << content << '\n';
            cout << "Content appended to '" << filename << "' successfully.\n";
            file.close();
            
            // Update the content in our list
            string currentContent = fileList.getFileContent(filename);
            fileList.updateFileContent(filename, currentContent + content + "\n");
        } else {
            cout << "Error: Unable to open file '" << filename << "'.\n";
        }
    }

    // Overwrite file content
    void overwriteFile(const string& filename, const string& content) {
        if (!fileList.contains(filename)) {
            cout << "File doesn't exist. Create it first.\n";
            return;
        }

        ofstream file(filename);
        if (file.is_open()) {
            file << content;
            cout << "File '" << filename << "' overwritten successfully.\n";
            file.close();
            
            // Update the content in our list
            fileList.updateFileContent(filename, content);
        } else {
            cout << "Error: Unable to open file '" << filename << "'.\n";
        }
    }











































































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

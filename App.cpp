#include <bits/stdc++.h>
#include "PrisonManagerment.cpp"

using namespace std;

class App{
    private:
        PrisonManager manager;
        string fileName;

    public:
        App(string &file) : fileName(file){
            manager.loadFromFile(fileName);
        }
        void showMenu(){
            cout << "\n=== Prison Management System =====" << endl
                 << "|  " << "1. Add Prisoner" << setw(16) << "|" << endl
                 << "|  " << "2. Display All Prisoners" << setw(7) << "|" << endl
                 << "|  " << "3. Edit Prisoner by ID" << setw(9) << "|" << endl
                 << "|  " << "4. Find Prisoner by ID" << setw(9) << "|" << endl
                 << "|  " << "5. Delete Prisoner by ID" << setw(7) << "|" << endl
                 << "|  " << "6. Sort by Sentence time" << setw(7) << "|" << endl
                 << "|  " << "7. Save Data to File" << setw(11) << "|" << endl
                 << "|  " << "0. Exit" << setw(24) << "|" << endl
                 << "==================================\n";
        }
        void run(){
            int choice;
             do {
                showMenu();
                cout << "Please choose an option: ";
                cin >> choice;
                cin.ignore();
                
                switch (choice){
                    case 1: { 
                        Prisoner p = manager.inputInfo();
                        manager.addPrisoner(p);
                        cout << "Prisoner added successfully!" << endl;
                        break;
                    }
                    case 2: { 
                        manager.displayAllPrisoner();
                        break;
                    }
                    case 3: {
                        int id;
                        cout << "Enter the ID of the prisoner to edit: ";
                        cin >> id;
                        cin.ignore();
                        cout << endl;
                        manager.editPrisonerById(id);
                        break;
                    }
                    case 4: { 
                        int id;
                        cout << "Enter the ID of the prisoner to find: ";
                        cin >> id;
                        cin.ignore();
                        manager.findPrisonerById(id);
                        break;
                    }
                    
                    case 5: { 
                        int id;
                        cout << "Enter the ID of the prisoner to delete: ";
                        cin >> id;
                        cin.ignore();
                        manager.deleteById(id);
                        break;
                    }
                    case 6: { 
                        manager.sortBySentenceTime();
                        break;
                    }
                
                    case 7: {
                        manager.saveToFile(fileName);
                        cout << "Saved to file successfully\n";
                        break;
                    }
                    case 0: {
                        cout << "Exiting the program..." << endl;
                        manager.saveToFile(fileName);
                        break;
                    }
                    default:
                        cout << "Invalid choice! Please try again." << endl;
                        break;
                }
            } while (choice != 0);
        }
};
#include <bits/stdc++.h>
#include "Prisoner.cpp"

using namespace std;

class PrisonManager{
    private:
        vector<Prisoner> prisonerList;
        int numPrison;
    public:

        void loadFromFile(string &fileName){
            ifstream file(fileName);
            if(!file.is_open()){
                cout << "Can not open this file!" << endl;
                return;
            }
            int prisonId;
            string name, gender, birthDate, address, crime, prisonEntryDate; 
            int sentenceTime;

            while(file >> prisonId){
                file.ignore();
                getline(file, name);
                file >> gender;
                file >> birthDate;
                file.ignore();
                getline(file, address);
                getline(file, crime);
                file >> prisonEntryDate;
                file >> sentenceTime;
                file.ignore(); 

                Prisoner prisoner(prisonId, name, gender, birthDate,  address, crime, prisonEntryDate,sentenceTime);
                prisonerList.push_back(prisoner);
                numPrison++;
            }
            file.close();
        }

        void addPrisoner(Prisoner &prisoner){
            prisonerList.push_back(prisoner);
            numPrison++;
        }

        
        Prisoner inputInfo(){
            Prisoner newPrisoner;
            cout << "Enter prisoner information: \n";
            cin >> newPrisoner;
            return newPrisoner;
        }

        void editPrisonerById(int prisonerId) {
            for (auto &prisoner : prisonerList) {
                if (prisoner.getId() == prisonerId) {
                    cout << "~What's infomation you want to update ?~" << endl;
                    cout << "1. Name\n2. Gender\n3. Birth Date\n4. Address\n5. Crime\n6. Prison Entry Date\n7. Sentence Time" << endl;
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~\n";
                    cout << "Pls choose: ";

                    int choice;
                    cin >> choice;
                    cin.ignore();

                    switch (choice) {
                        case 1: {
                            string newName;
                            cout << "Enter the new name: ";
                            getline(cin, newName);
                            prisoner.setName(newName);
                            break;
                        }
                        case 2: {
                            string newGender;
                            cout << "Enter the new gender: ";
                            getline(cin, newGender);
                            prisoner.setGender(newGender);
                            break;
                        }
                        case 3: {
                            string newBirthDate;
                            cout << "Enter the new birth date (YYYY-MM-DD): ";
                            getline(cin, newBirthDate);
                            prisoner.setBirth(newBirthDate);
                            break;
                        }
                        case 4: {
                            string newAddress;
                            cout << "Enter the new address: ";
                            getline(cin, newAddress);
                            prisoner.setAddress(newAddress);
                            break;
                        }
                        case 5: {
                            string newCrime;
                            cout << "Enter the new crime: ";
                            getline(cin, newCrime);
                            prisoner.setCrime(newCrime);
                            break;
                        }
                        case 6: {
                            string newPrisonEntryDate;
                            cout << "Enter the new prison entry date (YYYY-MM-DD): ";
                            getline(cin, newPrisonEntryDate);
                            prisoner.setEntryDate(newPrisonEntryDate);
                            break;
                        }
                        case 7: {
                            int newSentenceTime;
                            cout << "Enter the new sentence time (in months): ";
                            cin >> newSentenceTime;
                            prisoner.setSentenceTime(newSentenceTime);
                            break;
                        }
                        default:
                            cout << "Invalid choice!" << endl;
                            break;
                    }
                    cout << "Information updated successfully!" << endl;
                    return;
                }
            }
            cout << "Prisoner with ID " << prisonerId << " not found." << endl;
        }   

        void findPrisonerById(int prisonerId){
            for(auto &prisoner : prisonerList){
                if(prisoner.getId() == prisonerId){
                    cout << prisoner;
                    return;
                }
            }
            cout << "Prisoner with ID " << prisonerId << " not found." << endl;
        }

        void deleteById(int prisonerId){
            for (auto it = prisonerList.begin(); it != prisonerList.end(); ++it) {
            if (it->getId() == prisonerId) {
                prisonerList.erase(it);
                numPrison--;
                cout << "Prisoner with ID " << prisonerId << " has been deleted." << endl;
                return;
            }
        }
        cout << "Prisoner with ID " << prisonerId << " not found." << endl;
        }   

        void displayAllPrisoner(){
            if(prisonerList.empty()){
                cout << "No prisoner found. " << endl;
                return;
            }
            cout << "List all prisoner: " << endl;
            for(auto &prisoner: prisonerList){
                cout << prisoner;
                cout << endl;
            }
        }


        void sortBySentenceTime(){
            sort(prisonerList.begin(), prisonerList.end());  // dung sort va toan tu < 
            cout << "Prisoners sorted by sentence time successfully." << endl;
        }

        void saveToFile(string &fileName){
            ofstream file(fileName);
            if(!file.is_open()){
                cout << "Cannot open the file to save!! " << endl;
                return;
            }

            for(auto &prisoner : prisonerList){
                file << prisoner.getId() << "\n"
                     << prisoner.getName() << "\n"
                     << prisoner.getGender() << "\n"
                     << prisoner.getBirth() << "\n"
                     << prisoner.getAddress() << "\n"
                     << prisoner.getCrime() << "\n"
                     << prisoner.getEntryDate() << "\n"
                     << prisoner.getSentenceTime() << "\n";
            }
            file.close();
        }


};
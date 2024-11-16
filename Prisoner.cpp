#include <bits/stdc++.h>
using namespace std;

class Prisoner{
    private:
        int prisonId;
        string name;
        string gender;
        string birthDate;
        string address;
        string crime; 
        string prisonEntryDate; //ngay vao tu
        int sentenceTime; //thoi gian thu an
        
    public:
        Prisoner(){}
        Prisoner(int prisonId, string &name, string &gender, string &birthDate, string &address, string &crime, string &prisonEntryDate, int sentenceTime) 
            : prisonId(prisonId), name(name), gender(gender), birthDate(birthDate), address(address), crime(crime), prisonEntryDate(prisonEntryDate), sentenceTime(sentenceTime) {}
        
        //getter
        int getId(){ return prisonId; }
        string getName(){ return name; }
        string getGender(){ return gender; }
        string getBirth(){ return birthDate; }
        string getAddress(){ return address; }
        string getCrime(){ return crime; }
        string getEntryDate(){ return prisonEntryDate; }
        int getSentenceTime(){ return sentenceTime; }

        //setter
        void setId(int id){ this->prisonId = id; }
        void setName(string &name){ this->name = name; }
        void setGender(string &gender) { this->gender = gender; }
        void setBirth(string &birthDate) { this->birthDate = birthDate; }
        void setAddress(string &address) { this->address = address; }
        void setCrime(string &crime) { this->crime = crime; }
        void setEntryDate(string &prisonEntryDate) { this->prisonEntryDate = prisonEntryDate; }
        void setSentenceTime(int sentenceTime) { this->sentenceTime = sentenceTime; }

        
        friend istream &operator >>(istream &is, Prisoner &p){
            cout << "Enter Prisoner ID: ";
            is >> p.prisonId;
            cout << "Enter Name: ";
            is.ignore();
            getline(is, p.name);
            cout << "Enter Gender(male/female): ";
            getline(is, p.gender);
            cout << "Enter Birth Date (YYYY-MM-DD): ";
            getline(is, p.birthDate);
            cout << "Enter Address: ";
            getline(is, p.address);
            cout << "Enter Crime: ";
            getline(is, p.crime);
            cout << "Enter Entry Date (YYYY-MM-DD): ";
            getline(is, p.prisonEntryDate);
            cout << "Enter Sentence Time (months): ";
            is >> p.sentenceTime;
            return is;
        }


        friend ostream &operator <<(ostream &os, Prisoner &p){
            os << "~~~~INFOMATION~~~~~~~~~~~~~~~" << "\n"
                 << "ID: "  << p.prisonId << "\n"
                 << "Name: "  << p.name << "\n"
                 << "Gender: "  << p.gender << "\n"
                 << "Birth Date: " << p.birthDate << "\n"
                 << "Address: " << p.address << "\n"
                 << "Crime: " << p.crime << "\n"
                 << "Entry date: " << p.prisonEntryDate << "\n"
                 << "Sentence Time: " << p.sentenceTime << " months\n";
            return os;
        }

        bool operator <(Prisoner &other){
            return sentenceTime < other.sentenceTime;
        }
        

};
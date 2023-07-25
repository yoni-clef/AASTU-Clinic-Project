#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
using namespace std;

//since contacts have its own details we chose to define another structure
struct contact{
string phoneNum;
string subCity;
string city;
string emergencyContactName;
string emergencyContactPhone;
};
//since we might want to use the personal details in other places let's define a structure to store them.
struct personalDetails{
string name;
string dateOfBirth;
int age;
int height;
int weight;
char sex;
};
//here we defined a structure to store the important informations of the patient;
struct medicalRecord{
personalDetails patient;
contact addressInfo;
string medicalRecordNum;
string medicalHistory;
string dateOfRegistration;
};
//this structure is defined to helps us store appointment details
struct appointmentRequest{
personalDetails patient;
contact addressOf;
string medicalRecordNum;
string appointmentDate;
string appointmentTime;
string department;
string procedure;
};


//We declared a global variable numOfPatient to use it in multiple places

int numOfPatient=0;
int numOfApp=0;

//we declared a global structure so as to use it in all functions

medicalRecord patient[100];
appointmentRequest meeting[100];

//None of the functions has parameters as the author of the famous book "Clean Code" Robert Cecil says "The best functions are those without Parameters."
void menu();
void getRecord();
void Search();
void displayRecord();
void setAppointment();
void displayAppointments();
void storeRecord();
void storeAppointment();

int main() {

menu();


return 0;

}

//this function is the only function we are going to call in the main functions so using switch we are going to call the other functions
//...inside this function

void menu(){
    int choice;
    label:
    cout<<"\n----AASTU Student Clinic Menu----\n\n 1.Add patient record\n 2.Display Patient record \n 3.Search \n "
        <<"4.Add appointment\n 5.Available appointments\n 6.Exit\n";
    cout<<"\nEnter your choice: ";
    cin>>choice;
    switch(choice){
    case 1: getRecord();
            goto label;
            break;
    case 2: displayRecord();
            goto label;
            break;
    case 3: Search();
            goto label;
            break;
    case 4: setAppointment();
            goto label;
            break;
    case 5: displayAppointments();
            goto label;
    case 6: exit(0);
    }
}
void getRecord(){
    system("cls");
    int currentSize;
    cout<<"\nEnter the number of patient records you want to add:";
    cin>>currentSize;
    for(int i=numOfPatient;i<(currentSize+numOfPatient);++i){
            cin.ignore();
            cout<<"\nEnter the name of the patient: ";
            getline(cin,patient[i].patient.name);
            cout<<"Enter the birth date of the patient: ";
            getline(cin,patient[i].patient.dateOfBirth);
            cout<<"Enter the age of the patient: ";
            cin>>patient[i].patient.age;
            cout<<"Enter the Sex (M/F) of the patient: ";
            cin>>patient[i].patient.sex;
            cout<<"Enter the height of the patient: ";
            cin>>patient[i].patient.height;
            cout<<"Enter the weight of the patient: ";
            cin>>patient[i].patient.weight;
            cout<<"Enter the phone number of the patient: ";
            cin.ignore();
            getline(cin,patient[i].addressInfo.phoneNum);
            cout<<"Enter the Sub-City where the Patient lives: ";
            getline(cin,patient[i].addressInfo.subCity);
            cout<<"Enter the city where the patient currently lives: ";
            getline(cin,patient[i].addressInfo.city);
            cout<<"Enter the name of Emergency contact name: ";
            getline(cin,patient[i].addressInfo.emergencyContactName);
            cout<<"Enter the phone number of Emergency contact:";
            getline(cin,patient[i].addressInfo.emergencyContactPhone);
            cout<<"Enter the medical record number for the patient: ";
            getline(cin,patient[i].medicalRecordNum);
            cout<<"Enter a brief medical history for the patient: ";
            getline(cin,patient[i].medicalHistory);
            cout<<"Enter the date of registration: ";
            getline(cin,patient[i].dateOfRegistration);
            system("cls");

    }

    numOfPatient+=currentSize;
    storeRecord();
}
//We made this function to enable storing what we have accepted from the user in the console in an outside word file so even after closing/exiting
//...the console we can still find the record in the patient.doc file
void storeRecord(){
ofstream fout;
fout.open("Patient.doc");
        fout<<"\n----AASTU Clinic Patient Record------\n";
for(int i=0;i<numOfPatient;++i){
        fout<<"\n\t\t\tDate of Registration:"<<patient[i].dateOfRegistration<<"\n\nName: "<<patient[i].patient.name<<"\tDate of Birth: "
        <<patient[i].patient.dateOfBirth;
        fout<<"\nAge: "<<patient[i].patient.age<<"\tSex: "<<patient[i].patient.sex<<"\tHeight: "<<patient[i].patient.height<<"\tWeight: "
        <<patient[i].patient.weight;
        fout<<"\nMedical Record Number: "<<patient[i].medicalRecordNum<<"\n\nPatient contact\n\n"<<"Phone Number: "<<patient[i].addressInfo.phoneNum;
        fout<<"\nSub-city: "<<patient[i].addressInfo.subCity<<"\nCity:"<<patient[i].addressInfo.city<<"\n\nEmergency contact\n\nName: ";
        fout<<patient[i].addressInfo.emergencyContactName<<"\nPhone Number: "<<patient[i].addressInfo.emergencyContactPhone;
        fout<<"\n\nGeneral Medical History:\n\n"<<patient[i].medicalHistory<<endl;
    }
fout.close();
}
void displayRecord(){
    system("cls");
    if(numOfPatient==0)
        cout<<"\nCurrently There are No Patient Records to Display!"<<endl;
        else{
    cout<<"\n----AASTU Clinic Patient Records------\n";
    for(int i=0;i<numOfPatient;++i){
        cout<<"\n\t\t\tDate of Registration:"<<patient[i].dateOfRegistration<<"\n\nName: "<<patient[i].patient.name<<"\tDate of Birth: "
        <<patient[i].patient.dateOfBirth;
        cout<<"\nAge: "<<patient[i].patient.age<<"\tSex: "<<patient[i].patient.sex<<"\tHeight: "<<patient[i].patient.height<<"\tWeight: "
        <<patient[i].patient.weight;
        cout<<"\nMedical Record Number: "<<patient[i].medicalRecordNum<<"\n\nPatient contact\n\n"<<"Phone Number: "<<patient[i].addressInfo.phoneNum;
        cout<<"\nSub-city: "<<patient[i].addressInfo.subCity<<"\nCity:"<<patient[i].addressInfo.city<<"\n\nEmergency contact\n\nName: ";
        cout<<patient[i].addressInfo.emergencyContactName<<"\nPhone Number: "<<patient[i].addressInfo.emergencyContactPhone;
        cout<<"\n\nGeneral Medical History:\n\n"<<patient[i].medicalHistory<<endl;
    }
        }


}
void Search(){
    system("cls");
    int searchChoice;
    choice:
    cout<<"  --Search--\n 1.Search by Name\n 2.Search by Medical Record Number";
    cout<<"\nHow do you want to search: ";
    cin>>searchChoice;
    if(numOfPatient==0)
        cout<<"\nCurrently There are No Patient Records to Search from!"<<endl;
       else{
    switch(searchChoice){
    case 1: {
            string searchKey;
            cout<<"\nEnter Search key:";
            cin.ignore();
            getline(cin,searchKey);
            for(int i=0;i<numOfPatient;++i){
            if(patient[i].patient.name.rfind(searchKey,0)==0){
                cout<<"\n----AASTU Clinic Patient Record------\n";
                cout<<"\n\t\t\tDate of Registration:"<<patient[i].dateOfRegistration<<"\n\nName: "<<patient[i].patient.name<<"\tDate of Birth: "
                <<patient[i].patient.dateOfBirth;
                cout<<"\nAge: "<<patient[i].patient.age<<"\tSex: "<<patient[i].patient.sex<<"\tHeight: "<<patient[i].patient.height<<"\tWeight: "
                <<patient[i].patient.weight;
                cout<<"\nMedical Record Number: "<<patient[i].medicalRecordNum<<"\n\nPatient contact\n\n"<<"Phone Number: "
                <<patient[i].addressInfo.phoneNum;
                cout<<"\nSub-city: "<<patient[i].addressInfo.subCity<<"\nCity:"<<patient[i].addressInfo.city<<"\n\nEmergency contact\n\nName: ";
                cout<<patient[i].addressInfo.emergencyContactName<<"\nPhone Number: "<<patient[i].addressInfo.emergencyContactPhone;
                cout<<"\n\nGeneral Medical History:\n\n"<<patient[i].medicalHistory<<endl;
                }
             else{
                    cout<<"Sorry! There is no Patient Record with that Name."<<endl;
                    goto choice;
             }
            }
            break;
    }
    case 2: {
            string Key;
            cout<<"Enter Search key: ";
            cin.ignore();
            getline(cin,Key);
            for(int i=0;i<numOfPatient;++i){
                if(patient[i].medicalRecordNum.rfind(Key,0)==0){
                  cout<<"\n----AASTU Clinic Patient Record------\n";
                  cout<<"\n\t\t\tDate of Registration:"<<patient[i].dateOfRegistration<<"\n\nName: "<<patient[i].patient.name<<"\tDate of Birth: "
                  <<patient[i].patient.dateOfBirth;
                  cout<<"\nAge: "<<patient[i].patient.age<<"\tSex: "<<patient[i].patient.sex<<"\tHeight: "<<patient[i].patient.height<<"\tWeight: "
                  <<patient[i].patient.weight;
                  cout<<"\nMedical Record Number: "<<patient[i].medicalRecordNum<<"\n\nPatient contact\n\n"<<"Phone Number: "
                  <<patient[i].addressInfo.phoneNum;
                  cout<<"\nSub-city: "<<patient[i].addressInfo.subCity<<"\nCity:"<<patient[i].addressInfo.city<<"\n\nEmergency contact\n\nName: ";
                  cout<<patient[i].addressInfo.emergencyContactName<<"\nPhone Number: "<<patient[i].addressInfo.emergencyContactPhone;
                  cout<<"\n\nGeneral Medical History:\n\n"<<patient[i].medicalHistory<<endl;
                }
                else{
                    cout<<"Sorry! There is no Patient Record with this Medical Record Number."<<endl;
                    goto choice;

                }
            }
            break;
    }
    default:cout<<"Invalid Choice! Please re-enter:\n";
            goto choice;

    }

       }

}
void setAppointment(){
    system("cls");
    int currentSize;
cout<<"How many appointments do you want to add:";
cin>>currentSize;
for(int i=numOfApp;i<(numOfApp+currentSize);++i){
            cin.ignore();
            cout<<"\nEnter the name of the patient: ";
            getline(cin,meeting[i].patient.name);
            cout<<"Enter the birth date of the patient: ";
            getline(cin,meeting[i].patient.dateOfBirth);
            cout<<"Enter the age of the patient: ";
            cin>>meeting[i].patient.age;
            cout<<"Enter the Sex (M/F) of the patient: ";
            cin>>meeting[i].patient.sex;
            cout<<"Enter the height of the patient: ";
            cin>>meeting[i].patient.height;
            cout<<"Enter the weight of the patient: ";
            cin>>meeting[i].patient.weight;
            cout<<"Enter the phone number of the patient: ";
            cin.ignore();
            getline(cin,meeting[i].addressOf.phoneNum);
            cout<<"Enter the Sub-City where the Patient lives: ";
            getline(cin,meeting[i].addressOf.subCity);
            cout<<"Enter the city where the patient currently lives: ";
            getline(cin,meeting[i].addressOf.city);
            cout<<"Enter the medical number of the patient:";
            getline(cin,meeting[i].medicalRecordNum);
            cout<<"Enter the department the appointment is intended for:";
            getline(cin,meeting[i].department);
            cout<<"Enter the procedure in which the appointment is intended for:";
            getline(cin,meeting[i].procedure);
            cout<<"Enter the preferred Date of appointment:";
            getline(cin,meeting[i].appointmentDate);
            cout<<"Enter the time of the appointment:";
            getline(cin,meeting[i].appointmentTime);

}
numOfApp+=currentSize;
storeAppointment();
}
void storeAppointment(){
ofstream fout;
fout.open("Patient Appointment.doc");
fout<<"---------Available Appointments--------\n";
for(int i=0;i<numOfApp;++i){
     fout<<"\n\t\t\tDate of appointment:"<<meeting[i].appointmentDate<<"\nAppointment Time:"<<meeting[i].appointmentTime<<"\n\nName: "
        <<meeting[i].patient.name<<"\tDate of Birth: "<<meeting[i].patient.dateOfBirth<<"\nAge: "<<meeting[i].patient.age<<"\tSex: "
        <<meeting[i].patient.sex<<"\tHeight: "<<meeting[i].patient.height<<"\tWeight: "<<meeting[i].patient.weight
        <<"\nMedical Record Number: "<<meeting[i].medicalRecordNum<<"\n\nPatient contact\n\n"<<"Phone Number: "<<meeting[i].addressOf.phoneNum
        <<"\nSub-city: "<<meeting[i].addressOf.subCity<<"\nCity:"<<meeting[i].addressOf.city<<"\nDepartment: "<<meeting[i].department
        <<"\nProcedure: "<<meeting[i].procedure<<endl;
}

}
void displayAppointments(){
    system("cls");
    if(numOfApp==0)
        cout<<"Currently,There are no available appointments!";
    else{
            cout<<"\n----Available Appointments-------\n";
    for(int i=0;i<numOfApp;++i){
        cout<<"\n\t\t\tDate of appointment:"<<meeting[i].appointmentDate<<"\nAppointment Time:"<<meeting[i].appointmentTime<<"\n\nName: "
        <<meeting[i].patient.name<<"\tDate of Birth: "<<meeting[i].patient.dateOfBirth<<"\nAge: "<<meeting[i].patient.age<<"\tSex: "
        <<meeting[i].patient.sex<<"\tHeight: "<<meeting[i].patient.height<<"\tWeight: "<<meeting[i].patient.weight
        <<"\nMedical Record Number: "<<meeting[i].medicalRecordNum<<"\n\nPatient contact\n\n"<<"Phone Number: "<<meeting[i].addressOf.phoneNum
        <<"\nSub-city: "<<meeting[i].addressOf.subCity<<"\nCity:"<<meeting[i].addressOf.city<<"\nDepartment: "<<meeting[i].department
        <<"\nProcedure: "<<meeting[i].procedure<<endl;
    }

    }
}


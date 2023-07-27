#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct contact {
    string phoneNum;
    string subCity;
    string city;
    string homeAddress;
    string emergencyContactName;
    string emergencyContactPhone;
};

struct personalDetails {
    string name;
    string dateOfBirth;
    int age;
    int height;
    int weight;
    char sex;
};

struct medicalRecord {
    personalDetails patient;
    contact addressInfo;
    string medicalRecordNum;
    string medicalHistory;
    string dateOfRegistration;
};

struct appointmentRequest {
    personalDetails patient;
    contact addressOf;
    string medicalRecordNum;
    string appointmentDate;
    string appointmentTime;
    string department;
    string procedure;
};

const int MAX_PATIENTS = 100;
const int MAX_APPOINTMENTS = 100;

medicalRecord patient[MAX_PATIENTS];
appointmentRequest meeting[MAX_APPOINTMENTS];
int numOfPatient = 0;
int numOfApp = 0;

// Function prototypes
void menu();
void getRecord();
void search();
void displayRecord();
void setAppointment();
void displayAppointments();
void storeRecord();
void storeAppointment();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;
    while (true) {
        cout << "\n----AASTU Student Clinic Menu----\n"
            << " 1. Add patient record\n"
            << " 2. Display Patient record\n"
            << " 3. Search\n"
            << " 4. Add appointment\n"
            << " 5. Available appointments\n"
            << " 6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            getRecord();
            break;
        case 2:
            displayRecord();
            break;
        case 3:
            search();
            break;
        case 4:
            setAppointment();
            break;
        case 5:
            displayAppointments();
            break;
        case 6:
            exit(0);
        default:
            cout << "Invalid choice! Please re-enter.\n";
        }
    }
}

void getRecord() {
    system("cls");
    int currentSize;
    cout << "\nEnter the number of patient records you want to add: ";
    cin >> currentSize;
    cin.ignore();

    for (int i = numOfPatient; i < (currentSize + numOfPatient) && i < MAX_PATIENTS; ++i) {
        cout << "\nEnter the name of the patient: ";
        getline(cin, patient[i].patient.name);
        cout << "Enter the birth date of the patient: ";
        getline(cin, patient[i].patient.dateOfBirth);
        cout << "Enter the age of the patient: ";
        cin >> patient[i].patient.age;
        cout << "Enter the Sex (M/F) of the patient: ";
        cin >> patient[i].patient.sex;
        cout << "Enter the height of the patient: ";
        cin >> patient[i].patient.height;
        cout << "Enter the weight of the patient: ";
        cin >> patient[i].patient.weight;
        cout << "Enter the phone number of the patient: ";
        cin.ignore();
        getline(cin, patient[i].addressInfo.phoneNum);
        cout << "Enter the Sub-City where the Patient lives: ";
        getline(cin, patient[i].addressInfo.subCity);
        cout << "Enter the city where the patient currently lives: ";
        getline(cin, patient[i].addressInfo.city);
        cout << "Enter the home address of the patient: ";
        getline(cin, patient[i].addressInfo.homeAddress);
        cout << "Enter the name of Emergency contact name: ";
        getline(cin, patient[i].addressInfo.emergencyContactName);
        cout << "Enter the phone number of Emergency contact: ";
        getline(cin, patient[i].addressInfo.emergencyContactPhone);
        cout << "Enter the medical record number for the patient: ";
        getline(cin, patient[i].medicalRecordNum);
        cout << "Enter a brief medical history for the patient: ";
        getline(cin, patient[i].medicalHistory);
        cout << "Enter the date of registration: ";
        getline(cin, patient[i].dateOfRegistration);
        system("cls");
    }

    numOfPatient += currentSize;
    storeRecord();
}

void storeRecord() {
    ofstream fout;
    fout.open("PatientRecords.doc");
    fout << "------AASTU Clinic Patient Records------\n";
    for (int i = 0; i < numOfPatient; ++i) {
        fout << "\n\t\t\tDate of Registration: " << patient[i].dateOfRegistration
            << "\n\nName: " << patient[i].patient.name << "\tDate of Birth: " << patient[i].patient.dateOfBirth
            << "\nAge: " << patient[i].patient.age << "\tSex: " << patient[i].patient.sex
            << "\tHeight: " << patient[i].patient.height << "\tWeight: " << patient[i].patient.weight
            << "\nMedical Record Number: " << patient[i].medicalRecordNum
            << "\n\nPatient contact\n\n" << "Phone Number: " << patient[i].addressInfo.phoneNum
            << "\nSub-city: " << patient[i].addressInfo.subCity << "\nCity: " << patient[i].addressInfo.city
            << "\nHome Address: " << patient[i].addressInfo.homeAddress
            << "\n\nEmergency contact\n\nName: " << patient[i].addressInfo.emergencyContactName
            << "\nPhone Number: " << patient[i].addressInfo.emergencyContactPhone
            << "\n\nGeneral Medical History:\n\n" << patient[i].medicalHistory << endl;
    }
    fout.close();
}
// Function to display patient records
void displayRecord() {
    system("cls");
    if (numOfPatient == 0) {
        cout << "\nCurrently, There are No Patient Records to Display!" << endl;
    }
    else {
        cout << "\n------AASTU Clinic Patient Records------\n";
        for (int i = 0; i < numOfPatient; ++i) {
            cout << "\n\t\t\tDate of Registration: " << patient[i].dateOfRegistration
                << "\n\nName: " << patient[i].patient.name << "\tDate of Birth: " << patient[i].patient.dateOfBirth
                << "\nAge: " << patient[i].patient.age << "\tSex: " << patient[i].patient.sex
                << "\tHeight: " << patient[i].patient.height << "\tWeight: " << patient[i].patient.weight
                << "\nMedical Record Number: " << patient[i].medicalRecordNum
                << "\n\nPatient contact\n\n" << "Phone Number: " << patient[i].addressInfo.phoneNum
                << "\nSub-city: " << patient[i].addressInfo.subCity << "\nCity: " << patient[i].addressInfo.city
                << "\nHome Address: " << patient[i].addressInfo.homeAddress
                << "\n\nEmergency contact\n\nName: " << patient[i].addressInfo.emergencyContactName
                << "\nPhone Number: " << patient[i].addressInfo.emergencyContactPhone
                << "\n\nGeneral Medical History:\n\n" << patient[i].medicalHistory << endl;
        }
    }
}

// Function to search for patient records
void search() {
    system("cls");
    int searchChoice;
choice:
    cout << "  --Search--\n 1. Search by Name\n 2. Search by Medical Record Number\n";
    cout << "How do you want to search: ";
    cin >> searchChoice;
    if (numOfPatient == 0) {
        cout << "\nCurrently, There are No Patient Records to Search from!" << endl;
    }
    else {
        switch (searchChoice) {
        case 1: {
            string searchKey;
            cout << "\nEnter Search key: ";
            cin.ignore();
            getline(cin, searchKey);
            for (int i = 0; i < numOfPatient; ++i) {
                if (patient[i].patient.name.rfind(searchKey, 0) == 0) {
                    cout << "\n------AASTU Clinic Patient Record------\n";
                    cout << "\n\t\t\tDate of Registration: " << patient[i].dateOfRegistration
                        << "\n\nName: " << patient[i].patient.name << "\tDate of Birth: " << patient[i].patient.dateOfBirth
                        << "\nAge: " << patient[i].patient.age << "\tSex: " << patient[i].patient.sex
                        << "\tHeight: " << patient[i].patient.height << "\tWeight: " << patient[i].patient.weight
                        << "\nMedical Record Number: " << patient[i].medicalRecordNum
                        << "\n\nPatient contact\n\n" << "Phone Number: " << patient[i].addressInfo.phoneNum
                        << "\nSub-city: " << patient[i].addressInfo.subCity << "\nCity: " << patient[i].addressInfo.city
                        << "\nHome Address: " << patient[i].addressInfo.homeAddress
                        << "\n\nEmergency contact\n\nName: " << patient[i].addressInfo.emergencyContactName
                        << "\nPhone Number: " << patient[i].addressInfo.emergencyContactPhone
                        << "\n\nGeneral Medical History:\n\n" << patient[i].medicalHistory << endl;
                }
            }
            break;
        }
        case 2: {
            string Key;
            cout << "Enter Search key: ";
            cin.ignore();
            getline(cin, Key);
            for (int i = 0; i < numOfPatient; ++i) {
                if (patient[i].medicalRecordNum.rfind(Key, 0) == 0) {
                    cout << "\n------AASTU Clinic Patient Record------\n";
                    cout << "\n\t\t\tDate of Registration: " << patient[i].dateOfRegistration
                        << "\n\nName: " << patient[i].patient.name << "\tDate of Birth: " << patient[i].patient.dateOfBirth
                        << "\nAge: " << patient[i].patient.age << "\tSex: " << patient[i].patient.sex
                        << "\tHeight: " << patient[i].patient.height << "\tWeight: " << patient[i].patient.weight
                        << "\nMedical Record Number: " << patient[i].medicalRecordNum
                        << "\n\nPatient contact\n\n" << "Phone Number: " << patient[i].addressInfo.phoneNum
                        << "\nSub-city: " << patient[i].addressInfo.subCity << "\nCity: " << patient[i].addressInfo.city
                        << "\nHome Address: " << patient[i].addressInfo.homeAddress
                        << "\n\nEmergency contact\n\nName: " << patient[i].addressInfo.emergencyContactName
                        << "\nPhone Number: " << patient[i].addressInfo.emergencyContactPhone
                        << "\n\nGeneral Medical History:\n\n" << patient[i].medicalHistory << endl;
                }
            }
            break;
        }
        default:
            cout << "Invalid Choice! Please re-enter:\n";
            goto choice;
        }
    }
}

// Function to set an appointment
void setAppointment() {
    system("cls");
    int currentSize;
    cout << "How many appointments do you want to add: ";
    cin >> currentSize;
    cin.ignore();
    for (int i = numOfApp; i < (numOfApp + currentSize) && i < MAX_APPOINTMENTS; ++i) {
        cout << "\nEnter the name of the patient: ";
        getline(cin, meeting[i].patient.name);
        cout << "Enter the birth date of the patient: ";
        getline(cin, meeting[i].patient.dateOfBirth);
        cout << "Enter the age of the patient: ";
        cin >> meeting[i].patient.age;
        cout << "Enter the Sex (M/F) of the patient: ";
        cin >> meeting[i].patient.sex;
        cout << "Enter the height of the patient: ";
        cin >> meeting[i].patient.height;
        cout << "Enter the weight of the patient: ";
        cin >> meeting[i].patient.weight;
        cout << "Enter the phone number of the patient: ";
        cin.ignore();
        getline(cin, meeting[i].addressOf.phoneNum);
        cout << "Enter the Sub-City where the Patient lives: ";
        getline(cin, meeting[i].addressOf.subCity);
        cout << "Enter the city where the patient currently lives: ";
        getline(cin, meeting[i].addressOf.city);
        cout << "Enter the home address of the patient: ";
        getline(cin, meeting[i].addressOf.homeAddress);
        cout << "Enter the medical number of the patient: ";
        getline(cin, meeting[i].medicalRecordNum);
        cout << "Enter the department the appointment is intended for: ";
        getline(cin, meeting[i].department);
        cout << "Enter the procedure in which the appointment is intended for: ";
        getline(cin, meeting[i].procedure);
        cout << "Enter the preferred Date of appointment: ";
        getline(cin, meeting[i].appointmentDate);
        cout << "Enter the time of the appointment: ";
        getline(cin, meeting[i].appointmentTime);
        system("cls");
    }
    numOfApp += currentSize;
    storeAppointment();
}

// Function to store appointments in a file
void storeAppointment() {
    ofstream fout;
    fout.open("PatientAppointments.doc");
    fout << "---------Available Appointments--------\n";
    for (int i = 0; i < numOfApp; ++i) {
        fout << "\n\t\t\tDate of appointment: " << meeting[i].appointmentDate
            << "\n\t\t\tAppointment Time: " << meeting[i].appointmentTime
            << "\n\nName: " << meeting[i].patient.name << "\tDate of Birth: " << meeting[i].patient.dateOfBirth
            << "\nAge: " << meeting[i].patient.age << "\tSex: " << meeting[i].patient.sex
            << "\tHeight: " << meeting[i].patient.height << "\tWeight: " << meeting[i].patient.weight
            << "\nMedical Record Number: " << meeting[i].medicalRecordNum
            << "\n\nPatient contact\n\n" << "Phone Number: " << meeting[i].addressOf.phoneNum
            << "\nSub-city: " << meeting[i].addressOf.subCity << "\nCity: " << meeting[i].addressOf.city
            << "\nHome Address: " << meeting[i].addressOf.homeAddress
            << "\n\nDepartment: " << meeting[i].department << "\nProcedure: " << meeting[i].procedure << endl;
    }
    fout.close();
}

// Function to display appointments
void displayAppointments() {
    system("cls");
    if (numOfApp == 0) {
        cout << "Currently, There are no available appointments!" << endl;
    }
    else {
        cout << "\n----Available Appointments-------\n";
        for (int i = 0; i < numOfApp; ++i) {
            cout << "\n\t\t\tDate of appointment: " << meeting[i].appointmentDate
                << "\n\t\t\tAppointment Time: " << meeting[i].appointmentTime
                << "\n\nName: " << meeting[i].patient.name << "\tDate of Birth: " << meeting[i].patient.dateOfBirth
                << "\nAge: " << meeting[i].patient.age << "\tSex: " << meeting[i].patient.sex
                << "\tHeight: " << meeting[i].patient.height << "\tWeight: " << meeting[i].patient.weight
                << "\nMedical Record Number: " << meeting[i].medicalRecordNum
                << "\n\nPatient contact\n\n" << "Phone Number: " << meeting[i].addressOf.phoneNum
                << "\nSub-city: " << meeting[i].addressOf.subCity << "\nCity: " << meeting[i].addressOf.city
                << "\nHome Address: " << meeting[i].addressOf.homeAddress
                << "\n\nDepartment: " << meeting[i].department << "\nProcedure: " << meeting[i].procedure << endl;
        }
    }
}
void getRecord(){
    system("cls");
    int currentSize;
    cout<<"\nEnter the number of patient records you want to add:";
    cin>>currentSize;
            cin.ignore();
    for(int i=numOfPatient;i<(currentSize+numOfPatient);++i){
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
            cout<<"Enter the home address of the patient: ";
            getline(cin,patient[i].addressInfo.homeAddress);
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

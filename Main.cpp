#include <windows.h>
#include<iostream>
#include<string>
#include<fstream>
#include"Header.h"
#include <chrono>
#include <ctime>
#include <string>
#include <sstream>
#include <conio.h>
#include<vector>
#include<iomanip>
#include <thread>
#include <limits>





using namespace std;
#ifdef max
#undef max
#endif


struct UserCredentials {
    string username;
    string password;
};

bool Signin(const vector<UserCredentials>& userCredentials, const string& username, const string& password) {
    for (const auto& credentials : userCredentials) {
        if (credentials.username == username && credentials.password == password) {
            return true;
        }
    }
    return false;
}

int main()
{

    srand(time(0));
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);				// maximize screen 
    Logo();
    vector<UserCredentials> userCredentials;

    // Read user credentials from file
    ifstream fin("Admin.txt");
    if (!fin) {
        cout << "Error opening file: Admin.txt" << endl;
        return 1;
    }

    string username, password;
    while (fin >> username >> password) {
        userCredentials.push_back({ username, password });
    }
    fin.close();

    // Prompt for login
    cout << "Please Enter Your Username and Password to Login" << endl;
    string inputUsername, inputPassword;
    bool loginSuccess = false;

    while (!loginSuccess) {
        cout << "Enter your username: ";
        cin >> inputUsername;

        cout << "Enter your password: ";
        inputPassword.clear(); // Clear the input password
        char ch;
        while ((ch = _getch()) != '\r') { // Read characters until Enter is pressed
            if (ch != '\b') { // If not Backspace
                inputPassword.push_back(ch); // Append character to password
                cout << '*'; // Print asterisk
            }
            else if (!inputPassword.empty()) { // If Backspace and password not empty
                inputPassword.pop_back(); // Remove last character from password
                cout << "\b \b"; // Move cursor back, erase character, move cursor back again
            }
        }
        cout << endl; // Move to the next line

        // Check if username and password match
        loginSuccess = Signin(userCredentials, inputUsername, inputPassword);

        if (loginSuccess) {
            cout << "Login Successful.." << endl;
            system("pause");
            system("cls");
        }
        else {
            system("cls");
        }
    }

    while (true)
    {
        Person person;

        cout << "Welcome to Marquee Management System" << endl;
        cout << "Press 1 - Add A Booking" << endl;
        cout << "Press 2 - Edit A Booking" << endl;
        cout << "Press 3 - Cancel A Booking" << endl;
        cout << "Press 4 - Check Availability" << endl;
        cout << "Press 5 - Quit " << endl;
        cout << "Press 6 - Credits" << endl;

        int choice;
        cout << "Enter your Choice: ";
        cin >> choice;

        if (!int()) {
			cout << "Invalid input - Enter A Number" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("cls");
		}
        system("cls");

        if (choice == 1)
        {
            ifstream lastDateFile("lastDate.txt");
            string lastDate;
            if (lastDateFile.is_open())
            {
                getline(lastDateFile, lastDate);
                lastDateFile.close();
            }

            cout << "-----Booking-----" << endl;
            person.get_name();
            cout << "Enter Name of Customer: ";
            string name;
            cin.clear();
           // cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            getline(cin, name);
            person.set_name(name);
            person.get_phone_num();
            cout << "Enter Phone Number of Customer: ";
            string phone_num;
            cin >> phone_num;
            person.set_phone_num(phone_num);

            cout << "Number Of Functions of " << name << ": " << endl;
            int choice2;
            cin >> choice2;
            for (int i = 1; i <= choice2; i++)
            {
                string eventName;
                cout << "Event " << i << " Name (Mehndi, Barat, Walima, Other) : " << endl;
                cin >> eventName;
                cout << "Input Details of " << eventName << endl;
                cout << endl;
                cout << "------" << eventName << "------" << endl;
                
                string dateString = person.bookingDate();
                int numPeople = person.numberOfPeople();
                string functionTime = "";
                functionTime = person.timeOfDay();
                string controller = person.userBookingName();
             //   person.sortEvents();
                person.displayBookingDetails(dateString, functionTime, numPeople, controller, eventName);
                cout << "Event " << i << " Done!" << endl;
                cout << endl;
            }
            cout << "Booking Complete!" << endl;
        }
        else if (choice == 2)
        {
            cout << "-----Edit A Booking-----" << endl;
            string date;
            person.editBooking();

        }
        else if (choice == 3)
        {
            cout << "-----Cancel A Booking-----" << endl;
            person.cancelBooking();
        }

        else if (choice == 4)
        {
            cout << "-----Check Availability-----" << endl;
            person.checkAvailability();


        }


        else if (choice == 5) 
        {
            cout << "-----Thanks For Using My Software-----" << endl;
            break;
            return 1;
        }
        else if (choice == 6)
        {
            cout << "----Credits:-----" << endl;
            cout << "\n\n\t\tDeveloped by : Ahmad Tayyab\n\n\n";
        }
        else 
        {

            cout << "Invalid Choice / Invalid Input. Please Input a Number" << endl;
        }

        system("pause");
        system("cls");
    }
    

    return 0;
}
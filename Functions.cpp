#include"Header.h"
#include <Windows.h>
#include<iostream>
#include <limits>
#include<fstream>
#include <chrono>
#include <ctime>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include<iomanip>
#include <thread>
#include <conio.h>



HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);  // FOR COLORING


using namespace std;
#ifdef max
#undef max
#endif

void Logo()
{


	system("Cls");		// Clear screen
	cout << "\n\n";
	system("Color 09");

	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

	cout << "\t\t\t   __  __    ___    _____   _____   _   _   _____   _____ " << endl;
	this_thread::sleep_for(chrono::milliseconds(150));
	cout << "\t\t\t  |  \\/  |  / _ \\  | ___ \\ |  _  | | | | | |  ___| |  ___|" << endl;
	this_thread::sleep_for(chrono::milliseconds(150));
	cout << "\t\t\t  | .  . | / /_\\ \\ | |_/ / | | | | | | | | | |__   | |__  " << endl;
	this_thread::sleep_for(chrono::milliseconds(150));
	cout << "\t\t\t  | |\\/| | |  _  | |    /  | | | | | | | | |  __|  |  __| " << endl;
	this_thread::sleep_for(chrono::milliseconds(150));
	cout << "\t\t\t  | |  | | | | | | | |\\ \\  \\ \\/' / | |_| | | |___  | |___ " << endl;
	this_thread::sleep_for(chrono::milliseconds(150));
	cout << "\t\t\t  \\_|  |_/ \\_| |_/ \\_| \\_|  \\_/\\_\\  \\___/  \\____/  \\____/ " << endl;
	this_thread::sleep_for(chrono::milliseconds(150));

	cout << "\t\t\t   __  __    ___    _   _    ___    _____   _____   __  __   _____   _   _   _____ " << endl;
	this_thread::sleep_for(chrono::milliseconds(150));
	cout << "\t\t\t  |  \\/  |  / _ \\  | \\ | |  / _ \\  |  __ \\ |  ___| |  \\/  | |  ___| | \\ | | |_   _|" << endl;
	this_thread::sleep_for(chrono::milliseconds(150));
	cout << "\t\t\t  | .  . | / /_\\ \\ |  \\| | / /_\\ \\ | |  \\/ | |__   | .  . | | |__   |  \\| |   | |	" << endl;
	this_thread::sleep_for(chrono::milliseconds(150));
	std::cout << "\t\t\t  | |\\/| | |  _  | | . ` | |  _  | | | __  |  __|  | |\\/| | |  __|  | . ` |   | |   "<< std::endl;
		
		this_thread::sleep_for(chrono::milliseconds(150));
	cout << "\t\t\t  | |  | | | | | | | |\\  | | | | | | |\\_\\ \\| |___  | |  | | | |___  | |\\  |   | |	" << endl;
	this_thread::sleep_for(chrono::milliseconds(150));
	cout << "\t\t\t  \\_|  |_/ \\_| |_/ \\_| \\_/ \\_| |_/  \\____/ \\____/  \\_|  |_/ \\____/  \\_| \\_/   \\_/	" << endl;
	this_thread::sleep_for(chrono::milliseconds(150));

	cout << "\t\t\t   _____  __   __  _____   _____   _____   __  __ " << endl;
	this_thread::sleep_for(chrono::milliseconds(150));
	cout << "\t\t\t  /  ___| \\ \\ / / /  ___| |_   _| |  ___| |  \\/  |" << endl;
	this_thread::sleep_for(chrono::milliseconds(150));
	cout << "\t\t\t  \\ `--.   \\ V /  \\ `--.    | |   | |__   | .  . |" << endl;
	this_thread::sleep_for(chrono::milliseconds(150));
	cout << "\t\t\t   `--. \\   \\ /    `--. \\   | |   |  __|  | |\\/| |" << endl;
	this_thread::sleep_for(chrono::milliseconds(150));
	cout << "\t\t\t  /\\__/ /   | |   /\\__/ /   | |   | |___  | |  | |" << endl;
	this_thread::sleep_for(chrono::milliseconds(150));
	cout << "\t\t\t  \\____/    \\_/   \\____/    \\_/   \\____/  \\_|  |_|" << endl;
	this_thread::sleep_for(chrono::milliseconds(150));
	cout << "\n\n\n\n\n\n\n\n\n\n";

	cout<<setw(130)<<"Developed by : Ahmad Tayyab"<<endl;
	this_thread::sleep_for(chrono::milliseconds(1500));

			 Sleep(1000);
			 system("Cls");











	
}

Appointment newAppointment;

Person::Person()
{
	name = "";
	phone_num = "";
}
Person::Person(string name, string phone_num)
{
	this->name = name;
	this->phone_num = phone_num;
}
Person::~Person()
{
}
void Person::set_name(string name)
{
	this->name = name;
}
void Person::set_phone_num(string phone_num)
{
	this->phone_num = phone_num;
}
string Person::get_name()
{
	return name;
}
string Person::get_phone_num()
{
	return phone_num;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------


string Person::bookingDate()
{

	cout << "Input  of Event (DD-MM-YYYY): ";
	string dateString;
	cin.clear();
	//cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	getline(cin, dateString);
	cout << endl;
	return dateString;
	system("cls");
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------


int Person::numberOfPeople() {
	cout << "Input The Number of People: ";
	int numPeople;
	cin >> numPeople;
	cout << endl;
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return numPeople;
	system("cls");
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------
void Person::writeToFiles(const string& dateString, const string& functionTime, const int& numPeople, const string& controller, const string& eventName, const string& name, const string& phoneNumber) {
	// Write to text file
	ofstream textFile("BookingDetails.txt", ios::app);
	if (textFile.is_open()) {
		textFile << "---Booking---" << endl;
		textFile << "Event Date: " << dateString << endl;
		textFile << "Function Time: " << functionTime << endl;
		textFile << "Number Of People: " << numPeople << endl;
		textFile << "Event: " << eventName << endl;
		textFile << "Booked by: " << controller << endl;
		textFile << "Name: " << name << endl; // Store name
		textFile << "Phone Number: " << phoneNumber << endl; // Store phone number
		textFile << "---------------" << endl << endl;
		textFile.close();
	}
	else {
		cout << "Error: Unable to open text file for writing" << endl;
	}

	// Write to CSV file
	ofstream csvFile("BookingDetails.csv", ios::app);
	if (csvFile.is_open()) {
		csvFile << dateString << "," << functionTime << "," << numPeople << "," << controller << "," << eventName << "," << name << "," << phoneNumber << endl;
		csvFile.close();
	}
	else {
		cout << "Error: Unable to open CSV file for writing" << endl;
	}
}

void Person::syncTextFileFromCSV() {
	ifstream csvFile("BookingDetails.csv");
	if (!csvFile.is_open()) {
		cout << "Error: Unable to open CSV file for reading" << endl;
		return;
	}

	ofstream textFile("BookingDetails.txt");
	if (!textFile.is_open()) {
		cout << "Error: Unable to open text file for writing" << endl;
		return;
	}

	string line;
	while (getline(csvFile, line)) {
		stringstream ss(line);
		string dateString, functionTime, controller, eventName, name, phoneNumber;
		int numPeople;

		getline(ss, dateString, ',');
		getline(ss, functionTime, ',');
		ss >> numPeople;
		ss.ignore(); // Ignore the comma
		getline(ss, controller, ',');
		getline(ss, eventName, ',');
		getline(ss, name, ','); // Read name from CSV
		getline(ss, phoneNumber, ','); // Read phone number from CSV

		textFile << "---Booking---" << endl;
		textFile << "Event Date: " << dateString << endl;
		textFile << "Function Time: " << functionTime << endl;
		textFile << "Number Of People: " << numPeople << endl;
		textFile << "Event: " << eventName << endl;
		textFile << "Booked by: " << controller << endl;
		textFile << "Name: " << name << endl; // Store name
		textFile << "Phone Number: " << phoneNumber << endl; // Store phone number
		textFile << "---------------" << endl << endl;
	}

	csvFile.close();
	textFile.close();
}

string Person::convertDate(const string& date) {
	// Implementation of convertDate function
	return date.substr(6, 4) + date.substr(3, 2) + date.substr(0, 2);
}


//--------------------------------------------------------------------------------------------------------------------------------------------------------
//void Person::sortEvents() {
//	ifstream textFileIn("BookingDetails.txt");
//	if (!textFileIn.is_open()) {
//		cout << "Error: Unable to open text file for reading" << endl;
//		return;
//	}
//
//	vector<string> events;
//	string line;
//	while (getline(textFileIn, line)) {
//		if (line.find("Event Date: ") != string::npos) {
//			events.push_back(line);
//		}
//	}
//	textFileIn.close();
//
//	// Sort events vector based on dates
//	sort(events.begin(), events.end(), [&](const string& a, const string& b) {
//		return convertDate(a.substr(12, 10)) < convertDate(b.substr(12, 10));
//		});
//
//	// Write sorted events back to the text file
//	ofstream textFileOut("BookingDetails.txt");
//	if (!textFileOut.is_open()) {
//		cout << "Error: Unable to open text file for writing" << endl;
//		return;
//	}
//
//	for (const string& event : events) {
//		textFileOut << event << endl;
//	}
//	textFileOut.close();
//
//	// Update CSV file with sorted events
//	updateCSV(events);
//
//	cout << "Events sorted successfully." << endl;
//}
//
//void Person::updateCSV(const vector<string>& events) 
//{
//	// Open CSV file for writing
//	ofstream csvFile("BookingDetails.csv");
//	if (!csvFile.is_open()) 
//	{
//		cout << "Error: Unable to open CSV file for writing" << endl;
//		return;
//	}
//	for (const string& event : events) {
//		stringstream ss(event);
//		string token;
//		getline(ss, token, ','); // Skip "Event Date: "
//		getline(ss, token, ','); // Get date
//		csvFile << token << ",";
//		getline(ss, token, ','); // Skip time
//		getline(ss, token, ','); // Skip number of people
//		getline(ss, token, ','); // Skip controller
//		getline(ss, token, ','); // Get event name
//		csvFile << token << endl;
//	}
//
//	csvFile.close();
//}

//----------------------------------------------------------------------------------------------------------------------------------------------------------




//----------------------------------------------------------------------------------------------------------------------------------------------------------
void Person::displayBookingDetails(const string& dateString, const string& functionTime, const int& numPeople,const string& controller, const string& eventName)
{
	system("cls");
	string name = get_name();
	string phone_num = get_phone_num();
	cout << "----------Booking Details----------" << endl;
	cout << endl;

	cout << "Name: " << name << endl;
	cout << "Phone Number: " << phone_num << endl;
	cout << "Event Date: " << dateString << endl;
	cout << "Function Time: " << functionTime << endl;
	cout << "Number Of People: " << numPeople << endl;
	cout << "Event: " << eventName << endl; // Display the Name of Event on a separate line
	cout << "Event Booked At Time: " << getCurrentTime() << endl;

	static string lastDate; // to keep track of last booked date
	static int count = 0; // count for current date, initialized to 0


	ifstream lastDateFile("lastDate.txt");
	if (lastDateFile.is_open()) {
		getline(lastDateFile, lastDate);
		lastDateFile.close();
	}
	else {
		cout << "Error: Unable to open lastDate.txt" << endl;
	}


	// Check if the booking is for the same date as the last booking
	if (dateString != lastDate) {
		// Reset count to 0 if booking is for a new date
		lastDate = dateString;
		count = 0;
	}
	else if (dateString == lastDate)
	{
		// Increment count
		count++;
	}
	else
	{
		cout<<"Error: Unable to compare dates"<<endl;
	}

	
	

	ofstream outfile;
	outfile.open("BookingDetails.txt", ios::app);
	outfile << "---Function #" << ++count  << "---" << endl;
	outfile << "Name: " << name << endl;
	outfile << "Phone Number: " << phone_num << endl;
	outfile << "Event Date: " << dateString << endl;
	outfile << "Function Time: " << functionTime << endl;
	outfile << "Number Of People: " << numPeople << endl;
	outfile << "Event: " << eventName << endl; // Also write the Name of Event to the file
	outfile << "Event Booked At Time: " << getCurrentTime() << endl;
	outfile << "Event Booked by: " << controller << endl;
	outfile << "-----------------------------------" << endl;
	outfile << endl;
	outfile.close();

	ofstream lastDateFileOut("lastDate.txt");
	if (lastDateFileOut.is_open()) {
		lastDateFileOut << lastDate;
		lastDateFileOut.close();
	}
	else 
	{
		cout << "Error: Unable to open lastDate.txt for writing" << endl;
	}

	writeToFiles(dateString, functionTime, numPeople, controller, eventName,name,phone_num);

	// Synchronize text file with CSV file
	syncTextFileFromCSV();



	
}

	


//----------------------------------------------------------------------------------------------------------------------------------------------------------


string Person::timeOfDay() 
{
	cout << "Input The Function Timing: ";
	string FunctionTime;
	cin.clear();

	getline(cin, FunctionTime);
	cout << endl;
   // displayBookingDetails(dateString,FunctionTime,numPeople); // Pass function time to displayBookingDetails
	return FunctionTime;
	system("Cls");	
	
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------


string Person::userBookingName()
{
	cout << "Event Booked by: "<<" ";
	
	string controller;
	getline(cin, controller);
	cout << endl;
	return controller;
	system("cls");
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------

void Person::checkAvailability()
{
	cout << "----------Check Availability----------" << endl;
	cout << "Enter Date To Check Availability (DD-MM-YYYY): ";
	string dateString;
	//cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, dateString);

	ifstream infile("BookingDetails.txt");
	if (!infile)
	{
		cout << "Error opening file: BookingDetails.txt" << endl;
		return;
	}

	string line;
	int totalEvents = 0;
	bool found = false;
	while (getline(infile, line))
	{
		if (line.find("Event Date: " + dateString) != string::npos)
		{
			found = true;
			cout << "----------Booking Details----------" << endl;
			cout << "Event Date: " << dateString << endl;

			// Read the next lines containing name and phone number
			string name, phoneNum;
			getline(infile, line); // Read "Name: "
			name = line.substr(6); // Extract the name
			cout << line << endl; // Output name
			getline(infile, line); // Read "Phone Number: "
			phoneNum = line.substr(14); // Extract the phone number
			cout << line << endl; // Output phone number

			// Output the remaining event details
			for (int i = 0; i < 4; ++i)
			{
				if (!getline(infile, line))
				{
					cout << "Error: Unexpected end of file." << endl;
					return;
				}
				cout << line << endl;
			}

			++totalEvents;

			// Check if there are more events on the same date
			while (getline(infile, line))
			{
				if (line.find("Event Date: ") != string::npos)
				{
					if (line.find("Event Date: " + dateString) != string::npos)
					{
						cout << "----------Booking Details----------" << endl;
						cout << "Event Date: " << dateString << endl;

						// Output the remaining event details
						for (int i = 0; i < 4; ++i)
						{
							if (!getline(infile, line))
							{
								cout << "Error: Unexpected end of file." << endl;
								return;
							}
							cout << line << endl;
						}
						++totalEvents;
					}
					else
					{
						break; // Stop searching if a different date is encountered
					}
				}
			}
		}
	}

	if (!found)
	{
		cout << "No events found for the date: " << dateString << endl;
	}
	else
	{
		cout << "-----------------------------------" << endl;
		cout << "Total events booked for " << dateString << ": " << totalEvents << endl;
		cout << "-----------------------------------" << endl;
	}

	infile.close();
}




//
//void Person::editBooking()
//{
//	string date;
//	cout << "Enter the date of the events you want to edit (DD-MM-YYYY): ";
//	cin >> date;
//	cout << endl;
//
//	ifstream fin("BookingDetails.txt");
//	if (!fin)
//	{
//		cout << "Error opening file: BookingDetails.txt" << endl;
//		return;
//	}
//
//	string line;
//	cout << "Booked events for " << date << ":" << endl;
//	int eventCount = 0;
//	while (getline(fin, line))
//	{
//		if (line.find("Event Date: " + date) != string::npos)
//		{
//			eventCount++;
//			cout << "Event " << eventCount << ":" << endl;
//			// Display event details
//			cout << line << endl;
//			for (int i = 0; i < 6; ++i)
//			{
//				getline(fin, line);
//				cout << line << endl;
//			}
//			cout << "-----------------------------------" << endl;
//			cout << endl;
//		}
//	}
//	fin.close();
//
//	if (eventCount == 0)
//	{
//		cout << "No events found for the date: " << date << endl;
//		return;
//	}
//
//	cout << "Total events booked for " << date << ": " << eventCount << endl;
//
//	int eventIndex;
//	cout << "Enter the index of the event to edit (1-" << eventCount << "): ";
//	cin >> eventIndex;
//
//	// Reopen the file to read from the beginning
//	fin.open("BookingDetails.txt");
//
//	ofstream temp("temp.txt");
//	if (!fin || !temp)
//	{
//		cout << "Error opening files." << endl;
//		return;
//	}
//
//	int currentEventIndex = 0;
//	while (getline(fin, line))
//	{
//		if (line.find("Event Date: " + date) != string::npos)
//		{
//			currentEventIndex++;
//			if (currentEventIndex == eventIndex)
//			{
//				// Edit the selected event
//				cout << "Enter new date (DD-MM-YYYY): ";
//				string newDate;
//				cin >> newDate;
//				temp << "Event Date: " << newDate << endl;
//
//				cout << "Enter new time of event: ";
//				string newTime;
//				cin >> newTime;
//				temp << "Function Time: " << newTime << endl;
//
//				cout << "Enter new number of people: ";
//				int newNumPeople;
//				cin >> newNumPeople;
//				temp << "Number Of People: " << newNumPeople << endl;
//
//				// Skip the rest of the event details in the original file
//				for (int i = 0; i < 3; ++i)
//				{
//					getline(fin, line);
//				}
//			}
//			else
//			{
//				temp << line << endl; // Copy unchanged event details to temp file
//			}
//		}
//		else
//		{
//			temp << line << endl; // Copy non-event lines to temp file
//		}
//	}
//
//	fin.close();
//	temp.close();
//
//	// Replace the original file with the temp file
//	remove("BookingDetails.txt");
//	rename("temp.txt", "BookingDetails.txt");
//
//	// Update changes in CSV file
//	ifstream csvIn("BookingDetails.csv");
//	ofstream tempCsv("temp.csv");
//	if (!csvIn || !tempCsv)
//	{
//		cout << "Error opening CSV files." << endl;
//		return;
//	}
//
//	while (getline(csvIn, line))
//	{
//		if (line.find("Event Date: " + date) != string::npos)
//		{
//			currentEventIndex++;
//			if (currentEventIndex == eventIndex)
//			{
//				// Edit the selected event in CSV file
//				stringstream ss(line);
//				string token;
//				getline(ss, token, ','); // Skip date
//				getline(ss, token, ','); // Skip time
//				getline(ss, token, ','); // Skip number of people
//				getline(ss, token, ','); // Skip controller
//				getline(ss, token, ','); // Get event name
//
//				// Assuming newDate, newTime, and newNumPeople are updated variables
//				string newDate, newTime,eventName;
//				int newNumPeople;
//				cout << "Enter new date (DD-MM-YYYY): ";
//				cin >> newDate;
//				cout << "Enter new time of event: ";
//				cin >> newTime;
//				cout << "Enter new number of people: ";
//				cin >> newNumPeople;
//
//				tempCsv << newDate << "," << newTime << "," << newNumPeople << "," << token << "," << eventName << endl;
//			}
//			else
//			{
//				tempCsv << line << endl; // Copy unchanged event details to temp CSV file
//			}
//		}
//		else
//		{
//			tempCsv << line << endl; // Copy non-event lines to temp CSV file
//		}
//	}
//
//	csvIn.close();
//	tempCsv.close();
//
//	// Replace the original CSV file with the temp CSV file
//	remove("BookingDetails.csv");
//	rename("temp.csv", "BookingDetails.csv");
//
//	cout << "Event details updated successfully." << endl;
//}







void Person::editBooking()
{
	string date;
	cout << "Enter the date of the events you want to edit (DD-MM-YYYY): ";
	cin >> date;
	cout << endl;

	ifstream fin("BookingDetails.txt");
	if (!fin)
	{
		cout << "Error opening file: BookingDetails.txt" << endl;
		return;
	}

	string line;
	cout << "Booked events for " << date << ":" << endl;
	int eventCount = 0;
	while (getline(fin, line))
	{
		if (line.find("Event Date: " + date) != string::npos)
		{
			eventCount++;
			cout << "Event " << eventCount << ":" << endl;
			// Display event details
			cout << line << endl;
			for (int i = 0; i < 6; ++i)
			{
				getline(fin, line);
				cout << line << endl;
			}
			cout << "-----------------------------------" << endl;
			cout << endl;
		}
	}
	fin.close();

	if (eventCount == 0)
	{
		cout << "No events found for the date: " << date << endl;
		return;
	}

	cout << "Total events booked for " << date << ": " << eventCount << endl;

	int eventIndex;
	cout << "Enter the index of the event to edit (1-" << eventCount << "): ";
	cin >> eventIndex;

	// Reopen the file to read from the beginning
	fin.open("BookingDetails.txt");

	ofstream temp("temp.txt");
	if (!fin || !temp)
	{
		cout << "Error opening files." << endl;
		return;
	}

	int currentEventIndex = 0;
	while (getline(fin, line))
	{
		if (line.find("Event Date: " + date) != string::npos)
		{
			currentEventIndex++;
			if (currentEventIndex == eventIndex)
			{
				// Edit the selected event
				cout << "Enter new date (DD-MM-YYYY): ";
				string newDate;
				cin >> newDate;
				temp << "Event Date: " << newDate << endl;

				cout << "Enter new time of event: ";
				string newTime;
				cin >> newTime;
				temp << "Function Time: " << newTime << endl;

				cout << "Enter new number of people: ";
				int newNumPeople;
				cin >> newNumPeople;
				temp << "Number Of People: " << newNumPeople << endl;

				// Skip the rest of the event details in the original file
				for (int i = 0; i < 3; ++i)
				{
					getline(fin, line);
				}
			}
			else
			{
				// Copy event details to temp file until the next event or the end of file
				do
				{
					temp << line << endl;
				} while (getline(fin, line) && line.find("Event Date: ") == string::npos);
			}
		}
		else
		{
			temp << line << endl; // Copy non-event lines to temp file
		}
	}

	fin.close();
	temp.close();

	// Replace the original file with the temp file
	remove("BookingDetails.txt");
	rename("temp.txt", "BookingDetails.txt");

	// Update changes in CSV file
	ifstream csvIn("BookingDetails.csv");
	ofstream tempCsv("temp.csv");
	if (!csvIn || !tempCsv)
	{
		cout << "Error opening CSV files." << endl;
		return;
	}

	while (getline(csvIn, line))
	{
		if (line.find("Event Date: " + date) != string::npos)
		{
			currentEventIndex++;
			if (currentEventIndex == eventIndex)
			{
				// Edit the selected event in CSV file
				stringstream ss(line);
				string token;
				getline(ss, token, ','); // Skip date
				getline(ss, token, ','); // Skip time
				getline(ss, token, ','); // Skip number of people
				getline(ss, token, ','); // Skip controller
				getline(ss, token, ','); // Get event name

				// Assuming newDate, newTime, and newNumPeople are updated variables
				string newDate, newTime;
				int newNumPeople;
				cout << "Enter new date (DD-MM-YYYY): ";
				cin >> newDate;
				cout << "Enter new time of event: ";
				cin >> newTime;
				cout << "Enter new number of people: ";
				cin >> newNumPeople;

				tempCsv << newDate << "," << newTime << "," << newNumPeople << "," << token << "," << token << endl;

			}
			else
			{
				tempCsv << line << endl; // Copy unchanged event details to temp CSV file
			}
		}
		else
		{
			tempCsv << line << endl; // Copy non-event lines to temp CSV file
		}
	}

	csvIn.close();
	tempCsv.close();

	// Replace the original CSV file with the temp CSV file
	remove("BookingDetails.csv");
	rename("temp.csv", "BookingDetails.csv");

	cout << "Event details updated successfully." << endl;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------




BookingDetails readBookingDetailsFromFile(ifstream& infile) {
	BookingDetails booking;
	string line;
	while (getline(infile, line)) {
		if (line.substr(0, 12) == "---Function") {
			return booking;
		}
		else if (line.find("Name: ") == 0) {
			booking.name = line.substr(6);
		}
		else if (line.find("Phone Number: ") == 0) {
			booking.phone_num = line.substr(14);
		}
		else if (line.find("Event Date: ") == 0) {
			booking.dateString = line.substr(12);
		}
		else if (line.find("Function Time: ") == 0) {
			booking.functionTime = line.substr(15);
		}
		else if (line.find("Number Of People: ") == 0) {
			booking.numPeople = stoi(line.substr(18));
		}
		else if (line.find("Event: ") == 0) {
			booking.eventName = line.substr(7);
		}
		else if (line.find("Event Booked At Time: ") == 0) {
			booking.bookedTime = line.substr(22);
		}
		else if (line.find("Event Booked by: ") == 0) {
			booking.controller = line.substr(18);
		}
	}
	return booking;
}





void Person:: cancelBooking() {
	ifstream infile("BookingDetails.txt");
	if (!infile.is_open()) {
		cout << "Error opening file." << endl;
		return;
	}

	string dateToCancel;
	cout << "Enter the date for which you want to cancel bookings: ";
	cin >> dateToCancel;

	int index = 1;
	ofstream outfile("TempBookingDetails.txt");
	string line;
	while (getline(infile, line)) {
		if (line.find("Event Date: ") == 0) {
			string dateString = line.substr(12);
			if (dateString == dateToCancel) {
				cout << "Index: " << index++ << endl;
				cout << line << endl; // Print the date
				cout << "Name: ";
				getline(infile, line);
				cout << line << endl;
				cout << "Phone Number: ";
				getline(infile, line);
				cout << line << endl;
				cout << "Function Time: ";
				getline(infile, line);
				cout << line << endl;
				cout << "Number Of People: ";
				getline(infile, line);
				cout << line << endl;
				cout << "Event: ";
				getline(infile, line);
				cout << line << endl;
				cout << "Event Booked At Time: ";
				getline(infile, line);
				cout << line << endl;
				cout << "Event Booked by: ";
				getline(infile, line);
				cout << line << endl;
				cout << "-----------------------------------" << endl;

				cout << "Do you want to delete this booking? (y/n): ";
				char choice;
				cin >> choice;
				if (choice == 'n' || choice == 'N') {
					outfile << "Event Date: " << dateString << endl;
					outfile << "Name: ";
					outfile << line << endl;
					getline(infile, line);
					outfile << line << endl;
					getline(infile, line);
					outfile << line << endl;
					getline(infile, line);
					outfile << line << endl;
					getline(infile, line);
					outfile << line << endl;
					getline(infile, line);
					outfile << line << endl;
					getline(infile, line);
					outfile << line << endl;
					index++;
				}
				continue;
			}
		}
		outfile << line << endl;
	}

	infile.close();
	outfile.close();

	remove("BookingDetails.txt");
	rename("TempBookingDetails.txt", "BookingDetails.txt");

	ifstream csvIn("BookingDetails.csv");
	ofstream tempCsv("temp.csv");
	if (!csvIn || !tempCsv) {
		cout << "Error opening CSV files." << endl;
		return;
	}


	while (getline(csvIn, line)) {
		if (line.find(dateToCancel) != string::npos) {
			continue; // Skip the line if it matches the date to cancel
		}
		tempCsv << line << endl;
	}

	csvIn.close();
	tempCsv.close();

	remove("BookingDetails.csv");
	rename("temp.csv", "BookingDetails.csv");

	cout << "Bookings for date " << dateToCancel << " canceled successfully." << endl;
}






















//----------------------------------------------------------------------------------------------------------------------------------------------------------


string Person::getCurrentTime()
{
	
		time_t now;
		time(&now);
		char buffer[26];
		string currentTime;

		if (ctime_s(buffer, sizeof(buffer), &now) == 0) {
			currentTime = buffer;
		}
		else {
			currentTime = "Error getting current time";
		}

		return currentTime;
		system("cls");
	}


//----------------------------------------------------------------------------------------------------------------------------------------------------------





Admin::Admin()
{
	username = "";
	password = "";
}
Admin::Admin(string username, string password)
{
	this->username = username;
	this->password = password;
}
Admin::~Admin()
{
}
void Admin::set_username(string username)
{
	this->username = username;
}
void Admin::set_password(string password)
{
	this->password = password;
}
string Admin::get_username()
{
	return username;
}
string Admin::get_password()
{
	return password;
}
string Admin::getCurrentTime()
{

	time_t now;
	time(&now);
	char buffer[26];
	string currentTime;

	if (ctime_s(buffer, sizeof(buffer), &now) == 0) {
		currentTime = buffer;
	}
	else {
		currentTime = "Error getting current time";
	}

	return currentTime;



}

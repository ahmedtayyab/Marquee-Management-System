#pragma once
#include<Windows.h>
#include<iostream>
#include<string>
#include <fstream>
#include <chrono>
#include <ctime>
#include <sstream>
#include <conio.h>
#include <vector>
using namespace std;

#ifdef max
#undef max
#endif

void Logo();


struct Event {
	string dateString;
	string functionTime;
	int numPeople;
	string controller;
	string eventName;
	string name; // Additional fields for storing name and phone number
	string phoneNumber;
};


struct Appointment
{
	tm dateTime;
};

struct BookingDetails
{
	string name;
	string phone_num;
	string dateString;
	string functionTime;
	int numPeople;
	string eventName;
	string bookedTime;
	string controller;
};

BookingDetails readBookingDetailsFromFile(ifstream& infile);






class Person
{
private:
	string dateString;
	int numPeople;

protected:
	string name;
	string phone_num;

public:
	Person();
	~Person();
	Person(string, string);
	void set_name(string);
	void set_phone_num(string);
	string get_name();
	string get_phone_num();
	string bookingDate();
	int numberOfPeople();

	void displayBookingDetails(const string& dateString, const string& functionTime, const int& numpeople, const string& controller, const string& eventName);

	void editBooking();

	string getCurrentTime();

	string timeOfDay();

	string userBookingName();


	void checkAvailability();
	
	void cancelBooking();

	void writeToFiles(const string& dateString, const string& functionTime, const int& numPeople, const string& controller, const string& eventName, const string& name, const string& phoneNumber);


	static string convertDate(const string& date);
	//void sortEvents();
	void syncTextFileFromCSV();
	

	void updateCSV(const vector<string>& event);

};

class Admin :public Person
{
protected:
	string username;
	string password;
public:

	Admin();
	~Admin();
	Admin(string, string);
	void set_username(string);
	void set_password(string);
	string get_username();
	string get_password();
	string getCurrentTime();


}; 

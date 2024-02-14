
#include <bits/stdc++.h>
using namespace std;

class Car
{
private:
	int carId;
	string carModel, carPlate, carMileage, carCapacity, carCostPerDay, carInsuranceCost;

public:
	void getCarInfo() // Enter the details of a car you want to add to the system
	{
		cout << "\n[RETREIVING CAR INFO....]"
			 << "\nEnter Car ID: ";
		cin >> carId;
		cout << "Enter Car Model:";
		getline(cin >> ws, carModel);
		cout << "Enter Car Number Plate: ";
		getline(cin >> ws, carPlate);
		cout << "Enter Car Capacity: ";
		getline(cin >> ws, carCapacity);
		cout << "Enter Car Mileage: ";
		getline(cin >> ws, carMileage);
		cout << "Enter Car Cost Per Day: ";
		getline(cin >> ws, carCostPerDay);
		cout << "Enter Car Insurance Cost: ";
		getline(cin >> ws, carInsuranceCost);
		cout << "_________" << endl;
	}

	void DisplayCarInfo() // Display the details of a specific car in the system
	{
		cout << "\nCar ID: " << carId
			 << "\nCar Model: " << carModel
			 << "\nCar Number Plate: " << carPlate
			 << "\nCar Capacity: " << carCapacity
			 << "\nCar Mileage: " << carMileage
			 << "\nCar Cost Per Day: " << carCostPerDay
			 << "\nCar Insurance Cost: " << carInsuranceCost << endl;
	}
	void getCarModel() { cout << carModel; } // Just get the model of a car
};

class CarRentalData
{
protected:
	vector<Car> AllCars, bookedCars; // Vector to store all cars and booked cars

public:
	friend class CarBooking;
	void addAllCar(Car &car) { AllCars.push_back(car); }	   // Used for adding a new car into the Allcars vector
	void addBookedCar(Car &car) { bookedCars.push_back(car); } // Used for adding a booked car to the bookedcars vector

	int numberOfAllCars() { return AllCars.size(); };
	int numberOfCarBooked() { return bookedCars.size(); };

	void getAllCars() // Displays all the cars that are in the Allcars vector
	{
		if (AllCars.size() != 0)
		{
			cout << "\n[DISPLAYING ALL CARS....]" << endl;

			for (int i = 0; i < AllCars.size(); i++)
			{
				cout << endl
					 << "[" << i + 1 << "]"
					 << ". ";
				AllCars.at(i).DisplayCarInfo();
				cout << "_________" << endl;
			}
		}
		else
			cout << "No cars available" << endl;
	}

	void getBookedCars() // Display all the booked cars in the bookedCars vector
	{
		if (bookedCars.size() != 0)
		{
			cout << "\n[DISPLAYING BOOKED CARS....]" << endl;

			for (int i = 0; i < bookedCars.size(); i++)
			{

				cout << "[" << i + 1 << "]"
					 << ". ";
				bookedCars.at(i).DisplayCarInfo();
				cout << "_________" << endl;
			}
		}
		else
		{
			cout << "No Booked Cars!" << endl;
		}
	}
};

CarRentalData data;

class CarBooking
{
private:
	Car BookedCar;
	string carPickupLocation, carDropoffLocation, carPickUpDate;
	string carDropOffDate, carPickupTime, carDropOffTime;
	int carIndex = -1;
	bool wrongIndex = true;

public:
	void getBookingInfo() // Function that is called when a user wants to book a car.
	{
		if (data.numberOfAllCars() == 0)
			cout << "No Cars Available" << endl;

		else
		{
			data.getAllCars();
			cout << "\n[GETTING BOOKING INFO....]" << endl;
			while (wrongIndex)
			{
				try
				{
					cout << "Choose Index number of Car You Want: ";
					cin >> carIndex;
					if ((carIndex > data.AllCars.size()))
					{
						throw out_of_range("Invalid Index");
					}
					else
					{
						wrongIndex = false;
						BookedCar = data.AllCars[carIndex - 1];
						BookedCar.DisplayCarInfo();
						data.bookedCars.push_back(BookedCar);
						data.AllCars.erase(data.AllCars.begin() + (carIndex - 1));
					}
				}
				catch (out_of_range)
				{
					cout << "Index is out of range" << endl;
				}
			}
			cout << "Enter Car Pick-Up Location: ";
			getline(cin >> ws, carPickupLocation);
			cout << "Enter Car Drop-Off Location: ";
			getline(cin >> ws, carDropoffLocation);
			cout << "Enter Car Pick-Up Date: ";
			getline(cin >> ws, carPickUpDate);
			cout << "Enter Car Drop-Off Date: ";
			getline(cin >> ws, carDropOffDate);
			cout << "Enter Car Pick-Up time: ";
			getline(cin >> ws, carPickupTime);
			cout << "Enter Car Drop Off Time: ";
			getline(cin >> ws, carDropOffTime);
			cout << "_________" << endl;
		}
	}

	void displayBookingInfo()
	{
		if (carIndex == -1)
		{
			cout << "No Cars booked!" << endl;
			return;
		}
		cout << "Car Index: " << carIndex << endl;
		cout << "\n[DISPLAYING BOOKING INFO....]";

		data.AllCars[carIndex - 1].DisplayCarInfo();
		cout << "\nPick-Up Location: " << carPickupLocation
			 << "\nDrop-Off Location: " << carDropoffLocation
			 << "\nPick-Up Date: " << carPickUpDate
			 << "\nDrop-Off Date: " << carDropOffDate
			 << "\nPick-Up Date: " << carPickUpDate
			 << "\nPick-Up time: " << carPickupTime
			 << "\nDrop Off Time: " << carDropOffTime
			 << "\n___________" << endl;
	}
};

class Customer
{
private:
	string customerName, customerPass, customerAddress, customerPhone;
	CarBooking Bookingobj1;

public:
	friend class CarBooking;

	Customer(){};
	// Customer(CarBooking obj) { Bookingobj1 = obj; }
	void setCustomerName(string temp) { customerName = temp; }
	string getCustomerName() { return customerName; }
	void setCustomerPassword(string temp) { customerPass = temp; }
	string getCustomerPassword() { return customerPass; }
	void setCustomerAddress(string temp) { customerAddress = temp; }
	string getCustomerAddress() { return customerAddress; }
	void setCustomerPhone(string temp) { customerPhone = temp; }
	string getCustomerPhone() { return customerPhone; }
	void setCustomerInfo()
	{
		cout << "[GET CUSTOMER INFO....]"
			 << "\nEnter Name: ";
		fflush(stdin);
		getline(cin, customerName);
		cout << "Enter Password: ";
		fflush(stdin);
		getline(cin, customerPass);
		cout << "Enter Customer Address: ";
		fflush(stdin);
		getline(cin, customerAddress);
		cout << "Enter Customer Phone: ";
		fflush(stdin);
		getline(cin, customerPhone);
		cout << "\n___________\n";
	}
	void updateCustomerInfo()
	{
		cout << "[UPDATE CUSTOMER INFO....]"
			 << "\nName And Password Cannot Be Changed!"
			 << "\nEnter Customer Address: ";
		fflush(stdin);
		getline(cin, customerAddress);
		cout << "Enter Customer Phone: ";
		fflush(stdin);
		getline(cin, customerPhone);
		cout << "\n___________\n";
	}
	void displayCustomerInfo()
	{
		cout << "[DISPLAY CUSTOMER INFO....]"
			 << "\nName: " << customerName
			 << "\nAddress: " << customerAddress
			 << "\nPhone: " << customerPhone
			 << "\n___________" << endl;
	}
	void myBookingInfo()
	{
		Bookingobj1.displayBookingInfo();
	}
	void rentCar()
	{
		Bookingobj1.getBookingInfo();
	}
};

void customer_menu(Customer &cust)
{
	int choice;
	while (1)
	{
		system("cls");
		cout << "Welcome to Rental Car Management System";
		cout << "\nPress to view\n"
			 << "   1. Rent Car\n"
			 << "   2. View All Cars\n"
			 << "   3. View Your Booking\n"
			 << "   4. View Your Profile\n"
			 << "   5. Update Your Profile\n"
			 << "   0. Back\n"
			 << "Your Input: ";
		cin >> choice;
		switch (choice)
		{
		case 0:
		{
			return;
			break;
		}

		case 1:
		{
			cust.rentCar();
			system("pause");
			break;
		}

		case 2:
		{
			if (data.numberOfAllCars() == 0 && data.numberOfCarBooked() == 0)
			{
				cout << "No Cars Available" << endl;
				system("pause");
			}
			else
			{
				data.getAllCars();
				data.getBookedCars();
				system("pause");
			}
			break;
		}

		case 3:
		{
			cust.myBookingInfo();
			system("pause");
			break;
		}

		case 4:
		{
			cust.displayCustomerInfo();
			system("pause");
			break;
		}

		case 5:
		{
			cust.updateCustomerInfo();
			system("pause");
			break;
		}

		default:
		{
			cout << "An Error Occured" << endl;
			break;
		}
		}
	}
};

class Admin
{
private:
	string adminEmail, adminPass, adminName;
	Customer obj1;

public:
	Admin(Customer obj) { obj1 = obj; }
	Admin(string adminName, string adminPass, string adminEmail) : adminName(adminName), adminPass(adminPass), adminEmail(adminEmail){};
	void getAdminInfo()
	{
		cout << "\n[GET ADMIN INFO....]" << endl;
		cout << "Enter Admin Name: ";
		fflush(stdin);
		getline(cin, adminName);
		cout << "Enter Admin Password: ";
		fflush(stdin);
		getline(cin, adminPass);
		cout << "Enter Admin Email: ";
		fflush(stdin);
		getline(cin, adminEmail);
		cout << "_________" << endl;
	}
	string getAdminName() { return adminName; }
	string getAdminPassword() { return adminPass; }

	void DisplayAdminInfo()
	{
		cout << "\n[DISPLAY ADMIN INFO....]"
			 << "\nAdmin Name: " << adminName
			 << "\nAdmin Password: " << adminPass
			 << "\nAdmin Email: " << adminEmail
			 << "\n___________" << endl;
	}

	void getCustomerBookingInfo()
	{
		obj1.displayCustomerInfo();
		cout << endl;
		obj1.myBookingInfo();
	}
};

Admin admin("admin", "admin", "admin@gmail.com");

void admin_menu()
{
	int choice;
	while (1)
	{
		system("cls");
		cout << "Welcome Admin";
		cout << "\nPress\n"
			 << "   1. Add New Car\n"
			 << "   2. View All Cars\n"
			 << "   3. View Your Profile\n"
			 << "   4. Update Your Profile\n"
			 << "   0. Back\n"
			 << "Your Input: ";
		cin >> choice;
		switch (choice)
		{
		case 0:
		{
			return;
			break;
		}

		case 1:
		{
			Car car;
			car.getCarInfo();
			data.addAllCar(car);
			system("pause");
			break;
		}

		case 2:
		{
			data.getAllCars();
			data.getBookedCars();
			system("pause");
			break;
		}

		case 3:
		{
			admin.DisplayAdminInfo();
			system("pause");
			break;
		}

		case 4:
		{
			admin.getAdminInfo();
			system("pause");
			break;
		}

		default:
		{
			cout << "An Error Ocurred";
			break;
		}
		}
	}
};

void add_customer_account_file(Customer &cust)
{
	ofstream f("customer_accounts.csv", ios::app);
	if (!f.is_open())
	{
		cout << "could not open file\n";
		exit(EXIT_FAILURE);
	}
	else
	{
		f << cust.getCustomerName() << ","
		  << cust.getCustomerPassword() << ","
		  << cust.getCustomerAddress() << ","
		  << cust.getCustomerPhone() << endl;
		f.close();
	}
};

Customer retrieve_customer_account_file(string user, string pass) // Function to retreive user from CSV File
{
	ifstream f("customer_accounts.csv", ios::in);
	Customer b;
	if (!f.is_open())
	{
		cout << "could not open file\n";
		exit(EXIT_FAILURE);
	}
	while (!f.eof())
	{
		string line;
		getline(f, line, ','); // name
		b.setCustomerName(line);
		getline(f, line, ','); // pass
		b.setCustomerPassword(line);
		getline(f, line, ','); // address
		b.setCustomerAddress(line);
		getline(f, line); // phone
		b.setCustomerPhone(line);

		if ((b.getCustomerName() == user) && (b.getCustomerPassword() == pass))
			break;

		else
		{
			string temp = "not_found";
			b.setCustomerName(temp);
		}
	}
	f.close();
	return b;
};

// To login as admin login with username and password both as "admin"

int main()
{
	system("cls");
	cout << "\n                             ______________________________________________________________"
		 << "\n                            |                                                              |"
		 << "\n                            |                          WELCOME                             |"
		 << "\n                            |                                                              |"
		 << "\n                            |               CAR RENTAL MANAGEMENT SYSTEM                   |"
		 << "\n                            |______________________________________________________________|\n\n\n";
	system("pause");
	int choice;
	while (1)
	{
		system("cls");
		cout << "Welcome to Rental Car Management System";
		cout << "\nPress\n"
			 << "   1. Register\n"
			 << "   2. Login\n"
			 << "   0. Exit\n"
			 << "Your Input: ";
		cin >> choice;
		switch (choice)
		{
		case 0:
		{
			cout << "Thank You For Choosing Us!";
			exit(EXIT_SUCCESS);
			break;
		}

		case 1:
		{
			system("cls");
			Customer cust;
			cust.setCustomerInfo();
			add_customer_account_file(cust);
			system("pause");
			break;
		}

		case 2:
		{
			string name, password, inName, inPassword;
			system("cls");
			cout << "\n***** Account Login *****\n"
				 << "Enter Username: ";
			fflush(stdin);
			getline(cin, inName);
			cout << "Enter Password: ";
			fflush(stdin);
			getline(cin, inPassword);

			if (inName == admin.getAdminName() && inPassword == admin.getAdminPassword())
			{
				admin_menu();
			}
			else
			{
				Customer cust;
				cust = retrieve_customer_account_file(inName, inPassword);

				if (cust.getCustomerName() != "not_found")
				{
					cout << "Login Successful\n"
						 << "Welcome, "
						 << cust.getCustomerName() << endl;
					system("pause");
					customer_menu(cust);
				}
				else if ((cust.getCustomerName() == "not_found"))
				{
					cout << "incorrect name or password\n";
					system("pause");
				}
			}
			break;
		}
		default:
		{
			cout << "An Error Occured";
			break;
		}
		}
	}
	return 0;
}

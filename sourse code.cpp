#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

struct Admin
{
    string a_ID;
    string a_pin;
};

void customer();
void adminLogin();
void customerLogin();
void createAccount();
void adminMenu();
void customerMenu();
void addCar();
void viewCars();
void viewRentedCars();
void removeCar();
void viewAvailableCars();
void rentCar();
void returnCar();

int main()
{

    char choice;
    bool c = true;
    do
    {
        system("cls");
        cout << "\n\n\n\t*****  Welcome  *****";
        cout << "\n\n***** Car Rental Management System *****\n\n";
        cout << "\n\n";

        cout << "1. I am a Customer \n\n";
        cout << "2. I am an Administrator \n\n";
        cout << "3. Exit";
        cout << "\n\nEnter Your Choice: ";
        cin >> choice;
        switch (choice)
        {
	        case '1':
	            customer();
	            break;
	
	        case '2':
	            adminLogin();
	            break;
	
	        case '3':
	            cout << "\nThanks For Visiting ! ";
	            break;
	
	        default:
	            cout << "\nEnter a valid choice!";
	            c = false;
	            break;
        }
    } while (choice != '3' || c == false);

    return 0;
}

void customer()
{
    system("cls");
    char choice;
    bool c = true;

    cout << "\n\n\n\t*****  Welcome  *****";
    cout << "\n\n***** Car Rental Management System *****\n\n";

    do
    {
        cout << "\n\n";
        cout << "\n1. I Already have an account (Login)\n";
        cout << "\n2. I Don't have an Account (Create Account)\n";
        cout << "\n3. Exit\n";
        cout << "\n\nEnter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
	        case '1':
	            customerLogin();
	            break;
	
	        case '2':
	            createAccount();
	            break;
	
	        case '3':
	            cout << "\n\nThanks For Visiting !";
	            break;
	
	        default:
	            cout << "\nEnter a valid choice! ";
	            c = false;
	            break;
        }
    } while (c == false);
}

void adminLogin()
{
    system("cls");
    string ID, pin;
    Admin a1 = {"12", "456"}, a2 = {"54", "879"};

    cout << "\n\n\n\t*****  Welcome  *****";
    cout << "\n\n***** Car Rental Management System *****\n\n";
    cin.ignore();
    do
    {
        cout << "\n\n";
        cout << "Enter you login details: \n\n";
        cout << "Enter ID: ";
        getline(cin, ID);
        cout << "Enter PIN: ";
        getline(cin, pin);
        if ((ID == a1.a_ID && pin == a1.a_pin) || (ID == a2.a_ID && pin == a2.a_pin))
        {
            cout << "\nLogin Sucessfull !\n\n";
            adminMenu();
        }
        else
        {
            cout << "Incorrect ID of PIN. Try Again! \n";
        }
    } while (!((ID == a1.a_ID && pin == a1.a_pin) || (ID == a2.a_ID && pin == a2.a_pin)));
    system("cls");
}

void customerLogin()
{
    system("cls");
    string ID, pin;
    bool found = false;

    cout << "\n\n\n\t*****  Welcome  *****";
    cout << "\n\n***** Car Rental Management System *****\n\n";

    do
    {
        cout << "\n\n";
        cout << "Enter your login details: \n\n";
        cout << "Enter ID: ";
        cin >> ID;
        cout << "Enter PIN: ";
        cin >> pin;

        ifstream file("Customer_List.txt"); // Open the file for reading
        if (!file.is_open())
        {
            cout << "Error: Unable to open the customer list file!" << endl;
            return;
        }

        string fileID, filePIN;
        while (file >> fileID >> filePIN) // Read ID and PIN from the file
        {
            if (fileID == ID && filePIN == pin) // Check if credentials match
            {
                found = true;
                break;
            }
        }
        file.close();

        if (found)
        {
            cout << "\nLogin Successful!\n\n" << endl;
            customerMenu(); 
        }
        else
        {
            cout << "Incorrect ID or PIN. Try Again!\n";
        }
    } while (!found);
    system("cls");
}

void createAccount()
{
    system("cls");
    string ID, pin;
    cout << "\n\n\n\t*****  Welcome  *****";
    cout << "\n\n***** Car Rental Management System *****\n\n";
    cout << "\n\n";
    
    cout << "Enter the following details to create you account: \n\n";
    cout << "Set your ID: ";
    cin >> ID;
    cout << "Set your PIN: ";
    cin >> pin;
    ofstream file("Customer_List.txt", ios::app); // Open the file in append mode
    if (!file.is_open())
    {
        cout << "Error: Unable to open the customer list file for writing!" << endl;
        return;
    }

    file << ID << "\t" << pin << endl; // Append the new customer details to the file
    file.close();

    cout << "Account Created Successfully!" << endl;
    customerMenu();
}

void adminMenu()
{
    system("cls");
    char choice;
    bool c = true;

    cout << "\n\n\n\t*****  Welcome  *****";
    cout << "\n\n***** Car Rental Management System *****\n\n";

    do
    {
        cout << "\n\n";
        cout << "1. View All Cars" << endl;
        cout << "2. Add a Car " << endl;
        cout << "3. View Available Cars" << endl;
        cout << "4. View Rented Cars" << endl;
        cout << "5. Remove a Car" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
	        case '1':
	            viewCars();
	            break;
	
	        case '2':
	            addCar();
	            break;
	
	        case '3':
	            viewAvailableCars();
	            break;
	
	        case '4':
	            viewRentedCars();
	            break;
	
	        case '5':
	            removeCar();
	            break;
	
	        case '6':
	            cout << "Thanks for you time. Bye! ";
	            break;
	
	        default:
	            cout << "\nEnter a valid choice\n";
	            c = false;
	            break;
        }
    } while (choice != '6' || c == false);
    system("cls");
}

void customerMenu()
{
    system("cls");
    char choice;
    bool c = true;

    cout << "\n\n\n\t*****  Welcome  *****";
    cout << "\n\n***** Car Rental Management System *****\n\n";

    do
    {
        cout << "\n\n";
        cout << "1. View all cars\n";
        cout << "2. View available cars\n";
        cout << "3. Rent a Car \n";
        cout << "4. Return a Car\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
	        case '1':
	            viewCars();
	            break;
	
	        case '2':
	            viewAvailableCars();
	            break;
	
	        case '3':
	            rentCar();
	            break;
	
	        case '4':
	            returnCar();
	            break;
	
	        case '5':
	            cout << "Thanks for visiting!";
	            break;
	
	        default:
	            cout << "Enter a valid choice";
	            c = false;
	            break;
        }
        cout << endl;
    } while (choice != '5' || c == false);
}

void viewCars()
{
    system("cls");
    ifstream file("Car_List.txt"); // Open the file
    if (!file.is_open())           // Check if the file is opened successfully
    {
        cout << "Error: Unable to open the car list file!" << endl;
        return;
    }

    string line;
    cout << "\n\t\t\t\t\t\tAll Cars:\n\n";
    while (getline(file, line)) // Read each line from the file
    {
        cout << line << endl; // Display the line
    }

    file.close(); // Close the file
}

void addCar()
{
    system("cls");
    string ID, name, regNo, transmission, engine, model, rent;

    cout << "\n\n\n\t*****  Welcome  *****";
    cout << "\n\n***** Car Rental Management System *****\n\n";

    cout << "\n\n";
    cout << "Enter the details of car that you want to add \n\n";
    cin.ignore();
    cout << "Enter ID: ";
    getline(cin, ID);

    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Registration No: ";
    getline(cin, regNo);

    cout << "Enter Transmission: ";
    getline(cin, transmission);

    cout << "Enter Engine: ";
    getline(cin, engine);

    cout << "Enter Model: ";
    getline(cin, model);

    cout << "Enter Rent Per Day: ";
    getline(cin, rent);

    // Open the file in append mode
    ofstream allCars("Car_List.txt", ios::app);
    ofstream availableCars("Available_Cars.txt", ios::app);
    if (!allCars.is_open() && !availableCars.is_open())
    {
        cout << "Error: Unable to open the car list file for writing!" << endl;
        return;
    }

    // Append the new car details to the file
    allCars << ID << "\t" << name << "\t\t" << regNo << "\t\t" << transmission << "\t\t"
            << engine << "\t\t" << model << "\t\t" << rent << endl;
    allCars.close();

    availableCars << ID << "\t" << name << "\t\t" << regNo << "\t\t" << transmission << "\t\t"
                  << engine << "\t\t" << model << "\t\t" << rent << endl;
    availableCars.close();

    cout << "Car Added Successfully!" << endl;
}

void viewRentedCars()
{
    system("cls");
    ifstream file("Rented_Cars.txt"); // Open the file
    if (!file.is_open())
    {
        cout << "Error: Unable to open the car list file!" << endl;
        return;
    }

    string line;
    cout << "\n\t\t\t\t\t\tRented Cars:\n\n";
    while (getline(file, line)) // Read each line from the file
    {
        cout << line << endl; // Display the line
    }

    file.close();
}

void removeCar()
{
    int carID;
    bool carFoundInAll = false;
    bool carFoundInAvailable = false;

    cout << "\n\n";
    cout << "Enter the ID of the car you want to remove: ";
    cin >> carID;

    // Open files for all cars
    ifstream allCarsFile("Car_List.txt");
    ofstream tempAllCarsFile("Temp_Car_List.txt");

    if (!allCarsFile.is_open() || !tempAllCarsFile.is_open())
    {
        cout << "Error: Unable to open 'Car_List.txt' for writing!" << endl;
        return;
    }

    string line;
    while (getline(allCarsFile, line))
    {
        stringstream ss(line);
        int currentID;
        ss >> currentID;

        if (currentID == carID)
        {
            carFoundInAll = true; // Skip writing this car to the temp file
        }
        else
        {
            tempAllCarsFile << line << endl; // Write all non-removed cars to the temp file
        }
    }

    allCarsFile.close();
    tempAllCarsFile.close();

    if (carFoundInAll)
    {
        // Replace Car_List.txt with Temp_Car_List.txt
        remove("Car_List.txt");
        rename("Temp_Car_List.txt", "Car_List.txt");
        cout << "Car with ID " << carID << " has been successfully removed" << endl;
    }
    else
    {
        remove("Temp_Car_List.txt"); // Clean up temp file
        cout << "Car with ID " << carID << " was not found in 'Car_List.txt'." << endl;
    }

    // Open files for available cars
    ifstream availableCarsFile("Available_Cars.txt");
    ofstream tempAvailableCarsFile("Temp_Available_Cars.txt");

    if (!availableCarsFile.is_open() || !tempAvailableCarsFile.is_open())
    {
        cout << "Error: Unable to open 'Available_Cars.txt' for writing!" << endl;
        return;
    }

    while (getline(availableCarsFile, line))
    {
        stringstream ss(line);
        int currentID;
        ss >> currentID;

        if (currentID == carID)
        {
            carFoundInAvailable = true; // Skip writing this car to the temp file
        }
        else
        {
            tempAvailableCarsFile << line << endl; // Write all non-removed cars to the temp file
        }
    }

    availableCarsFile.close();
    tempAvailableCarsFile.close();

    if (carFoundInAvailable)
    {
        // Replace Available_Cars.txt with Temp_Available_Cars.txt
        remove("Available_Cars.txt");
        rename("Temp_Available_Cars.txt", "Available_Cars.txt");
    }
    else
    {
        remove("Temp_Available_Cars.txt"); // Clean up temp file
        cout << "Car with ID " << carID << " was not found in 'Available_Cars.txt'." << endl;
    }
}

void viewAvailableCars()
{
    system("cls");
    ifstream file("Available_Cars.txt"); // Open the file
    if (!file.is_open())                 // Check if the file is opened successfully
    {
        cout << "Error: Unable to open the car list file!" << endl;
        return;
    }

    string line;
    cout << "\n\t\t\t\t\t\tAvailable Cars:\n\n";
    while (getline(file, line)) // Read each line from the file
    {
        cout << line << endl; // Display the line
    }

    file.close(); // Close the file
}

void rentCar()
{
    int carID;
    bool carFound = false;
    string carDetails;

    cout << "\n\n";
    cout << "Enter the ID of the car you want to rent: ";
    cin >> carID;
   

    // Open files for reading and writing
    ifstream availableFile("Available_Cars.txt");
    ofstream tempFile("Temp_Available_Cars.txt");
    ofstream rentedFile("Rented_Cars.txt", ios::app); // Append mode for rented cars

    if (!availableFile.is_open() || !tempFile.is_open() || !rentedFile.is_open())
    {
        cout << "Error: Unable to open files!" << endl;
        return;
    }

    string line;
    while (getline(availableFile, line))
    {
        stringstream ss(line);
        int currentID;
        ss >> currentID;

        if (currentID == carID)
        {
            carFound = true;
            carDetails = line; // Save the car details to move to Rented_Cars.txt
        }
        else
        {
            tempFile << line << endl; // Write back non-matching cars to temp file
        }
    }

    availableFile.close();
    tempFile.close();

    if (carFound)
    {
        // Add the car to rented cars
        rentedFile << carDetails<<endl;
        rentedFile.close();

        // Replace Available_Cars.txt with Temp_Available_Cars.txt
        remove("Available_Cars.txt");
        rename("Temp_Available_Cars.txt", "Available_Cars.txt");

        cout << "Car with ID " << carID << " has been successfully rented!" << endl;
    }
    else
    {
        remove("Temp_Available_Cars.txt"); // Clean up temp file
        cout << "Car with ID " << carID << " is not available for rent." << endl;
    }
}

void returnCar()
{
    int carID;
    bool carFound = false;
    string carDetails;

    cout << "\n\n";

    cout << "Enter the ID of the car you want to return: ";
    cin >> carID;

    // Open files for reading and writing
    ifstream rentedFile("Rented_Cars.txt");
    ofstream tempFile("Temp_Rented_Cars.txt");
    ofstream availableFile("Available_Cars.txt", ios::app); // Append mode for available cars

    if (!rentedFile.is_open() || !tempFile.is_open() || !availableFile.is_open())
    {
        cout << "Error: Unable to open files!" << endl;
        return;
    }

    string line;
    while (getline(rentedFile, line))
    {
        stringstream ss(line);
        int currentID;
        ss >> currentID;

        if (currentID == carID)
        {
            carFound = true;
            carDetails = line; // Save the car details to move back to Available_Cars.txt
        }
        else
        {
            tempFile << line << endl; // Write all non-returned cars to temp file
        }
    }

    rentedFile.close();
    tempFile.close();

    if (carFound)
    {
        // Add the returned car to Available_Cars.txt
        availableFile << carDetails << endl;
        availableFile.close();

        // Replace Rented_Cars.txt with Temp_Rented_Cars.txt
        remove("Rented_Cars.txt");
        rename("Temp_Rented_Cars.txt", "Rented_Cars.txt");

        cout << "Car with ID " << carID << " has been successfully returned!" << endl;
    }
    else
    {
        remove("Temp_Rented_Cars.txt"); // Clean up temp file
        cout << "Car with ID " << carID << " is not in the rented list." << endl;
    }
}

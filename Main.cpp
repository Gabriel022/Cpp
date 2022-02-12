/*
 *
 * Gabriel Facco Bettinelli
 *
 * Final Programming Assignment.
 *
 * May 9, 2017
 *
*/

//   Additional files needed to compile this program:
//   EmployeeInfo.cpp
//   BinaryEmployeeTree.cpp



#include "EmployeeInfo.h" // Including Declaration of EmployeeInfo Class.
#include "BinaryEmployeeTree.h" // Including Declaration of BinaryEmployeeTree Class.
#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdio.h>
using namespace std;



// Function prototypes
void gettingSafeIntInput(int &intvalueback);
void initialization();
int displayMenu();
void displayError();
void gettingSafeStringInput(string &a);
bool checkStringForSpaces(const string &a);
void case1(BinaryEmployeeTree &EmployeeInfo); // Executes option number 1 in the menu.




int main()
{
    BinaryEmployeeTree EmployeeTree;
    int choice = 0;

    initialization(); // Display Initial Output.

    while(choice!=6){

        choice = displayMenu(); // Getting back the result from the user, and making the variable choice equal that choice
        switch(choice) // Switch Statement over 6 different cases(default included).
        {
            case 1:
                    {
                        case1(EmployeeTree);
                    }
                        break;

            case 2:
                    {
                        cout<< "Search For Employee." <<endl;
                        cout<< "Input Employee's ID that is desired to be found: " << endl;
                        int b; gettingSafeIntInput(b);
                        if(EmployeeTree.searchNode(b) == -1)
                        {
                            cout << endl << "Employee Not Found!" << endl;
                            cout << "Try other ID." << endl << endl;
                        }
                    }
                        break;

            case 3:
                    {
                        cout<< "Dismiss Employee." <<endl;
                        cout<< "Enter the Id Number of desired Employee to be hired." << endl;
                        int b; gettingSafeIntInput(b);
                        while(b <= 1000 || b >= 9999)
                        {
                            cout << "Incorrect Number input(Smaller than 1000 or bigger than 9999)." << endl;
                            cout << "Try Again." << endl;
                            gettingSafeIntInput(b);
                        }
                        if(EmployeeTree.searchNode(b) == 0) //Verifying Id Number to see if exist.
                        {
                            EmployeeTree.remove(b);
                            cout<< "Employee Fired." << endl << endl;
                        }
                        else
                        {
                            cout <<"Employee could not be founded! Try Again!" << endl << endl;
                        }

                    }
                        break;

            case 4:
                    {
                        cout<< "Showing all employees:" <<endl;
                        EmployeeTree.displayInOrder();
                        cout<< endl;
                    }
                        break;

            case 5:
                    {

                        cout<< "Showing all instances of the employees under 25 years old. " << endl << endl;
                        EmployeeTree.findYoungEmployees();
                        cout << "All instances of Peoples with less than 25 years showed." << endl << endl;
                    }
                        break;

            case 6:
                    {
                        cout<<"Exiting Program.";
                        exit(0);
                    }

            default: displayError();
        }
    }
    return 0;
}


// ********************************************************
// name:      gettingSafeIntInput
// called by: main.
// passed:    integer variable(reference)
// returns:   a integer value that gets stored in a variable passed as reference argument to the function.
// calls:     nobody
// The gettingSafeIntInput display for the user to enter a valid number, then it analyzes the input, and filter it to be in the right type of input
// (This case is int), and if it is not from the right type, it makes the user try again another input, until it gets in the right way.                                          *
// ********************************************************

void gettingSafeIntInput(int &intvalueback){
    string input = "";
    int myNumber = 0;
    while (true) {
        cout << "Please enter a valid number: ";
        getline(cin, input);

        // This code converts from string to number safely.
        stringstream myStream(input);
        if ((myStream >> myNumber) && (!(input.find('.')!=string::npos)) && (!(input.find(',')!=string::npos)))
            break;

        cout << "Invalid input, please try again" << endl;
 }

    intvalueback = myNumber;
}

// ********************************************************
// name:      initialization
// called by: main.
// passed:    nothing.
// returns:   void.
// calls:     nobody
// The initialization() Display Initial Output.                                         *
// ********************************************************
void initialization(){
    cout << "Hello, this program controls the hire or firing of a company employee's." << endl;
    cout << "Please select one of the choices from the Employee menu." << endl;
    cout << endl;
}


// ********************************************************
// name:      displayMenu
// called by: main.
// passed:    nothing.
// returns:   integer-userchoice.
// calls:     gettingsafeintinput
// The  displayMenu() display the menu options, and return the user choice.                                      *
// ********************************************************
int displayMenu()
{
    int userChoice;
    cout<<"Choose an option from the Menu:"<<endl;
    cout<<"1.Hire a new Employee." << endl;
    cout<<"2.Search For Employee."<<endl;
    cout<<"3.Dismiss Employee."<<endl;
    cout<<"4.Show all employees."<<endl;
    cout<<"5.Find all instances of the employees under 25 years old."<<endl;
    cout<<"6.Exit"<<endl;
    cout<<endl;

    gettingSafeIntInput(userChoice);
    cout<<endl;

    return userChoice;
}

// ********************************************************
// name:      displayError
// called by: main.
// passed:    nothing.
// returns:   void-.
// calls:     nothing.
// The  displayError() display a default error, when user choose the wrong option in the menu.                                      *
// ********************************************************
void displayError()
{
    cout<< "Wrong Menu Choice, please try again."<<endl;

}


// ********************************************************
// name:      checkStringForSpaces
// called by: gettingSafeStringInput.
// passed:    string.
// returns:   bool value-.
// calls:     find_first_not_of.
// The  checkStringForSpaces() returns true is the string is empty, otherwise returns false.                                      *
// ********************************************************
bool checkStringForSpaces(const string &a) {
   return a.find_first_not_of (' ') == a.npos;
}


// ********************************************************
// name:      gettingSafeStringInput
// called by: main.
// passed:    string varible
// returns:   void
// calls:     checkStringForSpaces , resize(), str.length()
// The gettingSafeStringInput display for the user to enter a valid name, then it analyzes the input, and filter it to be in the right type of input
// (This case is string, no more than 50 char), and if it is not from the right type, it makes the user try again another input, until it gets in the right way.                                          *
// ********************************************************
void gettingSafeStringInput(string &a)
{
    int catcher = 0;
    int status = 0;
    //status == -1 is empty string
    //status == -2 is non letter input.
    int holder = 1;
    {
        while(holder == 1){ // Getting the Picture Name.
            cout << "Please Enter The Information (Maximum of 50 characters):" <<endl;
            string input3 = "";
            getline(cin, input3);

            bool b = checkStringForSpaces(input3);
            //If string is empty, change status.
            if(b == true)
            {
                status = -1;
            }
            //Checking for only letters on input.
            for(int i=0; i< input3.length();i++)
            {

//                if(!(isalpha(input3[i])))
//                {
//                    status = -2;              //COMMETING OUT CATCH FOR NON LETTERS INPUT.
//                    catcher = -2;
//                }
                if(!(isalpha(input3[0])))       // Therefore changing else if to if.
                {
                    catcher = -2;
                }
                else
                {
                    status = 0;

                }
            }
            if(status == 0)
            {
                a = input3;
                holder = 2;
            }
            else if(status == -1)
            {
                cout <<"Empty input." << endl;
                cout <<"Please try again and enter a correct name." << endl << endl;
            }
//            else if(status == -2 || catcher == -2)
//            {
//                cout <<"Empty input, or non-letters input found." << endl;                //COMMETING OUT ERROR FOR NON LETTER INPUT.
//                cout <<"Please try again and enter a correct name." << endl << endl;      // SO FUNCTION WILL ALLOW NUMBERS WITH THE STRING.
//            }
        }
    }
    //If input is larger than 50. Resize it to 50 chars.
    if(a.length() > 50)
    {
        a.resize(50);
    }
    cout << endl;
}



//Functino that executes the option number 1 in the menu
void case1(BinaryEmployeeTree &EmployeeTree)
{
    cout<< "Hire a new Employee." <<endl;
    cout<< "Put the Following Information about the Employee: " <<endl;
    cout<< "Select his Employee ID Number.";
    int b;
    gettingSafeIntInput(b);
    while(b <= 1000 || b >= 9999)
    {
        cout << "Incorrect Number input(Smaller than 1000 or bigger than 9999)." << endl;
        cout << "Try Again." << endl;
        gettingSafeIntInput(b);
    }

    while((EmployeeTree.validatingEmployeeID(b) == -1))
    {
        cout << "Already Existing Employee ID. Please Try Other number." << endl << endl;
        gettingSafeIntInput(b);
        if(b <= 1000 || b >= 9999)
        {
            cout << "Incorrect Number input(Smaller than 1000 or bigger than 9999)." << endl;
            cout << "Try Again." << endl;
            gettingSafeIntInput(b);
        }
    }
    cout<< "Employee's Name: " << endl;
    string c; gettingSafeStringInput(c);
    cout<< "Employee's Division: " << endl;
    string d; gettingSafeStringInput(d);
    cout<< "Employee's Age: " << endl;
    int e;
    gettingSafeIntInput(e);
    if(e < 18)
    {
        cout << "Incorrect Number input.Age should be bigger than 18." << endl;
        cout << "Try Again." << endl;
        gettingSafeIntInput(e);
    }
    EmployeeTree.insertNode(b, c, d, e);
    cout << "Employee Added Successfully. " << endl << endl;
}

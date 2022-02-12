/*
 *
 * Gabriel Facco Bettinelli
 *
 * Final Programming Assignment.
 *
 * May 9, 2017
 *
*/

#ifndef EMPLOYEEINFO_H
#define EMPLOYEEINFO_H

#include <string>
using namespace std;

// GradedActivity class declaration

class EmployeeInfo
{
    private:

        int employeeId; // Employee ID Number - integer (>1000 and <9999)

        string employeeName; //Employee Name - string (>0 and <50)

        string employeedivision; //Division - string (>0 and <50)
        int employeeAge; //  Age - integer (>=18)

    public:
        //Default Constructor          sets all the member variables to 0 or to " "
        EmployeeInfo()
        {
            employeeName = " ";
            employeedivision = " ";
            employeeId = 0;
            employeeAge = 0;
        }

        // Destructor
        virtual ~EmployeeInfo()
        {};

        // Overloaded Constructor
        EmployeeInfo(int a, string b, string c, int d);

        // Mutators function
        void setEmployeeId(int a);

        void setEmployeeName(string a);
        void setEmployeeDivision(string a);
        void setEmployeeAge(int a);

        // Accessors functions
        int getEmployeeId() const
        { return employeeId; }

        string getEmployeeName() const
        { return employeeName; }

        string getEmployeeDivision() const
        { return employeedivision; }

        int getEmployeeAge() const
        { return employeeAge; }

};
#endif

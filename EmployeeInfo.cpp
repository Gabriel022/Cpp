/*
 *
 * Gabriel Facco Bettinelli
 *
 * Final Programming Assignment.
 *
 * May 9, 2017
 *
*/

#include "EmployeeInfo.h"
#include <iostream>
#include <string>
using namespace std;


//Overload constructor declaration.
EmployeeInfo::EmployeeInfo(int a, string b, string c, int d)
{
    setEmployeeAge(a);
    setEmployeeName(b);
    setEmployeeDivision(c);
    setEmployeeAge(d);
}


//Setters / Mutators declaration.

void EmployeeInfo::setEmployeeId(int a){ //accepts an integer argument that is copied to the imageNumber variable - validate for (>1000 and <9999)
      if ((a > 1000) && (a < 9999)){
      employeeId = a;
      }
   else{
      cout << "Invalid Employee number.\n";
      exit(EXIT_FAILURE);
      cout << a;
   }
}

 void EmployeeInfo::setEmployeeName(string a){ //accepts a string argument that is copied to the imageName variable - validate for (>0 and <50)

     if((a.empty())||(a.size() > 50)){

      cout << "Invalid Employee name.\n";
      exit(EXIT_FAILURE);
     }
     else{
       employeeName = a;
     }
}

 void EmployeeInfo::setEmployeeDivision(string a){ //accepts a string argument that is copied to the filmType variable - validate for (>0 and <50)
     if((a.empty())||(a.size() > 50)){
        cout << "Invalid Division Type name.\n";
      exit(EXIT_FAILURE);
     }
     else{
        employeedivision = a;
     }

}

void EmployeeInfo::setEmployeeAge(int a){ //accepts a float argument that is copied to the pricePrints variable - validate for (>=18)
    if (a >= 18){
      employeeAge = a;
    }
   else{
      cout << "Invalid Employee's Age.\n";
      exit(EXIT_FAILURE);
   }

}


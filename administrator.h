/*
 * administrator.h
 *
 *  Created on: Aug 19, 2014
 *      Author: brandon
 */

#ifndef ADMINISTRATOR_H_
#define ADMINISTRATOR_H_

#include <string>
#include "salariedemployee.h"

namespace SavitchEmployees {

class Administrator: public SalariedEmployee {
private:
   string Title;
   string AreaOfResponsibility;
   string NameOfSupervisor;

   //private Variable inhereted from SalariedEmployee
   //double salary    //yearly

public:
   //Default Constructor
   Administrator ();

   //Constructor that supplies all necessary information to
   //Parent class SalariedEmployee
   Administrator ( const string& theName , const string& theSsn ,
         double theYearlySalary );

   //setter functions
   void SetTitle(string theTitle);
   void SetAreaOfResponsibility(string theArea);
   void SetNameOfSupervisor(string theSupervisorName);

   void KeyboardInput();

   //output functions
   void print() const;
   void printCheck() const;


};

}

#endif /* ADMINISTRATOR_H_ */

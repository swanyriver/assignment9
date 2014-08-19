/*
 * administrator.cpp
 *
 *  Created on: Aug 19, 2014
 *      Author: brandon
 */

#include <iostream>

#include "administrator.h"
#include "SwansonLibs/swansonInput.hpp"

using namespace SavitchEmployees;

//Default Constructor
Administrator::Administrator () :
         Title( "No Title Yet" ), AreaOfResponsibility(
               " No Area of Responsibility Yet" ), NameOfSupervisor(
               "No Supervisor Yet" ) {
   }

   //Constructor that supplies all necessary information to
   //Parent class SalariedEmployee
Administrator::Administrator ( const string& theName , const string& theSsn ,
         double theYearlySalary ) :
         SalariedEmployee( theName , theSsn , theYearlySalary ) {
   }

//setter functions
void Administrator::SetTitle(string theTitle){
   this->Title = theTitle;
}

void Administrator::SetAreaOfResponsibility(string theArea){
   this->AreaOfResponsibility = theArea;
}

void Administrator::SetNameOfSupervisor(string theSupervisorName){
   this->NameOfSupervisor = theSupervisorName;
}

void Administrator::KeyboardInput(){
   string NamePrompt = "What is the admins Name: ";
   string ssnPrompt = "What is the admins SSN: ";
   string NetPayPrompt = "What is the admins Net Pay: ";
   string SalaryPrompt = "What is the admins Yearly Salary: ";
   string TitlePrompt = "What is the admins Title: ";
   string AreaPrompt = "What is the admins Area of Responsibility: ";
   string SupervisorPrompt = "What is the admins Supervisor's Name: ";

   this->setName(swansonInput::GetString(NamePrompt));
   this->setSsn(swansonInput::GetString(ssnPrompt));
   this->setNetPay(swansonInput::GetDouble(NetPayPrompt));
   this->setSalary(swansonInput::GetDouble(SalaryPrompt));
   this->SetTitle(swansonInput::GetString(TitlePrompt));
   this->SetAreaOfResponsibility(swansonInput::GetString(AreaPrompt));
   this->SetNameOfSupervisor(swansonInput::GetString(SupervisorPrompt));

}

//output functions
void Administrator::print() const;
void Administrator::printCheck() const;


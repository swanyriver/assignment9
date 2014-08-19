/*
 * main.cpp
 *
 *  Created on: Aug 19, 2014
 *      Author: brandon
 */



#include "administrator.h"

#include <iostream>

using namespace std;
using namespace SavitchEmployees;

int main(){

   cout << "here we will create an administrator through inputting his "
         <<"information \nand then We will display his employee ID and pay stub"
         << endl << endl;

   //constructs a default un-initialized admin
   Administrator myAdmin;

   //inflates data fields with provided input
   myAdmin.KeyboardInput();

   //diplays important information about the admin
   myAdmin.print();

   //display admins paystub
   myAdmin.printCheck();
}

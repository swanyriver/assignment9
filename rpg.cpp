/*
 * rpg.cpp
 *
 *  Created on: Aug 19, 2014
 *      Author: brandon
 */

#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>

#include "SwansonLibs/swansonUtils.hpp"

using namespace std;


///////////////////////////////////////////////////////////////////////////
//////////////ABSTRACT (incomplete) CLASSES ///////////////////////////////
////////creature and demon don't define GetSpecies/////////////////////////
///////////////////////////////////////////////////////////////////////////
class Creature{
protected:
   int strength; // How much damage we can inflict
   int hitpoints; // How much damage we can sustain

   stringstream damageLog; //used to keep track of damage modifiers

public:
   virtual string getSpecies() = 0; // Returns type of species

   Creature(int startStrength, int startHitpoints):
      strength(startStrength), hitpoints(startHitpoints){}

   int getStrength(){
      return strength;
   }
   int getHitPoints(){
      return hitpoints;
   }

   //calculates base damage for all creatures;
   int getDamage(){
      int damage = swansonUtil::GetRandomInRange(1,this->strength);
      this->damageLog << getSpecies() << " with strength:" << this->getStrength()
            << " Initial Damage:" << damage;
      return damage;
   }

   string Log(){
      string log = damageLog.str();
      damageLog.str(string()); //empties stream
      return log;
   }

};

class Demon: public Creature{
private:
   int demonDamages;
public:
   Demon(int startStrength, int startHitpoints):
      Creature(startStrength,startHitpoints), demonDamages(0){}

   int getDamage(){
      int damage = Creature::getDamage();
      //5% chance for demon damage
      if(swansonUtil::GetRandomInRange(1,20)==1){
         damage += 50;
         demonDamages++;
         this->damageLog << " Extra Demon Damage:50 ";
      }

      return damage;
   }

   int getDemomDamages(){
      return demonDamages;
   }
};

///////////////////////////////////////////////////////////////////////////
//////////////CONCRETE SUBCLASSES OF CREATURE//////////////////////////////
///////////////////////////////////////////////////////////////////////////
class Balrog: public Demon{
public:
   Balrog(int startStrength, int startHitpoints):
      Demon(startStrength,startHitpoints){}

   string getSpecies(){
      return "Balrog";
   }

   int getDamage(){
      //two attacks
      int attack1, attack2;

      attack1 = Demon::getDamage();
      this->damageLog << " (Attack 1)  \n";

      attack2 = Demon::getDamage();
      this->damageLog << " (Attack 2)  \n";

      return attack1 + attack2;
   }
};

class CyberDemon: public Demon{
public:
   CyberDemon(int startStrength, int startHitpoints):
      Demon(startStrength,startHitpoints){}

   string getSpecies(){
      return "CyberDemon";
   }

   int getDamage(){
      return Demon::getDamage();
   }
};

class Elf: public Creature{
private:
   int elfDamages;
public:
   Elf(int startStrength, int startHitpoints):
      Creature(startStrength,startHitpoints), elfDamages(0){}

   string getSpecies(){
      return "Elf";
   }

   int getDamage(){
      int damage = Creature::getDamage();
      //10% chance for double magic damage
      if(swansonUtil::GetRandomInRange(1,10)==1){
         damage = damage * 2;
         elfDamages++;
         this->damageLog << "\n       Elf Magic, Double Damage! ";
      }
      return damage;
   }

   int GetElfDamages(){
      return elfDamages;
   }
};
class Human: public Creature{
public:
   Human(int startStrength, int startHitpoints):
      Creature(startStrength,startHitpoints){}

   string getSpecies(){
      return "Human";
   }

   int getDamage(){
      return Creature::getDamage();
   }
};

///////////////////////////////////////////////////////////////////////////
///////INT MAIN()   TEST DRIVERS///////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
int main(){

   Human dave(20,200);
   Elf theresa(15,150);
   Balrog jason(10,400);
   CyberDemon chris(25,300);

   swansonUtil::SeedRandom();

   cout << "We have 4 adventures \n"
         << dave.getSpecies() << " with a strength of "
         << dave.getStrength() << " and "
         << dave.getHitPoints() << " hitpoints\n\n"

         << theresa.getSpecies() << " with a strength of "
         << theresa.getStrength() << " and "
         << theresa.getHitPoints() << " hitpoints\n\n"

         << jason.getSpecies() << " with a strength of "
         << jason.getStrength() << " and "
         << jason.getHitPoints() << " hitpoints\n\n"

         << chris.getSpecies() << " with a strength of "
         << chris.getStrength() << " and "
         << chris.getHitPoints() << " hitpoints\n\n";



   ////brute unit testing
   cout << "after testing 1000 cases:" << endl;
   double damageTotal = 0;
   const double NUM_TEST = 1000;

   for(int i=0;i<NUM_TEST;i++){
      damageTotal+=dave.getDamage()/NUM_TEST;
   }
   cout << dave.getSpecies() << " did an average damage of:"
         << int(damageTotal) << endl;
   damageTotal = 0;

   for(int i=0;i<NUM_TEST;i++){
      damageTotal+=theresa.getDamage()/NUM_TEST;
   }
   cout << theresa.getSpecies() << " did an average damage of:"
         << int(damageTotal) << " with " << theresa.GetElfDamages() <<
         " magic attacks"<< endl;
   damageTotal = 0;

   for(int i=0;i<NUM_TEST;i++){
      damageTotal+=jason.getDamage()/NUM_TEST;
   }
   cout << jason.getSpecies() << " did an average damage of:"
         << int(damageTotal) << " with " << jason.getDemomDamages()
         << " demon attacks" << endl;
   damageTotal = 0;

   for(int i=0;i<NUM_TEST;i++){
      damageTotal+=chris.getDamage()/NUM_TEST;
   }
   cout << chris.getSpecies() << " did an average damage of:"
         << int(damageTotal) << " with " << chris.getDemomDamages()
         << " demon attacks" << endl;
   damageTotal = 0;


   dave.Log();
   theresa.Log();
   jason.Log();
   chris.Log();


   cout << "\n\npress any key to continue to verbose output of attacks";
   getchar();

   for(int i=0;i<25; i++){
      int damage;

      cout << "------------------ Attack " << i <<
            "-------------------------------"  << endl;
      damage = dave.getDamage();
      cout << dave.Log() << " Total Damage: " << damage << endl;

      damage = theresa.getDamage();
      cout << theresa.Log() << " Total Damage: " << damage << endl;

      damage = jason.getDamage();
      cout << jason.Log() << " Total Balrog Damage: " << damage << endl;

      damage = chris.getDamage();
      cout << chris.Log() << " Total Damage: " << damage << endl;

   }

}

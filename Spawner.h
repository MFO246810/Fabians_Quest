#include "char.h"
#include <iostream>
#ifndef Spawner_H
#define Spawner_H
using namespace std; 

//derived class of character for spawner
class Spawner:public character{
private: 
int size_of_troops;
int* Num_of_Troops;
int count = 0;

public:
~Spawner(){
  delete[] Num_of_Troops;
}
void printstats() override {
  count = count + 1;
  cout <<"Name: "  << name << endl;
  cout << "Hp: " << hp << endl;
  cout << "Number of Troops: " << size_of_troops << endl;
  if (count == 4){
    cout << "Number of Troops doubled" << endl;
    doubling();
    cout << "There are now: " << size_of_troops << " troops" << endl;
    count = 0;
    gethealing(75);
    cout << "Health restored to: " << hp << endl;
  }
}
void gethealing(int h){
  hp = hp + h;
}
void printstatusmessage() override{
cout << "" << endl;
}
void levelup() override{
  level = level;
  MaxHp = MaxHp;
  Maxspecialability = Maxspecialability;
}
void implementspecialability(int m)override{
}
void setHp(int numHp) override {hp = numHp;}
int getHp() override {return hp;}
int getMaxHp() override {return MaxHp;}
void setMaxHp(int _mhp) override {MaxHp = _mhp;}
void setAttacks1() override{ 
  attacks1("Bladeslash", 20);
}
int getAttacks1dmg() override {
  return attacks1.getDmg() * size_of_troops;
}
void setAttacks2() override{ 
  attacks2("Kick", 10);
}
int getAttacks2dmg() override {
  return attacks2.getDmg() * size_of_troops;
}
void setAttacks3() override{ 
  attacks3("Punch", 20);
}
int getAttacks3dmg() override {
  return attacks3.getDmg() * size_of_troops;
}
void takedamage(int dmg) override{
  hp = hp-dmg;
}
int getspecialability() override{
  return 0;
}
int getMaxspecialability()override {
  return 0;
}
void setspecialability(int num) override{
  size_of_troops = num;
}
void increasespecialability(int SpecAbil) override {
  Maxspecialability = Maxspecialability + SpecAbil;
}
void doubling(){
  Num_of_Troops = new int [size_of_troops];
  for (int i = 0; i < size_of_troops; i++){
    Num_of_Troops[i] = i;
  }
  delete [] Num_of_Troops;
  
  size_of_troops = size_of_troops * 2;
  Num_of_Troops = new int [size_of_troops];
  for (int i = 0; i < size_of_troops; i++){
    Num_of_Troops[i] = i;
  } 
}
};
#endif
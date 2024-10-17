#include "fighterchar.h"
#include <iostream>
#ifndef Orc_of_West_H
#define Orc_of_West_H
using namespace std; 

// derived class of character for orc
class Orc : public fighterchar {
  private:
  bool status = true;

  public: 
void levelup() override{
  level = level;
  MaxHp = MaxHp;
  Maxspecialability = Maxspecialability;
}
void takedamage(int dmg) override{
  hp = hp - dmg;
}
void printstatusmessage() override{
cout << "a" << endl;
}
void implementspecialability(int m)override{
}
void setHp(int numHp)override {hp = numHp;}
int getHp() override {return hp;}
int getMaxHp() override {
    return MaxHp;
  }
void setMaxHp(int mhp) override {
    MaxHp = mhp;
  }
void setspecialability(int num) override {
    defensevalue = num;
    Maxspecialability = num;
  }
int getMaxspecialability() override {
  return Maxspecialability;
}
int getspecialability() override {return defensevalue;}
void setstatus(bool x){
    status = x;
  }

void printstats() override{
    cout << "Name: " << name << endl;
    cout << "Hp: " << hp << endl;
  }
bool getstatus(){return status;}
void increasespecialability(int d) override {defensevalue = defensevalue + d;}

void setAttacks1() override{
    attacks1("Earth Tremor", 50);
    defensevalue = defensevalue - 35;
  }
int getAttacks1dmg() override {
  return attacks1.getDmg();
}
void setAttacks2() override{
    attacks2("Clubslam", 25);
    defensevalue = defensevalue - 25;
  }
int getAttacks2dmg() override {
  return attacks2.getDmg();
}
void setAttacks3() override{
    attacks3("light Club attack", 10);
    defensevalue = defensevalue - 5;
  }
  int getAttacks3dmg() override {
    return attacks3.getDmg();
  }
};








#endif
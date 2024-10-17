#include "char.h"
#include <iostream>
#ifndef Enigineer_H
#define Enigineer_H
using namespace std; 

// derived class of character for enigineer
class Enigineerchar: public character {
  private:
  int parts = 100;

  public: 
  void levelup() override{
    level = level + 1;
    MaxHp = MaxHp + 35;
    Maxspecialability = Maxspecialability + 25;
  }
  void takedamage(int dmg) override{
    hp = hp - dmg;
  }
  void setspecialability(int num) override{
    parts = num;
    Maxspecialability = num;
  }
  int getMaxspecialability() override {
    return Maxspecialability;
  }
  void printstatusmessage() override{
  cout << "Parts at Max" << endl;
  }
  void setHp(int numHp) override {
    hp = numHp;
    MaxHp = numHp;
  }
  int getHp() override {return hp;}
  int getMaxHp() override {
    return MaxHp;
  }
  void setMaxHp(int _mhp) override {
    MaxHp = _mhp;
  }
  void  increasespecialability (int p) override {parts = parts + p;}
  int getspecialability() override {return parts;}
  void printstats() override{
    cout << "Name: " << name << endl;
    cout << "Hp: " << hp << endl;
    cout << "Level: " << level << endl;
    cout << "Parts: " << parts << endl;
  }
  void setAttacks1() override{
    attacks1("Large cannonblast", 100);
  }
  int getAttacks1dmg() override{
    if (parts >= 25){
      return attacks1.getDmg();
    }
    else{
      return 0;
    }
    
  }
  void setAttacks2() override{
    attacks2("Small canonblast", 40);
  }
  int getAttacks2dmg() override{
    if (parts >= 15){
      return attacks2.getDmg();
    }
    else{
      return 0;
    }
  }
  void setAttacks3() override{
    attacks3("Gunshot", 10);
  }
  int getAttacks3dmg() override{
    if (parts >= 5){
      return attacks3.getDmg();
    }
    else{
      return 0;
    }
  }
  void implementspecialability(int p)override{
    parts = parts - p;
  }
};

#endif
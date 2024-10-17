#include "char.h"
#include <iostream>
#ifndef wizardchar_H
#define wizardchar_H
using namespace std; 

// derived class of character for wizard 
class wizardchar : public character{
  private:
  int mana = 100;

  public:
  void takedamage(int dmg) override{
    hp = hp - dmg;
  }
  void levelup() override{
    level = level + 1;
    MaxHp = MaxHp + 25;
    Maxspecialability = Maxspecialability + 25;
  }
  void printstatusmessage() override{
  cout << "Mana at Max" << endl;
  }
  void setspecialability(int num) override{
    mana = num;
    Maxspecialability = num;
  }
  int getMaxspecialability() override {
    return Maxspecialability;
  }
  void increasespecialability(int m) override {mana = mana + m;}
  int getspecialability() override {return mana;}
  void setHp(int numHp) override {
    hp = numHp;
    MaxHp = numHp;
  }
  int getHp(void) override {return hp;}
  int getMaxHp() override {
    return MaxHp;
  }
  void setMaxHp(int _mhp) override {
    MaxHp = _mhp;
  }
  void printstats() override {
    cout << "Name: " << name << endl;
    cout << "Level: " << level << endl;
    cout << "Hp: " << hp << endl;
    cout << "Mana: "<< mana << endl;
  }
  void setAttacks1() override {
    attacks1("Fireball", 100);
  }
  int getAttacks1dmg() override {
    if (mana >= 25){
      return attacks1.getDmg();
    }
    else{
      return 0;
    } 
  }

  void setAttacks2() override {
    attacks2("Thunderstruck", 50);
  }
  int getAttacks2dmg() override {
    if (mana >= 15){
      return attacks2.getDmg();
    }
    else{
      return 0;
    }
  }
  void setAttacks3() override {
    attacks3("Eldritch blast", 25);
  }
  int getAttacks3dmg() override {
    if (mana >= 5){
      return attacks3.getDmg();
    }
    else{
      return 0;
    }
    
  }
  void implementspecialability(int m) override {
    mana = mana - m;
  }
  };

#endif

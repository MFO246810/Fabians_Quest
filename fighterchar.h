#include "char.h"
#include <iostream>
#ifndef fighterchar_H
#define fighterchar_H
using namespace std; 

// derived class of character for fighter
class fighterchar: public character {
  protected:
  int defensevalue = 100;

  public: 
  void levelup() override{
    level = level + 1;
    MaxHp = MaxHp + 50;
    Maxspecialability = Maxspecialability + 25;
  }
  void takedamage(int dmg) override{
    hp = hp - (dmg/2);
  }
  void printstatusmessage() override{
  cout << "A fighter has no special property you always take half damage" << endl;
  }
  void setspecialability(int num) override{
    defensevalue = num;
    Maxspecialability = num;
  }
  int getMaxspecialability() override {
    return Maxspecialability;
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
  void increasespecialability(int d) override {defensevalue = defensevalue + d;}
  int getspecialability() override {return defensevalue;}
  void printstats() override{
    cout << "Name: " << name << endl;
    cout << "Hp: " << hp << endl;
    cout << "Level: " << level << endl;
    cout << "No special ability you take half damage" << endl;
  }
  void setAttacks1() override{
    attacks1("Bladestorm", 50);
    defensevalue = defensevalue - 25;
  }
  int getAttacks1dmg() override{
    return attacks1.getDmg();
  }
  void setAttacks2() override{
    attacks2("Bladeslash", 20);
    defensevalue = defensevalue - 15;
  }
  int getAttacks2dmg() override{
    return attacks2.getDmg();
  }
  void setAttacks3() override{
    attacks3("lightblade attack", 10);
    defensevalue = defensevalue - 5;
  }
  int getAttacks3dmg() override{
    return attacks3.getDmg();
  }
void implementspecialability(int m)override{
}
};




#endif
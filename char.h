#ifndef char_H
#define char_H
#include <iostream>
#include <string>
using namespace std;

//class definition for character and attack
class attacks {
  private:
  string attackname;
  int dmg;

  public:
  attacks(){
    attackname = "";
    dmg = 0;
  }
  attacks(string _name, int damage){
    attackname = _name;
    dmg = damage;
  }
  void operator()(string atk, int dg){
    attackname = atk;
    dmg = dg;
  }
  void setAttackname(string atkname){attackname = atkname;}
  string getAttackname(){return attackname;}
  void setDmg(int _dmg){dmg = _dmg;}
  int getDmg(){return dmg;}
};

class character {
  protected:
  int hp;
  int healingpotion = 0;
  int level = 1;
  int MaxHp;
  int Maxspecialability;
  string name; 
  attacks attacks1;
  attacks attacks2;
  attacks attacks3;

  public: 
  character(){
    name = "";
    hp = 0;
  }
  void setName(string _name){name = _name;}
  string getName(){return name;} 
  virtual void takedamage(int dmg){
    hp = hp - dmg;
  }
  virtual void printstatusmessage(){
    cout << "Special property at Max" << endl;
  }
  void gethealing(int h){
    hp = hp + h;
  }
  virtual void printstats(){
    cout << name << endl;
    cout << hp;
  }
  virtual void levelup() = 0;
  void setlevel(int _level){level = _level;}
  int getlevel(){return level;}
  void sethealthpotion(int _hpotion){
    healingpotion = healingpotion + _hpotion;
  }
  int gethealthpotion(){return healingpotion;}
  virtual void setHp(int numHp) = 0;
  virtual void implementspecialability(int m) = 0;
  virtual int getHp() = 0;
  virtual int getMaxHp() = 0;
  virtual void setMaxHp(int _mhp) = 0;
  virtual void setAttacks1() = 0;
  virtual int getspecialability() = 0;
  virtual int getMaxspecialability() = 0;
  virtual void setspecialability(int num) = 0;
  virtual void increasespecialability(int SpecAbil) = 0;
  string getAttacks1name() {
    return attacks1.getAttackname();
  }
  virtual int getAttacks1dmg() {
    return attacks1.getDmg();
  }
  virtual void setAttacks2() = 0;
  string getAttacks2name() {
    return attacks2.getAttackname();
  }
  virtual int getAttacks2dmg() {
    return attacks2.getDmg();
  }
  virtual void setAttacks3() = 0;
  string getAttacks3name() {
    return attacks3.getAttackname();
  }
  virtual int getAttacks3dmg() {
    return attacks3.getDmg();
  }
};




#endif
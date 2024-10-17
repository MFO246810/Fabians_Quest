#include "char.h"
#include <iostream>
#ifndef dragon_H
#define dragon_H
using namespace std; 

// derived class of chracter Dragon
class Dragon: public character{
private: 
int m;
public: 
void setHp(int numHp) override {
  hp = numHp;
}
int getHp() override {
  return hp;
}
int getMaxHp() override{return MaxHp;}
void setMaxHp(int _mhp) override {MaxHp = _mhp;}
void setAttacks1() override{
  attacks1("Flame breath", 80);
}
int getAttacks1dmg() override {
  return attacks1.getDmg();
}
void setAttacks2() override{
  attacks2("Bite", 60);
}
int getAttacks2dmg() override {
  return attacks2.getDmg();
}
void setAttacks3() override{
  attacks3("Clawstrike", 50);
}
int getAttacks3dmg() override {
  return attacks3.getDmg();
}
int getspecialability() override {
  return 0;
}
int getMaxspecialability() override {
  return 0;
}
void setspecialability (int num) override {
  m = num;
}
void increasespecialability(int SpecAbil) override{
  m = SpecAbil;
}
void implementspecialability(int m)override{
}
void takedamage(int dmg) override {
  hp = hp - dmg;
}
void printstatusmessage() override {
  cout << "Special property at Max" << endl;
}
void printstats() override {
  cout <<"Name: "<< name << endl;
  cout << "Hp: "<< hp << endl;
}
void levelup() override {
  level = 1;
}
};

#endif
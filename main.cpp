#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h> 
#include <cctype>
#include "char.h"
#include "wizardchar.h"
#include "fighterchar.h"
#include "Enigineer.h"
#include "Orc.h"
#include "Spawner.h"
#include "dragon.h"
using namespace std;

//Writes the save function 
void writer(string filename, char choice, int goal, character* c);

// Handles all the combat stuff
int round(character* c, character* b);

//Writes the boss attack function
void Bossatk(character* c, character* b, int round, int Bossatk, string menuChoice, int d1, int d2);

//restore a chracter full health
void restore(character* c);

//Works on savepoints 
void savePoint(character* c, char Characterchoice, int goal);

// Sets healing potion
void sethealingpotion(character* c, int number_of_healingpotion);

// Handles suprise attacks 
void supriseattack(character* c, character* b);

int main() {
   string title = 
    R"(
   /$$$$$$$$       /$$       /$$                                       /$$$$$$                                  /$$    
  | $$_____/      | $$      |__/                                      /$$__  $$                                | $$    
  | $$    /$$$$$$ | $$$$$$$  /$$  /$$$$$$  /$$$$$$$   /$$$$$$$       | $$  \ $$ /$$   /$$  /$$$$$$   /$$$$$$$ /$$$$$$  
  | $$$$$|____  $$| $$__  $$| $$ |____  $$| $$__  $$ /$$_____//$$$$$$| $$  | $$| $$  | $$ /$$__  $$ /$$_____/|_  $$_/  
  | $$__/ /$$$$$$$| $$  \ $$| $$  /$$$$$$$| $$  \ $$|  $$$$$$|______/| $$  | $$| $$  | $$| $$$$$$$$|  $$$$$$   | $$    
  | $$   /$$__  $$| $$  | $$| $$ /$$__  $$| $$  | $$ \____  $$       | $$/$$ $$| $$  | $$| $$_____/ \____  $$  | $$ /$$
  | $$  |  $$$$$$$| $$$$$$$/| $$|  $$$$$$$| $$  | $$ /$$$$$$$/       |  $$$$$$/|  $$$$$$/|  $$$$$$$ /$$$$$$$/  |  $$$$/
  |__/   \_______/|_______/ |__/ \_______/|__/  |__/|_______/         \____ $$$ \______/  \_______/|_______/    \___/  
                                                                           \__/                                        
    )";

    cout << title << endl;
  character* wizard = new wizardchar;
  character* fighter = new fighterchar;
  character* enigineer = new Enigineerchar;
  // creates the different chracter types 
  cout << "Choose your character: " << endl;
  cout << "1. Wizard (Select by pressing the 'W' key)" << endl;
  cout << "2. Fighter (Select by pressing the 'F' key)" << endl;
  cout << "3. Enigineer (Select by pressing the 'E' key)" << endl;
  cout << "4. Exit (Select by pressing the 'Q' key" << endl;
  cout << "5. Open savefile (Select by pressing the 'S' key)" << endl;
  // prints out the different options for the user to choose from
  char choice;
  int acceptingquestchoice;
  int directionchoice;
  int goal = 0;
  int result = 2;
  string name;
  cin >> choice;
  cin.ignore();
  if (choice != 'W' && choice != 'F' && choice != 'E' && choice != 'S' && choice != 'Q'){
    cout << "Invalid choice. Please try again." << endl;
    cin >> choice;
    cin.ignore();
  }
  // if the user chooses a character that is not one of the options, it will print out an error message and` ask the user to choose again
  while ((choice == 'W') || ( choice == 'w') || (choice == 'F') ||( choice == 'f') || (choice == 'E') || ( choice == 'e') || (choice == 'S')||(choice == 's') || (choice == 'Q')||(choice == 'q')){
    choice = toupper(choice);
  if ((choice == 'W') ||( choice == 'w')){
    cout << "Give your Wizard a name: " << endl;
    getline(cin, name);
    string art = 
      R"(


    :                                         
    ##                                         
    :@@-                                         
    -@@*                                          
    .                                -@@@:                                          
    .+@@@+.                            =@@@@                                           
    =@@@@@@@-                          +@@@@#                                           
    :@@@@@@@@*                         *@@@@@.                                           
    =@@@@@@@@.                       .%@@@@@@                                            
    :@@@@@@:                       -@@@@@@@#                         .+#*=.             
    #@@@*                        =@@@@@@@@+                        @@@@@@@.            
    %@@-                       *@@@@@@@@@:                        +@@@@@%             
    @@%                       @@@@@@@@@@@                          @@@@@+             
    =@@@@#                     =@@@@@@@@@@@#                       -@@@@@@@#=-           
    +@@@@@@@:                 +@@@@@@@@@@@@=                       .%@@@@@@@@@.          
    .%@@@@@@@.                -@@@@@@@@@@@@@:                      :#-%+:=*-*+ **         
    =@@@@@@@#                -@@@@@@@@@@@@@*                       **#@@@%@@@@@@*         
    =@@@@@@=                %@@@@@@@@@@@@@-                          :@@%#%@#            
    *@@@@@@@*              .%@@@@@@@@@@@%.                       -@@@*=@@#:*@@#         
    :@@@@@@@@@@=           :@@@@@@@@@@@@@#.                       +@@.      -@=         
    .@@@@@@@@@@@%.         @@@@@@@@@@@@@@%.                       +@%    *+ @@%.        
    .@@@@@@@@@@@@@-.      @@@@@@@@@@@@@@@=                       :@@@+...#@@@@#         
    .@@@@@@@@@@@@@@@@.    @@@@@@@@@@@@@@@:                       -@@@@@@@@@.            
    .@@@@@@@@@@@@@@@@@@%@@@@@@@@@@@@@@@@@@#=-.                  .@@@@@@@@*              
    -@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*=              .#@@@@@++:               
    #@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#=      =*%@@@@@@@%                   
    #@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#:=#@@@@@@@@@@#                    
    .%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@:                     
    :@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%.                     
    =@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%.                     
    +@@#=@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%.                     
    +@@: =@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@+                     
    +@@   -@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@+                     
    *@%    -@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*                     
    *@%    -@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%.                    
    *@@    *@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%.                    
    .#@%   =@@@@@@@@@@@@#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%.                    
    .%@+  .%@@@@@@@@@@@- #@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@:                    
    :@@-  -@@@@@@@@@@@=  #@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@:                    
    .@@:  -@@@@@@@@@@=   #@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@:                    
    =@@.    *@@@@@@@:   -@@@@@@@@@@@@@@@@@@@@@@@@@@@%@@@@@@@@@@@@@@@@:                    
    #@@.      :%%+      =@@@@@@@@@@@@@@@@@@@@@@@@@@@::@@@@@@@@@@@@@@#                     
    *@%.                =@@@@@@@@@@@@@@@@@@@@@@@@@@@@ -@@@@@@@@@@@@@+                     
    %@=                 *@@@@@@@@@@@@@@@@@@@@@@@@@@@@+ -@@@@@@@@@@@%.                     
    .@@-                 *@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#--@@@@@@@@@@+                      
    .@@:                 #@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@* :@@@@@@@@=                       
    .@@:                 #@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*   .::.                           
    .@@:                :@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-                                 
    .@@:                *@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@:                                
    =@@:               .@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@                                
    #@*                :@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@                           :   
    .@@=                %@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.                  -#: .-@@=  
    -@%.               =@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-                 :@@@@@@@=  
    @@#               =@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%-                +@@@@@@#  
    .@@*              -@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=               =@@@@@@%. 
    .@@=              %@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.               +@@@@@@@- 
    -@@.             -@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.             +@@@@@@@@@# 
    #@@              -@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@            #@@@@@@@@@@@@=
    %@%               :@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-          .%@@@@@@@@@@@@@=
    @@*                %@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.          *@@@@@@@@@@@@@@.
    @@*              .#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-        :@@@@@@@@@@@@@@: 
    :@@:             .%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@+.     #@@@@@@@@@@@@@@. 
    +@@              :@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*    =@@@@@@@@@@@@@@%. 
    .%@@              -@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-.  *@@@@@@@@@@@@#@@. 
    :@@#             #@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@==@@@@@@@@@@@@@#@. 
    +@@*      :%@%%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%.
    #@@*      @@@@@@@@@@@@@@@@@*@@@@@@@@@@@@@@* .*@@@@@@@@@@@@@@@@@@@@@@@#::==+#%#+*+-:.  .    
    :@@@-         +@@@@@@@@@@=           .  .            -*%@@@@@#                              
    -*=                                                                                        

      )";

    cout << art << endl;
    wizard->setName(name);
    wizard->setHp(500);
    wizard->setspecialability(100);
    wizard->setMaxHp(500);
    wizard->setAttacks1();
    wizard->setAttacks2();
    wizard->setAttacks3();
    break;
  }
  if ((choice == 'F') ||( choice == 'f')){
    cout << "Give your fighter a name: " << endl;
    getline(cin, name);
    cout << R"(
        /$$$$$$$$ /$$           /$$         /$$                        
       | $$_____/|__/          | $$        | $$                        
       | $$       /$$  /$$$$$$ | $$$$$$$  /$$$$$$    /$$$$$$   /$$$$$$ 
       | $$$$$   | $$ /$$__  $$| $$__  $$|_  $$_/   /$$__  $$ /$$__  $$
       | $$__/   | $$| $$  \ $$| $$  \ $$  | $$    | $$$$$$$$| $$  \__/
       | $$      | $$| $$  | $$| $$  | $$  | $$ /$$| $$_____/| $$      
       | $$      | $$|  $$$$$$$| $$  | $$  |  $$$$/|  $$$$$$$| $$      
       |__/      |__/ \____  $$|__/  |__/   \___/   \_______/|__/      
                         /$$  \ $$                                        
                        |  $$$$$$/                                        
                         \______/                                         
        //                                                                  
    )" << endl;
    fighter->setName(name);
    fighter->setHp(400);
    fighter->setspecialability(100);
    fighter->setMaxHp(400);
    fighter->setAttacks1();
    fighter->setAttacks2();
    fighter->setAttacks3();
    break;
  }
  if ((choice == 'E') ||( choice == 'e')){
    cout << "Give your Enigineer a name: " << endl;
    getline(cin, name);
    cout << R"(
       /$$$$$$$$           /$$           /$$                                        
      | $$_____/          |__/          |__/                                        
      | $$       /$$$$$$$  /$$  /$$$$$$  /$$ /$$$$$$$   /$$$$$$   /$$$$$$   /$$$$$$ 
      | $$$$$   | $$__  $$| $$ /$$__  $$| $$| $$__  $$ /$$__  $$ /$$__  $$ /$$__  $$
      | $$__/   | $$  \ $$| $$| $$  \ $$| $$| $$  \ $$| $$$$$$$$| $$$$$$$$| $$  \__/
      | $$      | $$  | $$| $$| $$  | $$| $$| $$  | $$| $$_____/| $$_____/| $$      
      | $$$$$$$$| $$  | $$| $$|  $$$$$$$| $$| $$  | $$|  $$$$$$$|  $$$$$$$| $$      
      |________/|__/  |__/|__/ \____  $$|__/|__/  |__/ \_______/ \_______/|__/      
                               /$$  \ $$                                            
                              |  $$$$$$/                                            
                               \______/                                             

        )" << std::endl;
    enigineer->setName(name);
    enigineer->setHp(650);
    enigineer->setspecialability(100);
    enigineer->setMaxHp(650);
    enigineer->setAttacks1();
    enigineer->setAttacks2();
    enigineer->setAttacks3();
    break;
  }
  if ((choice == 'S')||(choice == 's')){
    string filename;
    string addon = ".txt";
    cout << "Enter the name of the savefile: " << endl;
    cin >> filename;
    cin.ignore();
    ifstream savefile(filename + addon);
    if (savefile.is_open()){
      char Characterchoice;
      int level;
      int goal2;
      string name;
      int maxhp;
      int hp;
      int healingpotion;
      int specialability;
      savefile >> Characterchoice;
      savefile >> goal2;
      savefile >> level;
      savefile >> healingpotion;
      savefile >> name;
      savefile >> maxhp;
      savefile >> hp;
      savefile >> specialability;
      goal = goal2;
      choice = Characterchoice;
      if (Characterchoice == 'W'){
        wizard->setlevel(level);
        wizard->setName(name);
        wizard->setHp(hp);
        wizard->setspecialability(specialability);
        wizard->setMaxHp(maxhp);
        wizard->sethealthpotion(healingpotion);
        wizard->setAttacks1();
        wizard->setAttacks2();
        wizard->setAttacks3();
        cout << "Your character has been loaded from the savefile." << endl;
        break;
      }
      if (Characterchoice == 'F'){
        fighter->setlevel(level);
        fighter->setName(name);
        fighter->setHp(hp);
        fighter->setspecialability(specialability);
        fighter->setMaxHp(maxhp);
        fighter->sethealthpotion(healingpotion);
        fighter->setAttacks1();
        fighter->setAttacks2();
        fighter->setAttacks3();
        cout << "Your character has been loaded from the savefile." << endl;
        break;
      }
      if (Characterchoice == 'E'){
        enigineer->setlevel(level);
        enigineer->setName(name);
        enigineer->setHp(hp);
        enigineer->setspecialability(specialability);
        enigineer->setMaxHp(maxhp);
        enigineer->sethealthpotion(healingpotion);
        enigineer->setAttacks1();
        enigineer->setAttacks2();
        enigineer->setAttacks3();
        cout << "Your character has been loaded from the savefile." << endl;
        break;
      }
    }
  }
  if ((choice == 'Q')||(choice == 'q')) {
    break;
    return 0;
  }
}
  cout << "Welcome to Fabian's Quest " << name << endl;
  cout << "The hero of the seven lands, defeater of Elrog the Great, would-be-king to the northern lands, Fabian, has failed in his most recent adventure." << endl;
  cout << "The King has chosen you as his replacement, granting you blessings and equipment before embarking on this perilous quest." << endl;
  cout << "Do you accept the quest: " << endl;
  cout << "1 for Yes" << endl;
  cout << "2 for No" << endl;
  // Story block
  cin >> acceptingquestchoice;
  if (acceptingquestchoice == 1){
    cout << "You have accepted the quest, and embarked on your journey." << endl;
  }
  if (acceptingquestchoice == 2){
    cout << "You have declined the quest, and lost your blessings." << endl;
    cout << "Game Over" << endl;
    return 0;
  }
  for (int i = 0; i < 56; i++) {
    cout << "-";
  }
  cout << endl << endl;
  cout << "|                  Quest details:                      |" << endl;
  cout << "|    Goal 1: Kill the great Orc of the West            |" << endl;
  cout << "|    Goal 2: Destroy the attacking army of Malragnum   |" << endl;
  cout << "|    Goal 3: Defeat the being named Thragg!!!!         |" << endl;
  cout << "************Press 1 to begin your journey.**************" << endl;
  // Story block
  for (int i = 0; i < 56; i++) {
    cout << "-";
  }
  
  cout << endl << endl;
  while (goal != 100){
    if (goal == 0){
      cin >> goal;
      cin.ignore();
    }
    // checks the goal put in and makes sure it is valid
    if (choice == 'W'){
      if (wizard->getlevel() != goal){
        cout << "Choose another goal" << endl;
        cin >> goal;
        cin.ignore();
      }
    }
    if (choice == 'F'){
      if (fighter->getlevel() != goal){
        cout << "Choose another goal" << endl;
        cin >> goal;
        cin.ignore();
      }
    }
    if (choice == 'E'){
      if (enigineer->getlevel() != goal){
        cout << "Choose another goal" << endl;
        cin >> goal;
        cin.ignore();
      }
    }
    if ((goal != 1) && (goal != 2) && (goal != 3)){
      cout << "Not an option. Please choose again" << endl;
      cin >> goal;
      cin.ignore();
    }
    // Handles the goals needed for quest one
    if (goal == 1){
      // Handles the savepoint 
      if (choice == 'W'){
        savePoint(wizard, choice, goal);
      }
      if (choice == 'F'){
        savePoint(fighter, choice, goal);
      }
      if (choice == 'E'){
        savePoint(enigineer, choice, goal);
      }
      cout << endl;
      character* Orc_of_the_west = new Orc;
      // Handles the cretion for the orc boss
      Orc_of_the_west->setName("Orc_of_West");
      Orc_of_the_west->setHp(800);
      Orc_of_the_west->setMaxHp(800);
      Orc_of_the_west->setAttacks1();
      Orc_of_the_west->setAttacks2();
      Orc_of_the_west->setAttacks3();
      cout << "You have chosen to kill the Orc of the West. " << endl;
      cout << R"(
                                C@@@>                                                                      
                               /@@@/                                                                      
                               Ik@a^                  +w@@m- ,                                            
                                 J{                  Y@@@@@@@                                             
                                 zY             .`   W@@@@@@J     lj                                      
                                 )a^             ]b- j@@@@@@[   +#X ,_l                                   
                                 ld"          ^|J}*@[.M@@@@@@  ]$@bW){                                    
                                 .d;          ,-;b@@@kkW@@@@@@@@@@wYp                                     
                                  w1          I*bZ@@@@@@@@@@@@@@@@@@j>                                    
                                 (@@$}         >M@@@@@@@@@@@@@@@@@@@@j                                    
                                 >M@@@$Z;     [@@@@@@@@@@@@@@@@@@@@@$                                     
                                  >B!~@@@@@@$@@@@@@@@@@@@@@@@@@@@@@@@M~                                   
                                   M;   j@@@@@@@@@w@@@@@@@@@@@@@@@@@@M-                                   
                                   #t      f@@@Y   *@@@@@@@@@@@@X' k@@@@)                                 
                                   Q#               (@@@@@@@@@@@/  a@@@m:                                 
                                   _W               k@@@@@@@@@@ai  c@@@J`                                 
                                   ^@                @@@@@@@@@@@/   @@@j                                  
                                    @I             )@@@@@@@@@@@@*+  @@ai                                  
                                    @z           ,a@@@@@@@@@@@@@@@!B@@*~                                  
                                    vo           C@@@@@@@@@@@@@@@@@1mwv^                                  
                                    iB          ~*@@@@@@@@@@@@@@@@@@.                                     
                                    '@          v@@@@@@@@@@@@@@@@@@[;                                     
                                     @+         z@@@@@@a@@@@@@@@@@@                                       
                                     WC        {@@@@@x iM@@@)d@@@@@}                                      
                                     tp       I@@@@@^   f@$<  r@@@@@                                      
                                     la       :*@@@@     w-   ~@@@@*                                      
                                     `W`      |@@@@@@     +   (@@@@@@1                                    
                                     i@m      O@@@@@@        `h@@@@@@O                                    
                                     :@d      ^d@@@@'         la@@@@$,                                    
                                     '@@/      |@@@@           +M@@@$                                     
                                      w@j      {@@@+            n@@@$                                     
                                      >@j      +@@@`             0@@@                                     
                                      .Qj      1@@@`             ;M@$;                                    
                                       _j   #@@@@@@J              a@@@x                                   
                                       ';   t#$ar[-               d@@@@1
      )";
      cout << "Head to the western forest" << endl;
      cout << "You have arrived at the western forest." << endl;
      cout << "You see a fork in the path." << endl;
      cout << "Do you go left or right? (1 for left and 2 for right)" << endl;
      //** Handles the choice for the fork in the path
      cin >> directionchoice;
      cin.ignore();
      if (directionchoice == 2){
        cout << "You have chosen to go right." << endl;
        cout << "You walk down the path " << endl;
        cout << "You find a dead soldier" << endl;
        cout << "Do you search his body (1 for yes and 2 for no)" << endl;
        cin >> directionchoice;
        cin.ignore();
        if (directionchoice == 1){
          cout << "As you search his body you find a health potion" << endl;
          if (choice == 'W'){
            sethealingpotion(wizard, 1);
          }
          if (choice == 'F'){
            sethealingpotion(fighter, 1);
          }
          if (choice == 'E'){
            sethealingpotion(enigineer, 1);
          }
          // Healing potion accumulated 
          cout << "You have obtained a health potion" << endl;
          cout << "You walk back to the path" << endl;
          cout << "You encounter a cave." << endl;
          cout << "Do you enter the cave? (1 for yes and 2 for no)" << endl;
          // Handles the choice for the cave
          cin >> directionchoice;
          cin.ignore();
            if (directionchoice == 2){
              cout << "You have chosen to go around the cave." << endl;
              cout << "As you continue to walk around the cave." << endl;
              cout << "You hear a loud roar." << endl;
              cout << "It seems like your walk around the cave has awoken what is inside" << endl;
              cout << "A huge arm smashes through the cave and grabs you." << endl;
              cout << "It then slams you to the floor doing 50 damage to you" << endl;
              // Damage to player due to story action
              if (choice == 'W'){
                wizard->takedamage(50);
                result = round(wizard, Orc_of_the_west);
              }
              if (choice == 'F'){
                fighter->takedamage(50);
                result = round(fighter, Orc_of_the_west);
              }
              if (choice == 'E'){
                enigineer->takedamage(50);
                result = round(enigineer, Orc_of_the_west);
              }
              // Handles the take damage function and then initiates the round function which handles combat
            }
            if (directionchoice == 1){
              cout << "You have chosen to enter the cave." << endl;
              cout << "You find a giant orc sleeping in the cave." << endl;
              cout << "It matches the description of the orc of the west" << endl;
              cout << "Do you fight the orc? (1 for yes and 2 for no)" << endl;
              cin >> directionchoice;
              cin.ignore();
              if (directionchoice == 1){
                if (choice == 'W'){
                  result = round(wizard, Orc_of_the_west);
                }
                if (choice == 'F'){
                  result = round(fighter, Orc_of_the_west);
                }
                if (choice == 'E'){
                  result = round(enigineer, Orc_of_the_west);
                }
                directionchoice = 3;
              }
              if (directionchoice == 2){
                cout << "You have chosen to run away from the orc." << endl;
                cout << "This wakes up the Orc and he is very mad" << endl;
                cout << "He grabs you and toss you on the floor." << endl;
                cout << "You take damage and die" << endl;
                cout << "Game Over" << endl;
                if (choice == 'W'){
                  wizard->printstats();
                }
                if (choice == 'F'){
                  fighter->printstats();
                }
                if (choice == 'E'){
                  enigineer->printstats();
                }
                // Handles the death of the player and the gameover
                return 0;
              }
          }
        }
      }
      if (directionchoice == 1){
        cout << "You have chosen to go left." << endl;
        cout << "You encounter a cave." << endl;
        cout << "Do you enter the cave? (1 for yes and 2 for no)" << endl;
        cin >> directionchoice;
        cin.ignore();
        if (directionchoice == 2){
          cout << "You have chosen to go around the cave." << endl;
          cout << "As you continue to walk around the cave." << endl;
          cout << "You hear a loud roar." << endl;
          cout << "It seems like your walk around the cave has awoken what is inside" << endl;
          cout << "A huge arm smashes through the cave and grabs you." << endl;
          cout << "It then slams you to the floor doing 50 damage to you" << endl;
          if (choice == 'W'){
            wizard->takedamage(50);
            result = round(wizard, Orc_of_the_west);
          }
          if (choice == 'F'){
            fighter->takedamage(50);
            result = round(fighter, Orc_of_the_west);
          }
          if (choice == 'E'){
            enigineer->takedamage(50);
            result = round(enigineer, Orc_of_the_west);
          }
        }
        if (directionchoice == 1){
          cout << "You have chosen to enter the cave." << endl;
          cout << "You find a giant orc sleeping in the cave." << endl;
          cout << "It matches the description of the orc of the west" << endl;
          cout << "Do you fight the orc? (1 for yes and 2 for no)" << endl;
          cin >> directionchoice;
          cin.ignore();
          if (directionchoice == 1){
            if (choice == 'W'){
              result = round(wizard, Orc_of_the_west);
            }
            if (choice == 'F'){
              result = round(fighter, Orc_of_the_west);
            }
            if (choice == 'E'){
              result = round(enigineer, Orc_of_the_west);
            }
          }
          if (directionchoice == 2){
            cout << "You have chosen to run away from the orc." << endl;
            cout << "This wakes up the Orc and he is very mad" << endl;
            cout << "He grabs you and toss you on the floor." << endl;
            cout << "You take damage and die" << endl;
            cout << "Game Over" << endl;
            wizard->printstats();
            return 0;
          }
        }
      }
    }
    if (result == 0){
      cout << "Game over, You have been defeated by the orc of the west" << endl;
      if (choice == 'W'){
        wizard->printstats();
      }
      if (choice == 'F'){
        fighter->printstats();
      }
      if (choice == 'E'){
        enigineer->printstats();
      }
      return 0;
    }
    if (result == 1){
      goal = goal + 1;
      cout <<"You have defeated the orc of the west" << endl;
      cout << "You receive 3 healing potion" << endl; 
      cout << "You have also leveled up" << endl;
      if (choice == 'W'){
        wizard->levelup();
        restore(wizard);
        wizard->printstats();
        sethealingpotion(wizard, 3);
      }
      if (choice == 'F'){
        fighter->levelup();
        restore(fighter);
        fighter->printstats();
        sethealingpotion(fighter, 3);
      }
      if (choice == 'E'){
        enigineer->levelup();
        restore(enigineer);
        enigineer->printstats();
        sethealingpotion(enigineer, 3);
      }
    }

    if(goal == 2){
      character* Troops_of_Malragnum = new Spawner;
      cout << R"(
           /$$$$$$                                                     /$$$$$$        /$$      /$$           /$$
           /$$__  $$                                                   /$$__  $$      | $$$    /$$$          | $$
          | $$  \ $$  /$$$$$$  /$$$$$$/$$$$  /$$   /$$        /$$$$$$ | $$  \__/      | $$$$  /$$$$  /$$$$$$ | $$  /$$$$$$  /$$$$$$   /$$$$$$  /$$$$$$$  /$$   /$$ /$$$$$$/$$$$
          | $$$$$$$$ /$$__  $$| $$_  $$_  $$| $$  | $$       /$$__  $$| $$$$          | $$ $$/$$ $$ |____  $$| $$ /$$__  $$|____  $$ /$$__  $$| $$__  $$| $$  | $$| $$_  $$_  $$
          | $$__  $$| $$  \__/| $$ \ $$ \ $$| $$  | $$      | $$  \ $$| $$_/          | $$  $$$| $$  /$$$$$$$| $$| $$  \__/ /$$$$$$$| $$  \ $$| $$  \ $$| $$  | $$| $$ \ $$ \ $$
          | $$  | $$| $$      | $$ | $$ | $$| $$  | $$      | $$  | $$| $$            | $$\  $ | $$ /$$__  $$| $$| $$      /$$__  $$| $$  | $$| $$  | $$| $$  | $$| $$ | $$ | $$
          | $$  | $$| $$      | $$ | $$ | $$| $$  | $$      | $$  | $$| $$            | $$ \/  | $$|  $$$$$$$| $$| $$     |  $$$$$$$|  $$$$$$$| $$  | $$|  $$$$$$/| $$ | $$ | $$
          |__/  |__/|__/      |__/ |__/ |__/ \____  $$       \______/ |__/            |__/     |__/ \_______/|__/|__/      \_______/ \____  $$|__/  |__/ \______/ |__/ |__/ |__/
                                             /$$  | $$                                                                               /$$  \ $$
                                            |  $$$$$$/                                                                              |  $$$$$$/
                                            \______/                                                                                \______/
                                                                                                                                                                              
        )" << endl;
      // Army of malragnum creation 
      Troops_of_Malragnum->setName("Troops_of_Malragnum");
      Troops_of_Malragnum->setHp(600);
      Troops_of_Malragnum->setMaxHp(600);
      Troops_of_Malragnum->setAttacks1();
      Troops_of_Malragnum->setAttacks2();
      Troops_of_Malragnum->setAttacks3();
      Troops_of_Malragnum->setspecialability(2);
      cout << endl;
      cout << "After you leave the cave a royal carriage awaits you outside" << endl;
      if (choice == 'W'){
        savePoint(wizard, choice, goal);
      }
      if (choice == 'F'){
        savePoint(fighter, choice, goal);
      }
      if (choice == 'E'){
        savePoint(enigineer, choice, goal);
      }
      // Another savepoint
      cout << endl;
      cout << "The guard of the carriage calls you into the cariage" << endl;
      cout << "He says 'I am here to take you to the front lines to battle the army of Malragnum'" << endl;
      cout << "He says 'Get in the carriage and I will take you over there'" << endl;
      cout << "Do you join the carriage? (1 for yes and 2 for no)" << endl;
      cin >> directionchoice;
      // story block
      cin.ignore();
      if (directionchoice == 1){
        cout << "You have chosen to join the carriage" << endl;
        cout << "The Carriage begins to travel and travels to the front lines" << endl;
        cout << "You arrive at the front line the where you find hordes of troops approaching a small group of soldiers" << endl;
        cout << "Do you fight the troops? (1 for yes and 2 for no)" << endl;
        cin >> directionchoice;
        cin.ignore();
        // simulates combat between the army and player
        if (directionchoice == 1){
          if (choice == 'W'){
            result = round(wizard, Troops_of_Malragnum);
          }
          if (choice == 'F'){
            result = round(fighter, Troops_of_Malragnum);
          }
          if (choice == 'E'){
            result = round(enigineer, Troops_of_Malragnum);
          }
        }
        if (directionchoice == 2){
          cout << "You have chosen not to fight the troops" << endl;
          cout << "You decide to walk away from the troops" << endl;
          cout << "You have abondoned your quest. " << endl;
          cout << "All the soldiers start fighting you" << endl;
          cout << "You have been defeated by the soldiers of the King" << endl;
          cout << "You died" << endl;
          cout << "Game over" << endl;
          // Ends game and initiates game over due to story action 
          return 0;
        }
      }
      if (directionchoice == 2){
        cout << "You have chosen not to join the carriage" << endl;
        cout << "The guard walks up to you and stabs you" << endl;
        cout << "You have been defeated by the guard" << endl;
        cout << "You died" << endl;
        cout << "Game over" << endl;
        // Ends game and initiates game over due to story action 
        return 0;
      }
    }
    if (result == 0){
      // Ends game and initiates game over due to combat
      cout << "Game over, You have been defeated by the troops" << endl;
      if (choice == 'W'){
        wizard->printstats();
      }
      if (choice == 'F'){
        fighter->printstats();
      }
      if (choice == 'E'){
        enigineer->printstats();
      }
      return 0;
    }
    if (result == 1){
      // Handles the result of a combat encounter 
      goal = goal + 1;
      cout <<"You have defeated the Army of malragnum" << endl;
      cout << "You receive 3 healing potion" << endl; 
      cout << "You have also leveled up" << endl;
      if (choice == 'W'){
        wizard->levelup();
        restore(wizard);
        wizard->printstats();
        sethealingpotion(wizard, 3);
      }
      if (choice == 'F'){
        fighter->levelup();
        restore(fighter);
        fighter->printstats();
        sethealingpotion(fighter, 3);
      }
      if (choice == 'E'){
        enigineer->levelup();
        restore(enigineer);
        enigineer->printstats();
        sethealingpotion(enigineer, 3);
      }
    }
    if (goal == 3){
      character* Thragg = new Dragon;
      cout << R"(
                                     AAAAAAAAAAAAAAA                  
                                 AAAAAAAAAAA                          
                                AAAA AAAAA                            
                             AAAAAAAAAAAAA                            
                          AAAAAAAAAAAAAAA AAAAAAAAAA                  
                    AAAAAAA    AAAAAAAA  AA     AAAAAAAAA             
              AAAAA AAAAAA          AAA       AA          AA          
         AAAAAAA                    AA    AAA          AAAAAA         
         AAAAA   AAAAAAAAA        AA                AA       AA       
        AAAAAA           AA AAA  AA             AAA          AAAA     
         A             AAAAA AA  A    A                    AAAAAAA    
                A     AAA AAA         AA                A        AA   
               AAA   AA AAA          AAA                          AAA 
                AA    AAA        AAAAAAA      A                    AA 
               AAAAAAAA  AAAAAAAAAAAAA        A              AAA   AA 
              AAAAAA  AAA        AAAAA        A          AAAAA      AA
                AAAAAA                AAA         AA                AA
                                        AAAAAAAAA A               AAAA
                                           AA    AA            AAA    
                                                AAA       A AA        
                                                 A                    
                                               AAA                 
      )" << endl;
      Thragg->setName("Thragg");
      Thragg->setHp(1500);
      Thragg->setMaxHp(1500);
      Thragg->setAttacks1();
      Thragg->setAttacks2();
      Thragg->setAttacks3();
      Thragg->setspecialability(2);
      cout << "You rest up with the soldiers of the army" << endl;
      cout << "You have gained the title of hero" << endl;
      if (choice == 'W'){
        savePoint(wizard, choice, goal);
      }
      if (choice == 'F'){
        savePoint(fighter, choice, goal);
      }
      if (choice == 'E'){
        savePoint(enigineer, choice, goal);
      }
      cout << endl;
      cout << "In the morning you wake up to the sound of a load roar" << endl;
      cout << "You see a giant dragon flying towards the camp" << endl;
      cout << "One of the soldiers screams 'O my God its Thraggggggg' 'Runnnnnnnn!'"<< endl;
      cout << "Another soldier screams 'Those Malragnum bastards summon Thragggg' 'Run Run now'" << endl;
      cout << "Thragg flys down and releases a flame blast" << endl;
      cout << "Killing some soldiers but you manage to survive" << endl;
      cout << "Attack Thragg to gain his attention" << endl;
      if (choice == 'W'){
        supriseattack(wizard, Thragg);
      }
      if (choice == 'F'){
        supriseattack(fighter, Thragg);
      }
      if (choice == 'E'){
        supriseattack(enigineer, Thragg);
      }
      cout << "You have sucessfully attacked Thragg" << endl;
      cout << "He sees you and starts flying towards you" << endl;
      cout << "You try to dodge but he picks you up from the ground" << endl;
      cout << "He tosses you into a rock doing 20 damage" << endl;
      if (choice == 'W'){
        wizard->takedamage(20);
      }
      if (choice == 'F'){
        fighter->takedamage(20);
      }
      if (choice == 'E'){
        enigineer->takedamage(20);
      }
      cout << "He lands infront of you and is ready to ball" << endl;
      if (choice == 'W'){
        result = round(wizard, Thragg);
      }
      if (choice == 'F'){
        result = round(fighter, Thragg);
      }
      if (choice == 'E'){
        result = round(enigineer, Thragg);
      }
    }
    if (result == 0){
      cout << "Game over, You have been defeated by Thragg" << endl;
      if (choice == 'W'){
        wizard->printstats();
      }
      if (choice == 'F'){
        fighter->printstats();
      }
      if (choice == 'E'){
        enigineer->printstats();
      }
      return 0;
    }
    if (result == 1){
      goal = goal + 1;
      cout <<"You have defeated Thragg" << endl;
      cout << "You receive 3 healing potion" << endl; 
      cout << "You have also leveled up" << endl;
      cout << "You have completed the quest congratulations" << endl;
      if (choice == 'W'){
        wizard->levelup();
        restore(wizard);
        wizard->printstats();
        sethealingpotion(wizard, 3);
      }
      if (choice == 'F'){
        fighter->levelup();
        restore(fighter);
        fighter->printstats();
        sethealingpotion(fighter, 3);
      }
      if (choice == 'E'){
        enigineer->levelup();
        restore(enigineer);
        enigineer->printstats();
        sethealingpotion(enigineer, 3);
      }
    }
    goal = 100;
  }
}

// Handles all the combat stuff
int round(character* c, character* b){
  c->setspecialability(c->getMaxspecialability());
  int round = 1;
  string choice = " ";
  for(int i = 0; i < 21; i++){
    cout << "-";
  }
  cout << "Combat started" ;
  for(int i = 0; i < 21; i++){
    cout << "-";
  }
  cout << endl;
  while ((choice != "Q") && (c->getHp() > 0) && (b->getHp() > 0)){
    int bossatk = rand()% 3 + 1;
    int d1 = rand()% 20 + 1;
    int d2 = rand()% 20 + 1;
    for(int i = 0; i < 40; i++){
      cout << "-";
    }
    cout << endl;
    cout << "Round " << round << endl;
    for(int i = 0; i < 40; i++){
      cout << "-";
    }
    cout << endl;
    round = round + 1;
    Bossatk(c, b, round, bossatk, choice, d1, d2);
    c->printstats();
    for(int i = 0; i < 40; i++){
      cout << "-";
    }
    cout << endl;
    cout << "Boss status: " << endl;
    b->printstats();
    cout << "What would you like to do?" << endl;
    cout << "Attack: Select 'A' for attack" << endl;
    cout << "Dodge: Select 'D' to dodge" << endl;
    cout << "Heal: Select 'H' to heal" << endl;
    cin >> choice;
    cin.ignore();
    if ((choice == "A")|| (choice == "a")){
      int numchoice;
      cout << "Choose what attack to use: " << endl;
      cout << "Attack 1 (1 to choose): " << c->getAttacks1name() << endl;
      cout << "Attack 2 (2 to choose): " << c->getAttacks2name() << endl;
      cout << "Attack 3 (3 to choose): " << c->getAttacks3name() << endl; 
      cin >> numchoice;
      cin.ignore();
      if (numchoice == 1){
        if (c->getAttacks1dmg() == 0){
          cout <<"Insufficient materials" << endl;
          cout << "Choose another attack" << endl;
          cout << "Attack 2 (2 to choose): " << c->getAttacks2name() << endl;
          cout << "Attack 3 (3 to choose): " << c->getAttacks3name() << endl; 
          cin >> numchoice;
          cin.ignore();
          if (numchoice == 2){
            if (c->getAttacks2dmg() == 0){
              cout <<"Insufficient materials" << endl;
              cout << "Choose another attack" << endl;
              cout << "Attack 3 (3 to choose): " << c->getAttacks3name() << endl; 
              cin >> numchoice;
              cin.ignore();
              if (numchoice == 3){
                if (c->getAttacks3dmg() == 0){
                  cout <<"Insufficient materials" << endl;
                  cout << "No attacks can performed this round" << endl;
                }
                else {
                   b->takedamage(c->getAttacks3dmg());
                   c->implementspecialability(5);
                }
              }
            }
            else{
               b->takedamage(c->getAttacks2dmg());
              c->implementspecialability(15);
            }
          }
          if (numchoice == 3){
            if (c->getAttacks3dmg() == 0){
              cout <<"Insufficient materials" << endl;
              cout << "No attacks can performed this round" << endl;
            }
            else {
               b->takedamage(c->getAttacks3dmg());
              c->implementspecialability(5);
            }
          }
        }
        else{
          b->takedamage(c->getAttacks1dmg());
          c->implementspecialability(25);
        }
      }
      if (numchoice == 2){
        if (c->getAttacks2dmg() == 0){
        cout <<"Insufficient materials" << endl;
        cout << "Choose another attack" << endl;
        cout << "Attack 3 (3 to choose): " << c->getAttacks3name() << endl; 
        cin >> numchoice;
        cin.ignore();
          if (numchoice == 3){
            if (c->getAttacks3dmg() == 0){
              cout <<"Insufficient materials" << endl;
              cout << "No attacks can performed this round" << endl;
            }
            else {
              b->takedamage(c->getAttacks3dmg());
              c->implementspecialability(5);
            }
          }
        }
          else{
            b->takedamage(c->getAttacks2dmg());
            c->implementspecialability(15);
          }
      }
      if (numchoice == 3){
        if (c->getAttacks3dmg() == 0){
            cout <<"Insufficient materials" << endl;
            cout << "No attacks can performed this round" << endl;
          }
          else {
            b->takedamage(c->getAttacks3dmg());
            c->implementspecialability(5);
          }
        }

    }
    if ((choice == "H")||(choice == "h")){
      if ((c->getMaxHp() > c->getHp()) && (c->gethealthpotion() > 0)){
        c->gethealing(25);
        c->sethealthpotion(-1);
        cout << "Hp increased" << endl;
      }
      else {
        cout << "You have no more healing potions" << endl;
      }
    }
    if ((choice == "D")||(choice == "d")){
      if (c->getMaxspecialability() > c->getspecialability()){
        c->increasespecialability(20);
        cout << "Special ability increased" << endl;
      }
      else{
        c->printstatusmessage();
      }
    }
    if ((choice == "t")||(choice == "T")){
      b->setHp(0);
      return 1;
    }
    if (choice != "A" && choice == "a" && choice != "H" && choice == "h" && choice != "D" && choice == "d" && choice != "T" && choice == "t"){
      cout << "Invalid choice" << endl;
      cout << "You lose a turn" << endl;
      cout << "Choose again" << endl;
    }
  }
  cout << "Combat Over" << endl;
  if (b->getHp() <= 0){
    return 1;
  }
  else {
    return 0;
  }

}

//Writes the save function 
void writer(string filename, char choice, int goal, character* c){
  string txt = ".txt";
  ofstream saveFile(filename + txt);
  if (saveFile.is_open()){
    saveFile << choice << endl;
    saveFile << goal << endl;
    saveFile << c->getlevel() << endl;
    saveFile << c->gethealthpotion() << endl;
    saveFile << c->getName() << endl;
    saveFile << c->getMaxHp() << endl;
    saveFile << c->getHp() << endl;
    saveFile << c->getspecialability() << endl;
    saveFile.close();
    cout << "Game Saved" << endl;
  }
}

//Writes the boss attack function 
void Bossatk(character* c, character* b, int round, int _bossatk, string menuChoice, int d1, int d2){
  d2 = d2 + 3;
  if (round%2 != 0){
    if (_bossatk == 1){
      if ((menuChoice == "D")|| (menuChoice == "d")){
        if (d1 < d2){
          c->takedamage(b->getAttacks1dmg()/2);
          cout << "You unsucessfully dodged the attack" << endl;
          cout << "The boss attacks you for " << b->getAttacks1dmg()/2 << " damage" << endl;
        }
        else{
          c->takedamage(0);
          cout << "You sucessfully dodged the attack" << endl;
          cout << "Boss attacked you with " << b->getAttacks1name() << " and did 0 damage" << endl;
        } 
      }
      else{
        c->takedamage(b->getAttacks1dmg());
        cout << "Boss attacked you with " << b->getAttacks1name() << " and did " << b->getAttacks1dmg() << " damage" << endl;
      }
    }
    if (_bossatk == 2){
      if ((menuChoice == "D")|| (menuChoice == "d")){
        if (d2 < d1){
          c->takedamage(b->getAttacks2dmg()/2);
          cout << "You unsucessfully dodged the attack" << endl;
          cout << "The boss attacks you for " << b->getAttacks2dmg()/2 << " damage" << endl;
        }
          else {
            c->takedamage(0);
             cout << "You sucessfully dodged the attack" << endl;
            cout << "Boss attacked you with " << b->getAttacks2name() << " and did 0 damage" << endl;
          }
      }
      else {
        c->takedamage(b->getAttacks2dmg());
        cout << "Boss attacked you with " << b->getAttacks2name() << " and did " << b->getAttacks2dmg() << " damage" << endl;
      } 
    }
    if (_bossatk == 3){
        if ((menuChoice == "D")|| (menuChoice == "d")){
          if (d2 < d1){
            c->takedamage(b->getAttacks3dmg()/2);
            cout << "You unsucessfully dodged the attack" << endl;
            cout << "The boss attacks you for " << b->getAttacks3dmg()/2 << " damage" << endl;
          }
          else{
            c->takedamage(0);
            cout << "You sucessfully dodged the attack" << endl;
            cout << "Boss attacked you with " << b->getAttacks3name() << " and did 0 damage" << endl;
          } 
        }
        else{
          c->takedamage(b->getAttacks3dmg());
          cout << "Boss attacked you with " << b->getAttacks3name() << " and did " << b->getAttacks3dmg() << " damage" << endl;
        }
      }
  }
}

//restore a chracter full health
void restore(character* c){
  c->setHp(c->getMaxHp());
  c->setspecialability(c->getMaxspecialability());
}

//Works on savepoints 
void savePoint(character* c, char Characterchoice, int goal){
  for (int i = 0; i < 56; i++){
    cout << "_";
  }
  int savechoice;
  cout << endl;
  cout << "Savepoint: Do you choose to save" << endl;
  cout << "1 for yes and 2 for no" << endl;
  cin >> savechoice;
  cin.ignore();
  if (savechoice == 1){
    cout << "Give me a name of save: " << endl;
    string savename;
    cin >> savename;
    cin.ignore();
    if (Characterchoice == 'W'){
      writer(savename, Characterchoice, goal, c);
      cout << "Save Successful" << endl;
    }
    if (Characterchoice == 'F'){
      writer(savename, Characterchoice, goal, c);
      cout << "Save Successful" << endl;
    }
    if (Characterchoice == 'E'){
      writer(savename, Characterchoice, goal, c);
      cout << "Save Successful" << endl;
    }
  }
  if (savechoice == 2){
    cout << "You have choosing not to save" << endl;
  }
  for (int i = 0; i < 56; i++){
    cout << "_";
  }
}

// Sets healing potion 
void sethealingpotion(character* c, int number_of_healingpotion){
  c->sethealthpotion(number_of_healingpotion);
}

// Handles suprise attacks 
void supriseattack(character* c, character* b){
  int numchoice;
  cout << "Choose what attack to use: " << endl;
  cout << "Attack 1 (1 to choose): " << c->getAttacks1name() << endl;
  cout << "Attack 2 (2 to choose): " << c->getAttacks2name() << endl;
  cout << "Attack 3 (3 to choose): " << c->getAttacks3name() << endl; 
  cin >> numchoice;
  cin.ignore();
  if (numchoice == 1){
    if (c->getAttacks1dmg() == 0){
      cout <<"Insufficient materials" << endl;
      cout << "Choose another attack" << endl;
      cout << "Attack 2 (2 to choose): " << c->getAttacks2name() << endl;
      cout << "Attack 3 (3 to choose): " << c->getAttacks3name() << endl; 
      cin >> numchoice;
      cin.ignore();
      if (numchoice == 2){
        if (c->getAttacks2dmg() == 0){
          cout <<"Insufficient materials" << endl;
          cout << "Choose another attack" << endl;
          cout << "Attack 3 (3 to choose): " << c->getAttacks3name() << endl; 
          cin >> numchoice;
          cin.ignore();
          if (numchoice == 3){
            if (c->getAttacks3dmg() == 0){
              cout <<"Insufficient materials" << endl;
              cout << "No attacks can performed this round" << endl;
            }
            else {
               b->takedamage(c->getAttacks3dmg());
            }
          }
        }
        else{
           b->takedamage(c->getAttacks2dmg());
        }
      }
      if (numchoice == 3){
        if (c->getAttacks3dmg() == 0){
          cout <<"Insufficient materials" << endl;
          cout << "No attacks can performed this round" << endl;
        }
        else {
           b->takedamage(c->getAttacks3dmg());
        }
      }
    }
    else{
      b->takedamage(c->getAttacks1dmg());
    }
  }
  if (numchoice == 2){
    if (c->getAttacks2dmg() == 0){
    cout <<"Insufficient materials" << endl;
    cout << "Choose another attack" << endl;
    cout << "Attack 3 (3 to choose): " << c->getAttacks3name() << endl; 
    cin >> numchoice;
    cin.ignore();
      if (numchoice == 3){
        if (c->getAttacks3dmg() == 0){
          cout <<"Insufficient materials" << endl;
          cout << "No attacks can performed this round" << endl;
        }
        else {
          b->takedamage(c->getAttacks3dmg());
        }
      }
    }
      else{
        b->takedamage(c->getAttacks2dmg());
      }
  }
  if (numchoice == 3){
    if (c->getAttacks3dmg() == 0){
        cout <<"Insufficient materials" << endl;
        cout << "No attacks can performed this round" << endl;
      }
      else {
        b->takedamage(c->getAttacks3dmg());
      }
    }
}
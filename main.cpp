#include <iostream>
#include <string>
using namespace std;
class Character {
protected:
    string name;
    int health;
    int damage;
public:
    Character(string n, int h, int d) : name(n), health(h), damage(d) {}
    void attack(Character& obj) {
        obj.health -= damage;
        if (obj.health < 0) obj.health = 0;
        cout << name << " attacks " << obj.name << " and deals " << damage << " damage!\n";
    }
    bool isAlive(){
        return health > 0;
    }
    void displayStatus(){
        cout << "Name: " << name << endl;
    }
    int get_health(){
        return health;
    }
};
class Player : public Character {
public:
    Player(string n, int h, int d): Character(n,h,d){}
    void victory(){
      cout<<name<<" won!";
    }
    void defeat(){
      cout<<name<<" was defeated!";
    }
    void displayPlayer(){
      cout<<"[Player O_O]"<<endl<<"Name: "<<name<<endl; 
    }
};
class Enemy : public Character {
public:
    Enemy(string n, int h, int d): Character(n,h,d){}
    void displayEnemy(){ 
      cout<<"[Enemy X_X]"<<endl<<"Name: "<<name<<endl;
    }
};
void drawHealth(int health){
      cout<<"Health:"<<endl;
      for(int i=0;i<health;i++)
        cout<<"|";
      cout<<endl;
}
int main() {
    string name; 
    int damage, health, n = 0;
    cin >> name >> health >> damage;
    Player player(name, health, damage);
    cin >> name >> health >> damage;
    Enemy enemy(name, health, damage);

    while (player.isAlive() && enemy.isAlive()) {
        n++;
        cout << endl << "----- The round " << n << " begins -----\n";
        player.displayPlayer();
        drawHealth(player.get_health());
        enemy.displayEnemy();
        drawHealth(enemy.get_health());
        player.attack(enemy);
        if (enemy.isAlive()) {
            enemy.attack(player);
        }
    }

    if (player.isAlive()) {
        player.victory();
    } else {
        player.defeat();
    }

    return 0;
}
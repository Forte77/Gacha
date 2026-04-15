#include <iostream>
#include <random>
#include <iterator>
#include <vector>
using namespace std;
class Equipment{
    private:
        string rarity;
        string slot;
    public:
        int power;
        int bonus=0;
        string name;
        double Weight;
        Equipment(){rarity = "rarity";name = "name"; slot = "slot";bonus = 0;power=0;};
        Equipment(string rarity, string name,string slot,int bonus = 0){
            random_device r;
            mt19937 rng(r());
            int x;
            int y;
            int a = 1;
            int z;
            this->rarity = rarity;
            this->name = name;
            this->slot = slot;
            if (rarity == "Common"){
                x = 1;
                y = 149;
                this->Weight = 50.0;
            } else if (rarity == "Rare"){
                x = 150;
                y = 299;
                z = 20;
                this->Weight = 30.0;
            } else if (rarity == "Epic"){
                x = 300;
                y = 499;
                z = 30;
                this->Weight = 10.0;
            } else if (rarity == "Legendary"){
                x = 500;
                y = 799;
                z = 40;
                this->Weight = 7.0;
            } else if (rarity == "Mythical"){
                x = 800;
                y = 999;
                z = 50;
                this->Weight = 3.0;
            }
            uniform_int_distribution<int> rando(x,y);
            if (rarity != "Common"){
                uniform_int_distribution<int> b(a,z);
                this->bonus = b(rng);
            }
            this->power = rando(rng);
        };
        void print(){cout<<name<<endl<<slot<<endl<<rarity<<endl<<power<<endl<<bonus;};
};
/*void WeightedRandom(Equipment entries[]){
    random_device rd;
    mt19937 gen(rd);
    uniform_real_distribution<double> dis(0.0,1.0);
    double random = dis(gen);
    double totalWeight = 0;
    for (int i=0; i<entries.size();i++){
        totalWeight += entries[i].Weight;}
    double value = random * totalWeight;
    for(int i = 0; i < entries.size();i++){
        value -= entries[i].Weight;
        if(value <= 0){
            return entries[i].name;
        }
    }
    return entries[entries.size() -1].name;
}*/
int main()
{
    cout << "hello world" << endl;
    string common[10] = {"Iron Sword","Broadblade","Kunai","Iron Daggers","Iron Chestplate","Shield","Iron Pants","Ruby Pendant","Bow","Gun"};
    string rarity = "Common";
    string name = "iron sword";
    string slot = "weapon";
    int power = 100;
    int bonus = 0; 
    Equipment sword(rarity,name,slot,bonus);
    sword.print();
}

/*
coding idea
create a luck based system that gives loot and stuff
give items rarity and a pool of stuff

could add hsr sets for examples, god pieces like zeus lightning Poseidon's trident etc

common 0 - 149

rare 150 - 299

epic 300 - 499

legendary 500 - 699

mythical 700 - 999
will have a better power % 

give items stats that can be used to improve power level

each piece has a power system commons can only roll 1-10 power 
etc

what do i want from this project 
what do i want from the user input
what do i want to be seen
leaderboard
boss rush that forte working one

i want it to show a message to ask to roll from a pool of equipment 
weapons, helmet, shield, chestplate, pants, boots, artifact,

what do i want it to do
when the user selects what they want it will tell them what rarity it has as labelled above 
then i want the equipment to have a power level associated with it ie common can how power between 1 - 50 and mythical 200 - 500
add a power % level onto the equipment
have a cap on equipment where the power % is making it more powerful 
it then outputs this number and the rarity it then saves the new equipment onto the person if the number is higher so if they rolled a common 10 power and roll a common 25 power they will be improved
after that i want it to output their total new power
whenever you roll a item you can preserve a piece so whenever you roll something that isn't that piece you keep it if not it compares the two same pieces and give you the better one

i want each equipment to be store in its only value

50  10% 55 52
*/
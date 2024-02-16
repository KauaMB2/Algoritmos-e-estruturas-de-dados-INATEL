/*A Sony, a principal empresa de videogames do mundo, está recrutando desenvolvedores de jogos para
integrar seu seleto time de desenvolvimento. Para selecionar os melhores talentos, eles propuseram um
desafio de programação, no qual os participantes têm a oportunidade de começar suas carreiras no
emocionante mundo dos games.*/
#include <iostream>
#include <string>
#include <locale>
#include <cstdlib>
#include <vector>
#include <cmath>

using namespace std;

struct Warrior{
    string name;
    int force;
    int hability;
    int age;
    int life;
    int id;
};

void cleanScreen(){
    #ifdef _WIN32//RAM: 1 execução
        system("cls");//RAM: 1 execução
    #else //RAM: 1 execução
        system("clear");//RAM: 1 execução
    #endif//RAM: 1 execução
}

int main(){
    locale::global(locale("pt_BR.UTF-8"));
    
    vector<Warrior> warriors;//RAM: 1 execução
    
    
    for(int i=0;i<5;i++){//RAM: 6 execuções 
        Warrior newWarrior;//RAM: 1 execução
        cin >> newWarrior.name;//RAM: 1 execução
        cin >> newWarrior.force;//RAM: 1 execução
        cin >> newWarrior.hability;//RAM: 1 execução
        cin >> newWarrior.age;//RAM: 1 execução
        cout << "\n";//RAM: 1 execução
        newWarrior.id=i;//RAM: 1 execução
        newWarrior.life=100;//RAM: 1 execução
        warriors.push_back(newWarrior);//RAM: 1 execução
        cleanScreen();//RAM: 1 execução
    }
    vector<vector<int>> warriorMatrix(2, vector<int>(2));//RAM: 1 execução
    for(int i = 0; i < 2; i++) {//RAM: 6 execuções | Assinótica: f(n²)
        for(int j = 0; j < 2; j++) {//RAM: 6 execuções
            int IDChoiced;//RAM: 1 execução
            cin >> IDChoiced;//RAM: 1 execução
            warriorMatrix[i][j] = IDChoiced;//RAM: 3 execuções
        }
    }
    int DANO1 = warriors[warriorMatrix[0][0]].force + pow(2, warriors[warriorMatrix[0][0]].hability);//RAM: 1 execução
    int DANO2 = warriors[warriorMatrix[0][1]].force + pow(2, warriors[warriorMatrix[0][1]].hability);//RAM: 1 execução
    cout << DANO1 << endl;//RAM: 1 execução
    cout << DANO2 << endl;//RAM: 1 execução
    if((DANO1)>(DANO2)){//RAM: 4 execuções
        cout << warriors[warriorMatrix[0][0]].name << " ganhou a batalha contra " << warriors[warriorMatrix[0][1]].name << "." << endl;//RAM: 6 execuções
    }else{
        cout << warriors[warriorMatrix[0][1]].name << " ganhou a batalha contra " << warriors[warriorMatrix[0][0]].name << "." << endl;//RAM: 6 execuções
    }
    DANO1 = warriors[warriorMatrix[1][0]].force + pow(2, warriors[warriorMatrix[1][0]].hability);//RAM: 7 execuções
    DANO2 = warriors[warriorMatrix[1][1]].force + pow(2, warriors[warriorMatrix[1][1]].hability);//RAM: 7 execuções
    if((DANO1)>(DANO2)){//RAM: 4 execuções
        cout << warriors[warriorMatrix[1][1]].name << " ganhou a batalha contra " << warriors[warriorMatrix[1][0]].name << "." << endl;//RAM: 7 execuções
    }else{
        cout << warriors[warriorMatrix[1][1]].name << " ganhou a batalha contra " << warriors[warriorMatrix[1][0]].name << "." << endl;//RAM: 7 execuções
    }
    return 0;
}

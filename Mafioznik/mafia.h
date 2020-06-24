#ifndef MAFIA_H
#define MAFIA_H
#include <iostream>
#include "QVector"

using namespace std;

class Mafia
{
private:
    QVector<QString> roles;
    int amount_of_mafia;
    int amount_of_kom;
    int amount_of_doctor;
    int amount_of_maniac;
    int amount_of_prostitutka;
public:
    Mafia(){
        amount_of_kom = 0;
        amount_of_mafia = 0;
        amount_of_doctor = 0;
        amount_of_maniac = 0;
        amount_of_prostitutka = 0;

    }
    int getAmountMafia(){
        return amount_of_mafia;
    }
    int getAmountKom(){
        return amount_of_kom;
    }
    int getAmountDoc(){
        return amount_of_doctor;
    }
    int getAmountManiac(){
        return amount_of_maniac;
    }
    int getAmountProstitutka(){
        return amount_of_prostitutka;

    }

    void setAmountMafia(int value){
       amount_of_mafia+= value;
    }
    void setAmountKom(int value){
        amount_of_kom+= value;
    }
    void setAmountDoc(int value){
        amount_of_doctor+= value;
    }
    void setAmountManiac(int value){
       amount_of_maniac+= value;
    }
    void setAmountProstitutka(int value){
      amount_of_prostitutka+= value;
    }

    void AddMafia(){
        roles.push_back("Mafia");
        setAmountMafia(1);

    }
    void AddPrositutka(){
        roles.push_back("Prostitutka");
        setAmountProstitutka(1);

    }
    void AddManiac(){
        roles.push_back("Maniac");
        setAmountManiac(1);

    }
    void AddDoc(){
        roles.push_back("Doctor");
        setAmountDoc(1);

    }
    void AddKom(){
        roles.push_back("Komisar");
        setAmountKom(1);

    }

    void AddMir(){
        roles.push_back("Mirnyi");

    }
    void MinusaAllMir(){
        for(int i = 0; i < roles.length();i++){
            if(roles[i]=="Mirnyi"){
                roles.remove(i);

            }
        }

    }
    void MinusMafia(){
        for(int i = 0; i < roles.length();i++){
            if(roles[i]=="Mafia"){
                roles.remove(i);
                i = roles.length();
            }
        }
        setAmountMafia(-1);

    }
    void MinusProstitutka(){
        for(int i = 0; i < roles.length();i++){
            if(roles[i]=="Prostitutka"){
                roles.remove(i);
                i = roles.length();
            }
        }
        setAmountProstitutka(-1);

    }
    void MinusManiac(){
        for(int i = 0; i < roles.length();i++){
            if(roles[i]=="Maniac"){
                roles.remove(i);
                i = roles.length();
            }
        }
        setAmountManiac(-1);

    }
    void MinusDoc(){
        for(int i = 0; i < roles.length();i++){
            if(roles[i]=="Doctor"){
                roles.remove(i);
                i = roles.length();
            }
        }

        setAmountDoc(-1);

    }
    void MinusKom(){
        for(int i = 0; i < roles.length();i++){
            if(roles[i]=="Komisar"){
                roles.remove(i);
                i = roles.length();
            }
        }
        setAmountKom(-1);

    }
    QVector<QString> getRoles(){
        return roles;
    }

    int size(){
        return roles.length();
    }
};

#endif // MAFIA_H

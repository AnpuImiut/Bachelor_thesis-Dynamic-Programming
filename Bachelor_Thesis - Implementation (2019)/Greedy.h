#ifndef GREEDY_H_INCLUDED
#define GREEDY_H_INCLUDED

#include<vector>
#include<iostream>
#include<iomanip> //set_precision, std::fixed

#include"DFkt.h"
#include"Input_Datafield.h"

class Greedy
{
private:
    std::vector<double> werte; //Datenfeld für die Berechnungen
    InputArgs & Input_Args;
    void clear_data();
public:
    Greedy(InputArgs & arg);
    ~Greedy();
    void init();
    void berechne();
    void ausgabe() const;
};


#endif // GREEDY_H_INCLUDED

#ifndef DYNP_H_INCLUDED
#define DYNP_H_INCLUDED

#include<vector>
#include<iostream>
#include<iomanip> //set_precision, std::fixed
#include<string>
#include<stdlib.h>//system("cls") - Kommandozeile leeren

#include"DFkt.h"
#include"pngwriter.h"
#include"Input_Datafield.h"

// * DP steht für Dynamisches Programm

class DP
{
private:
    std::vector<std::vector<double> > werte; //Datenfeld für die Berechnungen des dynamischen Programms
    std::vector<std::vector<bool> > choice; //Datenfeld für die Entscheidungen
    InputArgs & Input_Args;
    void createSaveDestinationStringPng(std::string & arg);
    void clear_data();
public:
    DP(InputArgs & arg);
    ~DP();
    void init();
    void berechne();
    void ausgabe();
    void StandardConvertPng();
    double get_Minimum_Value();
};


#endif // DYNP_H_INCLUDED

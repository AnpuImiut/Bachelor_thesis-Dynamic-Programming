#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#include<iostream>
#include<stdlib.h>//system("cls") - Kommandozeile leeren

#include"Input_Datafield.h"
#include"DynP.h"
#include"Greedy.h"
#include"LinDFkt.h"
#include"log_s_fkt.h"
#include"PolySDfkt.h"
#include"expFDfkt.h"
#include"logFDfkt.h"
#include"PolyFDfkt.h"
#include"matplotlibcpp.h"

namespace plt = matplotlibcpp;

class Interface
{
private:
    InputArgs Input_Args;
    DP DynProgram;
    Greedy GreedyProgram;
public:
    Interface();
    ~Interface();
    void calculate(int mode);
    void run();
    void chooseFkt(std::string answer);
    bool input();
    void clearlog();
    void chooseMode();
    void pngRoutine();
    void graphRoutine();
    void minValueRoutine();
    void dpgrpGraph();
    void createGraph(std::vector<double> x,std::vector<double> y,std::string saveFile);
    void massPng(char mode);
    int choose_Parameter();
};

#endif // INTERFACE_H_INCLUDED

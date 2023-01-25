#include"interface.h"

Interface::Interface():Input_Args(InputArgs()),DynProgram(DP(Input_Args)),GreedyProgram(Input_Args)
{

}

Interface::~Interface()
{
    delete Input_Args.fkt_ptr;
}

void Interface::calculate(int mode)
{
    if(mode >= 1)
    {
        DynProgram.init();
        DynProgram.berechne();
    }
    if(mode >= 2)
    {
        GreedyProgram.init();
        GreedyProgram.berechne();
    }
}

void Interface::run()
{
    while(true)
    {
        //erfolgt bei n = 0
        if(!(input()))
           break;
        chooseMode();
        clearlog();
    }
}

void Interface::chooseFkt(std::string answer)
{
    delete Input_Args.fkt_ptr;
    if(answer == "lin")
    {
        LinDistanzFkt::Identifikation();
        int x_0;
        std::cout<< "Eingabe der Nullstelle.\n";
        std::cin>> x_0;
        Input_Args.fkt_ptr = new LinDistanzFkt(Input_Args.n,x_0);
        return;
    }
    if(answer == "logS")
    {
        LogSDfkt::Identifikation();
        int x_0;
        std::cout<< "Eingabe der Nullstelle.\n";
        std::cin>> x_0;
        Input_Args.fkt_ptr = new LogSDfkt(Input_Args.n,x_0);
        return;
    }
    if(answer == "polyS")
    {
        PolySDfkt::Identifikation();
        int x_0, e;
        std::cout<< "Eingabe der Nullstelle und des Exponenten.\n";
        std::cin>> x_0 >> e;
        Input_Args.fkt_ptr = new PolySDfkt(Input_Args.n,x_0,e);
        return;
    }
    if(answer == "expF")
    {
        expFDfkt::Identifikation();
        double c;
        std::cout<< "Eingabe der Wachstumskonstante.\n";
        std::cin>> c;
        Input_Args.fkt_ptr = new expFDfkt(Input_Args.n,c);
        return;
    }
    if(answer == "logF")
    {
        logFDfkt::Identifikation();
        int b;
        double c;
        std::cout<< "Eingabe der Basis und der Wachstumskonstanten\n";
        std::cin>> b >> c;
        Input_Args.fkt_ptr = new logFDfkt(Input_Args.n,b,c);
        return;
    }
    if(answer == "polyF")
    {
        PolyFDfkt::Identifikation();
        int e;
        double c;
        std::cout<< "Eingabe des Exponenten und der Wachstumskonstanten\n";
        std::cin >> e >> c;
        Input_Args.fkt_ptr = new PolyFDfkt(Input_Args.n,e,c);
        return;
    }
}

bool Interface::input()
{
    std::string tmp;
    std::cout<< "Geben sie die Anzahl der Elemente ein:n = ? (0 beendet das Programm)\n";
    std::cin>> Input_Args.n;
    if(Input_Args.n == 0)
        return false;
    std::cout<< "Welche Art von Distanzfunktion moechten sie verwenden?\n";
    std::cout<< "Linear(lin)\nLogarithmisch, langsam fallend(logS)\nPolynom, langsam fallend(polyS)\nExponentielle, schnell fallend(expF)\n";
    std::cout<< "Logarithmisch, schnell fallend(logF)\nPolynom, schnell fallend(polyF)\n...\n";
    std::cin>> tmp;
    chooseFkt(tmp);
    return true;
}

void Interface::clearlog()
{
    std::cout<< "Wollen sie das Kommandozeilenfenster leeren?: Ja(y), Nein(n)\n";
    char answ;
    std::cin>> answ;
    if(answ == 'y')
        system("cls");
}

void Interface::chooseMode()
{
    std::cout<< "Modusauswahl:\n";
    std::cout<< "Png-Routine(png)\nGraph-Routine(grp)\nMinValue(mv)\n...\n";
    std::string inp;
    std::cin>> inp;
    if(inp == "png")
    {
        pngRoutine();
    }
    if(inp == "grp")
    {
        graphRoutine();
    }
    if(inp == "mv")
    {
        minValueRoutine();
    }
}

void Interface::pngRoutine()
{
    std::cout<< "Welche Art von Png-Konvertierung moechten sie vornehmen und in welcher Stückzahl. Eingabe:Modus Anzahl\n";
    std::cout<< "Standard(s): Farbuebergang(Werte-Datenfeld) + Farb - Layer(Choice-Datenfeld)\n";
    std::cout<< "...\n\n";
    std::cout<< "single: Einzelnes Png erstellen.\nmass: Mehrere Pngs erstellen\n";
    char answ;
    std::string mode;
    std::cin>> answ >> mode;
    calculate(2);
    if(mode == "single")
    {
        switch(answ)
        {
        case 's':
            {
                DynProgram.StandardConvertPng();
                break;
            }
        default:
            {
                return;
            }
        }
    }
    if(mode == "mass")
    {
        massPng(answ);
    }

}

void Interface::graphRoutine()
{
    std::cout<< "Welche Art von Graphen moechten sich erstellen\n";
    std::cout<< "Distanzfunktion-Parameter-Graph(dpgrp)\n...\n";
    std::string inp;
    std::cin>> inp;
    if(inp == "dpgrp")
    {
        dpgrpGraph();
    }
}

void Interface::minValueRoutine()
{
    calculate(2);
    std::cout<< "The minimum value is: " << std::setprecision(20) << std::fixed << DynProgram.get_Minimum_Value() << "\n";
}

void Interface::dpgrpGraph()
{
    int chosen = choose_Parameter();
    std::array<double,3> ParaRanges;
    ParaRanges = Input_Args.fkt_ptr->get_Parameter_Range(chosen);
    double low, high, steps;
    low = ParaRanges[0];
    high = ParaRanges[1];
    steps = ParaRanges[2];
//    if(chosen == 0)
//    {
//        high *= 10;
//    }

    std::vector<double> x;
    x.reserve((high - low)/steps);
    std::vector<double> y;
    y.reserve(x.capacity());

    for(double i = low;i<=high;i+=steps)
    {
        if(chosen == 0)
        {
            Input_Args.n = i;
        }
        else
        {
            Input_Args.fkt_ptr->set_Parameter(i,chosen);
        }
        calculate(1);
        x.push_back(i);
        y.push_back(DynProgram.get_Minimum_Value());
    }

    std::string saveFile;
    saveFile.append("GraphOut/");
    saveFile.append(std::to_string(Input_Args.fkt_ptr->get_n()));
    saveFile.append("_");
    saveFile.append(Input_Args.fkt_ptr->getTyp());
    saveFile.append("_");
    saveFile.append(Input_Args.fkt_ptr->sp_values());
    saveFile.append("_");
    saveFile.append(std::to_string(chosen));
    saveFile.append("_dpgrp.png");
    createGraph(x,y,saveFile);
}

void Interface::createGraph(std::vector<double> x,std::vector<double> y,std::string saveFile)
{
    plt::plot(x,y);
    plt::save(saveFile);
    plt::close();
}

int Interface::choose_Parameter()
{
    DistanzFkt *DFKT = Input_Args.fkt_ptr;
    std::vector<std::string>  paraNames = DFKT->get_Parameter_Names();
    std::vector<double> para = DFKT->get_Parameters();
    std::string inp;
    std::cout<< "Distanzfkt-Typ:" << DFKT->getTyp() << "\n";
    std::cout<< "Parameter sind:";
    for(auto i: paraNames)
    {
        std::cout<< i << " ";
    }
    std::cout<< "\nWaehlen sie einen von diesen aus\n";
    std::cin>> inp;

    int chosen;
    for(int i = 0;i<paraNames.size();++i)
    {
        if(paraNames[i] == inp)
        {
            chosen = i;
            break;
        }
    }
    return chosen;
}

void Interface::massPng(char mode)
{
    int chosen = choose_Parameter();
    std::array<double,3> ParaRanges;
    ParaRanges = Input_Args.fkt_ptr->get_Parameter_Range(chosen);
    double low, high, steps;
    low = ParaRanges[0];
    high = ParaRanges[1];
    steps = ParaRanges[2];
    if(chosen == 0)
    {
        low = 50;
        high = 50+2*high;
    }
    for(double i = low;i<=high;i+=steps)
    {
        if(chosen == 0)
        {
            Input_Args.n = i;
        }
        else
        {
            Input_Args.fkt_ptr->set_Parameter(i,chosen);
        }
        calculate(1);
        switch(mode)
        {
            case 's':
            {
                DynProgram.StandardConvertPng();
            }
            default:
            {
                break;
            }
        }
    }
}

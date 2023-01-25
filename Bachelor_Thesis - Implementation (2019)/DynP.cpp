#include"DynP.h"

DP::DP(InputArgs & arg):Input_Args(arg)
{

}

DP::~DP()
{
    werte.clear();
    choice.clear();
}

void DP::clear_data()
{
    for(int i = 0;i<werte.size();++i)
    {
        werte[i].clear();
    }
    werte.clear();
    for(int i = 0;i<choice.size();++i)
    {
        choice[i].clear();
    }
    choice.clear();
}

void DP::init()
{
    const int tmp_n = Input_Args.n;
    const DistanzFkt *Dfkt_ptr = Input_Args.fkt_ptr;
    clear_data();
    werte.resize(tmp_n);
    choice.resize(tmp_n);
    for(int i = 1;i <= tmp_n;++i)
    {
        werte[i-1].resize(i,0);
        choice[i-1].resize(i,false);
    }
    for(int i = 0;i<tmp_n;++i)
    {
        werte[tmp_n-1][i] = Dfkt_ptr->berechne(tmp_n,tmp_n-i);
    }
}

void DP::berechne()
{
    const int tmp_n = Input_Args.n;
    const DistanzFkt *Dfkt_ptr = Input_Args.fkt_ptr;
    for(int i = tmp_n-1;i >= 1;--i)
    {
        for(int j = 0;j <= i-1;++j)
        {
            double firstArg,secondArg;
            double FA_tmp1 = Dfkt_ptr->berechne(tmp_n,tmp_n-j);
            double FA_tmp2 = (double)i/(double)tmp_n;
            //firstArg = (double)i/(double)tmp_n * Dfkt_ptr->berechne(tmp_n,tmp_n-j+1);
            firstArg = FA_tmp1;
            firstArg *= FA_tmp2;
            double SA_tmp1 = 1.0d/(double)(i+1);
            double SA_tmp2 = werte[i][0];
            double SA_tmp3 = (double)i/((double)(i+1));
            double SA_tmp4 = werte[i][j+1];
            secondArg = SA_tmp1 * SA_tmp2 + SA_tmp3 * SA_tmp4;
            if(firstArg > secondArg)
            {
                werte[i-1][j] = firstArg;
                choice[i-1][j] = true;
            }
            else
            {
                werte[i-1][j] = secondArg;
                choice[i-1][j] = false;
            }
        }
    }
}

void DP::ausgabe()
{
    const int tmp_n = Input_Args.n;
    for(int i = 0;i < tmp_n;++i)
    {
        for(int j = 0;j < werte[i].size();++j)
        {
            std::cout<< std::setprecision(3) << std::fixed << werte[i][j] << " ";
        }
        std::cout<< "\n";
    }
    std::cout<< "\n\n";
    for(int i = 0;i < tmp_n;++i)
    {
        for(int j = 0;j < choice[i].size();j++)
        {
            std::cout<< std::fixed << choice[i][j] << " ";
        }
        std::cout<< "\n";
    }
    std::cout<< "\n";
}

void DP::StandardConvertPng()
{
    const int tmp_n = Input_Args.n;

    std::string saveDestination;
    createSaveDestinationStringPng(saveDestination);
    saveDestination.append("_standard.png");
    pngwriter one(tmp_n,tmp_n,0,saveDestination.c_str());

    //Farbpalette im recht oberen Quadranten zeichnen
    for(int y = tmp_n;y >= 3*tmp_n/4;--y)
    {
        for(int x = tmp_n/2; x <= tmp_n;++x)
        {
            one.plot(x,y,0.51,(double)(2*x-tmp_n)/(double)tmp_n,0.0);
        }
    }
    //Farbpalette für mit Choice=1
    for(int y = (3*tmp_n/4)+1;y >= tmp_n/2;--y)
    {
        for(int x = tmp_n/2;x <= tmp_n;++x)
        {
            one.plot(x,y,0.23,(double)(2*x-tmp_n)/(double)tmp_n,1.0);
        }
    }
    //Tatsächlichen Werte
    for(int i = 0;i < werte.size();++i)
    {
        for(int j = 0;j < werte[i].size();++j)
        {
            if(choice[i][j])
                one.plot(j+1,tmp_n-i,0.23,werte[i][j],1.0);
            else
                one.plot(j+1,tmp_n-i,0.51,werte[i][j],0.0);
        }
    }
    one.close();
}

void DP::createSaveDestinationStringPng(std::string & arg)
{
    const DistanzFkt *Dfkt_ptr = Input_Args.fkt_ptr;
    arg.append("PngOut/");
    arg.append(std::to_string(Input_Args.n));
    arg.append("_");
    arg.append(Dfkt_ptr->getTyp());
    arg.append("_");
    arg.append(Dfkt_ptr->sp_values());
}

double DP::get_Minimum_Value()
{
    return werte[0][0];
}

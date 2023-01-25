#include"Greedy.h"

Greedy::Greedy(InputArgs & arg):Input_Args(arg)
{

}

Greedy::~Greedy()
{
    werte.clear();
}

void Greedy::init()
{
    clear_data();
    werte.resize(Input_Args.n,0.0);
}

void Greedy::clear_data()
{
    werte.clear();
}

void Greedy::berechne()
{
    const int tmp_n = Input_Args.n;
    const DistanzFkt *Dfkt_ptr = Input_Args.fkt_ptr;
    for(int i = 0;i < werte.size();++i)
    {
        //werte[i] = (double)(i+1)/(double)n * Dfkt->berechne(n,n-i);
        for(int j = 0;j <= i;++j)
        {
            if(Dfkt_ptr->berechne(tmp_n,tmp_n-j) == 0.0d)
            {
                break;
            }
            else
            {
                werte[i] = (double)(j+1)/(double)tmp_n * Dfkt_ptr->berechne(tmp_n,tmp_n-j);
            }
        }
    }
}

void Greedy::ausgabe() const
{
    for(int i = 0;i < werte.size();++i)
    {
        std::cout<< werte[i] << " ";
    }
    std::cout<< "\n";
}


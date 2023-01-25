#include"expFDfkt.h"

expFDfkt::expFDfkt(int & n, double m):DistanzFkt(n,"expF"),c(m){}

double expFDfkt::berechne(int x, int y) const
{
    int betrag = fabs(x-y);
    return 1.0/exp(c*(double)betrag);
}

void expFDfkt::Identifikation()
{
    std::cout<< "Typ:exponentielle Funktion,schnell fallend, Parameter: Wachstumskonstante(c), Eingabemuster:c\n";
}

std::string expFDfkt::sp_values() const
{
    return std::to_string(c);
}

std::vector<double> expFDfkt::get_Parameters() const
{
    std::vector<double> answer;
    answer.push_back((double)n);
    answer.push_back(c);
    return answer;
}

std::vector<std::string> expFDfkt::get_Parameter_Names() const
{
    std::vector<std::string> answer;
    answer.push_back("n");
    answer.push_back("c");
    return answer;
}

std::array<double,3> expFDfkt::get_Parameter_Range(int index) const
{
    double low, high, step;

    switch(index)
    {
    case 0:
        {
            low = 1.0;
            high =  n;
            step = 1.0;
            break;
        }
    case 1:
        {
            low = 0.001;
            high = 0.1;
            step = 0.0005;
            break;
        }
    default:
        {
            break;
        }
    }

    std::array<double,3> ans;
    ans[0] = low;
    ans[1] = high;
    ans[2] = step;
    return ans;
}

void expFDfkt::set_Parameter(double arg,int paraind)
{
    switch(paraind)
    {
    case 0:
        {
            n = (int)arg;
            break;
        }
    case 1:
        {
            c = arg;
            break;
        }
    default:
        {
            return;
        }
    }
}

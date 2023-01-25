#include"LinDFkt.h"

LinDistanzFkt::LinDistanzFkt(int & n, int m):DistanzFkt(n,"lin"),x_0(m){}

double LinDistanzFkt::berechne(int x, int y) const
{
    int betrag = fabs(x-y);
    if(betrag >= x_0)
    {
        return 0.0d;
    }
    else
    {
        double answer = 1.0d - ((double)betrag/(double)x_0);
        if(answer < 0.0)
            return 0.0;
        else
            return answer;
    }
}

void LinDistanzFkt::Identifikation()
{
    std::cout<< "Typ:Lineare Funktion, Parameter: Beginn der Nullstelle(x_0), Eingabemuster:x_0\n";
}

std::string LinDistanzFkt::sp_values() const
{
    return std::to_string(x_0);
}

std::vector<double> LinDistanzFkt::get_Parameters() const
{
    std::vector<double> answer;
    answer.push_back((double)n);
    answer.push_back((double)x_0);
    return answer;
}

std::vector<std::string> LinDistanzFkt::get_Parameter_Names() const
{
    std::vector<std::string> answer;
    answer.push_back("n");
    answer.push_back("x_0");
    return answer;
}

std::array<double,3> LinDistanzFkt::get_Parameter_Range(int index) const
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
            low = 1.0;
            high = n;
            step = 1.0;
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

void LinDistanzFkt::set_Parameter(double arg,int paraind)
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
            x_0 = (int)arg;
            break;
        }
    default:
        {
            return;
        }
    }
}

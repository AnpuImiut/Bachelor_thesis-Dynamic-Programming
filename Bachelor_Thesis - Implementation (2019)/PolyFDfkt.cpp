#include"PolyFDfkt.h"

PolyFDfkt::PolyFDfkt(int & n, int m, double C):DistanzFkt(n,"PolyF"),e(m),c(C){}

double PolyFDfkt::berechne(int x, int y) const
{
    int betrag = fabs(x-y);
    double tmp = c*pow((double)betrag,(double)e)+1;
    return 1.0/tmp;
}

void PolyFDfkt::Identifikation()
{
    std::cout<< "Typ:Polynom, schnell fallend, Parameter:Exponent(e), Wachstumskonstante(c), Eingabemuster:e c\n";
}

std::string PolyFDfkt::sp_values() const
{
    std::string answer;
    answer.append(std::to_string(e));
    answer.append("_");
    answer.append(std::to_string(c));
    return answer;
}

std::vector<double> PolyFDfkt::get_Parameters() const
{
    std::vector<double> answer;
    answer.push_back((double)n);
    answer.push_back((double)e);
    answer.push_back(c);
    return answer;
}

std::vector<std::string> PolyFDfkt::get_Parameter_Names() const
{
    std::vector<std::string> answer;
    answer.push_back("n");
    answer.push_back("e");
    answer.push_back("c");
    return answer;
}

std::array<double,3> PolyFDfkt::get_Parameter_Range(int index) const
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
            high = 10.0;
            step = 1.0;
            break;
        }
    case 2:
        {
            low = 0.00001;
            high = 0.002;
            step = 0.000007;
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

void PolyFDfkt::set_Parameter(double arg,int paraind)
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
            e = (int)arg;
            break;
        }
    case 2:
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

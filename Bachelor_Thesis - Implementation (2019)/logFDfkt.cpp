#include"logFDfkt.h"

logFDfkt::logFDfkt(int & n, int B, double m):DistanzFkt(n,"logF"),b(B),c(m){}

double logFDfkt::berechne(int x, int y) const
{
    int betrag = fabs(x-y);
    return log10((double)b)/log10(c*(double)betrag + (double)b);
}

void logFDfkt::Identifikation()
{
    std::cout<< "Typ:logarithmische Funktion, schnell fallend, Parameter:Basis(b), Wachstumskonstante(c), Eingabemuster:b c\n";
}

std::string logFDfkt::sp_values() const
{
    std::string answer;
    answer.append(std::to_string(b));
    answer.append("_");
    answer.append(std::to_string(c));
    return answer;
}

std::vector<double> logFDfkt::get_Parameters() const
{
    std::vector<double> answer;
    answer.push_back((double)n);
    answer.push_back((double)b);
    answer.push_back(c);
    return answer;
}

std::vector<std::string> logFDfkt::get_Parameter_Names() const
{
    std::vector<std::string> answer;
    answer.push_back("n");
    answer.push_back("b");
    answer.push_back("c");
    return answer;
}

std::array<double,3> logFDfkt::get_Parameter_Range(int index) const
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
            low = 2.0;
            high = 10.0;
            step = 1.0;
            break;
        }
    case 2:
        {
            low = 0.001;
            high = 0.75;
            step = 0.003 ;
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

void logFDfkt::set_Parameter(double arg,int paraind)
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
            b = (int)arg;
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

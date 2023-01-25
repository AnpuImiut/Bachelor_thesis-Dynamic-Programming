#include"log_s_fkt.h"

LogSDfkt::LogSDfkt(int & n, int m):DistanzFkt(n,"logS"),x_0(m+1){} //m+1, weil die Nullstelle sonst bei m-1 liegen würde

double LogSDfkt::berechne(int x, int y) const
{
    int betrag = fabs(x-y);
    double tmp = x_0 - betrag+1;
    double answer = log(tmp)/log((double)x_0+1);
    if(betrag >= x_0)
        return 0.0;
    else
        return answer;
}

void LogSDfkt::Identifikation()
{
    std::cout<< "Typ:logarithmische Funktion, langsam fallend, Parameter: Beginn der Nullstelle(x_0), Eingabemuster:x_0\n";
}

std::string LogSDfkt::sp_values() const
{
    return std::to_string(x_0);
}

std::vector<double> LogSDfkt::get_Parameters() const
{
    std::vector<double> answer;
    answer.push_back((double)n);
    answer.push_back((double)x_0);
    return answer;
}

std::vector<std::string> LogSDfkt::get_Parameter_Names() const
{
    std::vector<std::string> answer;
    answer.push_back("n");
    answer.push_back("x_0");
    return answer;
}

std::array<double,3> LogSDfkt::get_Parameter_Range(int index) const
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
            high = n-1;
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

void LogSDfkt::set_Parameter(double arg,int paraind)
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

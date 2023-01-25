#include"PolySDfkt.h"

PolySDfkt::PolySDfkt(int & n, int m, int E):DistanzFkt(n,"PolyS"),x_0(m),e(E){}

double PolySDfkt::berechne(int x, int y) const
{
    int betrag = fabs(x-y);
    double answer = 1.0 - (pow((double)betrag,(double)e)/pow((double)x_0,(double)e));
    if(answer < 0.0)
        return 0.0;
    else
        return answer;
}

void PolySDfkt::Identifikation()
{
    std::cout<< "Typ:Polynom,langsam fallend, Parameter: Beginn der Nullstelle(x_0), Exponent(e) Eingabemuster:x_0 e\n";
}

std::string PolySDfkt::sp_values() const
{
    std::string answer;
    answer.append(std::to_string(x_0));
    answer.append("_");
    answer.append(std::to_string(e));
    return answer;

}

std::vector<double> PolySDfkt::get_Parameters() const
{
    std::vector<double> answer;
    answer.push_back((double)n);
    answer.push_back((double)x_0);
    answer.push_back((double)e);
    return answer;
}

std::vector<std::string> PolySDfkt::get_Parameter_Names() const
{
    std::vector<std::string> answer;
    answer.push_back("n");
    answer.push_back("x_0");
    answer.push_back("e");
    return answer;
}

std::array<double,3> PolySDfkt::get_Parameter_Range(int index) const
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
    case 2:
        {
            low = 1.0;
            high = 20;
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

void PolySDfkt::set_Parameter(double arg,int paraind)
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
    case 2:
        {
            e = (int)arg;
        }
    default:
        {
            return;
        }
    }
}

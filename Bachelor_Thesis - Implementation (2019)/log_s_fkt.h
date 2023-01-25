#ifndef LOG_S_FKT_H_INCLUDED
#define LOG_S_FKT_H_INCLUDED

//log_s stands for slow decreasing function
#include<math.h> //log(x)

#include"DFkt.h"

class LogSDfkt:public DistanzFkt
{
private:
    int x_0; //Nullstelle
public:
    LogSDfkt(int & n, int m);
    ~LogSDfkt() override = default;
    double berechne(int x, int y) const override;
    static void Identifikation();
    std::string sp_values() const;
    std::vector<double> get_Parameters() const;
    std::vector<std::string> get_Parameter_Names() const;
    std::array<double,3> get_Parameter_Range(int index) const;
    void set_Parameter(double arg,int paraind);
};

#endif // LOG_S_FKT_H_INCLUDED

#ifndef LOGFDFKT_H_INCLUDED
#define LOGFDFKT_H_INCLUDED

#include<math.h>

#include"DFkt.h"

class logFDfkt:public DistanzFkt
{
private:
    int b; //Basis des Logarithmus
    double c;//Wachstumskonstante
public:
    logFDfkt(int & n, int B, double m);
    ~logFDfkt() override = default;
    double berechne(int x, int y) const override;
    static void Identifikation();
    std::string sp_values() const;
    std::vector<double> get_Parameters() const;
    std::vector<std::string> get_Parameter_Names() const;
    std::array<double,3> get_Parameter_Range(int index) const;
    void set_Parameter(double arg,int paraind);
};



#endif // LOGFDFKT_H_INCLUDED

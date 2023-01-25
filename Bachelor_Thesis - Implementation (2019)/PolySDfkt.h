#ifndef POLYSDFKT_H_INCLUDED
#define POLYSDFKT_H_INCLUDED

#include<math.h>

#include"DFkt.h"

class PolySDfkt:public DistanzFkt
{
private:
    int x_0; //quadratische Nullstelle
    int e; //Exponent x^e
public:
    PolySDfkt(int & n, int m, int E);
    ~PolySDfkt() override = default;
    double berechne(int x, int y) const override;
    static void Identifikation();
    std::string sp_values() const;
    std::vector<double> get_Parameters() const;
    std::vector<std::string> get_Parameter_Names() const;
    std::array<double,3> get_Parameter_Range(int index) const;
    void set_Parameter(double arg,int paraind);
};

#endif // POLYSDFKT_H_INCLUDED

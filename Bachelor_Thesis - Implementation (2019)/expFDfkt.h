#ifndef EXPFDFKT_H_INCLUDED
#define EXPFDFKT_H_INCLUDED

#include<math.h>

#include"DFkt.h"

class expFDfkt:public DistanzFkt
{
private:
    double c; //Wachstumskonstante
public:
    expFDfkt(int & n, double m);
    ~expFDfkt() override = default;
    double berechne(int x, int y) const override;
    static void Identifikation();
    std::string sp_values() const;
    std::vector<double> get_Parameters() const;
    std::vector<std::string> get_Parameter_Names() const;
    std::array<double,3> get_Parameter_Range(int index) const;
    void set_Parameter(double arg,int paraind);
};


#endif // EXPFDFKT_H_INCLUDED

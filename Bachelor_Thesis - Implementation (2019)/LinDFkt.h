#ifndef LINDFKT_H_INCLUDED
#define LINDFKT_H_INCLUDED

#include<math.h>
#include<iostream>

#include"DFkt.h"

class LinDistanzFkt: public DistanzFkt
{
private:
    int x_0; //Nullstelle
public:
    LinDistanzFkt(int & n, int m);
    ~LinDistanzFkt() override = default;
    double berechne(int x, int y) const override;
    static void Identifikation();
    std::string sp_values() const;
    std::vector<double> get_Parameters() const;
    std::vector<std::string> get_Parameter_Names() const;
    std::array<double,3> get_Parameter_Range(int index) const;
    void set_Parameter(double arg,int paraind);
};


#endif // LINDFKT_H_INCLUDED

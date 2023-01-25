#ifndef DFKT_H_INCLUDED
#define DFKT_H_INCLUDED

#include<iostream>
#include<string>
#include<vector>
#include<array>

class DistanzFkt
{
private:

protected:
    int & n;
    std::string typ;
public:
    DistanzFkt(int & N,std::string T):n(N),typ(T){};
    virtual ~DistanzFkt() = default;
    virtual double berechne(int x, int y) const = 0;
    std::string getTyp() const;
    int get_n();
    virtual std::string sp_values() const{return "";}; //sp stands for special
    virtual std::vector<double> get_Parameters() const = 0;
    virtual std::vector<std::string> get_Parameter_Names() const = 0;
    virtual std::array<double,3> get_Parameter_Range(int index) const = 0;
    virtual void set_Parameter(double arg,int paraind) = 0;
};

#endif // DFKT_H_INCLUDED

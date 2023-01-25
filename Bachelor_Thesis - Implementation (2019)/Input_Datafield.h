#ifndef INPUT_DATAFIELD_H_INCLUDED
#define INPUT_DATAFIELD_H_INCLUDED

#include"DFkt.h"

struct InputArgs
{
    int n;
    DistanzFkt *fkt_ptr = nullptr;
    InputArgs():n(0),fkt_ptr(nullptr){};
};

#endif // INPUT_DATAFIELD_H_INCLUDED

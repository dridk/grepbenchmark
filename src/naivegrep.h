#ifndef NAIVEGREP_H
#define NAIVEGREP_H
#include "abstractgrep.h"

class NaiveGrep : public AbstractGrep
{
public:
    NaiveGrep();
    ~NaiveGrep();

    virtual vector<int> findQuery(const string &query);


};

#endif // NAIVEGREP_H

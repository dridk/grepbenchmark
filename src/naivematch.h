#ifndef NAIVEGREP_H
#define NAIVEGREP_H
#include "abstractmatch.h"

class NaiveMatch : public AbstractMatch
{
public:
    NaiveMatch();
    ~NaiveMatch();

    virtual vector<int> findQuery(const string &query);


};

#endif // NAIVEGREP_H

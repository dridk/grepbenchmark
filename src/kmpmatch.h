#ifndef KMPMATCH_H
#define KMPMATCH_H
#include "abstractmatch.h"

class KmpMatch : public AbstractMatch
{
public:
    KmpMatch();

    virtual vector<int> findQuery(const string &query);


protected:
    //compute margin table from a query string
    static std::vector<int> computeNext(const std::string& query);

    // compute margin from a string
    static int margin(const std::string& sub);

private:

};

#endif // KMPMATCH_H

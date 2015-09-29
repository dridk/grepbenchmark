#include "naivematch.h"

NaiveMatch::NaiveMatch()
{

}

NaiveMatch::~NaiveMatch()
{

}

vector<int> NaiveMatch::findQuery(const string &query)
{
    vector<int> positions;

    if (source().empty())
    {
        cerr<<"source text is empty";
        return positions;
    }

    if (query.size() > source().size())
    {
        cerr<<"query is too large";
        return positions;
    }

    for (int i=0; i<source().size() - query.size(); ++i)
    {

        if (source().substr(i,query.size()) == query )
            positions.push_back(i);
    }

    return positions;
}


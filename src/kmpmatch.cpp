#include "kmpmatch.h"

KmpMatch::KmpMatch()
    :AbstractMatch()
{

}
//--------------------------------------------------
vector<int> KmpMatch::findQuery(const std::string &query)
{
    std::vector<int> positions;
    // create the prefix Tables
    std::vector<int> next      = computeNext(query);

    int m = 0; // cursor in text
    int i = 0; // cursor in query

    // check over all source text
    while (m < source().size() - query.size() )
    {

        // if query caracter match source caracter, test the next query caracter ( i+1)
        if (query[i] == source()[m+i])
            ++i;

        // Otherwise jump to the next source position m+=x
        // where x come from prefix table
        else {
            int partial_match_length = i+1;                                    // length of the partial match
            int jump = partial_match_length - next[partial_match_length - 1];  // This is the magic formula ...
            m+= jump;

            if ( i> 0) // aucune idée..
            i=next[i];
        }

        // if query match the source, add it to position list and reset variables
        if (i == query.size()-1) {
            positions.push_back(m);
            i=0;
            m+=query.size();
        }
    }

    return positions;
}
//--------------------------------------------------
std::vector<int> KmpMatch::computeNext(const std::string &query)
{
    std::vector<int> next;
    // the first element is always 0, cause there is no margin
    next.push_back(0);

    // call margin on each subword of query
    // ex : cocacola has : c,co, coc, coca, cocac, cocaco, cocacol, cocacola
    for (int i=2; i< query.size()+1; ++i)
    {
        std::string sub = query.substr(0,i);
        next.push_back(margin(sub));

    }

    return next;
}
//--------------------------------------------------
int KmpMatch::margin(const string &sub)
{
    // compute margin of a string. For ex :
    // cocaco has prefix [co] and suffix [co] which has length of 2

    int m = 0;
    // if string has less than 1 caracter, that's mean no margin
    if (sub.size() <= 1)
        return m;

    // create all substring prefix and suffix
    for ( int i=1; i<sub.size(); ++i)
    {
        int j = sub.size() - i;
        string prefix  = sub.substr(0,i);
        string suffix  = sub.substr(j, i);

        // margin is the size of the longuest prefix which equal suffix
        if ( prefix == suffix)
            m= i;
    }
    return m;
}


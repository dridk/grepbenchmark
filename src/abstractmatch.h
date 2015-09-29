#ifndef ABSTRACT_GREP_H
#define ABSTRACT_GREP_H
#include <string>
#include <vector>
#include <iostream>
#include "color.h"
using namespace std;
class AbstractMatch
{
public:
    AbstractMatch();
    ~AbstractMatch();
	
    void setSource(const string& source);
    const string &source() const;

    // Return source position of matched query
    virtual vector<int> findQuery(const string& query) = 0 ;

    // test unit

    void test();



	

private:
    string mSource;


};
#endif

#ifndef ABSTRACT_GREP_H
#define ABSTRACT_GREP_H
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class AbstractGrep
{
public:
	AbstractGrep();
	~AbstractGrep();
	
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

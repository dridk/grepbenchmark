#include "abstractgrep.h"

AbstractGrep::AbstractGrep()
{

}

//================================
AbstractGrep::~AbstractGrep()
{
	
}

void AbstractGrep::setSource(const string& source)
{
	mSource = source;

}

const string &AbstractGrep::source() const
{
    return mSource;
}

void AbstractGrep::test()
{

    setSource("sachalechatdesachat");
    vector<int> positions = findQuery("cha");

    for (auto i : positions)
    {
        string sub = source().substr(i, 3);

        if ( sub == "cha" )
            cout<<"Found..."<<endl;
    }

}




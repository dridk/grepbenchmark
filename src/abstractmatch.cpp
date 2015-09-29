#include "abstractmatch.h"

AbstractMatch::AbstractMatch()
{

}

//================================
AbstractMatch::~AbstractMatch()
{

}

void AbstractMatch::setSource(const string& source)
{
    mSource = source;

}

const string &AbstractMatch::source() const
{
    return mSource;
}

void AbstractMatch::test()
{

    Color::Modifier red(Color::FG_RED);
    Color::Modifier def(Color::FG_DEFAULT);

    string text  = "sachalechatdesachat";
    string query = "cha";

    setSource(text);
    vector<int> positions = findQuery(query);

    if ( positions.size() == 0){
        cout<<text;
        return;
    }

    int j = 0;

    for (int i=0; i<text.size(); ++i)
    {

        if ( i == positions[j])
            cout<<red;

        cout<<text[i];


        if ( i == positions[j] + query.size()-1){
            if (positions.size() > j+1)
                j++;
           cout<<def;

        }
    }

    cout<<endl;

}




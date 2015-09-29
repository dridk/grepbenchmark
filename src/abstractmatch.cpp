#include "abstractmatch.h"

AbstractMatch::AbstractMatch()
{

}

//================================
AbstractMatch::~AbstractMatch()
{

}
//================================
void AbstractMatch::setSource(const string& source)
{
    mSource = source;

}
//================================
const string &AbstractMatch::source() const
{
    return mSource;
}

void AbstractMatch::test(const string &query,bool verbose )
{
    auto begin = std::chrono::high_resolution_clock::now();
    vector<int> positions = findQuery(query);
    auto elapsed = std::chrono::high_resolution_clock::now() - begin;
    long long duration = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
    cout<<positions.size()<<" elements found in "<<duration<<" ms"<<endl;

    if (!verbose)
        return ;

    Color::Modifier red(Color::FG_RED);
    Color::Modifier def(Color::FG_DEFAULT);

    if ( positions.size() == 0){
        cout<<source();
        return ;
    }

    int j = 0;
    for (int i=0; i<source().size(); ++i)
    {

        if ( i == positions[j])
            cout<<red;

        cout<<source()[i];

        if ( i == positions[j] + query.size()-1){
            if (positions.size() > j+1)
                j++;
            cout<<def;

        }
    }

    cout<<endl;

    return ;

}
//================================
//void AbstractMatch::test()
//{


//    string text  = "sachalechatmangedeschat";
//    string query = "cha";

//    setSource(text);

//    // thanks natir for his code ..
//    auto begin = std::chrono::high_resolution_clock::now();
//    vector<int> positions = findQuery(query);
//    auto elapsed = std::chrono::high_resolution_clock::now() - begin;

//    long long duration = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

//    cout<<"in "<<duration<<" ms"<<endl;

//    if ( positions.size() == 0){
//        cout<<text;
//        return;
//    }

//    int j = 0;

//    for (int i=0; i<text.size(); ++i)
//    {

//        if ( i == positions[j])
//            cout<<red;

//        cout<<text[i];


//        if ( i == positions[j] + query.size()-1){
//            if (positions.size() > j+1)
//                j++;
//           cout<<def;

//        }
//    }

//    cout<<endl;

//}
////================================
//void AbstractMatch::print() const
//{
//    Color::Modifier red(Color::FG_RED);
//    Color::Modifier def(Color::FG_DEFAULT);

//    if ( positions.size() == 0){
//        cout<<source();
//        return;
//    }

//    int j = 0;
//    for (int i=0; i<source().size(); ++i)
//    {

//        if ( i == positions[j])
//            cout<<red;

//        cout<<text[i];

//        if ( i == positions[j] + query.size()-1){
//            if (positions.size() > j+1)
//                j++;
//           cout<<def;

//        }
//    }

//    cout<<endl;

//}




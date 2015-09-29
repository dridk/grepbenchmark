#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>
#include "naivematch.h"
#include "kmpmatch.h"

using namespace std;
int main(int argc, char **argv)
{


    ifstream file;
    file.open("cftr.txt");

    if (file.fail())
        cerr<<"cannot open file";

    string text = string((std::istreambuf_iterator<char>(file)),
                         (std::istreambuf_iterator<char>()));



    KmpMatch match;
    match.setSource(text);



   match.test("CATTTTAGCTGTGGTACTTTGTAGAAATGTGAGAAA",false);



    return 0;
}	

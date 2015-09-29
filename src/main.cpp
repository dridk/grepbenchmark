#include <iostream>
#include <string>
#include "naivematch.h"
#include "color.h"
using namespace std;
int main(int argc, char **argv)
{
	
    NaiveMatch grep;

    grep.setSource("salutchatchatsacha");


    grep.test();


    return 0;
}	

#include <iostream>
#include <vector>
#include <sstream>
#include "Range.h"

using namespace std;

template<class type>
bool checkCase(string, type, type);

bool criteria01();
bool criteria02();
bool criteria03();
bool criteria04();
bool criteria05();
bool criteria06();
bool criteria07();
bool criteria08();
void criteria09();

int main()
{
    
    bool flag=true;

    cout << "Range Class Testing!" << endl;

    if(criteria01())
        cout << "Criteria 01: Templates constructor 1.0: Passed" << endl;
    else
        cout << "Criteria 01: Templates constructor 1.0: Failed" << endl;


    if(criteria02())
        cout << "Criteria 02: Templates constructor 2.0: Passed" << endl;
    else
        cout << "Criteria 02: Templates constructor 2.0: Failed" << endl;


    if(criteria03())
        cout << "Criteria 03: Templates Length: Passed" << endl;
    else
        cout << "Criteria 03: Templates Length: Failed" << endl;

    if(criteria04())
        cout << "Criteria 04: Templates Sum: Passed" << endl;
    else
        cout << "Criteria 04: Templates Sum: Failed" << endl;

    if(criteria05())
        cout << "Criteria 05: Templates Average: Passed" << endl;
    else
        cout << "Criteria 05: Templates Average: Failed" << endl;

    if(criteria06())
        cout << "Criteria 06: Templates Min: Passed" << endl;
    else
        cout << "Criteria 06: Templates Min: Failed" << endl;

    if(criteria07())
        cout << "Criteria 07: Templates Max: Passed" << endl;
    else
        cout << "Criteria 07: Templates Max: Failed" << endl;

    if(criteria08())
        cout << "Criteria 08: Templates operator<<: Passed" << endl;
    else
        cout << "Criteria 08: Templates operator<<: Failed" << endl;

    criteria09();

    return 0;
}

bool criteria01()
{
    Range<int>r1(3,11);
    Range<double>r2(3.1, 11.0);
    stringstream out1,out2;
    out1 << r1;
    out2 << r2;

    if(checkCase("Criteria 01",out1.str(),string("3 4 5 6 7 8 9 10 11 ")) && checkCase("Criteria 01",out2.str(),string("3.1 4.1 5.1 6.1 7.1 8.1 9.1 10.1 ")))
        return true;
    else
        return false;

}

bool criteria02()
{
    Range<int>r1(3,11,2);
    Range<double>r2(3.1, 11.0,2.0);
    stringstream out1,out2;
    out1 << r1;
    out2 << r2;

    if(checkCase("Criteria 02",out1.str(),string("3 5 7 9 11 ")) && checkCase("Criteria 02",out2.str(),string("3.1 5.1 7.1 9.1 ")))
        return true;
    else
        return false;
}

bool criteria03()
{
    Range<double>r1(7.5, 20.3, 2.5);
    Range<int>r2(12, 3, -2);

    if(checkCase("Criteria 03",r1.length(),6) && checkCase("Criteria 03",r2.length(),5))
        return true;
    else
        return false;
}


bool criteria04()
{
    Range<double>r1(7.5, 20.3, 2.5);
    Range<int>r2(12, 3, -2);
    Range<double>r3(20.0, 4.0, -2.5);

    if(checkCase("Criteria 04",r1.sum(),82.5) && checkCase("Criteria 04",r2.sum(),40)&& checkCase("Criteria 04",r3.sum(),87.5))
        return true;
    else
        return false;
}

bool criteria05()
{
    Range<double>r1(7.5, 20.3, 2.5);
    Range<int>r2(12, 3, -2);
    Range<double>r3(20.0, 4.0, -2.5);

    if(checkCase("Criteria 05",r1.average(),82.5/6) && checkCase("Criteria 05",r2.average(),40/5)&& checkCase("Criteria 05",r3.average(),87.5/7))
        return true;
    else
        return false;
}

bool criteria06()
{
    Range<double>r1(7.5, 20.3, 2.5);
    Range<int>r2(12, 3, -2);
    Range<double>r3(20.0, 4.0, -2.5);

    if(checkCase("Criteria 06",r1.min(),7.5) && checkCase("Criteria 06",r2.min(),4)&& checkCase("Criteria 06",r3.min(),5.0))
        return true;
    else
        return false;
}

bool criteria07()
{
    Range<double>r1(7.5, 20.3, 2.5);
    Range<int>r2(12, 3, -2);
    Range<double>r3(20.0, 4.0, -2.5);

    if(checkCase("Criteria 07",r1.max(),20.0) && checkCase("Criteria 07",r2.max(),12)&& checkCase("Criteria 07",r3.max(),20.0))
        return true;
    else
        return false;
}


bool criteria08()
{
    Range<double>r1(7.5, 20.3, 2.5);
    Range<int>r2(12, 3, -2);
    Range<double>r3(20.0, 4.0, -2.5);

    stringstream out1,out2,out3;
    out1 << r1;
    out2 << r2;
    out3 << r3;
    
    if(checkCase("Criteria 08",out1.str(),string("7.5 10 12.5 15 17.5 20 ")) && checkCase("Criteria 08",out2.str(),string("12 10 8 6 4 "))&& checkCase("Criteria 08",out3.str(),string("20 17.5 15 12.5 10 7.5 5 ")))
        return true;
    else
        return false;
}

void criteria09()
{
    cout << "Criteria 09: Good coding practices(white space, variable names) : I will check your code!!!!! " << endl;
}

template<class type>
bool checkCase(string name, type is, type shouldBe)
{
    if(is != shouldBe)
    {
        cout << name << " -> Failed: output was " << is << " should have been " << shouldBe << endl;
        
    }
    return is == shouldBe;
}

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#ifdef __cplusplus
extern "C"{
#endif

#include "fnv.h"

#ifdef __cplusplus
}
#endif

using namespace std;

int compar(const void* str1,const void* str2)
{
    if(str1 < str2)
        return -1;
    else if(str1>str2)
        return 1;
    else
        return 0;
}
string preparador(stringstream &sstr, unsigned int n)
{
    string *strs = new string[n];
    string aux = "";

    for(int i=0;i<n;i++)
    {
        sstr >> strs[i];

    }


    qsort(strs, n, sizeof(string),compar);

    aux+= strs[0];
    for(int i=1;i<n;i++)
    {
        if(strs[i-1] == strs[i])
            continue;
        else
            aux+=" "+strs[i];
    }
    // tem vazamento de memória pra caramba aqui.
    return aux;
}

void interpreter(stringstream &line)
{
char operation;
unsigned int n;
string value;
line >> operation;
line >> n;
value = preparador(line,n);
cout << value;
cout << ":end" << endl;




}

int main()
{

    std::ifstream file("/home/danilo/Trabalho1_EDA/Cpp/inputhash-01.txt");

    std::string str;
    std::stringstream s;
    unsigned long nsub, n;
    std::getline(file, str);
    s << str;

    s >> nsub;

    s >> n;


    //cout << n <<endl<<nsub;
    while (std::getline(file, str))
    {
        std::stringstream ss;
        ss << str;
        interpreter(ss);
    }
}


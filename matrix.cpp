#include <iostream>
#include <cstdlib>
#include "matrix.hpp"

using namespace std;

matrix::matrix(int w, int k)
{
    if(k<=0 && w<=0)
    {
        cout<<"Podales zle wymiary macierzy"<<endl;
    }
    else
    {
        wiersze=w;
        kolumny=k;
        macierz=new double *[w];

        for(int i=0;i<w;i++)
        {
            macierz[i]=new double [k];
        }
        
        for(int i=0;i<w;i++)
        {
            for(int j=0;j<k;j++)
            {
                macierz[i][j]={0};
            }
        }
    }
}
matrix::matrix(int w)
{
    if( w<=0)
    {
        cout<<"Podales zly wymiary macierzy"<<endl;
    }
    else
    {
        wiersze=w;
        kolumny=w;
        macierz=new double *[w];

        for(int i=0;i<w;i++)
        {
            macierz[i]=new double [w];
        }
        
        for(int i=0;i<w;i++)
        {
            for(int j=0;j<w;j++)
            {
                macierz[i][j]={0};
            }
        }
    }
}
matrix::~matrix()
{
    for(int i=0;i<wiersze;i++)
    {
        delete[] macierz[i];
    }
    delete[] macierz;
}
void matrix::prints()
{
    for(int i=0; i<wiersze; i++)
    {
        for(int j=0; j<kolumny; j++)
        {
            cout << macierz[i][j] << "\t";
        }
        cout << endl;
    }

}
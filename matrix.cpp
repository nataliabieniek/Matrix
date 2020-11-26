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
void matrix::set(int n, int m, int val)
{
    if(n>=wiersze && n<0 && m>=kolumny && m<0)
    {
        std::cout << "Zle dane do funkcji set" << std::endl;
        exit(-1);
    }
    macierz[n][m]=val;
}
double matrix::get(int n, int m)
{
    if(n>wiersze && n<0 && m>kolumny && m<0)
    {
        std::cout << "Zle dane do funkcji get" << std::endl;
        return 0;;
    }
    return macierz[n][m];
}
int matrix::cols()
{
    return kolumny;
}
int matrix::rows()
{
    return wiersze;
}
matrix matrix::add(matrix &m2)
{
    if(kolumny!=m2.cols() && wiersze!= m2.rows())
    {
        std::cout << "Nie ma mozliwosci dodania. Macierze nie pasuja do siebie" << std::endl;
        return 1;
    }
    matrix m_add(wiersze, kolumny);
    for(int i=0; i<wiersze; i++)
    {
        for(int j=0; j<kolumny; j++)
        {
            macierz[i][j]=macierz[i][j]+ m2.get(i,j);
        }
    }
    return m_add;
}
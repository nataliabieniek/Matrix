#include <iostream>
#include <cstdlib>
#include "matrix.cpp"


int main()
{
    std::cout << "Labolatorium 3" << std::endl;
    matrix macierz(2,3);
    matrix macierz2(2,3);
    int wartosc=1;
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<3; j++)
        {
            macierz.set(i,j,wartosc);
            wartosc++;
            macierz2.set(i,j,wartosc);
            wartosc++;
        }
        wartosc=wartosc*3;
    }
    macierz.prints();
    std::cout << std::endl << "Pierwszy element ma wartosc\t" <<macierz.get(0,0) << std::endl;
    std::cout << "Ilosc wierszy:\t" << macierz.rows() <<"\nIlosc kolumn:\t" << macierz.cols()<<std::endl;
    std::cout << std::endl;
    macierz.add(macierz2);
    macierz.prints();
}
#include <iostream>
#include <cstdlib>
#include "matrix.cpp"


int main()
{
    std::cout << "Labolatorium 3" << std::endl;
    matrix macierz(2,3);
    int wartosc=1;
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<3; j++)
        {
            macierz.set(i,j,wartosc);
            wartosc++;
        }
        wartosc=wartosc*3;
    }
    macierz.prints();
}
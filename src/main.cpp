#include <iostream>
#include <cstdlib>
#include <matrix/matrix.hpp>


int main()
{
    std::cout << "Labolatorium 3" << std::endl;
    matrix macierz(2, 3);
    matrix macierz2(2, 3);
    int wartosc = 1;
    std::cout << "Macierz zaraz po utworzeniu:" << std::endl;
    macierz.prints();
    std::cout << "Macierz po wpisania wartosci do niej:" << std::endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            macierz.set(i,j,wartosc);
            wartosc++;
            macierz2.set(i,j,wartosc*1.5);
            wartosc++;
        }
        wartosc=wartosc*3;
    }
    macierz.prints();
    std::cout << "Pierwszy element ma wartosc\t" <<macierz.get(0,0) << std::endl;
    std::cout << "Ilosc wierszy:\t" << macierz.rows() <<"\nIlosc kolumn:\t" << macierz.cols()<<std::endl;
    std::cout << "Dodamy do naszej macierzy nastepujaca macierz2:" << std::endl;
    macierz2.prints();
    std::cout << "Macierz 1 po dodaniu:" << std::endl;
    macierz+macierz2;
    macierz.prints();
    std::cout << "Teraz odejmiemy od tej macierzy macierz2:" << std::endl;
    macierz-macierz2;
    macierz.prints();
}
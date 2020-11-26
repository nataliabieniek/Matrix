#include <iostream>
#include <cstdlib>

class matrix
{
    public:
    matrix(int w, int k);
    matrix(int w);
    ~matrix();
    void prints();
    void set(int n, int m, int val);
    double get(int n, int m);
    int cols();
    int rows();


    private:
    int kolumny;
    int wiersze;
    double **macierz;
};
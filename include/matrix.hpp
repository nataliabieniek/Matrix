#include <iostream>
#include <cstdlib>

class matrix
{
    public:
    matrix(int w, int k);
    matrix(int w);
    matrix(std::string path);
    ~matrix();
    void prints();
    void set(int n, int m, int val);
    double get(int n, int m);
    int cols();
    int rows();
    matrix add(matrix &m2);
    matrix subtract(matrix &m2);
    matrix multiply(matrix &m2);
    void store(std::string filename, std::string path);

    private:
    int kolumny;
    int wiersze;
    double **macierz;
};
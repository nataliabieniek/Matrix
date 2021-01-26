#ifndef matrix_hpp
#define matrix_hpp

#include <iostream>
#include <cstdlib>



class matrix
{
    public:
    matrix();
    matrix(int w, int k);
    matrix(int w);
    matrix(std::string path);
    ~matrix();
    void prints();
    void set(int n, int m, int val);
    double get(int n, int m);
    int cols();
    int rows();
    matrix operator+(matrix &m2)noexcept(false);
    matrix operator-(matrix &m2) noexcept(false);
    matrix operator*(matrix &m2) noexcept(false);
    void store(std::string filename, std::string path);
    bool matrix::operator==(matrix &m);
    bool matrix::operator!=(matrix &m);
    void matrix::operator[](int row_index) noexcept(false);

    private:
    int kolumny;
    int wiersze;
    double **macierz;
};

#endif
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <matrix/matrix.hpp>

using namespace std;

class WrongElement : public exception
{
    virtual const char *what() const throw()
    {
        return "Exeption1: Brak zadanego elementu";
    }
};

class WrongOpenFile : public exception
{
    virtual const char *what() const throw()
    {
        return "Exeption2: Blad otwarcia pliku";
    }
};

class WrongSize : public exception
{
    virtual const char *what() const throw()
    {
        return "Exeption3: Zly rozmiar macierzy";
    }
};
matrix::matrix(int w, int k)
{
    if (k <= 0 && w <= 0)
    {
        throw WrongElement();
    }
    else
    {
        wiersze = w;
        kolumny = k;
        macierz = new double *[w];

        for (int i = 0; i < w; i++)
        {
            macierz[i] = new double[k];
        }

        for (int i = 0; i < w; i++)
        {
            for (int j = 0; j < k; j++)
            {
                macierz[i][j] = {0};
            }
        }
    }
}
matrix::matrix(int w)
{
    if (w <= 0)
    {
        throw WrongElement();
    }
    else
    {
        wiersze = w;
        kolumny = w;
        macierz = new double *[w];

        for (int i = 0; i < w; i++)
        {
            macierz[i] = new double[w];
        }

        for (int i = 0; i < w; i++)
        {
            for (int j = 0; j < w; j++)
            {
                macierz[i][j] = {0};
            }
        }
    }
}
matrix::~matrix()
{
    for (int i = 0; i < wiersze; i++)
    {
        delete[] macierz[i];
    }
    delete[] macierz;
}
void matrix::prints()
{
    for (int i = 0; i < wiersze; i++)
    {
        for (int j = 0; j < kolumny; j++)
        {
            cout << macierz[i][j] << "\t";
        }
        cout << endl;
    }
}
void matrix::set(int n, int m, int val)
{
    if (n >= wiersze && n < 0 && m >= kolumny && m < 0)
    {
        throw WrongElement();
    }
    macierz[n][m] = val;
}
double matrix::get(int n, int m)
{
    if (n > wiersze && n < 0 && m > kolumny && m < 0)
    {
        throw WrongElement();
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
    if (kolumny != m2.cols() && wiersze != m2.rows())
    {
        throw WrongSize();
    }
    matrix m_add(wiersze, kolumny);
    for (int i = 0; i < wiersze; i++)
    {
        for (int j = 0; j < kolumny; j++)
        {
            macierz[i][j] = macierz[i][j] + m2.get(i, j);
        }
    }
    return m_add;
}
matrix matrix::subtract(matrix &m2)
{
    if (kolumny != m2.cols() && wiersze != m2.rows())
    {
        throw WrongSize();
    }
    matrix m_sub(wiersze, kolumny);
    for (int i = 0; i < wiersze; i++)
    {
        for (int j = 0; j < kolumny; j++)
        {
            macierz[i][j] = macierz[i][j] - m2.get(i, j);
        }
    }
    return m_sub;
}
matrix matrix::multiply(matrix &m2)
{
    if (kolumny != m2.rows())
    {
        throw WrongSize();
    }
    matrix m_mul(wiersze, m2.cols());
    for (int i = 0; i < wiersze; i++)
    {
        for (int j = 0; j < m2.cols(); j++)
        {
            double mnozenie = 0;
            for (int k = 0; k < m2.rows(); k++)
            {
                mnozenie += macierz[i][k] * m2.matrix::get(k, j);
            }
            m_mul.matrix::set(i, j, mnozenie);
        }
    }
    return m_mul;
}
void matrix::store(string filename, string path)
{
    path += "\\" + filename;
    ofstream file(path);
    if(!file.is_open())
    {
        throw WrongOpenFile();
    }
    file << wiersze << "\t" << kolumny << endl;
    for (int i = 0; i < wiersze; i++)
    {
        for (int j = 0; j < kolumny; j++)
        {
            int wart = macierz[i][j];
            file << wart << "\t";
        }
        file << endl;
    }
    file.close();
}
matrix::matrix(std::string path)

{
    ifstream file;
    file.open(path);
    if (file.is_open() == false)
    {
        throw WrongOpenFile();
    }
    else
    {
        file >> wiersze;
        file >> kolumny;

        macierz = new double *[wiersze];
        for (int i = 0; i < wiersze; i++)
        {
            macierz[i] = new double[kolumny];
        }

        for (int i = 0; i < wiersze; i++)
        {
            for (int j = 0; j < kolumny; j++)
            {
                file >> macierz[i][j];
            }
        }
    }
}
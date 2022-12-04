#include <iostream>
#include <cstdlib>
 
const int ERR_EXIT = -1;
 
using namespace std;
 
 
class Matrix
{
public:
    int **mat;
    int rows;  
    int colls; 
    size_t SIZE;
 
    Matrix();
    Matrix(int _rows);
    Matrix(int _rows, int _colls);
    Matrix(const Matrix &COP);ия
    ~Matrix();

    void printMatrix();
    void printMatrixOne();
    Matrix operator = (Matrix &A);
    Matrix operator + (Matrix &A);
    Matrix operator - (Matrix &A);
    Matrix operator * (Matrix &A);
    Matrix operator * (int num);
    Matrix set_ZERO();
    Matrix inMat();
};
 

Matrix::Matrix()
{
    mat = NULL;
    rows = 0;
    colls = 0;
}
 

Matrix::Matrix(int _rows )
{
    rows = _rows;
    mat = new int* [_rows];
    for(int i = 0; i < _rows; i++)
    {
        mat[i] = new int[_rows];
    }
}
 

Matrix::Matrix(int _rows, int _colls)
{
    rows = _rows;
    colls = _colls;
    if (!(mat = new int* [_rows]))
    {
        cerr << "Неможливо розмістити матрицю у пам'яті";
        exit(ERR_EXIT);
    }
    for (int i = 0; i < _rows; i++)
    {
        if (!(mat[i] = new int[_colls]))
        {
            cerr << "Неможливо розмістити матрицю у пам'яті";
            exit (ERR_EXIT);
        }
    }
    for (int i = 0; i < _rows; i++)
            for (int j = 0; j < _colls; j++)
                mat[i][j] = 1+rand()%9;
}
 

Matrix::Matrix(const Matrix &COP)
{
    int i,j;
    rows = COP.rows;
    colls = COP.colls;
 
    if (!(mat = new int*[rows]))
    {
        cerr << "Неможливо розмістити матрицю у пам'яті";
        exit(ERR_EXIT);
    }
    for (i = 0; i < rows; i++)
    {
        if (!(mat[i] = new int [colls]))
        {
            cerr << "Неможливо розмістити матрицю у пам'яті";
            exit(ERR_EXIT);
        }
    }
   
    for (j = 0; j < colls; j++)
    {
        for (i = 0; i < rows; i++)
        {
            mat[i][j] = COP.mat[i][j];
        }
    }
 
}
 

 Matrix & operator = (const Matrix &A)
{
    int i,j;
    for (i = 0; i < colls; i++)
        delete (mat[i]);
        delete (mat);
    rows = A.rows;
    colls = A.colls;
 
    if (!(mat = new int*[rows]))
    {
        cerr << "Неможливо розмістити матрицю у пам'яті";
        exit(ERR_EXIT);
    }
 
    for (i = 0; i < rows; i++)
    {
        if (!(mat[i] = new int [colls]))
        {
            cerr << "Неможливо розмістити матрицю у пам'яті";
            exit(ERR_EXIT);
        }
    }
 
    for (j = 0; j < A.rows; j++)
    {
        for (i = 0; i < A.colls; i++)
        {
            mat[i][j] = A.mat[i][j];
        }
    }
 
    return *this;
}
 

Matrix::~Matrix()
{
    for(int i = 0; i < rows; ++i)
    {
        delete  [] mat[i];
        mat[i] = NULL;
    }
    delete [] mat;
    mat = NULL;
}
 
Matrix Matrix::set_ZERO()
{
    int i,j;
    for (j = 0; j < colls; j++)
        for (i = 0; i < rows; i++)
        mat[i][j] = 0;
    return *this;
}
 

Matrix Matrix::operator-(Matrix &A)
{
    int i,j;
    if (colls != A.colls || rows != A.rows )
    {
        cerr << "Матриця не сумісна з операцією -";
        exit(ERR_EXIT);
    }
    Matrix C (rows, colls);
    for (j = 0; j < colls; j++)
    {
        for (i = 0; i < rows; i++)
        {
            C.mat[i][j] = mat[i][j] - A.mat[i][j];
        }
    }
    return C;
}
 

Matrix Matrix::operator+(Matrix &A)
{
    int i,j;
    if (colls != A.colls || rows != A.rows )
    {
        cerr << "Матриця не сумісна з операцією+";
        exit(ERR_EXIT);
    }
    Matrix C (rows, colls);
    for (j = 0; j < colls; j++)
    {
        for (i = 0; i < rows; i++)
        {
            C.mat[i][j] = A.mat[i][j] + mat[i][j];
        }
    }
    return C;
}
 

Matrix Matrix::operator*(Matrix &A)
{
    int i,j,k;
    if ((colls != A.rows))
    {
        cerr << "Матриця не сумісна з операцією *";
        exit(ERR_EXIT);
    }
 
    Matrix M (rows, colls);
    M.set_ZERO();
 
    for (j = 0; j < A.colls; j++)
        for (i = 0; i < rows; i++)
            for (k = 0; k < A.rows; k++)
                M.mat[i][j] = M.mat[i][j] + mat[i][k] *  A.mat[k][j];
    return M;
}
 

Matrix Matrix::operator*(int num)
{
    int i,j;
    for (j = 0; j < colls; j++)
        for (i = 0; i < rows; i++)
            mat[i][j] = num * mat[i][j];
    return *this;
}
 
// Ввод данных
Matrix Matrix::inMat()
{
    int i,j;
    cout << "Введите матрицу " << endl;
    cout << rows << 'X' << colls << ":" << endl;
 
    for (i = 0 ; i < rows; i++)
    {
        for (j = 0; j < colls; j++)
        {
            cin >> mat[i][j];
        }
    }
    return *this;
}
 

void Matrix::printMatrix()
{
   for (int i = 0; i<rows; i++)
        {
            for (int j = 0; j<colls; j++)
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
}
 

void Matrix::printMatrixOne()
{
   for (int i = 0; i<rows; i++)
        {
            cout << mat[i] << " ";
        }
            cout << endl;
}
int main()
{
    setlocale(0,"");
    int i;
 
    Matrix  F(4), A( 4, 4 ), B( 4, 4 ), C(4, 4), G;
    //A.inMat();
    cout << "Матрица F" << endl;
    F.printMatrixOne();
    cout << "Матрица G" << endl;
    G.printMatrix();
    cout << "Матрица А" << endl;
    A.printMatrix();
    cout << "Матрица B" << endl;
    B.printMatrix();
    C = A * B;
    cout << "Матрица С" << endl;
    C.printMatrix();
    cout << "Введіть множник i = " << endl;
    cin >> i;
    C * i;
    cout << "Матрица С" << endl;
    C.printMatrix();
 
 
 
 
    return 0;
}


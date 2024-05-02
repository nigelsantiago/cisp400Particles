#include <iostream>
#include <vector>
#include <iomanip>
#include "Matrices.h"

namespace Matrices
{
  Matrix::Matrix::Matrix(int _rows, int _cols)
  {
    a.resize(_rows);
    for (int rIndex = 0; rIndex < _rows; rIndex++)
    {
      a[rIndex].resize(_cols);   
    }
  rows = _rows;
  cols = _cols;
  }

    ///Add each corresponding element.
    ///usage:  c = a + b;
  Matrix operator+(const Matrix& a, const Matrix& b)
  {
      if (a.getCols() != b.getCols() || a.getRows() != b.getRows())
      {
          throw runtime_error("Error: dimensions must agree");
      }
      else 
      {
          Matrix c(a.getRows(), a.getCols());
          for (int i = 0; i < a.getRows(); i++)
          {
              for (int j = 0; j < a.getCols(); j++)
              {
                  c(i, j) = a(i, j) + b(i, j);
              }
          }
          return c;
      }
  }


    ///Matrix multiply.  See description.
    ///usage:  c = a * b;
  Matrix operator*(const Matrix& a, const Matrix& b)
  {
    if (a.getCols() != b.getRows())
    {
      throw runtime_error("Error: dimensions must agree");
    }
    else
    {
      Matrix c(a.getRows(), b.getCols());
      for (int k = 0; k < b.getCols(); k++)
      {
        for (int i = 0; i < a.getRows(); i++)
        {
          double total = 0.0;
          for (int j = 0; j < b.getRows(); j++)
          {
            total += a(i, j) * b(j, k);
          }
          c(i, k) = total;
        }
      }
    return c;
    }
  }

    ///Matrix comparison.  See description.
    ///usage:  a == b
  bool operator==(const Matrix& a, const Matrix& b)
  {
    if (a.getCols() != b.getCols() || a.getRows() != b.getRows())
    {
      return false;
    }
    bool isEqual = true;
    for (int i = 0; i < a.getRows(); i++)
    {
      for (int j = 0; j < a.getCols(); j++)
      {
        if (abs(a(i, j)) != abs(b(i, j)))
        {
          isEqual = false;
        }
      }
    }
    return isEqual;
  }

    ///Matrix comparison.  See description.
    ///usage:  a != b
  bool operator!=(const Matrix& a, const Matrix& b)
  {
      if (a.getCols() != b.getCols() || a.getRows() != b.getRows())
      {
        return true;
      }
    bool isNotEqual = true;
    int matchCount = 0;
    for (int i = 0; i < a.getRows(); i++)
    {
      for (int j = 0; j < a.getCols(); j++)
      {
        if (abs(a(i, j)) == abs(b(i, j)))
        {
          matchCount++;
        }
      }
    }
    if (matchCount == a.getCols() * a.getRows())
    {
      isNotEqual = false;
    }
    return isNotEqual;
  }

    ///Output matrix.
    ///Separate columns by ' ' and rows by '\n'
  ostream& operator<<(ostream& os, const Matrix& a)
  {
    for (int i = 0; i < a.getRows(); i++)
    {
      for (int j = 0; j < a.getCols(); j++)
      {
        os << setw(15) << a(i, j);
      }
      os << endl;
    }
    return os;
  }

    TranslationMatrix::TranslationMatrix(double xShift, double yShift, int nCols)
      : Matrix (2, nCols)
  {
    for (int j = 0; j < nCols; j++)
      (*this)(0, j) = xShift;
    for (int j = 0; j < nCols; j++)
      (*this)(1, j) = yShift;
  }
    ScalingMatrix::ScalingMatrix(double scale)
      : Matrix (2, 2)
  {
    (*this)(0, 0) = scale;
    (*this)(1, 0) = 0;
    (*this)(0, 1) = 0;
    (*this)(1, 1) = scale;
  }
  RotationMatrix::RotationMatrix(double theta)
      : Matrix (2, 2)
  {
    (*this)(0, 0) = cos(theta);
    (*this)(0, 1) = (-sin(theta));
    (*this)(1, 0) = sin(theta);
    (*this)(1, 1) = cos(theta);
  }
}

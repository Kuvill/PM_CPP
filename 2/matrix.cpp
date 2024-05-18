#include "matrix.h"

#include <algorithm>
#include <iostream>

namespace lp {

Matrix::Matrix() {}

Matrix::Matrix(int rowsn, int colsn) : _colsn(rowsn), _rowsn(colsn) {
  _ptr = new int *[_rowsn];
  for (int i = 0; i < _rowsn; ++i) {
    _ptr[i] = new int[_colsn];
  }
}

Matrix::Matrix(const Matrix &other)
    : _rowsn(other._rowsn), _colsn(other._colsn) {

  _ptr = new int *[_rowsn];
  for (int i = 0; i < _rowsn; ++i) {
    _ptr[i] = new int[_colsn];
    std::copy(other._ptr[i], other._ptr[i] + other._colsn, _ptr[i]);
  }
}

Matrix Matrix::operator=(const Matrix &other) {
  if (_rowsn != other._rowsn)
    _ptr = new int *[other._rowsn];

  if (_colsn != other._colsn)
    for (int i = 0; i < _rowsn; ++i) {
      _ptr[i] = new int[other._colsn];
      std::copy(other._ptr[i], other._ptr[i] + other._colsn, _ptr[i]);
    }
  else
    for (int i = 0; i < _rowsn; ++i)
      std::copy(other._ptr[i], other._ptr[i] + other._colsn, _ptr[i]);

  return *this;
}

Matrix::~Matrix() {
  for (int i = 0; i < _rowsn; ++i) {
    delete[] _ptr[i];
  }
}

std::istream &operator>>(std::istream &is, Matrix &obj) {
  for (int i = 0; i < obj.Rows(); ++i) {
    std::cout << "Enter " << obj.Cols() << " numbers in " << i << " rows from "
              << obj.Rows() << std::endl;
    for (int j = 0; j < obj.Cols(); ++j) {
      is >> obj.At(i, j);
    }
  }

  return is;
}

std::ostream &operator<<(std::ostream &os, const Matrix &obj) {
  for (int i = 0; i < obj.Rows(); ++i) {
    for (int j = 0; j < obj.Cols(); ++j) {
      os << obj.At(i, j) << " ";
    }
  }

  return os;
}

} // namespace lp

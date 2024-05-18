#pragma once

#include <sstream>

namespace lp {

class Matrix {
private:
  int **_ptr = nullptr;
  int _rowsn = 0, _colsn = 0;

public:
  Matrix();

  Matrix(int colsn, int rowsn);

  Matrix(const Matrix &other);

  Matrix operator=(const Matrix &other);

  ~Matrix();

  int Rows() const { return _rowsn; }
  int Cols() const { return _colsn; }

  int &At(int rowsn, int colsn) { return _ptr[rowsn][colsn]; }
  int At(int rowsn, int colsn) const { return _ptr[rowsn][colsn]; }
};

std::istream &operator>>(std::istream &is, Matrix &obj);
std::ostream &operator<<(std::ostream &os, const Matrix &obj);

} // namespace lp

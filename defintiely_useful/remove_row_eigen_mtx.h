// This is from https://stackoverflow.com/questions/13290395/how-to-remove-a-certain-row-or-column-while-using-eigen-library-c
// Keywords: eigen, matrix, resize, remove row, remove column, blocking
// Date: 9/12/2024

void removeRow(Eigen::MatrixXd& matrix, unsigned int rowToRemove)
{
    unsigned int numRows = matrix.rows()-1;
    unsigned int numCols = matrix.cols();

    if( rowToRemove < numRows )
        matrix.block(rowToRemove,0,numRows-rowToRemove,numCols) = matrix.block(rowToRemove+1,0,numRows-rowToRemove,numCols);

    matrix.conservativeResize(numRows,numCols);
}

void removeColumn(Eigen::MatrixXd& matrix, unsigned int colToRemove)
{
    unsigned int numRows = matrix.rows();
    unsigned int numCols = matrix.cols()-1;

    if( colToRemove < numCols )
        matrix.block(0,colToRemove,numRows,numCols-colToRemove) = matrix.block(0,colToRemove+1,numRows,numCols-colToRemove);

    matrix.conservativeResize(numRows,numCols);
}


/// I turned this into a class for NG_nav here it is

#ifndef EIGEN_MATRIX_UTILS_H
#define EIGEN_MATRIX_UTILS_H

#include <eigen3/Eigen/Eigen>

namespace Eigen_mtx_utils
{
/**
 * @brief Remove a row from an unsized Eigen Matrix
 * @param matrix Matrix to remove row from
 * @param row Row to remove
 * @return Matrix with row removed
 */
Eigen::MatrixXd Remove_row(const Eigen::MatrixXd& matrix, const Eigen::Index& row)
{
  Eigen::Index num_rows = matrix.rows()-1;
  Eigen::Index num_cols = matrix.cols();

  Eigen::MatrixXd out = matrix;
  if(row < num_rows)
  {
    out.block(row, 0, num_rows-row, num_cols) = matrix.block(row + 1, 0, num_rows-row, num_cols);
  }
  out.conservativeResize(num_rows, num_cols);
  return out;
}

/**
 * @brief Remove a row from an unsized Eigen Matrix
 * @param matrix Matrix to remove row from
 * @param row Row to remove
 * @return Matrix with row removed
 */
Eigen::MatrixXd Remove_row(Eigen::VectorXd& matrix, const Eigen::Index& row)
{
  return Remove_row(static_cast<const Eigen::MatrixXd>(matrix), row);
}

/**
 * @brief Remove a column from an unsized Eigen Matrix
 * @param matrix Matrix to remove column from
 * @param col Column to remove
 * @return Matrix with column removed
 */
Eigen::MatrixXd Remove_column(const Eigen::MatrixXd& matrix, const Eigen::Index& col)
{
  Eigen::Index num_rows = matrix.rows();
  Eigen::Index num_cols = matrix.cols()-1;

  Eigen::MatrixXd out = matrix;
  if(col < num_cols)
  {
    out.block(0, col, num_rows, num_cols-col) = matrix.block(0, col+1, num_rows, num_cols-col);
  }

  out.conservativeResize(num_rows,num_cols);
  return out;
}
} // namespace Eigen_mtx_utils

#endif

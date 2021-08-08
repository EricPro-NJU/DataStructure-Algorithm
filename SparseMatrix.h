//
// Created by RUIPENG on 2021/8/3.
// Basic Data Structure 06: Sparse Matrix
// Sparse Matrix is a matrix with very few non-zero elements
// We can ignore zeros to save memory
// Implemented by Triple Tuple
//

#ifndef NJU_REVIEW_SPARSEMATRIX_H
#define NJU_REVIEW_SPARSEMATRIX_H

#include <iostream>
#include <cstdlib>
#include "commons.h"
using namespace std;

class SparseMatrix {
protected:
    struct TriTuple{
        int row;
        int col;
        T val;
        TriTuple():row(0),col(0),val(0){}
        TriTuple(int r, int c, T v):row(r),col(c),val(v){}
        TriTuple(const TriTuple& tp):row(tp.row),col(tp.col),val(tp.val){}
        TriTuple& operator = (const TriTuple& tp) {
            row = tp.row;
            col = tp.col;
            val = tp.val;
            return *this;
        }
    };
    int row, col, maxSize, num;
    TriTuple* matrix;
    void remove(int loc);
    int position(TriTuple a, TriTuple b);
public:
    SparseMatrix(int sz = defaultSize, int row = 0, int col = 0);
    SparseMatrix(const SparseMatrix& m);
    ~SparseMatrix(){delete[]matrix;}
    int getRow() const{return row;}
    int getCol() const{return col;}
    int getSize() const{return maxSize;};
    int getNum() const{return num;}

    SparseMatrix transpose();
    SparseMatrix operator + (const SparseMatrix& m);
    SparseMatrix operator * (const SparseMatrix& m);
    SparseMatrix& operator = (const SparseMatrix& m);

    bool modify(int row, int col, T data);

    friend ostream& operator << (ostream& out, SparseMatrix& m);
    //friend istream& operator >> (istream& in, SparseMatrix& m);
};

void SparseMatrixDemo();


#endif //NJU_REVIEW_SPARSEMATRIX_H

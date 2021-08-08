//
// Created by RUIPENG on 2021/8/3.
//

#include "SparseMatrix.h"

void SparseMatrixDemo(){
    SparseMatrix matrix1(defaultSize, 10, 10);
    matrix1.modify(0,3,5);
    matrix1.modify(1,1,6);
    matrix1.modify(5,7,9);
    matrix1.modify(4,0,3);
    matrix1.modify(2,7,7);
    cout << matrix1 << endl;
    SparseMatrix matrix2 = matrix1.transpose();
    cout << matrix2 << endl;
    matrix2.modify(9,9,0);
    cout << matrix2 << endl;
    matrix2.modify(0, 4, 0);
    cout << matrix2 << endl;
}

SparseMatrix::SparseMatrix(int sz, int row, int col) {
    this->maxSize = sz;
    this->row = row;
    this->col = col;
    this->num = 0;
    this->matrix = new TriTuple[sz];
}

SparseMatrix::SparseMatrix(const SparseMatrix &m) {
    this->maxSize = m.maxSize;
    this->row = m.row;
    this->col = m.col;
    this->num = m.num;
    this->matrix = new TriTuple[this->maxSize];
    for(int i = 0; i < this->num; i++){
        this->matrix[i] = m.matrix[i];
    }
}

SparseMatrix SparseMatrix::transpose() {
    SparseMatrix ret(this->maxSize, this->col, this->row);
    if(num == 0) {
        return ret;
    }
    int* rowSize = new int[col];
    int* rowStart = new int[col];
    for(int i = 0; i < col; i++) {
        rowSize[i] = 0;
    }
    for(int i = 0; i < num; i++) {
        rowSize[matrix[i].col]++;
    }
    rowStart[0] = 0;
    for(int i = 1; i < col; i++) {
        rowStart[i] = rowStart[i-1] + rowSize[i-1];
    }
    ret.num = num;
    for(int i = 0; i < num; i++) {
        int loc = rowStart[matrix[i].col];
        ret.matrix[loc].row = matrix[i].col;
        ret.matrix[loc].col = matrix[i].row;
        ret.matrix[loc].val = matrix[i].val;
        rowStart[matrix[i].col]++;
    }
    delete[]rowSize;
    delete[]rowStart;
    return ret;
}

SparseMatrix SparseMatrix::operator+(const SparseMatrix &m) {
    /*if(row != m.row || col != m.col) {
        cout << "Error! Invalid matrix size for addition." << endl;
        return SparseMatrix();
    }
    SparseMatrix res(maxSize+m.maxSize, row, col);
    int i = 0, j = 0;
    while(i<num && j<m.num) {

    }*/
    return SparseMatrix(); //not implemented
}

SparseMatrix SparseMatrix::operator*(const SparseMatrix &m) {
    return SparseMatrix(); //not implemented
}

SparseMatrix &SparseMatrix::operator=(const SparseMatrix &m) {
    this->col = m.col;
    this->row = m.row;
    this->maxSize = m.maxSize;
    this->num = m.num;
    delete[]this->matrix;
    this->matrix = new TriTuple[this->maxSize];
    for(int i = 0; i < this->num; i++){
        this->matrix[i] = m.matrix[i];
    }
    return *this;
}

ostream &operator<<(ostream &out, SparseMatrix &m) {
    out << "SparseMatrix INFO: size(" << m.row << ", " << m.col << "); ElementNum: "<<m.num;
    out << " [";
    for(int i = 0; i < m.num; i++) {
        out<<"("<<m.matrix[i].row<<", "<<m.matrix[i].col<<"):"<<m.matrix[i].val;
        if(i!=m.num-1) out<<"; ";
    }
    out<<"]";
    return out;
}



bool SparseMatrix::modify(int r, int c, T data) {
    if(r<0 || r>=row) {
        cout << "Error! Wrong location."<<endl;
        return false;
    }
    if(c<0 || c>=col) {
        cout << "Error! Wrong location." <<endl;
        return false;
    }
    if(data != 0) {
        int i;
        for(i = 0; i < num; i ++){
            if(matrix[i].row == r && matrix[i].col == c) {
                matrix[i].val = data;
                return true;
            }
            if(matrix[i].row > r || (matrix[i].row == r && matrix[i].col > c)) {
                break;
            }
        }
        //i is the insert location
        if(num == maxSize) {
            cout << "Error when modifying data. Memory exceeded." <<endl;
            return false;
        }
        for(int j = num; j > i; j--) {
            matrix[j] = matrix[j-1];
        }
        matrix[i].row = r;
        matrix[i].col = c;
        matrix[i].val = data;
        num++;
        return true;
    }
    else{
        int i;
        for(i = 0; i < num; i ++){
            if(matrix[i].row == r && matrix[i].col == c) {
                remove(i);
                return true;
            }
            if(matrix[i].row > r || (matrix[i].row == r && matrix[i].col > c)) {
                break;
            }
        }
        return true;
    }

}

void SparseMatrix::remove(int loc) {
    for(int i = loc; i < num-1; i++){
        matrix[i] = matrix[i+1];
    }
    num--;
}

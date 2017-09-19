//
//  main.cpp
//  matrix_shift
//
//  Created by Vitaliy M on 19.09.17.
//  Copyright (c) 2017 Vitaliym. All rights reserved.
//

#include <iostream>
using namespace std;

const int MATRIX_SIZE = 8;

int matrix[MATRIX_SIZE][MATRIX_SIZE] = {
        {0, 1, 2, 3, 2, 1, 0, 4},
        {1, 2, 3, 4, 5, 6, 7 ,8},
        {8, 7, 6, 5, 4, 3, 2, 1},
        {2, 1, 4, 3, 6, 7, 3, 5},
        {4, 3, 8, 2, 7, 3, 2, 1},
        {9, 5, 2, 8, 3, 6, 4, 2},
        {5, 1, 1, 2, 4, 5, 6, 3},
        {3, 4, 7, 2, 5, 1, 8, 7}
};

void swap(int & a, int & b){
    a += b;
    b = a - b;
    a -= b;
}

void reverse(int a[], int left, int right){
    if (left >= right || right >= MATRIX_SIZE) return;

    for (int i = left, j = right; i < j; i++, j--)
    {
        swap(a[i], a[j]);
    }
}

void rotate(int a[], int shift)
{
    if (shift < 0){
        while (abs(shift) >= MATRIX_SIZE){
            shift = -abs(shift) % MATRIX_SIZE;
        }
        shift += MATRIX_SIZE;
    }

    if (shift > MATRIX_SIZE) {
        shift = shift % MATRIX_SIZE;
    }
    reverse(a, 0, shift - 1);
    reverse(a, shift, MATRIX_SIZE - 1);
    reverse(a, 0, MATRIX_SIZE - 1);
}

void shift_row(int *row, int shift){
    rotate(row, shift);
}

void shift_col(int col, int shift){
    shift *= -1;
    int temp[MATRIX_SIZE] = {};
    for (int i = 0; i != MATRIX_SIZE; ++i){
        temp[i] = matrix[i][col];
    }
    shift_row(temp, shift);
    for (int i = 0; i != MATRIX_SIZE; ++i){
        matrix[i][col] = temp[i];
    }
}

int main(int argc, const char * argv[]) {
    shift_col(0, 3);
    for (int i = 0; i != MATRIX_SIZE; ++i){
        for (int j = 0; j != MATRIX_SIZE; ++j){
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;

}

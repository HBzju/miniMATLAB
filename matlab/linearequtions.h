#ifndef LINEEQUTION_H
#define LINEEQUTION_H

extern "C"
{
    #include <my++/myhead.h>
}

Vector* sloveLinear(Matrix* left, Vector *right){//方程的左边和右边
    return lspinvlinsolveVector(left,right);
}

Matrix* sloveLinear(Matrix* left, Matrix* right){
    return lspinvlinsolveMatrix(left,right);
}

#endif // LINEEQUTION_H


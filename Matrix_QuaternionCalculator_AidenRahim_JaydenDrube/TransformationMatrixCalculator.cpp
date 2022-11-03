#include "TransformationMatrixCalculator.h"
#include <cmath>
#include <iostream>

/**************************************************************************
* ScaleMatrixUnifrom: Scales the whole matrix by one user input value
* @author Aiden Rahim
* @parameter: float scale - value to scale by
* @return MatrixScale (scaled matrix) 
***************************************************************************/
MatrixStruct TransformationMatrixCalculator::ScaleMatrixUnifrom(float scale)
{

    MatrixStruct MatrixScale;
    MatrixScale.Matrix[0][0] = scale;
    MatrixScale.Matrix[1][1] = scale;
    MatrixScale.Matrix[2][2] = scale;
    MatrixScale.Matrix[3][3] = 1;

    return MatrixScale; 
}

/**************************************************************************
* ScaleMatrixNonUniform: Scales the matrix using three different user input values (x, y and z)
* @author Aiden Rahim
* @parameter: float scaleX, float scaleY, float scaleZ - values to scale by 
* @return MatrixScale (scaled matrix)
***************************************************************************/
MatrixStruct TransformationMatrixCalculator::ScaleMatrixNonUniform(float scaleX, float scaleY, float scaleZ)
{
    MatrixStruct MatrixScale;
    MatrixScale.Matrix[0][0] = scaleX;
    MatrixScale.Matrix[1][1] = scaleY;
    MatrixScale.Matrix[2][2] = scaleZ;
    MatrixScale.Matrix[3][3] = 1;
    return MatrixScale;
}


/**************************************************************************
* TranslateMatrix: translates the matrix using three user input values (x, y and z)
* @author Aiden Rahim
* @parameter: float translateX, float translateY, float translateZ - values to translate by
* @return MatrixTranslate (Translated matrix)
***************************************************************************/
MatrixStruct TransformationMatrixCalculator::TranslateMatrix(float translateX, float translateY, float translateZ)
{
    MatrixStruct MatrixTranslate;
    MatrixTranslate.Matrix[0][0] = 1;
    MatrixTranslate.Matrix[1][1] = 1;
    MatrixTranslate.Matrix[2][2] = 1;
    MatrixTranslate.Matrix[3][3] = 1;

    MatrixTranslate.Matrix[0][3] = translateX;
    MatrixTranslate.Matrix[1][3] = translateY;
    MatrixTranslate.Matrix[2][3] = translateZ; 

    return MatrixTranslate;
}

/**************************************************************************
* RotateMatrix: Rotates the matrix via user input angle 
* @author Aiden Rahim
* @parameter: float angle, Axis axis - angle and axis to rotate by 
* @return MatrixRotated (Rotated matrix)
***************************************************************************/
MatrixStruct TransformationMatrixCalculator::RotateMatrix(float angle, Axis axis)
{
    MatrixStruct MatrixRotated;

    MatrixStruct Rotation(float angle, Axis axis);
        switch (axis) {
        case Axis::X:
            MatrixRotated.Matrix[0][0] = 1;
            MatrixRotated.Matrix[1][1] = cos(angle);
            MatrixRotated.Matrix[1][2] = sin(angle);
            MatrixRotated.Matrix[2][1] = -sin(angle);
            MatrixRotated.Matrix[2][2] = cos(angle);
            MatrixRotated.Matrix[3][3] = 1;
            break;
    
        case Axis::Y:
            MatrixRotated.Matrix[1][1] = 1;
            MatrixRotated.Matrix[0][0] = cos(angle);
            MatrixRotated.Matrix[2][0] = sin(angle);
            MatrixRotated.Matrix[0][2] = -sin(angle);
            MatrixRotated.Matrix[2][2] = cos(angle);
            MatrixRotated.Matrix[3][3] = 1;
            break;
           


        case Axis::Z:
            MatrixRotated.Matrix[2][2] = 1;
            MatrixRotated.Matrix[0][0] = cos(angle);
            MatrixRotated.Matrix[0][1] = sin(angle);
            MatrixRotated.Matrix[1][0] = -sin(angle);
            MatrixRotated.Matrix[1][1] = cos(angle);
            MatrixRotated.Matrix[3][3] = 1;
            break;
            
    }


    return MatrixRotated;
}

/**************************************************************************
* ProjectMatrix: Projects the matrix using user input distance 
* @author Aiden Rahim
* @parameter: float distance, Axix axis - distance and axis to project 
* @return MatrixProjected (Projected matrix)
***************************************************************************/
MatrixStruct TransformationMatrixCalculator::ProjectMatrix(float distance, Axis axis)
{
    MatrixStruct MatrixProjected;

    MatrixStruct Projection(float angle, Axis axis);
        switch (axis) {
        case Axis::Z:
            MatrixProjected.Matrix[0][0] = 1;
            MatrixProjected.Matrix[1][1] = 1;
            MatrixProjected.Matrix[2][2] = 1;
            MatrixProjected.Matrix[2][3] = 1 / distance;
            break;

        case Axis::Y:
            MatrixProjected.Matrix[0][0] = 1;
            MatrixProjected.Matrix[1][1] = 1;
            MatrixProjected.Matrix[2][2] = 1;
            MatrixProjected.Matrix[1][3] = 1 / distance;
            break;

        case Axis::X:
            MatrixProjected.Matrix[0][0] = 1;
            MatrixProjected.Matrix[1][1] = 1;
            MatrixProjected.Matrix[2][2] = 1;
            MatrixProjected.Matrix[0][3] = 1 / distance;
            break; 

        }
        
        return MatrixProjected; 
}

/**************************************************************************
* MultiplyMatrices: Multiplies two matrices 
* @author Aiden Rahim
* @parameter: MatrixStruct* A, MatrixStruct* B - Two matrices to multiply by
* @return ProductMatrix (Multiplied matrix)
***************************************************************************/
MatrixStruct TransformationMatrixCalculator::MultiplyMaxtrices(MatrixStruct* A, MatrixStruct* B)
{
    MatrixStruct ProductMatrix;

    ProductMatrix.Matrix[0][0] = (A->Matrix[0][0] * B->Matrix[0][0]) + (A->Matrix[1][0] * B->Matrix[0][1]) + (A->Matrix[2][0] * B->Matrix[0][2]) + (A->Matrix[3][0] * B->Matrix[0][3]);
    ProductMatrix.Matrix[1][0] = (A->Matrix[0][0] * B->Matrix[1][0]) + (A->Matrix[1][0] * B->Matrix[1][1]) + (A->Matrix[2][0] * B->Matrix[1][2]) + (A->Matrix[3][0] * B->Matrix[1][3]);
    ProductMatrix.Matrix[2][0] = (A->Matrix[0][0] * B->Matrix[2][0]) + (A->Matrix[1][0] * B->Matrix[2][1]) + (A->Matrix[2][0] * B->Matrix[2][2]) + (A->Matrix[3][0] * B->Matrix[2][3]);
    ProductMatrix.Matrix[3][0] = (A->Matrix[0][0] * B->Matrix[3][0]) + (A->Matrix[1][0] * B->Matrix[3][1]) + (A->Matrix[2][0] * B->Matrix[3][2]) + (A->Matrix[3][0] * B->Matrix[3][3]);

    ProductMatrix.Matrix[0][1] = (A->Matrix[0][1] * B->Matrix[0][0]) + (A->Matrix[1][1] * B->Matrix[0][1]) + (A->Matrix[2][1] * B->Matrix[0][2]) + (A->Matrix[3][1] * B->Matrix[0][3]);
    ProductMatrix.Matrix[1][1] = (A->Matrix[0][1] * B->Matrix[1][0]) + (A->Matrix[1][1] * B->Matrix[1][1]) + (A->Matrix[2][1] * B->Matrix[1][2]) + (A->Matrix[3][1] * B->Matrix[1][3]);
    ProductMatrix.Matrix[2][1] = (A->Matrix[0][1] * B->Matrix[2][0]) + (A->Matrix[1][1] * B->Matrix[2][1]) + (A->Matrix[2][1] * B->Matrix[2][2]) + (A->Matrix[3][1] * B->Matrix[2][3]);
    ProductMatrix.Matrix[3][1] = (A->Matrix[0][1] * B->Matrix[3][0]) + (A->Matrix[1][1] * B->Matrix[3][1]) + (A->Matrix[2][1] * B->Matrix[3][2]) + (A->Matrix[3][1] * B->Matrix[3][3]);

    ProductMatrix.Matrix[0][2] = (A->Matrix[0][2] * B->Matrix[0][0]) + (A->Matrix[1][2] * B->Matrix[0][1]) + (A->Matrix[2][2] * B->Matrix[0][2]) + (A->Matrix[3][2] * B->Matrix[0][3]);
    ProductMatrix.Matrix[1][2] = (A->Matrix[0][2] * B->Matrix[1][0]) + (A->Matrix[1][2] * B->Matrix[1][1]) + (A->Matrix[2][2] * B->Matrix[1][2]) + (A->Matrix[3][2] * B->Matrix[1][3]);
    ProductMatrix.Matrix[2][2] = (A->Matrix[0][2] * B->Matrix[2][0]) + (A->Matrix[1][2] * B->Matrix[2][1]) + (A->Matrix[2][2] * B->Matrix[2][2]) + (A->Matrix[3][2] * B->Matrix[2][3]);
    ProductMatrix.Matrix[3][2] = (A->Matrix[0][2] * B->Matrix[3][0]) + (A->Matrix[1][2] * B->Matrix[3][1]) + (A->Matrix[2][2] * B->Matrix[3][2]) + (A->Matrix[3][2] * B->Matrix[3][3]);
                                                                                                                                                                  
    ProductMatrix.Matrix[0][3] = (A->Matrix[0][3] * B->Matrix[0][0]) + (A->Matrix[1][3] * B->Matrix[0][1]) + (A->Matrix[2][3] * B->Matrix[0][2]) + (A->Matrix[3][3] * B->Matrix[0][3]);
    ProductMatrix.Matrix[1][3] = (A->Matrix[0][3] * B->Matrix[1][0]) + (A->Matrix[1][3] * B->Matrix[1][1]) + (A->Matrix[2][3] * B->Matrix[1][2]) + (A->Matrix[3][3] * B->Matrix[1][3]);
    ProductMatrix.Matrix[2][3] = (A->Matrix[0][3] * B->Matrix[2][0]) + (A->Matrix[1][3] * B->Matrix[2][1]) + (A->Matrix[2][3] * B->Matrix[2][2]) + (A->Matrix[3][3] * B->Matrix[2][3]);
    ProductMatrix.Matrix[3][3] = (A->Matrix[0][3] * B->Matrix[3][0]) + (A->Matrix[1][3] * B->Matrix[3][1]) + (A->Matrix[2][3] * B->Matrix[3][2]) + (A->Matrix[3][3] * B->Matrix[3][3]);
                                                                                     
    return ProductMatrix;
}

void TransformationMatrixCalculator::PrintMatrix(MatrixStruct* matrix)
{
    MatrixStruct MatrixPrinted;

    //Row Major
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << MatrixPrinted.Matrix[i][j] << "";
        }
    }

    //Column Major
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << MatrixPrinted.Matrix[j][i] << "";
        }
    }
}



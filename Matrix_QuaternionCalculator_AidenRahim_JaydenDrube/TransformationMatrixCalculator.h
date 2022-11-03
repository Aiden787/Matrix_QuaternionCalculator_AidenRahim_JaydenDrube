#pragma once
enum class Axis {
	X,
	Y,
	Z
};

struct MatrixStruct {
	float Matrix[4][4] = { 0 };
};
class TransformationMatrixCalculator
{
public:
	static MatrixStruct ScaleMatrixUnifrom(float);
	static MatrixStruct ScaleMatrixNonUniform(float, float, float);
	static MatrixStruct TranslateMatrix(float, float, float);
	static MatrixStruct RotateMatrix(float, Axis);
	static MatrixStruct ProjectMatrix(float, Axis);
	static MatrixStruct MultiplyMaxtrices(MatrixStruct*, MatrixStruct*);
	void PrintMatrix(MatrixStruct*); 
};


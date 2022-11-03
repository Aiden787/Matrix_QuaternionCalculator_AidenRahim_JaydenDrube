#include "UI.h"
#include "TransformationMatrixCalculator.h"
#include <iostream>

void UI::MainMenu()
{
	std::cout << "Matrix Translation Calculator" << std::endl;  
	std::cout << "Please select the translations you would like to preform. 1 - Scale (Unifrom), 2 - Scale (Non Unifrom), 3 - Translate, 4 - Rotate, 5 - Project" << std::endl;
	int UserSelection;
	std::cin >> UserSelection;
	switch (UserSelection)
	{
	case 1:
		MatrixScaleUnifromInput();
		
	}
}

void UI::MatrixScaleUnifromInput()
{
	int UserScaleValue;
	std::cout << "Please enter the value you would like to scale by:" << std::endl; 
	std::cin >> UserScaleValue; 
	TransformationMatrixCalculator::ScaleMatrixUnifrom(UserScaleValue); 

}

void UI::MatrixScaleNonUnifromInput()
{
}

void UI::MatrixTranslationInput()
{
}

void UI::MatrixRotationInput()
{
}

void UI::MatrixProjectionInput()
{
}

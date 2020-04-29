#include <iostream>
#include "HeavisideStepFunction.h"
#include "SinRegularizedHeavisideStepFunction.h"
#include "AtanRegularizedHeavisideStepFunction.h"
#include "ConicShellInteriorExteriorSpatialFunction.h"
#include "EllipsoidInteriorExteriorSpatialFunction.h"
#include "SphereSpatialFunction.h"
#include "FiniteCylinderSpatialFunction.h"
#include "FrustumSpatialFunction.h"
#include "SymmetricEllipsoidInteriorExteriorSpatialFunction.h"
#include "TorusInteriorExteriorSpatialFunction.h"
#include "GaussianSpatialFunction.h"
#include "GaussianDerivativeSpatialFunction.h"
#include "BinaryThresholdSpatialFunction.h"
#include "GaussianKernelFunction.h"
#include "BSplineKernelFunction.h"

//1.FunctionBase 抽象
//|
//|--2.HeavisideStepFunctionBase 抽象 //========阶跃函数========/
//|  |
//|  |--3.HeavisideStepFunction
//|  |
//|  |--4.RegularizedHeavisideStepFunction    抽象
//|	    |
//|     |--5.SinRegularizedHeavisideStepFunction
//|     |
//|     |--6.AtanRegularizedHeavisideStepFunction
//|
//|--7.SpatialFunction 抽象 //========空间函数========/
//|  |
//|  |--8.GaussianSpatialFunction
//|  |
//|  |--9.GaussianDerivativeSpatialFunction
//|  |
//|  |--10.BinaryThresholdSpatialFunction
//|  |
//|  |--11.InteriorExteriorSpatialFunction 抽象
//|     |
//|     |--12.ConicShellInteriorExteriorSpatialFunction
//|     |
//|     |--13.EllipsoidInteriorExteriorSpatialFunction 
//|     |
//|     |--14.SphereSpatialFunction
//|     |
//|     |--15.FiniteCylinderSpatialFunction
//|     |
//|     |--16.FrustumSpatialFunction
//|     |
//|     |--17.SymmetricEllipsoidInteriorExteriorSpatialFunction
//|     |
//|     |--18.TorusInteriorExteriorSpatialFunction
//|
//|--19.KernelFunctionBase 抽象
//|  |
//|  |--20.GaussianKernelFunction
//|  |
//|  |--21.BSplineKernelFunction
//|  |
//|  |--22.BSplineDerivativeKernelFunction
//|
//|--23.BSplineInterpolationWeightFunction

int main()
{
	//HeavisideStepFunctionTest();
   
	//SinRegularizedHeavisideStepFunctionTest();

	//AtanRegularizedHeavisideStepFunctionTest();

	//ConicShellInteriorExteriorSpatialFunctionTest();

	//EllipsoidInteriorExteriorSpatialFunctionTest();

	//SphereSpatialFunctionTest();

	//FiniteCylinderSpatialFunctionTest();

	//SymmetricEllipsoidInteriorExteriorSpatialFunctionTest();

	//TorusInteriorExteriorSpatialFunctionTest();

	//GaussianSpatialFunctionTest();

	//GaussianDerivativeSpatialFunctionTest();

	//BinaryThresholdSpatialFunctionTest();

	//GaussianKernelFunctionTest();

	BSplineKernelFunctionTest();

	system("pause");
}
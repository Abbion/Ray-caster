#include "LinearMath.h"

LinearFunction CreateLinearFunction(const sf::Vector2f v_F1, const sf::Vector2f v_F2)
{
	float Ycomp = v_F1.y - v_F2.y;
	float Xcomp = v_F1.x - v_F2.x;
	float Acomp = Ycomp / Xcomp;
	float Bcomp = v_F1.y - (v_F1.x * Acomp);
	return LinearFunction{ Acomp, Bcomp };
}

LinearFunction CreatePerpendicularLinearFunction(const LinearFunction v_Function, const sf::Vector2f v_F1)
{
	float Acomp = -(1 / v_Function.a);
	float Bcomp = v_F1.y - (v_F1.x * Acomp);
	return LinearFunction{ Acomp, Bcomp };
}

sf::Vector2f GetIntersectionOfLinearFunctions(const LinearFunction v_Func1, const LinearFunction v_Func2)
{
	float Xcomp = v_Func1.a - v_Func2.a;
	float Xcomp2 = v_Func2.b - v_Func1.b;
	float Xcomp3 = Xcomp2 / Xcomp;
	float Ycomp = (v_Func1.a * Xcomp3) + v_Func1.b;
	return sf::Vector2f(Xcomp3, Ycomp);
}
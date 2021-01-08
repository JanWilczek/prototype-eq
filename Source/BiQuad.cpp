#include "BiQuad.h"

namespace proteq
{
	BiQuad::BiQuad(double b0p, double b1p, double b2p, double a1p, double a2p)
		: b0{ b0p }, b1{b1p}, b2{b2p}, a1{a1p}, a2{a2p}
	{}

	void BiQuad::setCoefficients(double b0p, double b1p, double b2p, double a1p, double a2p)
	{
		b0 = b0p;
		b1 = b1p;
		b2 = b2p;
		a1 = a1p;
		a2 = a2p;
	}

	double BiQuad::filter(double x0)
	{
		auto y0 = b0 * x0 + b1 * x1 + b2 * x2 - a1 * y1 - a2 * y2;

		x2 = x1;
		x1 = x0;

		y2 = y1;
		y1 = y0;

		return y0;
	}
}

#pragma once

namespace proteq
{
	class BiQuad
	{
	public:
		BiQuad() = default;
		BiQuad(double b0, double b1, double b2, double a1, double a2);

		void setCoefficients(double b0, double b1, double b2, double a1, double a2);
		double filter(double inputSample);

	private:
		double b0, b1, b2, a1, a2;
		double x1 = 0.0, x2 = 0.0, y1 = 0.0, y2 = 0.0;
	};
}


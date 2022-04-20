#pragma once
#include "Fint.h"

const m31::FInt Zero = m31::FInt(0);

namespace m31 {
	struct FCalc {

		// Newton-Raphson
		static FInt Sqrt(FInt value, int interatorTimes = 8) {
			if (value == Zero)
			{
				return 0;
			}
			if (value < Zero) {
				throw invalid_argument("value small than zero.");
			}

			FInt result = value;
			for (int i = 0;i< interatorTimes; i++)
			{
				result = (result + value / result) >> 1;
			}

			return result;
		}
	};
}
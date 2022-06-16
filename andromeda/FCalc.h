#pragma once
#include "Fint.h"

namespace m31 {
	
	const FInt FINT_ZERO = FInt(0);
	const FInt FINT_ONE = FInt(1);

	struct FCalc {
		// Newton-Raphson
		static FInt Sqrt(FInt value, int interatorTimes = 8) {
			if (value == FINT_ZERO)
			{
				return 0;
			}
			if (value < FINT_ZERO) {
				throw invalid_argument("value small than zero.");
			}

			FInt result = value;
			FInt history;
			int count = 0;
			do
			{
				history = result;
				result = (result + (value / result)) >> 1;
				cout << result.RawFloat() << endl;
				++count;
			
			} while (result!=history&& count < interatorTimes);
			return result;
		}
	};
}
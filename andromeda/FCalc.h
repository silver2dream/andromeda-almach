#pragma once
#include "Fint.h"
#include "FAcosTable.h"
#include "FArgs.hpp"

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

		static FArgs Acos(FInt value) {
			FInt rate = (value * FAcosTable::HalfIndexCount) + FAcosTable::HalfIndexCount;
			rate = Clamp(rate, FINT_ZERO, FAcosTable::IndexCount);
			return FArgs(FAcosTable::Table[rate.RawInt()],FAcosTable::Multipler);
		}

		static FInt Clamp(FInt input, FInt min, FInt max) {
			if (input<min)
			{
				return min;
			}
			if (input>max)
			{
				return max;
			}
			return input;
		}
	};
}
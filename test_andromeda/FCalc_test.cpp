#include "pch.h"
#include "FCalc.h"

using namespace m31;

namespace FCalcUnitTest {
	TEST(FCalcUnitTest, NewtonRaphson) {
		auto v1 = FInt(3);
		auto v = FCalc::Sqrt(v1).RawFloat();
		EXPECT_FLOAT_EQ(1.73144531f, v);
	};
}
#include "pch.h"
#include "FVector.h"

using namespace m31;

namespace FVectorUnitTest {
	TEST(FVectorTest, FVectorMultiply) {
		auto v1 = FVector::OneVector;
		v1 = v1 * 2;

		ASSERT_EQ(2.f, v1.x.RawFloat());
		ASSERT_EQ(2.f, v1.y.RawFloat());
		ASSERT_EQ(2.f, v1.z.RawFloat());
	};

	TEST(FVectorTest, FVectorAdd) {
		auto v1 = FVector::OneVector;
		auto v2 = FVector(2.f, 1.f, 6);
		v1 = v1 + v2;

		ASSERT_EQ(3.f, v1.x.RawFloat());
		ASSERT_EQ(2.f, v1.y.RawFloat());
		ASSERT_EQ(7.f, v1.z.RawFloat());
	};
}
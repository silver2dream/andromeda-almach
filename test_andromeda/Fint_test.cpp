#include "pch.h"
#include "Fint.h"

using namespace m31;

namespace FIntUnitTest {

	TEST(FIntTest, FloatPlusInt) {
		auto v1 = FInt(1);
		auto v2 = FInt(0.5f);

		ASSERT_EQ(1.5f, (v1 + v2).RawFloat());
	};

	TEST(FIntTest, LeftShift) {
		auto v1 = FInt(1);
		auto v3 = v1 << 1;

		ASSERT_EQ(2.f, v3.RawFloat());
		std::cout << v3.RawFloat();
	};

	TEST(FIntTest, MultipleCase) {
		auto v1 = FInt(500);
		auto v2 = FInt(0.3f);

		ASSERT_EQ(149, (v1 * v2).RawInt());

	};

	TEST(FIntTest, MultipleNegCase) {
		auto v1 = FInt(500);
		auto v2 = FInt(-0.3f);

		ASSERT_EQ(-149, (v1 * v2).RawInt());

	};

	TEST(FIntTest, Divisor){

		auto v3 = FInt(2);
		auto v4 = FInt(0.5f);

		ASSERT_EQ(4.f, (v3 / v4).RawFloat());
	};

	TEST(FIntTest, DivisorNegCase) {

		auto v3 = FInt(2);
		auto v4 = FInt(-0.5f);

		ASSERT_EQ(-4.f, (v3 / v4).RawFloat());
	};
}


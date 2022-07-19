#pragma once

#define M31_PI 3.14159265358979323846   // pi
#include <cmath>
#include <stdexcept>
#include <string>

using namespace std;

namespace m31 {
	struct FArgs
	{
		FArgs(int value, unsigned int multipler) {
			this->value = value;
			this->multipler = multipler;
		}

		int value;
		unsigned int multipler;

		FArgs& operator = (const FArgs v) {
			value = v.value;
			multipler = v.multipler;
			return *this;
		}
		
		bool operator > (const FArgs& b) {
			if (multipler == b.multipler)
			{
				return value > b.value;
			}
			else
			{
				throw invalid_argument("Multipler is unequal.");
			}
		}

		bool operator < (const FArgs& b) {
			if (multipler == b.multipler)
			{
				return value < b.value;
			}
			else
			{
				throw invalid_argument("Multipler is unequal.");
			}
		}

		bool operator >= (const FArgs& b) {
			if (multipler == b.multipler)
			{
				return value >= b.value;
			}
			else
			{
				throw invalid_argument("Multipler is unequal.");
			}
		}

		bool operator <= (const FArgs& b) {
			if (multipler == b.multipler)
			{
				return value <= b.value;
			}
			else
			{
				throw invalid_argument("Multipler is unequal.");
			}
		}

		bool operator == (const FArgs& b) {
			if (multipler == b.multipler)
			{
				return value == b.value;
			}
			else
			{
				throw invalid_argument("Multipler is unequal.");
			}
		}

		bool operator != (const FArgs& b) {
			if (multipler == b.multipler)
			{
				return value != b.value;
			}
			else
			{
				throw invalid_argument("Multipler is unequal.");
			}
		}

		// This is using for view angle, it can't use to calculator logic.
		int CovertViewAngle() {
			float radians = ConvertToFloat();
			return (int)round(radians / M31_PI * 180);
		}

		// This is using for view angle, it can't use to calculator logic.
		float ConvertToFloat() {
			return value * 1.0f / multipler;
		}

		string ToString() {
			return to_string(value);
		}

		static const FArgs Zero;
		static const FArgs HalfPI;
		static const FArgs PI;
		static const FArgs TwoPI;
	};

	const FArgs FArgs::Zero = FArgs(0, 10000);
	const FArgs FArgs::HalfPI = FArgs(15708, 10000);
	const FArgs FArgs::PI = FArgs(31416, 10000);
	const FArgs FArgs::TwoPI = FArgs(62832, 10000);
}
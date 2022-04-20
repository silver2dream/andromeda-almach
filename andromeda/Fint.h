#pragma once

#include <cmath>
#include <string>
#include <stdexcept>

using namespace std;

namespace m31 {

	constexpr int BIT_MOVE_TIMES = 10;
	constexpr int MULTIPLIER_FACTOR = 1 << BIT_MOVE_TIMES;

	struct FInt
	{
		FInt() {
			shiftValue = 0;
		}

		FInt(int value) {
			this->shiftValue = value * MULTIPLIER_FACTOR;
		}
		
		FInt(float value) {
			auto fv = std::round(value * MULTIPLIER_FACTOR);
			this->shiftValue = static_cast<int>(fv);
		}

		FInt& operator + (const int b) {
			auto v = FInt(shiftValue + getShiftByInt(b));
			return v;
		}
		FInt& operator + (const float b) {
			auto v = FInt(shiftValue + getShiftByfloat(b));
			return v;
		}
		FInt& operator + (const FInt& b) {
			auto v = FInt(shiftValue + b.shiftValue);
			return  v;
		}

		FInt& operator - (const int b) {
			auto v = FInt(shiftValue - getShiftByInt(b));
			return v;
		}
		FInt& operator - (const float b) {
			auto v = FInt(shiftValue - getShiftByfloat(b));
			return v;
		}
		FInt& operator - (const FInt& b) {
			auto v = FInt(shiftValue - b.shiftValue);
			return v;
		}

		FInt& operator * (const int b) {
			if (shiftValue >=0)
			{
				shiftValue = shiftValue * b;
			}
			else
			{
				shiftValue = -(-shiftValue * b);
			}
			
			return *this;
		}
		FInt& operator * (const float b) {
			long v = shiftValue * getShiftByfloat(b);
			if (shiftValue>=0)
			{
				shiftValue = v >> BIT_MOVE_TIMES;
			}
			else {
				shiftValue = - (-v >> BIT_MOVE_TIMES);
			}
			return *this;
		}
		FInt& operator * (const FInt& b) {
			long v = shiftValue * b.shiftValue;
			if (shiftValue>=0)
			{
				shiftValue = v >> BIT_MOVE_TIMES;
			}
			else
			{
				shiftValue = -(-v >> BIT_MOVE_TIMES);
			}
			return *this;
		}

		FInt& operator / (const int b) {
			if (b == 0)
			{
				throw invalid_argument("Divisor by zero.");
			}

			shiftValue = shiftValue << BIT_MOVE_TIMES / b;
			return *this;
		}
		FInt& operator / (const float b) {
			if (b == 0)
			{
				throw invalid_argument("Divisor by zero.");
			}
			shiftValue = (shiftValue << BIT_MOVE_TIMES) / getShiftByfloat(b);
			return *this;
		}
		FInt& operator / (const FInt& b) {
			if (b.shiftValue == 0)
			{
				throw invalid_argument("Divisor by zero.");
			}

			shiftValue = (shiftValue << BIT_MOVE_TIMES) / b.shiftValue;
			return *this;
		}

		FInt& operator = (const int v) {
			shiftValue = getShiftByInt(v);
			return *this;
		}
		FInt& operator = (const float v) {
			shiftValue = getShiftByfloat(v);
			return *this;
		}
		FInt& operator = (const FInt& v) {
			shiftValue = v.shiftValue;
			return *this;
		}
		
		bool operator == (const float b) {
			return shiftValue == getShiftByfloat(b);
		}
		bool operator == (const int b) {
			return shiftValue == getShiftByInt(b);
		}
		bool operator == (const FInt& b) {
			return shiftValue == b.shiftValue;
		}

		bool operator != (const float b) {
			return shiftValue != getShiftByfloat(b);
		}
		bool operator != (const int b) {
			return shiftValue != getShiftByInt(b);
		}
		bool operator != (const FInt& b) {
			return shiftValue != b.shiftValue;
		}

		bool operator > (const int b) {
			return shiftValue > getShiftByInt(b);
		}
		bool operator > (const float b) {
			return shiftValue > getShiftByfloat(b);
		}
		bool operator > (const FInt& b) {
			return shiftValue > b.shiftValue;
		}

		bool operator >= (const int b) {
			return shiftValue >= getShiftByInt(b);
		}
		bool operator >= (const float b) {
			return shiftValue >= getShiftByfloat(b);
		}
		bool operator >= (const FInt& b) {
			return shiftValue >= b.shiftValue;
		}

		bool operator < (const int b) {
			return shiftValue < getShiftByInt(b);
		}
		bool operator < (const float b) {
			return shiftValue < getShiftByfloat(b);
		}
		bool operator < (const FInt& b) {
			return shiftValue < b.shiftValue;
		}

		bool operator <= (const int b) {
			return shiftValue <= getShiftByInt(b);
		}
		bool operator <= (const float b) {
			return shiftValue <= getShiftByfloat(b);
		}
		bool operator <= (const FInt& b) {
			return shiftValue <= b.shiftValue;
		}
	
		FInt& operator >> (const int moveTimes) {
			if (shiftValue >= 0)
			{
				shiftValue = shiftValue >> moveTimes;
			}
			else
			{
				shiftValue = -(-shiftValue >> moveTimes);
			}
			
			return *this;
		}
		FInt& operator << (const int moveTimes) {
			shiftValue = shiftValue << moveTimes;
			return *this;
		}

		FInt& operator-() {
			shiftValue = -shiftValue;
			return *this;
		}

		float RawFloat() {
			return shiftValue * 1.f / MULTIPLIER_FACTOR;
		}

		int RawInt() {
			if (shiftValue>= 0)
			{
				return static_cast<int>(shiftValue >> BIT_MOVE_TIMES);
			}
			else
			{
				return -static_cast<int>(-shiftValue >> BIT_MOVE_TIMES);
			}
		}

		string ToString() {
			return to_string(RawFloat());
		}

	private:
		long shiftValue = 0;

		long getShiftByInt(int v) {
			return v * MULTIPLIER_FACTOR;
		}

		long getShiftByfloat(float v) {
			auto fv = std::round(v * MULTIPLIER_FACTOR);
			return static_cast<long>(fv);
		}

		FInt(const long newShiftValue) {
			shiftValue = newShiftValue;
		}
	};

}
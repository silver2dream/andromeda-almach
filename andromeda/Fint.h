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

		FInt operator + (const int b) {
			return FInt(shiftValue + getShiftByInt(b));
		}
		FInt operator + (const float b) {
			return FInt(shiftValue + getShiftByfloat(b));
		}
		FInt operator + (const FInt& b) {
			return FInt(shiftValue + b.shiftValue);
		}

		FInt operator - (const int b) {
			return FInt(shiftValue - getShiftByInt(b));
		}
		FInt operator - (const float b) {
			return FInt(shiftValue - getShiftByfloat(b));
		}
		FInt operator - (const FInt& b) {
			return FInt(shiftValue - b.shiftValue);
		}

		FInt operator * (const int b) {
			if (shiftValue >=0)
			{
				return FInt(shiftValue * b);
			}
			else
			{
				return FInt(-(-shiftValue * b));
			}
		}
		FInt operator * (const float b) {
			if (shiftValue>=0)
			{
				return FInt((shiftValue * getShiftByfloat(b)) >> BIT_MOVE_TIMES);
			}
			else {
				return FInt(-(-(shiftValue * getShiftByfloat(b)) >> BIT_MOVE_TIMES));
			}
		}
		FInt operator * (const FInt& b) {
			if (shiftValue>=0)
			{
				return FInt((shiftValue * b.shiftValue) >> BIT_MOVE_TIMES);
			}
			else
			{
				return FInt(-(-(shiftValue * b.shiftValue) >> BIT_MOVE_TIMES));
			}
		}

		FInt operator / (const int b) {
			if (b == 0)
			{
				throw invalid_argument("Divisor by zero.");
			}
			return FInt(shiftValue << BIT_MOVE_TIMES / b);
		}
		FInt operator / (const float b) {
			if (b == 0)
			{
				throw invalid_argument("Divisor by zero.");
			}
			return FInt((shiftValue << BIT_MOVE_TIMES) / getShiftByfloat(b));
		}
		FInt operator / (const FInt& b) {
			if (b.shiftValue == 0)
			{
				throw invalid_argument("Divisor by zero.");
			}
			return FInt((shiftValue << BIT_MOVE_TIMES) / b.shiftValue);
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
	
		FInt operator >> (const int moveTimes) {
			if (shiftValue >= 0)
			{
				return FInt(shiftValue >> moveTimes);
			}
			else
			{
				return FInt(-(-shiftValue >> moveTimes));
			}
		}
		FInt operator << (const int moveTimes) {
			return FInt(shiftValue << moveTimes);
		}

		FInt operator-() {
			return FInt(-shiftValue);
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
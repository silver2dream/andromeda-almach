#pragma once
#include <Fint.h>
#include <string>
#include <FCalc.h>

using namespace std;

namespace m31 {
	struct FVector
	{

	public:
		/*FVector(float inX, float inY, float inZ) {
			x = FInt(inX);
			y = FInt(inY);
			z = FInt(inZ);
		};*/

		FVector(FInt inX, FInt inY, FInt inZ) {
			x = inX;
			y = inY;
			z = inZ;
		};

		string ToString() {
			return x.ToString()+", " + y.ToString() +", " + z.ToString();
		}

		FInt x;
		FInt y;
		FInt z;

		static const FVector ZeroVector;
		static const FVector OneVector;
		static const FVector UpVector;
		static const FVector DownVector;
		static const FVector ForwardVector;
		static const FVector BackwardVector;
		static const FVector RightVector;
		static const FVector LeftVector;

		FVector& operator + (const FVector& b) {
			x = x + b.x;
			y = y + b.y;
			z = z + b.z;
			return *this;
		}

		FVector& operator - (const FVector& b) {
			x = x - b.x;
			y = y - b.y;
			z = z - b.z;
			return *this;
		}

		FVector& operator * (const FInt& value) {
			x = x * value;
			y = y * value;
			z = z * value;
			return *this;
		}

		FVector& operator / (const FInt& value) {
			x = x / value;
			y = y / value;
			z = z / value;
			return *this;
		}

		FVector& operator - () {
			x = -x;
			y = -y;
			z = -z;
			return *this;
		}

		bool operator == (const FVector& b) {
			return x == b.x && y == b.y && z == b.z;
		}

		bool operator != (const FVector& b) {
			return x != b.x || y != b.y || z != b.z;
		}

		FInt SqrMagnitude() {
			return x * x + y * y + z * z;
		}

		static FInt SqrMagnitude(FVector v) {
			return v.x * v.x + v.y * v.y + v.z * v.z;
		}

		FInt Magnitude(){
			auto m = FCalc::Sqrt(this->SqrMagnitude());
			return m;
		}
	};

	const FVector FVector::ZeroVector = FVector(0, 0, 0);
	const FVector FVector::OneVector = FVector(1, 1, 1);
	const FVector FVector::UpVector = FVector(0, 1, 0);
	const FVector FVector::DownVector = FVector(0, -1, 0);
	const FVector FVector::ForwardVector = FVector(0, 0, 1);
	const FVector FVector::BackwardVector = FVector(0, 0, -1);
	const FVector FVector::RightVector = FVector(1, 0, 0);
	const FVector FVector::LeftVector = FVector(-1, 0, 0);
}
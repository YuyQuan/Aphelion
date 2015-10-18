#ifndef APHELION_MATHEMATICS_VECTOR3
#define APHELION_MATHEMATICS_VECTOR3

namespace aphelion
{
	namespace mathematics
	{
		struct Vector3
		{
			float x, y, z;

			Vector3() = default;
			Vector3(const float x, const float y, const float z);

			Vector3& Add(const Vector3& other);
			Vector3& Subtract(const Vector3& other);
			Vector3& Multiply(const Vector3& other);
			Vector3& Divide(const Vector3& other);

			Vector3& operator+=(const Vector3& other);
			Vector3& operator-=(const Vector3& other);
			Vector3& operator*=(const Vector3& other);
			Vector3& operator/=(const Vector3& other);

			bool operator==(const Vector3& other);
			bool operator!=(const Vector3& other);
		};

		Vector3& operator+(Vector3* left, const Vector3& right);
		Vector3& operator-(Vector3* left, const Vector3& right);
		Vector3& operator*(Vector3* left, const Vector3& right);
		Vector3& operator/(Vector3* left, const Vector3& right);
	}
}

#endif // APHELION_MATHEMATICS_VECTOR3
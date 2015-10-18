#include "Vector3.h"

namespace aphelion
{
	namespace mathematics
	{
		Vector3::Vector3(const float x, const float y, const float z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}

		Vector3& Vector3::Add(const Vector3& other)
		{
			x += other.x;
			y += other.y;
			z += other.z;

			return *this;
		}

		Vector3& Vector3::Subtract(const Vector3& other)
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;

			return *this;
		}

		Vector3& Vector3::Multiply(const Vector3& other)
		{
			x *= other.x;
			y *= other.y;
			z *= other.z;

			return *this;
		}

		Vector3& Vector3::Divide(const Vector3& other)
		{
			if(other.x != 0) {
				x /= other.x;
			}

			if(other.y != 0) {
				y /= other.y;
			}

			if(other.z != 0) {
				z /= other.z;
			}

			return *this;
		}

		Vector3& Vector3::operator+=(const Vector3& other)
		{
			return Add(other);
		}

		Vector3& Vector3::operator-=(const Vector3& other)
		{
			return Subtract(other);
		}

		Vector3& Vector3::operator*=(const Vector3& other)
		{
			return Multiply(other);
		}

		Vector3& Vector3::operator/=(const Vector3& other)
		{
			return Divide(other);
		}

		bool Vector3::operator==(const Vector3& other)
		{
			return x == other.x && y == other.y && x == other.z;
		}

		bool Vector3::operator!=(const Vector3& other)
		{
			return !(*this == other);
		}

		Vector3& operator+(Vector3* left, const Vector3& right)
		{
			return left->Add(right);
		}

		Vector3& operator-(Vector3* left, const Vector3& right)
		{
			return left->Subtract(right);
		}

		Vector3& operator*(Vector3* left, const Vector3& right)
		{
			return left->Multiply(right);
		}

		Vector3& operator/(Vector3* left, const Vector3& right)
		{
			return left->Divide(right);
		}
	}
}

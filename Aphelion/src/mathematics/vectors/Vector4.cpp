#include "Vector4.h"

namespace aphelion
{
	namespace mathematics
	{
		Vector4::Vector4(const float x, const float y, const float z, const float w)
		{
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;
		}

		Vector4& Vector4::Add(const Vector4& other)
		{
			x += other.x;
			y += other.y;
			z += other.z;
			w += other.w;

			return *this;
		}

		Vector4& Vector4::Subtract(const Vector4& other)
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;
			w -= other.w;

			return *this;
		}

		Vector4& Vector4::Multiply(const Vector4& other)
		{
			x *= other.x;
			y *= other.y;
			z *= other.z;
			w *= other.w;

			return *this;
		}

		Vector4& Vector4::Divide(const Vector4& other)
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

			if(other.w != 0) {
				w /= other.w;
			}

			return *this;
		}

		Vector4& Vector4::operator+=(const Vector4& other)
		{
			return Add(other);
		}

		Vector4& Vector4::operator-=(const Vector4& other)
		{
			return Subtract(other);
		}

		Vector4& Vector4::operator*=(const Vector4& other)
		{
			return Multiply(other);
		}

		Vector4& Vector4::operator/=(const Vector4& other)
		{
			return Divide(other);
		}

		bool Vector4::operator==(const Vector4& other)
		{
			return x == other.x && y == other.y && x == other.z && w == other.w;
		}

		bool Vector4::operator!=(const Vector4& other)
		{
			return !(*this == other);
		}

		Vector4& operator+(Vector4* left, const Vector4& right)
		{
			return left->Add(right);
		}

		Vector4& operator-(Vector4* left, const Vector4& right)
		{
			return left->Subtract(right);
		}

		Vector4& operator*(Vector4* left, const Vector4& right)
		{
			return left->Multiply(right);
		}

		Vector4& operator/(Vector4* left, const Vector4& right)
		{
			return left->Divide(right);
		}
	}
}

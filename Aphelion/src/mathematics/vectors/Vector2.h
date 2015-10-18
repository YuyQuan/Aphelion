#ifndef APHELION_MATHEMATICS_VECTOR2
#define APHELION_MATHEMATICS_VECTOR2

namespace aphelion
{
	namespace mathematics
	{
		struct Vector2
		{
			float x, y;

			Vector2() = default;
			Vector2(const float x, const float y);

			Vector2& Add(const Vector2& other);
			Vector2& Subtract(const Vector2& other);
			Vector2& Multiply(const Vector2& other);
			Vector2& Divide(const Vector2& other);
		
			Vector2& operator+=(const Vector2& other);
			Vector2& operator-=(const Vector2& other);
			Vector2& operator*=(const Vector2& other);
			Vector2& operator/=(const Vector2& other);
		
			bool operator==(const Vector2& other);
			bool operator!=(const Vector2& other);
		};

		Vector2& operator+(Vector2* left, const Vector2& right);
		Vector2& operator-(Vector2* left, const Vector2& right);
		Vector2& operator*(Vector2* left, const Vector2& right);
		Vector2& operator/(Vector2* left, const Vector2& right);
	}
}

#endif // APHELION_MATHEMATICS_VECTOR2

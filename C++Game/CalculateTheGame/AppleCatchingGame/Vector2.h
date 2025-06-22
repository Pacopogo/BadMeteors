#pragma once
#include <cmath>
#include <SFML/System/Vector2.hpp>

namespace PabloPhysics
{

	#define V_Convert(V) (sf::Vector2f{(V).x, (V).y})

	struct Vector2
	{
		float x;
		float y;

		Vector2 operator +(const Vector2& other) const
		{
			return Vector2{ x + other.x, y + other.y };
		}

		void operator +=(const Vector2& other) 
		{
			x += other.x;
			y += other.y;
		}

		Vector2 operator -(const Vector2& other) const
		{
			return Vector2{ x - other.x, y - other.y };
		}

		void operator -=(const Vector2& other)
		{
			x -= other.x;
			y -= other.y;
		}

		Vector2 operator *(float scaler) const
		{
			return Vector2{ x * scaler, y * scaler };
		}

		void operator *=(float scaler)
		{
			x *= scaler;
			y *= scaler;
		}

		Vector2 operator /(float devider) const
		{
			return Vector2{ x / devider, y / devider };
		}

		void operator /=(float devider)
		{
			x /= devider;
			y /= devider;
		}

		Vector2 normalized() const
		{
			return Vector2{ x,y } / magnitude();
		}

		float magnitude() const
		{
			return std::sqrtf(squared_magnitude());
		}

		float squared_magnitude() const
		{
			return (x * x) + (y * y);
		}

		static Vector2 zero() 
		{
			return Vector2{ 0,0 };
		}

		static float distance(const Vector2& v1, const Vector2& v2) 
		{
			return (v1 - v2).magnitude();
		}

		static float squared_distance(const Vector2& v1, const Vector2& v2)
		{
			return (v1 - v2).squared_magnitude();
		}

		static float dot(const Vector2& v1, const Vector2& v2)
		{
			return v1.x * v2.x + v1.y * v2.y;
		}

		static float cross(const Vector2& v1, const Vector2& v2)
		{
			return (v1.x * v2.y) - (v1.y * v2.x);
		}

	};
}


#pragma once
#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>

#ifdef STATIC_LIB//STATIC
	#define MATH_DLL 
#else//DYNAMIC
	#ifdef DLL_EXPORT
		#define MATH_DLL __declspec(dllexport)
	#else
			#define MATH_DLL __declspec(dllimport)
	#endif
#endif

class Vector2
{
public:
	//--------------------------------------------------------------------------------------
	//Constructor
	//--------------------------------------------------------------------------------------
	MATH_DLL	Vector2();
	//--------------------------------------------------------------------------------------
	//Constructor
	//--------------------------------------------------------------------------------------
	MATH_DLL	Vector2(float newX , float newY);
	//--------------------------------------------------------------------------------------
	//Deconstructor
	//--------------------------------------------------------------------------------------
	MATH_DLL	~Vector2();
	//--------------------------------------------------------------------------------------
	// Adds two vector2s together
	//
	// Param:
	//		takes in a vector2
	// Return:
	//		returns the result
	//--------------------------------------------------------------------------------------
	MATH_DLL	Vector2 operator+(const Vector2& rhs);
	//--------------------------------------------------------------------------------------
	// Subtracts two vector2s together
	//
	// Param:
	//		takes in a vector2
	// Return:
	//		returns the result
	//--------------------------------------------------------------------------------------
	MATH_DLL	Vector2 operator-(const Vector2& rhs);
	//--------------------------------------------------------------------------------------
	// times two vector4s together
	//
	// Param:
	//		takes in a vector2
	// Return:
	//		returns the result
	//--------------------------------------------------------------------------------------
	MATH_DLL	Vector2 operator*(const float rhs);
	//--------------------------------------------------------------------------------------
	// takes two equal-length sequences of numbers and returns a single number.
	//
	// Param:
	//		takes in a vector2
	// Return:
	//		returns the result
	//--------------------------------------------------------------------------------------
	MATH_DLL	float Dot(Vector2& rhs);
	//--------------------------------------------------------------------------------------
	// returns true or false depending on if the number is greater than the other number
	//
	// Param:
	//		input: takes a vector2
	// Return:
	//		returns true or false
	//--------------------------------------------------------------------------------------
	MATH_DLL	bool operator> (const Vector2& rhs);
	//--------------------------------------------------------------------------------------
	// returns true or false depending on if the number is less than the other number
	//
	// Param:
	//		takes in a vector2
	// Return:
	//		returns true or false
	//--------------------------------------------------------------------------------------
	MATH_DLL	bool operator< (const Vector2& rhs);
	//--------------------------------------------------------------------------------------
	// returns true or false depending on if the number is equal to the other number
	//
	// Param:
	//		takes in a vector2
	// Return:
	//		returns true or false
	//--------------------------------------------------------------------------------------
	MATH_DLL	bool operator==(const Vector2& rhs);
	//--------------------------------------------------------------------------------------
	// returns true or false depending on if the number does not equal to the other number
	//
	// Param:
	//		takes in a vector2
	// Return:
	//		returns true or false
	//--------------------------------------------------------------------------------------
	MATH_DLL	bool operator!=(const Vector2& rhs);
	//--------------------------------------------------------------------------------------
	// returns true or false depending on if the number greater than or equal to the other number
	//
	// Param:
	//		takes in a vector2
	// Return:
	//		returns true or false
	//--------------------------------------------------------------------------------------
	MATH_DLL	bool operator<=(const Vector2& rhs);
	//--------------------------------------------------------------------------------------
	// returns true or false depending on if the number less than or equal to the other number
	//
	// Param:
	//		takes in a vector2
	// Return:
	//		returns true or false
	//--------------------------------------------------------------------------------------
	MATH_DLL	bool operator>=(const Vector2& rhs);
	//--------------------------------------------------------------------------------------
	//How large an object is
	//
	// Param:
	//		none
	// Return:
	//		returns the result
	//--------------------------------------------------------------------------------------
	MATH_DLL	float Magnitude();
	//--------------------------------------------------------------------------------------
	//square of a magnitude
	//
	// Param:
	//		none
	// Return:
	//		returns the result
	//--------------------------------------------------------------------------------------
	MATH_DLL	float sqrMagnitude();
	//--------------------------------------------------------------------------------------
	//multiply by a factor that makes an integral equal to a desired value
	//
	// Param:
	//		Takes in a Vector2
	// Return:
	//		returns the result
	//--------------------------------------------------------------------------------------
	MATH_DLL	void Normalise();
	//--------------------------------------------------------------------------------------
	//normalise the magnitude
	//
	// Param:
	//		Takes in a Vector2
	// Return:
	//		returns the result
	//--------------------------------------------------------------------------------------
	MATH_DLL	Vector2 Normalised(Vector2& data);
	//--------------------------------------------------------------------------------------
	//calculates the distance between two vector4s
	//
	// Param:
	//		Takes in a Vector2
	// Return:
	//		returns the dist
	//--------------------------------------------------------------------------------------
	MATH_DLL	float Distance(Vector2& rhs);
	//--------------------------------------------------------------------------------------
	//Divides two vectors
	//
	// Param:
	//		Takes in a float
	// Return:
	//		returns the result
	//--------------------------------------------------------------------------------------
	MATH_DLL	Vector2 operator/(const float rhs);
	//--------------------------------------------------------------------------------------
	//positive number
	//
	// Param:
	//		none
	// Return:
	//		returns the result
	//--------------------------------------------------------------------------------------
	MATH_DLL	Vector2 posOperator();
	//--------------------------------------------------------------------------------------
	//negative number
	//
	// Param:
	//		none
	// Return:
	//		returns the result
	//--------------------------------------------------------------------------------------
	MATH_DLL	Vector2 operator-();
	//--------------------------------------------------------------------------------------
	//short for x = x + y
	//
	// Param:
	//		Takes in a Vector2
	// Return:
	//		returns the result
	//--------------------------------------------------------------------------------------
	MATH_DLL	Vector2 operator+=(const Vector2& rhs);
	MATH_DLL	float & operator[](const int rhs);
	MATH_DLL	operator float*();
	//--------------------------------------------------------------------------------------
	//calculates the minimum of the vector2
	//
	// Param:
	//		Takes in a Vector2
	// Return:
	//		returns the result
	//--------------------------------------------------------------------------------------
	MATH_DLL	Vector2 min(const Vector2& rhs);
	//--------------------------------------------------------------------------------------
	//calculates the maximum of the vector2
	//
	// Param:
	//		Takes in a Vector2
	// Return:
	//		returns the result
	//--------------------------------------------------------------------------------------
	MATH_DLL	Vector2 max(const Vector2& rhs);
	//--------------------------------------------------------------------------------------
	//moves the point to the nearest available value.
	//
	// Param:
	//		Takes in two Vector2s
	// Return:
	//		returns the result
	//--------------------------------------------------------------------------------------
	MATH_DLL	Vector2 clamp(Vector2& min, Vector2 & max);
	//--------------------------------------------------------------------------------------
	//interpolation between two values
	//
	// Param:
	//		Takes in two Vector2s and a float
	// Return:
	//		none
	//--------------------------------------------------------------------------------------
	MATH_DLL	Vector2 lerp(Vector2 a, Vector2 b, float t);
	//--------------------------------------------------------------------------------------
	//compound linear interpolations
	//
	// Param:
	//		Takes in three Vector2s and a float
	// Return:
	//		none
	//--------------------------------------------------------------------------------------
	MATH_DLL	Vector2 quadraticBezier(Vector2 a, Vector2 b, Vector2 c, float t);
	//--------------------------------------------------------------------------------------
	//compound linear interpolations with tangents
	//
	// Param:
	//		Takes in four Vector2s and a float
	// Return:
	//		none
	//--------------------------------------------------------------------------------------
	MATH_DLL	Vector2 hermiteCurve(Vector2 point0, Vector2 tangent0, Vector2 point1, Vector2 tangent1, float t);
	//--------------------------------------------------------------------------------------
	//Swizzles the elements of the vector, assigning differing values depending on the variables in the function name
	//
	// Param:
	//		none
	// Return:
	//		returns the result
	//--------------------------------------------------------------------------------------
	MATH_DLL	Vector2 xx();
	MATH_DLL	Vector2 xy();
	MATH_DLL	Vector2 yx();
	MATH_DLL	Vector2 yy();
	
	float x;
	float y;
};
//--------------------------------------------------------------------------------------
// times a float and a vector2 together
//
// Param:
//		takes in a vector2
// Return:
//		returns the result
//--------------------------------------------------------------------------------------
MATH_DLL Vector2 operator*(float lhs, const Vector2 rhs);

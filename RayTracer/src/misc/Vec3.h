
// Represents a 3-dimensional vector

#pragma once

#include <concepts> 

// enforces numeric types
template<typename T>
concept arithmetic = std::integral<T> || std::floating_point<T>;

template <typename T> 
	requires arithmetic<T>
class Vec3
{

public:

	Vec3();
	Vec3(T in_num1, T in_num2, T in_num3);

	T m_Values[3];

	// getters
	inline double x() const { return m_Values[0]; }
	inline double y() const { return m_Values[1]; }
	inline double z() const { return m_Values[2]; }

};



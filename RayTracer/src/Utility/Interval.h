

#pragma once

#include <cmath>

class Interval
{

public:

	const static Interval universe;

	Interval(const float in_min, const float in_max);

	// getters
	inline float getMin() const { return m_min; }
	inline float getMax() const { return m_max; }

	bool contains(const float in_val) const;
	bool surrounds(const float in_val) const;
	float clamp(const float in_val) const;

private:

	const float m_min;
	const float m_max;


};

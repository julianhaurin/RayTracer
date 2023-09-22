
#include "Interval.h"

const Interval Interval::universe(INT_MIN, INT_MAX);

// Public Methods //

Interval::Interval(const float in_min, const float in_max)
	: m_min(in_min), m_max(in_max)
{}

// inclusive
bool Interval::contains(const float in_val) const {
	return m_min <= in_val && in_val <= m_max;
}

// not inclusive
bool Interval::surrounds(const float in_val) const {
	return m_min < in_val && in_val < m_max;
}

// Private Methods //


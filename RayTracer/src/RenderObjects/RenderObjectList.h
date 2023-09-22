
// List of render objects

#pragma once

#include "RenderObject.h"

#include <vector>
#include <memory>

#include "../Ray.h"

class RenderObjectList : public RenderObject
{

public:

	RenderObjectList();
	RenderObjectList(const std::shared_ptr<RenderObject> in_renderObject);

	~RenderObjectList();

	// list functions
	inline void addObject(const std::shared_ptr<RenderObject> in_object) { m_RenderObjects.push_back(in_object); };
	inline void clearObjects() { m_RenderObjects.clear(); }

	bool isHit(const Ray& in_ray, Interval in_interval, HitRecord& in_hitRecord) const override;

private:

	std::vector<std::shared_ptr<RenderObject>> m_RenderObjects;

};
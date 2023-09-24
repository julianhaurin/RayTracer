
#include "RenderObjectList.h"

// Public Methods //

RenderObjectList::RenderObjectList() 
    : m_RenderObjects(std::vector<std::shared_ptr<RenderObject>>())
{}

RenderObjectList::RenderObjectList(const std::shared_ptr<RenderObject> in_renderObject)
    : m_RenderObjects(std::vector<std::shared_ptr<RenderObject>>())
{
    addObject(in_renderObject);
}

RenderObjectList::~RenderObjectList() {

}


bool RenderObjectList::isHit(const Ray& in_ray, Interval in_interval, HitRecord& in_hitRecord) const {
    
    HitRecord tempHitRec;

    bool hitAnything = false;
    float closestSoFar = in_interval.getMax();

    for (const auto& object : m_RenderObjects) {
        if (object->isHit(in_ray, Interval(in_interval.getMin(), closestSoFar), tempHitRec)) {
            hitAnything = true;
            closestSoFar = tempHitRec.m_t;
            in_hitRecord = tempHitRec;
        }
    }

    return hitAnything;
}

// Private Methods //



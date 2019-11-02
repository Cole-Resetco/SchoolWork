#include "plane.h"
#include "ray.h"
#include <cfloat>


// Intersect with the half space defined by the plane.  The plane's normal
// points outside.  If the ray starts on the "inside" side of the plane, be sure
// to record a hit with t=0 as the first entry in hits.
bool Plane::
Intersection(const Ray& ray, std::vector<Hit>& hits) const
{
    // TODO
    // t = -((u - x1) . n) / (v . n)
    double t = -(dot(ray.endpoint - x1, normal)) / dot(ray.direction, normal);
    
    if(t > small_t)
    {
		Hit h;
		if(((dot(ray.endpoint - x1, normal)) <= 0) &&  ((dot(ray.direction, normal)) > 0))
		{
			h.ray_exiting = true;
		}
		else
		{
			h.ray_exiting = false;
		}
		
		h.t = t;
		h.object = this;
		hits.push_back(h);
		return true;
	}	
    return false;
}

vec3 Plane::
Normal(const vec3& point) const
{
    return normal;
}

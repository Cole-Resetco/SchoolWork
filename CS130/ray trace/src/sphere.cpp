#include "sphere.h"
#include "ray.h"


// Determine if the ray intersects with the sphere
bool Sphere::Intersection(const Ray& ray, std::vector<Hit>& hits) const
{
	double t1, t2;
    vec3 w = ray.direction;
    vec3 u = ray.endpoint;
    double r = radius;
    vec3 c = center;
    vec3 v = u - c;
    double D = ((dot(w,v)) * (dot(w,v))) - ((dot(v,v)) - (r * r));
    
    if(D > 0)
    {
		t1 = -((dot(w,v) + (sqrt(D))));
		
		t2 = -((dot(w,v) - (sqrt(D))));
		
		Hit h1 = {this, t1, true};
		Hit h2 = {this, t2, true};
		
		if(t1 >= 0)
		{	
			hits.push_back(h1);
		}
		if(t2 >= 0)
		{	
			hits.push_back(h2);
		}
	}
    else{
		return false;
	}
}

vec3 Sphere::Normal(const vec3& point) const
{
    vec3 normal = point - center;
    normal /= normal.magnitude();
    // TODO: set the normal
    return normal;
}

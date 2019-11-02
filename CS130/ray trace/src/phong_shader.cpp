#include "light.h"
#include "phong_shader.h"
#include "ray.h"
#include "render_world.h"
#include "object.h"
#include <cmath>



vec3 Phong_Shader::
Shade_Surface(const Ray& ray,const vec3& intersection_point,
    const vec3& same_side_normal,int recursion_depth) const
{
    vec3 color;
    
    color += (color_ambient)*(world.ambient_color) * (world.ambient_intensity);
    
    for (int i = 0; i < world.lights.size(); i++)
    {
		//max(dot(l,n),0) * color_diffuse * light_color
		vec3 l = world.lights.at(i)->position - intersection_point;
		vec3 diff = std::max(dot(l.normalized(), same_side_normal), 0.0) * color_diffuse * world.lights.at(i)->Emitted_Light(ray)/(l.magnitude_squared());
		
		vec3 Rs = (2 *(dot(l.normalized(), same_side_normal)) * same_side_normal - l.normalized());
		vec3 viewpoint =  ray.endpoint - intersection_point;
		vec3 spec = pow(std::max(dot(Rs.normalized(), viewpoint.normalized()), 0.0),specular_power) * color_specular * world.lights.at(i)->Emitted_Light(ray)/(l.magnitude_squared());
		
		Hit newHit;
		if(world.enable_shadows)
		{
			Ray newRay;
			newRay.endpoint = intersection_point;
			newRay.direction = (world.lights.at(i)->position - intersection_point).normalized();
			newRay.endpoint = newRay.endpoint + (newRay.direction * small_t);
			if(world.Closest_Intersection(newRay, newHit)) continue;
		}
		
		
		color += diff + spec;
	}
    
    return color;
}

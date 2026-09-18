#pragma once

#include <cmath>
#include <cassert>

/*
PROMPT #1:

I want to create a math library. 

1. create a class vec3 (exportable) that has a constructor which takes in three floats x, y, z, creating a vec3 object
2. create a class method `add` that takes in two vec3 objects
2.1 add x1 to x2, y1 to y2, y3 to y3 using + operator.
2.2 return resulting vec3 object created using the resulting new x, y, z values.

PROMPT #2:

do the same for substraction

PROMPT #3:

create a function dot that returns a scalar given two vec3 objects. the scalar (type float) should be x1*x2+y1*y2+z1*z2.

PROMPT #4:

create helper method vectorLength. it should receive a Vec3 object and return float scalar equivlent of sqrt(x**2+y**2+z**2)

create normalize function that takes a Vec3 object. it should return a vec3 object equivalent of (x/vectorLength(x), x/vectorLength(y), x/vectorLength(z))

for edge case of dividing by zero, add an assertion that displays and error message

PROMPT #5:

create a scalar multiply function that takes a vec3 object v and a float scalar c. it returns a vec3 → (c*x_v, c*y_v, c*z_v)

*/

class Vec3 {
public:
    float x, y, z;

    Vec3(float x = 0.0f, float y = 0.0f, float z = 0.0f);

    Vec3 operator+(const Vec3& other) const;
    Vec3 operator-(const Vec3& other) const;

    static Vec3 add(const Vec3& a, const Vec3& b);
    static Vec3 subtract(const Vec3& a, const Vec3& b);
    static float dot(const Vec3& a, const Vec3& b);
    static Vec3 cross(const Vec3& a, const Vec3& b);
    static float vectorLength(const Vec3& v);
    static Vec3 normalize(const Vec3& v);
    static Vec3 scalarMultiply(const Vec3& v, float c);
};

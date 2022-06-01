#ifndef __MATH__MATH_H__
#define __MATH__MATH_H__
namespace framework::math
{
    struct vec2
    {
        float m_x, m_y;

        vec2(float x, float y)
            : m_x(x), m_y(y)
        {
        }
    };

    struct vec2i
    {
        int m_x, m_y;

        vec2i(int x, int y)
            : m_x(x), m_y(y)
        {
        }

        bool operator==(const vec2i& other)
        {
            return m_x == other.m_x && m_y == other.m_y;
        }
    };

    struct vec3
    {
        float m_x, m_y, m_z;

        vec3(float x, float y, float z)
            : m_x(x), m_y(y), m_z(z)
        {
        }

        vec3(int x, int y, int z)
        {
            m_x = static_cast<float>(x);
            m_y = static_cast<float>(y);
            m_z = static_cast<float>(z);
        }
    };
}
#endif // __MATH__MATH_H__

#ifndef __SDK__VARIANT_H__
#define __SDK__VARIANT_H__

#include <vector>
#include <string>
#include <iomanip>
#include <variant>

#include "config/macros.h"

#include "math/math.h"

#include "packet.h"
#include "update.h"

namespace framework
{
    enum
    {
        VARIANT_UNKNOWN,
        VARIANT_FLOAT,
        VARIANT_STR,
        VARIANT_VEC2,
        VARIANT_VEC3,
        VARIANT_UINT,
        VARIANT_INT = 9
    };

    using variant = std::variant<float, std::string, math::vec2, math::vec3, uint32_t, int>;

    class variantlist
    {
    public:
        variantlist(const variant& v0) : m_variants({v0}) {}
        variantlist(const variant& v0, const variant& v1) : m_variants({v0,v1}) {}
        variantlist(const variant& v0, const variant& v1, const variant& v2) : m_variants({v0,v1,v2}) {}
        variantlist(const variant& v0, const variant& v1, const variant& v2, const variant& v3) : m_variants({v0,v1,v2,v3}) {}
        variantlist(const variant& v0, const variant& v1, const variant& v2, const variant& v3, const variant& v4) : m_variants({v0,v1,v2,v3,v4}) {}
        variantlist(const variant& v0, const variant& v1, const variant& v2, const variant& v3, const variant& v4, const variant& v5) : m_variants({v0,v1,v2,v3,v4,v5}) {}
        variantlist(const variant& v0, const variant& v1, const variant& v2, const variant& v3, const variant& v4, const variant& v5, const variant& v6) : m_variants({v0,v1,v2,v3,v4,v5,v6}) {}

        FRAMEWORK_EXPORT int get_type(const variant& var) const;

        // gotta make this cleaner, soon.
        gameupdatepacket_t* pack() const;

    private:
        std::vector<variant> m_variants;
    };
}

#endif // __SDK__VARIANT_H__
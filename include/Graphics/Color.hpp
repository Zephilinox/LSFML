#ifndef COLOR_HPP
#define COLOR_HPP

#include <Lua5.2/lua.hpp>
#include <LuaBridge/luabridge.h>
#include <SFML/Graphics/Color.hpp>

namespace lsf
{

class Color
{
public:
    Color() = default;
    Color(float, float, float, float);
    Color(const sf::Color&);

    Color getCopy();

    Color add (const Color&);
    Color sub (const Color&);

    float getR() const;
    float getG() const;
    float getB() const;
    float getA() const;

    void setR(float);
    void setG(float);
    void setB(float);
    void setA(float);

    sf::Color m_color;
};

} //lsf

void registerColor(lua_State* L);

#endif

#ifndef VECTOR2_HPP
#define VECTOR2_HPP

#include <Lua5.2/lua.hpp>
#include <LuaBridge/luabridge.h>
#include <SFML/System/Vector2.hpp>

namespace lsf
{

class Vector2
{
public:
    Vector2() = default;
    Vector2(float, float);
    Vector2(sf::Vector2f vec);

    Vector2 getCopy();

    void setX(float);
    void setY(float);

    float getX() const;
    float getY() const;

    sf::Vector2f m_vector;
};

} //lsf

void registerVector2(lua_State* L);

#endif

#include "System/Vector2.hpp"

#include <iostream>

namespace lsf
{
    Vector2::Vector2(float x, float y)
        : m_vector(x, y)
    {
    }

    Vector2::Vector2(sf::Vector2f vec)
        : m_vector(vec)
    {
    }

    Vector2 Vector2::getCopy()
    {
        return m_vector;
    }

    void Vector2::setX(float x)
    {
        m_vector.x = x;
    }

    void Vector2::setY(float y)
    {
        m_vector.y = y;
    }

    float Vector2::getX() const
    {
        return m_vector.x;
    }

    float Vector2::getY() const
    {
        return m_vector.y;
    }

} //lsf

void registerVector2(lua_State* L)
{
    luabridge::getGlobalNamespace(L)
        .beginNamespace("sfml")
            .beginClass<lsf::Vector2>("Vector2")
                .addConstructor<void(*)(float, float)>()
                .addFunction("getCopy", &lsf::Vector2::getCopy)
                .addProperty("x", &lsf::Vector2::getX, &lsf::Vector2::setX)
                .addProperty("y", &lsf::Vector2::getY, &lsf::Vector2::setY)
            .endClass()
        .endNamespace()
    ;
}

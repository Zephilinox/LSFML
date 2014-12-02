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

    Vector2 Vector2::add(const Vector2& vec)
    {
        return m_vector + vec.m_vector;
    }

    Vector2 Vector2::sub(const Vector2& vec)
    {
        return m_vector - vec.m_vector;
    }

    Vector2 Vector2::mul(float scalar)
    {
        return m_vector * scalar;
    }

    Vector2 Vector2::div(float scalar)
    {
        return m_vector / scalar;
    }

    bool Vector2::eq(const Vector2& vec)
    {
        return m_vector == vec.m_vector;
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
                .addFunction("__add", &lsf::Vector2::add)
                .addFunction("__sub", &lsf::Vector2::sub)
                .addFunction("__mul", &lsf::Vector2::mul)
                .addFunction("__div", &lsf::Vector2::div)
                .addFunction("__eq", &lsf::Vector2::eq)
                .addFunction("getCopy", &lsf::Vector2::getCopy)
                .addProperty("x", &lsf::Vector2::getX, &lsf::Vector2::setX)
                .addProperty("y", &lsf::Vector2::getY, &lsf::Vector2::setY)
            .endClass()
        .endNamespace()
    ;
}

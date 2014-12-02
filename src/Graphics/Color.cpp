#include "Graphics/Color.hpp"

#include <iostream>

namespace lsf
{
    Color::Color(float r, float g, float b, float a)
        : m_color(r, g, b, a)
    {
    }

    float Color::getR() const
    {
        return m_color.r;
    }

    float Color::getG() const
    {
        return m_color.g;
    }

    float Color::getB() const
    {
        return m_color.b;
    }

    float Color::getA() const
    {
        return m_color.a;
    }

    void Color::setR(float r)
    {
        m_color.r = r;
    }

    void Color::setG(float g)
    {
        m_color.g = g;
    }

    void Color::setB(float b)
    {
        m_color.b = b;
    }

    void Color::setA(float a)
    {
        m_color.a = a;
    }

} //lsf

void registerColor(lua_State* L)
{
    luabridge::getGlobalNamespace(L)
        .beginNamespace("sfml")
            .beginClass<lsf::Color>("Color")
                .addConstructor<void(*)(float, float, float, float)>()
                .addProperty("r", &lsf::Color::getR, &lsf::Color::setR)
                .addProperty("g", &lsf::Color::getG, &lsf::Color::setG)
                .addProperty("b", &lsf::Color::getB, &lsf::Color::setB)
                .addProperty("a", &lsf::Color::getA, &lsf::Color::setA)
            .endClass()
        .endNamespace()
    ;
}

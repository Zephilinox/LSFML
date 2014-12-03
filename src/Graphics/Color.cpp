#include "Graphics/Color.hpp"

#include <iostream>

namespace lsf
{
    Color::Color(float r, float g, float b, float a)
        : m_color(r, g, b, a)
    {
    }

    Color::Color(const sf::Color& col)
        : m_color(col)
    {
    }

    Color Color::getCopy()
    {
        return Color(m_color);
    }

    Color Color::add (const Color& col)
    {
        return Color(m_color+col.m_color);
    }

    Color Color::sub (const Color& col)
    {
        sf::Color c(std::max(0, int(m_color.r - col.m_color.r)),
                    std::max(0, int(m_color.g - col.m_color.g)),
                    std::max(0, int(m_color.b - col.m_color.b)),
                    std::max(0, int(m_color.a - col.m_color.a)));

        return Color(c);
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
                .addFunction("getCopy", &lsf::Color::getCopy)
                .addFunction("__add", &lsf::Color::add)
                .addFunction("__sub", &lsf::Color::sub)
                .addProperty("r", &lsf::Color::getR, &lsf::Color::setR)
                .addProperty("g", &lsf::Color::getG, &lsf::Color::setG)
                .addProperty("b", &lsf::Color::getB, &lsf::Color::setB)
                .addProperty("a", &lsf::Color::getA, &lsf::Color::setA)
            .endClass()
        .endNamespace()
    ;
}

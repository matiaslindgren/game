/*
* Copyright (c) 2006-2007 Erin Catto http://www.box2d.org
* Copyright (c) 2013 Google, Inc.
*
* This software is provided 'as-is', without any express or implied
* warranty.  In no event will the authors be held liable for any damages
* arising from the use of this software.
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely, subject to the following restrictions:
* 1. The origin of this software must not be misrepresented; you must not
* claim that you wrote the original software. If you use this software
* in a product, an acknowledgment in the product documentation would be
* appreciated but is not required.
* 2. Altered source versions must be plainly marked as such, and must not be
* misrepresented as being the original software.
* 3. This notice may not be removed or altered from any source distribution.
*/

// This header has been altered from the original Box2D header

#ifndef DEBUGDRAW_H
#define DEBUGDRAW_H
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

// This class implements debug drawing callbacks that are invoked
// inside b2World::Step.
class DebugDraw : public b2Draw
{
public:
  DebugDraw(sf::RenderWindow& window) : m_window(window), b2Draw() {};

	void DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);

	void DrawFlatPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);

	void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);

	void DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color);

	void DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color);

	void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color);

	void DrawParticles(const b2Vec2 *centers, float32 radius, const b2ParticleColor *colors, int32 count);

	void DrawTransform(const b2Transform& xf);

	void DrawPoint(const b2Vec2& p, float32 size, const b2Color& color);

	void DrawString(int x, int y, const char* string, ...);

	void DrawString(const b2Vec2& p, const char* string, ...);

	void DrawAABB(b2AABB* aabb, const b2Color& color);

private:
  sf::RenderWindow& m_window;

  sf::Color b2color_to_sfml(const b2Color& b2_color) const
  {
    return sf::Color(b2_color.r*255, b2_color.g*255, b2_color.b*255);
  }

  sf::Vector2f b2Vec2_to_sfml(const b2Vec2& b2_vector) const
  {
    return sf::Vector2f(b2_vector.x, -b2_vector.y);
  }

};

float ComputeFPS();

void LoadOrtho2DMatrix(double left, double right, double bottom, double top);

#endif

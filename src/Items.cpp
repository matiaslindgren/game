#include "Items.hpp"

void CreateCup(b2Body* body, const b2Vec2& position, const b2Vec2& size)
{
  const float& width = size.x;
  const float& height = size.y;
  static constexpr auto edge_thickness = 0.5f;
  static constexpr auto side_slope = 0.2f;

  b2Vec2 left_side[] = {
    b2Vec2(0, height),
    b2Vec2(edge_thickness, height),
    b2Vec2(edge_thickness + side_slope, 0),
    b2Vec2(side_slope, 0)
  };

  b2Vec2 right_side[4];
  for (auto i = 0; i < 4; i++)
  {
    right_side[i] = left_side[i] + b2Vec2(width, 0);
  }
  right_side[0].x += 2*side_slope;
  right_side[1].x += 2*side_slope;

  b2Vec2 bottom[] = {
    left_side[3],
    right_side[2],
    right_side[2] - b2Vec2(0, edge_thickness),
    left_side[3] - b2Vec2(0, edge_thickness)
  };

  b2Vec2* fixture_vertices[] = {
    left_side,
    right_side,
    bottom
  };

  for (auto i = 0; i < 3; i++)
  {
    for (auto j = 0; j < 4; j++)
    {
      fixture_vertices[i][j].x += position.x;
      fixture_vertices[i][j].y += -(position.y + height);
    }
  }

  for (auto i = 0; i < 3; i++)
  {
    b2PolygonShape shape;
    shape.Set(fixture_vertices[i], 4);

    b2FixtureDef fixture_def;
    fixture_def.shape = &shape;
    // Cups are light and bouncy
    fixture_def.density = 0.4f;
    fixture_def.restitution = 0.5f;
    b2Fixture* fixture = body->CreateFixture(&fixture_def);
    fixture->SetUserData(new Polygon(fixture_vertices[i], 4, sf::Color(50, 50, 250, 150)));
  }
}


void CreateBox(b2Body* body, const b2Vec2& position, const b2Vec2& size)
{
  const float& width = size.x;
  const float& height = size.y;

  b2Vec2 vertices[] = {
    b2Vec2(0, 0),
    b2Vec2(width, 0),
    b2Vec2(width, height),
    b2Vec2(0, height)
  };

  for (auto i = 0; i < 4; i++)
  {
    vertices[i] += position;
    vertices[i].y *= -1;
  }

  {
    b2PolygonShape shape;
    shape.Set(vertices, 4);

    b2FixtureDef fixture_def;
    fixture_def.shape = &shape;
    if (body->GetType() == b2_dynamicBody)
    {
      // Boxes should appear heavy with great inertia
      fixture_def.density = 2.0f;
      fixture_def.restitution = 0.15f;
    }
    b2Fixture* fixture = body->CreateFixture(&fixture_def);
    fixture->SetUserData(new Polygon(vertices, 4, sf::Color(150, 150, 150, 50)));
  }
}

void CreateDispenserItem(b2Body* body, const b2Vec2& position, const float& particle_radius, sf::Texture* texture)
{
  const float& height = 35*particle_radius;
  const float& width = 8*particle_radius;

  b2Vec2 nozzle_vertices[] = {
    b2Vec2(0, 0),
    b2Vec2(0, height),
    b2Vec2(width, height),
    b2Vec2(width, 0),
  };

  for (auto i = 0; i < 4; i++)
  {
    nozzle_vertices[i].x += position.x - width/2;
    nozzle_vertices[i].y += -(position.y + height/3);
  }

  b2ChainShape shape;
  shape.CreateChain(nozzle_vertices, 4);

  b2FixtureDef fixture_def;
  fixture_def.shape = &shape;
  b2Fixture* fixture = body->CreateFixture(&fixture_def);
  fixture->SetUserData(new DrawableDispenser(nozzle_vertices, 4, texture));

/* static constexpr unsigned int k_TriangleFanSegments = 24; */
/* static constexpr float k_Increment = 2.0f * b2_pi / k_TriangleFanSegments;; */
/*   sf::VertexArray  button_vertices_(sf::TrianglesFan, k_TriangleFanSegments + 2), */
/*   float theta = 0.0f; */
/*   sf::Vector2f sfml_center = sf::Vector2f(button_center.x, button_center.y); */
/*   sf::Color sfml_color = sf::Color::Red; */
/*   for (auto i = 0; i < button_vertices_.getVertexCount(); i++) */
/*   { */
/*     button_vertices_[i].position = sfml_center + button_radius*sf::Vector2f(cosf(theta), sinf(theta)); */
/*     button_vertices_[i].color = sfml_color; */
/*     theta += k_Increment; */
/*   } */

}


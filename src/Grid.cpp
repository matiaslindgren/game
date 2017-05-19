#include "Grid.hpp"


Grid::Grid(const float& top, const float& left,
           const float& line_length, const float& offset)
  : lines(sf::Lines)
{
  for (auto delta = 0.0f; delta < line_length; delta += offset)
  {
    sf::Vertex y_top(sf::Vector2f(delta, top), sf::Color::Black);
    sf::Vertex y_bottom(sf::Vector2f(delta, top + line_length), sf::Color::Black);
    sf::Vertex x_left(sf::Vector2f(left, delta), sf::Color::Black);
    sf::Vertex x_right(sf::Vector2f(left + line_length, delta), sf::Color::Black);
    lines.append(y_top);
    lines.append(y_bottom);
    lines.append(x_left);
    lines.append(x_right);
  }
}

void Grid::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  states.transform *= getTransform();
  target.draw(lines, states);
}

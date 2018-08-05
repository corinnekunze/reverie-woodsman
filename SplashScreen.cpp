#include "stdafx.h"
#include "SplashScreen.h"

void SplashScreen::show(sf::RenderWindow & renderWindow) {
  sf::Texture texture;
  if (texture.loadFromFile("resources/cute_image.jpg"))
  {
    return;
  }
  sf::Sprite sprite(texture);

  sf::Font font;
  if (font.loadFromFile("resources/sansation.ttf"))
  {
    return;
  }
  sf::Text text("Reverie Woodsman", font, 50);
  text.setFillColor(sf::Color::Black);

  sf::Music music;
  if (music.openFromFile("nice_music.ogg"))
  {
    return;
  }
  music.play();
  renderWindow.draw(sprite);
  renderWindow.draw(text);
  renderWindow.display();

  sf::Event event;
  while(renderWindow.pollEvent(event))
  {
    if(event.type == sf::Event::EventType::KeyPressed ||
       event.type == sf::Event::EventType::MouseButtonPressed ||
       event.type == sf::Event::EventType::Closed)
    {
      return;
    }
  }
}

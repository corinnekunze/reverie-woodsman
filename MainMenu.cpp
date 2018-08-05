#include "stdafx.h"
#include "MainMenu.h"

MainMenu::MenuResult MainMenu::show(sf::RenderWindow& window)
{
  MenuItem playButton;
  playButton.rect.top = 145;
  playButton.rect.left = 0;
  playButton.action = Play;

  MenuItem exitButton;
  exitButton.rect.left = 0;
  exitButton.rect.top = 383;

  exitButton.action = Exit;

  _menuItems.push_back(playButton);
  _menuItems.push_back(exitButton);

  window.display();

  return GetMenuResponse(window);
}

MainMenu::MenuResult MainMenu::HandleClick(int x, int y)
{
  std::list<MenuItem>::iterator it;

  for (it = _menuItems.begin(); it != _menuItems.end(); it++)
  {
    sf::Rect<int> menuItemRect = (*it).rect;
    if (menuItemRect.top < y &&
        menuItemRect.left < x)
    {
      return (*it).action;
    }
  }
  return Nothing;
}

MainMenu::MenuResult MainMenu::GetMenuResponse(sf::RenderWindow& window)
{
  sf::Event menuEvent;
  while (true) {
    while (window.pollEvent(menuEvent))
    {
      if (menuEvent.type == sf::Event::MouseButtonPressed) {
        return HandleClick(menuEvent.mouseButton.x, menuEvent.mouseButton.y);
      }
      if (menuEvent.type == sf::Event::Closed)
      {
        return Exit;
      }
  }
  }
}

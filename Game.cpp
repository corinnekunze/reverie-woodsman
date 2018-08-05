#include "stdafx.h"
#include "Game.h"
#include "SplashScreen.h"
#include "MainMenu.h"

void Game::Start(void)
{
  if (_gameState != Uninitialized) return;

  _mainWindow.create(sf::VideoMode(1024, 768, 32), "Reverie Woodsman");
  _gameState = Game::ShowingSplash;

  while(!IsExiting())
  {
    GameLoop();
  }

  _mainWindow.close();
}

bool Game::IsExiting()
{
  if (_gameState == Game::Exiting)
    return true;
  else
    return false;
}

void Game::GameLoop()
{
  sf::Event currentEvent;
  while(_mainWindow.pollEvent(currentEvent))
  {
    switch(_gameState)
    {
      case Game::ShowingSplash:
      {
        ShowSplashScreen();
        break;
      }
      case Game::ShowingMenu:
      {
        ShowMenu();
        break;
      }
      case Game::Playing:
      {
        _mainWindow.clear(sf::Color(255, 0, 0));
        _mainWindow.display();

        if (currentEvent.type == sf::Event::Closed)
        {
          _gameState = Game::Exiting;
        }
        break;
      }
    }
  }
}

void Game::ShowSplashScreen()
{
  SplashScreen splashScreen;
  splashScreen.show(_mainWindow);
  _gameState = Game::ShowingMenu;
}

void Game::ShowMenu()
{
  MainMenu mainMenu;
  MainMenu::MenuResult result = mainMenu.show(_mainWindow);
  switch(result)
  {
    case MainMenu::Exit:
      _gameState = Game::Exiting;
      break;
    case MainMenu::Play:
      _gameState = Game::Playing;
      break;
  }
}

Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::_mainWindow;

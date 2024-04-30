#include "Engine.h"
using namespace sf;
using namespace std;

Engine::Engine()
{
  m_Window.create(VideoMode::getDesktopMode(), "Particles");
}
void Engine::input()
{
  Particle p;
  while (m_Window.isOpen())
	{
        Event event;
        while (m_Window.pollEvent(event))
		{
            if (event.type == Event::Closed)
            {
                m_Window.close();
            }
            else if (event.type == Event::MouseButtonPressed) 
            {
              if (event.mouseButton.button == sf::Mouse::Left)
				      {
                int count = 0;
                while (count <= 5)
                  {
                    Particle();
                      count++;
                  }
              }
            }
            else if (Keyboard::isKeyPressed(Keyboard::Escape))
            {
                m_Window.close();
            }
}
void Engine::update(float dtAsSeconds)
{
}
void Engine::draw()
{
}

void Engine::run()
{
  Clock clock;
  Time t;
  float s;
  Particle p;
  
  cout << "Starting Particle unit tests..." << endl;
  Particle p(m_Window, 4, { (int)m_Window.getSize().x / 2, (int)m_Window.getSize().y / 2 });
  p.unitTests();
  cout << "Unit tests complete.  Starting engine..." << endl;

  while(m_Window.isOpen())
  {
    t = clock.restart()
    s = t.asSeconds();
    
    input();
    update();
    draw();
  }
      
}

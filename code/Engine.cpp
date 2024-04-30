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
		int numPoints = rand(); //check rand formula
		while (count <= 5)
                {
        	  Particle(target, numPoints, mouseclickPosition); //remeber to get target and mouseClickPosition
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
	vector<Particles>::iterator iter;
	for (iter = m_Particles.begin(); iter != m_Particles.end(); iter ++)
	{
		if (*iter.getTTL() > 0.0)
		{
			*iter.update();
			iter++
		}
		else
		{
			*iter.erase();
			return iter;
		}
	}
		
}
void Engine::draw()
{
	m_Window.clear();
	for (int i = 0; i < m_Particles.size(); i++)
	{
		m_Window.draw(m_Particle.at(i));
	}
	m_Window.display;		
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

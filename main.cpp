#include <SFML/Graphics.hpp>
using namespace sf;

/*struct vector2f
{
    int x;
    int y;
};*/

Vector2f speed = {5.f, 5.f};

int main()
{
    RenderWindow window(VideoMode(800, 600), "SFML works!");
    RectangleShape shape({50.f,20.f});
    shape.setFillColor(Color::Green);
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();

        if(shape.getPosition().x + shape.getSize().x >= 800 || shape.getPosition().x < 0)
        {
            speed.x *= -1;
            shape.setFillColor(Color::Blue);
        }
        

        if(shape.getPosition().y + shape.getSize().y >= 600 || shape.getPosition().y < 0)
        {
            speed.y *= -1;
            shape.setFillColor(Color::Green);
        }

        shape.move(speed);
        window.draw(shape);
        window.display();
    }

    return 0;
}
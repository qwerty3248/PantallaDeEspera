#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cstdlib>
#include <ctime>

int main() {
    // Crear la ventana
    sf::RenderWindow window(sf::VideoMode(900, 900), "Pantalla de Espera");

    // Establecer el fondo verde
    window.clear(sf::Color::Green);

    // Cargar las imágenes
    sf::Texture texture1, texture2;
    if (!texture1.loadFromFile("knekro1.png") || !texture2.loadFromFile("knekro2.png")) {
        return -1; // Error al cargar las imágenes
    }

    // Convertir las texturas en sprites
    sf::Sprite sprite1(texture1);
    sf::Sprite sprite2(texture2);

    // Control de la imagen actual
    bool X = true;

    // Semilla para aleatoriedad
    std::srand(static_cast<unsigned int>(std::time(0)));

    // Temporizador para la animación
    sf::Clock clock;

    // Bucle principal
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Borrar la ventana con el fondo verde
        window.clear(sf::Color::Green);

        // Elegir aleatoriamente la imagen
        sf::Sprite* selected_sprite = nullptr;
        if (X) {
            selected_sprite = &sprite1;
            X = false;
        } else {
            selected_sprite = &sprite2;
            X = true;
        }

        // Asignar una posición aleatoria para la imagen
        float x_pos = static_cast<float>(std::rand() % 551);  // Coordenada X aleatoria
        float y_pos = static_cast<float>(std::rand() % 701);  // Coordenada Y aleatoria

        // Establecer la posición de la imagen seleccionada
        selected_sprite->setPosition(x_pos, y_pos);

        // Dibujar la imagen
        window.draw(*selected_sprite);

        // Mostrar el contenido de la ventana
        window.display();

        // Llamar a esta función nuevamente después de un pequeño retraso (aproximadamente 200 ms)
        while (clock.getElapsedTime().asMilliseconds() < 200) {
            // Espera hasta que pase el tiempo deseado
        }
        clock.restart();
    }

    return 0;
}


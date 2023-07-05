//функции поиска корней уравнения (2 способа)
/*
#include <iostream>
#include <cmath>

using namespace std;
double a, b, c; double x[10];

//метод дихотомии разгон
double FunctoinDichotomyEasy(double t) {
    double t1 = t * t * t - 4 * t * t - 5 * t + 4;
    for (int i = 0; x[i] != -3; ++i) { t1 /= (t - x[i]); }
    return t1;
}

void DichotomyEasy() {
    std::cout << "Dichotomy: x = ";
    a = -2; b = 6;
    for (int i = 0; i < 10; ++i) x[i] = -3;
    int j = -1;
    while (++j < 3) {
        while (b - a > 0.000001) {
            c = (a + b) / 2;
            if (FunctoinDichotomyEasy(a) * FunctoinDichotomyEasy(c) < 0) b = c;
            else a = c;
        }
        x[j] = (a + b) / 2;
        a = -2, b = 2;
    }
    for (int i = 0; i < 3; ++i) std::cout << x[i] << " ";
    std::cout << std::endl;
}

//метод хорд разгон
double FunctoinChordEasy(double t) {
    double t1 = t * t * t - 4 * t * t - 5 * t + 4;
    for (int i = 0; x[i] != -3; ++i) { t1 /= (t - x[i]); }
    return t1;
}

void ChordEasy() {
    std::cout << "Chord: x = ";
    a = -2; b = 6;
    for (int i = 0; i < 10; ++i) x[i] = -3;
    int j = -1;
    while (++j < 3) {
        while (b - a > 0.000001) {
            c = (FunctoinChordEasy(b) * a - FunctoinChordEasy(a) * b) / (FunctoinChordEasy(b) - FunctoinChordEasy(a));
            if (c < a) c = (a + b) / 2;
            if (abs(FunctoinChordEasy(c)) <= 0.000001) break;
            else if (FunctoinChordEasy(a) * FunctoinChordEasy(c) < 0) b = c;
            else a = c;
        }
        x[j] = c;
        a = -2, b = 2;
    }
    for (int i = 0; i < 3; ++i) std::cout << x[i] << " ";
    std::cout << std::endl;
}

//метод дихотомии норм
double FunctoinDichotomyHard(double t) {
    double t1 = log(t + sin(sin(t * t))) - 0.7 * t + 1;
    for (int i = 0; x[i] != -2; ++i) { t1 /= (t - x[i]); }
    return t1;
}

void DichotomyHard() {
    std::cout << "Dichotomy: x = ";
    a = 0.5; b = 4.5;
    for (int i = 0; i < 10; ++i) x[i] = -2;
    int j = -1;
    while (++j < 3) {
        if (x[0] == -1.5) a = 0;
        while (b - a > 0.000001) {
            c = (a + b) / 2;
            if (FunctoinDichotomyHard(a) * FunctoinDichotomyHard(c) < 0) b = c;
            else a = c;
        }
        x[j] = (a + b) / 2;
        a = 0.5, b = 3;
    }
    for (int i = 0; i < 3; ++i) std::cout << x[i] << " ";
    std::cout << std::endl;
}

//метод хорд норм
double FunctoinChordHard(double t) {
    double t1 = log(t + sin(sin(t * t))) - 0.7 * t + 1;
    for (int i = 0; x[i] != -2; ++i) { t1 /= (t - x[i]); }
    return t1;
}

void ChordHard() {
    std::cout << "Chord: x = ";
    a = 0.5; b = 4.5;
    for (int i = 0; i < 10; ++i) x[i] = -2;
    int j = -1;
    while (++j < 3) {
        while (b - a > 0.000001) {
            c = (FunctoinChordHard(b) * a - FunctoinChordHard(a) * b) / (FunctoinChordHard(b) - FunctoinChordHard(a));
            if (c > b) c = (a + b) / 2;
            if (abs(FunctoinChordHard(c)) <= 0.000001) break;
            else if (FunctoinDichotomyHard(a) * FunctoinChordHard(c) < 0) b = c;
            else a = c;
        }
        x[j] = c;
        a = 0.5, b = 4.5;
    }
    for (int i = 0; i < 3; ++i) std::cout << x[i] << " ";
    std::cout << std::endl;
}

int main() {
    std::cout << std::endl << "x^3 - 4x^2 - 5x + 4 = 0, interval [-2, 6]" << std::endl;
    DichotomyEasy();
    ChordEasy();
    std::cout << std::endl << "log(x + sin(sin(x^2))) = 0.7 * x - 1, interval [0.5, 4.5]" << std::endl;
    DichotomyHard();
    ChordHard();
}
*/

//функции поиска корней уравнения картинки
/*
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

int scale = 80;

// sin(x ^ 2) / x = 0.25              красная
// cos(2 * sin(t)) = sin(2 * cos(t))  синяя

void Graphic(int i, int j, sf::Image& img)
{
    //оси
    img.setPixel(i, scale * 4, sf::Color::Black);
    img.setPixel(scale * 4, j, sf::Color::Black);
    if (j % scale == 0 && i > scale * 4 - 3 && i < scale * 4 + 4) img.setPixel(i, j, sf::Color::Black);
    if (i % scale == 0 && j > scale * 4 - 3 && j < scale * 4 + 4) img.setPixel(i, j, sf::Color::Black);

    //график
    double x = i * 1.0 / scale - 4, y = j * 1.0 / scale - 4;
    if (x != 0) {
        if (abs(sin(x * x) / x - 0.25 + y) <= 0.02) {
                img.setPixel(i, j, sf::Color::Red);
        }
        if (abs(cos(2 * sin(x)) - sin(2 * cos(x)) + y) <= 0.02) {
                img.setPixel(i, j, sf::Color::Blue);
        }
    }
}

void Event(sf::RenderWindow& window, sf::Image& img) {
    sf::Texture texture;
    texture.loadFromImage(img);
    sf::Sprite sprite;
    sprite.setTexture(texture, true);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(sprite);
        window.display();
    }
}

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(scale * 15, scale * 8), "SFML works!", sf::Style::Default, settings);
    sf::Image img;
    img.create(scale * 15, scale * 8, sf::Color::White);
    for (int i = 0; i < scale * 15; i++) {
        for (int j = 0; j < scale * 8; j++) {
            Graphic(i, j, img);
        }
    }
    Event(window, img);
    return 0;
}
*/

//фракталы (3 штуки)
//*
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

using namespace std; 

int m[1023][5], n = 1, work = 1, n1 = 1, color = 1;

void StupidCar(sf::RenderWindow& window) {
    sf::RectangleShape rectangle(sf::Vector2f(300, 15));
    rectangle.setFillColor(sf::Color::Green);
    rectangle.setPosition(320, 370);
    window.draw(rectangle);
    rectangle.setRotation(90);
    rectangle.setPosition(320, 90);
    window.draw(rectangle);
    sf::RectangleShape rectangl(sf::Vector2f(50, 15));
    rectangl.setFillColor(sf::Color::Black);
    rectangl.setPosition(300, 80);
    window.draw(rectangl);
    sf::CircleShape shape(20);
    shape.setFillColor(sf::Color::Red);
    shape.setOutlineThickness(3);
    shape.setOutlineColor(sf::Color::Blue);
    shape.setPosition(600, 350);
    window.draw(shape);
    shape.setPosition(300, 350);
    window.draw(shape);
}

void Serpinskynapkin(sf::RenderWindow& window) {
    for (int i = 0; i < n; ++i) {
        sf::VertexArray triangle(sf::Triangles, 3);
        triangle[0].position = sf::Vector2f(m[i][0], m[i][1]);
        triangle[1].position = sf::Vector2f(m[i][2], m[i][3]);
        triangle[2].position = sf::Vector2f(m[i][4], m[i][3]);
        triangle[0].color = sf::Color::Green;
        triangle[1].color = sf::Color::Red;
        triangle[2].color = sf::Color::Blue;
        window.draw(triangle);
    }
}

void KohIslands(sf::RenderWindow& window) {
    sf::VertexArray triangle(sf::LineStrip, 768 / n + 1);
    for (int i = 0; i * n <= 768; ++i) {
        triangle[i].position = sf::Vector2f(m[i * n][0], m[i * n][1]);
        triangle[i].color = sf::Color::Red;
    }
    window.draw(triangle);
}

void Pythagoreantree(sf::RenderWindow& window) {
    for (int i = 0; i < n; ++i) {
        sf::ConvexShape square(4);
        square.setPoint(0, sf::Vector2f(m[i][0], m[i][1]));
        square.setPoint(1, sf::Vector2f(m[i][2], m[i][3]));
        square.setPoint(2, sf::Vector2f(m[i][2] + m[i][1] - m[i][3], m[i][3] + m[i][2] - m[i][0]));
        square.setPoint(3, sf::Vector2f(m[i][0] + m[i][1] - m[i][3], m[i][1] + m[i][2] - m[i][0]));
        if (color == 1) square.setFillColor(sf::Color::Color(m[i][4], 150, 20)); //коричнево зеленый
        else if (color == 2) square.setFillColor(sf::Color::Color(m[i][4], 250, 0)); //желто зеленый
        else if (color == 3) square.setFillColor(sf::Color::Color(200, m[i][4], m[i][4])); //прозрачно красное
        else if (color == 4) square.setFillColor(sf::Color::Color(m[i][4], 250, 250)); //нежно ледяное
        else if (color == 5) square.setFillColor(sf::Color::Color(m[i][4], 250, 250 - m[i][4])); //желто берюзовый
        else square.setFillColor(sf::Color::Color(m[i][4], m[i][4], m[i][4])); //чб
        window.draw(square);
    }
}

void Event(sf::RenderWindow& window, sf::Image& img) {
    sf::Texture texture;
    texture.loadFromImage(img);
    sf::Sprite sprite;
    sprite.setTexture(texture, true);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::MouseButtonPressed &&
                event.mouseButton.button == sf::Mouse::Left && n < 729 && work == 1) {
                n1 = n;
                for (int i = 0; i < n1; ++i) {
                    m[n][0] = (m[i][0] + m[i][2]) / 2 + (m[i][0] + m[i][2]) % 2;
                    m[n][1] = (m[i][1] + m[i][3]) / 2 + (m[i][1] + m[i][3]) % 2;
                    m[n][2] = m[i][2];
                    m[n][3] = m[i][3];
                    m[n][4] = m[i][0];
                    m[n + 1][0] = (3 * m[i][0] - m[i][2]) / 2 + (3 * m[i][0] - m[i][2]) % 2;
                    m[n + 1][1] = (m[i][1] + m[i][3]) / 2 + (m[i][1] + m[i][3]) % 2;
                    m[n + 1][2] = m[i][0];
                    m[n + 1][3] = m[i][3];
                    m[n + 1][4] = m[i][4];
                    m[i][4] = (3 * m[i][0] - m[i][2]) / 2 + (3 * m[i][0] - m[i][2]) % 2;
                    m[i][2] = (m[i][0] + m[i][2]) / 2 + (m[i][0] + m[i][2]) % 2;
                    m[i][3] = (m[i][1] + m[i][3]) / 2 + (m[i][1] + m[i][3]) % 2;
                    n += 2;
                }
            }
            else if (event.type == sf::Event::MouseButtonPressed &&
                event.mouseButton.button == sf::Mouse::Left && n > 1 && work == 2) {
                n1 = n;
                n /= 4;
                for (int i = 0; i < 768; i += n1) {
                    m[i + n][0] = (m[i][0] * 2 + m[i + n1][0]) / 3;
                    m[i + n][1] = (m[i + n1][1] + m[i][1] * 2) / 3;
                    m[i + n * 3][0] = (m[i][0] + m[i + n1][0] * 2) / 3;
                    m[i + n * 3][1] = (m[i + n1][1] * 2 + m[i][1]) / 3;
                    m[i + n * 2][0] = (m[i + n][0] + m[i + n * 3][0]) / 2 - (int)(0.866025 * (m[i + n * 3][1] - m[i + n][1]));
                    m[i + n * 2][1] = (m[i + n][1] + m[i + n * 3][1]) / 2 - (int)(0.866025 * (m[i + n][0] - m[i + n * 3][0]));
                }
            }
            else if (event.type == sf::Event::MouseButtonPressed &&
                event.mouseButton.button == sf::Mouse::Left && n < 1023 && work == 3) {
                int k = n;
                for (int i = n - n1; i < k; ++i) {
                    m[n][0] = m[i][0] + (m[i][3] + m[i][0] - m[i][2] - m[i][1]) / 2;
                    m[n][1] = m[i][1] - (m[i][2] + m[i][3] - m[i][1] - m[i][0]) / 2;
                    m[n][2] = m[i][0] + m[i][3] - m[i][1];
                    m[n][3] = m[i][1] + m[i][0] - m[i][2];
                    m[n][4] = m[i][4] - 25;
                    ++n;
                    m[n][0] = m[i][2] + m[i][3] - m[i][1];
                    m[n][1] = m[i][3] + m[i][0] - m[i][2];
                    m[n][2] = m[i][2] - (m[i][1] + m[i][0] - m[i][2] - m[i][3]) / 2;
                    m[n][3] = m[i][3] + (m[i][0] + m[i][3] - m[i][1] - m[i][2]) / 2;
                    m[n][4] = m[i][4] - 25;
                    ++n;
                }
                n1 *= 2;
            }
            else if (event.type == sf::Event::TextEntered && event.text.unicode < 128) {
                color = event.text.unicode - 48;
            }
        }
        window.clear();
        window.draw(sprite);
        if (work == 1) Serpinskynapkin(window);
        else if (work == 2) KohIslands(window);
        else if (work == 3) Pythagoreantree(window);
        else if (work == 4) StupidCar(window);
        window.display();
    }
}

int main()
{
    cout << "hi! What kind of work will we watch?" << endl;
    while (1) {
        cout << "1. Serpinsky's napkin" << endl << "2. Koh's Islands" << endl << "3. Pythagorean's tree" << endl << "4. Stupid Car" << endl << "I chose: ";
        cin >> work;
        cout << "A message from the future: ";
        for (int i = 0; i < 1023; ++i) {
            for (int j = 0; j < 5; ++j) {
                m[i][j] = 0;
            }
        }
        if (work == 1) {
            cout << "I hope your eyes don't break :)" << endl << endl;
            n = 1;
            m[0][0] = 420; m[0][1] = 30;
            m[0][2] = 136; m[0][3] = 502; m[0][4] = 704;
        }
        else if (work == 2) {
            cout << "Extremely beautiful snowflake!" << endl << endl;
            n = 256;
            m[0][0] = 420; m[0][1] = 10;
            m[n][0] = 187; m[n][1] = 415;
            m[n * 2][0] = 653; m[n * 2][1] = 415;
            m[n * 3][0] = 420; m[n * 3][1] = 10;
        }
        else if (work == 3) {
            cout << "Do you want to see magic? Click on the numbers on the keyboard" << endl << endl;
            n = 1; n1 = 1; color = 1;
            m[0][0] = 360; m[0][1] = 420;
            m[0][2] = 480; m[0][3] = 420; m[0][4] = 250;
        }
        else if (work == 4) {
            cout << "Very Stupid Car";
        }
        sf::RenderWindow window(sf::VideoMode(840, 560), "SFML works!");
        sf::Image img;
        img.create(840, 560, sf::Color::White);
        Event(window, img);
    }
    return 0;
}
//*/
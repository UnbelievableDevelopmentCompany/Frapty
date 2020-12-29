#pragma once
#include "QSfmlWidget.h"

class Viewport : public QSfmlWidget
{
public:
    Viewport(QWidget* parent = nullptr, const QPoint& position = QPoint(), const QSize& size = QSize()) : QSfmlWidget(parent, position, size)
    {

    }
private:
    void OnInit() override
    {
        cs.setFillColor(sf::Color::Green);
        cs.setRadius(100);
        cs.setPosition(20, 30);
        cs.setScale(1, 2);
    }

    void OnUpdate() override
    {
        clear(sf::Color(0, 0, 0));
        draw(cs);
    }

    sf::CircleShape cs;
};


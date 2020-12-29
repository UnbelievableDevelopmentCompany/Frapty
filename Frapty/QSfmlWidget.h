#pragma once

#include <SFML/Graphics.hpp>
#include <QtWidgets>

#ifdef Q_WS_X11
#include <Qt/qx11info_x11.h>
#include <X11/Xlib.h>
#endif

class QSfmlWidget : public QWidget, public sf::RenderWindow
{
private:
    QTimer myTimer;
    bool myInitialized;
public:
    QSfmlWidget(QWidget* parent, const QPoint& position, const QSize& size, unsigned int frameTime = 0);
    virtual ~QSfmlWidget();

private:
    virtual void OnInit();
    virtual void OnUpdate();
    virtual QPaintEngine* paintEngine() const;
    virtual void showEvent(QShowEvent*);
    virtual void paintEvent(QPaintEvent*);
};
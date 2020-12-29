#include "QSfmlWidget.h"


QSfmlWidget::QSfmlWidget(QWidget* parent, const QPoint& position, const QSize& size, unsigned int frameTime) :
    QWidget(parent), myInitialized(false)
{
    setAttribute(Qt::WA_PaintOnScreen);
    setAttribute(Qt::WA_OpaquePaintEvent);
    setAttribute(Qt::WA_NoSystemBackground);

    setFocusPolicy(Qt::StrongFocus);

    move(position);
    resize(size);

    this->setVerticalSyncEnabled(true);
    this->setFramerateLimit(60);

    myTimer.setInterval(frameTime);
}

QSfmlWidget::~QSfmlWidget()
{
}

void QSfmlWidget::OnInit()
{
}

void QSfmlWidget::OnUpdate()
{
}


void QSfmlWidget::showEvent(QShowEvent*)
{
    if (!myInitialized)
    {
#ifdef Q_WS_X11
        XFlush(QX11Info::display());
#endif
        sf::Window::create((sf::WindowHandle)winId());
        OnInit();

        connect(&myTimer, SIGNAL(timeout()), this, SLOT(repaint()));
        myTimer.start();

        myInitialized = true;
    }
}

void QSfmlWidget::paintEvent(QPaintEvent*)
{
    OnUpdate();
    sf::Window::display();
}

QPaintEngine* QSfmlWidget::paintEngine() const
{
    return nullptr;
}
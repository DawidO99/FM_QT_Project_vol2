#include "CustomCalendarWidget.h"
CustomCalendarWidget::CustomCalendarWidget(QWidget *parent): QCalendarWidget(parent)
{}

CustomCalendarWidget::~CustomCalendarWidget()
{}


void CustomCalendarWidget::paintCell(QPainter* painter, const QRect& rect, const QDate& date) const {
    QCalendarWidget::paintCell(painter, rect, date);

    // Rysowanie tekstu "X" w �rodku kom�rki
    painter->save();
    painter->setPen(Qt::blue);
    painter->drawText(rect, Qt::AlignCenter, "X");
    painter->restore();

    if (date.day() == 20) {
        QImage image(":/images/matchday.jpg"); // U�ycie �cie�ki zasob�w (resource path)
        if (!image.isNull()) { // Sprawdzenie, czy obraz zosta� za�adowany prawid�owo
            painter->drawImage(rect, image);
        }
        else {
            qDebug() << "Nie mo�na za�adowa� obrazu: images/matchday.jpg";
        }
    }
}

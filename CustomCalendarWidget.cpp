#include "CustomCalendarWidget.h"
CustomCalendarWidget::CustomCalendarWidget(QWidget *parent): QCalendarWidget(parent)
{}

CustomCalendarWidget::~CustomCalendarWidget()
{}


void CustomCalendarWidget::paintCell(QPainter* painter, const QRect& rect, const QDate& date) const {
    QCalendarWidget::paintCell(painter, rect, date);

    // Rysowanie tekstu "X" w œrodku komórki
    painter->save();
    painter->setPen(Qt::blue);
    painter->drawText(rect, Qt::AlignCenter, "X");
    painter->restore();

    if (date.day() == 20) {
        QImage image(":/images/matchday.jpg"); // U¿ycie œcie¿ki zasobów (resource path)
        if (!image.isNull()) { // Sprawdzenie, czy obraz zosta³ za³adowany prawid³owo
            painter->drawImage(rect, image);
        }
        else {
            qDebug() << "Nie mo¿na za³adowaæ obrazu: images/matchday.jpg";
        }
    }
}

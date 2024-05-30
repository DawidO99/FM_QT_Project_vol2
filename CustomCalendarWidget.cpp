#include "CustomCalendarWidget.h"
CustomCalendarWidget::CustomCalendarWidget(QWidget *parent): QCalendarWidget(parent)
{}

CustomCalendarWidget::~CustomCalendarWidget()
{}


void CustomCalendarWidget::paintCell(QPainter* painter, const QRect& rect, const QDate& date) const {
    QCalendarWidget::paintCell(painter, rect, date);

        // Tutaj mo�esz doda� kod rysuj�cy tekst lub ikon�
        painter->save();
        painter->setPen(Qt::blue);
        painter->drawText(rect, Qt::AlignCenter, "X"); // Przyk�ad: rysowanie tekstu "X" w �rodku kom�rki
        painter->restore();

        if (date.day()==20) 
        {
            painter->drawImage(rect.x(), rect.y(), QImage("images/matchday.jpg"));
        }
}
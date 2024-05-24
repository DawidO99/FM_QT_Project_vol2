#include "CustomCalendarWidget.h"
CustomCalendarWidget::CustomCalendarWidget(QWidget *parent)
	: QCalendarWidget(parent)
{}

CustomCalendarWidget::~CustomCalendarWidget()
{}


void CustomCalendarWidget::paintCell(QPainter* painter, const QRect& rect, const QDate& date) const {
    QCalendarWidget::paintCell(painter, rect, date);

        // Tutaj mo¿esz dodaæ kod rysuj¹cy tekst lub ikonê
        painter->save();
        painter->setPen(Qt::blue);
        painter->drawText(rect, Qt::AlignCenter, "X"); // Przyk³ad: rysowanie tekstu "X" w œrodku komórki
        painter->restore();
}
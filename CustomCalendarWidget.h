#pragma once

#include <QPainter>
#include <QCalendarWidget>

class CustomCalendarWidget  : public QCalendarWidget
{
	Q_OBJECT

public:
	CustomCalendarWidget(QWidget* parent = Q_NULLPTR);
	~CustomCalendarWidget();
protected:
	void paintCell(QPainter* painter, const QRect& rect, const QDate& date) const;
};

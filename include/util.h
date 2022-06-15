#ifndef UTIL_H
#define UTIL_H

#endif // UTIL_H
#include <QPointF>

inline float distance(QPointF a, QPointF b)
{
	return hypot(a.x() - b.x(), a.y() - b.y());
}

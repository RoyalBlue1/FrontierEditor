#ifndef SPAWNARCTITANDATAMODEL_H
#define SPAWNARCTITANDATAMODEL_H

#include "spawntitandatamodel.h"


class SpawnArcTitanDataModel : public SpawnTitanDataModel
{
	Q_OBJECT
public:
	SpawnArcTitanDataModel();

	QString caption() const override
	{ return QStringLiteral("Spawn Arc Titan"); }


	QString name() const override
	{ return QStringLiteral("ArcTitan"); }

};

#endif // SPAWNARCTITANDATAMODEL_H

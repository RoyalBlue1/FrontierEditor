#ifndef SPAWNNUKETITANDATAMODEL_H
#define SPAWNNUKETITANDATAMODEL_H

#include "spawntitandatamodel.h"


class SpawnNukeTitanDataModel : public SpawnTitanDataModel
{
	Q_OBJECT
public:
	SpawnNukeTitanDataModel();

	QString caption() const override
	{ return QStringLiteral("Spawn Nuke Titan"); }



	QString name() const override
	{ return QStringLiteral("NukeTitan"); }

};

#endif // SPAWNNUKETITANDATAMODEL_H

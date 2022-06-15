#ifndef GAMEMAP_H
#define GAMEMAP_H
#include <QMap>
#include <QPoint>
#include <array>

#endif // GAMEMAP_H

enum class GameMap
{
	AngelCity,
	BlackWaterCanal,
	Coliseum,
	ColiseumColumn,
	Colony,
	Complex,
	Crashsite,
	Drydock,
	Eden,
	ForwardbaseKodai,
	Glitch,
	Grave,
	Homestead,
	Relic,
	Rise,
	Thaw,
	Wargames
};

static const QMap<GameMap, QString> mapFileNames {
	{GameMap::AngelCity, "mp_angel_city"},
	{GameMap::BlackWaterCanal, "mp_black_water_canal"},
	{GameMap::Coliseum, "mp_coliseum"},
	{GameMap::ColiseumColumn, "mp_coliseum_column"},
	{GameMap::Colony, "mp_colony02"},
	{GameMap::Complex, "mp_complex3"},
	{GameMap::Crashsite, "mp_crashsite3"},
	{GameMap::Drydock, "mp_drydock"},
	{GameMap::Eden, "mp_eden"},
	{GameMap::ForwardbaseKodai, "mp_forwardbase_kodai"},
	{GameMap::Glitch, "mp_glitch"},
	{GameMap::Grave, "mp_grave"},
	{GameMap::Homestead, "mp_homestead"},
	{GameMap::Relic, "mp_relic02"},
	{GameMap::Rise, "mp_rise"},
	{GameMap::Thaw, "mp_thaw"},
	{GameMap::Wargames, "mp_wargames"}};

const std::map<GameMap, std::array<float, 3>> transformMap {
	{GameMap::AngelCity, {-6516, 6633, 11.353f}},
	{GameMap::BlackWaterCanal, {-5416, 6437, 12}},
	{GameMap::Coliseum, {-1510, 1561, 3}},
	{GameMap::ColiseumColumn, {-1510, 1561, 3}},
	{GameMap::Colony, {-9504, 8961, 13}},
	{GameMap::Complex, {-10855, 3451, 12}},
	{GameMap::Crashsite, {-10668, 4576, 12}},
	{GameMap::Drydock, {-5659, 5749, 10.5f}},
	{GameMap::Eden, {-4705, 6163, 11}},
	{GameMap::ForwardbaseKodai, {-5272, 5671, 10}},
	{GameMap::Glitch, {-8386, 8386, 16}},
	{GameMap::Grave, {-2690, 3866, 14}},
	{GameMap::Homestead, {-4839, 5871, 13}},
	{GameMap::Relic, {-7428, 2375, 15}},
	{GameMap::Rise, {-7558, 7399, 12}},
	{GameMap::Thaw, {-5046, 5515, 11.188f}},
	{GameMap::Wargames, {-5923, 5105, 9.5f}}};

#ifndef INC_3DSHOOTER_MAP_H
#define INC_3DSHOOTER_MAP_H

#include <cstdlib>

class Map {
private:

public:
    size_t width, height;
    Map();
    // Возвращает номер объекта на позиции i,j
    int get(const size_t i, const size_t j);
    // Проверяет есть в i-ой, j-ой точке карты что-нибудь
    bool isEmpty(const size_t i, const size_t j);
};


#endif // MAP_H

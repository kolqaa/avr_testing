#ifndef BH1750_H
# define BH1750_H

#include "../main.h"

void            init_bh1750_lightSensor(void);
uint16_t        getlux_from_bh1750_lightSensor(void);

#endif

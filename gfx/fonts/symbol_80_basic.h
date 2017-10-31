#ifndef SYMBOL_80_BASIC_H
#define SYMBOL_80_BASIC_H

/*Use UTF-8 encoding in the IDE*/

#include "misc_conf.h"

#if  USE_FONT_SYMBOL_80_BASIC != 0

#include <stdint.h>
#include "misc/gfx/font.h"

font_t * symbol_80_basic_get_dsc(void);

#endif   /*USE_FONT_SYMBOL_80_BASIC != 0*/

#endif   /*SYMBOL_80_BASIC_H*/
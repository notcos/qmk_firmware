/* Copyright 2020 Spaceman
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "rev2.h"


#ifdef OLED_ENABLE
oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

bool oled_task_kb(void) {
    if (!oled_task_user()) {
        return false;
    }
    static const char PROGMEM pancake_logo[] = {
        0x00, 0x00, 0x3e, 0x0a, 0x04, 0x00, 0x3c, 0x0a, 0x3c, 0x00, 0x3e, 0x0c, 0x18, 0x3e, 0x00, 0x3e,
        0x22, 0x22, 0x00, 0x3c, 0x0a, 0x3c, 0x00, 0x3e, 0x08, 0x36, 0x00, 0x3e, 0x2a, 0x22, 0x00, 0x00,
        0x00, 0x30, 0xc8, 0x84, 0x84, 0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x19, 0x1d,
        0x1d, 0x0d, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x84, 0x84, 0xc8, 0x30, 0x00,
        0x00, 0x63, 0x94, 0x08, 0x08, 0x11, 0x71, 0x17, 0x13, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x62,
        0xe2, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x11, 0x11, 0x11, 0x31, 0x08, 0x08, 0x94, 0x63, 0x00,
        0x00, 0x00, 0x03, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
        0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x06, 0x02, 0x02, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00 };
    oled_write_raw_P(pancake_logo, sizeof(pancake_logo));
    // Host Keyboard Layer Status
    oled_set_cursor(0, 4);
    oled_write_P(PSTR("\nLAYER\n-----\n"), false);

    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("Deflt\n"), false);
            break;
        case 1:
            oled_write_P(PSTR("Vim\n"), false);
            break;
        case 2:
            oled_write_P(PSTR("Num\n"), false);
            break;
        case 3:
            oled_write_P(PSTR("i3wm\n"), false);
            break;
	case 4:
            oled_write_P(PSTR("Npad\n"), false);
            break;
	case 5:
            oled_write_P(PSTR("Mouse\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
            break;
    }
    return false;
}
#endif

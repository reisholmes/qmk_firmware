#include "reisholmes.h"

bool oled_task_user(void) {
    oled_write_P(PSTR("WPM: "), false);
    oled_write(get_u8_str(get_current_wpm(), '0'), false);
	// Host Keyboard Layer Status
	oled_write_P(PSTR("    rainkeeb \n"), false);
		oled_write_P(PSTR("Layer: "), false);

		switch (get_highest_layer(layer_state)) {
			case BSE:
				oled_write_P(PSTR("Default\n"), false);
				break;
			case LWR:
				oled_write_P(PSTR("Lower\n"), false);
				break;
			case RSE:
				oled_write_P(PSTR("Raise\n"), false);
				break;
			case ADJ:
				oled_write_P(PSTR("Adjust\n"), false);
				break;
			case SYM:
				oled_write_P(PSTR("Symbols\n"), false);
				break;
			default:
				// Or use the write_ln shortcut over adding '\n' to the end of your string
				oled_write_ln_P(PSTR("Undefined"), false);
		}
	oled_write_P(PSTR(" "), false);

	return false;
}
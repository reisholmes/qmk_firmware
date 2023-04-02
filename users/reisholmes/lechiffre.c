#include "quantum.h"
#include "layout.h"

// controls for top led
// led order is:
// 9
// 10

// This runs after another backlight effect and replaces colors already set
// I run blue as base 

void rgb_matrix_indicators_user(void) {
    switch (get_highest_layer(layer_state)) {
        case BSE:
		    // define different colours for rest of LEDs
            // rgb_matrix_set_color_all(234, 128, 255);
			rgb_matrix_set_color(9, 0, 0, 8);
			rgb_matrix_set_color(10, 0, 0, 8); // blue
            break;
		case LWR:
			rgb_matrix_set_color(9, 0, 0, 0);
			rgb_matrix_set_color(10, 20, 0, 20); // purple
            break;
        case RSE:
			rgb_matrix_set_color(9, 20, 10, 0); // yellow
			rgb_matrix_set_color(10, 0, 0, 0);
            break;
		case ADJ:
			rgb_matrix_set_color(9, 20, 0, 0); // red
			rgb_matrix_set_color(10, 20, 0, 0); // red
            break;
		case SYM:
			rgb_matrix_set_color(9, 0, 20, 0); // green
			rgb_matrix_set_color(10, 0, 20, 0); // green
            break;
		default:
			// catch any other case
            break;
    }
}
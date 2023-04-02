#include "quantum.h"
#include "layout.h"

// pin order is:
// 6
// 5
// 4

void keyboard_post_init_user(void) {
    setPinOutput(B4);                                                                           
    setPinOutput(B5);  
	setPinOutput(B6);	
};

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        default:
			writePinHigh(B6);
            writePinLow(B4);
            writePinLow(B5);
            break;        
		case LWR:
            writePinHigh(B4);
            writePinLow(B5);
			writePinLow(B6);
            break;
        case RSE:
            writePinHigh(B5);
            writePinLow(B4);
			writePinLow(B6);
            break;
		case ADJ:
			writePinHigh(B6);
			writePinHigh(B5);
			writePinLow(B4);
			break;
		case SYM:
			writePinHigh(B6);
			writePinHigh(B4);
			writePinLow(B5);
			break;
		case GME:
			writePinHigh(B6);
			writePinHigh(B5);
			writePinHigh(B4);
			break;			
    }
	return state;
};

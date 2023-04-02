#include "quantum.h"
#include "layout.h"
#include QMK_KEYBOARD_H
#include "analog.h"

// pin order is:
// 4
// 7
// 6

void keyboard_post_init_user(void) {
    setPinOutput(B4);                                                                           
    setPinOutput(D7);  
	setPinOutput(D6);	
};

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        default:
			writePinHigh(B4);
            writePinLow(D7);
            writePinLow(D6);
            break;        
		case LWR:
            writePinHigh(D6);
            writePinLow(B4);
			writePinLow(D7);
            break;
        case RSE:
            writePinHigh(D7);
            writePinLow(B4);
			writePinLow(D6);
            break;
		case ADJ:
			writePinHigh(B4);
			writePinHigh(D7);
			writePinLow(D6);
			break;
		case SYM:
			writePinHigh(B4);
			writePinHigh(D6);
			writePinLow(D7);
			break;
		case GME:
			writePinHigh(B4);
			writePinHigh(D6);
			writePinHigh(D7);
			break;			
    }
	return state;
};


//slider
int16_t max_pot_val = 1023;
int16_t max_ticks = 20;
int16_t pot_oldVal = 0;
int16_t pot_val    = 0;
bool moving     = false;
#define POT_TOLERANCE 50
#define POT_PIN F0
#include "print.h"


void matrix_init_user(void) {
    analogReference(ADC_REF_POWER);
}

void matrix_scan_user(void){
    pot_val   = (analogReadPin(POT_PIN));

    // If there is a big enough change, then we need to do something
    if (abs(pot_val - pot_oldVal) > POT_TOLERANCE) {
        moving = true;
        pot_oldVal = pot_val;
    }
    else{
        if (moving){
            // Do some fancy conversion to get 'absolute' position to num tap_codes to send
            // Reset moving to 0 so that we don't get multiple attempts to do this
            int num_ticks = ((float)pot_val/max_pot_val)*max_ticks;
            for (int i = 0; i<max_ticks;++i){
                tap_code(KC_VOLD);
            }
            for (int i = 0; i<num_ticks;++i){
                tap_code(KC_VOLU);
            }
            moving = false;
        }
    }
}
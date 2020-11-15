// This file does all the heavy lifting for defining OLED, RGB, and keycodes

#include "bongo.c"
#include "keylog.c"

extern keymap_config_t keymap_config;
extern uint8_t is_master;

// Rotate the right OLED
#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_master) {
    return OLED_ROTATION_270;
  } else {
    return OLED_ROTATION_180;
  }
}

// Define what we want to write out to master OLED
// Shows if we are on Mac layout or standard Linux layout
void render_bootmagic_status(void) {
  if (keymap_config.swap_lalt_lgui) {
    oled_write_P(PSTR("<Mac>"), false);
  } else {
    oled_write_P(PSTR("<Lin>"), false);
  }
}

// Render out our current Base layout
void render_default_layer_state(void) {
  oled_write_P(PSTR("Base:"), false);
  switch (biton32(default_layer_state)) {
    case _QW:
      oled_write_P(PSTR(" QRTY"), false);
      break;
  }
}

// Layers rule, display our current layer
void render_layer_state(void) {
  oled_write_P(PSTR("Layr:"), false);
  switch (biton32(layer_state)) {
    case 0:
      oled_write_P(PSTR(" DEF "), false);
      break;
    case _RA:
      oled_write_P(PSTR(" RAI "), false);
      break;
    case _LO:
      oled_write_P(PSTR(" LOW "), false);
      break;
    case _AD:
      oled_write_P(PSTR(" ADJ "), false);
      break;
    default:
      oled_write_P(PSTR(" UNK "), false);
      break;
  }
}

// Lock status
void render_keylock_status(uint8_t led_usb_state) {
  oled_write_P(PSTR("Lock:"), false);
  oled_write_P(PSTR(" "), false);
  oled_write_P(PSTR("NUM "), led_usb_state & (1 << USB_LED_NUM_LOCK));
  oled_write_P(PSTR(" "), false);
  oled_write_P(PSTR("CAPS"), led_usb_state & (1 << USB_LED_CAPS_LOCK));
  oled_write_P(PSTR(" "), false);
  oled_write_P(PSTR("SCRL"), led_usb_state & (1 << USB_LED_SCROLL_LOCK));
}

// Modifiers
void render_mod_status(uint8_t modifiers) {
  oled_write_P(PSTR("Mods:"), false);
  oled_write_P(PSTR(" "), false);
  oled_write_P(PSTR("SHFT"), (modifiers & MOD_MASK_SHIFT));
  oled_write_P(PSTR(" "), false);
  oled_write_P(PSTR("CTRL"), (modifiers & MOD_MASK_CTRL));
  oled_write_P(PSTR(" "), false);
  oled_write_P(PSTR("GUI "), (modifiers & MOD_MASK_GUI));
  oled_write_P(PSTR(" "), false);
  oled_write_P(PSTR("ALT "), (modifiers & MOD_MASK_ALT));
}

// Using our keylogger to display the string
void render_keylogger_status(void) {
  oled_write_P(PSTR("Log: "), false);
  oled_write(keylog_str, false);
}

// Order our Master OLED
void render_status_main(void) {
  render_bootmagic_status();
  render_default_layer_state();
  render_layer_state();
  render_keylock_status(host_keyboard_leds());
  render_mod_status(get_mods()|get_oneshot_mods());
  render_keylogger_status();
}

// Order our Secondary OLED
void render_status_secondary(void) {
//  render_crkbd_logo();
//  oled_scroll_left(); // Turns on scrolling
  render_anim();
}

// Tells the OLEDs what to render
void oled_task_user(void) {
  update_log();
  if (is_master) {
    render_status_main();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
  } else {
    render_status_secondary();
  }
}
#endif

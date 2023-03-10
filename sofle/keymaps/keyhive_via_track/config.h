 /* Copyright 2020 Josef Adamcik
  * Modification for VIA support and RGB underglow by Jens Bonk-Wiltfang
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

#pragma once
#undef EE_HANDS
#undef MASTER_LEFT
#undef MASTER_RIGHT
#undef SPLIT_POINTING_ENABLE
#undef POINTING_DEVICE_RIGHT

#define EE_HANDS
#define MASTER_LEFT
//#define MASTER_RIGHT
#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_RIGHT

#define PIMORONI_TRACKBALL_ROTATE // might or might not be needed, depends how you have mounted the trackball

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/

// More lighting options in quantum/rgblight/rgblight.h
#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_STATIC_LIGHT
#    define RGBLIGHT_DEFAULT_HUE 127
#    define RGBLIGHT_SLEEP

// Disabling some of these is a good way to save flash space.
//#    define RGBLIGHT_EFFECT_ALTERNATING     // 108
//#    define RGBLIGHT_EFFECT_RGB_TEST        // 158
//#    define RGBLIGHT_EFFECT_RAINBOW_MOOD    // 160
//#    define RGBLIGHT_EFFECT_STATIC_GRADIENT // 168
//#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL   // 192
//#    define RGBLIGHT_EFFECT_BREATHING       // 348
//#    define RGBLIGHT_EFFECT_KNIGHT          // 336
//#    define RGBLIGHT_EFFECT_SNAKE           // 406
//#    define RGBLIGHT_EFFECT_CHRISTMAS       // 508
/*
#define RGBLIGHT_EFFECT_TWINKLE         // 1156
*/
#endif

// Disabled to save space
#define NO_ACTION_ONESHOT  // 332
#define NO_ACTION_MACRO    // 0
#define NO_ACTION_FUNCTION // 0
#define DISABLE_LEADER     // 0

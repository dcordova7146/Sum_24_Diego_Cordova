#pragma once

#ifdef DINO_GLFW
	#define DINO_KEY_SPACE              32
	#define DINO_KEY_APOSTROPHE         39  /* ' */
	#define DINO_KEY_COMMA              44  /* , */
	#define DINO_KEY_MINUS              45  /* - */
	#define DINO_KEY_PERIOD             46  /* . */
	#define DINO_KEY_SLASH              47  /* / */
	#define DINO_KEY_0                  48
	#define DINO_KEY_1                  49
	#define DINO_KEY_2                  50
	#define DINO_KEY_3                  51
	#define DINO_KEY_4                  52
	#define DINO_KEY_5                  53
	#define DINO_KEY_6                  54
	#define DINO_KEY_7                  55
	#define DINO_KEY_8                  56
	#define DINO_KEY_9                  57
	#define DINO_KEY_SEMICOLON          59  /* ; */
	#define DINO_KEY_EQUAL              61  /* = */
	#define DINO_KEY_A                  65
	#define DINO_KEY_B                  66
	#define DINO_KEY_C                  67
	#define DINO_KEY_D                  68
	#define DINO_KEY_E                  69
	#define DINO_KEY_F                  70
	#define DINO_KEY_G                  71
	#define DINO_KEY_H                  72
	#define DINO_KEY_I                  73
	#define DINO_KEY_J                  74
	#define DINO_KEY_K                  75
	#define DINO_KEY_L                  76
	#define DINO_KEY_M                  77
	#define DINO_KEY_N                  78
	#define DINO_KEY_O                  79
	#define DINO_KEY_P                  80
	#define DINO_KEY_Q                  81
	#define DINO_KEY_R                  82
	#define DINO_KEY_S                  83
	#define DINO_KEY_T                  84
	#define DINO_KEY_U                  85
	#define DINO_KEY_V                  86
	#define DINO_KEY_W                  87
	#define DINO_KEY_X                  88
	#define DINO_KEY_Y                  89
	#define DINO_KEY_Z                  90
	#define DINO_KEY_LEFT_BRACKET       91  /* [ */
	#define DINO_KEY_BACKSLASH          92  /* \ */
	#define DINO_KEY_RIGHT_BRACKET      93  /* ] */
	#define DINO_KEY_GRAVE_ACCENT       96  /* ` */
	#define DINO_KEY_WORLD_1            161 /* non-US #1 */
	#define DINO_KEY_WORLD_2            162 /* non-US #2 */

	/* Function keys */
	#define DINO_KEY_ESCAPE             256
	#define DINO_KEY_ENTER              257
	#define DINO_KEY_TAB                258
	#define DINO_KEY_BACKSPACE          259
	#define DINO_KEY_INSERT             260
	#define DINO_KEY_DELETE             261
	#define DINO_KEY_RIGHT              262
	#define DINO_KEY_LEFT               263
	#define DINO_KEY_DOWN               264
	#define DINO_KEY_UP                 265
	#define DINO_KEY_PAGE_UP            266
	#define DINO_KEY_PAGE_DOWN          267
	#define DINO_KEY_HOME               268
	#define DINO_KEY_END                269
	#define DINO_KEY_CAPS_LOCK          280
	#define DINO_KEY_SCROLL_LOCK        281
	#define DINO_KEY_NUM_LOCK           282
	#define DINO_KEY_PRINT_SCREEN       283
	#define DINO_KEY_PAUSE              284
	#define DINO_KEY_F1                 290
	#define DINO_KEY_F2                 291
	#define DINO_KEY_F3                 292
	#define DINO_KEY_F4                 293
	#define DINO_KEY_F5                 294
	#define DINO_KEY_F6                 295
	#define DINO_KEY_F7                 296
	#define DINO_KEY_F8                 297
	#define DINO_KEY_F9                 298
	#define DINO_KEY_F10                299
	#define DINO_KEY_F11                300
	#define DINO_KEY_F12                301
	#define DINO_KEY_F13                302
	#define DINO_KEY_F14                303
	#define DINO_KEY_F15                304
	#define DINO_KEY_F16                305
	#define DINO_KEY_F17                306
	#define DINO_KEY_F18                307
	#define DINO_KEY_F19                308
	#define DINO_KEY_F20                309
	#define DINO_KEY_F21                310
	#define DINO_KEY_F22                311
	#define DINO_KEY_F23                312
	#define DINO_KEY_F24                313
	#define DINO_KEY_F25                314
	#define DINO_KEY_KP_0               320
	#define DINO_KEY_KP_1               321
	#define DINO_KEY_KP_2               322
	#define DINO_KEY_KP_3               323
	#define DINO_KEY_KP_4               324
	#define DINO_KEY_KP_5               325
	#define DINO_KEY_KP_6               326
	#define DINO_KEY_KP_7               327
	#define DINO_KEY_KP_8               328
	#define DINO_KEY_KP_9               329
	#define DINO_KEY_KP_DECIMAL         330
	#define DINO_KEY_KP_DIVIDE          331
	#define DINO_KEY_KP_MULTIPLY        332
	#define DINO_KEY_KP_SUBTRACT        333
	#define DINO_KEY_KP_ADD             334
	#define DINO_KEY_KP_ENTER           335
	#define DINO_KEY_KP_EQUAL           336
	#define DINO_KEY_LEFT_SHIFT         340
	#define DINO_KEY_LEFT_CONTROL       341
	#define DINO_KEY_LEFT_ALT           342
	#define DINO_KEY_LEFT_SUPER         343
	#define DINO_KEY_RIGHT_SHIFT        344
	#define DINO_KEY_RIGHT_CONTROL      345
	#define DINO_KEY_RIGHT_ALT          346
	#define DINO_KEY_RIGHT_SUPER        347
	#define DINO_KEY_MENU               348

	#define DINO_KEY_LAST               DINO_KEY_MENU

#else
#no_sutable_definition_like_DINO_GLFW

#endif
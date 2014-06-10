/* The height of the bar (in pixels) */
#define BAR_HEIGHT  22
/* The width of the bar. Set to -1 to fit screen */
#define BAR_WIDTH -1
/* Offset from the left. Set to 0 to have no effect */
#define BAR_OFFSET 0
/* Choose between an underline or an overline */
#define BAR_UNDERLINE 0
/* The thickness of the underline (in pixels). Set to 0 to disable. */
#define BAR_UNDERLINE_HEIGHT 2
/* Default bar position, overwritten by '-b' switch */
#define BAR_BOTTOM 1
/* The fonts used for the bar, comma separated. Only the first 2 will be used. */
//#define BAR_FONT "-*-tewi-medium-r-normal-*-11-*-*-*-*-*-*-*", "fixed"
#define BAR_FONT       "-*-terminus-medium-r-normal-*-16-*-*-*-c-*-*-1","fixed"
/* Some fonts don't set the right width for some chars, pheex it */
#define BAR_FONT_FALLBACK_WIDTH 6
/* Define the opacity of the bar (requires a compositor such as compton) */
#define BAR_OPACITY 1.0 /* 0 is invisible, 1 is opaque */
/* Color palette */
#define BACKGROUND 0x272727
#define COLOR0 0x1b1b1b
#define COLOR8 0x434343
#define COLOR1 0x7d699b
#define COLOR9 0x9d87b9
#define COLOR2 0x61859b
#define COLOR3 0x7d859b
#define COLOR4 0x616ab7
#define COLOR5 0x7c69b7
#define COLOR6 0x6185b6
#define COLOR7 0xdde3ff
#define FOREGROUND 0xc5c8c6

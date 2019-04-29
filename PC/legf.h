#ifndef LEGF_H_
#define LEGF_H_



//Responsive points
typedef struct ResponsiveValues{
    int Value;
    enum {Relative, Absolute, Responsive} Type;
} ResponsiveValue;

typedef struct png_image{
		int width;
		int height;
		unsigned char* data;
	} png_image;

//Child list
typedef struct node {
    void* val;
    struct node_t * next;
} node_t;

//Components
typedef struct Components{
    char Name[32];
    int CompID;
	int Depth;
    node_t* Child;
    struct Components* Parent;
    enum {Application, Frame, SimpleComponent, CustomComponent} Type;
    enum {None, Rect, Text, Line, Bitmap} Shape;
	png_image* png;
    union {
        struct{
            char Text[128];
            int TextColor;
            int BackgroundColor;
            int FontSize;
        } TextValues;
        char Bitmap[64];
        struct{
            int Color;
            int BackgroundColor;
            int BorderWidth;
        } ShapeValues;
    } ShapeValue;
    ResponsiveValue X1, Y1, X2, Y2;
    short Visible;
    short isContainer;
    short isFocusable;
    node_t* Methods;
    node_t* Events;
} Component;


typedef struct FontChar{
		char char_id;
		int x, y, width, height;
		int offsetx, offsety;
		int char_width;
		unsigned char map[14][14];
	} FontChar;

#define screenWidth 480
#define screenHeight 272

unsigned char screenBitmap[screenWidth][screenHeight][4];
Component* comps;
unsigned int component_count;
unsigned int component_tree_depth;

void semir();
int pc_render_test();
int pc_render();
void pc_render_init();
void pc_render_close();
void pc_render_flush();
void load_components();
void initialize_view();
void print_comp(Component aComp);
void refresh_view();
void bmp_random_contents();
void print_bmp_contents();
void save_font_to_c();
void save_comps_to_c();
void include_components();
Component load_comp();
png_image* include_image(int comp_id);
void save_images_to_c();

#endif

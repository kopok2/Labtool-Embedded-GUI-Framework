#include <legf.h>
#include <stdio.h>
#include <string.h>

#define PC_mode 1
#if PC_mode == 1
	#include <lodepng.h>
	#define font_png_path "font10.PNG"
	#define font_config_path "font10.cfg"
#else
	#include <font.c>
#endif
#define font_height 14
#include <gen_comps.c>


FontChar font[128];
int count_font = 0;

void load_font()
{
	#if PC_mode == 1
		unsigned error;
		unsigned char* image;
		unsigned width, height;
		error = lodepng_decode32_file(&image, &width, &height, font_png_path);
		if(error) printf("error %u: %s\n", error, lodepng_error_text(error));

		FILE* file = fopen (font_config_path, "r");
		int i = 0;
		count_font = 0;
		int font_part = 0;
		int x, y;
		fscanf (file, "%d", &i);    
		while (!feof (file))
		{  
			if(font_part > 7)
			{
				font_part = 1;
				for(x=0; x<16; x++)
				{
					for(y=0; y<16; y++)
					{
						font[count_font].map[x][y]=0;
					}
				}
				for(x=font[count_font].x; x<font[count_font].x+font[count_font].width; x++)
				{
					for(y=font[count_font].y; y<font[count_font].y+font[count_font].height; y++)
					{
						font[count_font].map[x-font[count_font].x][y-font[count_font].y]=image[(x+y*width)*4+3];
					}
				}
				count_font++;
			}
			else
			{
				font_part++;
			}
			switch(font_part)
			{
				case 1:
					font[count_font].char_width = i;
				break;
				case 2:
					font[count_font].offsetx = i;
				break;
				case 3:
					font[count_font].offsety = i;
				break;
				case 4:
					font[count_font].x = i;
				break;
				case 5:
					font[count_font].y = i;
				break;
				case 6:
					font[count_font].width = i;
				break;
				case 7:
					font[count_font].height = i;
				break;
				case 8:
					font[count_font].char_id = i;
				break;
				default:
					printf("Incorrect font part %u\n", font_part);
			}
			fscanf (file, "%d", &i);      
		}
		fclose (file);
		save_font_to_c();
	#else
		for(int i=0; i<font_b_count; ++i)
		{
			FontChar* lc = (FontChar*) &font_b[i];
			font[i] = *lc;
		}
	#endif
}

void save_font_to_c()
{
	FILE * fp;
	fp = fopen ("../font.c","w");
	unsigned char* lc =(unsigned char*) &font[0];
	fprintf(fp, "int font_b_count = %u;\n", count_font);
	fprintf(fp, "unsigned char font_b[%u][%u] = {{%u ", count_font, sizeof(font[0]), *(lc));
	for(int i=1; i<sizeof(font[0]); ++i)
	{
		fprintf(fp, ",%u ", *(lc+i));
	}
	fprintf(fp, "}");
	for(int j=1; j<count_font; ++j)
	{
		lc =(unsigned char*) &font[j];
		fprintf(fp, ",\n {%u ", *(lc));
		for(int i=1; i<sizeof(font[0]); ++i)
		{
			fprintf(fp, ",%u ", *(lc+i));
		}
		fprintf(fp, "}");
	}
	fprintf(fp, "};");
	fclose(fp);
}

int get_char_id(char char_id)
{
	int i;
	for(i=0; i<128; i++)
	{
		if(font[i].char_id == char_id)
		{
			return i;
		}
	}
	return 0;
}

int text_width(char* str)
{
	int result =0;
	char c;
	int i =0;
	c = str[i];
	while(!c=='\0')
	{
		result += font[get_char_id(c)].char_width;
		++i;
		c = str[i];
	}
	return result;
}

int print_char(char char_id, int x_pos, int y_pos, int color, int bgcolor)
{
	double rr, gg, bb, a;
	unsigned int r, g, b;
	char str[16] = "000000";
	sprintf(str, "%06x", bgcolor);
	sscanf(str, "%02x%02x%02x", &r, &g, &b);
	int x, y, i;
	i = get_char_id(char_id);
	for(x=x_pos; x<x_pos+font[i].char_width; x++)
	{
		for(y=y_pos; y<y_pos+font_height; y++)
		{
			screenBitmap[x][y][0] = r;
			screenBitmap[x][y][1] = g;
			screenBitmap[x][y][2] = b;
			screenBitmap[x][y][3] = 255;
		}
	}
	sprintf(str, "%06x", color);
	sscanf(str, "%02x%02x%02x", &r, &g, &b);
	for(x=0; x<font[i].width; x++)
		{
			for(y=0; y<font[i].height; y++)
			{
				a = font[i].map[x][y];
				a = a/255;
				rr= r*a + (1-a)*screenBitmap[x_pos+x+font[i].offsetx][y_pos+y+font[i].offsety][0];
				gg= g*a + (1-a)*screenBitmap[x_pos+x+font[i].offsetx][y_pos+y+font[i].offsety][1];
				bb= b*a + (1-a)*screenBitmap[x_pos+x+font[i].offsetx][y_pos+y+font[i].offsety][2];
				screenBitmap[x_pos+x+font[i].offsetx][y_pos+y+font[i].offsety][0] = rr;
				screenBitmap[x_pos+x+font[i].offsetx][y_pos+y+font[i].offsety][1] = gg;
				screenBitmap[x_pos+x+font[i].offsetx][y_pos+y+font[i].offsety][2] = bb;
			}
		}
	return font[i].char_width;
}

void print_string(char* str, int x_pos, int y_pos, int color, int bgcolor)
{
	char c;
	int print_x = x_pos;
	int i =0;
	c = str[i];
	while(!c=='\0')
	{
		print_x += print_char(c, print_x, y_pos, color, bgcolor);
		++i;
		c = str[i];
	}
}

void text_rect(char* str, int x1, int y1, int x2, int y2, int color, int bgcolor)
{
	int x, y, x_pos, y_pos;
	unsigned int r, g, b;
	char cstr[16] = "000000";
	sprintf(cstr, "%06x", bgcolor);
	sscanf(cstr, "%02x%02x%02x", &r, &g, &b);
	for(x=x1; x<x2; x++)
	{
		for(y=y1; y<y2; y++)
		{
			screenBitmap[x][y][0]=r;
			screenBitmap[x][y][1]=g;
			screenBitmap[x][y][2]=b;
			screenBitmap[x][y][3]=255;
		}
	}
	if(text_width(str) > (x2-x1))
	{
		printf("String too long to be displayed.\n");
	}
	else
	{
		x_pos = x1 + ((x2-x1)/2)-(text_width(str)/2);
		y_pos = y1 + ((y2-y1)/2)-(font_height/2);
	}
	print_string(str, x_pos, y_pos, color, bgcolor);
}
 
void swap(int* a , int*b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 

float absolute(float x ) 
{ 
    if (x < 0) return -x; 
    else return x; 
} 

int iPartOfNumber(float x) 
{ 
    return (int)x; 
} 

int roundNumber(float x) 
{ 
    return iPartOfNumber(x + 0.5) ; 
} 

float fPartOfNumber(float x) 
{ 
    if (x>0) return x - iPartOfNumber(x); 
    else return x - (iPartOfNumber(x)+1); 
  
} 

float rfPartOfNumber(float x) 
{ 
    return 1 - fPartOfNumber(x); 
} 

void drawPixel(int x, int y, float a, int color)
{
	unsigned int r, g, b;
	char cstr[16] = "000000";
	sprintf(cstr, "%06x", color);
	sscanf(cstr, "%02x%02x%02x", &r, &g, &b);
	float rr, gg, bb;
	rr = r*a + (1-a)*screenBitmap[x][y][0];
	gg = g*a + (1-a)*screenBitmap[x][y][1];
	bb = b*a + (1-a)*screenBitmap[x][y][2];
	screenBitmap[x][y][0]= rr;
	screenBitmap[x][y][1]= gg;
	screenBitmap[x][y][2]= bb;
	screenBitmap[x][y][3]=255;
}

void drawAALine(int x0 , int y0 , int x1 , int y1, int color) 
{ 
	//Using Xiaolin Wu's line algorithm
    int steep = absolute(y1 - y0) > absolute(x1 - x0) ; 
  
    // swap the co-ordinates if slope > 1 or we 
    // draw backwards 
    if (steep) 
    { 
        swap(&x0 , &y0); 
        swap(&x1 , &y1); 
    } 
    if (x0 > x1) 
    { 
        swap(&x0 ,&x1); 
        swap(&y0 ,&y1); 
    } 
  
    //compute the slope 
    float dx = x1-x0; 
    float dy = y1-y0; 
    float gradient = dy/dx; 
    if (dx == 0.0) 
        gradient = 1; 
  
    int xpxl1 = x0; 
    int xpxl2 = x1; 
    float intersectY = y0; 
  
    // main loop 
    if (steep) 
    { 
        int x; 
        for (x = xpxl1 ; x <=xpxl2 ; x++) 
        { 
            // pixel coverage is determined by fractional 
            // part of y co-ordinate 
            drawPixel(iPartOfNumber(intersectY)-1, x, 
                        rfPartOfNumber(intersectY), color); 
            drawPixel(iPartOfNumber(intersectY), x, 
                        fPartOfNumber(intersectY), color); 
            intersectY += gradient; 
        } 
    } 
    else
    { 
        int x; 
        for (x = xpxl1 ; x <=xpxl2 ; x++) 
        { 
            // pixel coverage is determined by fractional 
            // part of y co-ordinate 
            drawPixel(x, iPartOfNumber(intersectY)-1, 
                        rfPartOfNumber(intersectY), color); 
            drawPixel(x, iPartOfNumber(intersectY), 
                          fPartOfNumber(intersectY), color); 
            intersectY += gradient; 
        } 
    } 
} 

void rectangle(int x1, int y1, int x2, int y2, int color, int bgcolor, int border)
{
	int x, y;
	unsigned int r, g, b;
	char str[16] = "000000";
	sprintf(str, "%06x", bgcolor);
	sscanf(str, "%02x%02x%02x", &r, &g, &b);

	//Central part
	for(x= x1+border; x<x2-border; x++)
	{
		for(y= y1+border; y< y2-border; y++)
		{
			screenBitmap[x][y][0] = r;
			screenBitmap[x][y][1] = g;
			screenBitmap[x][y][2] = b;
		}
	}

	//Borders
	sprintf(str, "%06x", color);
	sscanf(str, "%02x%02x%02x", &r, &g, &b);

	//Top border
	for(x=x1; x<x2; x++)
	{
		for(y= y1; y< y1+border; y++)
		{
			screenBitmap[x][y][0] = r;
			screenBitmap[x][y][1] = g;
			screenBitmap[x][y][2] = b;
		}
	}
	//Bottom border
	for(x=x1; x<x2; x++)
	{
		for(y= y2-border; y< y2; y++)
		{
			screenBitmap[x][y][0] = r;
			screenBitmap[x][y][1] = g;
			screenBitmap[x][y][2] = b;
		}
	}
	//Left border
	for(x=x1; x<x1+border; x++)
	{
		for(y= y1+border; y< y2-border; y++)
		{
			screenBitmap[x][y][0] = r;
			screenBitmap[x][y][1] = g;
			screenBitmap[x][y][2] = b;
		}
	}
	//Right border
	for(x=x2-border; x<x2; x++)
	{
		for(y= y1+border; y< y2-border; y++)
		{
			screenBitmap[x][y][0] = r;
			screenBitmap[x][y][1] = g;
			screenBitmap[x][y][2] = b;
		}
	}
}

void draw_image(png_image* img, int x1, int y1)
{
	printf("%u %u %u\n", &img, img->width, img->height);
	for(int x=x1; x<x1+img->width; ++x)
	{
		for(int y=y1; y<y1+img->height; ++y)
		{
			screenBitmap[x][y][0] = img->data[(x-x1+(y-y1)*img->width)*4+0];
			screenBitmap[x][y][1] = img->data[(x-x1+(y-y1)*img->width)*4+1];
			screenBitmap[x][y][2] = img->data[(x-x1+(y-y1)*img->width)*4+2];
		}
	}
}

void initialize_view()
{
	printf("Initializing LEGF...\n");
	load_font();
    #if PC_mode == 1
        pc_render_init();
		load_components();
    #else
		pc_render_init();
		include_components();
	#endif
	setup_comps();
	//comps = comps_d;
	//generate_parent_tree();
}

int getx1(Component aComp)
{
    int x1 =0;
    int px1 =0;
    if(aComp.Parent)
    {
        struct Components pr;
        pr = *aComp.Parent;
        px1 = getx1(pr);
    }
    switch(aComp.X1.Type)
    {
        case Relative:
            x1 = px1 + aComp.X1.Value;
        break;
        case Absolute:
            x1 = aComp.X1.Value;
        break;
        case Responsive:
            x1 = px1;
        break;
        default:
            printf("Unrecognized point type\n");
    }
    return x1;
}

int gety1(Component aComp)
{
    int y1 =0;
    int py1 =0;
    if(aComp.Parent)
    {
        struct Components pr;
        pr = *aComp.Parent;
        py1 = gety1(pr);
    }
    switch(aComp.Y1.Type)
    {
        case Relative:
            y1 = py1 + aComp.Y1.Value;
        break;
        case Absolute:
            y1 = aComp.Y1.Value;
        break;
        case Responsive:
            y1 = py1;
        break;
        default:
            printf("Unrecognized point type\n");
    }
    return y1;
}

int getx2(Component aComp)
{
    int x2 =0;
    int px1 =0;
    int px2 =0;
    if(aComp.Parent)
    {
        struct Components pr;
        pr = *aComp.Parent;
		px1 = getx1(pr);
        px2 = getx2(pr);
    }
    switch(aComp.X2.Type)
    {
        case Relative:
            x2 = px1 + aComp.X2.Value;
        break;
        case Absolute:
            x2 = aComp.X2.Value;
        break;
        case Responsive:
            x2 = px2;
        break;
        default:
            printf("Unrecognized point type\n");
    }
    return x2;
}

int gety2(Component aComp)
{
    int y2 =0;
    int py1 =0;
    int py2 =0;
    if(aComp.Parent)
    {
        struct Components pr;
        pr = *aComp.Parent;
        py1 = gety1(pr);
        py2 = gety2(pr);
    }
    switch(aComp.Y2.Type)
    {
        case Relative:
            y2 = py1 + aComp.Y2.Value;
        break;
        case Absolute:
            y2 = aComp.Y2.Value;
        break;
        case Responsive:
            y2 = py2;
        break;
        default:
            printf("Unrecognized point type\n");
    }
    return y2;
}

void refresh_view()
{
	Component* aComps = comps;
	int n = component_count;
	rectangle(0, 0, screenWidth, screenHeight, 0x000000, 0x000000, 0);
    int j, d;
	for(d=0; d<=component_tree_depth; ++d)
    {
		for(j =0; j<n; j++)
		{
			if(aComps[j].Depth == d)
			{
				if(aComps[j].Visible)
				{
					//Calculate render positions
					int x1 = getx1(aComps[j]);
					int y1 = gety1(aComps[j]);
					int x2 = getx2(aComps[j]);
					int y2 = gety2(aComps[j]);

					switch(aComps[j].Shape)
					{
						case Text:
							text_rect(aComps[j].ShapeValue.TextValues.Text,x1,y1,x2,y2,aComps[j].ShapeValue.TextValues.TextColor,aComps[j].ShapeValue.TextValues.BackgroundColor);
						break;
						case Rect:
							rectangle(x1, y1, x2, y2, aComps[j].ShapeValue.ShapeValues.Color, aComps[j].ShapeValue.ShapeValues.BackgroundColor, aComps[j].ShapeValue.ShapeValues.BorderWidth);
						break;
						case Line:
							drawAALine(x1, y1, x2, y2, aComps[j].ShapeValue.ShapeValues.Color);
						break;
						case Bitmap:
							draw_image(aComps[j].png, x1, y1);
						break;
						default:
							printf("Unrecognized component");
					}
				}
			}
		}
    }
	#if PC_mode == 1
        pc_render_flush();
    #else
		pc_render_flush();
	#endif
}

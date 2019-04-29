#include <legf.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define PC_mode 1
#if PC_mode == 1
	#include <lodepng.h>
#else
	#include <images.c>
#endif
char Result[1024];

void add_attr(char what[], char value[])
{
    char tmp_str[1024];
    sprintf(tmp_str, "    \"%s\": %s,\n", what, value);
    strcat(Result, tmp_str);
}

void load_image(png_image* dest, char* source_path)
{
	int error;
	error = lodepng_decode32_file(&dest->data, &dest->width, &dest->height, source_path);
	if(error) printf("error %u: %s\n", error, lodepng_error_text(error));
}
#if PC_mode == 0
png_image* include_image(int comp_id)
{
	png_image* lc = (png_image*) images[comp_id-1];
	//printf("dest: %u\n", lc);
	//printf("%u %u %u %u %u\n", lc, comp_id, &data[comp_id-1], lc->width, lc->height);
	lc->data = data[comp_id-1];
	return lc;
}
#endif
char * i(int a)
{
    static char tmp_str[1024];
    sprintf(tmp_str, "%d", a);
    return tmp_str;
}

char * s(char * a)
{
    static char tmp_str[1024];
    sprintf(tmp_str, "\"%s\"", a);
    return tmp_str;
}

void print_comp(Component aComp)
{
    strcpy(Result, "{\n");
    add_attr("Name", s(aComp.Name));
    add_attr("CompID", i(aComp.CompID));
    add_attr("Parent", i((int)aComp.Parent));
    add_attr("Type", i(aComp.Type));
    add_attr("Shape", i(aComp.Shape));
    switch(aComp.Shape)
    {
        case Text:
            add_attr("Text", s(aComp.ShapeValue.TextValues.Text));
            add_attr("TextColor", i(aComp.ShapeValue.TextValues.TextColor));
            add_attr("TBackgroundColor", i(aComp.ShapeValue.TextValues.BackgroundColor));
            add_attr("FontSize", i(aComp.ShapeValue.TextValues.FontSize));
        break;
        case Rect:
        case Line:
            add_attr("Color", i(aComp.ShapeValue.ShapeValues.Color));
            add_attr("BackgroundColor", i(aComp.ShapeValue.ShapeValues.BackgroundColor));
            add_attr("BorderWidth", i(aComp.ShapeValue.ShapeValues.BorderWidth));
        break;
        case Bitmap:
            add_attr("Bitmap", s(aComp.ShapeValue.Bitmap));
        break;
        default:
        break;
    }
    add_attr("X1Type", i(aComp.X1.Type));
    add_attr("X1Value", i(aComp.X1.Value));
    add_attr("Y1Type", i(aComp.Y1.Type));
    add_attr("Y1Value", i(aComp.Y1.Value));
    add_attr("X2Type", i(aComp.X2.Type));
    add_attr("X2Value", i(aComp.X2.Value));
    add_attr("Y2Type", i(aComp.Y2.Type));
    add_attr("Y2Value", i(aComp.Y2.Value));
    add_attr("Visible", i(aComp.Visible));
    add_attr("isContainer", i(aComp.isContainer));
    add_attr("isFocusable", i(aComp.isFocusable));
    strcat(Result, "}\n");
    printf(Result);
}

Component load_comp(char * path)
{
    Component Result;
    FILE *fptr;
    char buffer[255];
    char delim[2];
    char *ptr;
    char type[128];
    char value[128];
    fptr = fopen(path, "r");
    if ((fptr = fopen(path,"r")) == NULL){
        printf("Error! opening file");
    }
    while(fgets(buffer, 255, (FILE*) fptr))
    {
        strcpy(delim, ":");
        ptr = strtok(buffer, delim);
        strcpy(type, "");
        strcpy(value, "");
        while(ptr != NULL)
        {
            if(strcmp(type, "")== 0)
            {
                strcpy(type, ptr);
            }
            else
            {
                strcpy(value, ptr);
            }
            ptr = strtok(NULL, delim);
            
        }
        if(strcmp(type, "")!=0)
        {
            if(strcmp(value, "")!=0)
            {
                if (strstr(type, "Name") != NULL)
                {
                    strcpy(delim, "\"");
                    ptr = strtok(value, delim);
                    ptr = strtok(NULL, delim);
                    strcpy(Result.Name, ptr);
                }
                if (strstr(type, "CompID") != NULL)
                {
                    strcpy(delim, ",");
                    ptr = strtok(value, delim);
                    Result.CompID = atoi(ptr);
                }
                if (strstr(type, "Parent") != NULL)
                {
                    strcpy(delim, ",");
                    ptr = strtok(value, delim);
                    Result.Parent = (void*)atoi(ptr);
                }
                if (strstr(type, "\"Type\"") != NULL)
                {
                    strcpy(delim, ",");
                    ptr = strtok(value, delim);
                    Result.Type = atoi(ptr);
                }
                if (strstr(type, "\"Shape\"") != NULL)
                {
                    strcpy(delim, ",");
                    ptr = strtok(value, delim);
                    Result.Shape = atoi(ptr);
                }
                if (strstr(type, "\"Text\"") != NULL)
                {
                    strcpy(delim, "\"");
                    ptr = strtok(value, delim);
                    ptr = strtok(NULL, delim);
                    strcpy(Result.ShapeValue.TextValues.Text, ptr);
                }
                if (strstr(type, "\"TextColor\"") != NULL)
                {
                    strcpy(delim, "\"");
                    ptr = strtok(value, delim);
                    ptr = strtok(NULL, delim);
                    Result.ShapeValue.TextValues.TextColor = strtol(ptr, NULL, 16);
                }
                if (strstr(type, "\"TBackgroundColor\"") != NULL)
                {
                    strcpy(delim, "\"");
                    ptr = strtok(value, delim);
                    ptr = strtok(NULL, delim);
                    Result.ShapeValue.TextValues.BackgroundColor = strtol(ptr, NULL, 16);
                }
                if (strstr(type, "\"FontSize\"") != NULL)
                {
                    strcpy(delim, ",");
                    ptr = strtok(value, delim);
                    Result.ShapeValue.TextValues.FontSize = atoi(ptr);
                }
                if (strstr(type, "\"X1Type\"") != NULL)
                {
                    strcpy(delim, ",");
                    ptr = strtok(value, delim);
                    Result.X1.Type = atoi(ptr);
                }
                if (strstr(type, "\"X1Value\"") != NULL)
                {
                    strcpy(delim, ",");
                    ptr = strtok(value, delim);
                    Result.X1.Value = atoi(ptr);
                }
                if (strstr(type, "\"Y1Type\"") != NULL)
                {
                    strcpy(delim, ",");
                    ptr = strtok(value, delim);
                    Result.Y1.Type = atoi(ptr);
                }
                if (strstr(type, "\"Y1Value\"") != NULL)
                {
                    strcpy(delim, ",");
                    ptr = strtok(value, delim);
                    Result.Y1.Value = atoi(ptr);
                }
                if (strstr(type, "\"X2Type\"") != NULL)
                {
                    strcpy(delim, ",");
                    ptr = strtok(value, delim);
                    Result.X2.Type = atoi(ptr);
                }
                if (strstr(type, "\"X2Value\"") != NULL)
                {
                    strcpy(delim, ",");
                    ptr = strtok(value, delim);
                    Result.X2.Value = atoi(ptr);
                }
                if (strstr(type, "\"Y2Type\"") != NULL)
                {
                    strcpy(delim, ",");
                    ptr = strtok(value, delim);
                    Result.Y2.Type = atoi(ptr);
                }
                if (strstr(type, "\"Y2Value\"") != NULL)
                {
                    strcpy(delim, ",");
                    ptr = strtok(value, delim);
                    Result.Y2.Value = atoi(ptr);
                }
                if (strstr(type, "\"Bitmap\"") != NULL)
                {
                    strcpy(delim, "\"");
                    ptr = strtok(value, delim);
                    ptr = strtok(NULL, delim);
                    strcpy(Result.ShapeValue.Bitmap, ptr);
					Result.png = malloc(sizeof(png_image));
					load_image(Result.png, ptr);
                }
                if (strstr(type, "\"Color\"") != NULL)
                {
                    strcpy(delim, "\"");
                    ptr = strtok(value, delim);
                    ptr = strtok(NULL, delim);
                    Result.ShapeValue.ShapeValues.Color = strtol(ptr, NULL, 16);
                }
                if (strstr(type, "\"BackgroundColor\"") != NULL)
                {
                    strcpy(delim, "\"");
                    ptr = strtok(value, delim);
                    ptr = strtok(NULL, delim);
                    Result.ShapeValue.ShapeValues.BackgroundColor = strtol(ptr, NULL, 16);
                }
                if (strstr(type, "\"BorderWidth\"") != NULL)
                {
                    strcpy(delim, ",");
                    ptr = strtok(value, delim);
                    Result.ShapeValue.ShapeValues.BorderWidth = atoi(ptr);
                }
                if (strstr(type, "\"Visible\"") != NULL)
                {
                    strcpy(delim, ",");
                    ptr = strtok(value, delim);
                    Result.Visible = atoi(ptr);
                }
                if (strstr(type, "\"isContainer\"") != NULL)
                {
                    strcpy(delim, ",");
                    ptr = strtok(value, delim);
                    Result.isContainer = atoi(ptr);
                }
                if (strstr(type, "\"isFocusable\"") != NULL)
                {
                    strcpy(delim, ",");
                    ptr = strtok(value, delim);
                    Result.isFocusable = atoi(ptr);
                }
            }
        }
    }
    fclose(fptr);
    return Result;
}

#include <embedded_legf.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"
#define NULL 0

unsigned char png_6[] = {22 ,0 ,0 ,0 ,18 ,0 ,0 ,0 ,16 ,84 ,209 ,0 };
unsigned char img_6[] = {255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,247 ,162 ,166 ,255 ,242 ,85 ,91 ,255 ,246 ,148 ,152 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,246 ,141 ,145 ,255 ,237 ,28 ,36 ,255 ,237 ,28 ,36 ,255 ,238 ,35 ,43 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,250 ,191 ,193 ,255 ,242 ,85 ,91 ,255 ,248 ,170 ,173 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,246 ,141 ,145 ,255 ,237 ,28 ,36 ,255 ,237 ,28 ,36 ,255 ,237 ,28 ,36 ,255 ,237 ,28 ,36 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,239 ,49 ,57 ,255 ,237 ,28 ,36 ,255 ,238 ,35 ,43 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,246 ,141 ,145 ,255 ,237 ,28 ,36 ,255 ,237 ,28 ,36 ,255 ,237 ,28 ,36 ,255 ,237 ,28 ,36 ,255 ,244 ,106 ,112 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,238 ,35 ,43 ,255 ,237 ,28 ,36 ,255 ,237 ,28 ,36 ,255 ,246 ,141 ,145 ,255 ,247 ,162 ,166 ,255 ,237 ,28 ,36 ,255 ,237 ,28 ,36 ,255 ,237 ,28 ,36 ,255 ,237 ,28 ,36 ,255 ,237 ,28 ,36 ,255 ,254 ,248 ,248 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,245 ,128 ,132 ,255 ,237 ,28 ,36 ,255 ,237 ,28 ,36 ,255 ,237 ,28 ,36 ,255 ,237 ,28 ,36 ,255 ,237 ,28 ,36 ,255 ,237 ,28 ,36 ,255 ,237 ,28 ,36 ,255 ,237 ,28 ,36 ,255 ,244 ,106 ,112 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,254 ,248 ,248 ,255 ,242 ,92 ,98 ,255 ,237 ,28 ,36 ,255 ,237 ,28 ,36 ,255 ,237 ,28 ,36 ,255 ,237 ,28 ,36 ,255 ,237 ,28 ,36 ,255 ,237 ,28 ,36 ,255 ,237 ,28 ,36 ,255 ,254 ,248 ,248 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,254 ,248 ,248 ,255 ,244 ,114 ,119 ,255 ,237 ,28 ,36 ,255 ,237 ,28 ,36 ,255 ,237 ,28 ,36 ,255 ,237 ,28 ,36 ,255 ,237 ,28 ,36 ,255 ,244 ,106 ,112 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,251 ,212 ,214 ,255 ,238 ,35 ,43 ,255 ,237 ,28 ,36 ,255 ,237 ,28 ,36 ,255 ,237 ,28 ,36 ,255 ,237 ,28 ,36 ,255 ,254 ,248 ,248 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,254 ,248 ,248 ,255 ,241 ,71 ,77 ,255 ,237 ,28 ,36 ,255 ,237 ,28 ,36 ,255 ,237 ,28 ,36 ,255 ,237 ,28 ,36 ,255 ,245 ,121 ,125 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,246 ,135 ,139 ,255 ,237 ,28 ,36 ,255 ,237 ,28 ,36 ,255 ,238 ,35 ,43 ,255 ,252 ,219 ,221 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,246 ,141 ,145 ,255 ,237 ,28 ,36 ,255 ,237 ,28 ,36 ,255 ,237 ,28 ,36 ,255 ,246 ,148 ,152 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,247 ,162 ,166 ,255 ,237 ,28 ,36 ,255 ,237 ,28 ,36 ,255 ,237 ,28 ,36 ,255 ,242 ,92 ,98 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,239 ,49 ,57 ,255 ,237 ,28 ,36 ,255 ,237 ,28 ,36 ,255 ,237 ,28 ,36 ,255 ,247 ,162 ,166 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,250 ,191 ,193 ,255 ,239 ,57 ,64 ,255 ,237 ,28 ,36 ,255 ,237 ,28 ,36 ,255 ,237 ,28 ,36 ,255 ,237 ,28 ,36 ,255 ,238 ,35 ,43 ,255 ,254 ,248 ,248 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 };
unsigned char* images[6] ={NULL, NULL, NULL, NULL, NULL, &png_6[0]};
unsigned char* data[6] ={NULL, NULL, NULL, NULL, NULL, &img_6[0]};

unsigned int component_count = 0;
unsigned int component_tree_depth;

/* INITIALIZE SECTION */
Component comps[11];

void setup_comps(void)
{sprintf(comps[0].Name, "Button");
comps[0].CompID = 1;
comps[0].Parent =(Component *) 0;
comps[0].Type = 2;
comps[0].Shape = 1;
comps[0].ShapeValue.ShapeValues.Color = 0x3179E4;
comps[0].ShapeValue.ShapeValues.BackgroundColor = 0xAA3F55;
comps[0].ShapeValue.ShapeValues.BorderWidth = 1;
comps[0].X1.Type = 1;
comps[0].X1.Value = 350;
comps[0].Y1.Type = 1;
comps[0].Y1.Value = 0;
comps[0].X2.Type = 1;
comps[0].X2.Value = 480;
comps[0].Y2.Type = 1;
comps[0].Y2.Value = 272;
comps[0].Visible = 1;
comps[0].isContainer = 1;
comps[0].isFocusable = 1;

sprintf(comps[1].Name, "wow");
comps[1].CompID = 2;
comps[1].Parent = (Component *)1;
comps[1].Type = 2;
comps[1].Shape = 2;
sprintf(comps[1].ShapeValue.TextValues.Text, "#####");
comps[1].ShapeValue.TextValues.TextColor = 0xFFFFFF;
comps[1].ShapeValue.TextValues.BackgroundColor = 0x000000;
comps[1].ShapeValue.TextValues.FontSize = 25;
comps[1].X1.Type = 0;
comps[1].X1.Value = 25;
comps[1].Y1.Type = 0;
comps[1].Y1.Value = 25;
comps[1].X2.Type = 0;
comps[1].X2.Value = 300;
comps[1].Y2.Type = 0;
comps[1].Y2.Value = 100;
comps[1].Visible = 0;
comps[1].isContainer = 1;
comps[1].isFocusable = 1;

sprintf(comps[2].Name, "wow");
comps[2].CompID = 3;
comps[2].Parent = (Component *)1;
comps[2].Type = 2;
comps[2].Shape = 2;
comps[2].ShapeValue.ShapeValues.Color = 0x3179E4;
comps[2].ShapeValue.ShapeValues.BackgroundColor = 0xFF0000;
comps[2].ShapeValue.ShapeValues.BorderWidth = 1;
comps[2].X1.Type = 0;
comps[2].X1.Value = 1;
comps[2].Y1.Type = 0;
comps[2].Y1.Value = 1;
comps[2].X2.Type = 2;
comps[2].X2.Value = 129;
comps[2].Y2.Type = 0;
comps[2].Y2.Value = 271;
comps[2].Visible = 1;
comps[2].isContainer = 1;
comps[2].isFocusable = 1;

sprintf(comps[3].Name, "Button");
comps[3].CompID = 4;
comps[3].Parent =(Component *) 3;
comps[3].Type = 2;
comps[3].Shape = 2;
sprintf(comps[3].ShapeValue.TextValues.Text, "Settings");
comps[3].ShapeValue.TextValues.TextColor = 0xFFFFFF;
comps[3].ShapeValue.TextValues.BackgroundColor = 0x0000FF;
comps[3].ShapeValue.TextValues.FontSize = 25;
comps[3].X1.Type = 2;
comps[3].X1.Value = 11;
comps[3].Y1.Type = 0;
comps[3].Y1.Value = 0;
comps[3].X2.Type = 2;
comps[3].X2.Value = 0;
comps[3].Y2.Type = 0;
comps[3].Y2.Value = 54;
comps[3].Visible = 1;
comps[3].isContainer = 1;
comps[3].isFocusable = 1;

sprintf(comps[4].Name, "Button");
comps[4].CompID = 5;
comps[4].Parent = (Component *)3;
comps[4].Type = 2;
comps[4].Shape = 2;
sprintf(comps[4].ShapeValue.TextValues.Text, "Sensors");
comps[4].ShapeValue.TextValues.TextColor = 0xFFFFFF;
comps[4].ShapeValue.TextValues.BackgroundColor = 0x000080;
comps[4].ShapeValue.TextValues.FontSize = 25;
comps[4].X1.Type = 2;
comps[4].X1.Value = 11;
comps[4].Y1.Type = 0;
comps[4].Y1.Value = 54;
comps[4].X2.Type = 2;
comps[4].X2.Value = 0;
comps[4].Y2.Type = 0;
comps[4].Y2.Value = 108;
comps[4].Visible = 1;
comps[4].isContainer = 1;
comps[4].isFocusable = 1;

sprintf(comps[5].Name, "Button");
comps[5].CompID = 6;
comps[5].Parent = (Component *)0;
comps[5].Type = 2;
comps[5].Shape = 2;
sprintf(comps[5].ShapeValue.TextValues.Text, "Created by Karol Oleszek");
comps[5].ShapeValue.TextValues.TextColor = 0xFFFFFF;
comps[5].ShapeValue.TextValues.BackgroundColor = 0x000080;
comps[5].ShapeValue.TextValues.FontSize = 25;
comps[5].X1.Type = 0;
comps[5].X1.Value = 0;
comps[5].Y1.Type = 0;
comps[5].Y1.Value = 0;
comps[5].X2.Type = 0;
comps[5].X2.Value = 350;
comps[5].Y2.Type = 0;
comps[5].Y2.Value = 250;
comps[5].Visible = 1;
comps[5].isContainer = 1;
comps[5].isFocusable = 1;

sprintf(comps[6].Name, "Button");
comps[6].CompID = 7;
comps[6].Parent = (Component *)3;
comps[6].Type = 2;
comps[6].Shape = 2;
sprintf(comps[6].ShapeValue.TextValues.Text, "CPU");
comps[6].ShapeValue.TextValues.TextColor = 0xFFFFFF;
comps[6].ShapeValue.TextValues.BackgroundColor = 0x0000FF;
comps[6].ShapeValue.TextValues.FontSize = 25;
comps[6].X1.Type = 2;
comps[6].X1.Value = 11;
comps[6].Y1.Type = 0;
comps[6].Y1.Value = 108;
comps[6].X2.Type = 2;
comps[6].X2.Value = 0;
comps[6].Y2.Type = 0;
comps[6].Y2.Value = 162;
comps[6].Visible = 1;
comps[6].isContainer = 1;
comps[6].isFocusable = 1;

sprintf(comps[7].Name, "Button");
comps[7].CompID = 8;
comps[7].Parent = (Component *)3;
comps[7].Type = 2;
comps[7].Shape = 2;
sprintf(comps[7].ShapeValue.TextValues.Text, "Memory");
comps[7].ShapeValue.TextValues.TextColor = 0xFFFFFF;
comps[7].ShapeValue.TextValues.BackgroundColor = 0x000080;
comps[7].ShapeValue.TextValues.FontSize = 25;
comps[7].X1.Type = 2;
comps[7].X1.Value = 11;
comps[7].Y1.Type = 0;
comps[7].Y1.Value = 162;
comps[7].X2.Type = 2;
comps[7].X2.Value = 0;
comps[7].Y2.Type = 0;
comps[7].Y2.Value = 216;
comps[7].Visible = 1;
comps[7].isContainer = 1;
comps[7].isFocusable = 1;

sprintf(comps[8].Name, "Button");
comps[8].CompID = 9;
comps[8].Parent = (Component *)3;
comps[8].Type = 2;
comps[8].Shape = 2;
sprintf(comps[8].ShapeValue.TextValues.Text, "Exit >");
comps[8].ShapeValue.TextValues.TextColor = 0xFFFFFF;
comps[8].ShapeValue.TextValues.BackgroundColor = 0x0000FF;
comps[8].ShapeValue.TextValues.FontSize = 25;
comps[8].X1.Type = 2;
comps[8].X1.Value = 11;
comps[8].Y1.Type = 0;
comps[8].Y1.Value = 216;
comps[8].X2.Type = 2;
comps[8].X2.Value = 0;
comps[8].Y2.Type = 0;
comps[8].Y2.Value = 268;
comps[8].Visible = 1;
comps[8].isContainer = 1;
comps[8].isFocusable = 1;

sprintf(comps[9].Name, "Button");
comps[9].CompID = 10;
comps[9].Parent = 0;
comps[9].Type = 2;
comps[9].Shape = 2;
sprintf(comps[9].ShapeValue.TextValues.Text, "Labtool Embedded GUI Framework");
comps[9].ShapeValue.TextValues.TextColor = 0xFFFFFF;
comps[9].ShapeValue.TextValues.BackgroundColor = 0x000080;
comps[9].ShapeValue.TextValues.FontSize = 25;
comps[9].X1.Type = 0;
comps[9].X1.Value = 0;
comps[9].Y1.Type = 0;
comps[9].Y1.Value = 250;
comps[9].X2.Type = 0;
comps[9].X2.Value = 350;
comps[9].Y2.Type = 0;
comps[9].Y2.Value = 272;
comps[9].Visible = 1;
comps[9].isContainer = 1;
comps[9].isFocusable = 1;

sprintf(comps[10].Name, "Button");
comps[10].CompID = 11;
comps[10].Parent = (Component *) 6;
comps[10].Type = 2;
comps[10].Shape = 2;
sprintf(comps[10].ShapeValue.TextValues.Text, "...");
comps[10].ShapeValue.TextValues.TextColor = 0xFFFFFF;
comps[10].ShapeValue.TextValues.BackgroundColor = 0x000000;
comps[10].ShapeValue.TextValues.FontSize = 25;
comps[10].X1.Type = 0;
comps[10].X1.Value = 0;
comps[10].Y1.Type = 0;
comps[10].Y1.Value = 0;
comps[10].X2.Type = 0;
comps[10].X2.Value = 350;
comps[10].Y2.Type = 0;
comps[10].Y2.Value = 108;
comps[10].Visible = 1;
comps[10].isContainer = 1;
comps[10].isFocusable = 1;
}

png_image* include_image(int comp_id)
{
	png_image* lc = (png_image*) images[comp_id-1];
	lc->data = data[comp_id-1];
	return lc;
}

Component* get_comp_ptr_from_id(int id)
{
	for(int i=0; i<component_count; ++i)
	{
		if(comps[i].CompID == id)
		{
			return &comps[i];
		}
	}
	return NULL;
}

int get_comp_depth(Component* aComp)
{
	if(aComp->Parent)
	{
		return get_comp_depth(aComp->Parent) + 1;
	}
	else
	{
		return 0;
	}
}

void generate_parent_tree()
{
	int deapest = 0;
	for(int i=0; i<component_count; ++i)
	{
		comps[i].Parent = get_comp_ptr_from_id((int)comps[i].Parent);
	}
	for(int i=0; i<component_count; ++i)
	{
		comps[i].Depth = get_comp_depth(&comps[i]);
		if(comps[i].Depth > deapest)
		{
			deapest = comps[i].Depth;
		}
	}
	component_tree_depth = deapest;
}

void include_components()
{
	#if INDIRECT_INCLUDE == 1
	component_count = comp_b_count;
	comps = (Component*)malloc(component_count * sizeof(Component));
	for(int i=0; i<comp_b_count; ++i)
		{
			Component* lc = (Component*) &comps_b[i];
			comps[i] = *lc;
			if(comps[i].Shape == Bitmap)
			{
				comps[i].png = malloc(sizeof(png_image));
				comps[i].png = include_image(comps[i].CompID);
			}
		}
		#endif
		setup_comps();
		component_count = 11;
		generate_parent_tree();
}

void legf_init(void)
{
	BSP_LCD_Clear(LCD_COLOR_BLUE);
	include_components();
}

/* REFRESH SECTION */

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
char Result[2048];
char * i(int a)
{
    static char tmp_str[1024];
    sprintf(tmp_str, "%d", a);
    return tmp_str;
}
int hh=0;
void add_attr(char what[], char value[])
{
    char tmp_str[1024];
    sprintf(tmp_str, "    \"%s\": %s,\n", what, value);
    strcat(Result, tmp_str);
		BSP_LCD_DisplayStringAt(0,hh*14, (uint8_t*)tmp_str, LEFT_MODE);
	hh++;
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
}
void legf_refresh(void)
{
	Component* aComps = comps;
	int n = component_count;
	char str[256];
  BSP_LCD_Clear(LCD_COLOR_BLACK);
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
  BSP_LCD_SetFont(&Font12);
	sprintf(str, "Comps:%u Depth:%u Size: %d", n, component_tree_depth+1, sizeof(Component));
	BSP_LCD_DisplayStringAt(200, (BSP_LCD_GetYSize() - 55), (uint8_t *)str, LEFT_MODE);
	for(int d=0; d<=component_tree_depth; ++d)
  {
		for(int j =0; j<n; j++)
		{
			
			if(aComps[j].Depth == d)
			{
					BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
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
						BSP_LCD_SetTextColor(0xFF000000+aComps[j].ShapeValue.TextValues.BackgroundColor);
						BSP_LCD_FillRect(x1, y1, x2-x1, y2-y1);
						BSP_LCD_SetTextColor(0xFF000000+aComps[j].ShapeValue.TextValues.TextColor);
						BSP_LCD_SetBackColor(0xFF000000+aComps[j].ShapeValue.TextValues.BackgroundColor);
						sprintf(str, "%s", aComps[j].ShapeValue.TextValues.Text);
						BSP_LCD_DisplayStringAt(x1+(x2-x1)/2-strlen(str)*4, y1+(y2-y1)/2-6, (uint8_t *)str, LEFT_MODE);
					
					break;
					case Bitmap:
						BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
					break;
					case Line:
						BSP_LCD_SetTextColor(LCD_COLOR_LIGHTRED);
					break;
					case Rect:
						BSP_LCD_SetTextColor(0xFF000000+aComps[j].ShapeValue.ShapeValues.BackgroundColor);
					BSP_LCD_FillRect(x1, y1, x2-x1, y2-y1);
						BSP_LCD_SetTextColor(0xFF000000+aComps[j].ShapeValue.ShapeValues.Color);
						int b = aComps[j].ShapeValue.ShapeValues.BorderWidth;
						BSP_LCD_FillRect(x1+b, y1+b, x2-x1-b, y2-y1-b);
					break;
					default:
						BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
					break;
				}
			}			
		}
		}
  }
}

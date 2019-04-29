#include <stdlib.h>
#include <legf.h>
#include <stdio.h>
#include <dirent.h>
#include <comps.c>
#define PC_mode 1
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
	//printf("%u\n", component_tree_depth);
}

void load_components()
{
    //Load components
    comps = (Component*)malloc(128 * sizeof(Component));
    int i = 0;
    DIR *dir;
    char path[256];
    struct dirent *ent;
    if ((dir = opendir ("../components/")) != NULL)
		{
        while ((ent = readdir (dir)) != NULL)
		{
            strcpy(path, "");
            strcat(path, "../components/");
            strcat(path, ent->d_name);
            //printf ("%s \n", path);
            if(i>1)
			{
				comps[i-2] = load_comp(path);
			}
            i = i+1;
        }
        closedir (dir);
    } 
	else
	{
		/* could not open directory */
		perror ("");
    }
	component_count = i-2;
	save_comps_to_c();
	save_images_to_c();
	generate_parent_tree();
	
}
#if PC_mode == 0
void include_components()
{
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
				//printf("dest: %u\n", comps[i].png);
			}
		}
		generate_parent_tree();
}
#endif
void save_comps_to_c()
{
	FILE * fp;
	fp = fopen ("../comps.c","w");
	unsigned char* lc =(unsigned char*) &comps[0];
	fprintf(fp, "int comp_b_count = %u;\n", component_count);
	fprintf(fp, "unsigned char comps_b[%u][%u] = {{%u ", component_count, sizeof(comps[0]), *(lc));
	for(int i=1; i<sizeof(comps[0]); ++i)
	{
		fprintf(fp, ",%u ", *(lc+i));
	}
	fprintf(fp, "}");
	for(int j=1; j<component_count; ++j)
	{
		lc =(unsigned char*) &comps[j];
		fprintf(fp, ",\n {%u ", *(lc));
		for(int i=1; i<sizeof(comps[0]); ++i)
		{
			fprintf(fp, ",%u ", *(lc+i));
		}
		fprintf(fp, "}");
	}
	fprintf(fp, "};");
	fclose(fp);
}

void save_images_to_c()
{
	FILE * fp;
	fp = fopen ("../images.c","w");
	
	int image_count =0;
	unsigned char* lc;
	for(int i=0; i<component_count; ++i)
	{
		if(comps[i].Shape == Bitmap)
		{
			++image_count;
			lc =(unsigned char*) comps[i].png;
			fprintf(fp, "char png_%u[] = {%u ", comps[i].CompID, *(lc));
			for(int j=1; j<sizeof(png_image); ++j)
			{
				fprintf(fp, ",%u ", *(lc+j));
			}
			fprintf(fp, "};\n");
			lc =(unsigned char*) comps[i].png->data;
			fprintf(fp, "char img_%u[] = {%u ", comps[i].CompID, *(lc));
			for(int j=1; j<comps[i].png->width*comps[i].png->height*4; ++j)
			{
				fprintf(fp, ",%u ", *(lc+j));
			}
			fprintf(fp, "};\n");
		}
	}
	fprintf(fp, "char* images[%u] ={", component_count);
	if(comps[0].Shape == Bitmap)
	{
		fprintf(fp, "&png_1[0]");
	}
	else
	{
		fprintf(fp, "NULL");
	}
	for(int i=1; i<component_count; ++i)
	{
		if(comps[i].Shape == Bitmap)
		{
			fprintf(fp, ", &png_%u[0]", i+1);
		}
		else
		{
			fprintf(fp, ", NULL");
		}
	}
	fprintf(fp, "};\n");
	fprintf(fp, "char* data[%u] ={", component_count);
	if(comps[0].Shape == Bitmap)
	{
		fprintf(fp, "&img_1[0]");
	}
	else
	{
		fprintf(fp, "NULL");
	}
	for(int i=1; i<component_count; ++i)
	{
		if(comps[i].Shape == Bitmap)
		{
			fprintf(fp, ", &img_%u[0]", i+1);
		}
		else
		{
			fprintf(fp, ", NULL");
		}
	}
	fprintf(fp, "};\n");
	fclose(fp);
}

from os import listdir
from os.path import isfile, join
import json
dirpath = "components/"


def conv(key):
    result = key
    if "1T" in key:
        result = key.replace("1T", "1.T")
    elif "1V" in key:
        result = key.replace("1V", "1.V")
    elif "2T" in key:
        result = key.replace("2T", "2.T")
    elif "2V" in key:
        result = key.replace("2V", "2.V")
    elif "TextColor" in key:
        result = key.replace("TextColor", "ShapeValue.TextValues.TextColor")
    elif "TBackgroundColor" in key:
        result = key.replace("TBackgroundColor", "ShapeValue.TextValues.BackgroundColor")
    elif "FontSize" in key:
        result = key.replace("FontSize", "ShapeValue.TextValues.FontSize")
    elif "Text" in key:
        result = key.replace("Text", "ShapeValue.TextValues.Text")
    elif "Bitmap" in key:
        result = key.replace("Bitmap", "ShapeValue.Bitmap")
    elif "BackgroundColor" in key:
        result = key.replace("BackgroundColor", "ShapeValue.ShapeValues.BackgroundColor")
    elif "Color" in key:
        result = key.replace("Color", "ShapeValue.ShapeValues.Color")
    elif "BorderWidth" in key:
        result = key.replace("BorderWidth", "ShapeValue.ShapeValues.BorderWidth")
    return result


with open("gen_comps.c", "w") as outfile:
    comps = []
    for f in [f for f in listdir(dirpath)if isfile(join(dirpath, f))]:
        print(f)
        comps.append(json.loads(open(dirpath+f, "r").read()))
    
    outfile.write("Component comps[{0}];\n\n".format(comps.__len__()))
    outfile.write("void setup_comps(void)\n{")
    for id, obj in enumerate(comps):
        for key in obj:
            if key == "Text" or key == "Name" or key == "Bitmap":
                outfile.write("sprintf(comps[{0}].{1}, \"{2}\");\n".format(id, key, obj[key]).replace("Text", "ShapeValue.TextValues.Text").replace("Bitmap", "ShapeValue.Bitmap"))
            else:
                outfile.write("comps[{0}].{1} = {2};\n".format(id, conv(key), repr(obj[key]) if not "Color" in key else obj[key]).replace("'", '"'))
        outfile.write("\n")
    outfile.write("}\n\n")
//#include <EEPROM.h> 
#include <SPI.h>
#include <GD2.h>

void setup()
{
  GD.begin();
  GD.cmd_loadimage(0, 0);
  //GD.load("selfie3.jpg");
  GD.load("zx13.jpg");
  //GD.load("Boil1.png");
  //GD.load("Rad1.png");  
}

void loop()
{
  //GD.ClearColorRGB(0x000020);
  GD.Clear();
   GD.Begin(BITMAPS);
   GD.Vertex2ii(0, 0);
   GD.cmd_text(GD.w / 2, GD.h / 2, 31, OPT_CENTER, "Hello world");
  GD.swap();
}

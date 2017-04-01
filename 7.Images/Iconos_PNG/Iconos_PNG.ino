//21 Enero 2016
//#include <EEPROM.h>
#include <SPI.h>
#include <GD2.h>

#include "Icons0.h"        //ASSETS7    //-switchs, -boton enc
#include "Icons1.h"        //ASSETS7a   //-switchs, +boton enc, -icono de advertencia
#include "Icons2.h"        //ASSETS7b   //+switchs, +boton enc, -icono de advertencia, -iconos de audio
#include "Boton0.h"        //ASSETS10

//diseños para resaltar botones de encendido/apagado/reinicio de la PC
uint16_t  colorRP=255, colorGP=0, colorBP=0;
uint16_t  colorRE=255, colorGE=0, colorBE=0;
uint16_t  colorRR=255, colorGR=0, colorBR=0;
uint16_t  colorR=255, colorG=0, colorB=0;
//diseños para resaltar botones de encendido/apagado/reinicio de la PC

int Enc = 0;   //0= apagado, 1= encendido, 3= reset
int j, x, y;  //diseño de gauge progresivo
int menu = 0;  // 0= Menuprincipal, 1= Menu encendido
int retorno_MP =0;   //Mantiene en pantalla menu de encendido, 1 regresa a menu principal
int aviso = 0;   //bandera para confirmar tags 
int deltayaviso = 15;
//     int yico = 120;  //texto en movimiento vertical XD
int yico = 170;  //flecha en movimiento constante

void MenuPrincipal()
{
  //retorno_MP = 0;
  uint32_t m_ptr, m_w, m_h;
  GD.cmd_getprops(m_ptr, m_w, m_h);
  GD.finish();

  uint16_t w = GD.rd16(m_w);
  uint16_t h = GD.rd16(m_h);
  GD.BitmapSize(BILINEAR, BORDER, BORDER, w, h);
  float zoom = 0.3;

while(1)
{  
  GD.Clear();    
//  GD.Begin(BITMAPS);
//  GD.Vertex2ii(0, 95, 15);   //Imagen de fondo de  480x156

GD.SaveContext();
//    GD.ColorRGB(0xffffff);
    int zw = zoom * w / 2;
    int zh = zoom * h / 2;
    GD.Begin(BITMAPS);
    GD.cmd_scale(F16(zoom), F16(zoom));
    GD.cmd_setmatrix();
    GD.Vertex2ii(240 - zw, 173 - zh, 15, 0);
    zoom = min(1.0, zoom * 1.2);
GD.RestoreContext();    

//    GD.Vertex2ii(170, 115, 0);

   GD.Vertex2ii(0, 45, 0);
   GD.Vertex2ii(55, 45, 1);  
   GD.Vertex2ii(105, 45, 2);
   GD.Vertex2ii(155, 45, 3);  
   GD.Vertex2ii(205, 45, 4);  
   GD.Vertex2ii(255, 45, 5);    
   GD.Vertex2ii(0, 115, 6);
   GD.Vertex2ii(55, 115, 7);    
   GD.Vertex2ii(120, 115, 8);
   GD.Vertex2ii(155, 115, 9);  
   GD.Vertex2ii(205, 115, 10);  
   GD.Vertex2ii(255, 115, 11);   
   GD.Vertex2ii(0, 185, 12);        
   GD.Vertex2ii(55, 185, 13);     

   GD.Tag(2); IndicadorMP();  GD.Tag(255);

   if (aviso==1){
//         GD.Vertex2ii(35, 100, 3);  //escala 1.0
     GD.SaveContext();     
     icon3Zoom(3, 85, 120, 0.5);   // escala 0.5 XD de cualquier icono XD del set de iconos desplegado
       if (yico==144){yico=170;}
       yico = yico-1;       //lento
//       yico = yico-2;       //rápido
      // icon3Zoom(12, 365, 145, 1.0);   // 
//       icon3Zoom(12, 365, yico, 1.0);
//       GD.ColorRGB(0x00ff00);
       GD.Vertex2ii(365, yico, 12);     // No es necesario usar la instrucción para escalar las imagenes posteriores

     GD.Vertex2ii(380, 0, 0);
     GD.Vertex2ii(380, 20, 1);  
     GD.Vertex2ii(380, 45, 7);
     GD.Vertex2ii(380, 75, 5);  
     GD.Vertex2ii(380, 100, 6);  
    // GD.Vertex2ii(380, 130, 3);    
     GD.Vertex2ii(415, 0, 8);
     GD.Vertex2ii(415, 25, 9);    

     GD.ColorRGB(0x00ff00);
     GD.Vertex2ii(430, 60, 10);
     GD.Vertex2ii(430, 100, 12);  
     GD.Vertex2ii(410, 80, 13);  
     GD.Vertex2ii(450, 80, 11);   

     GD.RestoreContext();       
//     if (yico==110){yico=120;}
//     yico = yico-1;
//     GD.cmd_text(240, yico, 28,   OPT_CENTERX, "XD XD acceso a menu desplegable");   
     GD.cmd_text(240, 120, 28,   OPT_CENTERX, "Acceso a menu desplegable");   
     }

   GD.get_inputs();      
   GD.SaveContext();
     GD.ColorA(200);  
     GD.Tag(1);   marcaP(); //diseños para realzar sistema de encendido de la PC
     GD.Tag(255);
   GD.RestoreContext();   
    
    if (GD.inputs.tag==1){
          delay(100);
          espera();          
          carga_icoenc();  //ASSETS10
          menu=1;  
          GP();  //Selector de Menu
        }    
    
    if (GD.inputs.tag==2){
          aviso= aviso+1;
          deltayaviso=0;
          delay(195);
          if (aviso>=2){
              aviso= 0;
              deltayaviso=15;
            }
        }     
  GD.swap();
  }    
} 

void espera()
{
//  GD.ClearColorRGB(0x103000);  
  GD.ClearColorRGB(0x000025); //fondo de pantalla
  GD.Clear();
    GD.ColorA(255);  
//    GD.cmd_text(240, 120, 26,   OPT_CENTERX, "Procesando imagenes...");
    GD.cmd_text(240, 120, 26,   OPT_CENTERX, "Procesando entorno visual...");    
  GD.swap(); 
}

void IndicadorMP()
{
  if (Enc==0){GD.Vertex2ii(350, 175-deltayaviso, 0);}
  if (Enc>=1){GD.Vertex2ii(350, 175-deltayaviso, 1);}
}

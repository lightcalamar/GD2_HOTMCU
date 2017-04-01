void MenuEncPC()
{
  while(1)
  {
    GD.Clear();    
    GD.Begin(BITMAPS);
    GD.Vertex2ii(0, 95, 15);   //Imagen de fondo de  480x156
    
    GD.Vertex2ii(170, 115, 0);

    GD.get_inputs();      
GD.SaveContext();
    GD.ColorA(200);  
    GD.Tag(2);   
    GD.Tag(255);
GD.RestoreContext();   

    marca(); //diseños para realzar sistema de encendido de la PC
    
//    GD.Tag(2);  // al tocar la imagen del fondo de pantalla
//        GD.Vertex2ii(0, 95, 15);   //Imagen de fondo de  480x156
//    GD.Tag(255);

    
    if (GD.inputs.tag==2){
          delay(100);
          espera();          
          carga_iconos();   //ASSETS7/ASSETS7a/ASSETS7b menu principal
          menu=0;  //menu principal
          GP();  //Selector de Menu
        }    
    
  GD.swap();
  }  
}



void MenuEncPC1() {
//  LOAD_ASSETS_2();
//  LOAD_ASSETS_7();
//  cargarfondo();  //

retorno_MP = 0;

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


  GD.ColorA(200);  
  if (Enc==0){
    GD.Vertex2ii(170, 115, 0);
    colorRP = 255;   colorGP = 0;   colorBP = 0;    
    colorRE = 255;   colorGE = 0;   colorBE = 0;
    colorRR = 255;   colorGR = 0;   colorBR = 0;        
    colorR = 255;   colorG = 0;   colorB = 0;
    }
  if (Enc==1){
    GD.Vertex2ii(170, 115, 1);
    colorRP = 0;   colorGP = 255;   colorBP = 0;        
    colorRE = 0;   colorGE = 255;   colorBE = 0;
    colorRR = 0;   colorGR = 0;   colorBR = 255;    
    colorR = 0;   colorG = 255;   colorB = 0;    
    }   
  if (Enc==3){
    //if(Enc==0){GD.cmd_text(240, 120, 26,   OPT_CENTERX, "Sistema no iniciado, reincio no factible"); delay(2000);}else{
    GD.Vertex2ii(170, 115, 2);
    colorRP = 0;   colorGP = 0;   colorBP = 255;            
    colorRE = 0;   colorGE = 255;   colorBE = 0;    
    colorRR = 255;   colorGR = 255;   colorBR = 0;
    colorR = 0;   colorG = 255;   colorB = 0;//}
    }   

   GD.get_inputs();    
   GD.Tag(17);    GD.Vertex2ii(15, 35, 1);  GD.Tag(255);      
   GD.Tag(18);    GD.Vertex2ii(330, 35, 2);  GD.Tag(255);      

GD.SaveContext();
   GD.Tag(19);    marca();  GD.Tag(255);
GD.RestoreContext();   

    if (GD.inputs.tag==17){
          Enc=Enc+1;      
          if (Enc>=2){
            Enc=0;}
          delay(200);          
          //Insertar instrucción para activar rele de encendido/apagado y luego mandar al menu principal
          retorno_MP = 1;
        }

    if (GD.inputs.tag==18){
       if(Enc==0){GD.cmd_text(240, 100, 26, OPT_CENTERX, "Reincio no factible");}else{  
         Enc=3;    
         delay(200);
//         Enc = 1;
          //Insertar instrucción para activar rele de reincio y activar pantalla de reinicio, al saltar al menu principal hacer que Enc = 1  y luego mandar al menu principal
          retorno_MP = 1;}
       }


    if (GD.inputs.tag==19){
        delay(500);
        espera();          
        carga_iconos();   //ASSETS7/ASSETS7a/ASSETS7b menu principal
        menu=0;  //menu principal
        GP();  //Selector de Menu
       }


  //    GD.cmd_number(240,136,25,OPT_CENTER|OPT_SIGNED,retorno_MP);           

if (retorno_MP==1){

  GD.Begin(BITMAPS);
  GD.ColorA(200);  
  if (Enc==0){
    GD.Vertex2ii(170, 115, 0);
    colorRP = 255;   colorGP = 0;   colorBP = 0;    
    colorRE = 255;   colorGE = 0;   colorBE = 0;
    colorRR = 255;   colorGR = 0;   colorBR = 0;        
    colorR = 255;   colorG = 0;   colorB = 0;
    GD.cmd_text(240, 100, 26, OPT_CENTERX, "Apagando sistema...");
    }
  if (Enc==1){
    GD.Vertex2ii(170, 115, 1);
    colorRP = 0;   colorGP = 255;   colorBP = 0;        
    colorRE = 0;   colorGE = 255;   colorBE = 0;
    colorRR = 0;   colorGR = 0;   colorBR = 255;    
    colorR = 0;   colorG = 255;   colorB = 0;    
    GD.cmd_text(240, 100, 26, OPT_CENTERX, "Iniciando sistema...");    
    }   
  if (Enc==3){
    GD.Vertex2ii(170, 115, 2);
    colorRP = 0;   colorGP = 0;   colorBP = 255;            
    colorRE = 255;   colorGE = 0;   colorBE = 0;    
    colorRR = 255;   colorGR = 255;   colorBR = 0;
    colorR = 0;   colorG = 255;   colorB = 0;
    GD.cmd_text(240, 100, 26, OPT_CENTERX, "Reiniciando sistema...");    
    }  
  GD.SaveContext();
     marca();
  GD.RestoreContext();       

    GD.swap();
   
     delay(5000);
     espera();          
     carga_iconos();   //ASSETS7/ASSETS7a/ASSETS7b menu principal
     menu=0;  //menu principal
     GP();  //Selector de Menu
  }


  GD.swap();
 }
}

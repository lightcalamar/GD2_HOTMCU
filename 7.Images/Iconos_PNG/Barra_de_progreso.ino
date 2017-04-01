void GP()  //Diseño de gauge de espera
{
  do    
  {
   GD.ClearColorRGB(0x000025); //fondo de pantalla
   GD.Clear();

//Máscara de diseño   
  // marcas secundarias
    marcas(32, 240, 136, 100, 10);  //32 submarcas, centroX = 240, centroY = 136, RadioMax = 100, largomarca = 10 px
  //marcas principales
    marcas(4, 240, 136, 100, 20);  //4 marcas principales, centroX = 240, centroY = 136, RadioMax = 100, largomarca = 20 px  

   GD.ColorRGB(0,255,0); //R,G, B
   GD.Begin(POINTS);
   GD.PointSize(16 * 75);
   GD.Vertex2ii(240, 136);

   GD.ColorRGB(0x000025); //fondo de pantalla
   GD.PointSize(16 * 72);
   GD.Vertex2ii(240, 136);   
   
   GD.ColorRGB(0,255,0); //R,G, B
   GD.Begin(POINTS);
   GD.PointSize(16 * 58);
   GD.Vertex2ii(240, 136);

   GD.ColorRGB(0x000025); //fondo de pantalla
   GD.PointSize(16 * 56);
   GD.Vertex2ii(240, 136);      
   
//Máscara de diseño   
   
  // Lecturaaleatoria();   
   Progreso();
   

   GD.swap(); 
  }
  while(1);  
} 





void Progreso()  //Barra de progreso que retorna a menu principal
{
    GD.LineWidth(20);  //dot    espesor, default es 1 = comentar esta linea
    Lectura(j, 0, 100, 64, 240, 136, 70, 10);  //(int valor, valor minimo, valor máximo, int numerodesubmarcas, int xC, int yC, int RadioMax, int LargoMarca);  

//    GD.LineWidth(50);   //bar
//    Lectura(j, 0, 100, 100, 240, 136, 70, 10);  //(int valor, valor minimo, valor máximo, int numerodesubmarcas, int xC, int yC, int RadioMax, int LargoMarca);  
//      Lectura(j, 0, 100, 64, 240, 136, 70, 10);  //(int valor, valor minimo, valor máximo, int numerodesubmarcas, int xC, int yC, int RadioMax, int LargoMarca);  
//     Lectura(j, 0, 100, 256, 240, 136, 70, 20);  //(int valor, valor minimo, valor máximo, int numerodesubmarcas, int xC, int yC, int RadioMax, int LargoMarca);
//     Lectura(j, 0, 100, 512, 240, 136, 70, 20);  //(int valor, valor minimo, valor máximo, int numerodesubmarcas, int xC, int yC, int RadioMax, int LargoMarca);
      GD.cmd_number(240,136,25,OPT_CENTER|OPT_SIGNED,j);           
//      delay(25);
     if (j==100)
      {
       ok();
       delay(1000);
      }

     j = j + 1;
     
     if (j==101)
      {
       j = 0;  //resetea contador del gauge de progreso 
       
       if (menu==0){MenuPrincipal();}
//       if (menu==1){MenuEncPC();}
       if (menu==1){MenuEncPC1();}
       
      }

}


void ok()
{
   GD.cmd_text(240, 159, 23, OPT_CENTER, "OK"); 
   GD.swap();    
}  


void Lecturaaleatoria()
{
  //lectura
// int dato = random(0,100);  //0-100%
   int dato = random(0,1023);  //0-1023
 
   GD.LineWidth(50);
   Lectura(dato, 0, 1020, 128, 240, 136, 70, 10);  //(int valor, valor minimo, valor máximo, int numerodesubmarcas, int xC, int yC, int RadioMax, int LargoMarca);
//   Lectura(dato, 0, 1023, 32, 240, 136, 70, 10);  //(int valor, valor minimo, valor máximo, int numerodesubmarcas, int xC, int yC, int RadioMax, int LargoMarca);   
   delay(250);  
}  


void marcas(int NumMarcas, int xC, int yC, int RadioMax, int LargoMarca)
{
  GD.LineWidth(6);
  GD.Begin(LINES);

  for (int i = 0; i < NumMarcas; i++) 
  { 
    ray(x, y, 16 * (RadioMax-LargoMarca), i, NumMarcas, xC, yC); //punto inicial
    int xi=x, yi=y;

      ray(x, y, 16 * RadioMax, i, NumMarcas, xC, yC); //punto final
      int xf= x, yf = y;

    GD.ColorRGB(255,255,255); //R,G, B
    GD.Vertex2f(xi, yi);   // inicio
    GD.Vertex2f(xf, yf); //  fin
  }
}


void Lectura(int valor,int Minescala, int Maxescala, int NumMarcas, int xC, int yC, int RadioMax, int LargoMarca)
{
//  GD.LineWidth(6);
  GD.Begin(LINES);

  int Marcas = map(valor,Minescala,Maxescala,0,NumMarcas);

  for (int i = 0; i < Marcas; i++) 
  { 
    ray(x, y, 16 * (RadioMax-LargoMarca), i, NumMarcas, xC, yC); //punto inicial
    int xi=x, yi=y;

      ray(x, y, 16 * RadioMax, i, NumMarcas, xC, yC); //punto final
      int xf= x, yf = y;

    GD.ColorRGB(0,255,0); //R,G, B
    GD.Vertex2f(xi, yi);   // inicio
    GD.Vertex2f(xf, yf); //  fin
  }
}

static void ray(int &x, int &y, int r, int i, int n, int xc, int yc)
{
  uint16_t th = 0x8000 + 65536UL * i / n;  //ángulo de cada sector
  GD.polar(x, y, r, th);
  x += 16 * xc;
  y += 16 * yc;
}

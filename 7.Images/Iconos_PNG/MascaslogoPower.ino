void marca()
{
  GD.Begin(LINES);
  GD.LineWidth(30);
//  GD.ColorRGB(0xff0000);   //color de los segmentos
  GD.ColorRGB(colorRE,colorGE,colorBE);
  GD.Vertex2ii(56, 134); //  inicio
  GD.Vertex2ii(100, 134); //  fin 

  GD.ColorRGB(colorRR,colorGR,colorBR);
  GD.Vertex2ii(371, 134); //  inicio
  GD.Vertex2ii(415, 134); //  fin   
  
  GD.ColorRGB(colorR,colorG,colorB);
  GD.Vertex2ii(211, 214); //  inicio
  GD.Vertex2ii(255, 214); //  fin     
  
//  GD.ColorA(255);  
  GD.Begin(POINTS);  
  GD.PointSize(16*15);
  GD.ColorRGB(colorRP,colorGP,colorBP);    
  GD.Vertex2ii(431,172);
  GD.PointSize(16*13);
  GD.ColorRGB(0,0,0);  
  GD.Vertex2ii(431,172);  
  
  GD.Begin(LINES);
  GD.LineWidth(30);
  GD.ColorRGB(colorRP,colorGP,colorBP);    
  GD.Vertex2ii(431, 152); //  inicio
  GD.Vertex2ii(431, 170); //  fin   
  
  
//  GD.End();
}

void marcaP()
{
//  GD.ColorA(255);  
  GD.Begin(POINTS);  
  GD.PointSize(16*15);
  GD.ColorRGB(colorRP,colorGP,colorBP);    
  GD.Vertex2ii(431,172);
  GD.PointSize(16*13);
  GD.ColorRGB(0,0,0);  
  GD.Vertex2ii(431,172);  
  
  GD.Begin(LINES);
  GD.LineWidth(30);
  GD.ColorRGB(colorRP,colorGP,colorBP);    
  GD.Vertex2ii(431, 152); //  inicio
  GD.Vertex2ii(431, 170); //  fin   
  
  
//  GD.End();
}

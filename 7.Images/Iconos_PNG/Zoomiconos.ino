
void icon3Zoom(int numeroicono, int X, int Y, float zoom){
//   int X=45, Y=120;
//   float zoom = 0.5;
//  GD.Begin(BITMAPS);
    GD.cmd_scale(F16(zoom),F16(zoom));
    GD.cmd_setmatrix();
    GD.Vertex2ii(X, Y, numeroicono);
}  

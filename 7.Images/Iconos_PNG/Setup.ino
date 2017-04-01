void setup() {
  GD.begin();
//GD.self_calibrate();
//  GD.wr(REG_GPIO, 0x82);
//  GD.wr(REG_PWM_DUTY, 95);  //0-128  intensidad de la retroiluminacion XD en gameduino 2
  espera();          
//  carga_icoenc();  //ASSETS10
  carga_iconos();   //ASSETS7/ASSETS7a/ASSETS7b
  GP();
}

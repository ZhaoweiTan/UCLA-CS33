//2.90


static float u2f(unsigned u) {
  return float(u);
}

float fpwr4(int x){
  unsigned exp, frac;
  unsigned u;

  if(x < -75){
    exp = 0;
    frac = 0;
  }else if (x < -63){
    exp = 1 << (x*2 + 149);
    frac = 1;
  }else if( x < 64){
    exp = 2 * x + 127; 
    frac = 0;
  }
  else{
    exp = 255;
    frac = 0;
  }
}

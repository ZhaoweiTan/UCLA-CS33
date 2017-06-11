//Question 3.63


long switch_prob(long x, long n){
  long result = x;
  int index = n - 60;
  switch(index){
  case 0:
  case 2:
    result = 8 * x;
    break;
  case 3:
    result = x>>3;
    break;
  case 4:
    result = x<<4;
    result -=x;
    x = result;
  case 5:
    x = x * x;
  default:
    result = x + 75;
  }
  return result;
}




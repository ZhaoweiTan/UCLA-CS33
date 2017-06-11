//2.73 

int saturating_add(int x, int y){
  int w = (sizeof(int)<<3)-1;
  int total = x + y;
  int result = x + y;
  x = x >> w;
  y = y >> w;
  total = total >>w;
  int positiveOverflow = ~x & ~y & total; 
  int negativeOverflow = x&y&~total;
  int correct = ~(positiveOverflow|negativeOverflow);
  return (positiveOverflow & INT_MAX)|(correct & result)|(negativeOverflow & INT_MIN);
}

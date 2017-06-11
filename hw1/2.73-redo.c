//2.73 -redo 

int saturating_add(int x, int y){
  int w = sizeof(int) << 3 - 1;
  int result=x+y;
  int notoverflow = __builtin_add_overflow(x, y, &result); //return 0x0 if not overflowed
  notoverflow = ~!!notoverflow + 1;  //reverse, return 0xFFFFFFFF if not overflowed 
  notoverflow = ~notoverflow;
  return ((x+y) & notoverflow)|(((x>>31)^INT_MAX)&~notoverflow)|((x>>31)&INT_MIN&~notoverflow);
}

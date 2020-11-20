

// Create a function “func1” with 5 arguments and call “func1” from within another function “func2”

// fucntion declarations 
int func2(void);
int func1(int var0, int var1, int var2, int var3, int var4);

void main(void)
{
  int variable = func2();
  return;
}

// function sums five arguments and returns sum
int func1(int var0, int var1, int var2, int var3, int var4)
{
  int sum = var0 + var1 + var2 + var3 + var4;
  return sum;
}

// function calls func1 sum function, divides by 2 and returns value
int func2(void)
{
  int mvar1 = 1;
  int mvar2 = 1;
  int mvar3 = 1;
  int mvar4 = 1;
  int mvar5 = 1;
  int div5 = func1(mvar1, mvar2, mvar3, mvar4, mvar5)/5;
  return div5;
}
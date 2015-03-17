#include <stdio.h>
#define MEM_SIZE 100000
char Memory[MEM_SIZE];
int Frame_Pointer;
int Stack_Pointer;
int Temp;
double Temp_F;
int main() { 
Frame_Pointer=0;
Stack_Pointer=0;
Stack_Pointer += 12;
(*(int *)(&Memory[(Frame_Pointer + 0)])) = 3;
(*(double *)(&Memory[(Frame_Pointer + 4)])) = 5.000000;
(*(int *)(&Memory[(Stack_Pointer)])) = Frame_Pointer;
Stack_Pointer += 4;
*(int*)(&Memory[Stack_Pointer]) = 2;
Stack_Pointer += 4;
Frame_Pointer = Stack_Pointer - 0;
f1_6();
(*(double *)(&Memory[(Frame_Pointer + 4)])) = Temp_F;
Temp_F = (*(double *)(&Memory[(Frame_Pointer + 4)]));
printf("%6.4f\n", Temp_F);
(*(int *)(&Memory[(Stack_Pointer)])) = Frame_Pointer;
Stack_Pointer += 4;
*(int*)(&Memory[Stack_Pointer]) = (*(int *)(&Memory[(Frame_Pointer + 0)]));
Stack_Pointer += 4;
Frame_Pointer = Stack_Pointer - 0;
f2_8();
(*(int *)(&Memory[(Frame_Pointer + 0)])) = Temp;
Temp = (*(int *)(&Memory[(Frame_Pointer + 0)]));
printf("%d\n", Temp);
(*(int *)(&Memory[(Stack_Pointer)])) = Frame_Pointer;
Stack_Pointer += 4;
*(double*)(&Memory[Stack_Pointer]) = (*(double *)(&Memory[(Frame_Pointer + 4)]));
Stack_Pointer += 4;
Frame_Pointer = Stack_Pointer - 0;
f3_11();
(*(double *)(&Memory[(Frame_Pointer + 4)])) = Temp_F;
Temp_F = (*(double *)(&Memory[(Frame_Pointer + 4)]));
printf("%6.4f\n", Temp_F);
Stack_Pointer -= 12;
  return 0;
}
f1_6()
{
Temp_F = (*(int *)(&Memory[(Frame_Pointer + 0)]))*2.000000;
Stack_Pointer = Frame_Pointer;
Stack_Pointer -= 4;
Frame_Pointer = (*(int *)(&Memory[(Stack_Pointer)]));
}
f2_8()
{
Stack_Pointer += 4;
(*(int *)(&Memory[(Frame_Pointer + 4)])) = (*(int *)(&Memory[(Frame_Pointer + 0)]))*3;
Temp = (*(int *)(&Memory[(Frame_Pointer + 4)]));
Stack_Pointer = Frame_Pointer;
Stack_Pointer -= 4;
Frame_Pointer = (*(int *)(&Memory[(Stack_Pointer)]));
}
f3_11()
{
Stack_Pointer += 8;
(*(double *)(&Memory[(Frame_Pointer + 8)])) = (*(double *)(&Memory[(Frame_Pointer + 0)]))*2;
Temp_F = (*(double *)(&Memory[(Frame_Pointer + 8)]));
Stack_Pointer = Frame_Pointer;
Stack_Pointer -= 4;
Frame_Pointer = (*(int *)(&Memory[(Stack_Pointer)]));
}

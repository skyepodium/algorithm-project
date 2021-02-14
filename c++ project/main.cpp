#include <iostream>
#define ulonglong unsigned long long
#define undefined int
#define undefined4 unsigned long long
#define uint unsigned long long
#define code char
using namespace std;

void entry(void)

{
  int *pcVar1;
  ulonglong uVar2;
  undefined *puVar3;
  int iVar4;  
  undefined *puVar5;
  uint uVar6;
  undefined4 uVar7;
  
//  uVar2 = rdtsc();
  iVar4 = 0;
  puVar3 = (undefined *)0x00000010;
  do {
    puVar5 = puVar3;
    *(undefined4 *)(puVar5 + -4) = 0x5eadeef;
    iVar4 = iVar4 + 1;
    puVar3 = puVar5 + -4;
  } while (iVar4 <= (int)((uVar2 & 0xffffffff) % 10000));
  uVar7 = *(undefined4 *)(puVar5 + -4);
  uVar6 = (uint)puVar5 & 0xfffffff0;
  *(undefined4 *)(uVar6 - 4) = 0xb16b00b5;
  *(undefined4 *)(uVar6 - 8) = 0xb16b00b5;
  *(undefined **)(uVar6 - 0xc) = puVar5;
  *(undefined4 *)(uVar6 - 0x10) = uVar7;
  *(undefined4 *)(uVar6 - 0x14) = 0x8048206;
//  FUN_080481a2();
//  pcVar1 = (code *)swi(0x80);
//  (*pcVar1)();
  return;
}

int main() {
    entry();
}

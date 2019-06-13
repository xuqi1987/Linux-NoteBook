#include <stdio.h>

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef double u64;
#define P(str,arg) printf("%s : %lu字节\n", str,sizeof(arg))

// 数据成员对齐规则
// 结构体作为成员
// 结构体的总大小
typedef struct {
  u64 d; // 8 [0..7]
  u8 a; // 1 [8]
  u16 b; // 2 [9..10]
  u32 c; // 4 [11..14]
  //u64 d; // 8 [9..16]
}StruA; // 大小为8的整数倍 16

typedef struct {
  u64 d; // 8 [0..7]
  u8 a; // 1 [8]
  u64 b; // 8 [15..23]
  u8 a1; // 1 [24]
  u64 b1; // 8 [31..39]
}StruC; // 大小为8的整数倍 40

typedef struct {
  u64 d; // 8 [0..7]
  u64 b; // 8 [8..15]
  u8 a; // 1 [16]
  u8 a1; // 1 [17]
  u64 b1; // 8 [24..31]
}StruD; // 大小为8的整数倍 32

typedef struct {
    u8 a[5];
    u32 b; // 对齐原则，4的倍数
  //  void *p;
}StruE; // 12字节

typedef struct {
    u64 d; // 8 [0..7]
    u64 b; // 8 [8..15]
    u8 a; // 1 [16]
    u8 a1; // 1 [17]
    u64 b1; // 8 [24..31]
}StruF; // 12字节

typedef struct {
    u64 d; // 8 [0..7]
    StruE e; //12
}StruG; // 24字节

#pragma pack(push) //保存对齐状态
#pragma pack(8) // 设定为 4 字节对齐
typedef struct {
  u8 a; // 1
  u16 b; // 2
  u32 c; // 4
  u64 d; // 8
}StruB;
#pragma pack(pop) // 恢复对齐状态

void sizeofDemoPtr(u8 array[], int len)
{
  P("数组参数退化指针",array); // 当数组作为参数时，数组退化为指针
  // printf("%s\n",&array[1]);
}
void sizeofDemo()
{
  u8 array_u8[10]= "123456";  // 数组长度
  u8* pArray_u8 = "123456789"; // 指针长度8

  P("数组大小",array_u8);
  P("指针大小",pArray_u8);
  sizeofDemoPtr(array_u8,sizeof(array_u8));

  //P(u64);
  StruA A;
  //P(StruA);

  P("数据结构大小StruA",A); // 因为字节对齐，所以是8
  P("数据结构大小StruC",StruC);
  P("数据结构大小StruD",StruD);
  P("数据结构大小StruE",StruE);
  P("数据结构大小StruG",StruG);
  StruB B;
  P("对齐数组结构大小",B);


}

int main(int argc, char const *argv[]) {
  sizeofDemo();

  char a[] = {0xef,0xbb,0xbf,0x00};
  return 0;
}

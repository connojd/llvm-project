// RUN: %check_clang_tidy %s bsl-identifier-typographically-unambiguous %t

// -----------------------------------------------------------------------------
// Typography Rules
// -----------------------------------------------------------------------------

int var1_a_b_c;
int var1_abc;
// CHECK-MESSAGES: :[[@LINE-1]]:5: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

int var2_abc;
int var2_ABC;
// CHECK-MESSAGES: :[[@LINE-1]]:5: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

int var3_o;
int var3_0;
// CHECK-MESSAGES: :[[@LINE-1]]:5: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

int var4_O;
int var4_0;
// CHECK-MESSAGES: :[[@LINE-1]]:5: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

int var5_i;
int var5_1;
// CHECK-MESSAGES: :[[@LINE-1]]:5: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

int var6_I;
int var6_1;
// CHECK-MESSAGES: :[[@LINE-1]]:5: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

int var7_i;
int var7_l;
// CHECK-MESSAGES: :[[@LINE-1]]:5: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

int var8_I;
int var8_l;
// CHECK-MESSAGES: :[[@LINE-1]]:5: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

int var9_i;
int var9_L;
// CHECK-MESSAGES: :[[@LINE-1]]:5: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

int var10_I;
int var10_L;
// CHECK-MESSAGES: :[[@LINE-1]]:5: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

int var11_s;
int var11_5;
// CHECK-MESSAGES: :[[@LINE-1]]:5: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

int var12_S;
int var12_5;
// CHECK-MESSAGES: :[[@LINE-1]]:5: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

int var13_z;
int var13_2;
// CHECK-MESSAGES: :[[@LINE-1]]:5: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

int var14_Z;
int var14_2;
// CHECK-MESSAGES: :[[@LINE-1]]:5: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

int var15_n;
int var15_h;
// CHECK-MESSAGES: :[[@LINE-1]]:5: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

int var16_N;
int var16_h;
// CHECK-MESSAGES: :[[@LINE-1]]:5: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

int var17_n;
int var17_H;
// CHECK-MESSAGES: :[[@LINE-1]]:5: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

int var18_N;
int var18_H;
// CHECK-MESSAGES: :[[@LINE-1]]:5: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

int var19_b;
int var19_8;
// CHECK-MESSAGES: :[[@LINE-1]]:5: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

int var20_B;
int var20_8;
// CHECK-MESSAGES: :[[@LINE-1]]:5: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

int var19_m;
int var19_rn;
// CHECK-MESSAGES: :[[@LINE-1]]:5: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

int var20_M;
int var20_rn;
// CHECK-MESSAGES: :[[@LINE-1]]:5: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

int var21_m;
int var21_Rn;
// CHECK-MESSAGES: :[[@LINE-1]]:5: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

int var22_M;
int var22_Rn;
// CHECK-MESSAGES: :[[@LINE-1]]:5: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

int var23_m;
int var23_rN;
// CHECK-MESSAGES: :[[@LINE-1]]:5: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

int var24_M;
int var24_rN;
// CHECK-MESSAGES: :[[@LINE-1]]:5: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

int var25_m;
int var25_RN;
// CHECK-MESSAGES: :[[@LINE-1]]:5: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

int var26_M;
int var26_RN;
// CHECK-MESSAGES: :[[@LINE-1]]:5: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

void function1_a_b_c(){}
void function1_abc(){}
// CHECK-MESSAGES: :[[@LINE-1]]:6: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

void function2_abc(){}
void function2_ABC(){}
// CHECK-MESSAGES: :[[@LINE-1]]:6: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

void function3_o(){}
void function3_0(){}
// CHECK-MESSAGES: :[[@LINE-1]]:6: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

void function4_O(){}
void function4_0(){}
// CHECK-MESSAGES: :[[@LINE-1]]:6: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

void function5_i(){}
void function5_1(){}
// CHECK-MESSAGES: :[[@LINE-1]]:6: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

void function6_I(){}
void function6_1(){}
// CHECK-MESSAGES: :[[@LINE-1]]:6: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

void function7_i(){}
void function7_l(){}
// CHECK-MESSAGES: :[[@LINE-1]]:6: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

void function8_I(){}
void function8_l(){}
// CHECK-MESSAGES: :[[@LINE-1]]:6: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

void function9_i(){}
void function9_L(){}
// CHECK-MESSAGES: :[[@LINE-1]]:6: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

void function10_I(){}
void function10_L(){}
// CHECK-MESSAGES: :[[@LINE-1]]:6: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

void function11_s(){}
void function11_5(){}
// CHECK-MESSAGES: :[[@LINE-1]]:6: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

void function12_S(){}
void function12_5(){}
// CHECK-MESSAGES: :[[@LINE-1]]:6: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

void function13_z(){}
void function13_2(){}
// CHECK-MESSAGES: :[[@LINE-1]]:6: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

void function14_Z(){}
void function14_2(){}
// CHECK-MESSAGES: :[[@LINE-1]]:6: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

void function15_n(){}
void function15_h(){}
// CHECK-MESSAGES: :[[@LINE-1]]:6: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

void function16_N(){}
void function16_h(){}
// CHECK-MESSAGES: :[[@LINE-1]]:6: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

void function17_n(){}
void function17_H(){}
// CHECK-MESSAGES: :[[@LINE-1]]:6: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

void function18_N(){}
void function18_H(){}
// CHECK-MESSAGES: :[[@LINE-1]]:6: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

void function19_b(){}
void function19_8(){}
// CHECK-MESSAGES: :[[@LINE-1]]:6: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

void function20_B(){}
void function20_8(){}
// CHECK-MESSAGES: :[[@LINE-1]]:6: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

void function19_m(){}
void function19_rn(){}
// CHECK-MESSAGES: :[[@LINE-1]]:6: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

void function20_M(){}
void function20_rn(){}
// CHECK-MESSAGES: :[[@LINE-1]]:6: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

void function21_m(){}
void function21_Rn(){}
// CHECK-MESSAGES: :[[@LINE-1]]:6: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

void function22_M(){}
void function22_Rn(){}
// CHECK-MESSAGES: :[[@LINE-1]]:6: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

void function23_m(){}
void function23_rN(){}
// CHECK-MESSAGES: :[[@LINE-1]]:6: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

void function24_M(){}
void function24_rN(){}
// CHECK-MESSAGES: :[[@LINE-1]]:6: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

void function25_m(){}
void function25_RN(){}
// CHECK-MESSAGES: :[[@LINE-1]]:6: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

void function26_M(){}
void function26_RN(){}
// CHECK-MESSAGES: :[[@LINE-1]]:6: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

using alias1_a_b_c = int;
using alias1_abc = int;
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

using alias2_abc = int;
using alias2_ABC = int;
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

using alias3_o = int;
using alias3_0 = int;
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

using alias4_O = int;
using alias4_0 = int;
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

using alias5_i = int;
using alias5_1 = int;
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

using alias6_I = int;
using alias6_1 = int;
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

using alias7_i = int;
using alias7_l = int;
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

using alias8_I = int;
using alias8_l = int;
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

using alias9_i = int;
using alias9_L = int;
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

using alias10_I = int;
using alias10_L = int;
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

using alias11_s = int;
using alias11_5 = int;
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

using alias12_S = int;
using alias12_5 = int;
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

using alias13_z = int;
using alias13_2 = int;
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

using alias14_Z = int;
using alias14_2 = int;
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

using alias15_n = int;
using alias15_h = int;
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

using alias16_N = int;
using alias16_h = int;
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

using alias17_n = int;
using alias17_H = int;
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

using alias18_N = int;
using alias18_H = int;
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

using alias19_b = int;
using alias19_8 = int;
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

using alias20_B = int;
using alias20_8 = int;
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

using alias19_m = int;
using alias19_rn = int;
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

using alias20_M = int;
using alias20_rn = int;
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

using alias21_m = int;
using alias21_Rn = int;
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

using alias22_M = int;
using alias22_Rn = int;
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

using alias23_m = int;
using alias23_rN = int;
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

using alias24_M = int;
using alias24_rN = int;
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

using alias25_m = int;
using alias25_RN = int;
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

using alias26_M = int;
using alias26_RN = int;
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

enum enum1_a_b_c{};
enum enum1_abc{};
// CHECK-MESSAGES: :[[@LINE-1]]:6: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

enum enum2_abc{};
enum enum2_ABC{};
// CHECK-MESSAGES: :[[@LINE-1]]:6: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

enum enum3_o{};
enum enum3_0{};
// CHECK-MESSAGES: :[[@LINE-1]]:6: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

enum enum4_O{};
enum enum4_0{};
// CHECK-MESSAGES: :[[@LINE-1]]:6: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

enum enum5_i{};
enum enum5_1{};
// CHECK-MESSAGES: :[[@LINE-1]]:6: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

enum enum6_I{};
enum enum6_1{};
// CHECK-MESSAGES: :[[@LINE-1]]:6: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

enum enum7_i{};
enum enum7_l{};
// CHECK-MESSAGES: :[[@LINE-1]]:6: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

enum enum8_I{};
enum enum8_l{};
// CHECK-MESSAGES: :[[@LINE-1]]:6: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

enum enum9_i{};
enum enum9_L{};
// CHECK-MESSAGES: :[[@LINE-1]]:6: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

enum enum10_I{};
enum enum10_L{};
// CHECK-MESSAGES: :[[@LINE-1]]:6: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

enum enum11_s{};
enum enum11_5{};
// CHECK-MESSAGES: :[[@LINE-1]]:6: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

enum enum12_S{};
enum enum12_5{};
// CHECK-MESSAGES: :[[@LINE-1]]:6: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

enum enum13_z{};
enum enum13_2{};
// CHECK-MESSAGES: :[[@LINE-1]]:6: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

enum enum14_Z{};
enum enum14_2{};
// CHECK-MESSAGES: :[[@LINE-1]]:6: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

enum enum15_n{};
enum enum15_h{};
// CHECK-MESSAGES: :[[@LINE-1]]:6: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

enum enum16_N{};
enum enum16_h{};
// CHECK-MESSAGES: :[[@LINE-1]]:6: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

enum enum17_n{};
enum enum17_H{};
// CHECK-MESSAGES: :[[@LINE-1]]:6: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

enum enum18_N{};
enum enum18_H{};
// CHECK-MESSAGES: :[[@LINE-1]]:6: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

enum enum19_b{};
enum enum19_8{};
// CHECK-MESSAGES: :[[@LINE-1]]:6: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

enum enum20_B{};
enum enum20_8{};
// CHECK-MESSAGES: :[[@LINE-1]]:6: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

enum enum19_m{};
enum enum19_rn{};
// CHECK-MESSAGES: :[[@LINE-1]]:6: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

enum enum20_M{};
enum enum20_rn{};
// CHECK-MESSAGES: :[[@LINE-1]]:6: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

enum enum21_m{};
enum enum21_Rn{};
// CHECK-MESSAGES: :[[@LINE-1]]:6: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

enum enum22_M{};
enum enum22_Rn{};
// CHECK-MESSAGES: :[[@LINE-1]]:6: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

enum enum23_m{};
enum enum23_rN{};
// CHECK-MESSAGES: :[[@LINE-1]]:6: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

enum enum24_M{};
enum enum24_rN{};
// CHECK-MESSAGES: :[[@LINE-1]]:6: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

enum enum25_m{};
enum enum25_RN{};
// CHECK-MESSAGES: :[[@LINE-1]]:6: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

enum enum26_M{};
enum enum26_RN{};
// CHECK-MESSAGES: :[[@LINE-1]]:6: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

class class1_a_b_c{};
class class1_abc{};
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

class class2_abc{};
class class2_ABC{};
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

class class3_o{};
class class3_0{};
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

class class4_O{};
class class4_0{};
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

class class5_i{};
class class5_1{};
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

class class6_I{};
class class6_1{};
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

class class7_i{};
class class7_l{};
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

class class8_I{};
class class8_l{};
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

class class9_i{};
class class9_L{};
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

class class10_I{};
class class10_L{};
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

class class11_s{};
class class11_5{};
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

class class12_S{};
class class12_5{};
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

class class13_z{};
class class13_2{};
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

class class14_Z{};
class class14_2{};
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

class class15_n{};
class class15_h{};
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

class class16_N{};
class class16_h{};
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

class class17_n{};
class class17_H{};
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

class class18_N{};
class class18_H{};
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

class class19_b{};
class class19_8{};
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

class class20_B{};
class class20_8{};
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

class class19_m{};
class class19_rn{};
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

class class20_M{};
class class20_rn{};
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

class class21_m{};
class class21_Rn{};
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

class class22_M{};
class class22_Rn{};
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

class class23_m{};
class class23_rN{};
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

class class24_M{};
class class24_rN{};
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

class class25_m{};
class class25_RN{};
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

class class26_M{};
class class26_RN{};
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

struct struct1_a_b_c{};
struct struct1_abc{};
// CHECK-MESSAGES: :[[@LINE-1]]:8: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

struct struct2_abc{};
struct struct2_ABC{};
// CHECK-MESSAGES: :[[@LINE-1]]:8: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

struct struct3_o{};
struct struct3_0{};
// CHECK-MESSAGES: :[[@LINE-1]]:8: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

struct struct4_O{};
struct struct4_0{};
// CHECK-MESSAGES: :[[@LINE-1]]:8: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

struct struct5_i{};
struct struct5_1{};
// CHECK-MESSAGES: :[[@LINE-1]]:8: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

struct struct6_I{};
struct struct6_1{};
// CHECK-MESSAGES: :[[@LINE-1]]:8: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

struct struct7_i{};
struct struct7_l{};
// CHECK-MESSAGES: :[[@LINE-1]]:8: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

struct struct8_I{};
struct struct8_l{};
// CHECK-MESSAGES: :[[@LINE-1]]:8: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

struct struct9_i{};
struct struct9_L{};
// CHECK-MESSAGES: :[[@LINE-1]]:8: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

struct struct10_I{};
struct struct10_L{};
// CHECK-MESSAGES: :[[@LINE-1]]:8: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

struct struct11_s{};
struct struct11_5{};
// CHECK-MESSAGES: :[[@LINE-1]]:8: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

struct struct12_S{};
struct struct12_5{};
// CHECK-MESSAGES: :[[@LINE-1]]:8: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

struct struct13_z{};
struct struct13_2{};
// CHECK-MESSAGES: :[[@LINE-1]]:8: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

struct struct14_Z{};
struct struct14_2{};
// CHECK-MESSAGES: :[[@LINE-1]]:8: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

struct struct15_n{};
struct struct15_h{};
// CHECK-MESSAGES: :[[@LINE-1]]:8: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

struct struct16_N{};
struct struct16_h{};
// CHECK-MESSAGES: :[[@LINE-1]]:8: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

struct struct17_n{};
struct struct17_H{};
// CHECK-MESSAGES: :[[@LINE-1]]:8: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

struct struct18_N{};
struct struct18_H{};
// CHECK-MESSAGES: :[[@LINE-1]]:8: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

struct struct19_b{};
struct struct19_8{};
// CHECK-MESSAGES: :[[@LINE-1]]:8: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

struct struct20_B{};
struct struct20_8{};
// CHECK-MESSAGES: :[[@LINE-1]]:8: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

struct struct19_m{};
struct struct19_rn{};
// CHECK-MESSAGES: :[[@LINE-1]]:8: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

struct struct20_M{};
struct struct20_rn{};
// CHECK-MESSAGES: :[[@LINE-1]]:8: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

struct struct21_m{};
struct struct21_Rn{};
// CHECK-MESSAGES: :[[@LINE-1]]:8: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

struct struct22_M{};
struct struct22_Rn{};
// CHECK-MESSAGES: :[[@LINE-1]]:8: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

struct struct23_m{};
struct struct23_rN{};
// CHECK-MESSAGES: :[[@LINE-1]]:8: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

struct struct24_M{};
struct struct24_rN{};
// CHECK-MESSAGES: :[[@LINE-1]]:8: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

struct struct25_m{};
struct struct25_RN{};
// CHECK-MESSAGES: :[[@LINE-1]]:8: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

struct struct26_M{};
struct struct26_RN{};
// CHECK-MESSAGES: :[[@LINE-1]]:8: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

union union1_a_b_c{};
union union1_abc{};
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

union union2_abc{};
union union2_ABC{};
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

union union3_o{};
union union3_0{};
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

union union4_O{};
union union4_0{};
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

union union5_i{};
union union5_1{};
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

union union6_I{};
union union6_1{};
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

union union7_i{};
union union7_l{};
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

union union8_I{};
union union8_l{};
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

union union9_i{};
union union9_L{};
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

union union10_I{};
union union10_L{};
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

union union11_s{};
union union11_5{};
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

union union12_S{};
union union12_5{};
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

union union13_z{};
union union13_2{};
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

union union14_Z{};
union union14_2{};
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

union union15_n{};
union union15_h{};
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

union union16_N{};
union union16_h{};
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

union union17_n{};
union union17_H{};
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

union union18_N{};
union union18_H{};
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

union union19_b{};
union union19_8{};
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

union union20_B{};
union union20_8{};
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

union union19_m{};
union union19_rn{};
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

union union20_M{};
union union20_rn{};
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

union union21_m{};
union union21_Rn{};
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

union union22_M{};
union union22_Rn{};
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

union union23_m{};
union union23_rN{};
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

union union24_M{};
union union24_rN{};
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

union union25_m{};
union union25_RN{};
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

union union26_M{};
union union26_RN{};
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

// -----------------------------------------------------------------------------
// Global, Namespace, Function, Class Tests
// -----------------------------------------------------------------------------

int globalVar;
void globalFunction(){}
using globalAlias = int;
enum globalEnum{};
class globalClass{};
struct globalStruct{};
union globalUnion{};

namespace n1
{
    int namespaceVar;
    void namespaceFunction(){}
    using namespaceAlias = int;
    enum namespaceEnum{};
    class namespaceClass{};
    struct namespaceStruct{};
    union namespaceUnion{};
}

namespace n2
{
    int namespace_var;
    void namespace_function(){}
    using namespace_alias = int;
    enum namespace_enum{};
    class namespace_class{};
    struct namespace_struct{};
    union namespace_union{};

    int global_var;
    // CHECK-MESSAGES: :[[@LINE-1]]:9: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    int global_function;
    // CHECK-MESSAGES: :[[@LINE-1]]:9: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    int global_alias;
    // CHECK-MESSAGES: :[[@LINE-1]]:9: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    int global_enum;
    // CHECK-MESSAGES: :[[@LINE-1]]:9: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    int global_class;
    // CHECK-MESSAGES: :[[@LINE-1]]:9: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    int global_struct;
    // CHECK-MESSAGES: :[[@LINE-1]]:9: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    int global_union;
    // CHECK-MESSAGES: :[[@LINE-1]]:9: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

}

class classWithFunctionLocalVariablesNamedSimilarToGlobalsInNamespace
{
public:
    void local_function()
    {
        int namespace_var;
        int namespace_function;
        int namespace_alias;
        int namespace_enum;
        int namespace_class;
        int namespace_struct;
        int namespace_union;
    }
};

class classWithFunctionLocalAliasesNamedSimilarToGlobalsInNamespace
{
public:
    void local_function()
    {
        using namespace_var = int;
        using namespace_function = int;
        using namespace_alias = int;
        using namespace_enum = int;
        using namespace_class = int;
        using namespace_struct = int;
        using namespace_union = int;
    }
};

void functionWithVariablesNamedSimilarToGlobals1()
{
    int localVar1;
}

void functionWithVariablesNamedSimilarToGlobals2()
{
    int localVar1;
    int localVar2;

    int local_var2;
    // CHECK-MESSAGES: :[[@LINE-1]]:9: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    int global_var;
    // CHECK-MESSAGES: :[[@LINE-1]]:9: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    int global_function;
    // CHECK-MESSAGES: :[[@LINE-1]]:9: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    int global_alias;
    // CHECK-MESSAGES: :[[@LINE-1]]:9: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    int global_enum;
    // CHECK-MESSAGES: :[[@LINE-1]]:9: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    int global_class;
    // CHECK-MESSAGES: :[[@LINE-1]]:9: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    int global_struct;
    // CHECK-MESSAGES: :[[@LINE-1]]:9: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    int global_union;
    // CHECK-MESSAGES: :[[@LINE-1]]:9: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
}

void functionWithAliasesNamedSimilarToGlobals1()
{
    using localVar1 = int;
}

void functionWithAliasesNamedSimilarToGlobals2()
{
    using localVar1 = int;
    using localVar2 = int;

    using local_var2 = int;
    // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    using global_var = int;
    // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    using global_function = int;
    // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    using global_alias = int;
    // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    using global_enum = int;
    // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    using global_class = int;
    // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    using global_struct = int;
    // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    using global_union = int;
    // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    using global_union = int;
    // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
}

class classWithFunctionLocalVariablesNamedSimilarToGlobals1
{
public:
    int memberVar;
    void memberFunction(){}
    using memberAlias = int;
    enum memberEnum{};
    class memberClass{};
    struct memberStruct{};
    union memberUnion{};

    void local_function()
    {
        int localVar1;
    }
};

class classWithFunctionLocalVariablesNamedSimilarToGlobals2
{
public:
    int memberVar;
    void memberFunction(){}
    using memberAlias = int;
    enum memberEnum{};
    class memberClass{};
    struct memberStruct{};
    union memberUnion{};

    void local_function1()
    {
        int localVar1;
        int localVar2;

        int local_var2;
        // CHECK-MESSAGES: :[[@LINE-1]]:13: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

        int member_var;
        // CHECK-MESSAGES: :[[@LINE-1]]:13: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
        int member_function;
        // CHECK-MESSAGES: :[[@LINE-1]]:13: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
        int member_alias;
        // CHECK-MESSAGES: :[[@LINE-1]]:13: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
        int member_enum;
        // CHECK-MESSAGES: :[[@LINE-1]]:13: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
        int member_class;
        // CHECK-MESSAGES: :[[@LINE-1]]:13: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
        int member_struct;
        // CHECK-MESSAGES: :[[@LINE-1]]:13: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
        int member_union;
        // CHECK-MESSAGES: :[[@LINE-1]]:13: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

        int global_var;
        // CHECK-MESSAGES: :[[@LINE-1]]:13: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
        int global_function;
        // CHECK-MESSAGES: :[[@LINE-1]]:13: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
        int global_alias;
        // CHECK-MESSAGES: :[[@LINE-1]]:13: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
        int global_enum;
        // CHECK-MESSAGES: :[[@LINE-1]]:13: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
        int global_class;
        // CHECK-MESSAGES: :[[@LINE-1]]:13: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
        int global_struct;
        // CHECK-MESSAGES: :[[@LINE-1]]:13: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
        int global_union;
        // CHECK-MESSAGES: :[[@LINE-1]]:13: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    }

    void local_function2()
    {
        int localVar1;
        int localVar2;

        int local_var2;
        // CHECK-MESSAGES: :[[@LINE-1]]:13: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

        int member_var;
        // CHECK-MESSAGES: :[[@LINE-1]]:13: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
        int member_function;
        // CHECK-MESSAGES: :[[@LINE-1]]:13: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
        int member_alias;
        // CHECK-MESSAGES: :[[@LINE-1]]:13: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
        int member_enum;
        // CHECK-MESSAGES: :[[@LINE-1]]:13: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
        int member_class;
        // CHECK-MESSAGES: :[[@LINE-1]]:13: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
        int member_struct;
        // CHECK-MESSAGES: :[[@LINE-1]]:13: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
        int member_union;
        // CHECK-MESSAGES: :[[@LINE-1]]:13: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

        int global_var;
        // CHECK-MESSAGES: :[[@LINE-1]]:13: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
        int global_function;
        // CHECK-MESSAGES: :[[@LINE-1]]:13: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
        int global_alias;
        // CHECK-MESSAGES: :[[@LINE-1]]:13: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
        int global_enum;
        // CHECK-MESSAGES: :[[@LINE-1]]:13: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
        int global_class;
        // CHECK-MESSAGES: :[[@LINE-1]]:13: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
        int global_struct;
        // CHECK-MESSAGES: :[[@LINE-1]]:13: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
        int global_union;
        // CHECK-MESSAGES: :[[@LINE-1]]:13: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    }
};

class classWithFunctionLocalAliasesNamedSimilarToGlobals1
{
public:
    int memberVar;
    void memberFunction(){}
    using memberAlias = int;
    enum memberEnum{};
    class memberClass{};
    struct memberStruct{};
    union memberUnion{};

    void local_function()
    {
        using localAlias1 = int;
    }
};

class classWithFunctionLocalAliasesNamedSimilarToGlobals2
{
public:
    int memberVar;
    void memberFunction(){}
    using memberAlias = int;
    enum memberEnum{};
    class memberClass{};
    struct memberStruct{};
    union memberUnion{};

    void local_function1()
    {
        using localAlias1 = int;
        using localAlias2 = int;

        using local_alias2 = int;
        // CHECK-MESSAGES: :[[@LINE-1]]:15: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

        using member_var = int;
        // CHECK-MESSAGES: :[[@LINE-1]]:15: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
        using member_function = int;
        // CHECK-MESSAGES: :[[@LINE-1]]:15: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
        using member_alias = int;
        // CHECK-MESSAGES: :[[@LINE-1]]:15: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
        using member_enum = int;
        // CHECK-MESSAGES: :[[@LINE-1]]:15: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
        using member_class = int;
        // CHECK-MESSAGES: :[[@LINE-1]]:15: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
        using member_struct = int;
        // CHECK-MESSAGES: :[[@LINE-1]]:15: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
        using member_union = int;
        // CHECK-MESSAGES: :[[@LINE-1]]:15: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

        using global_var = int;
        // CHECK-MESSAGES: :[[@LINE-1]]:15: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
        using global_function = int;
        // CHECK-MESSAGES: :[[@LINE-1]]:15: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
        using global_alias = int;
        // CHECK-MESSAGES: :[[@LINE-1]]:15: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
        using global_enum = int;
        // CHECK-MESSAGES: :[[@LINE-1]]:15: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
        using global_class = int;
        // CHECK-MESSAGES: :[[@LINE-1]]:15: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
        using global_struct = int;
        // CHECK-MESSAGES: :[[@LINE-1]]:15: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
        using global_union = int;
        // CHECK-MESSAGES: :[[@LINE-1]]:15: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    }

    void local_function2()
    {
        using localAlias1 = int;
        using localAlias2 = int;

        using local_alias2 = int;
        // CHECK-MESSAGES: :[[@LINE-1]]:15: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

        using member_var = int;
        // CHECK-MESSAGES: :[[@LINE-1]]:15: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
        using member_function = int;
        // CHECK-MESSAGES: :[[@LINE-1]]:15: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
        using member_alias = int;
        // CHECK-MESSAGES: :[[@LINE-1]]:15: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
        using member_enum = int;
        // CHECK-MESSAGES: :[[@LINE-1]]:15: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
        using member_class = int;
        // CHECK-MESSAGES: :[[@LINE-1]]:15: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
        using member_struct = int;
        // CHECK-MESSAGES: :[[@LINE-1]]:15: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
        using member_union = int;
        // CHECK-MESSAGES: :[[@LINE-1]]:15: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

        using global_var = int;
        // CHECK-MESSAGES: :[[@LINE-1]]:15: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
        using global_function = int;
        // CHECK-MESSAGES: :[[@LINE-1]]:15: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
        using global_alias = int;
        // CHECK-MESSAGES: :[[@LINE-1]]:15: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
        using global_enum = int;
        // CHECK-MESSAGES: :[[@LINE-1]]:15: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
        using global_class = int;
        // CHECK-MESSAGES: :[[@LINE-1]]:15: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
        using global_struct = int;
        // CHECK-MESSAGES: :[[@LINE-1]]:15: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
        using global_union = int;
        // CHECK-MESSAGES: :[[@LINE-1]]:15: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    }
};

class classWithFieldsNamedSimilarToGlobals1
{
public:
    int memberVar;
    void memberFunction(){}
    using memberAlias = int;
    enum memberEnum{};
    class memberClass{};
    struct memberStruct{};
    union memberUnion{};
};

class classWithFieldsNamedSimilarToGlobals2
{
public:
    int memberVar;
    void memberFunction(){}
    using memberAlias = int;
    enum memberEnum{};
    class memberClass{};
    struct memberStruct{};
    union memberUnion{};

    int member_var;
    // CHECK-MESSAGES: :[[@LINE-1]]:9: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    int member_function;
    // CHECK-MESSAGES: :[[@LINE-1]]:9: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    int member_alias;
    // CHECK-MESSAGES: :[[@LINE-1]]:9: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    int member_enum;
    // CHECK-MESSAGES: :[[@LINE-1]]:9: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    int member_class;
    // CHECK-MESSAGES: :[[@LINE-1]]:9: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    int member_struct;
    // CHECK-MESSAGES: :[[@LINE-1]]:9: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    int member_union;
    // CHECK-MESSAGES: :[[@LINE-1]]:9: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

    int global_var;
    // CHECK-MESSAGES: :[[@LINE-1]]:9: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    int global_function;
    // CHECK-MESSAGES: :[[@LINE-1]]:9: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    int global_alias;
    // CHECK-MESSAGES: :[[@LINE-1]]:9: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    int global_enum;
    // CHECK-MESSAGES: :[[@LINE-1]]:9: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    int global_class;
    // CHECK-MESSAGES: :[[@LINE-1]]:9: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    int global_struct;
    // CHECK-MESSAGES: :[[@LINE-1]]:9: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    int global_union;
    // CHECK-MESSAGES: :[[@LINE-1]]:9: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
};

class classWithFunctionsNamedSimilarToGlobals1
{
public:
    int memberVar;
    void memberFunction(){}
    using memberAlias = int;
    enum memberEnum{};
    class memberClass{};
    struct memberStruct{};
    union memberUnion{};
};

class classWithFunctionsNamedSimilarToGlobals2
{
public:
    int memberVar;
    void memberFunction(){}
    using memberAlias = int;
    enum memberEnum{};
    class memberClass{};
    struct memberStruct{};
    union memberUnion{};

    void member_var(){}
    // CHECK-MESSAGES: :[[@LINE-1]]:10: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    void member_function(){}
    // CHECK-MESSAGES: :[[@LINE-1]]:10: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    void member_alias(){}
    // CHECK-MESSAGES: :[[@LINE-1]]:10: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    void member_enum(){}
    // CHECK-MESSAGES: :[[@LINE-1]]:10: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    void member_class(){}
    // CHECK-MESSAGES: :[[@LINE-1]]:10: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    void member_struct(){}
    // CHECK-MESSAGES: :[[@LINE-1]]:10: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    void member_union(){}
    // CHECK-MESSAGES: :[[@LINE-1]]:10: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

    void global_var(){}
    // CHECK-MESSAGES: :[[@LINE-1]]:10: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    void global_function(){}
    // CHECK-MESSAGES: :[[@LINE-1]]:10: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    void global_alias(){}
    // CHECK-MESSAGES: :[[@LINE-1]]:10: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    void global_enum(){}
    // CHECK-MESSAGES: :[[@LINE-1]]:10: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    void global_class(){}
    // CHECK-MESSAGES: :[[@LINE-1]]:10: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    void global_struct(){}
    // CHECK-MESSAGES: :[[@LINE-1]]:10: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    void global_union(){}
    // CHECK-MESSAGES: :[[@LINE-1]]:10: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
};

class classWithAliasesNamedSimilarToGlobals1
{
public:
    int memberVar;
    void memberFunction(){}
    using memberAlias = int;
    enum memberEnum{};
    class memberClass{};
    struct memberStruct{};
    union memberUnion{};
};

class classWithAliasesNamedSimilarToGlobals2
{
public:
    int memberVar;
    void memberFunction(){}
    using memberAlias = int;
    enum memberEnum{};
    class memberClass{};
    struct memberStruct{};
    union memberUnion{};

    using member_var = int;
    // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    using member_function = int;
    // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    using member_alias = int;
    // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    using member_enum = int;
    // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    using member_class = int;
    // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    using member_struct = int;
    // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    using member_union = int;
    // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

    using global_var = int;
    // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    using global_function = int;
    // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    using global_alias = int;
    // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    using global_enum = int;
    // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    using global_class = int;
    // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    using global_struct = int;
    // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    using global_union = int;
    // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
};

class classWithEnumsNamedSimilarToGlobals1
{
public:
    int memberVar;
    void memberFunction(){}
    using memberAlias = int;
    enum memberEnum{};
    class memberClass{};
    struct memberStruct{};
    union memberUnion{};
};

class classWithEnumsNamedSimilarToGlobals2
{
public:
    int memberVar;
    void memberFunction(){}
    using memberAlias = int;
    enum memberEnum{};
    class memberClass{};
    struct memberStruct{};
    union memberUnion{};

    enum member_var{};
    // CHECK-MESSAGES: :[[@LINE-1]]:10: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    enum member_function{};
    // CHECK-MESSAGES: :[[@LINE-1]]:10: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    enum member_alias{};
    // CHECK-MESSAGES: :[[@LINE-1]]:10: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    enum member_enum{};
    // CHECK-MESSAGES: :[[@LINE-1]]:10: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    enum member_class{};
    // CHECK-MESSAGES: :[[@LINE-1]]:10: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    enum member_struct{};
    // CHECK-MESSAGES: :[[@LINE-1]]:10: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    enum member_union{};
    // CHECK-MESSAGES: :[[@LINE-1]]:10: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

    enum global_var{};
    // CHECK-MESSAGES: :[[@LINE-1]]:10: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    enum global_function{};
    // CHECK-MESSAGES: :[[@LINE-1]]:10: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    enum global_alias{};
    // CHECK-MESSAGES: :[[@LINE-1]]:10: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    enum global_enum{};
    // CHECK-MESSAGES: :[[@LINE-1]]:10: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    enum global_class{};
    // CHECK-MESSAGES: :[[@LINE-1]]:10: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    enum global_struct{};
    // CHECK-MESSAGES: :[[@LINE-1]]:10: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    enum global_union{};
    // CHECK-MESSAGES: :[[@LINE-1]]:10: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
};

class classWithClassesNamedSimilarToGlobals1
{
public:
    int memberVar;
    void memberFunction(){}
    using memberAlias = int;
    enum memberEnum{};
    class memberClass{};
    struct memberStruct{};
    union memberUnion{};
};

class classWithClassesNamedSimilarToGlobals2
{
public:
    int memberVar;
    void memberFunction(){}
    using memberAlias = int;
    enum memberEnum{};
    class memberClass{};
    struct memberStruct{};
    union memberUnion{};

    class member_var{};
    // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    class member_function{};
    // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    class member_alias{};
    // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    class member_enum{};
    // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    class member_class{};
    // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    class member_struct{};
    // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    class member_union{};
    // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

    class global_var{};
    // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    class global_function{};
    // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    class global_alias{};
    // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    class global_enum{};
    // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    class global_class{};
    // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    class global_struct{};
    // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    class global_union{};
    // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
};

class classWithStructsNamedSimilarToGlobals1
{
public:
    int memberVar;
    void memberFunction(){}
    using memberAlias = int;
    enum memberEnum{};
    class memberClass{};
    struct memberStruct{};
    union memberUnion{};
};

class classWithStructsNamedSimilarToGlobals2
{
public:
    int memberVar;
    void memberFunction(){}
    using memberAlias = int;
    enum memberEnum{};
    class memberClass{};
    struct memberStruct{};
    union memberUnion{};

    struct member_var{};
    // CHECK-MESSAGES: :[[@LINE-1]]:12: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    struct member_function{};
    // CHECK-MESSAGES: :[[@LINE-1]]:12: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    struct member_alias{};
    // CHECK-MESSAGES: :[[@LINE-1]]:12: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    struct member_enum{};
    // CHECK-MESSAGES: :[[@LINE-1]]:12: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    struct member_class{};
    // CHECK-MESSAGES: :[[@LINE-1]]:12: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    struct member_struct{};
    // CHECK-MESSAGES: :[[@LINE-1]]:12: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    struct member_union{};
    // CHECK-MESSAGES: :[[@LINE-1]]:12: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

    struct global_var{};
    // CHECK-MESSAGES: :[[@LINE-1]]:12: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    struct global_function{};
    // CHECK-MESSAGES: :[[@LINE-1]]:12: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    struct global_alias{};
    // CHECK-MESSAGES: :[[@LINE-1]]:12: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    struct global_enum{};
    // CHECK-MESSAGES: :[[@LINE-1]]:12: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    struct global_class{};
    // CHECK-MESSAGES: :[[@LINE-1]]:12: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    struct global_struct{};
    // CHECK-MESSAGES: :[[@LINE-1]]:12: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    struct global_union{};
    // CHECK-MESSAGES: :[[@LINE-1]]:12: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
};

class classWithUnionsNamedSimilarToGlobals1
{
public:
    int memberVar;
    void memberFunction(){}
    using memberAlias = int;
    enum memberEnum{};
    class memberClass{};
    struct memberStruct{};
    union memberUnion{};
};

class classWithUnionsNamedSimilarToGlobals2
{
public:
    int memberVar;
    void memberFunction(){}
    using memberAlias = int;
    enum memberEnum{};
    class memberClass{};
    struct memberStruct{};
    union memberUnion{};

    union member_var{};
    // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    union member_function{};
    // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    union member_alias{};
    // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    union member_enum{};
    // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    union member_class{};
    // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    union member_struct{};
    // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    union member_union{};
    // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

    union global_var{};
    // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    union global_function{};
    // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    union global_alias{};
    // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    union global_enum{};
    // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    union global_class{};
    // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    union global_struct{};
    // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    union global_union{};
    // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
};

// -----------------------------------------------------------------------------
// Prototype Tests
// -----------------------------------------------------------------------------

void testFunctionPrototype();
void testFunctionPrototype()
{}

class testClassPrototype;
class testClassPrototype
{};

struct testStructPrototype;
struct testStructPrototype
{};

// -----------------------------------------------------------------------------
// Overloads
// -----------------------------------------------------------------------------

void functionOverloads(){}
void functionOverloads(int var1){}
void functionOverloads(int var1, int var2){}

class classWithMultipleConstructors
{
public:
    classWithMultipleConstructors(){}
    classWithMultipleConstructors(int var1){}
    classWithMultipleConstructors(int var1, int var2){}
};

// -----------------------------------------------------------------------------
// Params
// -----------------------------------------------------------------------------

void functionWithSimilarParams(int var1, int var_1){}
// CHECK-MESSAGES: :[[@LINE-1]]:46: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

class classWithMethodsWithSimilarParams
{
public:
    classWithMethodsWithSimilarParams(int var1, int var_1){}
    // CHECK-MESSAGES: :[[@LINE-1]]:53: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]

    void methodWithSimilarParams(int var1, int var_1){}
    // CHECK-MESSAGES: :[[@LINE-1]]:48: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
};

void functionWithSimilarParamsToVariables(int var1)
{
    int var_1;
    // CHECK-MESSAGES: :[[@LINE-1]]:9: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    int var_2;
}

void functionWithSimilarParamsToAliases(int var1)
{
    using var_1 = int;
    // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    using var_2 = int;
}

class classWithMethodsWithSimilarParamsToVariables
{
public:
    classWithMethodsWithSimilarParamsToVariables(int var1)
    {
        int var_1;
        // CHECK-MESSAGES: :[[@LINE-1]]:13: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
        int var_2;
    }

    void methodWithSimilarParamsToVariables(int var1)
    {
        int var_1;
        // CHECK-MESSAGES: :[[@LINE-1]]:13: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
        int var_2;
    }
};

class classWithMethodsWithSimilarParamsToAliases
{
public:
    classWithMethodsWithSimilarParamsToAliases(int var1)
    {
        using var_1 = int;
        // CHECK-MESSAGES: :[[@LINE-1]]:15: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
        using var_2 = int;
    }

    void methodWithSimilarParamsToAliases(int var1)
    {
        using var_1 = int;
        // CHECK-MESSAGES: :[[@LINE-1]]:15: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
        using var_2 = int;
    }
};

// -----------------------------------------------------------------------------
// Template Params
// -----------------------------------------------------------------------------

template<typename T>
using aliasWithTemplateType1 = int;

template<typename T>
using aliasWithTemplateType2 = int;

template<typename global_var>
// TODO: Currently there is no way to detect this as it's way too expensive
//       and there are multiple examples of template params with no parent,
//       which would result in a lot of searching. Since this is only an
//       issue with very specific situations like this that are unlikely to
//       occur, this is currently ignored.
using aliasWithTemplateTypeWithSimilarName = int;

template<typename T>
void functionWithTemplateType1(){}

template<typename T>
void functionWithTemplateType2(){}

template<typename global_var>
// CHECK-MESSAGES: :[[@LINE-1]]:19: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
void functionWithTemplateTypeWithSimilarName(){}

template<int I>
void functionWithNonTemplateType1(){}

template<int I>
void functionWithNonTemplateType2(){}

template<int global_var>
// CHECK-MESSAGES: :[[@LINE-1]]:14: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
void functionWithNonTemplateTypeWithSimilarName(){}

template<template<class> typename TT>
void functionWithNonTemplateType1(){}

template<template<class> typename TT>
void functionWithNonTemplateType2(){}

template<template<class> typename global_var>
// CHECK-MESSAGES: :[[@LINE-1]]:35: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
void functionWithNonTemplateTypeWithSimilarName(){}

template<typename T, typename t>
// CHECK-MESSAGES: :[[@LINE-1]]:31: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
void functionWithTemplateTypesThatAreSimilar(){}

template<typename T>
class classWithTemplateType1
{};

template<typename T>
class classWithTemplateType2
{};

template<typename T, typename t>
// CHECK-MESSAGES: :[[@LINE-1]]:31: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
class classWithTemplateTypesThatAreSimilar
{};

template<typename T>
struct structWithTemplateType1
{};

template<typename T>
struct structWithTemplateType2
{};

template<typename T, typename t>
// CHECK-MESSAGES: :[[@LINE-1]]:31: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
struct structWithTemplateTypesThatAreSimilar
{};

template<typename T>
union unionWithTemplateType1
{};

template<typename T>
union unionWithTemplateType2
{};

template<typename T, typename t>
// CHECK-MESSAGES: :[[@LINE-1]]:31: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
union unionWithTemplateTypesThatAreSimilar
{};

template<typename T>
class classWithOutOfLineDefinition
{
public:
    void bar();
};
 
template<typename T>
void classWithOutOfLineDefinition<T>::bar()
{}

class classWithStatic1
{
public:
    static int global_var;
    // CHECK-MESSAGES: :[[@LINE-1]]:16: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    static int static_var;
};

class classWithStatic2
{
public:
    static int global_var;
    // CHECK-MESSAGES: :[[@LINE-1]]:16: warning: Different identifiers shall be typographically unambiguous [bsl-identifier-typographically-unambiguous]
    static int static_var;
};

int classWithStatic1::static_var{};
int classWithStatic2::static_var{};

template<typename... ARGS>
bool
templateFunctionWithDifferentTemplateParams(ARGS &&... a)
{
    return true;
}

auto templateFunctionWithDifferentTemplateParamsTest1{
    templateFunctionWithDifferentTemplateParams(true, true, true)};
auto templateFunctionWithDifferentTemplateParamsTest2{
    templateFunctionWithDifferentTemplateParams(true, 1, true)};

template<typename T>
class classWithSpecialization
{
public:
    static constexpr int blah{};
};

template<>
class classWithSpecialization<int>
{
public:
    static constexpr int blah{42};
};

template<typename T>
class templateClassInstantiationTest
{};

templateClassInstantiationTest<int> templateClassInstantiationTest1{};
templateClassInstantiationTest<bool> templateClassInstantiationTest2{};

//Cracked by Roath
// Room: /d/beijing/dongzhimen.c

inherit ROOM;

string GATE_DESC_SHORT = "��ֱ��";
string GATE_DESC_LONG = @LONG
���Ǿ��Ƕ�����һ�����ţ��ſڹ���һ�Ÿ�ʾ (gaoshi)��
�������Ͼ��ǳ����ţ����ǵĶ�ֱ�Ŵ��ֱͨ��¥��
LONG;

mapping GATE_EXITS=([ /* sizeof() == 2 */
  "west" : __DIR__"dongzhidajie",
  "north" : __DIR__"tulu_dongzhi_n",
  "south" : __DIR__"tulu_dongzhi_s",
]);

mapping GATE_OBJECTS=([
   __DIR__"npc/bj_bing":2,
]);

string GATE_ENTER_DIR="west";
#include "outer_gate.h"

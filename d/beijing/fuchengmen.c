//Cracked by Roath
// Room: /d/beijing/fuchengmen.c
inherit ROOM;

string GATE_DESC_SHORT="������";

string GATE_DESC_LONG=@LONG
���Ǿ�������ĸ����š���ǽ������������䣬
ȫ����ש�������ɣ����Ŷ�ҲΪש��Ͳ�ǣ�ʮ�ּ�
�����ۡ��ſ����Ÿ�ʾ(gaoshi)��
LONG;

mapping GATE_EXITS=([
  "north" : __DIR__"tulu_fucheng_n",
  "south" : __DIR__"tulu_fucheng_s",
  "east"  : __DIR__"fuchengdajie",
]);

 
mapping GATE_OBJECTS=([
        __DIR__"npc/bj_bing":2,
]);

string GATE_ENTER_DIR="east";
// all the real definitions goes here
#include "outer_gate.h"

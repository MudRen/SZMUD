//Cracked by Roath
// Room: /d/beijing/xizhimen.c

inherit ROOM;
string GATE_DESC_SHORT="��ֱ��";
string GATE_DESC_LONG=@LONG
���Ǳ���������ĳ��ţ�һ����·ͨ��ɽ����ת������ɽ
������������ĳ�ǽ������������䣬ȫ����ש�������ɣ�
���Ŷ�ҲΪש��Ͳ�ǣ�ʮ�ּ�����ۡ��ſ����Ÿ�ʾ(gaoshi).
LONG;

mapping GATE_EXITS=([
  "north" : __DIR__"tulu_xizhi_n",
  "south" : __DIR__"tulu_xizhi_s",
  "east" : __DIR__"xizhidajie",
  "west" : "/d/hengshan/jinlongxia",
]);

mapping GATE_OBJECTS=([
  __DIR__"npc/bj_bing":3,
]);

string GATE_ENTER_DIR="east";
#include "outer_gate.h"

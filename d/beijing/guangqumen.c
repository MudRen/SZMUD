//Cracked by Roath
// Room: /d/beijing/guangqumen.c

inherit ROOM;

string GATE_DESC_SHORT="������";
string GATE_DESC_LONG=@LONG
���Ǿ�����ǳ�����ĳ��š�����ĳ�ǽ����Ե���΢
�ƾɣ��ر�Ҳ�����ڳ�ɭ�ϣ����Ͼ������صأ����Ȳ�����
���������˶���Χ��һ�Ÿ�ʾ(gaoshi).
LONG;

mapping GATE_EXITS=([
  "west" : __DIR__"chongwendajie",
  "north" : __DIR__"tulu_guangqu_n",
  "south" : __DIR__"tulu_guangqu_s",
]);

mapping GATE_OBJECTS=([
  __DIR__"npc/bj_bing":4,
]);

string GATE_ENTER_DIR="west";
#include "outer_gate.h"

//Cracked by Roath
// Room: /d/beijing/deshengmen.c

inherit ROOM;

string GATE_DESC_SHORT="��ʤ��";
string GATE_DESC_LONG=@LONG
���Ǿ��������ǵĵ�ʤ�š���������������ͨ���ɹţ�����˹
�Ĵ�·����·�ߵľ�Ӫ�����������һ���������м�����Ž̹�
�ĺȳ⣬���̲�ס��ȥ��һ�ۡ��ſ����Ÿ�ʾ(gaoshi)��
LONG;

mapping GATE_EXITS=([ /* sizeof() == 2 */
  "southwest" : __DIR__"tulu_desheng_sw",
  "east"  : __DIR__"tulu_desheng_e",
  "southeast" : __DIR__"xizhidajie",
]);

mapping GATE_OBJECTS=([
  __DIR__"npc/bj_bing":4,
]);

string GATE_ENTER_DIR="southeast";
#include "outer_gate.h"

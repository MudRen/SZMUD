//Cracked by Roath
// Room: /d/beijing/beihai.c

inherit ROOM;
string GATE_DESC_SHORT= "��������";
string GATE_DESC_LONG = @LONG
���Ǳ����������š���������������ϰ��ս�����ˡ�
ż�����Կ����г�͢ҪԱ���Ž��Ӿ������ſ�����һ��
��ʾ (gaoshi).
LONG;

mapping GATE_EXITS = ([ 
  "west" : __DIR__"fuchengdajie",
  "east" : "/d/beijing/beihai/ximen",
]);

mapping GATE_OBJECTS = ([
  __DIR__"npc/bj_bing":4,
]);

#include "inner_gate.h"

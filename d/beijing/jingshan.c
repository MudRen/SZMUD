//Cracked by Roath
// Room: /d/beijing/jingshan.c

inherit ROOM;

string GATE_DESC_SHORT="��ɽ";
string GATE_DESC_LONG = @LONG
����һ��λ�ڹ�¥������ı��֣�ʮ��Ƨ�����䣬·�ϼ�������
��ʲ�����ˣ��������¥�����������ʱ�������������ֱ���һ��С
�����м������֡���������
LONG;
mapping GATE_EXITS = ([ /* sizeof() == 2 */
  "north" : __DIR__"dianmen",
  "east"  : __DIR__"chaoyangdajie",
  "enter"  : __DIR__"huoshenmiao",
  "south"  : "/d/beijing/zijin/shenwumen",
]);

mapping GATE_OBJECTS = ([
    __DIR__"npc/bj_bing":4,
]);

#include "inner_gate.h"

//Cracked by Roath
// Room: /d/beijing/dianmen.c

inherit ROOM;

string GATE_DESC_SHORT = "�ذ���";
string GATE_DESC_LONG = @LONG
�ذ����ǻʳǵĺ��ţ���ʳ�������찲��ңң��ԣ���
�����찲�����ƻֺ꣬����ǽ���ʣ���ɫ�������������⣬��
���ûʣ��������¼����֮�������Ͼ����Ͻ�����. 
LONG;

mapping GATE_EXITS = ([
  "south" : __DIR__"jingshan",
  "north" : __DIR__"gulou",
]);

mapping GATE_OBJECTS = ([
__DIR__"npc/bj_bing":4,
]);

#include "inner_gate.h"

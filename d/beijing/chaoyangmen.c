//Cracked by Roath
// Room: /d/beijing/zhaoyangmen.c

inherit ROOM;

string GATE_DESC_SHORT="������";
string GATE_DESC_LONG=@LONG
���Ǿ��Ƕ���ĳ����š���ǽ������������䣬ȫ����
ש�������ɣ����Ŷ�ҲΪש��Ͳ�ǣ�ʮ�ּ�����ۡ�������
����ͨ�������Ĵ�����ſ���һ�Ÿ�ʾ(gaoshi).
LONG;

mapping GATE_EXITS=([
  "east": __DIR__"yidao3",
  "west" : __DIR__"chaoyangdajie",
  "north": __DIR__"tulu_chaoyang_n",
  "south": __DIR__"tulu_chaoyang_s",
]);

mapping GATE_OBJECTS=([
    __DIR__"npc/bj_bing":4,
]);

string GATE_ENTER_DIR="west";
#include "outer_gate.h"

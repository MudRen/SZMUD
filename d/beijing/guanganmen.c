//Cracked by Roath
// Room: /d/beijing/guanganmen.c

inherit ROOM;
string GATE_DESC_SHORT="�㰲��";
string GATE_DESC_LONG=@LONG
���Ǿ������ߵĳ���֮һ�����ڲ��Ǻܷ���������ĳ�ǽ�Ѿ�
��Щ����ô�����ˡ��Ƴǵ���·Ҳû�����������������Զ����˵
ʱ����ǿ�˳�û���űߵĸ�ʾ (gaoshi) Ҳ�Ѿ���Щ��ɫ��
LONG;

mapping GATE_EXITS=([
  "south" : __DIR__"tulu_guangan_s",
  "east"  : __DIR__"caishikou",
  "north" : __DIR__"tulu_guangan_n",
]);

mapping GATE_OBJECTS=([
	__DIR__"npc/bj_bing":2,
]);

string GATE_ENTER_DIR="east";
#include "outer_gate.h"

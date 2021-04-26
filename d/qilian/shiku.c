// Code of ShenZhou
#include "room.h"
inherit ROOM;

void create()
{
  set ("short", "ʯ��");
  set ("long", @LONG
Ī�߿�ʼ��춷���Ԫ���꣬�����������������д�Լ�İٸ�ʯ�ߡ�
������Ī�߿ߵ�һ�����ڡ�
LONG);

  set("exits", ([ 
  "eastdown" : __DIR__"drukou",
  "enter" : __DIR__"dtongdao",
]));
	set("cost", 2);
  set("objects", ([
	"/d/xingxiu/npc/yinli" : 1
	]));
  set("no_clean_up", 1);
  setup();
  call_out("reset_flags", 60);
}

void reset_flags() {
    set("no_clean_up", 1);
}

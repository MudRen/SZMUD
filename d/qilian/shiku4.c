// Code of ShenZhou
#include "room.h"
inherit ROOM;

void create()
{
  set ("short", "ʯ��");
  set ("long", @LONG
���߶��ǹ����񡣻����������������塢�ط����������·������㡢
�����Ů���ȵȲ�һ�������а˴��������ߡ�Ҳ�д�������ߡ�
LONG);

  set("exits", ([ 
  "east" : __DIR__"dtongdao2",
]));
	set("cost", 2);
  setup();
  replace_program(ROOM);
}


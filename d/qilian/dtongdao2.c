// Code of ShenZhou
#include "room.h"
inherit ROOM;

void create ()
{
  set ("short", "ͨ��");
  set ("long", @LONG
ͨ������ɽ���п���������ᴩ����ʯ�ߡ�ͨ�����������к���
��ĵıڻ��͸�������ͨ��ڶ��㡣
LONG);

  set("exits", ([ 
  "out" : __DIR__"dtongdao",
  "west" : __DIR__"shiku4",
  "up" : __DIR__"dtongdao3",
  "east" : __DIR__"shiku5",
]));

	set("cost", 1);
  setup();
  replace_program(ROOM);
}


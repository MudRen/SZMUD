// Code of ShenZhou
#include "room.h"
inherit ROOM;

void create ()
{
  set ("short", "ͨ��");
  set ("long", @LONG
ͨ������ɽ���п���������ᴩ����ʯ�ߡ�ͨ�����������и���
��ĵıڻ��͸���
LONG);

  set("exits", ([ 
  "out" : __DIR__"shiku",
  "west" : __DIR__"shiku2",
  "enter" : __DIR__"dtongdao2",
  "east" : __DIR__"shiku3",
]));

	set("cost", 1);
  setup();
  replace_program(ROOM);
}


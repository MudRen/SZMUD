// Code of ShenZhou
#include "room.h"
inherit ROOM;

void create ()
{
  set ("short", "��");
  set ("long", @LONG
���������ᴩ��ʯ�ߵ�ͨ��������ʯ���Ͽ��и�ʽ����Ͱ�͹�ʷ�
�Ĳ�ͼ��
LONG);

  set("exits", ([ 
  "east" : __DIR__"shiku8",
  "west" : __DIR__"shiku9",
  "down" : __DIR__"dtongdao3",
  "up" : __DIR__"dtongdao5",
]));

	set("cost", 1);
  setup();
  replace_program(ROOM);
}


// Code of ShenZhou
#include "room.h"
inherit ROOM;

void create()
{
  set ("short", "ʯ��");
  set ("long", @LONG
��һ���޵ò��ö�Ŀ���ڻ�ɫ�ʷḻ�������ڶࡣ������Ҫ��ƽ
����ա�Ҳ�з��졢��ʿ����ա�
LONG);

  set("exits", ([
  "west" : __DIR__"dtongdao",
]));
	set("cost", 2);
  setup();
   replace_program(ROOM);
}


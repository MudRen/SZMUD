// Code of ShenZhou
#include "room.h"
inherit ROOM;

void create ()
{
  set ("short", "ʯ��");
  set ("long", @LONG
��������ڵıڻ��������������ɱ����£�������ι������
����ɭ���֮���磬����ɫ�ñʣ��������ż��㡣������ʯ��ʯ��
֮�����У����Ժڰ׼�����֮���գ��Ե���ʵ��׾�� 
LONG);

  set("exits", ([ 
  "east" : __DIR__"dtongdao",
]));

	set("cost", 2);
  setup();
   replace_program(ROOM);
}


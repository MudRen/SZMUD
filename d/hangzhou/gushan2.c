// Code of ShenZhou
// ƽ̨
// Dong  11/03/1996.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "��ɽƽ̨");
    set("long", @LONG
ƽ̨�����С��������¾���ͤ��ͤ��������һ����(duilian)��
���ﻹ������ˮ�أ��ٳ��е�ʯ��ɽ�����õøߵͲβ�������¡�
��������ɽ��·��
LONG);

    set("exits", ([ /* sizeof() == 1 */ 
        "northdown" : __DIR__"gushan1", 
                 ])
       );
   set("item_desc", 
      ([
      "duilian" : 
	"ˮ		��\n"
	"ɽ		��\n"
	"��		ʱ\n"
        "��              ʱ\n"
	"��		��\n"
	"��		��\n"
      ])
      );
	set("cost", 1);
        set("outdoors", "hangzhou");
    setup();
    replace_program(ROOM);
}

// Code of ShenZhou
// ������
// Dong  11/03/1996.

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
   set("short", "������");
   set("long", @LONG
��������ɽ��������ǰСϪ��ˮ��������οͲ�ʱ�Ľ���������
�����������á���������ɽ��·��
LONG
        );

   set("exits", ([ /* sizeof() == 2 */ 
                  "southup" : __DIR__"tianzhu4", 
                  "northdown" : __DIR__"tianzhu2", 
                ])
       );
	set("objects", ([
                "/d/wudang/npc/guest" : 1,
		"/d/shaolin/npc/xiao-ku" : 1,
        ]));
	set("cost", 1);
   setup();
   replace_program(ROOM);
}
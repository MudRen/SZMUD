// Code of ShenZhou
// ������
// Dong  11/03/1996.

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
   set("short", "��ϲ��");
   set("long", @LONG
��ϲ��������������������ĵ�һ����������οͲ�ʱ�Ľ���
�����������ɴ���������������ɽ��·��
LONG
        );

   set("exits", ([ /* sizeof() == 2 */ 
                  "eastdown" : __DIR__"road61", 
                  "northdown" : __DIR__"tianzhu4", 
                ])
       );
	set("objects", ([
                "/d/wudang/npc/guest" : 1,
		"/d/hangzhou/npc/heshang" : 1,
        ]));

	set("cost", 1);
   setup();
   replace_program(ROOM);
}

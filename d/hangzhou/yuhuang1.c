// Code of ShenZhou
// ���ɽ·
// Dong  11/03/1996.

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
   set("short", "���ɽ��");
   set("long", @LONG
ֻ�����ϵ�ɽ·�������ӡ�ɽ·����һ��С����ͤ������������
��ͤ��Ъ�š���������һ����ʯ�������������ɽ��·��
LONG
        );

   set("exits", ([ /* sizeof() == 2 */ 
                  "northeast" : __DIR__"road71", 
                  "westup" : __DIR__"yuhuang2", 
                ])
       );

	set("cost", 3);
     set("fjing", 1);
        set("outdoors", "hangzhou");
   setup();
   replace_program(ROOM);
}

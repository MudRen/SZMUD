// Code of ShenZhou
// ��ʯɽ
// Dong  11/03/1996.

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
   set("short", "��ʯɽ");
   set("long", @LONG
��ʯɽ���Ǻܸߣ�ɽ�϶�����ʯ��ɽ·����һ��ͤ�ӡ�����ͤ����
ͤǰ�п����δ�ʯ���ٿո�����ɽ�ۣ�������ʯ���ֳ�����ʯ������
���Ͼ͵��˱������������±�ص�����ˡ�
LONG  );

   set("exits", ([ /* sizeof() == 2 */ 
                  "northup" : __DIR__"baoshi2", 
                  "southdown" : __DIR__"road12", 
                ])
       );
	set("objects", ([
            "/d/city/obj/stone" : 2,
        ]));

	set("cost", 4);
        set("outdoors", "hangzhou");
   setup();
   replace_program(ROOM);
}

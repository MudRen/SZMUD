// Code of ShenZhou
// ��ɽ 1
// Dong  11/03/1996.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "��ɽ");
    set("long", @LONG
ͨ���������ǰ��ӭ��ʯ���Ͽ��С���ɽ������������֡�����
ʰ����ɽ����ƽ̨�������߱��Ƿź�ͤ�����ϱ�����ƽ�����¡�����
��ͨ�������š�
LONG);

   set("exits", ([ /* sizeof() == 4 */ 
        "southup"   : __DIR__"gushan2", 
        "northeast" : __DIR__"fanghe", 
        "east" : __DIR__"pinghu", 
        "northwest" : __DIR__"xileng",
                ])
       );
	set("cost", 3);
set("fjing",1);
        set("outdoors", "hangzhou");
    setup();
    replace_program(ROOM);
}

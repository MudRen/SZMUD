// Code of ShenZhou
// Ϧ��ɽ
// Dong  11/03/1996.
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{   set("short", RED"Ϧ��ɽ"NOR);
    set("long", @LONG
Ϧ��ɽ�ϱ�ֲ�����ͺ�㡣ÿ��������־�Ⱦ������׳�ۡ�ɽ
����һ�������׷������񻰡����ߴ����еİ�������Ǳ�����������
�������ÿ��Ϧ�����£��������ƣ���Ӱ���������������ʮ��֮һ
�ġ��׷�Ϧ�ա���
LONG	);

    set("exits", ([ /* sizeof() == 1 */ 
                   "southdown" : __DIR__"road72", 
                 ])
       );
	set("cost", 3);
        set("outdoors", "hangzhou");
    setup();
    replace_program(ROOM);
}

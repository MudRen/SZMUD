// Code of ShenZhou
// shuiguan.c Ϳ��ˮ��
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "Ϳ��ˮ��");
	set("long", @LONG
����ȥ���ۿڵ���Ҫͨ�������СϪ֮�ϣ�ΡȻ��������ν������ɣ���
��һ��
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"east" : __DIR__"lingmu",
		"west" : __DIR__"tumen",	
	]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}

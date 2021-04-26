// Code of ShenZhou
// dufu.c ������
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "������");
	set("long", @LONG
����Ȫ�ݶ����ĸ�ۡ��Ȫ�ݶ����ƹ�Ȫ�ݵĺ�½��Ȩ��������������
�򣬹�Ͻ��ʱ��ǿ���Զ��ˮʦ����һ��һ��Ҫ�Ĺ�ְ��
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"west" : __DIR__"duxiang",
		"south" : __DIR__"mixiang",
	]));

        set("objects", ([ 
		__DIR__"npc/wujiang" : 1,
		__DIR__"npc/bing" : 2,
        ]));

        set("no_clean_up", 0);

	set("cost", 1);
        setup();
}

int valid_leave(object me, string dir)
{
	if ( objectp(present("wu jiang",environment(me))) && dir == "south" )
		return notify_fail("�佫��ȵ���������������˵Ȳ����ɴ˾�����\n");

	if ( objectp(present("guan bing",environment(me))) && dir == "south" )
		return notify_fail("�ٱ���ȵ���������������˵Ȳ����ɴ˾�����\n");

	return ::valid_leave(me, dir);
}

// Code of ShenZhou
// duxiang.c ������
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "������");
	set("long", @LONG
����Ȫ�ݵ�һ��С��徻���ࡣԶԶ�ɼ���׺�ǽ����������ɭ�ϣ���
Ȼ������ͨ��ס�ҡ�
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"west" : __DIR__"citong_n1",
		"east" : __DIR__"dufu",
	]));

	set("objects", ([
		__DIR__"npc/bing" : 2,
	 ]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}

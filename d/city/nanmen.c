// Code of ShenZhou
// Room: /city/nanmen.c
// YZC 1995/12/04 

#include <ansi.h>
inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "����");
	set("long",
"�������š���ǽ�������˹���ƣ������˻������̸��и�ҵ�Ĺ�棬�ٸ���
"+HIW"��ʾ"NOR+"(gaoshi)��˲�̫���ۡ��ٱ��Ǳ������Ļ���Ц�����������ƺ����Ǻ�����
��ִ�ڡ�һ����ֱ����ʯ�������ϱ��������졣\n"
	);
        set("outdoors", "city");

	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));

	set("exits", ([
		"south" : __DIR__"wdroad1",
		"north" : __DIR__"nandajie3",
		"east" : __DIR__"nanjiao1",
		"west" : __DIR__"nanjiao3",
	]));
        set("objects", ([
                __DIR__"npc/wujiang" : 1,
                __DIR__"npc/bing" : 2,
        ]));

	set("cost", 1);
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n�㽭�ᶽ\n�����\n";
}

int valid_leave(object me, string dir)
{
        if (dir =="north" )
        if(present("guan bing", (environment(me)))
        && me->query_condition("killer") > 0)
                return notify_fail("�ٱ����еĵ���ס�����ȥ·��\n");
        return ::valid_leave(me, dir);
}

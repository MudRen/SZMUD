// Code of ShenZhou
// Room: /d/dali/wuhua.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�廪¥����"NOR);
	set("long","�������廪¥�Ĵ��ţ����Ⱥ�ľ���ϵ����˸����Ͻ����������ޡ���������
گ�����Ӵ����ϸ�������ĵط�������һ����ľ���ƣ�������������һ�ɰ˳߸ߣ�
�����ý��������������"HIY"���廪¥��"NOR"����������گ��Ȱ���ӵ��ּ���\n"
);
	set("objects", ([
		__DIR__"npc/weishi4" : 2,
		]));
	set("exits", ([
		"south" : __DIR__"shanlu3.c",
		"enter" : __DIR__"wuhua1.c",
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("no_sleep_room",1);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}

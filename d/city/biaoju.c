// Code of ShenZhou
// Room: /city/biaoju.c
// Room: /city/biaoju.c
// YZC 1995/12/04 
// Modified by Sure 9/2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�����ھ�");
        set("long",
"������һ���ṹ��ΰ�Ľ���ǰ������ʯ̳�ϸ�����һ�����ɶ�ߵ���ˣ���
������Ʈ����������ý�������һͷ������צ��ʨ�ӣ�ʨ����ͷ��һֻ�����
�衣����������д�š�"BRED+HIY"�����ھ�"NOR+"���ĸ����֣������������վ��Ƿ�����ڴ�����
�������ʣ�������ͷ���Ű��ء�����ͷ��������˵Ц��\n"
	);

	set("exits", ([
		"south" : __DIR__"zhengting",
		"north" : __DIR__"xidajie3",
	]));

	set("objects", ([
		__DIR__"npc/linpingzhi" : 1,
		__DIR__"npc/biaotou" : 2,
	]));

	set("cost", 0);
	setup();
	replace_program(ROOM);
}

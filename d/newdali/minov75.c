// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov75.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ��Ƭï�ܵ����֣�������ɽ���Ǹ�ï�ܵ���Ҷ�֣������ڶࡣ�о���
��̨�������������������ס����£���׽�á�¹��С�ޣ��������������ɽ��
׽��Щ�����ޡ�
LONG);
	set("objects", ([
		__DIR__"npc/tylieren" : 2,
		]));
	set("exits", ([
		"northeast" : __DIR__"minov74",
		]));
	set("area", "������");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}

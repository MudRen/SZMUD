// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov37.c

inherit ROOM;

void create()
{
	set("short", "���Ϸ�");
	set("long", @LONG
����һ�������ĸ�����ӣ��˼��²�ȴû��ţ����������ϯΧס����һ
�����ݣ���������������̣�������һЩɣ�ϡ�һλ���Ĺ������������ʵ�ɣҶ
ι��ɣ�ϡ�
LONG);
	set("objects", ([
		__DIR__"npc/bycannv" : 1,
		]));
	set("exits", ([
		"west" : __DIR__"minov34",
		]));
	set("area", "���۲�");
	set("cost", 2);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

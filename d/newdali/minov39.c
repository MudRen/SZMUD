// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov39.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
һ�������ĸ�����ӣ��˼��²�û��ţ��ȴ����ϯΧ��һ����ɣ�ϵ�С
���ݣ���������̡�¥�ϴ��������ɴ�����������
LONG);
	set("objects", ([
		__DIR__"npc/bycannv" : 1,
		]));
	set("exits", ([
		"east" : __DIR__"minov38",
		"up" : __DIR__"minov40",
		]));
	set("area", "���۲�");
	set("cost", 2);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

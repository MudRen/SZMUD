// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov82.c

inherit ROOM;

void create()
{
	set("short", "ˮ��");
	set("long", @LONG
����һƬ����ƽ�ص�ũ������﹡��ȫ������ˮ��û�ţ�һЩ���Ჿ�ĸ�
Ů���Ž�������������������ˮ���㣬��Ȼû�н��������������ر�Ĺ�ȣ�
ÿ������������Ȼ��ˮ������
LONG);
	set("objects", ([
		__DIR__"npc/tynong" : 1,
		__DIR__"npc/niu" : 1,
		]));
	set("exits", ([
		"north" : __DIR__"minov78",
		]));
	set("area", "³����");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}

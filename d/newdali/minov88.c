// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov88.c

inherit ROOM;

void create()
{
	set("short", "����ɽ·");
	set("long", @LONG
�����ڴ���ɽ���һ����·�ϡ��˼��������ڣ��������ߣ���ɽ����Խ�
ƽ��������ɼ���ѩ��������ظ�ԭȺɽ������һ·��Խɽ��ֱͨ�����ϴ���
����ɽ����Щ�����˵Ĵ��䡣
LONG);
	set("exits", ([
		"northup" : __DIR__"minov89",
		"southdown" : __DIR__"minov87",
		]));
	set("area", "��Ū��");
	set("cost", 4);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}

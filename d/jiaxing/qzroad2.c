// Code of ShenZhou
// Room: /d/quanzhou/qzroad2.c
// Date: May 7, 96   Jay

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
������һ��ɽ·�ϡ�ʱֵ���գ�·�Ե�ɽ���Ͽ����˽��ɫ���Ͳ˻���
�����ǽ������Ǽ��ˡ�
LONG
	);

	set("exits", ([
                "east"  : __DIR__"jiaxing",
                "northwest" : "/d/taihu/road",
	]));

	set("outdoors", "quanzhou");
	set("cost", 3);
	setup();
	replace_program(ROOM);
}


// Code of ShenZhou

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
������һƬũ���Զ����һЩ��ׯ�������������𡣴�ׯ��Χ
��һ������أ�������һЩ���ڸ�����ũ�ˡ�
LONG
	);

	set("exits", ([
                "southeast" : "/d/jiaxing/qzroad2",
		"northeast" : __DIR__"taihu",
                "north" : "/d/forest/clforest4",
	]));

	set("outdoors", "taihu");
	set("cost", 3);
	setup();
	replace_program(ROOM);
}


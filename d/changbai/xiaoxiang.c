// Code of ShenZhou
// Room: xiaoxiang.c

inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
����һ��Ƨ�������С����ܼž�������һ����ӰҲû�С�������ʯ
��·������һ����Ļ�ѩ�����ڽ��·�������֨����������С��ľ�ͷ��
һ�����ݡ�
LONG
	);

	set("exits", ([
		"southwest" : __DIR__"tuwu",
                "east" : __DIR__"beicheng",
	]));

        set("outdoors", "changbai");
        set("cost", 2);

	setup();
	replace_program(ROOM);
}


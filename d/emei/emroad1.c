// Code of ShenZhou
// emroad1.c С·
// Shan: 96/06/22

inherit ROOM;

void create()
{
        set("short", "С·");
        set("long", @LONG
�����Ѿ����Ĵ������ˡ�һ�������ĵ�С��·��������ֳ����档·����
���������ũ������·�����˺��٣����ҴҸ�·��
LONG
        );
        set("exits", ([
		"south" : __DIR__"shijie2",
		"westup" : __DIR__"chuanxi1",
                "east" : __DIR__"emroad2",
		"southwest" : "/d/chengdu/eroad4",
        ]));

        set("no_clean_up", 0);

	set("outdoors", "emei");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}


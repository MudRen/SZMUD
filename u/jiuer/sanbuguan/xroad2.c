//Cracked by Shenzhou
// /d/sanbuguan/xroad2.c С·

inherit ROOM;

void create()
{
        set("short", "С·");
        set("long", @LONG
����һ�������ĵĻ���·��������ЩС���ݣ���������ġ�·�����˺��٣�
����ɫ�Ҵ���ǰ��·��
LONG
        );
        set("exits", ([
                "east" : __DIR__"xroad1",
                "southwest" : __DIR__"xroad3",
        ]));

        set("no_clean_up", 0);

	set("outdoors", "sanbuguan");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}


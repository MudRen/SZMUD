// Code of ShenZhou
// emroad4.c С·
// Shan: 96/06/22

inherit ROOM;

void create()
{
        set("short", "С·");
        set("long", @LONG
�������������ڡ�һ�������ĵĻ���·��������ЩС���ݣ���������ġ�
��·�����˺��٣�����ɫ�Ҵ���ǰ��·��
LONG
        );
        set("exits", ([
		"northeast" : __DIR__"emroad5",
					 "west" : __DIR__"emroad3",
                "north": "/d/zhongnan/daolu",
        ]));

        set("objects", ([
            "/d/city/obj/stone" : 2,
        ]));

        set("no_clean_up", 0);

	set("outdoors", "emei");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}


// Code of ShenZhou
// /d/emei/emroad5.c С·
// Shan: 96/06/22

inherit ROOM;

void create()
{
        set("short", "��ʯ��·");
        set("long", @LONG
������һ��ͨ�򳤰��ǵ���ʯ��·��������ЩС���ݣ���������ġ�·����
�˺��٣�����ɫ�Ҵ��򱱸�·����ȡ��㵽�����ǡ�
LONG
        );
        set("exits", ([
                "east" : __DIR__"emroad6",
                "north" : "/d/changan/nanmen",
                "southwest" : __DIR__"emroad4",
        ]));

        set("no_clean_up", 0);

	set("outdoors", "emei");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}

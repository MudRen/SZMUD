// Code of ShenZhou
// jiangfu.c ʩ�Ž�����
// Jay 5/11/97

inherit ROOM;

void create()
{
        set("short", "������");
	set("long", @LONG
���Ǿ�������鷿����������鼮֮�⣬����Ļ��Ǹ��ֱ��С�
LONG
        );

        set("exits", ([ 
		"south" : __DIR__"jiangfu",
	]));

        set("objects", ([ 
		__DIR__"npc/shilang" : 1,
        ]));

	set("cost", 1);
        setup();
        replace_program(ROOM);

}

// Code of ShenZhou
// Room: /d/jiaxing/jxnanmen.c
// modified by aln  2 / 98

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
�����Ǽ��˵����š���Χ����ï�ܵ����֡������������
���Ͽ��븣�����������߾��Ǻ����ˡ�
LONG
	);

	set("cost", 1);
	set("outdoors", "quanzhou");
	set("exits", ([ /* sizeof() == 4 */
                "east" : __DIR__"tieqiang",
                "southeast" : __DIR__"chating",
                "southwest" : __DIR__"field",
                "north" : __DIR__"jiaxing",
        ]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

// Code of ShenZhou
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "Ӣ�ۻ��");
        set("long", @LONG
�ĳ���Χ�ź�ѹѹ��һȺ�ˣ�����������Ѻ��С��
LONG
        );
        set("exits", ([
		"north" : __DIR__"street1",
	]));

	set("objects", ([
		__DIR__"npc/yiming" : 1,
	]));
	set("cost",1);
	setup();
        replace_program(ROOM);
}

// Code of ShenZhou
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "�ּ��");
        set("long", @LONG
������һ���ּ�С���������������ѡ�����ɽ��ï
�ܣ�������棬��λ��·Ҫʮ��С�ġ�
LONG
        );
        set("exits", ([
		"northwest" : __DIR__"qzroad3",
	]));

	set("objects", ([
            __DIR__"npc/zsnake" : 1,
            __DIR__"obj/tihu-xiang" : 1,
	]));
	set("cost",1);
        set("tjjob", 4);
	set("outdoors", "wudang");
	setup();
        replace_program(ROOM);
}

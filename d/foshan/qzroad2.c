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
		"east" : __DIR__"qzroad3",
		"west" : __DIR__"qzroad1",
	]));

	set("objects", ([
                "/d/emei/obj/flower" : 1,
	]));
	set("cost",1);
	set("outdoors", "wudang");
	setup();
        replace_program(ROOM);
}

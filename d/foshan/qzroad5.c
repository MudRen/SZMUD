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
		"northeast" : __DIR__"qzroad6",
		"southwest" : __DIR__"qzroad3",
	]));

	set("objects", ([
            "/d/city/obj/stone" : 2,
	]));
	set("cost",1);
	set("outdoors", "wudang");
	setup();
        replace_program(ROOM);
}

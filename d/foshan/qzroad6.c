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
		"northeast" : __DIR__"qzroad7",
		"southwest" : __DIR__"qzroad5",
	]));

	set("objects", ([
            "/d/city/obj/branch" : 2,
	]));
	set("cost",1);
	set("outdoors", "wudang");
	setup();
        replace_program(ROOM);
}

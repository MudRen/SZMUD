// Code of ShenZhou
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "�ּ��");
        set("long", @LONG
������һ���ּ�С���������������ѡ�����������һ������·����
��ĵ�·Ҫ��һЩ��
LONG
        );
        set("exits", ([
		"south" : __DIR__"road2",
		"northwest" : "/d/wudang/wdroad6",
	]));

	set("objects", ([
		"/d/city/obj/branch" : 1,
	]));
	set("cost",1);
	set("outdoors", "wudang");
	setup();
        replace_program(ROOM);
}

// Code of ShenZhou
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "�ּ��");
        set("long", @LONG
������һ���ּ�С���������������ѡ��������ǹ�������������
���Ǵ�����ĵؽ��ˡ�
LONG
        );
        set("exits", ([
		"east" : __DIR__"dlroad6",
		"northwest" : "/d/dali/tulu4",
	]));

	set("objects", ([
		"/d/city/obj/stone" : 1,
	]));
	set("cost",1);
	set("outdoors", "wudang");
	setup();
        replace_program(ROOM);
}

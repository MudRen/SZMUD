// Code of ShenZhou
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "�ּ��");
        set("long", @LONG
������һ���ּ�С���������������ѡ����������������ɽ��
����ͨ�������
LONG
        );
        set("exits", ([
		"east" : __DIR__"wgate",
		"west" : __DIR__"dlroad2",
	]));

	set("objects", ([
		"/d/city/obj/branch" : 1,
	]));
	set("cost",1);
	set("outdoors", "wudang");
	setup();
        replace_program(ROOM);
}

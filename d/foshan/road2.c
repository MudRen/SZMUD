// Code of ShenZhou
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "�ּ���");
        set("long", @LONG
������һ���ּ����������������ѡ������Ǻ������ڡ��ϱ���
���ϡ�
LONG
        );
        set("exits", ([
		"south" : __DIR__"road3",
		"north" : __DIR__"road1",
	]));

	set("objects", ([
		"/d/village/npc/dog" : 1,
	]));
	set("cost",1);
	set("outdoors", "wudang");
	setup();
        replace_program(ROOM);
}

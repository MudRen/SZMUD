// Code of ShenZhou
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "�ּ���");
        set("long", @LONG
������һ���ּ����������Ǻ��Ͼ��ڡ��ϱ�ͨ�������һ��
ɽ�ڡ�·���и�С���ӡ�
LONG
        );
        set("exits", ([
		"west" : __DIR__"cunkou",
		"southup" : __DIR__"nanling",
		"north" : __DIR__"road3",
	]));

	set("cost",1);
	set("outdoors", "wudang");
	setup();
        replace_program(ROOM);
}

// Room: wroad1.c ���
// By jpei

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
����һ������ʯ�̳ɵĴ�������߲�Զ�����������񶼳ɶ��ˡ�
LONG);
        set("outdoors", "chengdu");
        set("cost", 1);
	set("exits", ([
		"east" : __DIR__"daximen",
		"west" : __DIR__"wroad2",
	]));

	setup(); 
	replace_program(ROOM);
}

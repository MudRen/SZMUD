// Room: eroad1.c ���
// By jpei

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
����һ������ʯ�̳ɵĴ��������ͨ���������񶼳ɶ��ˣ��򶫱��߿���
ȥ��������
LONG);
        set("outdoors", "emei");
        set("cost", 1);
	set("exits", ([
		"west" : __DIR__"dadongmen",
		"northeast" : __DIR__"eroad2",
	]));

	setup(); 
	replace_program(ROOM);
}

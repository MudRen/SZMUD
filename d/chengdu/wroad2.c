// Room: wroad2.c ���
// By jpei

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
����һ������ʯ�̳ɵĴ�������߼��ﴦ�����������񶼳ɶ��ˡ�
LONG);
        set("outdoors", "chengdu");
        set("cost", 1);
	set("exits", ([
		"east" : __DIR__"wroad1",
              "west" : __DIR__"tulu3",
	]));

	setup(); 
	replace_program(ROOM);
}

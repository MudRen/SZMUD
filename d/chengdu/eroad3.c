// Room: eroad3.c ���
// By jpei

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
����һ������ʯ�̳ɵĴ�������ϱ�ͨ���Ĵ����в������治Զ�����Ǵ�
������ĵط��ˡ�
LONG);
        set("outdoors", "emei");
        set("cost", 1);
	set("exits", ([
		"east" : __DIR__"eroad4",
		"southwest" : __DIR__"eroad2",
	]));

	setup(); 
	replace_program(ROOM);
}

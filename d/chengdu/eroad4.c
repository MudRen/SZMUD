// Room: eroad4.c С·
// By jpei

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
�������˴��������С·�ϣ�ż��������������ҴҶ������������ĳ�
����������ͨ�����ɶ��Ĵ��������������������
LONG);
        set("outdoors", "emei");
        set("cost", 1);
	set("exits", ([
		"northeast" : "/d/emei/emroad1",
//		"east" : "/d/xiangyang/xiaolu2",
		"west" : __DIR__"eroad3",
	]));

	setup(); 
	replace_program(ROOM);
}

//Cracked by shenzhou
// road3.c

inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
������һ����ʯ����ϣ����ϱ���Լ�ɼ������ݳǵĳ�ǽ��
LONG
	);
	set("outdoors", "sanbuguan");

	set("exits", ([
		"west" : "/d/sanbuguan/road4",
		"southeast" : "/d/sanbuguan/road2",
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}


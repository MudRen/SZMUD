// Code of ShenZhou
// Room: /lyddao3.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
������һ����ʯ�̳ɵĴ���ϣ����������ű�ֱͨ��İ�������������
������ȥ��ȫ���ޱ��޼ʵ���Ұ����ߴ��·��м����Ͱ������꣬Ϊƽ̹��
��������˼�����͵����ߡ�·�Ͻ����ĳ�����һЩ��ѩ��
LONG
	);

	set("exits", ([
		"south" : __DIR__"lyddao2",
		"north" : __DIR__"lyddao4",
	]));

        set("objects",([
                __DIR__"npc/juren3" : 1,
        ]));

        set("outdoors", "changbai");
        set("cost", 2);

	setup();
	replace_program(ROOM);
}


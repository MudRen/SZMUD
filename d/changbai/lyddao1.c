// Code of ShenZhou
// Room: /lyddao1.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
������һ����ʯ�̳ɵĴ���ϣ����������ű�ֱͨ��İ�������������
������ȥ��ȫ���ޱ��޼ʵ���Ұ����ߴ��·��м����Ͱ������꣬Ϊƽ̹��
��������˼�����͵����ߡ�·�����˽���ϡ��������
LONG
	);

	set("exits", ([
		"south" : __DIR__"ningyuan",
		"northeast" : __DIR__"lyddao2",
	]));

        set("objects",([
                __DIR__"npc/juren2" : 1,
        ]));

        set("outdoors", "changbai");
        set("cost", 2);

	setup();
	replace_program(ROOM);
}


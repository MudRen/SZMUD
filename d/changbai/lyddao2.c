// Code of ShenZhou
// Room: /lyddao2.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
������һ����ʯ�̳ɵĴ���ϣ����������ű�ֱͨ��İ�������������
������ȥ��ȫ���ޱ��޼ʵ���Ұ����ߴ��·��м����Ͱ������꣬Ϊƽ̹��
��������˼�����͵����ߡ�·�����˽���ϡ������������Ҳ���������ˡ�
LONG
	);

	set("exits", ([
		"southwest" : __DIR__"lyddao1",
		"north" : __DIR__"lyddao3",
	]));

        set("objects",([
                __DIR__"npc/juren1" : 1,
                __DIR__"npc/juren4" : 1,
        ]));

        set("outdoors", "changbai");
        set("cost", 2);

	setup();
	replace_program(ROOM);
}


// Code of ShenZhou
// Room: /lyddao4.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
������һ����ʯ�̳ɵĴ���ϣ����������ű�ֱͨ��İ�������������
������ȥ��ȫ���ޱ��޼ʵ���Ұ����ߴ��·��м����Ͱ������꣬Ϊƽ̹��
��������˼�����͵����ߡ���Х�����Ŀ�綳����ֱ����¡�
LONG
	);

	set("exits", ([
		"south" : __DIR__"lyddao3",
		"north" : __DIR__"lyddao5",
	]));

        set("outdoors", "changbai");
        set("cost", 2);

	setup();
	replace_program(ROOM);
}


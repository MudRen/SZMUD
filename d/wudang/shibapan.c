// Code of ShenZhou
// shibapan.c �䵱ʮ����
// by Fang 8/19/96

inherit ROOM;

void create()
{
	set("short", "ʮ����");
	set("long", @LONG
	����һ���ܴ��б�£��׳�ʮ���̣���ʯ��һ��һ����ֱ���ϣ��ķѽ�����
�����������񣬹չ�����������ʮ��֮������������
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"southup" : __DIR__"shijie2",
		"northdown" : __DIR__"shiliang",
	]));

	set("cost", 3);
	setup();
	replace_program(ROOM);
}


// Code of ShenZhou
// Room: /d/dali/dalicheng4.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
�������������ܵ��������е��徻����ؽ�����گ��䣬�����޸����ڴ���
԰�ֹ����İ����£������˲ʡ�������Ϻ��浹Ҳ���˲��٣������ļ��紺����
���£��ɻ�˯���ޱ���次�
LONG);
	set("exits", ([
		"east" : __DIR__"dalicheng3",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}

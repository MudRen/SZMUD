// Code of ShenZhou
// xiaoxi.c
// maco

inherit ROOM;

void create()
{
    int i;
	set("short", "���");
	set("long", @LONG
���ﵽ���ǲ������ɣ���ǰһƬ����������϶���һ�����ٲ�
��ˮ���Ľ������ܻ����β�ӻ������䣬��ӳ�ڱ��̵ĺ�ˮ֮
�У�����Ī����ֻ������С����ౣ����б���ײ�������ٲ�����֯
��һƬ��������������һƬ�����Ĳ�ԭ��
LONG
	);

	set("exits", ([
		"east" : __DIR__"xiaoxi",
		"northwest" : __DIR__"caoyuan1",
	]));

	set("resource/water",1);
	set("outdoors","xingxiu");
	set("cost", 1);
	setup();
	replace_program(ROOM);
}


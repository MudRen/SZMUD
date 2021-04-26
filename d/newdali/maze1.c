// Code of ShenZhou
// Room: /d/dali/maze1.c

inherit ROOM;

int do_find(string);

void create()
{
	set("short", "������");
	set("long", @LONG
��������һƬ��ɭɭ��������ǰ��������ȥ����������Ķ�����ľ�����Ҿ�
����������Լ�ɼ���ЩС·��������������ϸ�۲죬��������Ȼ�Ǹ�������Թ���
���а������а��ԣ����Ŷݼף��˵ķ�ͬС�ɣ�ǧ��ҪðȻ��ȥ��
LONG);
	set("exits", ([
		"north" : __DIR__"minov11",
		"south" : __DIR__"maze2.c",
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
}
int valid_leave(object me, string dir)
{
	if (dir=="south") {
		me->set_temp("mark/maze��", 1);
		me->set_temp("mark/mazeľ", 1);
		me->set_temp("mark/mazeˮ", 1);
		me->set_temp("mark/maze��", 1);
		me->set_temp("mark/maze��", 1);
	}

	return ::valid_leave(me, dir);
}

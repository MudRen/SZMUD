// Code of ShenZhou
// Room: /d/dali/senlin1.c

inherit ROOM;

int do_enter(string);

void create()
{
	set("short", "��ɭ��");
	set("long", @LONG
ӭ��һ��Ƭ��ѹѹ��ɭ�֣��ߴ�Ĺ��ɲ������������һ�ž������������
������Щ�ر�
LONG);
	set("exits", ([
		"south" : __DIR__"senlin.c",
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
}
void init()
{
	add_action("do_enter","enter");
}
int do_enter(string arg)
{
	object me;
	me=this_player();

	if (arg=="������")
	{
		tell_object(me, "���Ƶ���������������󣬲������ݣ�����һ���󶴣����˽�ȥ��\n");
		tell_object(me, "������ʯ�����Ϻ������˺ü�ʮ����������һƬ���ƺ��\n");
		me->move("/d/dali/wjg1.c");
		return 1;
	}
	return 0;
}
// Code of ShenZhou
// yideng quest room 3

inherit ROOM;
int do_jump(string);

void create()
{
	set("short", "�ٲ���");
	set("long", @LONG
�������ٲ�ˮ�ף�ˮ������ֱ�£���˫��ʹ�����ԡ�ǧ��׹���Ĺ�������վ
�ȣ�ǡ����������������������
LONG);
	set("objects", ([
		__DIR__"npc/gfish" : 1,
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("no_sleep_room",1);
	set("invalid_startroom", 1);
	setup();
}
void init()
{
	add_action("do_jump", "jump");
}
int do_jump(string arg)
{
	object me = this_player();

	if ( !arg || arg != "bank" ) return notify_fail( "ʲô��\n");

	message_vision("$N������������ȥ��\n", me);
	me->move(__DIR__"yideng1");
	return 1;
}


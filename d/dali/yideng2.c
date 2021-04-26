// Code of ShenZhou
// yideng quest room 2

inherit ROOM;

int do_jump(string);
int do_lift(string);

void create()
{
	set("short", "�ٲ���");
	set("long", @LONG
�������ٲ�ˮ�ף�ˮ������ֱ�£���˫��ʹ�����ԡ�ǧ��׹����
��������վ�ȣ�ǡ�����������������������㷢�ֽ������Ѿ��ص�һ
���ʯ(stone) ����ȥ�ˡ�
LONG
	);

	set("item_desc",([
        "stone" : "һ��޴����ʯ��\n",
        ]));
	set("invalid_startroom", 1);
	setup();
}

void init()
{
	add_action("do_jump", "jump");
	add_action("do_lift", "lift");
}

int do_jump(string arg)
{
	object me = this_player();

	if ( !arg || arg != "bank" )
		return notify_fail( "ʲô��\n");

	message_vision("$N������������ȥ��\n", me);
	me->move(__DIR__"yideng1");
	return 1;
}

int do_lift(string arg)
{   
	object me = this_player();

	if ( !arg || arg != "stone" )
		return notify_fail( "ʲô��\n");

	message_vision("$N�������ʯ��̧ȥ��\n", me);
	if ( me->query_str() < 26 ) {
		message_vision("$N�������˼��ƣ�����ʯ�Ʒ粻����\n", me);
		me->receive_damage("qi", 100, "����͸֧��������");
	}
	else {
		message_vision("$N����������ȥ���Ǿ�ʯ��ˮ���������л���ҡ���˼��£�����$N\n���ԣ�����¡¡������������Ԩ��ȥ�ˣ�������ɽ�ȼ伤������������\n���Ȼ���ò�����\n... ...\n\n", me);
		me->move(__DIR__"yideng3");
	}
	return 1;
} 



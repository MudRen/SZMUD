// Code of ShenZhou
// yideng quest room, small boat

inherit ROOM;
void create()
{
	set("short", "С��");
	set("long", @LONG
������һ��С����⶯�����������ţ������ٲ�ǰ���ļ�ˮ��
����ˮ���ϡ�
LONG
	);
    set("no_sleep_room",1);

	setup();
}

void init()
{
	object me;
	me=this_player();
	remove_call_out("moveon");
	call_out("moveon", 10, me);
}

void moveon(object me)
{
	tell_object(me, "����������һ�����С������ˮ��ǳ����Ϫ�����㿿���´���\n");
	me->move("/d/dali/yideng4.c");
}

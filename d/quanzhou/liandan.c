// Code of ShenZhou
// liandan.c ����ʯ
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;
inherit F_SSERVER;

void create()
{
        set("short", "����ʯ");
	set("long", @LONG
���������ϵ�һ��խʯ(stone)�� ������ڡ��������ϣ��������˺����
���絶�ͷ��Ŀѣ��ҡҡ��׹���ഫ������������Ӣ�����������ʱ������
ʯ����������̵ġ�������ɽ���ĸ��֡�
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"northwest" : __DIR__"mituo",
		"eastdown" : __DIR__"shanlu2",
	]));

	set("item_desc",([
            "stone" : "ֻ��խʯ���������ϣ��ο�籩��ʼ�ղ������㲻����̾����֮�档\n"
	]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 3);
        setup();
}

void init()
{
	add_action("do_climb", "climb");
	add_action("do_climb", "pa");
}

int do_climb(string arg)
{
	object me = this_player();

	if ( !arg || arg != "stone" ) return 0;

	if ( me->query_temp("marks/climb") ) return notify_fail("�㻹δ��ʯ���������ż�ʲô��\n");

	message_vision("$N������������������ʯ�����ϱ��紵�ö�ҡ���ڣ���ʱ����ʧ�㣡\n", me);

	if ( random((int)me->query_kar()) < 2 ) {
		message_vision("ͻȻ���������$Nһ��֧�ֲ�ס������һ���Һ�ʧ���������ʯ��\n", me);
		me->receive_wound( "qi", me->query("max_qi")+100, "����紵��ɽʯ������" );
	}
	else if ( random((int)me->query_kar()) < 8 && me->query_skill("dodge") < 30 ) {
		message_vision("ͻȻ���������$Nһ��֧�ֲ�ס������һ���Һ�ʧ���������ʯ��\n", me);
		me->unconcious();
	}
	else if ( random((int)me->query_kar()) < 8 ) {
		message_vision("ͻȻ���������$N���紵�ö�ҡ���ڣ���ʱ����ʧ����£�\n", me);
		me->receive_damage( "qi", 50, "����紵��ɽʯ������" );
        	me->receive_damage( "jing", 50, "����紵��ɽʯ������" );
	}

	if ( living(me) ) {
		me->receive_damage( "qi", 50, "����紵��ɽʯ������" );
        	me->receive_damage( "jing", 20, "����紵��ɽʯ������" );
	}

	if ( me->query("potential") - me->query("learned_points") < 100 
	&& random(5) == 1 ) me->add("potential", 1);

	call_out("check", 1, me);
	me->set_temp("marks/climb", 1);

	return 1;
}

int check(object me)
{
	if ( !me->is_ghost() && living(me) ) 
		message_vision("$Nһ�������ܲ�ס��ֻ��С�����������������\n", me);
	else message_vision("$N����һ�������ĲҺ���ʧ���������ʯ��\n", me);

	me->delete_temp("marks/climb");

	return 1;
}

int valid_leave(object me, string dir)
{
	if ( me->query_temp("marks/climb") ) 
		return notify_fail("�㻹δ��ʯ�������أ�\n");

	return ::valid_leave(me, dir);
}
	
	

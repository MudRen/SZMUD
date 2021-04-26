// Code of ShenZhou
// /d/emei/tomb2.c
// xbc 97/02/05

#include <ansi.h>
inherit ROOM;

// int do_open(string);

void create()
{
	set("short", "Ĺ��");
	set("long", @LONG
�����ǹ���Ĺ�µ�Ĺ�ҡ�Ĺ�Ҳ���������һ�߰���ʯ�ף��Ա߷���һյ����
�ơ�ʯ��һ����Ⱦ�������������˽�����ɨ��
LONG
	);

	set("objects",  ([__DIR__"obj/coffin1" : 1,]) );
	set("item_desc", ([
		"coffin" : "����һ�߰���ʯ��ɵ�ʯ�ס�\n",
	]));

	set("invalid_startroom", 1);

	set("arrow_count", 3);
//	set("rwj_count", 1);

	set("cost", 0);
	setup();
}

void init()
{
//	add_action("do_open", "open");
	add_action("do_move", "move");
}

int shoot_arrow(object me)
{
	if ((int)query("arrow_count") < 1 ) return 0;

	switch ((int)query("arrow_count")) {
	case 3:
		message_vision(HIY"��Ȼ�伸֧�̼��ӹ׺�һ���������������ֱ����$N�����ţ�\n"NOR, me);
		break;
	case 2:
		message_vision(HIY"��Ȼ�伸֧�̼��ӹ׺�һ���������������ֱ����$N���ʺ�\n"NOR, me);
		break;
	case 1:
		message_vision(HIY"��Ȼ�伸֧�̼��ӹ׺�һ���������������ֱ����$N��ǰ�أ�\n"NOR, me);
		break;
	default:
		message_vision(HIY"��Ȼ�伸֧�̼��ӹ׺�һ���������������ֱ����$N�����ţ�\n"NOR, me);
		break;
	}
	add("arrow_count", -1);

	if ( (int)me->query_dex() > (22+random(8))) {
		message_vision("$Nͷһ�ͣ��ܿ��̼�������һ�ԡ�\n", me);
		return 1;
	}

	else if ( (int)me->query_dex() > (20+random(4))) {
		message_vision("$N������ܿ���ȴ������һ֧�̼������Ҽ磬������ȥ��\n", me);
		me->add("qi", -50);
		me->unconcious();
		return 1;
	}

	else {
		message_vision("$N��ܲ��������̼�������ã����ڵ��ϡ�\n", me);
		me->receive_damage("qi", 50, "������������");
		me->die();
		return 1;
	}
	return 0;
}

int do_move(string arg)
{
        object me;
	object room = load_object(__DIR__"secret_path1");

        me = this_player();

        if( !arg || arg=="" ) return 0;

        if( arg =="coffin" || arg =="guan" ) {
		if ( !query_temp("secret_trigger") ) {
			set_temp("secret_trigger", 1);
                	message_vision("$N����ȥ��ʯ�ף���֪������ʲô���أ�Ĺ��һ�Ǻ�Ȼ����һ��С�š�\n", me); 
			set("exits/down", __DIR__"secret_path1");
                       	room->set("exits/up", __FILE__);
                       	message("vision", "ͷ���ϵİ��ź�Ȼ���˴򿪣�Ĺ���д���΢���ĵƹ⡣\n",room );
			remove_call_out("close_door");
			call_out("close_door", 30, me);
                	return 1;
        	}
       		else
        		return notify_fail("������ȥ��ʯ�ף��۵���ͷ�󺹡�\n");
	}
	return 0;
}

void close_door()
{
	object room = load_object(__DIR__"secret_path1");

	if( !query("secret_trigger") ) return;

	message("vision", "����һ�������������ع����ˣ�һ���ָֻ�����ǰ�����ӡ�\n", this_object() );
	delete("exits/down");
	room->delete("exits/up");
	tell_room(room, "����һ�������������ع����ˡ�\n");
	delete("secret_trigger");
}




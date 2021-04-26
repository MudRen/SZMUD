// Code of ShenZhou
// duguan1.c �ù�̨
// Shan: 96/06/22

#include <ansi.h>

inherit ROOM;
string long_desc();

void create()
{
        set("short", "�ù�̨");
        set("long", (: long_desc :));
//	set("long", @LONG
//�����ǿ��ճ����ƺ�����⡢���֮�ء�̨���������ɣ������޵ף�����
//���ڡ���Ŀ��������������Ĵ�Сѩɽ��������Ŀ��
//LONG
//	);
	set("exits", ([
		"north" : __DIR__"huazang",
		"west" : __DIR__"duguang2",
	]));

        set("objects", ([
                "/kungfu/class/emei/bei.c" :1,
        ]));

        set("no_clean_up", 0);
//        set("outdoors", "emei" );

	setup();
//	replace_program(ROOM);

}

string long_desc()
{
        int t;  // time of the day in minutes
	mixed local;
        string desc;

        desc  = "�����ǿ��ճ����ƺ�����⡢���֮�ء�̨���������ɣ������޵ף�����\n";
        desc += "���ڡ���Ŀ��������������Ĵ�Сѩɽ��������Ŀ��\n";

        local = localtime(time()*60);
        t = local[2]*60 + local[1];

        // morning    5:00am -  7:30am   �ճ�
        // noon      10:30am - 12:00pm   �ƺ�
        // afternoon 12:00am -  2:00pm   ��� 
        // afternoon  2:00pm - 18:00pm   �ƺ�
        // night     19:00pm -  5:00am   ���

        // 05:00 - 11:30
        if ( t >= 400 && t < 600) {
               desc += HIR "    �����Ǹո�����һ����΢�׵Ĺ��ڶ����Ʋ����֣�һ�ֺ����е�������\n" NOR;
               desc += HIR "��ǧ�����ʱ�ڲ���ӳ���³��ֳ�����������\n" NOR;
        }
        // 11:30 - 12:30
        else if (( t >= 630 && t < 720) || ( t >= 840 && t < 1080)) {
                desc += HIC "�������ƺ�������ãã��������Ұ��Զ����ʡ��ƺ��ᵴʱ�����ڽ𶥣���\n" NOR;
                desc += HIC "̤���ƣ�����ƮƮ����֮�У�������Ѹ��ӿ��ʱ�������𶥶�������ǰ������\n" NOR;
                desc += HIC "�����г�������֮�⡣\n" NOR;
        }
        // 12:30 - 20:00
        else if ( t >= 720 && t < 840 ) {
                if( this_player()->query("kar") > random(30) ) {
                desc += HIY "���������羲���ƺ�ƽ�̣������Լ���������㱳��б��������������������\n" NOR;
                desc += HIY "�ɲ�ɫ�⻷��������Լ�����Ӱ�����س�������ɫ�����ϡ����⻷���˶�����\n" NOR;
                desc += HIY "Ӱ�ڻ��С������������ġ�����������������������������������\n" NOR;
                }
                else
                        desc += NATURE_D->outdoor_room_description();
        }
        // 20:00 - 05:00
        else if (( t >= 1260 && t < 1440 ) || ( t >= 0 && t < 300)) {
                desc += HIB "�����������º�����һƬ���������ֳ�һ�㡢�������ɫ�����⣬��������\n" NOR;
                desc += HIB "Խ��Խ�࣬ת�۱㲼��ɽ�ȣ��е�����өƮ�ɣ��е��緱����˸��\n" NOR;

//              desc += HIB "    ������������ơ���������\n" NOR;

}

        else 
                desc += NATURE_D->outdoor_room_description();

        return desc;
}

void init()
{
	add_action("do_tie", "tie");
	add_action("do_tie", "bang");
	add_action("do_climb", "climb");
	add_action("do_climb", "pa");
	add_action("do_jump", "jump");
}

int do_jump(string arg)
{
        object me = this_player();

        int t; 
        mixed local;

        local = localtime(time()*60);
        t = local[2]*60 + local[1];

        if ( !arg || arg == "" ) return 0;

        if ( arg == "cliff" ) {
                if ( (t >= 720 && t < 840) && (me->query_temp("seen_fo")>0) 
                && (me->query("kar") > random(30) ) ) {
	                me->delete_temp("seen_fo");
			message_vision("$N�������������¡�\n", me);
			call_out("to_pool", 1, me);
	                return 1;
                }
                else {
			message_vision("$N�������������¡�\n", me);
			call_out("to_cliff", 1, me);
	                return 1;
	        }
		return 0;
	}
	return 0;
}

int do_tie(string arg)
{
	object me = this_player();

        if ( !arg || arg == "" ) return 0;

	if ( arg == "tree" ) {
		if ( !present("sheng zi", me) )
			write("����ʲô����������\n");
		else {
			message_vision("$N��������ϸ��������������á�\n", me);
			me->set_temp("tied", 1);
		}
		return 1;
	}
	return 0;
}

int do_climb(string arg)
{
	object me = this_player();

	if ( arg && arg != "down" )
		return notify_fail("ʲô��\n");

	if ( !me->query_temp("tied") ){
	    	message_vision("$N����������������Ȼһ��ʧ�֣�ֱˤ����ȥ��\n", me);
		call_out("to_cliff", 1, me);
	    	return 1;
	}
		
	message_vision("$N�������ӿ�ʼ��������\n", me);
	tell_object(me, "�����������ƣ�ʲôҲ�����塣\n");
//	me->move(__DIR__"clifftree2");
	call_out("climb_up", 1);

	return 1;
}

int destroy_corpse()
{
	object obj, room;

	if ( !( room = find_object(__DIR__"cliff") ) )
                room = load_object(__DIR__"cliff");

	if ( obj = present("corpse", room) ) destruct(obj);

	return 1;
}

int climb_up()
{
        object me = this_player();

	tell_object(me, "������������һ������������Ӳ�������ֻ����������\n");
	me->move(__DIR__"duguang1");
	message("vision", me->name()+"����һ�������ͷ�󺹵��������ˡ�\n", environment(me), ({me}) );
	me->add("jingli",-50);
	return 1;

}

int valid_leave(object me, string dir)
{
	if ( me->query_temp("tied") && (dir == "north" || dir == "west"))
		me->delete_temp("tied");
		me->delete_temp("seen_fo");

	return ::valid_leave(me, dir);
}

#include "/d/emei/cliff.h"

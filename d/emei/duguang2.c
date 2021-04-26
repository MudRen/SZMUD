// Code of ShenZhou
// duguang2.c �ù�̨������
// Shan: 96/06/22

#include <ansi.h>

inherit ROOM;
string long_desc();

void create()
{
        set("short", "�ù�̨������");
        set("long", (: long_desc :));

	set("exits", ([
		"enter" : __DIR__"woyun",
		"east" : __DIR__"duguang1",
	]));

        set("item_desc", ([
                "cliff": "�������¸���ƮƮ������ף��㲻�����˸����¡�\n",
        ])  ) ;

        set("no_clean_up", 0);
       set("fjing", 1);
	setup();
}

string long_desc()
{
	object me = this_player();

        int t;  // time of the day in minutes
	mixed local;
        string desc;

        desc  = "�������ֳ����������ǿ��ճ����ƺ�����⡢���֮�ء�̨���������ɣ�\n";
        desc += "�����޵ף��������ڡ���Ŀ��������������Ĵ�Сѩɽ��������Ŀ����Ϊ����\n";
        desc += "�������࣬�������棬���������ã�������������Ͷ���ƺ��������������\n";

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
                desc += MAG "����������һ��ʹ������ĳ������������㲻����Ҫ�ڴ�Ͷ���ƺ�����������\n" NOR;
                desc += MAG "�����ۣ�������ӡ�\n" NOR;
		me->set_temp("seen_fo",1);
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
	add_action("do_pull", "pull");
	add_action("do_push", "tui");
	add_action("do_push", "push");
}

int do_jump(string arg)
{
        object me = this_player();

        int t; 
        mixed local;

        local = localtime(time()*60);
        t = local[2]*60 + local[1];

        if ( !arg || arg == "" ) return 0;

	if(me->query_encumbrance() * 10 / me->query_max_encumbrance() > 10/100)
        return notify_fail("�����̫�ණ����������ȥ��\n");
        if ( arg == "cliff" ) {
		message_vision("$N�������������¡�\n", me);
		remove_action("do_jump", "jump");
                if ( (t >= 720 && t < 840) && (me->query_temp("seen_fo")>0)) {
	                me->delete_temp("seen_fo");
                        if (me->query("kar") > 10+random(20) ) {
//Emei dizi will have a better chance, because they need to learn from zhou.
//�𷨶��ö࣬�����Ե
				if ( (me->query_skill("mahayana", 1) > 90+random(20))
					|| (me->query_str() > 20+random(10) 
						&& me->query("dex") < 18
						&& me->query("con") > 18 
						&& me->query("int") < 25) 
					|| (random(100) == 1) ){
//require a low int here. ɵ����ɵ����
					call_out("to_branch2", 1, me);
		                	return 1;
                        	}
			}
			switch( random(2) ) {
			case 0:
				call_out("to_branch1", 1, me);
				break;
			case 1:
				call_out("to_pool", 1, me);
				break;
			}
	                return 1;
                }
                else {
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
//	me->move(__DIR__"clifftree1");
	call_out("climb_up", 2);

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

	tell_object(me, "����������һ������������Ӳ�������ֻ����������\n");
	me->move(__DIR__"duguang2");
	message("vision", me->name()+"����һ�������ͷ�󺹵��������ˡ�\n", environment(me), ({me}) );
	tell_object(me, "������������������ȥ�ˡ�\n");
	me->receive_damage("jingli", 20, "��ɽ������");
	return 1;

}

int do_pull(string str)
{
        object ob, room;
	object me = this_player();
        int i;

        if (!str) return notify_fail("������ʲô��\n");
        ob = LOGIN_D->find_body(str);
        if (!ob) return notify_fail("����˺���������ɣ�\n");

	room = environment(ob);
//	if ( (string)file_name(room) != __DIR__"clifftree1" )
	if ( (string)room->query("short") != "�޺���" )
        	return notify_fail("����˺������������µ����ϰɣ�\n");
	
	if ( (me->query_str() < ob->query_str()) || (me->query("jingli") < ob->query("jingli")) )
		return notify_fail("��û��ô�����������������\n");

        tell_room(environment(ob),CYN"\n��Ȼ���˴��������Ϸ���һ�����ӣ�"+
        (string)ob->query("name")+"ץס���ӣ�������������ȥ��\n"NOR, ob);
        tell_object(ob,CYN"\n��Ȼ���˴��������Ϸ���һ������������ץס���ӣ�����������ȥ��\n"NOR);
        ob->move(environment(me));
        tell_object(me, CYN"\n��ʹ����"+(string)ob->query("name")+"��������������������\n"NOR);
        tell_object(ob,CYN"�㿴��"+(string)me->query("name")+
        "����������һͷ����������������\n"NOR);
        tell_room(environment(ob),CYN + (string)me->query("name")+"����һ�������ӣ�"
		+"ʹ����" + (string)ob->query("name")+"����������������\n"NOR,({me,ob}));
	me->add("jingli", -(int)ob->query("jingli"));
        return 1;
}


int valid_leave(object me, string dir)
{
	if ( me->query_temp("tied") && (dir == "enter" || dir == "east"))
		me->delete_temp("tied");
		me->delete_temp("seen_fo");

	if ( me->query_temp("exit") && (dir == "enter" || dir == "east"))
                me->delete_temp("exit");

	return ::valid_leave(me, dir);
}


int do_push(string who)
{
        object victim, room;
	object me = this_player();
        int i;

        victim = present(who, environment(me));
        if (!who ) return notify_fail("������ʲô��\n");
        if (!victim ) return notify_fail("����˲�������ɡ�\n");
        if (victim==me) return notify_fail("�Լ����ɡ�\n");

	message_vision("$N���˲�ע�⣬�͵�����ȥ��$n��\n\n", me, victim);

	if ( (me->query_str() < victim->query_str()) || (me->query("jingli") < victim->query("jingli")) ) {
		message_vision("$N����һ�£�û�ƶ�������ˤ���ˣ�ͷײ��һ���ʯ�ϡ�\n", me);		
		me->unconcious();
		return 1;
	}

	else {
		message_vision("$nһ��ûվ�ȣ�ֱ����ȥ��\n", me, victim);		
		call_out("to_pool", 1, victim);
        	return 1;
	}
}
#include "/d/emei/cliff.h"

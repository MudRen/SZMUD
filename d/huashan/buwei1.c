// Code of ShenZhou
// square.c

#include <ansi.h>
inherit ROOM;
string day_event() {return NATURE_D->outdoor_room_event();}

void create()
{
	set("short", "����");
	set("long", @LONG
���ǻ�ɽ��������Ⱥ�ľ�����������Ϊ�������˴���ǰ�������Ϲ���
�������á������Ҷ���кܿ���ȴûʲô���裬��ǽ�������ѽ��Σ�
����������Ⱥ���¡���ͽ�ĵط����������Ǹ���԰�����������м�ƫ����
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
	    "north" : __DIR__"square",
	    "south" : __DIR__"huayuan",
	    "east" : __DIR__"pianting", 
	]));

	set("objects", ([ 
	    CLASS_D("huashan") + "/buqun" : 1,
	]));

	set("no_clean_up", 0);

	set("valid_startroom",1);

	set("cost", 1);
	setup();

//	"/clone/board/huashan_b"->foo();
}

void init()
{
	object ob, me = this_player();
	int level;

	//destruct duplicated Yue, Ryu.
	if( objectp( ob = present("yue buqun 2", this_object()) ) )
	destruct(ob);

/*
	if ( mapp(me->query("family")) && me->query("family/family_name") == "��ɽ��" ) {
	   if ( me->query_skill("buddhism",1) > 0 && me->query_skill("ziyin-yin",1) < 1 ) {
		level = me->query_skill("buddhism", 1);
		me->delete_skill("buddhism");
		me->set_skill("ziyin-yin", level+1);
		tell_object(this_player(),HIR"\n�����ķ����Զ�����Ϊ�������\n"NOR);
	   }

	   if ( me->query_skill("taoism",1) > 0 && me->query_skill("zhengqi-jue", 1) < 1 ) {
		level = me->query_skill("taoism",1);
		me->delete_skill("taoism");
		me->set_skill("zhengqi-jue", level+1);
		tell_object(this_player(),HIR"��ѧ�ķ����Զ�����Ϊ��������\n\n"NOR);
	   }
	}
*/
	if ( me->query_temp("marks/��") ) {
		me->delete_temp("marks/��");
	}

	if ( me->query("yue") ) {
		me->set("huashan/yue", 1);
		me->delete("yue");
	}

	if ( me->query("ning") ) {
		me->set("huashan/ning", 1);
		me->delete("ning");
	}

	if ( me->query("feilong") ) {
		me->set("huashan/feilong", 1);
		me->delete("feilong");
	}

//      add_action("do_jump","jump");
	add_action("do_kill","kill");
	add_action("do_hit","hit");
	add_action("do_throw","throw");
}

int do_kill(string arg)
{
	object ob, ob1, me = this_player();

	if ( !arg || arg == "" ) return 0;

	if ( !ob=present(arg, environment(me)) ) return 0;

	if ( ob->query("family/family_name") == "��ɽ��" && me->query("family/family_name") != "��ɽ��" ) {
	   message_vision("$n����$N�ȵ�����"+RANK_D->query_rude(ob)+"�����ղ������������һ��\n", ob, me);    
	
	   if ( ob1=present("yue buqun", environment(me)) ) {
		message_vision("$Nһ����Ц���󵨿�ͽ�������ڻ�ɽ������ɱ�ˣ����һ�ɽ�ɺ��۸�ô��\n", ob1);
		ob1->kill_ob(me);
		return 1;
	   }

	   return 0;
	}
	else if ( ob->query("family/family_name") == "��ɽ��" && ob->query("id") != "yue buqun" 
	&& ob->query("id") != "ning zhongze" && me->query("family/family_name") == "��ɽ��" ) {
	   message_vision("$n����$N�ȵ�����"+RANK_D->query_rude(ob)+"�����ղ������������һ��\n", ob, me);

	   if ( ob1=present("yue buqun", environment(me)) ) {
		message_vision("$N���ô������Խ��Խ�г�Ϣ�ˣ��Լ�ͬ�ž������ɱ�����Ҷ���˼����ȥ��ڣ�\n", ob1);
		return 1;
	   }

	   return 0;
	}

	return 0;
}

int do_hit(string arg)
{
	object ob, ob1, me = this_player();

	if ( !arg || arg == "" ) return 0;

	if ( !ob=present(arg, environment(me)) ) return 0;

	if ( ob->query("family/family_name") == "��ɽ��" && me->query("family/family_name") != "��ɽ��" ) {
	   message_vision("$n����$N���һ�������У�\n",ob, me);

	   if ( ob1=present("yue buqun", environment(me)) ) {
		message_vision("$Nһ����Ц���󵨿�ͽ�������ڻ�ɽ��͵Ϯ���ˣ����һ�ɽ�ɺ��۸�ô��\n", ob1);
		ob1->kill_ob(me);
		return 1;
	   }

	   return 0;
	}
	else if ( ob->query("family/family_name") == "��ɽ��" && ob->query("id") != "yue buqun"
	&& ob->query("id") != "ning zhongze" && me->query("family/family_name") == "��ɽ��" ) {
	   message_vision("$n����$N�ȵ�����"+RANK_D->query_rude(ob)+"�����ղ������������һ��\n", ob, me);

	   if ( ob1=present("yue buqun", environment(me)) ) {
		message_vision("$N���ô������Խ��Խ�г�Ϣ�ˣ��Լ�ͬ�ž������ɱ�����Ҷ���˼����ȥ��ڣ�\n", ob1);
		return 1;
	   }

	   return 0;
	}

	return 0;
}

int do_throw(string arg)
{
	object victim, ob1, ob, me = this_player();
	string what, who;

	if( !arg
        ||      sscanf(arg, "%s at %s", what, who)!=2)
                return notify_fail("�����ʽ: throw <��Ʒ> at <ĳ��>��\n");

	ob = present(what, me);
        if( !ob ) ob = present(arg, environment(me));
	if( !ob ) return notify_fail("��Ҫ��ʲô��\n");

        if (ob->query("no_drop"))
                return notify_fail("������������뿪�㡣\n");

        if (!(victim = present(who, environment(me))))
                return notify_fail("����û�����Ŀ�ꡣ\n");

        if (!victim)
                return notify_fail("���ﲢ�޴��ˣ�\n");

        if (!living(victim))
                return notify_fail("�ⲻ�ǻ��\n");
	
	if ( victim->query("family/family_name") == "��ɽ��" && me->query("family/family_name") != "��ɽ��" ) {
	   message_vision("$n����$N���һ�������У�\n",victim, me);

	   if ( ob1=present("yue buqun", environment(me)) ) {
		message_vision("$Nһ����Ц���󵨿�ͽ�������ڻ�ɽ��͵Ϯ���ˣ����һ�ɽ�ɺ��۸�ô��\n", ob1);
		ob1->kill_ob(me);
		return 1;
	   }

	   return 0;
	}
	else if ( victim->query("family/family_name") == "��ɽ��" && victim->query("id") != "yue buqun"
	&& victim->query("id") != "ning zhongze" && me->query("family/family_name") == "��ɽ��" ) {
	   message_vision("$n����$N�ȵ�����"+RANK_D->query_rude(ob)+"�����ղ������������һ��\n", victim, me);

	   if ( ob1=present("yue buqun", environment(me)) ) {
		message_vision("$N���ô������Խ��Խ�г�Ϣ�ˣ��Լ�ͬ�ž������ɱ�����Ҷ���˼����ȥ��ڣ�\n", ob1);
		return 1;
	   }

	   return 0;
	}

	return 0;
}

int do_jump(string arg)
{
	object me = this_player();

	if ( !arg || arg == "" ) return 0;

	if ( arg == "bian" || arg == "board" ) {
	   if ( me->query_skill("dodge") > 50 ) {
	      write("����Ŵ��һ���������������Ҷ\n");
	      me->move(__DIR__"bian");
	   }
	   else {
	      write("����Ŵ��һ�������������������Ҷ�����Ṧ���ã�δ����Ը��\n");
	   }

	   return 1;
	}
	
	return 0;
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");
/*
	if ( (!myfam || myfam["family_name"] != "��ɽ��") && dir != "north" ) {
	   if ( present("yue buqun", environment(me)) )
		return notify_fail("����Ⱥ����˵�����Ǳ����صأ����˲������׳��룡\n");

	   if ( present("ning zhongze", environment(me)) )
		return notify_fail("��������������ǰ˵����Ǹ�����˲������׳��뱾���صأ�\n");
	}

	if ( dir == "north" && (day_event() == "event_night" || day_event() == "event_midnight") )
        	return notify_fail("��ɽ������ʱ��Ȼ�رգ�����ʱ����ͨ�У�\n");
*/

	return ::valid_leave(me, dir);
}

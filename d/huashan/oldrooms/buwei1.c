// Code of ShenZhou
// square.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���ǻ�ɽ��������Ⱥ�ľ�����������Ϊ�������˴���ǰ�������Ϲ���
�������á������Ҷ���кܿ���ȴûʲô���裬��ǽ�������ѽ��Σ�
����������Ⱥ���¡���ͽ�ĵط������������Ҽ������������������м���
Ժ���������ǳ�����
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
	    "north" : __DIR__"square",
	    "south" : __DIR__"zoulang1",
	    "east" : __DIR__"donglang",
	    "west" : __DIR__"xilang", 
	]));

	set("objects", ([ 
	    CLASS_D("huashan") + "/buqun" : 1,
	    CLASS_D("huashan") + "/zhongze" : 1,
	]));

	set("no_clean_up", 0);

	set("valid_startroom",1);

	set("cost", 1);
	setup();

	"/clone/board/huashan_b"->foo();
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
	if ( this_player()->query_temp("marks/��") ) {
		this_player()->delete_temp("marks/��");
	}

	add_action("do_jump","jump");
	add_action("do_kill","kill");
	add_action("do_hit","hit");
}

int do_kill(string arg)
{
	object ob, ob1, ob2, me = this_player();

	if ( !arg || arg == "" ) return 0;

	if ( !ob=present(arg, environment(me)) ) return 0;

	if ( ob->query("family/family_name") == "��ɽ��" && me->query("family/family_name") != "��ɽ��" ) {
	   message_vision("$n����$N�ȵ�����"+RANK_D->query_rude(ob)+"�����ղ������������һ��\n", ob, me);    
	
	   if ( ob1=present("yue buqun", environment(me)) ) {
		message_vision("$Nһ����Ц���󵨿�ͽ�������ڻ�ɽ������ɱ�ˣ����һ�ɽ�ɺ��۸�ô��\n", ob1);
		ob1->kill_ob(me);
	   }

	   if ( ob2=present("ning zhongze", environment(me)) ) {
		message_vision("$Nŭ��������д��������ڻ�ɽ����Ұ����ͼ����ɱ�ˣ�\n", ob2);
		ob2->kill_ob(me);
	   }

	   if ( !ob1 && !ob2 ) return 0;

	   return 1;
	}
	else if ( ob->query("family/family_name") == "��ɽ��" && ob->query("id") != "yue buqun" 
	&& ob->query("id") != "ning zhongze" && me->query("family/family_name") == "��ɽ��" ) {
	   message_vision("$n����$N�ȵ�����"+RANK_D->query_rude(ob)+"�����ղ������������һ��\n", ob, me);

	   if ( ob1=present("yue buqun", environment(me)) ) {
		message_vision("$N���ô������Խ��Խ�г�Ϣ�ˣ��Լ�ͬ�ž������ɱ�����Ҷ���˼����ȥ��ڣ�\n", ob1);
		return 1;
	   }

	   if ( ob2=present("ning zhongze", environment(me)) ) {
		message_vision("$N����������Լ�ͬ�ž������ɱ�������ҵ�˼����ȥ�ú���ڷ�ʡ��\n", ob2);
		return 1;
	   }

	   return 0;
	}

	return 0;
}

int do_hit(string arg)
{
	object ob, ob1, ob2, me = this_player();

	if ( !arg || arg == "" ) return 0;

	if ( !ob=present(arg, environment(me)) ) return 0;

	if ( ob->query("family/family_name") == "��ɽ��" && me->query("family/family_name") != "��ɽ��" ) {
	   message_vision("$n����$N���һ�������У�\n",ob, me);

	   if ( ob1=present("yue buqun", environment(me)) ) {
		message_vision("$Nһ����Ц���󵨿�ͽ�������ڻ�ɽ��͵Ϯ���ˣ����һ�ɽ�ɺ��۸�ô��\n", ob1);
		ob1->kill_ob(me);
	   }

	   if ( ob2=present("ning zhongze", environment(me)) ) {
		message_vision("$Nŭ��������д��������ڻ�ɽ����Ұ����ͼ͵Ϯ���ˣ�\n", ob2);
		ob2->kill_ob(me);
	   }

	   if ( !ob1 && !ob2 ) return 0;

	   return 1;
	}
	else if ( ob->query("family/family_name") == "��ɽ��" && ob->query("id") != "yue buqun"
	&& ob->query("id") != "ning zhongze" && me->query("family/family_name") == "��ɽ��" ) {
	   message_vision("$n����$N�ȵ�����"+RANK_D->query_rude(ob)+"�����ղ������������һ��\n", ob, me);

	   if ( ob1=present("yue buqun", environment(me)) ) {
		message_vision("$N���ô������Խ��Խ�г�Ϣ�ˣ��Լ�ͬ�ž������ɱ�����Ҷ���˼����ȥ��ڣ�\n", ob1);
		return 1;
	   }

	   if ( ob2=present("ning zhongze", environment(me)) ) {
		message_vision("$N����������Լ�ͬ�ž������ɱ�������ҵ�˼����ȥ�ú���ڷ�ʡ��\n", ob2);
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

    	if ( (!myfam || myfam["family_name"] != "��ɽ��") && dir != "north" ) {
    	   if ( present("yue buqun", environment(me)) )
		return notify_fail("����Ⱥ����˵�����Ǳ����صأ����˲������׳��룡\n");

    	   if ( present("ning zhongze", environment(me)) )
		return notify_fail("��������������ǰ˵����Ǹ�����˲������׳��뱾���صأ�\n");
	}

    	return ::valid_leave(me, dir);
}
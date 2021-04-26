// Code of ShenZhou
// ���߶�
// qfy 16/10/1996

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "ɽ��ʯ��");
	set("long", @LONG
��ɽ��ʯ����ͷ������ģ���ôҲ����������֪�кιŹ֡�    
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
		"out" :  __DIR__"jinshe1",
	]));

	set("zhui", 1);
	set("jian", 1);
	set("box1", 1);
	set("box2", 1);
	set("book", 1);
	set("con", 0);
	set("skeleton", 1);
	set("sword", 28+random(10));

	set("cost", 0);
	setup();
}

void init()
{
	object book, me=this_player();

	if ( query("con") == 2 ) {
		environment(me)->set("long",
                "ʯ�����м��ٷ��������̳ɵļ�ª���Σ�ÿ���˾�����ͬ������Ͷ��\n"
		"���������䡣ͼ�ξ�����ʯ���Ͽ��š��ر�������������Ե������������\n"
		"����ĪԹ��ʮ�����֡�\n");
	}
	else if ( query("con") == 1 ) {
		environment(me)->set("long", 
                "ʯ�����м��ٷ��������̳ɵļ�ª���Σ�ÿ���˾�����ͬ������Ͷ��\n"
		"���������䡣ͼ�ξ�����ʯ���Ͽ��š��ر�������������Ե������������\n"
		"����ĪԹ��ʮ�����֡������и�����͹����ʯ��֮�ϣ�ֱ������(sword)��\n");
	}
	else {
		environment(me)->set("long",
		"��ɽ��ʯ����ͷ������ģ���ôҲ����������֪�кιŹ֡�\n");
	}

	if ( me->query("jinshe") && query("book") >= 1 && !present("jinshe miji", me) ) {
		book = new(__DIR__"obj/jinshe_book2");
		if (!book) return 0;
		book->move(me);
		CHANNEL_D->do_channel(me, "rumor", sprintf("%sŪ���˽����ܼ���", me->query("name")));
		tell_object(me, "���������ܼ���ϸ�պá�\n");
		add("skeleton", -1);
		add("box1", -1);
		add("box2", -1);
		add("book", -1);
	}

	if ( query("con") != 0 ) {
		set("item_desc",([
			"wall" : "ʯ���Ͽ��ż�ª���Σ��������㣬���������书��\n",
		]));
	}

	add_action("do_use", "use");
	add_action("do_dig", "dig");
	add_action("do_lingwu", "lingwu");
	add_action("do_bury", "bury");
	add_action("do_pull", "pull");
}

int do_lingwu(string arg)
{
	object ob, me = this_player();
	int check, level;

	if( !arg || arg == "" ) return 0;

	if ( query("con") == 0 ) return 0;


	if ( arg == "zhangfa" ) {
		if( !ob=present("jinshe miji", me) || !ob->query("iden") ) 
			return notify_fail("ʲô��\n");
	////////////////////////////////////////////////////////////////////////
	//add by wzfeng

	if ((int)me->query("jingli") < 100)
		return notify_fail("��ľ��������ж������ؼ���\n");
	/////////////////////////////////////////////////////////////////////////////


		level = (int)me->query_skill("youshen-zhang", 1);
		check = level*level*level;

		if ( level < 100 ) return notify_fail("����������Ƶȼ��������޷�����������������ơ�\n");
		if ( check > (int)me->query("shen") * 10 ) 
			return notify_fail("������̫�٣���������а���Ԧѧϰ�����ؼ��Ϲ�����ʽ���ķ���\n");
		
		if ( check < (int)me->query("combat_exp")*10 ) {
			me->improve_skill("youshen-zhang", me->query("int"));
			tell_object(me, "��Ľ��������ƽ����ˡ�\n");
			me->receive_damage("jing", 60, "�����ʴ�����"); 
			return 1;
		}
		else {
			me->receive_damage("jing", 60, "�����ʴ�����");
			return notify_fail("����ϸ�ش�Ħ���ã�����Ȼ����������������ơ�\n");
		}
	}

	if ( arg == "jianfa" ) {
		if( !ob=present("jinshe miji", me) || !ob->query("iden") ) 
			return notify_fail("ʲô��\n");

		level = (int)me->query_skill("jinshe-jianfa", 1);
		check = level*level*level;

		if ( level < 100 ) return notify_fail("����߽����ȼ��������޷�����������������ơ�\n");
		if ( check > (int)me->query("shen") * 10 ) 
			return notify_fail("������̫�٣���������а���Ԧѧϰ�����ؼ��Ϲ�����ʽ���ķ���\n");

		if ( check < (int)me->query("combat_exp")*10 ) {
			me->improve_skill("jinshe-jianfa", me->query("int"));
			tell_object(me, "��Ľ��߽��������ˡ�\n");
			me->receive_damage("jing", 60, "�����ʴ�����");
			return 1;
		}
		else {
			me->receive_damage("jing", 60, "�����ʴ�����");
			return notify_fail("����ϸ�ش�Ħ���ã�����Ȼ����������߽�����\n");
		}
	}

	if ( arg == "zhuifa" ) {
		if( !ob=present("jinshe miji", me) || !ob->query("iden") ) 
			return notify_fail("ʲô��\n");

		level = (int)me->query_skill("jinshe-zhuifa", 1);
		check = level*level*level;

		if ( level < 100 ) return notify_fail("�����׶���ȼ��������޷�����������������ơ�\n");
		if ( check > (int)me->query("shen") * 10 ) 
			return notify_fail("������̫�٣���������а���Ԧѧϰ�����ؼ��Ϲ�����ʽ���ķ���\n");

		if ( check < (int)me->query("combat_exp")*10 ) {
                        me->improve_skill("jinshe-zhuifa", me->query("int"));  
			tell_object(me, "��Ľ���׶�������ˡ�\n");
			me->receive_damage("jing", 60, "�����ʴ�����");
			return 1;
		}
		else {
			me->receive_damage("jing", 60, "�����ʴ�����");
			return notify_fail("����ϸ�ش�Ħ���ã�����Ȼ�����������׶����\n");
		}
	}
}

int do_use(string arg)
{
    object ob, me = this_player();
       
    if( !arg || arg=="" ) return 0;

    if (!present("fire", me))  return 0;

    if ( arg=="fire" && query("con") != 0 )
	return notify_fail("�������Ż������ģ�\n");

    else if( arg=="fire" ) {
	if ( query("skeleton") >= 1 && !present("skeleton", environment(me)) && !me->query("jinshe") ) {
		message_vision("$N���Ż��ۣ�����΢���Ĺ���һ�գ���ʱ����һ����\n", me);
		message_vision("ֻ������ʯ����б����һ�����ùǣ������·��������߰˳ɣ�\n", me);
		message_vision("�����ù���Ȼ�пɼ����Ǹ����Ρ�\n", me);
		tell_object(me, "�㿴���⸱���Σ�һ��������������\n");
	}
	else message_vision("$N���Ż��ۣ�����΢���Ĺ���һ�ա�\n", me);

	set("con", query("last"));

	if ( query("con") <= 1 ) {
		environment(me)->set("long", 
		"ʯ�����м��ٷ��������̳ɵļ�ª���Σ�ÿ���˾�����ͬ������Ͷ��\n"
		"���������䡣ͼ�ξ�����ʯ���Ͽ��š��ر�������������Ե������������\n"
		"����ĪԹ��ʮ�����֡������и�����͹����ʯ��֮�ϣ�ֱ������(sword)��\n"); 

		set("item_desc",([
			"wall" : "ʯ���Ͽ��ż�ª���Σ��������㣬���������书��\n",
		]));

		set("con", 1);
	}
	else {
		environment(me)->set("long",
		"ʯ�����м��ٷ��������̳ɵļ�ª���Σ�ÿ���˾�����ͬ������Ͷ��\n"
		"���������䡣ͼ�ξ�����ʯ���Ͽ��š��ر�������������Ե������������\n"
		"����ĪԹ��ʮ�����֡�\n");
		set("con", 2);
	}

	if ( query("zhui") >= 1 ) {
		ob = new(__DIR__"obj/jinshe-zhui");
		ob->move(environment(me));
		add("zhui", -1);
	}

	if ( query("skeleton") >= 1 ) {
		ob = new(__DIR__"obj/skeleton");
		ob->move(environment(me));
		add("skeleton", -1);
	}       

	me->set_temp("visited", 1);

	return 1;
    }
    else return 0;      
}

int do_pull(string arg)
{
	object ob, obj, me=this_player();

	if ( !arg || arg != "sword" ) return 0;

	if ( present("jinshe jian", me) || me->query_temp("marks/jinshe") )
		return notify_fail("�㲻�����˽���\n");

	if ( present("jinshe jian", environment(me)) )
		return notify_fail("���ϲ����н���\n");
	
	if (me->query("neili") < 500)
		return notify_fail("������������\n");

	ob=new("/clone/unique/jinshe-jian");
	if (ob && me->query_kar() > query("sword")) {
		message_vision("$N������ס������Ǳ����������Ȼ����һ�Ρ�\n", me);

		if( me->query("max_neili") >= 300 && me->query("neili") >= 200 ) {
			message_vision("ֻ�����͵�һ����$N�������˳�����ͻȻ��ʯ����ֻ�к������ˣ�\n", me);
			add("jian", -1);
			ob->move(me);
	CHANNEL_D->do_channel(me, "rumor", sprintf("%sŪ����һ�����߽���", me->query("name")));
			me->add("neili", -500);
			me->set_temp("marks/jinshe", 1);
			
			set("con", 2);
			environment(me)->set("long",
			"ʯ�����м��ٷ��������̳ɵļ�ª���Σ�ÿ���˾�����ͬ����������\n"
			"���������䡣ͼ�ξ�����ʯ���Ͽ��š��ر�������������Ե������������\n"
			"����ĪԹ��ʮ�����֡�\n");
		}
		else {
			message_vision("$Nʹ������ʼ�հβ���������ԭ���������㡣\n", me);
			me->set("neili", 0);
			destruct(ob);
		}
	
		return 1;
	}
	else {
	obj=new("/clone/weapon/gangjian");
	obj->set("name", "�ϵ���" + obj->query("name"));
	obj->set("value", 0);
	obj->set("weapon_prop", 0);
	obj->move(me);
	me->set_temp("marks/jinshe", 1);
	me->add("neili", -500);
	me->start_busy(2);
	if(ob) destruct(ob);
	return notify_fail("ವ�һ�������һ���ֽ��۶��˰γ�����\n");
	}
}

int do_dig()
{
	object ob, me = this_player();

	if ( !present("tie qiao", me) )
		return notify_fail("����ʲô���ڰ���\n");

	if ( query("con") == 0 )
		return notify_fail("��ô���㿴�õ�ô��\n");

	if ( !me->query_temp("weapon") || me->query_temp("weapon")->name() != "����" )
		return notify_fail("���²�����������ô�ڰ���\n");
	
	if ( !me->query_temp("dig") ) message_vision("$N�������������ڵ����וּ�����������\n", me);
	else message_vision("$N��������ھ���������ϼᣬ��ʱʱ����ɽʯ���ھ��Ϊ������\n", me);

	if ( !me->query_temp("dig") && query("box1") >= 1 && random(10) == 5 ) {
		message_vision("��Ȼ����һ������������һ��������$N�ƽ�����һ����ԭ����һֻ���С�\n", me);
		add("box1", -1);
		ob = new(__DIR__"obj/box1");
		ob->move(environment(me));
		me->set_temp("dig", 1);
		me->add("jingli", -20);
	}
	else if ( !me->query_temp("dig") ) {
		message_vision("���˲��ã�$N����һ���󶴡�\n", me);
		me->add("jingli", -20);
	}
	else if ( me->query_temp("dig") && me->query_temp("read1") && me->query_temp("read2")
	&& me->query_temp("read3") && query("box2") >= 1 && random(10) == 1 
	&& (present("skeleton", environment(me)) || present("skeleton", me)) ) {
		message_vision("$N�۳���һ��󺹣����������ߣ�����һ��������������һ���Ȼ����һֻ���С�\n", me);
		add("box2", -1);
		ob = new(__DIR__"obj/box2");
		ob->move(environment(me));
		me->add("jingli", -20);
		me->set("jinshe", 1);
	}
	else {
		message_vision("$N�۳���һ��󺹣�����һ�������ִ�Ķ���\n", me);
		me->add("jingli", -50);
	}

	return 1;
}

int do_bury(string arg)
{
	object ob, me=this_player();

	if ( !arg || arg == "" ) return 0;

	if ( arg != "skeleton" && arg != "kulou" && arg != "gu" ) return 0;

	if ( !objectp(ob = present(arg, environment(me))) 
	&& !objectp(ob = present(arg, me)) ) return 0;

	if ( !me->query_temp("dig") )
		return notify_fail("���뽫������������ѽ��\n");

	message_vision("$N�Ѻ������ΰ���Ѩ�У��������������˼��ݡ�\n", me);
	me->set_temp("buried", 1);
	destruct(ob);

	return 1;
}

int valid_leave(object me, string dir)
{
	object ob1, ob2;

	environment(me)->set("last", environment(me)->query("con"));
	environment(me)->set("con", 0);
	me->delete_temp("dig");
	me->delete_temp("read1");
	me->delete_temp("read2");
	me->delete_temp("read3");

	if ( objectp(ob1=present("skeleton", environment(me))) ) {
		add("skeleton", 1);
		destruct(ob1);
	}

	if ( objectp(ob2=present("jinshe zhui", environment(me))) ) {
		add("zhui", 1);
		destruct(ob2);
	}

	return ::valid_leave(me, dir);
}

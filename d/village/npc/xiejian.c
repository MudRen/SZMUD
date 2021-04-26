// Code of ShenZhou
// xiejian.c а������

#include <ansi.h>

inherit NPC;

int waiting(object me);
int checking(object me);
int do_chase(object me);
int do_kill(object me, object dest);
string ask_me();

void create()
{
	set_name("����", ({ "li si", "li" }) );
	set("title", "С���ϰ�");
	set("gender", "����" );
	set("shen_type", -1);
	set("age", 40);
	set("str", 30);
	set("con", 30);
	set("int", 30);
	set("dex", 30);

	set("no_clean_up",1);

	set("long",
		"��������Ц�����С���ϰ壬��Ȼ����ʲô������ȴҲ�������ڡ�\n" );

	set("combat_exp", 200000);
	set("attitude", "peaceful");
	set("chat_chance", 1);
	set("chat_msg", ({
		"����˵��: ��λ�͹٣�������Щʲô������ ?\n",
	}) );

	set("inquiry", ([
	        "а��"   : (: ask_me :),
	        "ɱ��"   : (: ask_me :),
	]) );

	set("max_qi", 700);
	set("max_jing", 400);
	set("neili", 700);
	set("max_neili", 700);
	set("jiali", 50);
	set("shen_type", -1);
	set("env/wimpy", 60);

	set_skill("force", 60); 
	set_skill("ding-force", 60);
	set_skill("unarmed", 80);
	set_skill("ding-unarmed", 80);
	set_skill("sword", 100);
	set_skill("huashan-jianfa", 100);
	set_skill("dodge", 100);
	set_skill("ding-dodge", 100);
	set_skill("parry", 100);

	map_skill("unarmed", "ding-unarmed");
	map_skill("dodge", "ding-dodge");
	map_skill("sword", "huashan-jianfa");
	map_skill("parry", "huashan-jianfa");
        map_skill("force", "ding-force");
	
	setup();
	
	carry_object("d/city/obj/gangjian")->wield();
	carry_object("d/city/obj/cloth")->wear();

	add_money("silver", random(30));
}

void init()
{
	object me, ob;

	me = this_object();
	ob = this_player();

        ::init();

	if( !me->query("waiting_target") && ob->query_temp("fee_paid") ) 
		ob->delete_temp("fee_paid");

        add_action("do_name","ɱ");
	
}

string ask_me()
{
	return "�Ҿ���а�����ģ�����������ʲô����\n";
}

int do_name(string target)
{
	object me, dest, *all;
	int i;
 
	me = this_object();
	all = users();

/*
        if( me->query("sg/spy") )
                return notify_fail("������Ц��һ������������ɱ���˻�Ҫ��ɱ�ְ��æ����\n");
*/

	if(me->query("waiting_target"))
		return notify_fail("���ĺٺ�һЦ����������æ���ģ�������������ɣ�\n");
	
	if( !this_player()->query_temp("fee_paid") ) 
		return notify_fail("����˵�������ܽ�����ʲô�����ɵ��ȸ�Ǯ�ģ�\n");

	if( !target || target==" ") 
		return notify_fail("���Ķ�ݺݵ�˵������������Ǽһ�����֣��ҿ�û�����������ģ�\n");

	for(i=0; i<sizeof(all); i++) 
	{
		if( target == all[i]->name() || target == all[i]->query("id") )
			dest = all[i];
	}
	
	if( !dest )
		return notify_fail("����һ����Ц�������ڲ�����Ϸ�У����������ɡ�\n");
		
	if (dest->is_ghost())
		return notify_fail("���ĺܲ����ˣ����Ѿ��Ǹ������ˣ��㻹�����Ҹ�ʲô��\n");

/*
        if( dest->query("sg/exp") > 1000 )
                return notify_fail("��������һ����˵���������̵������ǲ���\n");
*/

	me->set("waiting_target", dest->query("id"));
	me->set("target_name", target);
	log_file("Playing", sprintf("%s(%s) attempted to hire lisi to kill %s(%s)\n",
			this_player()->query("name"), getuid(this_player()),
			dest->query("name"), dest->query("id")) );
		
	me->set_temp("apply/attack",  100);
	me->set_temp("apply/defense", 100);
	me->set_temp("apply/damage",  50);

	me->set("title", HIR "а��" NOR);
	me->set("long",
		"а�����ģ�ɱ�ְ�ʮ��߼���ʿ֮һ���н���ȾѪ������֮����\n" );

	me->delete("chat_chance");
	me->delete("chat_msg");

	message("vision",
		HIY "���ĺٺٺٵ�ǬЦ�˼�����˵����������������������!\n"NOR,
		environment(), me );

	me->set("pursuer", 1);
	me->set("vendetta/authority", 1);
	me->set("bellicosity", 10000);
	me->set("combat_exp", 200000);

	message_vision("$N���˳�ȥ��\n" NOR, me);

	call_out("do_chase", 1, me);
	
	return 1;
}

int accept_object(object who, object ob)
{
	
	if (ob->query("money_id") && ob->value() >= 3000000 
		&& !this_object()->query("waiting_target")) 
	{
	if ((int)this_player()->query("age") < 16
        || this_player()->query("combat_exp") < 10000){
                tell_object(who, "���������������һ�ۣ���м��˵���������ϵ��¶�����ȥ�����Ǽ���ү��������̸�ɡ�\n");
		return 1;
		}

		tell_object(who, "���ĳ����������ã�ˬ��˵�ɣ���Ҫ�Ұ���ɱ˭��\n");
		tell_object(who, "����룺ɱ Ŀ����������\n");
		who->set_temp("fee_paid",1);
		return 1;
	}
	else if (ob->query("money_id") && ob->value() < 3000000) 
	{
		tell_object(who, "���ĺٺ�һЦ��˵����������ô��Ǯ�� �����ҿ�û�����㰡��\n");
		return 1;
	}

	return 0;
}

int do_chase(object me)
{
	
	object dest;
	dest = find_player(me->query("waiting_target"));
	
	if( !objectp(dest) || !environment(dest) )	
	{
		call_out("waiting", 0, me);
		return 1;
	}
	
	me->move(environment(dest));
	message_vision("$N���˹�����\n" NOR, me);
	me->set_leader(dest);
	command("look " + dest->query("id"));
	
	if ( !environment(me)->query("no_fight"))
	{
		call_out("do_kill", 1, me, dest);
		return 1;
	}
	else
	{
		call_out("waiting", 0, me);
		return 1;
	}

	return 1;
}

int do_kill(object me, object dest)
{

	if( objectp(dest) && present(dest, environment(me))
		 && !environment(me)->query("no_fight"))
	{
		message_vision(HIR "$N��$n˵������˾����������������ȥ���Ƕ����ͣ�"
			+RANK_D->query_rude(dest)+"���������ɣ�\n" NOR, me, dest);
		me->set_leader(dest);
		me->kill_ob(dest);
		dest->fight_ob(me);

		call_out("checking", 0,  me); 	
	}
	else  
		call_out("waiting", 1, me); 	
	
	return 1;
}

int waiting(object me)
{
	object dest;
	dest = find_player(me->query("waiting_target"));
	
	if ( objectp(dest) )
	{
		if (dest->is_ghost())
		{
			me->delete("waiting_target");
			call_out("do_back", 1, me);
			return 1;
		}else if (me->is_fighting() && present(dest, environment(me)))
		{
			call_out("checking", 0, me);
			return 1;
		}else if (living(me) && !environment(dest)->query("no_fight"))
		{
			call_out("do_chase", 0, me);
			return 1;
		}
	}		
	
	remove_call_out("waiting");
	call_out("waiting", 60, me);
    return 1;
}

int checking(object me)
{
	object ob;

	if (me->is_fighting()) 
	{
		call_out("checking", 1, me);
        return 1;
	}

	if( objectp(ob = present("corpse", environment(me)))
		 && ob->query("victim_name") ==	me->query("target_name") )
	{
		me->delete("waiting_target");
		call_out("do_back", 1, me);
        return 1;
	}
	
	call_out("waiting", 0, me);
	return 1;
}

int do_back(object me)
{

	me->move("/d/village/shop");
	message("vision", "�������˽��������������ϵĳ������ѽ��ϵ�Ѫ��Ĩ��Ǭ����\n"
		"������һЦ˵��������ү���ӣ�����ɵ�Ǭ�����䣬�����Ժ���ʲô�»��������ҡ�\n", 
		environment(), me );

	me->set("title", "С���ϰ�");
	me->set("long",
		"��������Ц�����С���ϰ壬��Ȼ����ʲô������ȴҲ�������ڡ�\n" );
	
	me->set_leader(0);
	me->set("chat_chance", 1);
	me->set("chat_msg", ({
		"����˵��: ��λ�͹٣�������Щʲô������ ?\n",
	}) );

// all skills will be set back also
        me->delete_temp("apply/attack");
        me->delete_temp("apply/defense");
        me->delete_temp("apply/damage");

	return 1;
}
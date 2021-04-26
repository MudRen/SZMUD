// Code of ShenZhou
// npc: /d/xingxiu/npc/ke.c
// Jay 3/27/96

#include "ansi.h"
inherit NPC;
inherit F_MASTER;

int auto_perform();
int waiting(object me);
int checking(object me);
int do_chase(object me);
int do_kill(object me, object dest);
string ask_me();
string ask_lingshe();
int ask_shegu();

void create()
{
	set_name("ŷ����", ({ "ouyang feng", "ouyang", "feng" }));
	set("long", "�����θߴ󣬸߱���Ŀ������ѩ�׶��룬����������\n"
		"������ʹ�����ųơ���������\n");
	set("nickname","����");
	set("title", "����ɽׯׯ��");
	set("gender", "����");
	set("age", 65);

	set("lingshe_count",3);
	set_skill("cuff", 400);
	set_skill("lingshe-quan", 400);
	set_skill("shentuo-zhang", 400);
	set_skill("strike", 360);
	set_skill("dodge", 360);
	set_skill("chanchubu", 360);
	set_skill("parry", 360);
	set_skill("force", 360);
	set_skill("hamagong", 400);
	set_skill("lingshe-zhang",400);
	set_skill("staff",400);
	set_skill("poison",400);
	set_skill("training",360);
//	map_skill("cuff","lingshe-quan");
	map_skill("strike","hamagong");
	map_skill("staff","lingshe-zhang");
	map_skill("dodge","chanchubu");
	map_skill("parry", "lingshe-zhang");
	map_skill("staff","lingshe-zhang");
	map_skill("force","hamagong");
//	prepare_skill("cuff","lingshe-quan");
	prepare_skill("strike","hamagong");

	set("str", 33);
	set("int", 28);
	set("con", 29);
	set("dex", 28);

	set("max_qi", 5500);
	set("qi",5500);
	set("max_jing", 3000);
	set("jing",3000);
	set("neili", 6000);
	set("max_neili", 6000);
	set("jiali", 300);
	set("combat_exp", 3600000);

		  set("attitude", "peaceful");
		  set("shen_type", -1);

		  create_family("����ɽ", 1 , "ׯ��");
		  set("chat_chance_combat", 50);
		  set("chat_msg_combat", ({
			 (: auto_perform :),
		  }) );
	set("inquiry", ([
		"����" : "����������������ţ��������⡰�����ֹ��������ж���֮�أ�δ���������͡�",
		"��" : "����������������ţ��������⡰�����ֹ��������ж���֮�أ�δ���������͡�",
		"ŷ����" : "������ֶ��",
		//TEMP DISABLE BECAUSE THE ANTI-PK EVENTS (BY SCATTER)
		//"����": (: ask_me :),
		//"����": (: ask_me :),
		"����" : (: ask_lingshe :),
		"�߹�": (: ask_shegu :),
		"��ʬ��" : "�����Ҵ�ǰ�õ�С���⣬���ڿ˶����ã��Ϸ��Ѿ���мһ���ˡ�",
	]));

	setup();
        carry_object("/d/baituo/obj/lingshezhang")->wield();
        carry_object("/d/baituo/obj/wcloth")->wear();
	set_temp("job_pos",10);

}

void attempt_apprentice(object ob)
{
		  mapping fam;
	string son;

		  if( !mapp(fam = ob->query("family")) || fam["family_name"] != "����ɽ")
	{
		command ("say " + RANK_D->query_respect(ob) +
			"��ȥ��ɽׯ��ʦ���˷��������´���Ӱɡ�");
		return;
	}
	if ((int)ob->query_skill("hamagong", 1) < 100) {
		command("say ���ǰ���ɽׯ�ľ������Ҵ��ĸ�󡹦��"); 
		command("say " + RANK_D->query_respect(ob) + 
			"�Ƿ�Ӧ���ڸ�󡹦�϶��µ㹦��");
		return;
	}
	if ((int)ob->query_skill("training", 1) < 100) {
		command("say ���ǰ���ɽׯ����ҪѵԦ���棬"); 
		command("say " + RANK_D->query_respect(ob) + 
			"��Ԧ�����������á�");
		return;
	}
	if ((int)ob->query_skill("poison",1) < 100) {
		command("say ��Ķ���̫���ˡ�");
					 return;
	}

	if (ob->query("gender")=="Ů��") son = "��Ů";
	else son = "����";
	command("look "+ob->query("id"));
	command("say �ҿ������ʴ�ӱ������������"+ son +"��");
	command("say �����ϰ������常���͸���"
		"�ĸ�ͷ(ketou)��");
	ob->set_temp("ouyangfeng",1);
	return;
}

int do_ketou(string arg)
{
	object ob = this_player();
	string son;
//	string name, new_name;

	if (!ob->query_temp("ouyangfeng")) return 0;
		  if (ob->query("gender")=="Ů��") son = "��Ů";
		  else son = "����";

	message_vision("$N˫ϥ�򵹣�����$n˵�������常���ϣ����ܺ���һ�ݣ���\n\n"
			"$n���˵������Ҳ�����$N�ӵ��Ϸ���\n\n", ob, this_object() );

//	name = ob->query("name");
 //      new_name = "ŷ��"+ name[2..3];
  //      command("say �ӽ��Ժ�������ֽ���" + new_name + "��");

	command("say ���ӣ���Ҫ��Ϊ�����⡣");
	command("recruit " + ob->query("id"));
	ob->set("title","����ɽׯ��ׯ��");
	ob->set("fengdeath",ob->query("death_count"));
//	ob->set("name", new_name);
	command("chat ��λ�����������ţ��ӽ�����"+ob->query("name")+
		"�����Ϸ��"+son+"��˭�Ҷ��Ҷ�һ����ë��Ī���Ϸ����顣");
	command("say ���ӣ������Ҫ����ɱ�ˣ��������ҡ����𡱣�Ϊ���Ͱ������˳�ң�");

	return 1;
}
void init()
{
	object ob, me;
	add_action("do_ketou","ketou");
	::init();
	if (interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	
	if( !this_object()->query("waiting_target") && ob->query_temp("fengwait") ) 
		ob->delete_temp("fengwait");
	add_action("do_name","��");

}

string ask_me()
{
	object me = this_player();
	if (me->query("family/family_name") != "����ɽ") {
		command("say �ǲ������ǰ���ɽׯ���˴����㣬����������");
		kill_ob(me);
		return ("������\n");
	}
	if (me->query("family/master_name") != "ŷ����") 
		return ("�������洳�˻�Ҫ����ʰ���������ļһ\n");
	if (! (me->query("fengdeath") < me->query("death_count")))
		return ("�������û�½������ɱ�ˡ������Ҫץ������󡹦�ء�\n");
	
	command("say ���ӣ�˭�۸����ˣ������Ϊ����Ϊ��Ҫ��������");
	tell_object(me, "����룺�� Ŀ����������\n");
	me->set_temp("fengwait",1);
	return ("��㣡");
}

int do_name(string target)
{
	object me, dest, *all;
		  int i;
 
	me = this_object();
	all = users();

	if(me->query("waiting_target"))
		 return notify_fail("ŷ����˵������������æ���أ�\n");

	if( !this_player()->query_temp("fengwait") ) 
		return notify_fail("ŷ����˵���������������㣿�����ף�\n");

	if( !target || target==" ")
		return notify_fail("ŷ�����ݺݵ�˵���������Ϊ���Ǽһ�����֣�\n");


	for(i=0; i<sizeof(all); i++) 
	{
		if( target == all[i]->name() || target == all[i]->query("id") )
			dest = all[i];
	}
	if( !dest )
		return notify_fail("ŷ���泤̾һ���������ڲ�����Ϸ�У����������ɡ�\n");

	if (dest->is_ghost())
		return notify_fail("ŷ������˵�˵�����Ѿ��ܵ���Ӧ���ˣ��������ۣ�Ϊ��Ҳ���س����ˡ�\n");

	if (dest->query("id") != this_player()->query_temp("my_killer"))
		return notify_fail("ŷ����ҡҡͷ�����˲�������\n");

	me->set("waiting_target", dest->query("id"));
	me->set("target_name", target);
	log_file("Playing", sprintf("%s(%s) attempted to let Ouyang Feng to kill %s(%s)\n",
			this_player()->query("name"), getuid(this_player()),
			dest->query("name"), dest->query("id")) );

	this_player()->set("fengdeath",this_player()->query("death_count"));
	message("vision","ŷ����˵��������������ȵȣ�Ϊ��ȥȥ����!\n", environment(), me );

	message_vision("$N���˳�ȥ��\n", me);

	call_out("do_chase", 1, me);

	return 1;
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
	message_vision("$N���˹�����\n", me);
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
		message_vision(HIR "$N��$n˵�����󵨿�ͽ�������۸�����ŷ���ҵ��ˣ�\n" NOR, me, dest);
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
		 && ob->query("victim_name") == me->query("target_name") )
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

	me->move("/d/xingxiu/btroom");
	message("vision", "ŷ�������˽��������˲����ϵ�Ѫ��˵�������ӣ���ĳ�Ϊ�����㱨�ˡ�\n", 
		environment(), me );


	me->set_leader(0);
	return 1;
}

void greeting(object me)
{
	int sxds, hand;

	sxds = me->query_skill("shexing-diaoshou",1);
	hand = me->query_skill("hand",1);

	if (me->query("family/family_name") != "����ɽ") {
		me->apply_condition("snake_poison", 
		2 + me->query_condition("snake_poison"));
	}

	if( me->query("family/family_name") == "����ɽ" 
	&& !me->query("baituo_updated") ) {
		me->set_skill("cuff", hand);
		me->set_skill("lingshe-quan", sxds);
		me->delete_skill("hand");
		me->delete_skill("shexing-diaoshou");
		me->set("baituo_updated",1);
	}

	if (me->query("enter_shegu")) {
		if ( environment(me) != environment(this_object())) return;

		me->delete("enter_shegu");

		if (me->query("family/family_name") != "����ɽ") {
			command("hehe "+me->query("id"));
			command("say "+me->name()+RANK_D->query_rude(me)+"�������ô��߹ȣ�������������ĥ�������ɻ�ˣ������ơ����������ţ�");
			command("perform shoot "+me->query("id")); //for weapon
			kill_ob(me);
		}
		else if (me->query("family/family_name") == "����ɽ" 
		&& !me->query("baituo/shegu_permit") ) {
			command("slap "+me->query("id"));
			command("say ˭���������߹ȵģ�");
			message_vision(HIR"ŷ������$N�ļ�ͷ���ذ���һ�ƣ���󡹦����ֱ͸���࣬��ʱ���$N�����ֽ���������¡�\n"NOR, me);
			me->set("neili", 0);
			me->set("jingli", me->query("jingli")/10);
			me->set("qi", me->query("qi")/10);
			me->start_busy(3);
			command("say ���ͷ������Ǳ������ˡ����������´Σ�");
		}
	}
	return;
}

string ask_lingshe()
{
	mapping fam;
	object obj, me;

	me = this_player();
	if (me->query("family/master_name") != "ŷ����") {
		return ("���޹������������Ǳ�ҪΪ�");
	}
	if (query("lingshe_count") < 1) {
		return ("����ѱ�����ף�����û�У�");
	}
	message_vision(CYN"$N�鴽��Х�����л����γ�һ����ɫС�ߣ�����$nҡͷ��β������ʾ���ʺá�\n"NOR,
	this_object(), me);
        obj = new("/d/baituo/npc/lingshe.c");
	obj->move(environment());
	add("lingshe_count", -1);
		  return ("�������ԣ����޲��������Ƿ���Ե��Ϊ�������ˡ�");
}

int ask_shegu()
{
	object me, staff;
	int lv;
	me = this_player();

	if( me->query("family/family_name") != "����ɽ" && me->query("combat_exp") > 100000) {
		command("sneer "+me->query("id"));
		command("say ����ɽ�߹ȵ����ܣ�����͸¶������֪����"+RANK_D->query_rude(me)+"����̫�����ˣ�");
		kill_ob(me);
		command("perform bite "+me->query("id")); // has weapon
		command("perform puji "+me->query("id")); // no weapon
		return 1;
	}

	if( me->query("family/family_name") != "����ɽ" ) {
		command("sneer "+me->query("id"));
		message_vision("$Nû�лش�$n��\n", this_object(), me);
		return 1;
	}

	if( me->query("baituo/shegu_permit") ) {
		command("say �߹��е��߶�����������Ⲷ׽���ú�����������ĪҪ����������������");
		return 1;
	}

	lv = (int)me->query_skill("poison", 1);

	if( lv < 80 ) {
		command("say ƾ�����ʹ�����£�����߹Ȼ���úܡ��ԹԵ���ׯ��������");
		return 1;
	}
	
	if( lv < 100 ) {
		command("pat "+me->query("id"));
		command("say ��Ķ������е����ˣ���������߹ȣ����ö��µ㹦����ĥ��");
		return 1;
	}

	command("nod "+me->query("id"));
	command("say ���ö������ͣ��ƺ��ǽ������ˡ��ã��Ϸ��������߹��������졣");
	me->set("baituo/shegu_permit", 1);

        staff = new("/d/baituo/obj/lingshezhang");
	staff->move(me);

	message_vision("$N��һ��"+staff->name()+"����$n��\n",this_object(), me);
	command("say �ӽ����ᣬ��������ɽ����߹ȡ����Ĵ������У���Ķ��������Ը��ϲ�¥��");

	return 1;
}

#include "/kungfu/class/baituo/auto_perform.h"

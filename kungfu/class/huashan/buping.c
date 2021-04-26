// Code of ShenZhou
// buping.c �ⲻƽ
// qfy Oct 21, 1996

#include <ansi.h>
inherit NPC;
string ask_me();

void create()
{
	set_name("�ⲻƽ", ({ "feng buping", "feng", "buping" }));
	set("long", 
"�ⲻƽ�ǻ�ɽ���ڵĵ�һ���֡�����֮������һ��Ϳ�أ��ⲻƽ��\n"
"�ӿ�������ѩ���衣��������ޣ����������˵ã��ڹ����ǲ�����\n");
	set("gender", "����");
	set("age", 47);
	set("attitude", "peaceful");
	set("shen_type", 0);
	set("str", 28);
	set("int", 30);
	set("con", 27);
	set("dex", 28);
	set("shen", 0);
	
	set("max_qi", 1200);
	set("max_jing", 850);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 50);
	set("combat_exp", 920000);
	set("score", 5000);

	set_skill("force", 140);
	set_skill("dodge", 140);
	set_skill("parry", 140);
	set_skill("sword", 155);
	set_skill("strike", 130);
	set_skill("cuff", 130);
	set_skill("huashan-shenfa", 140);
	set_skill("zixia-gong", 130);
	set_skill("huashan-jianfa", 155);
	set_skill("hunyuan-zhang",130);
	set_skill("pishi-poyu", 130);
	set_skill("ziyin-yin", 100);
	set_skill("zhengqi-jue", 100);

	map_skill("cuff", "pishi-poyu");
	map_skill("force", "zixia-gong");
	map_skill("parry", "huashan-jianfa");
	map_skill("sword", "huashan-jianfa");
	map_skill("strike","hunyuan-zhang");
	map_skill("dodge","huashan-shenfa");

	prepare_skill("strike", "hunyuan-zhang");
	prepare_skill("cuff", "pishi-poyu");

	create_family("��ɽ��", 13, "���ڵ���");
	
	set("inquiry", ([
	    "����" : "���ڲ��ǻ�ɽ����ͳ���Խ�Ϊ�ڣ�����Ϊ����������ѧ�ľ�Ҫ��\n",
	    "����" : "�ߣ������书ӹ�ײ����������ὣ�����߰��㡣\n",
	    "����Ⱥ" : "������α���ӣ��ɶ�\n",
	    "��ɽ����" : "�Ǳ��Ǳ��ɾ�ѧ������һ��һ�Ľ����������ǡ����������һ�У��ɽ�ɱ�У������ܵ���\n",
	    "��ϼ��" : "���Ǳ����ڹ��ķ���\n",
	    "˼����" : "���Ǳ��ɵ�������˼��֮����\n",
	    "������" : "�������Ѷ��겻����ʦ�壬������������䡣\n",
	    "�ɽ�" : "������������Ǳ��ɾ��У��ɽ��������������У�\n",
	    "�ɽ�ɱ��" : "������������Ǳ��ɾ��У��ɽ��������������У�\n",
	    "�������" : (: ask_me :),
	]));

	setup();
	carry_object("/d/city/obj/changjian")->wield();
	carry_object("/d/city/obj/cloth")->wear();
}

void init() 
{
	object ob, me = this_object();

	::init();
	if (interactive(ob=this_player()) && ob->query("family/master_id") == "feng buping"
	&& ob->query("shen") < -100 ) {
		command("say " + RANK_D->query_rude(ob) + "�������������Ϊ���ܻ�����������" );
		me->kill_ob(ob);
	}
}

int accept_fight(object ob)
{
	object me = this_object();
	int my_max_qi = me->query("max_qi");

	if ( me->query("qi")*100 / my_max_qi <= 80 ) {
		call_out("checking", 1, me, ob);
		return 0;
	}       

	remove_call_out("checking");
	call_out("checking", 1, me, ob);

	return 1;
}

int accept_kill(object ob)
{
	object me = this_object();

	command("say �üһ���㳢�������Դ��Ŀ��콣����Ҳ�������Ŀ�˰ɣ�");
	remove_call_out("checking");
	call_out("checking", 1, me, ob);

	return 1;
}

int checking(object me, object ob)
{
	int my_max_qi = me->query("max_qi");
	object weapon;

	if (me->is_fighting()) {
	   if ( (me->query("qi")*100 / my_max_qi) <= 80 ) {
		command("exert recover");
	   }

	   if ( !me->query_temp("attack_pending") 
	   && objectp(weapon = me->query_temp("weapon")) ) {
		me->set_temp("attack_pending", 1);
		remove_call_out("fast_attack");
		call_out("fast_attack", 3, me, ob);
	   }

	   call_out("checking", 1, me, ob);
	   return 1;
	}

	if (!me->is_fighting()) {
		me->delete_temp("attack_pending");
		remove_call_out("fast_attack");
	}

	if ( !present(ob, environment()) && me->query("attack_pending")==1 ) {
	   me->delete_temp("attack_pending");
	   return 1;
	}

	return 1;
}

int fast_attack(object me, object ob)
{
	int i, num;

	me->delete_temp("attack_pending");

	if (!me->query_temp("weapon")) return 1;
	num = random(2)+3;

	message_vision(RED"\n�ⲻƽ��ɫ���أ�ʹ������������콣�����˽�����Ƶ����$N������"+chinese_number(num)+"����\n"NOR, ob);

	for (i=1; i<num+1; i++) {
	    COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));
	}

	return 1;
}

string ask_me()
{
	object ob = this_player(), me = this_object();
	mapping obfam;
	obfam = (mapping)ob->query("family");

	if ( !obfam || obfam["family_name"] != "��ɽ��" ) {
	   if ( ob->query_temp("feilong") < 3 ) {
		command( "sneer" );
		ob->add_temp("feilong", 1);
		return "���Ǻ���ԨԴ����������ʲô�����Ǳ�̫����ĺá�\n";
	   }
	   else {
		message_vision("$N��ɫ΢�䣬Ŀ������һ��������һ����Ц��\n", me);
		ob->delete_temp("feilong");
		me->kill_ob(ob);
		remove_call_out("checking");
		call_out("checking", 1, me, ob);
		return "�������Ĵ���̽����ɽ�����İ��ܣ������ϲ⣡�Ƿ���Ա��ɲ������㼴Ȼ�Ի�ɽ�������㿾���ֻ���û�ɽ����������·�ˡ�\n";
	   }
	}
	
	command( "look "+ob->query("id") );

	if ( ob->query_skill("huashan-jianfa", 1) < 100 )
		return "��Ļ�ɽ������Ϊ������ѧ���ˡ������������";

	if ( ob->query_skill("zixia-gong", 1) < 70 )
		return "�����Խ�Ϊ�ڣ�����Ϊ���������������ã������ϼ���ɵ�����һ���๦��";

	if ( ob->query_skill("zixia-gong", 1) > ob->query_skill("huashan-jianfa", 1) ) {
		command( "sneer" );
		return "�������ڵ��ˣ�ȴ��������̣�������ε�������";
	}

	if ( ob->query("huashan/feilong") )
		return "�ף��Ҳ��Ǵ����㡸����������𣿶��¹���ú���ϰ������˻�ɽ���ڵ�������";

	command( "say �ã��ұ㴫�㡸���������������ϸ�ˣ�" );

	message_vision("$N�������ߣ��׹���磬���ش���ɽ��Ρ�ţ����鴦������޼������Ī�⡣\n"
		      +"�赽������$Nһ����ȣ��������ַɳ�������һ�����磬ֱû��������һ�����С�\n", me);

	ob->set("huashan/feilong", 1);

	return "�����Ҫ�ڼ���ϰ���𹼸����ҵ�һ���̵���";
}
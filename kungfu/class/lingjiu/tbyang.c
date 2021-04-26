// By Xuanyuan 11/18/2001

#include <ansi.h>
int auto_perform();
inherit NPC;
string ask_me();
void create()
{
	set_name("������", ({ "fu mingyi", "fu"}));
	set("long",
	    "���ǡ����չ�������Ų������첿������.\n"+
	    "���ųơ�����.\n");
	set("title", "���첿����");
	set("gender", "Ů��");
	set("nickname", HIG "����" NOR);
	set("age", 20);
	set("shen_type",0);
	set("attitude", "peaceful");

	set("per", 21);
	set("class", "scholar");
	set("str", 25);
	set("int", 25);
	set("con", 30);
	set("dex", 30);

	set("qi", 1300);
	set("max_qi", 1300);
	set("jing", 500);
	set("max_jing", 500);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 20);

	set("combat_exp", 300000);
	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("hand",100);
	set_skill("strike", 100);
	set_skill("sword",100);
	set_skill("literate",100);
	set_skill("music",100);

	set_skill("zhemei-shou",100);
	set_skill("liuyang-zhang",100);
	set_skill("tianyu-qijian",100);
	set_skill("yueying-wubu",100);
	set_skill("bahuang-gong", 100);

	map_skill("force", "bahuang-gong");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");
	map_skill("sword", "tianyu-qijian");

	prepare_skill("strike","liuyang-zhang");
	prepare_skill("hand","zhemei-shou");

	set("inquiry", ([
		"ľ��"     : (: ask_me :),
		"����"	   : (: ask_me :),
		"��ľ��"   : (: ask_me :)
	]));

	prepare_skill("strike","liuyang-zhang");
	prepare_skill("hand","zhemei-shou");
	create_family("���չ�",4,"����");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );
	setup();
 	carry_object("/clone/weapon/changjian")->wield();
 	carry_object("/d/lingjiu/obj/qingyi")->wear();
        carry_object("/d/lingjiu/obj/doupeng")->wear();
        add_money("silver",25);
}

void init()
{	
	object me, ob;

	me = this_object();

	::init();
	if( objectp(ob = present("mu ren", environment())) )
	{
		remove_call_out("repairing_1");
		call_out("repairing_1", 5, me, ob);
	}
}
int repairing_1(object me, object ob)
{
	if ( !present(ob, environment()) ) return 1; 

	command("say �����ľ�˰ɣ� ���������ƣ� ���ڱ��ϴ��ţ����ܰ���ʲôæ��");
	
	remove_call_out("repairing_2");
	call_out("repairing_2", 2+random(3), me, ob);

	return 1;
}

int repairing_2(object me, object ob)
{
	if ( !present(ob, environment()) ) return 1; 

	if( ob->query("damaged") )
	{
		message_vision(GRN "\n�����Ƕ���ľ������һ�ᣬ�����Ű⶯ľ�˵���֫���Դ�����������߶��ʲô��\n\n" NOR, me);
		remove_call_out("repairing_3");
		call_out("repairing_3", 2+random(2), me, ob);
	}
	else
	{
		command("say ��ľ�˺ö˶˵���û����");
		command("follow none");

		message_vision(GRN "\n���������Ĺĵ����ˡ�\n" NOR, me);
		me->move("/d/lingjiu/caifeng");

		remove_call_out("do_back");
		call_out("do_back", random(15), me);
	}

	return 1;
}
	
int repairing_3(object me, object ob)
{
	command("say ��ԭ����ˣ��������޿��ɣ�");
	message_vision(GRN "\nֻ�������Ŵӻ����ͳ�һ��ϸϸ�Ľ��룬��ľ�˵����壬��Ū�˼��¡�\n\n" NOR, me);

	remove_call_out("repairing_4");
	call_out("repairing_4", 3+random(3), me, ob);

	return 1;
}

int repairing_4(object me, object ob)
{
	if( random(2) == 0 ) 
	{		
		command("say �ã��޺��ˣ�");
		ob->delete("damaged");
		ob->set("fight_times", 0);	
		message_vision(GRN "\nľ�˵�����֨֨��Ť���˼��£��ָ�������վ������̬��\n\n" NOR, me);
	}
	else 
		message_vision(GRN "\n������̾�˿�����˵�����������У���ľ���𻵵�̫�����ˣ�û�������ˣ�\n" NOR, me);

	command("say �ã��������ˣ�");
	command("wave");
	command("follow none");

	message_vision(GRN "\n���������˳�ȥ��\n" NOR, me);
	me->move("/d/lingjiu/caifeng");

	remove_call_out("do_back");
	call_out("do_back", random(15), me);

	return 1;
}

int do_back(object me)
{
	me->move("/d/lingjiu/caifeng");
	return 1;
}

string ask_me()
{
	mapping fam; 
	object ob;

	ob = this_player();
	
	if (!(fam = ob->query("family")) || fam["family_name"] != "���չ�")
		return RANK_D->query_respect(ob) + 
		"�뱾��������������֪�˻��Ӻ�̸��";

	command("say ľ�˴����ǰɣ� �ðɣ��Ҹ���ȥ������");
	command("follow " + ob->query("id"));

	return "�����߰գ�\n";
}

#include "/kungfu/class/lingjiu/tianbu.h"
#include "/kungfu/class/lingjiu/auto_perform.h"
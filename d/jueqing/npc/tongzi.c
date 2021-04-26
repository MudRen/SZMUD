// NPC:   /d/jueqing/npc/tongzi.c
// ������: jiuer 08/2001

#include <ansi.h>
inherit NPC;
int ask_zhuangzhu();
void greeting(object);

void create()
{
	object ob;
	set_name("����", ({ "tong zi", "tongzi", "tong" }));
	set("long","����һ��ʮ�����С���ף���Ц���еؿ����㡣\n");
	
	set("gender","����");
	set("age", 10);
	set("attitude","friendly");

	set("str", 20);
	set("dex", 28);
	set("con", 28);
	set("int", 28);
	
	set_skill("literate", 28);
	set_skill("unarmed", 10);
	set_skill("parry", 10);
	set_skill("force", 10);
	set_skill("sword", 10);
	set_skill("dodge", 10);
	
	set("jingli",100);
	set("max_neili",100);
	set("neili",100);
	set("eff_jing",100);
	set("eff_qi",200);
	set("combat_exp", 100);
	set("shen_type",1);
	
	set("inquiry", ([
			"ׯ��"   : 	(: ask_zhuangzhu :), 
		]));
	
	setup();

	carry_object("/d/quanzhou/obj/fuchen")->wield();
	carry_object("/d/jueqing/npc/obj/greenrobe")->wear();
}

void init()
{
	object me = this_player();
	
	::init();

	if( interactive(me) )
	{
		remove_call_out("greeting");
        call_out("greeting", 1, me);
	}
}

void greeting(object ob)
{
	if (!ob || environment(ob) != environment())
		return;
	switch(random(2)) 
	{
	case 0 :
		say("С����Ц��ӭ�����������ִ���Ƨ�ý����������˵��ã�\n"
			+"���չ�ͽ��٣��Һ���֮��ȴ��֪��λ" + RANK_D->query_respect(ob) + "�кι�ɣ���\n");
		break;
	case 1 :
		say("С����Ц��˵�����������ǰݼ��Ҽ�ׯ������������\n");
		break;
	}
}

int ask_zhuangzhu()
{
	object me = this_player(),here;
	string desc;
    here = environment(me);	
	desc = here->query("long");
	
	if ( (int)here->query_temp("opened") == 0)
	{
		say("����Ц������ԭ����Զ������ׯ���ģ�����ɡ���\n");
		say("����һ��˵һ�߰Ѵ�ʯ�Ŵ򿪡�\n");
		here->set("exits/enter", "/d/jueqing/changlang1"); 
	}
	else
	{
		say("����΢һ����˵������ׯ���������У����ȥ�����ɡ���\n");
	}
	return 1;
}



// /NPC lanjian.c
// By Xuanyuan 11/18/2001

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int auto_perform();
void create()
{
	set_name("����", ({ "lan jian", "lan"}));
	set("long",
	    "���Ǹ���ò毺õ�Ů��, ��������,\n"+
	    "�������, �������.\n"+
	    "���ܾ������ļ�����.\n");
	set("gender", "Ů��");
	set("per", 29);
	set("age", 18);
	set("shen_type",0);
	set("attitude", "peaceful");

	set("per", 33);
	set("class", "officer");
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);

	set("qi", 2000);
	set("max_qi", 2000);
	set("jing", 2000);
	set("max_jing", 2000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 50);

	set("combat_exp", 1000000);
	set("score", 10000);
	set_skill("force", 180);
	set_skill("dodge", 180);
	set_skill("parry", 180);
	set_skill("hand",180);
	set_skill("strike", 180);
	set_skill("sword",180);
	set_skill("literate",100);
	set_skill("music",180);

	set_skill("zhemei-shou",180);
	set_skill("liuyang-zhang",180);
	set_skill("tianyu-qijian",180);
	set_skill("yueying-wubu",180);
	set_skill("bahuang-gong", 180);

	map_skill("force", "bahuang-gong");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");
	map_skill("sword", "tianyu-qijian");

	prepare_skill("strike","liuyang-zhang");
	prepare_skill("hand","zhemei-shou");

	create_family("���չ�",3,"����");

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );
	setup();
 	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/lingjiu/obj/qingyi")->wear();
        carry_object("/d/city/npc/obj/doupeng")->wear();
	add_money("silver",15);
}
void init()
{
	object me, ob;
	mapping fam;

	::init();
	ob = this_player();
	me = this_object();
	
	if (interactive(ob) 
	&& !environment(ob)->query("no_fight")
	&& ((fam = ob->query("family")) && fam["family_name"] != "���չ�" )
	&& me->query("biao/owner"))
	{
		if( !ob->query_temp("warned") ) {
		command("say ����������˲��ý������չ��������뿪��");
			ob->set_temp("warned", 1);
	}
		else if( ob->query_temp("stay")<5 ) ob->add_temp("stay",1);
		else {
			command("say �󵨿�ͽ�������ô����չ�������\n");
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob); 
		}
	}
}
#include "/kungfu/class/lingjiu/jianbi.h"
#include "/kungfu/class/lingjiu/auto_perform.h"
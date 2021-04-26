// By Xuanyuan 11/18/2001

#include <ansi.h>

inherit NPC;
int auto_perform();
string ask_me(string name);
void create()
{
	set_name("½ɩ", ({ "lu sao", "lu", "sao" }));
	set("long",
	    "���ǡ����չ�������Ų��г��첿������.\n"+
	    "������ͯ�Ѷ���, ��������,������˪.\n");
	set("title", "���첿����");
	set("gender", "Ů��");
	set("age", 60);
	set("shen_type",0);
	set("attitude", "peaceful");

	set("per", 23);
	set("class", "scholar");
	set("str", 20);
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
/*
        set("inquiry", ([
		"ʳ��" : (: ask_me, "gao" :),
		"�Ե�" : (: ask_me, "gao" :),
		"ˮ" : (: ask_me, "suanmei" :),
		"�ƴ�" : (: ask_me, "jiudai" :),
        ]));
	set("fool_count", 15);
*/
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
string ask_me(string name)
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "���չ�")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";

	if (  present(name, this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"���������ϲ���������������Ҫ�ˣ� ����̰�����У�";

	if (query("fool_count") < 1)
		return "��Ǹ�������ò���ʱ�򣬿�����ʱ���Ѿ����ˡ�";

	ob = new("/clone/food/" + name);
	ob->move(this_player());

	add("fool_count", -1);

	message_vision("½ɩ��$Nһ��" + ob->query("name") + "��\n", this_player());

	return "��ȥ�ɡ�";
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
#include "/kungfu/class/lingjiu/tianbu.h"
#include "/kungfu/class/lingjiu/auto_perform.h"
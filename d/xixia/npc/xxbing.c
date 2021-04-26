// Code of ShenZhou

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("���ı�", ({ "xixia bing", "bing" }));
        set_color("$YEL$");
	set("age", 22);
	set("gender", "����");
	set("long", "һ�����������ʿ����\n");
	set("attitude", "heroism");

	set("str", 24);
	set("dex", 16);
	set("combat_exp", 20000);
	set("shen_type", 0);

	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("pike", 40);
	set_skill("force", 40);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);

	set("chat_msg_combat", ({
		"���ı��ȵ����󵨵��񣬾����췴���ɣ�\n",
		"���ı��ȵ����ܵ��˺����ܲ������㻹�ǿ�����־��ܣ�\n",
	}));
	setup();
	carry_object("/clone/weapon/qiang")->wield();
	carry_object("/d/city/obj/junfu")->wear();
}

void init()
{
	object ob;
//	::init();
	if (interactive(ob = this_player()) && 
		(int)ob->query_condition("xakiller")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
}

int accept_fight(object me)
{
	command("say ��ү����������ɱ�ţ��������㵹ù��\n");
	me->apply_condition("xakiller", 100);
	kill_ob(me);
	return 1;
}

int accept_kill(object me)
{
        command("say ��ү����������ɱ�ţ��������㵹ù��\n");
        me->apply_condition("xakiller", 100);
        kill_ob(me);
        return 1;
}


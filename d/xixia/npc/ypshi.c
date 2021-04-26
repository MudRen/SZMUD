// Code of ShenZhou

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("һƷ����ʿ", ({ "wu shi", "shi", "guard" }) );
	set("gender", "����");
	set("age", 35);
	set("long",
		"һ��������׵�������ʿ��\n");
	set("combat_exp", 350000);
        set("shen_type", -1);
	set("attitude", "heroism");

	set("str", 26);
	set("con", 22);
	set("int", 20);
	set("dex", 24);

	set("max_qi", 1000);
	set("eff_qi", 1000);
	set("qi", 1000);
	set("max_jing", 500);
	set("jing", 500);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 50);

	set_temp("apply/attack",  70);
	set_temp("apply/defense", 70);

	set_skill("blade", 130);
	set_skill("unarmed", 110);
	set_skill("force", 130);
	set_skill("parry", 130);
	set_skill("dodge", 130);

	set("no_get", "һƷ����ʿ�������̫���ˡ�");

	setup();

        carry_object("/d/city/obj/gangdao")->wield();
        carry_object("/d/city/obj/tiejia")->wear();
}
void init()
{
        object ob;
//      ::init();
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

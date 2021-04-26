// Code of ShenZhou
// Jay 5/10/97 

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("������", ({ "li yuanzhi", "li", "yuanzhi" }));
        set_color("$YEL$");
	set("long", 
		"�����������Ķ���Ů������������������ν�������������Ů��ȡ������֣��Ǽ�������֮�⡣\n"
		"����������������Щ���ԡ�\n");
		
	set("gender", "Ů��");
	set("age", 18);
	set("shen_type", 1);

	set("inquiry", ([
		"����ͬ" : "�������ɷ�\n",
		"�����" : "�����ҵ���\n",
		"�컨��" : "�Ҽ޼��漦���޹��湷����ô����ҲҪ�����\n",
	]));
	set("neili", 400);
	set("max_neili", 400);
	set("max_qi", 400);
	set("max_jing", 200);
	set("jiali", 10);

	set_skill("force", 50);
	set_skill("unarmed", 40);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_skill("sword", 60);
	set_skill("taiji-jian", 40);
	map_skill("sword", "taiji-jian");
	map_skill("parry", "taiji-jian");

	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
	set_temp("apply/damage", 15);

	set("combat_exp", 50000);

	setup();
	carry_object(__DIR__"obj/goldring")->wear();
	carry_object(__DIR__"obj/necklace")->wear();
	carry_object(__DIR__"obj/changjian")->wield();
}
int accept_kill(object me)
{
        command("say ���ò��ͷ��ˣ�����С����ô��ʰ�㣡\n");
        me->apply_condition("killer", 100);
        kill_ob(me);
        return 1;
}


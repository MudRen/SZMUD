// xiaofeng.c 

inherit NPC;
//inherit F_SKILL;

void create()
{
	set_name("С��", ({ "xiao feng", "xiao", "feng" }));
	set("long", 
		"�����Ǻ�÷ɽׯ��Ѿ�ߣ�һ�Ŷ쵰������˿����.\n"
		"���ϴ��Ų�֪������޳�У��������⡢���ϴ��Ž���\n");
		
	set("title", "Ѿ��");
	set("gender", "Ů��");
	set("age", 16);
	set("shen_type", 1);

        set_skill("dodge", 50);
        set_skill("unarmed", 50);
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
	set_temp("apply/damage", 15);

	set("combat_exp", 10000);

	setup();
        carry_object("/clone/misc/cloth")->wear();
}

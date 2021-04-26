// Code of ShenZhou
// Npc: /kungfu/class/shaolin/hui-kong.c
//  Date: YZC 96/01/19

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("�ۿ�����", ({
		"huikong zunzhe",
		"huikong",
		"zunzhe",
	}));
	set("long",
		"����һλ���ް߰׵���ɮ����һϮ�಼������ġ�������Ըߣ�\n"
		"̫��Ѩ΢͹��˫Ŀ��������\n"
	);


	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 50);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 650);
	set("max_jing", 300);
	set("neili", 600);
	set("max_neili", 600);
	set("jiali", 50);
	set("combat_exp", 150000);
	set("score", 100);

	set_skill("force", 70);
	set_skill("hunyuan-yiqi", 70);
	set_skill("dodge", 70);
	set_skill("shaolin-shenfa", 70);
        set_skill("cuff", 70);
        set_skill("luohan-quan", 70);
	set_skill("staff", 70);
	set_skill("pudu-zhang", 70);
	set_skill("parry", 70);
	set_skill("buddhism", 70);
	set_skill("literate", 70);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
        map_skill("cuff", "luohan-quan");
	map_skill("staff", "pudu-zhang");
	map_skill("parry", "pudu-zhang");

        prepare_skill("cuff", "luohan-quan");

	create_family("������", 38, "����");

	setup();

        carry_object("/d/shaolin/obj/chanzhang")->wield();
        carry_object("/d/shaolin/obj/hui-cloth")->wear();
}




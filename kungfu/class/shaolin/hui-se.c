// Code of ShenZhou
// Npc: /kungfu/class/shaolin/hui-se.c
// Date: YZC 96/01/19

inherit NPC;
inherit F_MASTER;


void create()
{
	set_name("��ɫ����", ({
		"huise zunzhe",
		"huise",
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
	set("str", 30);
	set("int", 18);
	set("con", 28);
	set("dex", 25);
	set("max_qi", 650);
	set("max_jing", 300);
	set("neili", 600);
	set("max_neili", 600);
	set("jiali", 50);
	set("combat_exp", 200000);
	set("score", 100);

	set_skill("force", 70);
	set_skill("hunyuan-yiqi", 70);
	set_skill("dodge", 70);
	set_skill("shaolin-shenfa", 70);
	set_skill("cuff", 70);
	set_skill("luohan-quan", 70);
        set_skill("club", 70);
        set_skill("weituo-gun", 70);
	set_skill("strike", 74);
	set_skill("sanhua-zhang", 74);
	set_skill("parry", 70);
	set_skill("buddhism", 70);
	set_skill("literate", 70);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
        map_skill("cuff", "luohan-quan");
        map_skill("club", "weituo-gun");
	map_skill("strike", "sanhua-zhang");
	map_skill("parry", "sanhua-zhang");

	prepare_skill("strike", "sanhua-zhang");

	create_family("������", 38, "����");

	setup();

        carry_object("/d/shaolin/obj/hui-cloth")->wear();
}


#include "/kungfu/class/shaolin/hui.h"


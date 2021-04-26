// huangyi.c ������Ů
// by jiuer 11/01/2001

#include <ansi.h>
inherit NPC;

void create()
{
	object bj;
	int skill_lvl = 170;

	set_name("������Ů", ({ "huangyi girl", "girl"}));
	set("long", 
		"������һϮ��ɴ��Ļ��£������������ס�\n");
	set("gender", "Ů��");
	set("age", 25);
	set("attitude", "peaceful");
	set("shen_type", 1);

	set("str", 20);
	set("int", 25);
	set("con", 25);
	set("dex", 30);

	set("max_qi", 2100);
	set("max_jing", 1850);
	set("jiali", 120);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jingli",3000);
	set("eff_jingli",3000);
	set("max_jingli",3000);

	set("combat_exp", 500000);
	set("score", 50000);

	set_skill("force", skill_lvl);
	set_skill("yunu-xinjing", skill_lvl);
	set_skill("cuff", skill_lvl);
	set_skill("meinu-quan", skill_lvl);
	set_skill("sword", skill_lvl);
	set_skill("yunu-jianfa", skill_lvl);
	set_skill("finger", skill_lvl);
	set_skill("suhan-zhi", skill_lvl);
	set_skill("parry", skill_lvl);
	set_skill("dodge", skill_lvl);
	set_skill("feiyan-gong", skill_lvl);
	set_skill("bee-training",skill_lvl);
	set_skill("lovingness",skill_lvl);
	set_skill("parry",skill_lvl);
	set_skill("suxin-jue",skill_lvl);
	set_skill("zuoyou-hubo",skill_lvl);
	set_skill("throwing",skill_lvl);
	set_skill("whip",skill_lvl);
	set_skill("jueqing-bian",skill_lvl);
	set_skill("finger",skill_lvl);
	set_skill("suhan-zhi",skill_lvl);

	map_skill("force", "yunu-xinjing");
	map_skill("dodge", "feiyan-gong");
	map_skill("cuff", "meinu-quan");
	map_skill("parry", "yunu-jianfa");
	map_skill("sword", "yunu-jianfa");
	map_skill("finger", "suhan-zhi");

	prepare_skill("cuff", "meinu-quan");
	prepare_skill("finger", "suhan-zhi");

	create_family("��Ĺ��", 5, "����");

	setup();

//	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/kungfu/class/gumu/obj/yellow_silk")->wear();
	carry_object("/kungfu/class/gumu/obj/miansha")->wear();
        
}

void init()
{
	object ob;

//	::init();
	return;
}

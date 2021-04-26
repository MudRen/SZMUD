// Code of ShenZhou
// weishi5.c ����

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("����", ({ "fu jiang", "jiang", "general" }) );
	set("gender", "����");
	set("age", 35);
	set("long", "��������λ��������־��Ľ��죬λ�Ӹ���ְ֮��ƽʱ����ʳǵ��ΰ���������\n����������\n");
	set("combat_exp", 300000);
	set("shen_type", 1);
	set("attitude", "heroism");
	set("str", 30);
	set("con", 30);
	set("int", 20);
	set("dex", 30);
	set("max_qi", 1500);
	set("qi", 1500);
	set("max_jing", 1000);
	set("jing", 1000);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jingli", 1000);
	set("max_jingli", 1000);
	set("jiali", 75);
	set("shen_type", 0);
	set_temp("apply/attack",  50);
	set_temp("apply/defense", 50);
	set_skill("sword", 120);
	set_skill("duanjia-jian", 130);
	set_skill("parry", 120);
	set_skill("cuff", 120);
	set_skill("jinyu-quan", 130);
	set_skill("dodge", 120);
	set_skill("duanshi-shenfa", 120);
	set_skill("force", 120);
	set_skill("kurong-changong", 120);
	map_skill("sword","duanjia-jian");
	map_skill("parry","duanjia-jian");
	map_skill("cuff","jinyu-quan");
    map_skill("dodge","duanshi-shenfa");
    map_skill("force","kurong-changong");
    prepare_skill("cuff","jinyu-quan");
	set("no_get", "�㿸����");
	setup();
	carry_object("/d/city/obj/gangjian")->wield();
	carry_object("/d/city/obj/tiejia")->wear();
}
#include "/kungfu/class/dali/condition.h"

// yqquan.c (kunlun)

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("Ҧ��Ȫ", ({ "yao qinqun", "yao" }));
	set("nickname",  CYN"ǧ��׷��"NOR );
	set("gender", "����");
	set("long", "�������������ֵ�.\n");
	set("age", 48);	
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 23);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	
	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 1200);
	set("max_neili", 1200);
	set("jiali", 0);
	set("combat_exp", 300000);

	set_skill("force", 120);
	set_skill("dodge", 120);
	set_skill("parry", 120);
        set_skill("finger", 120);
        set_skill("yiyang-zhi",90);
	set_skill("kurong-changong", 110);

	map_skill("force", "kurong-changong");
	map_skill("finger", "yiyang-zhi");
	map_skill("parry", "yiyang-zhi");

	setup();
        carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 10);
}

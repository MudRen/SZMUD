// zjzhen.c (kunlun)

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("朱九真", ({ "zhu jiuzhen", "zhu" }));
	set("nickname",  CYN"雪岭双姝"NOR );
	set("gender", "女性");
	set("long", "她就是红梅山庄庄主的独生女儿,长的容颜娇媚，又白又腻\n");
	set("age", 18);	
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 29);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	
	set("max_qi", 1000);
	set("max_jing", 600);
	set("neili", 800);
	set("max_neili", 800);
	set("jiali", 0);
	set("combat_exp", 100000);

	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
        set_skill("finger", 100);
        set_skill("yiyang-zhi",30);
	set_skill("kurong-changong", 60);

	map_skill("force", "kurong-changong");
	map_skill("finger", "yiyang-zhi");
	map_skill("parry", "yiyang-zhi");
          prepare_skill("finger", "yiyang-zhi");

	setup();
        carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 10);
}

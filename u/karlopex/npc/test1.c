//Cracked by Roath

inherit NPC;
#include "/u/lisser/npc/name.h"
void create() 
{
	seteuid(getuid());
        set_random_name("����");
        set("gender", "����" );
	set("title","������NPC");	
	set("age", 30);
	set("attitude", "peaceful");
	set("death_times", 1000);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 1000000);
	set("max_jing", 4000);
	set("neili", 10000);
	set("max_neili", 10000);
	set("combat_exp", 6400000);

	set_skill("force", 400);
	set_skill("dodge", 400);
	set_skill("parry", 400);
	set_skill("sword", 400);
	set_skill("strike", 400);
	set_skill("hunyuan-zhang",400);
	set_skill("zixia-gong", 400);
	set_skill("huashan-shenfa", 400);
	set_skill("literate", 400);
	set_skill("cuff", 400);
	set_skill("pishi-poyu", 400);
	set_skill("ziyin-yin", 400);
	set_skill("zhengqi-jue", 400);

	map_skill("cuff", "pishi-poyu");
	map_skill("force", "zixia-gong");
	map_skill("parry", "huashan-jianfa");
	map_skill("sword", "huashan-jianfa");
	map_skill("strike","hunyuan-zhang");
	map_skill("dodge","huashan-shennfa");

	prepare_skill("strike", "hunyuan-zhang");
	prepare_skill("cuff", "pishi-poyu");

	create_family("ؤ��", 30, "����");

	setup();
	carry_object("/d/city/obj/cloth")->wear();
}
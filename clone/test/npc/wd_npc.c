// Code of ShenZhou
// modified from zhang.c 3/00

inherit NPC;
inherit F_MASTER;

#include <ansi.h>
#include "/kungfu/class/wudang/auto_perform.h"

int reset();
int auto_perform();

void create()
{

        set_name("张三丰", ({ "zhang sanfeng", "zhang" }));
        set("nickname", "邋遢真人");
        set("long",
                "这就是武当派开山鼻祖、当今武林的泰山北斗张三丰真人。\n"
                "但见他身穿一袭污秽的灰布道袍，身形高大异常，须发如银，\n"
		"脸上红润光滑，笑眯眯的甚是可亲，此外也无特异情状。\n");
        set("gender", "男性");
        set("age", 100);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        
        set("max_qi", 14123);
        set("max_jing", 4000);
	set("eff_jingli", 5000);
	set("max_jingli", 5000);
        set("neili", 8000);
        set("max_neili", 8000);
        set("jiali", 300);
        set("combat_exp", 6400000);
        set("score", 640000);

        set_skill("force", 400);
        set_skill("taiji-shengong", 400);
        set_skill("dodge", 400);
        set_skill("tiyunzong", 400);
        set_skill("cuff", 400);
        set_skill("taiji-quan", 400);
        set_skill("parry", 400);
        set_skill("sword", 400);
        set_skill("taiji-jian", 400);
        set_skill("taoism", 400);
        set_skill("literate", 400);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("cuff", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");

        prepare_skill("cuff", "taiji-quan");

        create_family("武当派", 1, "开山祖师");
        set("class", "taoist");
        set("chat_chance", 80);
        set("chat_msg", ({
                (: reset :),
        }) );

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );

	setup();
	if( clonep() )
	{
		carry_object("/clone/weapon/changjian")->wield();
		carry_object("/d/wudang/obj/greyrobe")->wear();
	}
}

void die()
{
	object ob, me;
	me = this_object();

	if( !living(this_object()) ) revive(1);
	::die();
}

int reset()
{
        object me = this_object();
	if( me->query("eff_qi") < me->query("max_qi") )
		exert_function("heal");
	me->set("jiali", 300);
	command("wield sword");

	return 1;
}

// Code of ShenZhou
// Npc: /kungfu/class/emei/jingxian.c 静闲师太
// Date: xbc 96/09/22
// Modified by xQin 8/00
inherit NPC;

string ask_for_join();
string ask_for_huansu();
int auto_perform();

void create()
{
        set_name("静闲师太", ({
                "jingxian shitai",
                "jingxian",
                "shitai",
	}));
	set("long",
		"她是一位慈祥的年轻师太，在清音阁修行。\n"
		"她是灭绝师太的八大静字辈弟子之七，最擅长掌法与剑法。\n"
	);

	set("gender", "女性");
	set("attitude", "friendly");
	set("class", "bonze");

        set("inquiry",([
                "出家"  : (: ask_for_join :),
                "还俗" : (:ask_for_huansu:),
        ]));

	set("age", 30);
	set("shen_type", 1);

	set("str", 26);
	set("int", 20);
	set("con", 20);
	set("dex", 25);

	set("max_qi", 600);
	set("max_jing", 600);
	set("neili", 800);
	set("max_neili", 800);
	set("jiali", 40);
	set("combat_exp", 300000);
	set("score", 1000);

        set_skill("force", 70);
        set_skill("linji-zhuang", 70);
        set_skill("finger", 80);
        set_skill("tiangang-zhi", 80);
        set_skill("strike", 80);
        set_skill("jinding-zhang", 80);
        set_skill("sword", 80);
        set_skill("emei-jian", 80);
        set_skill("parry", 70);
        set_skill("dodge", 70);
        set_skill("zhutian-bu", 70);
        set_skill("persuading", 80);
        set_skill("mahayana", 80);
        set_skill("literate", 80);

        map_skill("force", "linji-zhuang");
        map_skill("strike", "jinding-zhang");
        map_skill("sword", "emei-jian");
        map_skill("finger", "tiangang-zhi");
        map_skill("parry", "jinding-zhang");
        map_skill("dodge", "zhutian-bu");

	prepare_skill("strike", "jinding-zhang");
	prepare_skill("finger", "tiangang-zhi");
	create_family("峨嵋派", 4, "弟子");

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );

	setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/emei/npc/obj/nun-cloth")->wear();
        carry_object("/d/emei/npc/obj/emei-shoes")->wear();

}
void init()
{
        object ob;

	::init();
        add_action("do_kneel", "kneel");

        if (interactive(ob=this_player()) 
	&& ob->query("family/master_id") == "jingxian shitai"
	&& ob->query("shen") < -100 ) 
	{
       	 	message_vision(
                "$n看着$N说道：你怎么在外边做坏事？\n",
                ob, this_object() );
		command("say 我峨嵋派乃是堂堂名门正派，" +
                        "对弟子要求极严。我不能再收留你，你去吧。\n");
                command("expell " + ob->query("id"));
                return;
        }

        if (interactive(ob=this_player()) 
	&& ob->query("family/master_id") == "jingxian shitai"
        && ob->query("class") !=  "bonze" )                 
	{
		message_vision(
                        "$n看着$N说道：你既然还了俗，还是去找你俗家师叔学艺吧。\n");
                ob->delete("family/master_name");
                ob->delete("family/master_id");
                return;
        }
}

#include "/kungfu/class/emei/jing2.h"
#include "/kungfu/class/emei/auto_perform.h"
#include "/kungfu/class/emei/nun.h"


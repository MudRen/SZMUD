// Code of ShenZhou
// /kungfu/class/emei/su.c 苏梦清
// shan: 96/08/22

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

int auto_perform();
void create()
{
        set_name("苏梦清", ({ "su mengqing", "su", "mengqing" }));
        set("long", 
		"她是灭绝师太的八大俗家第子之一，擅长回风拂柳剑。\n");
	set("gender", "女性");
	set("age", 35);
	set("attitude", "peaceful");
	set("shen_type", 1);

	set("str", 25);
	set("int", 20);
	set("con", 20);
	set("dex", 25);
	
	set("max_qi", 500);
	set("max_jing", 500);
	set("neili", 800);
	set("jiali", 20);
	set("max_neili", 800);

	set("combat_exp", 100000);
	set("score", 1000);

        set_skill("force", 60);
        set_skill("linji-zhuang", 70);
        set_skill("finger", 70);
        set_skill("tiangang-zhi", 70);
        set_skill("strike", 70);
        set_skill("jinding-zhang", 70);
        set_skill("sword", 80);
        set_skill("emei-jian", 80);
        set_skill("parry", 70);
        set_skill("dodge", 80);
        set_skill("zhutian-bu", 80);
        set_skill("throwing", 40);
        set_skill("persuading", 40);

        map_skill("force", "linji-zhuang");
        map_skill("strike", "jinding-zhang");
        map_skill("finger", "tiangang-zhi");
        map_skill("sword", "emei-jian");
        map_skill("blade", "yanxing-dao");
        map_skill("parry", "emei-jian");
        map_skill("dodge", "zhutian-bu");

	prepare_skill("strike", "jinding-zhang");
	prepare_skill("finger", "tiangang-zhi");

	create_family("峨嵋派", 4, "弟子");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );

        set("inquiry", ([
		"出家" : "你去本山的庵堂里找我静字辈师姐吧。她们在福寿庵、千佛庵、\n万年庵、万行庵和卧云庵修行。\n",
            "灭绝师太" : "她是本派掌门人，在华藏庵修行。\n",
        ]));

	setup();
	carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/emei/npc/obj/hui-cloth")->wear();
        carry_object("/d/emei/npc/obj/emei-shoes")->wear();

}

void init()
{
        object ob;

	::init();
        if (interactive(ob=this_player()) && ob->query("family/master_id") == "su mengqing" 
        && ob->query("shen") < -100 ) {
        message_vision(
                "$n看着$N说道：你怎么在外边做了坏事？我峨嵋派乃是堂堂名门正派，" +
			"对弟子要求极严。我不能再收留你，你去吧。\n",
                ob, this_object() );
                command("expell " + ob->query("id"));
		ob->delete("emei_shen");
		return;
        }
        if (interactive(ob=this_player()) && ob->query("family/master_id") == "su mengqing"
        && ob->query("class") == "bonze" ) {
		if (ob->query("gender") == "女性") {
        	message_vision(
                	"$n看着$N说道：你既然出了家，在我这里怎样修行？\n",
        		ob, this_object() );
           	command("say 我看你不如找个庵堂跟我静字辈师姐学艺吧。\n");
		ob->delete("family/master_name");	
                ob->delete("family/master_id");
		return;
		}
                message_vision(
                        "$n看着$N说道：你既然出了家，在我这里怎样修行？\n",
                        ob, this_object() );
                command("say 我看你不如去少林寺寻师吧。\n");
                ob->delete("family/master_name");
                ob->delete("family/master_id");
                return;
        }
       
}

#include "/kungfu/class/emei/sujia.h"
#include "/kungfu/class/emei/auto_perform.h"

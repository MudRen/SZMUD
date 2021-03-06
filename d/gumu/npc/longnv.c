// longnv.c 小龙女
// by April 01/08/03
// update 01/08/06

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	object bj;

        set_name("小龙女", ({ "xiao longnv", "long", "longnv" }));
        set("long", 
                "她披著一袭轻纱般的白衣，宛若身在烟中雾里的女神。她看起来不到三十岁，除了\n"
				+"一头披肩的黑发之外，全身素白。她面容秀美绝俗，只是肌肤间少了一层血色，显得\n"
				+"苍白异常。\n");
        set("gender", "女性");
		set("nickname","神雕侠侣");
        set("age", 38);
        set("attitude", "peaceful");
        set("shen_type", 1);

        set("str", 20);
        set("int", 25);
        set("con", 25);
        set("dex", 30);
        
        set("max_qi", 4000);
        set("max_jing", 5500);
        set("jiali", 200);
        set("neili", 6000);
        set("max_neili", 6000);
		set("jingli",4000);
		set("eff_jingli",4000);
		set("max_jingli",4000);

        set("combat_exp", 4500000);
        set("score", 10000);

        set_skill("force", 300);
        set_skill("yunu-xinjing", 300);
        set_skill("cuff", 300);
        set_skill("meinu-quan", 300);
        set_skill("sword", 320);
        set_skill("yunu-jianfa", 320);
        set_skill("finger", 300);
        set_skill("suhan-zhi", 300);
        set_skill("parry", 300);
        set_skill("dodge", 350);
        set_skill("feiyan-gong", 350);
		set_skill("bee-training",320);
		set_skill("lovingness",400);
		set_skill("parry",300);
		set_skill("suxin-jue",400);
		set_skill("zuoyou-hubo",300);
		set_skill("throwing",320);
		set_skill("whip",300);
		set_skill("jueqing-bian",300);
		set_skill("finger",300);
		set_skill("suhan-zhi",300);

        map_skill("force", "yunu-xinjing");
        map_skill("dodge", "feiyan-gong");
        map_skill("cuff", "meinu-quan");
        map_skill("parry", "yunu-jianfa");
        map_skill("sword", "yunu-jianfa");

        prepare_skill("cuff", "meinu-quan");

        create_family("古墓派", 3, "弟子");

		set("spouse/id", "yang guo");
		set("spouse/name", "杨过");
		set("spouse/title", "丈夫");

        set("chat_chance_combat", 50);

        setup();

        if( clonep() )
        {
                bj=carry_object("/d/gumu/obj/shunv-jian");
                if( objectp(bj) ) bj->wield();
					else carry_object("/clone/weapon/changjian")->wield();
				carry_object("/d/gumu/obj/white_silk")->wear();
        }
}

void init()
{
        object ob;

        ::init();
        return;
       
}

void attempt_apprentice(object ob)
{
    mapping fam;
	
	if (ob->query_per() < 25) {
		// 容貌<25不收
	    command("say 我派武功博大精深，非凡夫俗子可为。你去吧...");
		return;
	}

	if (ob->query("gender")!="女性"){
		// 只收女性
		command("say 若想学得刚猛武功就去找我丈夫杨过吧。");
		return;
	}

	command("say 好吧，我就收下你了。");
    command("recruit " + ob->query("id"));
}


// Code of ShenZhou
// xunbu.c 巡捕
// Fang 8/21/96
// modified Zhuang@XKX 960903
//
// This NPC is confined in the city now.
//
// if we call ::init() in init(), they'll start autofight because of hatred
// even after a player's death, which is not good.
//

#include <ansi.h>
inherit NPC;

private string *home_locations = ({
	"/d/quanzhou/gushao",
	"/d/quanzhou/xiqiao",
	"/d/quanzhou/alabo",
	"/d/quanzhou/citong_e2",
	"/d/quanzhou/jishi"
});

void create()
{
	set_name("巡捕", ({ "xun bu", "bu" }));
        set_color("$YEL$");
	set("age", 32);
	set("gender", "男性");
	set("long", "这是一个经验老到的巡捕，一双精明的眼睛冷冷地盯着你。\n");
	set("attitude", "heroism");
//	set("vendetta_mark", "authority");
	set("pursuer", 1);

	set("str", 24);
	set("dex", 16);
	set("combat_exp", 20000);
	set("shen_type", 0);

	set_skill("unarmed", 35 + random(10));
	set_skill("dodge", 35 + random(10));
	set_skill("parry", 35 + random(10));
	set_skill("blade", 35 + random(10));
	set_skill("force", 35 + random(10));
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);
        set("chat_chance", 5);
        set("chat_msg", ({
                "巡捕大喊: 闪开！\n",
                (: random_move :)
        }) );

        set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
		"巡捕喝道：大胆刁民，竟敢造反不成？\n",
		"巡捕喝道：跑得了和尚跑不了庙，你还是快快束手就擒！\n",
	}));
	setup();
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/armor/junfu")->wear();
}

void init()
{
	if( strsrch(file_name(environment()), "/d/quanzhou/") == -1 ) {
		message_vision("$N快步走了过来。\n$N神色慌张地离开了。\n", this_object());
		this_object()->move(home_locations[random(sizeof(home_locations))]);
		message_vision("$N快步走了过来。\n", this_object());
		return;
	} else if( interactive(this_player())
	&& (int)this_player()->query_condition("killer") ) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, this_player());
	} else if( is_killing(this_player()->query("id")) )
		remove_killer(this_player());
}

int accept_fight(object me)
{
        command("say 小的有公务在身，不能与你过招。\n");
        return 0;
}

int accept_kill(object me)
{
        command("say 你这是太岁头上动土，活得不耐烦了！明年此时就是你的忌日！\n");
        me->apply_condition("killer", 100);
        kill_ob(me);
        return 1;
}


// Code of ShenZhou
// jin.c 金老板
// chchong 2002.01.31
//  /d/changan/npc/jin.c

#include <ansi.h>
#include <dbase.h>

inherit NPC;
inherit F_DEALER;

string ask_me();

void create()
{
        set_name("金老板", ({ "jin laoban", "jin" }));
        set_color("$YEL$");
        set("title", "金玉楼楼老板");
	set("shen_type", 1);

	set("str", 20);
	set("gender", "男性");
	set("age", 55);
        set("long", "金老板一手开创的金玉楼驰名长安城。\n");
	set("combat_exp", 60000);
        set("qi", 300);
        set("max_qi", 300);
	set("attitude", "friendly");
	set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);

	set("vendor_goods", ({
                "/d/quanzhou/obj/hdjiudai",
                "/d/quanzhou/obj/fotiao",
	}));
            	
	setup();
        add_money("gold", 1);
}

void init()
{
	::init();
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

int accept_kill(object me)
{
        command("say 光天化日之下竟敢行凶杀人，没王法了吗？\n");
        me->apply_condition("killer", 100);
        kill_ob(me);
        return 1;
}

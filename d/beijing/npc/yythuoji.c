// Code of ShenZhou
// /d/beijing/npc/yythuoji.c

#include <ansi.h>
#include <localtime.h>

inherit NPC;
inherit F_DEALER;

int do_look(string);
int env_cmp(object o1, object o2);

void create()
{
        set_name("一言堂伙计", ({ "huoji", "huo ji" }) );
		set_color(YEL);
        set("long", "这是一言堂的领班伙计。\n");
        set("gender", "男性");
        set("age", 20);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 25);
        set("int", 23);
        set("con", 19);
        set("dex", 20);
        set("max_qi", 300);
        set("max_jing", 300);
        set("neili", 400);
        set("max_neili", 400);
        set("combat_exp", 80000);

        set_skill("literate", 100);
        set_skill("dodge", 30); 
		set_skill("force", 30);
		set_skill("parry", 30);
		set_skill("unarmed", 30);

        set("inquiry", ([
                "name" : "我就是一言堂伙计。" ,
                "here" : "这是京城一言堂。你可以问我 exchange, 兑换 ",
				"exchange" : "兑换奖励可以用 exchange xxx 来实现，xxx 代表相应的奖励。",
				"兑换" : "兑换奖励可以用 exchange xxx 来实现，xxx 代表相应的奖励。",
        ]) );

        setup();
        carry_object("d/city/obj/cloth")->wear();
}

int init()
{
  object ob;
  ob = this_player();
  ::init();

  if( interactive(ob = this_player()) && !is_fighting() ) {
       remove_call_out("greeting");
       call_out("greeting", 1, ob);
  }

}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        message_vision(	"$N朝$n微微笑了笑。\n",this_object(),ob );
        switch( random(2) ) {
                case 0:
                        command( "say 这位" + RANK_D->query_respect(ob)
                                + "，想要兑换奖励吗？这可找对人了。\n");
                        break;
                case 1:
                        command( "say 这位" + RANK_D->query_respect(ob)
                                + "，我这有各种价值不菲的物品，看看您想要兑换哪一件。\n");
                        break;
        }
}
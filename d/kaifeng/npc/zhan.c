//npc: /d/kaifeng/zhan.c
//by bravo
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("展昭", ({"zhan zhao","zhan"}));
       set("long",
                "一位威风凛凛的捕头，身材不高，但是两眼有神。\n"
                "据说中原一带的草寇都惧他三分。\n"
        );
       set("nickname", HIR" 御猫"NOR);
        set("gender", "男性");
        set("attitude", "peaceful");
        
        set("age", 25);
        set("shen", 10000);
        set("str", 35);
        set("int", 20);
        set("con", 30);
        set("dex", 35);
        set("per",35);
        set("max_qi", 2000);
        set("max_jing", 2000);
        set("neili", 3500);
        set("max_neili", 3500);
        set("jiali", 120);
        set("combat_exp", 350000);
        set("startroom","/d/kaifeng/ximen");

        set_skill("force", 200);
        set_skill("buddhism",200);
        set_skill("claw",200);
        set_skill("hunyuan-yiqi",200);
        set_skill("longzhua-gong", 200);
        set_skill("dodge", 200);
        set_skill("shaolin-shenfa", 200);
        set_skill("parry", 200);
        set("chat_chance", 20);
        set("chat_msg", ({
               "展昭挺了挺胸脯，朗声笑道：“听说本官来了，那些为非做歹的人无一不闻风而逃。 \n",
               (: random_move :)
       }) );
        map_skill("force", "hunyuan-yiqi");


        map_skill("dodge", "shaolin-shenfa");
        map_skill("parry", "longzhua-gong");
        map_skill("claw", "longzhua-gong");
       prepare_skill("claw", "longzhua-gong");

        setup();
        carry_object("/clone/armor/armor")->wear();
}

void init()
{
        object me, ob;

        ::init();

        ob = this_player();
        me = this_object();
        if (interactive(ob) 
        && !environment(ob)->query("no_fight")
        && (int)ob->query("PKS",1) >36 )
        {
 


         command("say  听说你最近做了不少坏事，今天就和本官走一趟。\n");
         remove_call_out("hiting_ob");
         call_out("hiting_ob", 1, ob);
                 
        }       
}
int hiting_ob(object ob)
{
        object me;
        me=this_object();
        me->set_leader(ob);
         ob->fight_ob(me);
        me->fight_ob(ob);
        remove_call_out("moving_ob");
        call_out("moving_ob",1,ob);
}
int moving_ob(object ob)
{
        if (!ob) return 0;
       if (!living(ob)&&present(this_player(), environment(this_object()))){
        switch( random(3) ) {
        case 0:

                command("say 在开封府撒野还想跑，让你尝尝我的厉害！");

        break;
        case 1:
                command("say  你给我老老实实去呆着吧。");
        break;
        case 2:
                command("nod");
        break;
        }
        ob->move("/d/city/dalao"); 
        ob->set("eff_jing",1);           
        }
        else {
        remove_call_out("hiting_ob");
        call_out("hiting_ob",1,ob);
        }
}

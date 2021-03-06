// Code of ShenZhou
// npc: /d/xingxiu/npc/ke.c
// Jay 3/27/96

#include "ansi.h"
inherit NPC;
inherit F_MASTER;


void create()
{
        set_name("欧阳锋", ({ "ouyang feng", "ouyang", "feng" }));
        set("long", "他身形高大，高鼻深目，满脸雪白短须，根根似铁。\n"
                "他极善使毒，号称“西毒”。\n");
        set("nickname","西毒");
        set("title", "白驼山庄庄主");
        set("gender", "男性");
        set("age", 65);

        set("lingshe_count",3);
        set_skill("cuff", 400);
        set_skill("lingshe-quan", 400);
        set_skill("shentuo-zhang", 400);
        set_skill("strike", 360);
        set_skill("dodge", 360);
        set_skill("chanchubu", 360);
        set_skill("parry", 360);
        set_skill("force", 360);
        set_skill("hamagong", 400);
        set_skill("lingshe-zhang",400);
        set_skill("staff",400);
        set_skill("poison",400);
        set_skill("training",360);
        map_skill("strike","hamagong");
        map_skill("staff","lingshe-zhang");
        map_skill("dodge","chanchubu");
        map_skill("parry", "lingshe-zhang");
        map_skill("staff","lingshe-zhang");
        map_skill("force","hamagong");
        prepare_skill("strike","hamagong");

        set("str", 33);
        set("int", 28);
        set("con", 29);
        set("dex", 28);

        set("max_qi", 5500);
        set("qi",5500);
        set("max_jing", 3000);
        set("jing",3000);
        set("neili", 6000);
        set("max_neili", 6000);
        set("jiali", 0);
        set("combat_exp", 3600000);

                  set("attitude", "peaceful");
                  set("shen_type", -1);

                  create_family("白驼山", 1 , "庄主");
        /*        set("chat_chance_combat", 50);
                  set("chat_msg_combat", ({
                         (: auto_perform :),
                  }) );*/
        set("inquiry", ([
                "西毒" : "既有了西毒这个名号，若非在这“毒”字功夫上稍有独得之秘，未免愧对诸贤。",
        ]));

        setup();
        carry_object("/d/baituo/obj/lingshezhang")->wield();
        carry_object("/d/baituo/obj/wcloth")->wear();

}

void init()
{
        object ob, me;
        ::init();
        /*
        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        */
        
}


void greeting(object me)
{
        int sxds, hand;

        sxds = me->query_skill("shexing-diaoshou",1);
        hand = me->query_skill("hand",1);

        if (me->query("family/family_name") != "白驼山") {
                me->apply_condition("snake_poison", 
                2 + me->query_condition("snake_poison"));
        }

        if( me->query("family/family_name") == "白驼山" 
        && !me->query("baituo_updated") ) {
                me->set_skill("cuff", hand);
                me->set_skill("lingshe-quan", sxds);
                me->delete_skill("hand");
                me->delete_skill("shexing-diaoshou");
                me->set("baituo_updated",1);
        }

        if (me->query("enter_shegu")) {
                if ( environment(me) != environment(this_object())) return;

                me->delete("enter_shegu");

                if (me->query("family/family_name") != "白驼山") {
                        command("hehe "+me->query("id"));
                        command("say "+me->name()+RANK_D->query_rude(me)+"，竟敢擅闯蛇谷，我若不将你折磨得死不成活不了，岂不枉称“西毒”名号？");
                        command("perform shoot "+me->query("id")); //for weapon
                        kill_ob(me);
                }
                else if (me->query("family/family_name") == "白驼山" 
                && !me->query("baituo/shegu_permit") ) {
                        command("slap "+me->query("id"));
                        command("say 谁叫你擅入蛇谷的？");
                        message_vision(HIR"欧阳锋在$N的肩头重重按了一掌，蛤蟆功劲力直透腑脏，登时震得$N面如白纸，汗如雨下。\n"NOR, me);
                        me->set("neili", 0);
                        me->set("jingli", me->query("jingli")/10);
                        me->set("qi", me->query("qi")/10);
                        me->start_busy(3);
                        command("say 这点惩罚，算是便宜你了。不许再有下次！");
                }
        }
        return;
}

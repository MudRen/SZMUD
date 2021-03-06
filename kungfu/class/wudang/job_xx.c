         // job_xx.c xx NPC
// CODE BY SCATTER
// 1/12/2002

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void init()
{
        object ob, me;
        int btime;
        string target;

        ob = this_object();
        me = this_player();

        target = ob->query_temp("wd/target");
        btime = ob->query_temp("wd/btime");

                if( me->query("id") == target )
                {
                                                ob->add_temp("wd/btime", 2);
                        me->start_busy(btime);
                        command("kill " + target);
                                                remove_call_out("check_player");
                                                call_out("check_player", 5, me, ob);
                }
}

void check_player(object me, object ob)
{
        if( me->query_skill_mapped("force") != "taiji-shengong" )
        {
                write("\n你武当的太极神功还没激发，导致你气血逆转．\n");
                me->unconcious();
                return;
        }
        
        remove_call_out("check_player");
        call_out("check_player", 5, me, ob);
        return;
}
        

void create()
{
        set_name("雪山弟子", ({ "Xueshan Dizi", "xueshan", "dizi" }));
        set("long", "看起来他武功非凡。\n");
        set("gender", "男性");
        set("age", 35);
        set("attitude", "peaceful");
        set("shen_type", 1);

        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 60);
        set("combat_exp", 1000000);
        
        setup();
}


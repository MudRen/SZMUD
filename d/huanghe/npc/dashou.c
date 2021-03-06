 //Cracked by yujie
// /d/huanghe/npc/dashou.c
// Last Modify By Scatter

inherit NPC;
inherit F_SSERVER;

#include "/d/huanghe/doc/bangskills.h"
#include "/d/huanghe/doc/info_biao.h"
#include <ansi.h>
#include <dbase.h>
#include <login.h>
#include <move.h>

#define BIAOHUO "/d/huanghe/obj/biaohuo"

void checking();

void create()
{
        string *biaojus, biaoju;
        
        biaojus = keys(info_biaoju);
        biaoju = biaojus[random(sizeof(biaojus))];

        set_name("打手", ({ "da shou","fighter" }));
        set("nickname", "拿人钱财，替人消灾");
        set("gender", "男性");
        set("age", 35);
        set("long",
"一名凶狠的打手，看来似乎很强壮。\n");
        set("attitude", "friendly");
        set("shen_type", -1);

        set("str", 24);
        set("int", 10);
        set("con", 24);
        set("dex", 24);
    

        setup();
        remove_call_out("checking");
        call_out("checking",2);
        
}

void start_call()
{
        object ob;
        if ( !objectp (ob = query("killob")) )
                return;
        
        remove_call_out("killer_check");
        call_out("killer_check",600,this_object(),ob);
        return;
}

void killer_check(object ob, object me)
{
        object ling;
        
        if ( !objectp(ob) )
                return;
                
        if ( !userp(me) )
                return;
        
        if ( present(me,environment(ob)) )
        {       remove_call_out("killer_check");
                call_out("killer_check",600,this_object(),ob);
                return;
        }
        
        if ( objectp (ling = present("bang ling",me)) )
                ling->set("job/is_kill", 0);
                
        tell_object(environment(ob),"打手冷哼了一句：胆小鬼。然后扬长而去！\n");
        destruct(ob);
        return;
}

void die()
{
        object ob, corpse, killer;

        if( !living(this_object()) ) revive(1);
        clear_condition();

        if (!objectp(query_temp("last_damage_from"))) return;
        else killer = query_temp("last_damage_from");
        if ( !objectp (ob = query("killob")) )
        {
                ::die();
                return;
        }
                
        if (killer->query("id")==ob->query("id"))
            ob->set("job/killer","me");
        else 
            ob->delete("job/killer","another");

        COMBAT_D->announce(this_object(), "dead");
        if( objectp(corpse = CHAR_D->make_corpse(this_object(), killer)) )
                corpse->move(environment());
        remove_all_killer();
        all_inventory(environment())->remove_killer(this_object());

        dismiss_team();
        remove_call_out("killer_check");
        destruct(this_object());
}

void checking()
{
        object ob, temp, me=this_object();
        string name;
        
        if(!objectp(query("killob")))
        {
                write("打手冷哼了一声，扬长而去。\n");
                destruct(me);
                return;
        }

        name = geteuid(query("killob"));
        temp = find_player(name);
        if (objectp(temp) && !userp(temp)) return;
        name = temp->query("name");
        
        
        if( objectp(ob = present("corpse", environment())) && ob->query("victim_name") == name )
        {
                tell_object(environment(),"打手对着尸体冷哼了一声，扬长而去。\n");
                destruct(this_object());
        }
        remove_call_out("checking");
        call_out("checking",2);
        return;
}

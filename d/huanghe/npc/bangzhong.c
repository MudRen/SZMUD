// Code of ShenZhou
// /d/huanghe/npc/bangzhong.c
// skills and exp are set up by message_bangzhu.h file
// by aln 2/98

#include <ansi.h>

inherit NPC;
inherit F_SSERVER;

int auto_check();
int do_destroy(object);

void create()
{
        set_name("����", ({ "bangzhong" }));
        set("gender", "����");
        set("age", 20 + random(10));
        set("long",
"һ����ĸߴ��׳��������ɱ����һ�������ɷ��ģ����\n");
        set("attitude", "friendly");
        set("shen_type", -1);

        set("str", 24);
        set("int", 10);
        set("con", 24);
        set("dex", 24);

        set("combat_exp", 30000);

        set("chat_chance", 5);
        set("chat_msg", ({
                (: auto_check :),
        }) );

        setup();
}

void init()
{
        ::init();

        add_action("do_check", "exert");
        add_action("do_check", "yun");
}

int do_check(string arg)
{
        object ob;
        string what, who;

        if( !arg ) return notify_fail("");

        if( arg != "play" ) {
                 if( sscanf(arg, "%s %s", what, who) != 2 )
                          return notify_fail("");

                 if( what != "play" )
                          return notify_fail("");
        }

        if( !(ob = query("owner")) ) 
                 return notify_fail("");

        if( environment(ob) != environment() )
                 return notify_fail("");

        return 1;
}

int auto_check()
{
        object me = this_object();
        object ob, dest, room, victim;

        if( !living(me) ) return 1;

        if( !(ob = query("owner")) )
                return do_destroy(me);

        if( !(dest = environment(ob)) )
                return do_destroy(me);

        room = environment();
        if( room != dest ) {
                message("vision",
                        me->name() + "����ææ���뿪�ˡ�\n",
                        room, ({me}));
                me->move(dest);
                message("vision",
                        me->name() + "���˹�����\n",
                        dest, ({me}));

                me->set_leader(ob);
                message_vision("$N�ϻ̳Ͽֵ�˵����������ˡ�\n", me);
                return 1;
        }

        if( !ob->is_fighting() ) return 1;

        if( !living(victim = offensive_target(ob)) ) return 1;

        if( !is_fighting(victim) )
                kill_ob(victim);

        return 1;
}

int do_destroy(object ob)
{
        message("vision",
                ob->name() + "����ææ���뿪�ˡ�\n",
                environment(ob), ({ob}));

        destruct(ob);
        return 1;
}

int accept_kill(object me)
{
        object ob;

        if( !(ob = query("owner")) ) return 1;

        if( environment(ob) != environment()
        || !living(ob)
        ||  ob->is_busy()
        ||  ob->is_killing() ) return 1;

        message_vision("$N��$n�ȵ��������ҵ��֣����Ӳ�С��\n", ob, me);
        ob->kill_ob(me);
        return 1;
}

#include <ansi.h>
#include <dbase.h>
#include <login.h>
#include <move.h>

void die()
{       
        object ob, corpse, killer, obj;
        int bonus, record,addscore;

        if( !living(this_object()) ) revive(1);
        clear_condition();

        if( objectp(killer = query_temp("last_damage_from")) ) {
        if( (string)killer->query_temp("bangs/victim") == query("title") ) {
                
                bonus = (int)query("combat_exp");
                bonus = bonus * 100/ (bonus + (int)killer->query("combat_exp"));
                
                if( obj = present("bang ling", killer) ) 
                {
                addscore=obj->query("score")/10000;
                if (addscore>30) addscore=30;
        	bonus = bonus + addscore;
        	
                record = bonus * 3 - random(bonus/2);
                killer->add("combat_exp", record);

                log_file("BangJob", sprintf("%s��%sʱ��ɱ��ʾ����%s�����\n", killer->query("name"), ctime(time()), chinese_number(record)));

                obj->delete("job");
                
                killer->add("clbscore",bonus);
                                
                }
        }
        }

        COMBAT_D->announce(this_object(), "dead");
        if( objectp(killer) )
        {
        	if( (string)killer->query_temp("bangs/victim") == query("title") )
        	{
        	tell_object(killer,HIW"����ι������õ�"+chinese_number(bonus)+"�㹦�͵㣬" + chinese_number(record)+ "�㾭��ֵ��\n"NOR);
        	killer->delete_temp("bangs/victim");
        	}
        }
        if( objectp(corpse = CHAR_D->make_corpse(this_object(), killer)) )
                corpse->move(environment());
        remove_all_killer();
        all_inventory(environment())->remove_killer(this_object());

        dismiss_team();
        destruct(this_object());
}



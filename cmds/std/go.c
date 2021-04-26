// Code of ShenZhou
// go.c
// modified by sdong for biaoche, 12/23/98
//changed by wzfeng 99/12/2
//changed by maco for play 1/18/2000 
//changed by FunBoo for blocking, before use dex to compare, now use dodge.

#include <ansi.h>;
inherit F_CLEAN_UP;

mapping default_dirs = ([
        "north":        "��",
        "south":        "��",
        "east":         "��",
        "west":         "��",
        "northup":      "����",
        "southup":      "�ϱ�",
        "eastup":       "����",
        "westup":       "����",
        "northdown":    "����",
        "southdown":    "�ϱ�",
        "eastdown":     "����",
        "westdown":     "����",
        "northeast":    "����",
        "northwest":    "����",
        "southeast":    "����",
        "southwest":    "����",
        "up":           "��",
        "down":         "��",
        "out":          "��",
        "enter":        "��",
        "in":           "��",
        "left":         "��",
        "right":        "��",
]);

string day_event(){return NATURE_D->outdoor_room_event();}

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        string dest, mout, min, dir, rided_name, result;
        object env, obj, rided, rider, ob, play_ob,room,wo=this_player();
        mapping exit;
        object *f_obs,thing=wo->query_temp("weapon");
        int time;
        me->update_age(); 
        time = ((me->query("mud_age"))-(me->query("pktime"))); 

        if( !arg ) return notify_fail("��Ҫ���ĸ������ߣ�\n");

        if( me->over_encumbranced() )
                return notify_fail("��ĸ��ɹ��أ��������á�\n");

        if( me->is_busy() )
                return notify_fail("��Ķ�����û����ɣ������ƶ���\n");
                ////////////////////////////////////////////////////////////////////////
                //add by wzfeng
                if(me->query_temp("cannot_move"))
                        if(me->query_temp("cannot_move_msg"))
                                return notify_fail(me->query_temp("cannot_move_msg")+"\n");
                        else
                                return notify_fail("�����ڲ����ƶ���\n");
///////////////////////////////////////////////////////////////////////////
        if (me->is_fighting()) {
                f_obs = me->query_enemy();
                if (objectp(f_obs[0]))
                if (5 + random((int)me->query("dex")) <=
                        random((int)f_obs[0]->query("dex"))) {
                        me->start_busy(1);
                        return notify_fail("������ʧ�ܡ�\n");
                }
        }

        if( me->query("jingli") < me->query("max_jingli")/10 )
                return notify_fail("���Ѿ���ƣ�������������á�\n");

        env = environment(me);
        if(!env) return notify_fail("������Ҳȥ���ˡ�\n");

        if( !mapp(exit = env->query("exits")) || undefinedp(exit[arg]) ) {
                if( query_verb()=="go")
                        return notify_fail("�������û�г�·��\n");
                else
                        return 0;
        }

        if( !env->valid_leave(me, arg) ) return 0;

        if( !stringp(dest = me->query_temp("new_valid_dest")) ) 
                dest = exit[arg];

        if( !(obj = load_object(dest)) )
                return notify_fail("�޷��ƶ���\n");

        me->delete_temp("new_valid_dest");

        if( objectp(rided = me->query("rided")) 
        && environment(rided) == env
        && me->query("race") == "����" )
                rided_name = rided->name();
        else me->delete("rided");
             
        if( obj->query("day_shop")
        && ( day_event() == "event_night" || day_event() == "event_midnight")
        && env->query("outdoors"))
                return notify_fail(obj->query("short")+"���ϲ�������������������\n");
       if( time < 3600 && obj->query("canScheme") && !wizardp(me)) return notify_fail(HIG"��һ��ɱ�����Ǹ��ط������ȥ��\n"NOR);

        if(!me->query("newjob/dwelling")
         && obj->query("owner") == me->query("id")
         && obj->query("short")[7..14] == "���ݴ��")
        {
                tell_object(me,HIG"����סַ��ʱ����Ϊ����"+obj->query("short")[15..<8]+"����\n"NOR);
                me->set("newjob/dwelling",obj->query("short")[15..<8]);
        }

        if( objectp(rided) && !env->valid_leave(rided, arg) )
                return notify_fail("�㲻������" + rided_name + "ͨ����\n");

        if( me->query("race") == "����" && me->query_temp("riding") ) {
                if( present( "biao che", environment(me) ) )
                        return notify_fail("���������ڳ����أ�\n");
      else me->delete_temp("riding");
        }


        if( me->query("race") == "����" && objectp(rided) ) {
                if( !obj->query("outdoors") )
                        return notify_fail("�㲻������" + rided_name + "��ȥ��\n");
                if( obj->query("cost") > rided->query("ability") )
                        return notify_fail(rided_name + "������ط������߲����ˣ�\n");
        } else  if( me->query("race") == "����" 
        && ( !obj->query("outdoors") 
        || obj->query("cost") > me->query("ability") ) ) return 0;

        if( !undefinedp(default_dirs[arg]) )
                dir = default_dirs[arg];
        else
                dir = arg;

        if( me->is_fighting() ) {
                if( me->query("race") == "����" ) {
                        if( objectp(rided)  ) {
                                mout = "����" + rided_name + "������" + dir + "��Ķ����ˡ�\n";               
                                min = "����" + rided_name + "����ײײ�����˹�����ģ����Щ�Ǳ���\n";
                        }
                        else {    
                                mout = "��" + dir + "��Ķ����ˡ�\n";
                                min = "����ײײ�����˹�����ģ����Щ�Ǳ���\n";
                        }
                }
                else {    
                        mout = replace_string( me->query("fleeout_message"), "$d", dir );
                        min  = me->query("fleein_message");
                }
        } 
        else {
                if( me->query("race") == "����" ) {
                        if( env->query("outdoors") ) {
                                if( objectp(me->query("rided")) ) {
                                        mout = "����" + rided_name + "��" + dir + "�ɳ۶�ȥ��\n";
                                        min  = "����" + rided_name + "���۹�����\n";
                                }
                                else {
                                                                        if( objectp(wo->query_temp("weapon")) ){
                                        mout = "������" + dir + "�뿪��\n";
                                                                                min = "����"+thing->query("name")+"�첽���˹�����\n";}
                                                                        else{
                                        mout = "������" + dir + "�뿪��\n";
                                                                                min = "�첽���˹�����\n";}

                                }
                        }
                        else 
                                                { 
                                                if( objectp(wo->query_temp("weapon")) ){
                                        mout = "��" + dir + "���˹�ȥ��\n";
                                                                                min = "����"+thing->query("name")+"���˹�����\n";}
                                                                        else{
                                        mout = "��" + dir + "���˹�ȥ��\n";
                                                                                min = "���˹�����\n";}

                                }
                        }
                else {
                        mout = replace_string( me->query("comeout_message"), "$d", dir );
                        min = me->query("comein_message");
                }
        }
        
        // Added for play. by maco
        if( objectp(play_ob = env->query("playing")) && me->query("race") == "����" && play_ob != me){
                if( !present(play_ob, env))
                        env->delete("playing");
                if(play_ob->query_temp("exercise/playing") && me->query_temp("be_played/"+play_ob->query("id")) > 1 ) {
                        message_vision("$N�볯"+dir+"��ȥ������$n������ʵ������֮����$N���ڶ����Ȼ�᲻�þʹ��뿪��\n", me, play_ob);
                        me->start_busy(2);
                        me->delete_temp("be_played/"+play_ob->query("id"));
                        return 1;
                }
        }

        
        //If the exit is blocked.
        if( objectp(ob = env->query("exit_blockers/"+dir)) && me->query("race") == "����" && ob != me){
                if( !present(ob, env))
                        env->delete("exit_blockers/"+ob->query_temp("exit_blocked"));
                if( present(ob, env) && interactive(ob) && living(ob)){
                        if( !me->query("rided")){
                                // if( me->query_dex() < ob->query_dex()+5+random(5))   // Changed by FunBoo@sz
                                                                if (me->query_skill("dodge")+random(30) < ob->query_skill("dodge")+random(30))
                                                                {
                                message_vision("$N��ͼ��"+dir+"��ȥ�����Ǳ�$n��ס�˳�·��\n", me, ob);
                                return 1;
                                }

                                mout = "ʩչ�Ṧ����" + ob->name() +"����һ�ζ��������½�Ҳû���š�\n";    
                        }
                        else {
                                if( me->query("combat_exp") >= ob->query("combat_exp")){
                                        if( ob->query("rided")){
                                                message_vision(HIR"$N����"+rided_name+"�������һͷ��$n��������ײ������ˤ���Ľų��졣\n"NOR, me, ob);
                                                ob->query("rided")->delete("rider");
                                                ob->delete("rided");
                                                }
                                else
                                message_vision(HIR"$N����"+rided_name+"���������$nײ���Ľų��졣\n"NOR, me, ob);

                                ob->receive_wound("qi", random(1000), rided);
                                result = COMBAT_D->eff_status_msg((int)ob->query("qi") * 100 /(int)ob->query("max_qi"));
                                message_vision("($N"+result+")\n", ob);
                                ob->start_busy(2);
                                ob->delete_temp("exit_blocked");
                                env->delete("exit_blockers/"+dir);
                                } 
                                if( me->query("combat_exp") < ob->query("combat_exp")/2){
                                message_vision(HIG"$Nһ��ץס"+rided_name+"����������$n���˴�����һ��ͣ��������\n"NOR, ob, me);
                                me->start_busy(2);
                                ob->start_busy(1);
                                return 1;
                                }
                                else if( me->query("combat_exp") < ob->query("combat_exp"))
                                message_vision(RED"$N��$n����"+rided_name+"��������Ͻ�����һ����$nͨ����\n"NOR, ob, me);
                        }
                }
                if( !living(ob)) 
                        mout = "����" +ob->name()+ "��" +dir+ "���˳�ȥ��\n";
        } 
        if( me->query("race") == "����" && !me->query("env/invisibility") ) {
                if( objectp(rided) ) {
                        if( random(5) == 0 ) me->add("jingli", -2);
                        rided->add("jingli", - env->query("cost")*2);
                        if( rided->query("jingli") <= 0 ) rided->unconcious();
                } else if (userp(me)) {
                        me->add("jingli", - env->query("cost")*2);
                        if( me->query("jingli") <= 0 ) me->unconcious();
                }
                message( "vision", me->name() + mout, env, ({me}) );
        } else if( !objectp(me->query("rider")) && me->query("race") != "����" ){
                me->add("jingli", - env->query("cost")*2);
                if( me->query("jingli") <= 0 ) me->unconcious();
        }

        if( me->move(obj) ) {
                me->remove_all_enemy();
                if( !objectp(me->query("rider")) && !me->query("env/invisibility") )
                        message( "vision", me->name() + min, environment(me), ({me}) );
                me->set_temp("pending", 0);
                all_inventory(env)->follow_me(me, arg);

                if(( !objectp(rided = me->query("rided")) 
                || environment(rided) != environment(me))
                && me->query("race") == "����")
                        me->delete("rided");

                if(( !objectp(rider = me->query("rider")) 
                || environment(rider) != environment(me))
                && me->query("race") != "����")
                        me->delete("rider");

                if( me->query_temp("exit_blocked")){
                env->delete("exit_blockers/"+me->query_temp("exit_blocked"));
                me->delete_temp("exit_blocked");
                }

                return 1;
        }

        return 0;
}

void do_flee(object me)
{
        mapping exits;
        string *directions;

        if( !environment(me) || !living(me) ) return;
        exits = environment(me)->query("exits");
        if( !mapp(exits) || !sizeof(exits) ) return;
        directions = keys(exits);
        tell_object(me, "�������һ���������...\n");
        main(me, directions[random(sizeof(directions))]);
}

int help(object me)
{
        write(@HELP
ָ���ʽ : go <����>
 
������ָ���ķ����ƶ���
 
HELP
    );
    return 1;
}


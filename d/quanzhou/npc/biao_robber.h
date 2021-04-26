// Code of ShenZhou
//modified by ryu.

private void destruct_me(object me)
{
        if (me) destruct(me);
}

void init()
{
        object victim = this_player();
        object *inv, me = this_object();
        mapping skill_status;
        string *sname;
        int i, max = 0, j;

        if ( !me->query_temp("said") ) {
             switch( random(3) )
             {
                case 0:
                        command( "rob" );
                        command( "say ʶ������������������������С���ߣ�" );
                        break;
                case 1:
                        command( "grin" );
                        command( "say ��õģ�������ı������ɣ�" );
                        break;
                case 2:
                        command( "hehe" );
                        command( "say ��ү����Ҫ��ͣ����������ЩǮ�ƻ��ã����±������ɣ�" );
                        break;
             }
             me->set_temp("said", 1);
        }

        if ( !me->query_temp("copied") ) {
           if ( mapp(skill_status = victim->query_skills()) ) {
                skill_status = victim->query_skills();
                sname = keys(skill_status);

                for(i=0; i<sizeof(skill_status); i++) {
                        if ( skill_status[sname[i]] > max ) max = skill_status[sname[i]];
                }

                me->set_skill("dodge", max+random(max)/2);
                me->set_skill("parry", max+random(max)/2);
                me->set_skill("cuff", max+random(max)/2);
                me->set_skill("force", max+random(max)/2);
                me->set_skill("sword", max+random(max)/2);
                me->set_skill("blade", max+random(max)/2);
                me->set_skill("halberd", max+random(max)/2);
                me->set_skill("stick", max+random(max)/2);
                me->set_skill("axe", max+random(max)/2);
                me->set_skill("staff", max+random(max)/2);
                me->set_skill("wuxing-quan", max);
                me->set_skill("wuxingbu", max+random(max)/2);
                me->set_skill("club", max+random(max)/2);

                me->set("combat_exp", victim->query("combat_exp"));
                me->set("max_qi", victim->query("max_qi"));
                me->set("eff_qi", victim->query("max_qi"));
                me->set("max_jing", victim->query("max_jing"));
                me->set("eff_jing", victim->query("max_jing"));
                me->set("qi", me->query("max_qi"));
                me->set("jing", me->query("max_jing"));
                me->set("jiali", victim->query("jiali")+random(20));

                me->set("no_sing", 1);
                me->set_temp("copied", 1);

        inv = all_inventory(victim);

                for (j=0; j<sizeof(inv); j++) {
                if(inv[j]->is_unique() && random(5) == 1) 
                map_skill("cuff", "wuxing-quan");
                map_skill("dodge", "wuxingbu");
                map_skill("parry", "wuxing-quan");
                prepare_skill("cuff", "wuxing-quan");

                }
        }
        if ( !me->query_temp("victim") ) {
                remove_call_out("rob_kill");
                call_out("rob_kill", 40, me, victim);
                me->set_temp("victim", victim->query("id"));
        } else if( (string)victim->query("id") == (string)me->query_temp("victim") ) {
                remove_call_out("rob_kill");
                call_out("rob_kill", 2, me, victim);
                }
        }       
        if ( userp(this_player()) && !me->is_fighting() && me->query_temp("fought") ) 
                call_out("destruct_me", 1, me);

//      remove_call_out("checking");
//              call_out("checking", 45, me, victim);
}

int accept_object(object who, object ob)
{
        object me = this_object();

        if ( me->is_fighting() ) {
                command( "grin" );
                command( "say ���ڲŸ���̫���ˣ������ұ���ҲҪ����ҲҪ���������ɣ�" );
                return 0;
        }

        if ( ob->name()=="����") {
                remove_call_out("rob_kill");
                message_vision( "$n����һ������$N��ƨ���ϣ���м�غ���һ����\n", who, me);
                command( "say ����ʶʱ�����ӽ������һ������ɣ�" );
                message_vision( "$N˵����ﳤ��ȥ��\n", me );
                if (environment(me)->query("short") == "ɽ·") who->delete_temp("biao/ma");
                if (environment(me)->query("short") == "��ɽ����") who->delete_temp("biao/bayi");
                if (environment(me)->query("short") == "�׺�Ȫ") who->delete_temp("biao/jiang");
                if (environment(me)->query("short") == "����·") who->delete_temp("biao/li");
                who->delete_temp("apply/short");
                who->set_temp("biao/fail", 1);
                remove_call_out("destroy_me");
                call_out("destroy_me", 1, me);
                return 1;
        }
        if ( ob->query("value") >= 10000 || ob->value() >= 100000) {
                remove_call_out("rob_kill");
                who->delete_temp("rob_victim");
                message_vision( "$n����һ������$N��ƨ���ϣ���м�غ���һ����\n", who, me);
                command( "say ����ʶʱ�����ӽ������һ������ɣ�" );
                message_vision( "$N˵����ﳤ��ȥ��\n", me );
                remove_call_out("destroy_me");
                call_out("destroy_me", 1, me);
                return 1;
        }
        else {
                command( "say ��үҪ���Ǳ������������ӿ���ˣ�������ţ�" );
                return 0;
        }
}

void rob_kill(object me, object victim)
{
        if( !objectp(victim) ) 
                victim = present((string)me->query_temp("victim"), environment(me) );
        if( !objectp(me) || !objectp(victim) ) return;
        message_vision( "$n����$N����㾹�Ҳ��������������㣡\n", victim, me );
        me->set_temp("fought", 1);
        me->kill_ob(victim);
        remove_call_out("checking");
                call_out("checking", 25, me, victim);
}

void destroy_me(object me)
{
        if(me) destruct(me);
}

int checking(object me, object victim)
{
        if ( !me) return 1;
        if ( !me->is_fighting() ) {destruct(me); return 1;}

        if ( !objectp(victim) ) 
                victim = present((string)me->query_temp("victim"), environment(me));
        if ( victim && present(victim, environment(me)) ) call_out("checking", 1, me, victim) ;

        return 1;
}


int accept_fight(object victim)
{
        object me = this_object();

        command( "say ��������ı��ӵ��������ҷ������������������үȥ�ɣ�" );
        me->set_temp("fought", 1);
        me->kill_ob(victim);
        remove_call_out("checking");
        call_out("checking", 1, me, victim);
        return 1;
}

int accept_kill(object victim)
{
        object me = this_object();

        command( "say ��֪����Ķ������ô�ү�ҳ�����ɣ�" );
        me->kill_ob(victim);
        remove_call_out("checking");
        call_out("checking", 1, me, victim);
        return 1;
}
void unconcious(object victim)
{
        message_vision("\n$NͻȻ��һ����������սȦ�����ˣ�\n", this_object());
        destruct(this_object());
}

void die()
{
        message_vision("\n$N���ˣ�\n", this_object());
        destruct(this_object());
}

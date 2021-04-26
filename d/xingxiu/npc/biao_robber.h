// Code of ShenZhou
void init()
{
        object victim = this_player();
        object me = this_object();

        if ( !me->query_temp("said") ) {
             command( "rob" );
             switch( random(2) )
             {
                case 0:
                        command( "say ���º��ڣ����ӱ����㹷����" );
                        break;
                case 1:
                        command( "say ��õģ����º��ڹ��ɣ�" );
                        break;
                case 2:
                        command( "say ��ү����Ҫ��ͣ����������ЩǮ�ƻ��ã����º��ڹ��ɣ�" );
			break;
	     }
             me->set_temp("said", 1);
        }
	
	if ( !me->query_temp("victim") ) {
                remove_call_out("rob_kill");
                call_out("rob_kill", 20, me, victim);
                me->set_temp("victim", 1);
        }
}

int accept_object(object who, object ob)
{
        object me = this_object();

        if ( me->is_fighting() ) {
                command( "grin" );
                command( "say ���ڲŸ���̫���ˣ��������ɣ�" );
                return 0;
        }

	if ( ob->name()=="����" ) {
                remove_call_out("rob_kill");
		message_vision( "$n����һ������$N��ƨ���ϣ���м�غ���һ����\n", who, me);
		command( "say ����ʶʱ�����ӽ������һ������ɣ�" );
                message_vision( "$N˵����ﳤ��ȥ��\n", me );
		if (environment(me)->query("short") == "ɽ·") who->delete_temp("biao/ma");
		who->delete_temp("apply/short");
                who->set_temp("biao/fail", 1);
                remove_call_out("destroy_me");
                call_out("destroy_me", 1, me);
                return 1;
        }
        else {
                command( "say ��үҪ���Ǻ��ڣ��������ӿ���ˣ�������ţ�" );
                return 0;
        }
}

void rob_kill(object me, object victim)
{
        message_vision( "$n����$N����㾹�Ҳ��������������㣡\n", victim, me );
        me->kill_ob(victim);
        remove_call_out("checking");
        call_out("checking", 1, me, victim);
}

void destroy_me(object me)
{
        destruct(me);
}

int checking(object me, object victim)
{
        if ( me->query("qi") < 100 ) return 1;

        if ( !me->is_fighting() ) destruct(me);

        if ( present(victim, environment()) ) call_out("checking", 1, me, victim);

	return 1;
}

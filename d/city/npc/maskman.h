// Code of ShenZhou
void init()
{
	object *inv, victim, me = this_object();

	if ( !me->query_temp("target") || !objectp(victim = find_player(me->query_temp("target")) ) ) {
		call_out("destruct_me", 1, me);
		return;
	}

	if ( !me->query_temp("said") ) {
	     message_vision("һ����������$N���˹����������ɱ���������ƺ���������֮����\n", victim);

	     switch( random(3) )
	     {
		case 0:
			command( "hehe" );
			command( "say ��"+victim->query("family/family_name")+"�������£�������̶�������ʵ����Ľ�ý���");
			break;
		case 1:
			command( "grin" );
			command( "say ������̶����������룬�㲻ȥҲ��ȥ���������һ�˰ɣ�" );
			break;
		case 2:
			command( "grin" );
                        command( "say "+victim->name()+"����̶����������룬�����ҽ������ɲ��ɵ��㲻ȥ��" );
			break;
	     }
	     me->set_temp("said", 1);
	}

	if ( !me->query_temp("victim") ) {
		me->set_temp("victim", victim->query("id"));
		me->set("pursuer", 1);
        	me->set("vendetta/authority", 1);
        	me->set("bellicosity", 10000);
		me->set_temp("fought", 1);
		message_vision( "$n����$N��𣺸��һ�ȥ�μ�������\n", victim, me );
		me->fight_ob(victim);
		victim->kill_ob(me);

		remove_call_out("checking");
		call_out("checking", 1, me, victim);
	} 
	else if( present(me->query_temp("victim"),environment(me))
	&& !me->is_fighting() && me->query_temp("copied") ) {
		me->kill_ob(victim);
		message_vision( "$n����$N��𣺻����ܣ������ү��ȥ������������\n", victim, me );
		
		remove_call_out("checking");
		call_out("checking", 1, me, victim);
	}  
/*     
	if ( userp(victim) && !me->is_fighting() && me->query_temp("fought") ) {
		remove_call_out("destruct_me");
		call_out("destruct_me", 1, me);
	}
*/
	add_action("do_filter", "climb");
	add_action("do_filter", "enter");
	add_action("do_filter", "jump");
	add_action("do_filter", "swim");
	add_action("do_filter", "fly");
	add_action("do_filter_random", "go");
}

int do_filter(string arg)
{
	object player=this_player(), me=this_object();

	if ( objectp(me) && me->query_temp("victim") == player->query("id") ) {
		message_vision("$N�ӽ����ƣ���Ц�������ܣ��������ˣ�\n", me);
		return 1;
	}

	return 0;
}

int do_filter_random(string arg)
{
	object player=this_player(), me=this_object();

	if ( objectp(me) && me->query_temp("victim") == player->query("id")
	&& random(10) < 5 ) {
		message_vision("$N�ӽ����ƣ���Ц�������ܣ��������ˣ�\n", me);
                return 1;
        }

        return 0;
}

void destruct_me(object me)
{
	if(me) {
		if ( (me->query("eff_qi") * 100 / me->query("max_qi")) < 20
		|| (me->query("qi") * 100 / me->query("max_qi")) < 20
		|| (me->query("eff_jing") * 100 / me->query("max_jing")) < 20
		|| (me->query("jing") * 100 / me->query("max_jing")) < 20 ) {
			message_vision("$N�Ȼ˵�������㹻�ݣ������Ȳ������ˣ����������ƣ�\n", me);
		}
		else if ( me->query_temp("runaway") ) {
			message_vision("$NͻȻ��һ����������սȦ�����ˣ�\n", me);
		}
		else {
			command("get all");
			message_vision("$N��˵�������������ܵÿ죬�������ǵ�ù�����������������أ�\n", me);
		}
		message_vision("����$N���������䣬����ʧ�����ˡ�\n\n", me);
		destruct(me);
	}
}

void simple_destruct(object me)
{
	if(me) {
		message_vision("$N�ɿ�����������˼��ۣ�Ȼ�����ν��������뿪�ˡ�\n", me);
		destruct(me);
	}
}

int checking(object me, object victim)
{
	if ( !me ) return 1;

	if ( !victim=find_player(me->query_temp("victim")) ) {
		remove_call_out("destruct_me");
		call_out("destruct_me", 1, me);
		return 1;
	}
	
	if ( victim->is_ghost() ) {
		command("grin");
		command("say ��ʶ̧�٣���ү�����㲻������ȻҪ��������ȥ���ͣ���ֻ�ó�ȫ������");
		command("haha");

		remove_call_out("destruct_me");
		call_out("destruct_me", 1, me);
		return 1; 
	}

	if ( me->is_fighting() ) {
	   if ( victim->query_skill_mapped("force") == "taiji-shengong"
	 	|| victim->query_skill_mapped("force") == "xiantian-gong" ) {
			me->set("jiali", 0);
	   }
	   else if ( victim->query_skill_mapped("force") == "linji-zhuang"
		&& !me->query_temp("weapon") ) {
			me->set("jiali", 0);
           }
           else if ( victim->query_skill_mapped("force") == "hunyuan-yiqi"
		&& victim->query_temp("jinzhongzhao") ) {
			me->set("jiali", 0);
           }
	   else {
	   	me->set("jiali", victim->query("jiali"));
	   	if ( me->query("jiali") < 100 ) me->set("jiali", 100);
	   }

	   me->set("jiajin", victim->query("jiajin"));
	   if ( me->query("jiajin") < 20 ) me->set("jiajin", 20);
	
	   if ( (victim->query("eff_qi") * 100 / victim->query("max_qi")) < 5
                || (victim->query("qi") * 100 / victim->query("max_qi")) < 5
                || (victim->query("eff_jing") * 100 / victim->query("max_jing")) < 5
                || (victim->query("jing") * 100 / victim->query("max_jing")) < 5 ) {
		victim->unconcious();
		command("halt");
                me->remove_all_enemy();

		command("grin");
		command("say ����󹦸�ɣ��Խ������и������ˡ�������");
 		command("get all from "+victim->query("id"));
		message_vision("$n�ɻ��������ӣ���$N�廨����ڼ��ϣ��������������ʧ�����ˡ�\n", victim, me );

		victim->set_temp("rysj_prisoner", 1);
		victim->set("startroom", "/d/qilian/dilao");
		victim->move("/d/qilian/dilao");
		message("vision", "�������š�ѽ����һ�����ˣ�һ����������˱�һ�����������˽������ڵ��ϡ�\n", environment(victim), ({victim}) );
		me->move("/d/qilian/dilao");
		remove_call_out("checking");
		remove_call_out("simple_destruct");
		call_out("simple_destruct", 5, me);

		if ( victim->query("family") ) 
		   command("chat �ߣ�����"+victim->query("family/family_name")+"�ô����������Ҳ������ˣ�������������֮����");
		command("chat "+victim->name()+"�ڽ�����Ҳ�������һ�������Ҳ���ڱ�������֮�£��ٺ٣�");
		
                return 1;
	   }	
           else if ( (me->query("qi")*100 / me->query("max_qi")) <= 10 
	   || (me->query("jing")*100 / me->query("max_jing")) <= 10 ) {
		command("halt");
		me->remove_all_enemy();
		//random_move();
		
		remove_call_out("checking");
		remove_call_out("destruct_me");
                call_out("destruct_me", 1, me);
                //call_out("checking", 3, me, victim);
		return 1;
           }
	}

	if ( !me->is_fighting() ) {
		if ( present(victim, environment(me)) ) {
	        	victim->kill_ob(me);
			me->kill_ob(victim);
			if ( !environment(me)->query("no_fight") )
				message_vision( "$n����$N��𣺻����ܣ������ү��ȥ��������̽�����\n", victim, me );
		
			remove_call_out("checking");
			call_out("checking", 1, me, victim);
			return 1;
		}
		else if ( (me->query("qi")*100 / me->query("max_qi")) > 10 && objectp(victim) ) {
			me->move(environment(victim));
			message_vision("$nͻȻ�������������$N��𣺻����ܣ��ԹԵظ���ү��ȥ����������\n", victim, me );
			
			remove_call_out("checking");
                        call_out("checking", 1, me, victim);
                        return 1;
                }
		else {	
			command("get all");
			remove_call_out("destruct_me");
			call_out("destruct_me", 1, me);
			return 1;
		}
	}

	remove_call_out("checking");
	call_out("checking", 1, me, victim);
	return 1;
}

int accept_fight(object victim)
{
	object me = this_object();

	if ( me->query_temp("victim") && victim->query("combat_exp") > me->query("combat_exp") ) {
		 command( "say ��������үû�������Ϲ�֣�" );
		 return 0;
	}
	else {
		command( "say ��ʶ̧�ٵĶ���������ү�ҽ������£�" );
		me->set_temp("fought", 1);
		me->kill_ob(victim);
		remove_call_out("checking");
		call_out("checking", 1, me, victim);
		return 1;
	}
}

int accept_kill(object victim)
{
	object me = this_object();

	if ( me->query_temp("victim") && victim->query("combat_exp") > me->query("combat_exp") ) {
		 command( "say �ú�������ǰ������Ȼ���а��֣���ү�ұ�������졣" );
		 //message_vision("\n$NͻȻ��һ����������սȦ�����ˣ�\n", me);
		 remove_call_out("checking");
		 me->remove_all_enemy();
		 me->set_temp("runaway", 1);
		 call_out("destruct_me", 1, me);
		 return 0;
	}
	else {
		command( "say ��֪����Ķ������ô�ү�ҳ�����ɣ�" );
		remove_call_out("checking");
		call_out("checking", 1, me, victim);
		return 1;
	}
}

void unconcious()
{
	object winner;

	message_vision("\n$NͻȻ��һ����������սȦ�����ˣ�\n", this_object());

	if ( objectp( winner = find_player(this_object()->query_temp("victim")) ) ) {
		tell_object(winner,"���ٵеľ��������ˣ�\n");
		winner->add("combat_exp", 40+random(30));
	}

        destruct(this_object());
}

void die()
{
	object winner;

	message_vision("\n$N���ڵ��ϣ��ֽż��³鶯�����ˣ�\n", this_object());

	if ( objectp( winner = find_player(this_object()->query_temp("victim")) ) ) {
                tell_object(winner,"���ٵеľ��������ˣ�\n");
                winner->add("combat_exp", 70+random(30));
        }

        destruct(this_object());
}

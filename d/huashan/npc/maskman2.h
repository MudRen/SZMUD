// Code of ShenZhou
#include <ansi.h>

void init()
{
	object *inv, victim = this_player(), me = this_object();
	mapping skill_status;
	string *sname;
	int i, max = 0, max1, j;
        if ( !living(me) || me->is_unconcious() ) return;

	if ( living(me) &&( (me->query("eff_qi") * 100 / me->query("max_qi")) < 20
		|| (me->query("qi") * 100 / me->query("max_qi")) < 20
		|| (me->query("eff_jing") * 100 / me->query("max_jing")) < 20
		|| (me->query("jing") * 100 / me->query("max_jing")) < 20 )) {
		message_vision("$N�Ȼ˵�������㹻�ݣ����Ӳ������ˣ�\n", me);
		message_vision("����$N���������䣬һ���ӱ㲻������Ӱ��\n\n", me);
		destruct(me);
		return;
		}
	else if( living(me) && environment(me)->query("no_fight") ) {
		remove_call_out("checking");
		remove_call_out("checking2");
		remove_call_out("destruct_me");
		message_vision("$N��˵���������ܵÿ죬�����浹ù��\n", me);
		message_vision("����$N���������䣬һ���ӱ㲻������Ӱ��\n\n", me);
		destruct(me);
		return;
		}

	if ( me->query("kill_player") == victim->query("id") && present(victim, environment(me))) {
		me->kill_ob(victim);
		victim->kill_ob(me);
		message_vision( "$n����$N��𣺻����ܣ��������ɣ�\n", victim, me );
		me->set_leader(victim);
		remove_call_out("checking");
		call_out("checking", 1, me, victim);
		return;
	}
	if ( strsrch(file_name(environment(me)), "/d/huashan/hsforest") == -1 && me->query("kill_player") != victim->query("id") ) {
		remove_call_out("checking");
		remove_call_out("destruct_me");
		call_out("destruct_me", 1, me, victim);
		return;
	}

	if ( !objectp(victim) ) {
		destruct(me);
		return;
	}

	if ( !me->query_temp("said") ) {
	     switch( random(2) )
	     {
		case 0:
			command( "grin" );
			command( "say ��ײ�����ҵ��вأ�ֻ������ȥ���������ˣ�" );
			break;
		case 1:
			command( "hehe" );
			command( "say ��ү�������޷��������������Ը����������������㵹ù�ɣ�" );
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
		
		max1 = (int)max*3/4 + 1;
		max = (int)max*3/4 + 1 + random((int)max/2);
		
		me->set_skill("dodge", max1);
		me->set_skill("parry", max1 );
		me->set_skill("force", max1);
		switch( random(4) )
		{
			case 0:
				me->set_skill("cuff", max1);
				me->set_skill("yujiamu-quan", max1);
				me->map_skill("cuff", "yujiamu-quan");
				me->prepare_skill("cuff", "yujiamu-quan");
				me->set_skill("hand", max1);
				me->set_skill("dashou-yin", max1);
				me->map_skill("hand", "dashou-yin");
				me->prepare_skill("hand", "dashouyin");
				me->set_skill("longxiang-banruo", max1);
				me->map_skill("force", "longxiang-banruo");
				me->set_skill("shenkongxing", max1);
				me->map_skill("dodge", "shenkongxing");
				switch( random(2) ) {
				   case 0:
					me->set_skill("staff", max);
					me->set_skill("jingang-chu", max);
					me->map_skill("staff", "jingang-chu");
					me->map_skill("parry", "jingang-chu");
					me->carry_object("/clone/weapon/tiezhang")->wield();
					break;
				   case 1:
					me->set_skill("sword", max);
					me->set_skill("mingwang-jian", max);
					me->map_skill("sword", "mingwang-jian");
					me->map_skill("parry", "mingwang-jian");
					me->carry_object("/clone/weapon/changjian")->wield();
					break;
				}
				break;
			case 1:
				me->set_skill("strike", max1);
				me->set_skill("chousui-zhang", max1);
				me->map_skill("strike", "xingxiu-duzhang");
				me->prepare_skill("strike", "xingxiu-duzhang");
				me->set_skill("claw", max1);
				me->set_skill("sanyin-zhua", max1);
				me->map_skill("claw", "sanyin-zhua");
				me->prepare_skill("claw", "sanyin-zhua");
				me->set_skill("huagong-dafa", max1);
				me->map_skill("force", "huagong-dafa");
				me->set_skill("staff", max);
				me->set_skill("tianshan-zhang", max);
				me->map_skill("staff", "tianshan-zhang");
				me->set_skill("zhaixinggong", max1);
				me->map_skill("dodge", "zhaixinggong");
				me->map_skill("parry", "tianshan-zhang");
				me->carry_object("/clone/weapon/tiezhang")->wield();
				break;
			case 2:
				me->set_skill("strike", max1);
				me->set_skill("lingshe-shenfa", max1);
				me->map_skill("dodge", "lingshe-shenfa");
				me->set_skill("huagu-mianzhang", max1);
				me->map_skill("strike", "huagu-mianzhang");
				me->prepare_skill("strike", "huagu-mianzhang");
				me->set_skill("kick", max1);
				me->set_skill("jueming-tui", max1);
				me->map_skill("kick", "jueming-tui");
				me->prepare_skill("kick", "jueming-tui");
				me->set_skill("dulong-dafa", max1);
				me->map_skill("force", "dulong-dafa");
				me->set_skill("ruyi-gou", max);
				me->map_skill("hook", "ruyi-gou");
				me->set_skill("hook", max);
				me->carry_object("/clone/weapon/hook")->wield();
				break;
			case 3: 
				me->set_skill("strike", max1);
				me->set_skill("hamagong", max1);
				me->set_skill("hand", max1);
				me->set_skill("shexing-diaoshou", max1);
				me->map_skill("hand", "shexing-diaoshou");
				if ( max > 100 ) {
					me->map_skill("strike", "hamagong");
					me->prepare_skill("strike", "hamagong");
				}
				else {
					me->prepare_skill("hand", "shexing-diaoshou");
				}
				me->map_skill("force", "hamagong");
				me->set_skill("staff", max);
				me->set_skill("lingshe-zhang", max);
				me->map_skill("staff", "lingshe-zhang");
				me->map_skill("parry", "lingshe-zhang");
				me->set_skill("chanchubu", max1);
				me->map_skill("dodge", "chanchubu");
				me->carry_object("/clone/weapon/tiezhang")->wield();
				break;
		}

		me->set("combat_exp", victim->query("combat_exp")+random(victim->query("combat_exp")/10));
		me->set("max_qi", victim->query("max_qi"));
		me->set("eff_qi", victim->query("max_qi"));
		me->set("max_jing", victim->query("max_jing"));
		me->set("eff_jing", victim->query("max_jing"));
		me->set("qi", me->query("max_qi"));
		me->set("jing", me->query("max_jing"));
		me->set("jiali", victim->query("jiali")*3/4);
		if ( victim->query("max_neili") > 0 ) {
			me->set("max_neili", victim->query("max_neili"));
		}
		else me->set("max_neili", 500);
		if ( victim->query("max_jingli") > 0 ) {
			me->set("max_jingli", victim->query("max_jingli"));
		}
		else me->set("max_jingli", 500);
		me->set("neili", me->query("max_neili"));
		me->set("jingli", me->query("max_jingli"));
		
		me->set_leader(victim);
		me->set("no_sing", 1);
		me->set_temp("copied", 1);
	}

	if ( !me->query_temp("victim") ) {
		me->set_temp("victim", victim->query("id"));
		me->set("pursuer", 1);
        	me->set("vendetta/authority", 1);
        	me->set("bellicosity", 10000);
		me->set_temp("fought", 1);
		message_vision( "$n����$N����������ɣ�\n", victim, me );
		me->kill_ob(victim);
		victim->kill_ob(me);
		remove_call_out("checking");
		call_out("checking", 1, me, victim);
	} 
	else if( present(me->query_temp("victim"),environment(me))
	&& !me->is_fighting() && me->query_temp("copied") ) {
		me->kill_ob(victim);
		victim->kill_ob(me);
		message_vision( "$n����$N��𣺻����ܣ��������ɣ�\n", victim, me );
		me->set_leader(victim);
		remove_call_out("checking");
		call_out("checking", 1, me, victim);
		}
	else if( me->query("kill_player") == victim->query("id") ) {
		me->kill_ob(victim);
		victim->kill_ob(me);
		message_vision( "$n����$N��𣺻����ܣ��������ɣ�\n", victim, me );
		me->set_leader(victim);
		remove_call_out("checking");
		call_out("checking", 1, me, victim);
		}
	
	}  
/*     
	if ( userp(victim) && !me->is_fighting() && me->query_temp("fought") ) {
		remove_call_out("destruct_me");
		call_out("destruct_me", 1, me, victim);
	}
*/
}

void destruct_me(object me, object victim)
{
	object target;
	if ( me->query("kill_player") &&  !environment(me)->query("no_fight") )
		return 0;
	if(me) {
		if ( (me->query("eff_qi") * 100 / me->query("max_qi")) < 20
		|| (me->query("qi") * 100 / me->query("max_qi")) < 20
		|| (me->query("eff_jing") * 100 / me->query("max_jing")) < 20
		|| (me->query("jing") * 100 / me->query("max_jing")) < 20 ) {
			message_vision("$N�Ȼ˵�������㹻�ݣ����Ӳ������ˣ�\n", me);
		}
		else {
			message_vision("$N��˵���������ܵÿ죬�����浹ù��\n", me);
		}
		message_vision("����$N���������䣬û��ɭ���\n\n", me);
		destruct(me);
	}
	else return 0;
}

int checking(object me, object victim)
{
	object room;
	if ( !me ) return 1;

//      command("say checking");

//	if ( file_name(environment(me)) == "/d/huashan/hsstreet3"
//	|| file_name(environment(me)) == "/d/huashan/hsstreet2" ) {
	room = environment(victim);
	if ( !living(me)) {
		remove_call_out("checking");
		call_out("checking", 1, me, victim);
		return 1;
	}
	if ( me->query("kill_player") == victim->query("id")  && !me->is_fighting() && present(victim, environment(me))) {
		me->kill_ob(victim);
		victim->kill_ob(me);
		message_vision( "$n����$N��𣺻����ܣ��������ɣ�\n", victim, me );
		me->set_leader(victim);
		remove_call_out("checking");
		call_out("checking", 1, me, victim);
		return 1;
	}

	if ( strsrch(file_name(environment(me)), "/d/huashan/hsforest") == -1 && me->query("kill_player") != victim->query("id")) {
		remove_call_out("checking");
		remove_call_out("destruct_me");
		call_out("destruct_me", 1, me, victim);
		return;
	}

	if ( !victim=find_player(me->query_temp("victim")) ) {
		remove_call_out("destruct_me");
		call_out("destruct_me", 1, me, victim);
		return 1;
	}
	
	if ( victim->is_ghost() ) {
		command("say ����󹦸���ˣ���������");
		message_vision("����$N���������䣬û��ɭ���\n\n", me);
		destruct(me);
		return 1; 
	}

	if ( me->is_fighting() ) {
           if ( (me->query("qi")*100 / me->query("max_qi")) <= 10 
	   || (me->query("jing")*100 / me->query("max_jing")) <= 10 ) {
		command("halt");
		me->remove_all_enemy();
		random_move();		
		remove_call_out("checking");
                call_out("checking", 3, me, victim);
		return 1;
           }
	}
	if ( !me->is_fighting() && present(victim, environment(me)) ) {
		me->kill_ob(victim);
		victim->kill_ob(me);
		message_vision( "$n����$N��𣺻����ܣ��������ɣ�\n", victim, me );
		me->set_leader(victim);
		remove_call_out("checking");
		call_out("checking", 1, me, victim);
		return 1;
	}
	else if ( !me->is_fighting() ) {
		remove_call_out("destruct_me");
		call_out("destruct_me", 1, me, victim);
		return 1;
	}

	remove_call_out("checking");
	call_out("checking", 1, me, victim);
	return 1;
}

int checking2(object me, object victim)
{
	object room;

	room = environment(victim);
	
	if(wizardp(victim)) 
		command("tell maco ����"+room->query("short")+"������"+environment(me)->query("short")+"��");

	if (me->is_busy() || me->is_fighting() || !living(me)) {
		remove_call_out("checking2");
		call_out("checking2", 1, me, victim);
		return 1;
	}
	else if ( room != environment(me) && me->query("kill_player") == victim->query("id") 
	&& !victim->is_ghost() ) {
		if(wizardp(victim))
			command("tell maco ��ǰ��"+room->query("short")+"��");
		message_vision(me->name() + "����ææ���뿪�ˡ�\n", me );
		me->move(room);
		message_vision(me->name() + "�첽���˹�����\n", me);
		call_out("checking2", 1, me, victim);

		return 1;
	}
	call_out("checking2", 1, me, victim);

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
		command( "say ��������ı��ӵ��������ҷ�����" );
		if (victim->query("family/family_name") != "��ɽ��") {
			me->set("kill_player",victim->query("id"));
			call_out("checking2", 1, me, victim);
			}
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
		 message_vision("\n$NͻȻ��һ����������սȦ�����ˣ�\n", me);
		 remove_call_out("checking");
		 me->remove_all_enemy();
		 destruct(me);
	}
	else {
		command( "say ��֪����Ķ������ô�ү�ҳ�����ɣ�" );
		if (victim->query("family/family_name") != "��ɽ��") {
			me->set("kill_player",victim->query("id"));
			call_out("checking2", 1, me, victim);
			}
		me->set_leader(victim);
		remove_call_out("checking");
		call_out("checking", 1, me, victim);
	}

	return 1;
}

void unconcious()
{
//      message_vision("\n$NͻȻ��һ����������սȦ�����ˣ�\n", this_object());
//      destruct(this_object());

	object me = this_object();

	remove_call_out("checking");
	me->disable_player(" <���Բ���>");
	me->set("jing", 0);
	me->set("qi", 0);
	COMBAT_D->announce(me, "unconcious");

	call_out("revive", random(100 - query("con")) + 30);

}

void die()
{
	object corpse, ling;
	mixed killer;

	remove_call_out("checking");
	
	if( !living(this_object()) ) revive(1);
	COMBAT_D->announce(this_object(), "dead");

	if( objectp(killer = query_temp("last_damage_from"))){
		set_temp("my_killer", killer->query("id"));
		COMBAT_D->killer_reward(killer, this_object());
		
		if ( ling=present("ling pai", this_object()) ) {
		   if ( this_object()->query("combat_exp") > killer->query("combat_exp")*2/3
		   && this_object()->query_temp("victim") == killer->query("id") ) {
			ling->set_temp("owner", killer->query("id"));
		   }
		   else {
			destruct(ling);
		   }
		}
	}

	if( objectp(corpse = CHAR_D->make_corpse(this_object(), killer)) )
		corpse->move(environment());
		corpse->delete("combat_exp");

	this_object()->remove_all_killer();
	all_inventory(environment())->remove_killer(this_object());
	
	destruct(this_object());

//      message_vision("\n$N���ˣ�\n", this_object());
//      destruct(this_object());
}

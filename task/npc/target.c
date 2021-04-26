//test
// /task/npc/target.c
//Made by jason@pkuxkx
//2001.1.3
inherit NPC;

int other_qi,other_jing;
int leave();

void create()
{
	set_name("����",({"thief"}));
	set("chat_chance",25);
	set("chat_msg",({
		(: random_move :),
	}));
	
	setup();
}

void init()
{
	
	int level,i,exp;
	string *sname,*pname,*mname,*tmp;
	mapping skill_status,prepare_status,map_status;
	object ppl=this_player();
	exp = ppl->query("combat_exp");

	if(ppl->query_temp("task_target")==query("id")
	&&query("task_bekill")==ppl->query("id"))
	{
		command("say ����ԩ�Ҳ���ͷ���������ɣ���");
		if(random(3)>1) kill_ob(ppl);   	
               if (exp > 750000) carry_object(query("default_weapon"))->wield();
		add_action("do_change","wield");
		add_action("do_change","wear");
		add_action("do_change","unwield");
		add_action("do_change","remove");
		add_action("do_enable","enable");
	}

}

int do_change(string arg)
{
	object ppl=this_player();
	if(ppl->query_temp("task_target")==query("id")
	&&query("task_bekill")==ppl->query("id"))
	{
		write("����װ���������˰ɣ�\n");
		return 1;
	}
	return 0;
}

int do_enable(string arg)
{
	object ppl=this_player();
	if(ppl->query_temp("task_target")==query("id")
	&&query("task_bekill")==ppl->query("id"))
	{
		write("�����У��������˰ɣ�\n");
		return 1;
	}
	return 0;
}

varargs int receive_wound(string type, int damage, mixed who)
{
    string owner=query("task_bekill");
    
    if(who && who->query("id")!=owner && userp(who)) {
	if(damage>0) {
	    switch(type) {
		case "qi": other_qi+=damage; break;
		case "jing": other_jing+=damage; break;
	    }
	}
    }
    return ::receive_wound(type, damage, who);
}

varargs int receive_damage(string type, int damage, mixed who)
{
    string owner=query("task_bekill");
    
    if(who && who->query("id")!=owner && userp(who)) {
	if(damage>0) {
	    switch(type) {
		case "qi": other_qi+=damage; break;
		case "jing": other_jing+=damage; break;
	    }
	}
    }
    return ::receive_damage(type, damage, who);
}

// This is called in heart_beat() to perform attack action.
int attack()
{
	object opponent;

	clean_up_enemy();

	opponent = select_opponent();
	if( objectp(opponent) ) {
	        string owner=query("task_bekill");
		set_temp("last_opponent", opponent);
		COMBAT_D->fight(this_object(), opponent);
		return 1;
	} else
		return 0;
}

void unconcious()
{
die();
}


void die()
{
	string owner;
    	string skill;
        object owner_ob;
	object me=this_object();
        int ts;
	string str,msg;
	int max_qi, max_jing, ratio, exp_r, pot_r;
	max_qi=query("max_qi");
	max_jing=query("max_jing");
	
        owner = query("task_bekill");
	if( stringp(owner) && objectp(owner_ob = find_player(owner)) ) {
		if( owner_ob->query_temp("task_target")!=query("id") 
			|| query_temp("last_damage_from") != owner_ob )
			//modified by icer 
			//����ɱ�Ĳ���
		{
			//log_file("task","leave fuc \n");
			leave();
		
			return;
		}
        	
	    if(environment(owner_ob)==environment() && living(owner_ob) ) {
   		message("vision",me->name()+"̾�˿����������ԡ�\n",environment());
	    } else {
		message_vision("$N���ˡ�\n",this_object());
	    }
	    	    
		    ratio=100*(max_qi-other_qi)/max_qi;
		    if(ratio<0) ratio=0;
		    ratio=ratio*(max_jing-other_jing)/max_jing;
		    
		    if(ratio<0) ratio=0;
		     
		    //exp_r=query("kill_reward/exp")*ratio*2/200;
                    exp_r=950+random(100);
		    //pot_r=query("kill_reward/pot")*ratio*2/200;
                    pot_r=250+random(100);

                //����ݼ�              
                ts = me->query("task_times");
                ts = 1 - (ts-1)/10;
                exp_r=exp_r*ts;
                pot_r=pot_r*ts;                 //add by yujie

                    owner_ob->add("combat_exp",exp_r);
		    owner_ob->add("potential",pot_r);
		    if( owner_ob->query("potential") > owner_ob->query("max_potential") ) owner_ob->set("potential",owner_ob->query("max_potential") );
		    
		    if (owner_ob->query_temp("task_level")==9)
          		owner_ob->set_temp("task_level",5);
        	   else 
        	   	owner_ob->add_temp("task_level",1);
	       	log_file("quest_new",sprintf("%s(%s) get %d exp and %d pot from kill quest npc on %s. \n",
				owner_ob->name(), getuid(owner_ob), exp_r, pot_r, ctime(time())));     
		if( owner_ob->query("combat_exp") < 4000000 )         	   message("vision","�㱻������"+chinese_number(exp_r)+"�㾭���"+
        	   chinese_number(pot_r)+"��Ǳ��!\n",owner_ob);
        	 if( owner_ob->query("combat_exp") > 4000000 )         	   message("vision","�㱻������"+ chinese_number(pot_r)+"��Ǳ��!\n",owner_ob);
         	
   		    
     }
     
	destruct(this_object());
	return;
}

int goto_leave()
{
	remove_call_out("leave");
	call_out("leave",query("wait_time"));
	return 1;
}

int leave()
{
	command("haha");
	command("say ���������õģ���Ҳ����ɱ�ģ�˭�ܰ�����ô��������������\n");
	destruct(this_object());
	return 1;
}

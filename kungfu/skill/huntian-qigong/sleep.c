//Cracked by Kafei
// sleep.c
// littlefish
// last updated Marz (07/05/96)
// last updated Ryu (11/10/97)

void wakeup(object, object);
//void del_sleeped();

int main(object me, string arg)
{
	string event;
	mapping fam;
	object where = environment(me);


        seteuid(getuid());

	if ( (!(fam = me->query("family")) || fam["family_name"] != "ؤ��")
             && !(where->query("sleep_room"))
             || (where->query("no_sleep_room")) )
             return notify_fail("���ﲻ������˯�ĵط���\n");
   
	if (me->is_busy())
		return notify_fail("����æ���أ�\n");

	if( me->is_fighting() )
		return notify_fail("ս���в���˯����\n");
        
	if (where->query("hotel") && !(me->query_temp("rent_paid")))
	{
		message_vision("��С���������$N���: �����ﵱ��������! �ȵ�һ¥��Ǯ������˯!\n",me);
		return 1;
	}
 
/*
	if (me->query_temp("sleeped"))
		return notify_fail("�������������˯��һ��, ��˯�������к�����! \n");
*/

	if (where->query("night_room")){
	event = NATURE_D->outdoor_room_event();
	if (event != "event_night" && event != "event_midnight" && event != "event_dawn")
                return notify_fail("��û�ڣ�˯ʲô����\n");
	}

	if (where->query("sleep_room"))
	{
		write("��������һ�ɣ���ʼ˯����\n");
		write("��һ�������ͽ��������硣\n");
		me->set_temp("block_msg/all",1);
		message_vision("$Nһ�������ڴ��ϣ���һ����������������������硣\n",me);
	}
	else { 
		write("�������½���һ�ɣ���ʼ˯����\n");
		write("��һ�������ͽ��������硣\n");
		me->set_temp("block_msg/all",1);
		message_vision("$N�����½�������һ�ɣ���һ�����������������������\n",me);
	}

	/*where->set("no_fight", 1);*/
	where->add_temp("sleeping_person", 1);

	//me->set("no_get", 1);	
	//me->set("no_get_from", 1);	
	
	if (!(where->query("hotel"))) 
		me->set_temp("sleeped",1);
	else
		me->delete_temp("rent_paid");

	me->disable_player("<˯����>");

	call_out("wakeup",random(60 - me->query("con")), me, where);
        
	return 1;
	
}

void wakeup(object me,object where)
{
	int sp, new_hp;

	sp = 10 - (int)me->query_condition("sleep");

//	me->add("qi", (((me->query("eff_qi")) - me->query("qi"))*sp)/10 + 3);
	new_hp = (int)me->query("qi");
	new_hp += ((int)me->query("eff_qi") - new_hp)*sp/10;
	if (new_hp < 0) new_hp = 0; 
	if (new_hp > (int)me->query("eff_qi") ) new_hp = me->query("eff_qi");
	me->set("qi", new_hp);
	
//	me->add("jing", (((me->query("eff_jing")) - me->query("jing"))*sp)/10 + 3);
	new_hp = (int)me->query("jing");
	new_hp += ((int)me->query("eff_jing") - new_hp)*sp/10;
	if (new_hp < 0) new_hp = 0; 
	if (new_hp > (int)me->query("eff_jing") ) new_hp = me->query("eff_jing");
	me->set("jing", new_hp);

//	me->add("jingli", ((me->query("max_jingli") - me->query("jingli"))*sp)/20 + 5);
	new_hp = (int)me->query("jingli");
	new_hp += ((int)me->query("max_jingli") - new_hp)*sp/5;
	if (new_hp < 0) new_hp = 0; 
	if (new_hp > (int)me->query("max_jingli") ) new_hp = me->query("max_jingli");
	me->set("jingli", new_hp);

//	me->add("neili", ((me->query("max_neili") - me->query("neili"))*sp)/20 + 5);
	new_hp = (int)me->query("neili");
	new_hp += ((int)me->query("max_neili") - new_hp)*sp/20;
	if (new_hp < 0) new_hp = 0; 
	if (new_hp > (int)me->query("max_neili") ) new_hp = me->query("max_neili");
	me->set("neili", new_hp);
	
	if (living(me)) return;

	me->enable_player();
        while( environment(me)->is_character() )
        	me->move(environment(environment(me)));
	me->apply_condition("sleep", 8 + random(5));
  
	/*call_out("del_sleeped", 179, me);*/

	message_vision("$Nһ����������������ػ��һ�½�ǡ�\n",me);
	me->set_temp("block_msg/all", 0);
	write("��һ��������ֻ���������档�ûһ���ˡ�\n");

	//if (!where->query("sleep_room") && !where->query("hotel"))
		//where->delete("no_fight");
     
	where->add_temp("sleeping_person", -1);
	//me->delete("no_get");	
	//me->delete("no_get_from");	
 
}

/*
void del_sleeped(object me)
{
	if (objectp(me) &&  me->query_temp("sleeped"))
		me->delete_temp("sleeped");
}
*/

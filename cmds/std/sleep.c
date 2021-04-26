//Cracked by Kafei
// sleep.c
// Code By Yujie(2001/11)

#include <ansi.h>

void wakeup(object, object);
void check_input(string ,object,object);
//void del_sleeped();

int main(object me, string arg)
{
	string event;
	mapping fam;
	object room,*inv;
	int i;
	object where = environment(me);
	object obj ,lead;

    	seteuid(getuid());

	if (where->query("no_sleep_room"))
        return notify_fail("���ﲻ������˯�ĵط���\n");

	fam = me->query("family");
	if (!where->query("sleep_room")){
                if ( !fam || (fam && fam["family_name"] != "ؤ��" && fam["family_name"] != "��Ĺ��"))
        return notify_fail("���ﲻ������˯�ĵط���\n");
	}

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

	if (fam && fam["family_name"] == "��Ĺ��" && !where->query("sleep_room")){
		if (where->query("outdoors")) 
			return notify_fail("�����ٸ�������˯���ɣ�\n");
		if (!present("rope", me))
            return notify_fail("���ﲻ������˯�ĵط���\n");
		if (me->query_skill("feiyan-gong",1)<60)
            return notify_fail("���ﲻ������˯�ĵط���\n");
	}
	
	lead = me->query_leader();
        me->set_leader(0);

	if (where->query("sleep_room"))
	{
		write("��������һ�ɣ���ʼ˯����\n");
		write("��һ�������ͽ��������硣\n");
		write(HIR"��һ��������ֹ˯��״̬��\n"NOR);
		me->set_temp("sleep_now",1);
		me->set_temp("sleep_type",1);
		input_to("check_input",0,me,lead);
		tell_room(environment(me), me->name()+"һ�������ڴ��ϣ���һ����������������������硣\n" ,me);
	}
	else if (fam && fam["family_name"] == "��Ĺ��"){
		write("��ȡ������˩�����ӵ�һ�ǡ�Ȼ������Ծ�����ӣ���ʼ˯����\n");
		write("��һ���������ڻ����Ƶ������Ͻ��������硣\n");
		write(HIR"��һ��������ֹ˯��״̬��\n"NOR);
		me->set_temp("sleep_now",1);
		me->set_temp("sleep_type",1);
		input_to("check_input",0,me,lead);
		tell_room(environment(me), me->name()+"����Ծ�����ӣ���Ȼ��������������˯������һ�������������\n" ,me);
	}
	else { 
		write("�������½���һ�ɣ���ʼ˯����\n");
		write("��һ�������ͽ��������硣\n");
		write(HIR"��һ��������ֹ˯��״̬��\n"NOR);
		me->set_temp("sleep_now",1);
		me->set_temp("sleep_type",1);
		input_to("check_input",0,me,lead);
		tell_room(environment(me), me->name()+"�����½�������һ�ɣ���һ�����������������������\n" ,me);
	}

	/*where->set("no_fight", 1);*/
	where->add_temp("sleeping_person", 1);

	//me->set("no_get", 1);	
	if (where->query("sleep_room")) me->set("no_get_from", 1);	
	
	if (!(where->query("hotel"))) 
		me->set_temp("sleeped",1);
	else
		me->delete_temp("rent_paid");
		
       me->set("disable_type","˯����");
	call_out("wakeup",random(60 - me->query("con")), me, where);
        
	return 1;
	
}

void check_input(string arg,object me,object lead)
{	int tim;
	if (me->query_temp("sleep_now"))
	{	tell_object(me,"�Ÿո�˯�ţ��ٶ�˯һ����ɡ�\n");
		input_to("check_input",0,me,lead);
		return;
	}
         me->delete("disable_type");

        while( environment(me)->is_character() )
                me->move(environment(environment(me)));
	tim = time() - (int)me->query("sleeptime");
	if ( me->query("neili") < (me->query("max_neili")*8/10) )
	{	tim = tim * 6;
		me->add("neili",tim);
		if (me->query("neili") > (me->query("max_neili")*8/10) ) 
			me->set("neili",me->query("max_neili")*8/10);
	}
	tell_room(environment(me), me->name()+"һ����������������ػ��һ�½�ǡ�\n" ,me);
	tell_object(me,"����һ�½�ǣ�ֻ���������档\n");
	me->delete_temp("sleep_type");
	me->set_leader(lead);
	me->delete("no_get_from");
	
	return;
}	

void wakeup(object me,object where)
{
	object room,obj,*inv;
        int i;
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
	
        while( environment(me)->is_character() )
        	me->move(environment(environment(me)));

	me->apply_condition("sleep", 8 + random(5));
	me->delete_temp("sleep_now");
	me->set("sleeptime",time() );
	  	
	//if (!where->query("sleep_room") && !where->query("hotel"))
		//where->delete("no_fight");
     
	where->add_temp("sleeping_person", -1);
	//me->delete("no_get");	
	where->add_temp("sleeping_person", -1);
	
 
}

//CODE BY SCATTER
//LINGPAI FOR YANGZHOU JOB

#include <ansi.h>
inherit ITEM;

void do_s1();

void create() 
{
	    set_name(HIW"�佫��"NOR,({"wujiang lin", "wujiang", "lin"}));
        set_weight(1);
                set("long", "�����佫���ϱ����������֤����֡�\n");
                set("unit", "��");
                set("value", 8);
                set("no_get", 1);
                set("no_drop", 1);
        setup();
}

void init()
{
	add_action("do_baodao", "baodao");
}

int do_baodao(string arg)
{
	object me=this_player();
	if(arg != "here")
	{
		write("ʲô?\n");
		return 1;
	}

	else
	{
		if( !environment(me)->query("yzjob") )
		{
			write("ʲô?\n");
			return 1;
		}
		else
		{
			//write(BHIW"��׼��(��ʱ 10 ���ʼ)\n");
			write(BCYN+HIW"��׼��(��ʱ 10 ���ʼ)\n"NOR);
			me->add_temp("yzjob/count", 10);
			remove_call_out("do_countdown");
			call_out("do_countdown", 1, me);
		}
	}
	return 1;
}


void do_countdown(object me)
{
	if( me->query_temp("yzjob/count") < 1 )
	{
		do_s1();
		return;
	}
	else
	{
		me->add_temp("yzjob/count", -1);
		write("��ʣ " + me->query_temp("yzjob/count") + " ����Ҫ��ʼ��\n");
		remove_call_out("do_count");
		call_out("do_countdown", 1, me);
		return;
	}
	return;
}


void do_s1()
{
	object me=this_player(), here=environment(me), ob;
	mapping skill_status; 
	int obexp, oblvl, i, count, point;
	string *sname;
	
	ob=new(__DIR__"shashou");
	ob->set_temp("yzjob/killtarget", me->query("id"));


	//***************
	//FULL SKILL CODE
	//***************
	obexp = me->query("combat_exp") / 1000;
	if( obexp > 50000 ) obexp = 50000;
	obexp *= 1000;
	oblvl = to_int(pow(obexp*10,0.33333)+1);
	
	if ( mapp(skill_status = ob->query_skills()) ) 
	{
		skill_status = ob->query_skills();
        sname = keys(skill_status);
        count = sizeof(skill_status);
		
		for(i=0; i<sizeof(skill_status); i++) 
		{
			ob->set_skill(sname[i],oblvl);
        }

    }
    ob->set("combat_exp",obexp);
	//*********************
	//FULL SKILL CODE (END)
	//*********************
	ob->move("/d/city/ximen");
	
	remove_call_out("do_s2");
	call_out("do_s2", 50);

	return;
}


void do_s2()
{
	object me=this_player(), here=environment(me), ob;
	mapping skill_status;
	int obexp, oblvl, i, count, point;
	string *sname;
	
	
	
	//NEED MORE MENPAI HERE
	ob=new(__DIR__"shashou");
	//NEED MORE MENPAI HERE



	ob->set_temp("yzjob/killtarget", me->query("id"));


	//***************
	//FULL SKILL CODE
	//***************
	obexp = me->query("combat_exp") / 1000;
	if( obexp > 50000 ) obexp = 50000;
	obexp *= 1000;
	oblvl = to_int(pow(obexp*10,0.33333)+1);
	
	if ( mapp(skill_status = ob->query_skills()) ) 
	{
		skill_status = ob->query_skills();
        sname = keys(skill_status);
        count = sizeof(skill_status);
		
		for(i=0; i<sizeof(skill_status); i++) 
		{
			ob->set_skill(sname[i],oblvl);
        }

    }
    ob->set("combat_exp",obexp);
	//*********************
	//FULL SKILL CODE (END)
	//*********************


	ob->move("/d/city/dongmen");
	message_vision(NOR"һ���佫�첽���˹���"+HIW+"�佫���������˵�����죡��"+HIG+"����"+HIW+"���ز�ס�ˣ���\n"+NOR+"�佫�첽���뿪\n", me);
	remove_call_out("do_s3");
	call_out("do_s3", 45);

	return;
}


void do_s3()
{
	object me=this_player(), here=environment(me), ob;
	mapping skill_status;
	int obexp, oblvl, i, count, point;
	string *sname;
	
	
	//NEED MORE MENPAI HERE
	ob=new(__DIR__"shashou");
	//NEED MORE MENPAI HERE



	ob->set_temp("yzjob/killtarget", me->query("id"));


	//***************
	//FULL SKILL CODE
	//***************
	obexp = me->query("combat_exp") / 1000;
	if( obexp > 50000 ) obexp = 50000;
	obexp *= 1000;
	oblvl = to_int(pow(obexp*10,0.33333)+1);
	
	if ( mapp(skill_status = ob->query_skills()) ) 
	{
		skill_status = ob->query_skills();
        sname = keys(skill_status);
        count = sizeof(skill_status);
		
		for(i=0; i<sizeof(skill_status); i++) 
		{
			ob->set_skill(sname[i],oblvl);
        }

    }
    ob->set("combat_exp",obexp);
	//*********************
	//FULL SKILL CODE (END)
	//*********************


	ob->move("/d/city/beimen");
	message_vision(NOR"һ���佫�첽���˹���"+HIW+"�佫���������˵�����죡��"+HIG+"����"+HIW+"����Ҫ��æ����\n"+NOR+"�佫�첽���뿪\n", me);
	
	remove_call_out("do_s4");
	call_out("do_s4", 40);

	return;
}




void do_s4()
{
	object me=this_player(), here=environment(me), ob;
	mapping skill_status;
	int obexp, oblvl, i, count, point;
	string *sname;
	
	
	//NEED MORE MENPAI HERE
	ob=new(__DIR__"shashou");
	//NEED MORE MENPAI HERE



	ob->set_temp("yzjob/killtarget", me->query("id"));


	//***************
	//FULL SKILL CODE
	//***************
	obexp = me->query("combat_exp") / 1000;
	if( obexp > 50000 ) obexp = 50000;
	obexp *= 1000;
	oblvl = to_int(pow(obexp*10,0.33333)+1);
	
	if ( mapp(skill_status = ob->query_skills()) ) 
	{
		skill_status = ob->query_skills();
        sname = keys(skill_status);
        count = sizeof(skill_status);
		
		for(i=0; i<sizeof(skill_status); i++) 
		{
			ob->set_skill(sname[i],oblvl);
        }

    }
    ob->set("combat_exp",obexp);
	//*********************
	//FULL SKILL CODE (END)
	//*********************


	ob->move("/d/city/nanmen");
	message_vision(NOR"һ���佫�첽���˹���"+HIW+"�佫���������˵�����죡��"+HIG+"����"+HIW+"��Ҫ���������ˣ���\n"+NOR+"�佫�첽���뿪\n", me);
	
	remove_call_out("do_s5");
	call_out("do_s5", 35);

	return;
}




void do_s5()
{
	object me=this_player(), here=environment(me), ob;
	mapping skill_status;
	int obexp, oblvl, i, count, point;
	string *sname;
	
	
	//NEED MORE MENPAI HERE
	ob=new(__DIR__"shashou");
	//NEED MORE MENPAI HERE



	ob->set_temp("yzjob/killtarget", me->query("id"));


	//***************
	//FULL SKILL CODE
	//***************
	obexp = me->query("combat_exp") / 1000;
	if( obexp > 50000 ) obexp = 50000;
	obexp *= 1000;
	oblvl = to_int(pow(obexp*10,0.33333)+1);
	
	if ( mapp(skill_status = ob->query_skills()) ) 
	{
		skill_status = ob->query_skills();
        sname = keys(skill_status);
        count = sizeof(skill_status);
		
		for(i=0; i<sizeof(skill_status); i++) 
		{
			ob->set_skill(sname[i],oblvl);
        }

    }
    ob->set("combat_exp",obexp);
	//*********************
	//FULL SKILL CODE (END)
	//*********************


	ob->move("/d/city/dongmen");
	message_vision(NOR"һ���佫�첽���˹���"+HIW+"�佫���������˵�����죡��"+HIG+"����"+HIW+"��Ҫ���������ˣ���\n"+NOR+"�佫�첽���뿪\n", me);
	
	remove_call_out("do_s6");
	call_out("do_s6", 30);

	return;
}


void do_s6()
{
	object me=this_player(), here=environment(me), ob;
	mapping skill_status;
	int obexp, oblvl, i, count, point;
	string *sname;
	
	
	//NEED MORE MENPAI HERE
	ob=new(__DIR__"shashou");
	//NEED MORE MENPAI HERE



	ob->set_temp("yzjob/killtarget", me->query("id"));


	//***************
	//FULL SKILL CODE
	//***************
	obexp = me->query("combat_exp") / 1000;
	if( obexp > 50000 ) obexp = 50000;
	obexp *= 1000;
	oblvl = to_int(pow(obexp*10,0.33333)+1);
	
	if ( mapp(skill_status = ob->query_skills()) ) 
	{
		skill_status = ob->query_skills();
        sname = keys(skill_status);
        count = sizeof(skill_status);
		
		for(i=0; i<sizeof(skill_status); i++) 
		{
			ob->set_skill(sname[i],oblvl);
        }

    }
    ob->set("combat_exp",obexp);
	//*********************
	//FULL SKILL CODE (END)
	//*********************


	ob->move("/d/city/ximen");
	message_vision(NOR"һ���佫�첽���˹���"+HIW+"�佫���������˵�����죡��"+HIG+"����"+HIW+"��Ҫ���������ˣ���\n"+NOR+"�佫�첽���뿪\n", me);
	
	remove_call_out("do_s7");
	call_out("do_s7", 20);

	return;
}


void do_s7()
{
	object me=this_player(), here=environment(me), ob;
	mapping skill_status;
	int obexp, oblvl, i, count, point;
	string *sname;
	
	
	//NEED MORE MENPAI HERE
	ob=new(__DIR__"shashou");
	//NEED MORE MENPAI HERE



	ob->set_temp("yzjob/killtarget", me->query("id"));


	//***************
	//FULL SKILL CODE
	//***************
	obexp = me->query("combat_exp") / 1000;
	if( obexp > 50000 ) obexp = 50000;
	obexp *= 1000;
	oblvl = to_int(pow(obexp*10,0.33333)+1);
	
	if ( mapp(skill_status = ob->query_skills()) ) 
	{
		skill_status = ob->query_skills();
        sname = keys(skill_status);
        count = sizeof(skill_status);
		
		for(i=0; i<sizeof(skill_status); i++) 
		{
			ob->set_skill(sname[i],oblvl);
        }

    }
    ob->set("combat_exp",obexp);
	//*********************
	//FULL SKILL CODE (END)
	//*********************


	ob->move("/d/city/beimen");
	message_vision(NOR"һ���佫�첽���˹���"+HIW+"�佫���������˵�����죡��"+HIG+"����"+HIW+"��Ҫ���������ˣ���\n"+NOR+"�佫�첽���뿪\n", me);
	
	remove_call_out("do_s8");
	call_out("do_finish", 100);

	return;
}

void do_finish()
{
	write("finish\n");
	return;
}
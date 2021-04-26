void set_owner(object owner);
// Code of ShenZhou
// /newjob/tiejiang/obj/luoche2.c �⳵

#include <move.h>
#include <ansi.h>
#include <room.h>
inherit ITEM;

string *address=({"����"});

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
]);



int do_drive(string arg);
int do_open();
int do_check();
int do_unride(string arg);
int do_ride(string arg);
int do_yao();
//int do_attack(string arg);
//int do_rob();
void host_appear();
void destroy_cart(object cart);
void greeting(object ob);
void destroy_it(object ob);
//void do_leave(object ob);
//void robber_rob(object me);
void do_buxuzu(object ppl);
int do_get(string arg);

void create()
{
	seteuid(getuid());
	set_name(HIW"�⳵"NOR, ({"luo che", "che"}));
	set_weight(50000);
	set_max_encumbrance(700000000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long",
			"����һ���ǳ���ʵ���⳵������ƥ���������ţ��⳵������һ����죬���顰���ݳ��С��ĸ����֡�\n");
		set("unit", "��");
		set("value", 1000000);
	     }
	     
	set("material", "steel");

	set("no_get",1);

	set("no_refresh", 1);
//	remove_call_out("auto_check");
//	call_out("auto_check", 30+random(30) );
    	
}
	int is_container() { return 1; }

void init()
{
	object ob;
	add_action("do_yao", "yao");
	add_action("do_drive", "gan");
	add_action("do_drive", "g");
	add_action("do_ride", "ride");
	add_action("do_ride", "shang");
	add_action("do_unride", "leave");
	add_action("do_get","get");
	
	if( interactive(ob = this_player()) ) {
		 call_out("greeting", 1, ob);
	}
}

int do_get()
{
  if( query("owner") != this_player()->query("id")) return;
  write("OK\n");
  return 0;
}


int do_yao()
{
	if( query("owner") != this_player()->query("id"))return notify_fail("������ĳ���\n"); //�ж��Ƿ����Լ��ĳ��� ���Խ׶���ȥ�� Troy 2001.12.7
	if (query("yao"))
	{
	switch (MONEY_D->player_pay(this_player(), 200)) 
	{
	case 0:
			write("��⵰��һ�ߴ���ȥ��\n");
		break;
	case 2:
		write("������Ǯ�����ˣ���Ʊ��û���ҵÿ���\n");
		break;
	default:
	message_vision("$N�ͳ��������Ӹ����򡣳�������������˵࣬���˵�����������\n", this_player());
	message_vision( HIW"����˵�����ã����Ǽ�����·�ɡ�\n"NOR,this_player());
	set ("xuzu",1);
	break;
	}
	delete ("yao");
	call_out("buxuzu",0);
	return 1;
}
return 0;
	}



void set_owner(object owner)
{
	object ob = this_object();
	set("owner",owner->query("id"));
	call_out("destroy_it",10,ob);
	delete("xuzu");
// mud time һ��1440
}



int do_ride(string arg)
{
	object me = this_player();
	object cart = this_object();
	if (!arg) return notify_fail("��Ҫ��ʲô��\n");
	if( me->query_temp("rided_luo") )  return notify_fail("���Ѿ����⳵�ϣ�\n");
	if( cart = present("luo che",environment()) );
	if( query("owner") != me->query("id"))return notify_fail("������ĳ���\n"); //�ж��Ƿ����Լ��ĳ���
	message_vision(HIY"$N"+HIY"�س������⳵���Գ���˵������������·�ѣ���\n"NOR,me);
	me->set_leader(cart ); //������ҡ�
	me->set_temp("rided_luo",1);  //�ڳ��ϡ�
	return 1;
}

int do_unride(string arg)
{
	object me = this_player();
	if( !me->query_temp("rided_luo") )  return notify_fail("���Ѿ������⳵�ϣ�\n");
	message_vision(HIY"$N"+HIY"�������⳵���Գ���˵���������Ե�һ�ᣡ��\n"NOR,me);
	me->delete_temp("rided_luo");
	return 1;
}

void destroy_it( object obj)  
//set_owner ʱ�����⳵ʱ�䣬��ʱ���ٸ���or�����ˡ������;�в����ˡ����ڶ����ͻ�һ��ʧ��
{
	object ppl;
	remove_call_out("distroy_it");
	if(!objectp(obj))return;
	if( !obj->query("owner")) return;
	if( obj->query("owner") ) 
	{
		ppl = find_player( obj->query("owner") );
		}

	if( userp(ppl)) //&& ppl->query_temp("rided_luo") )
		{
			message_vision( HIR"����ͣ���˳�����$n"+"˵�������⳵��ʱ�䵽�ˣ��Ƿ�Ҫ���⣨yao)��\n"NOR,obj,ppl);
		        set("yao",1);
		        //remove_call_out("do_buxuzu");
  		        call_out("do_buxuzu", 15,ppl );  
		}
	
}

void do_buxuzu (object ppl)
	{
		
		object ob = this_object();   
		if (query("xuzu"))
		{
			ob->set_owner(ppl);
			remove_call_out("do_buxuzu");
			delete("xuzu");
		}
		else
		{
		message_vision( HIW"�������$N"+HIW+"���ˣ�ת�۾���ûӰ�ˣ�\n"NOR,ob );
		ppl->delete_temp("rided_luo"); 
		destruct(ob);
		delete("yao");
		}
	}       
                
int do_drive(string arg)
{
        object env, obj, ob, me = this_player(), partner;
        string target_dir, dir, dest, victim;
        mapping exit;
        object here = environment(me),robber = present("robber",here);
        int busy_time;

        if (!arg) return notify_fail("��Ҫ����ʲô��\n");

        if( sscanf(arg, "%s %s", victim, dir) != 2 ) return notify_fail("ָ�����\n");

        if ( victim == me->query("id") ) return notify_fail("�αض��һ�٣�\n");

        if( !me->query_temp("rided_luo") )  return notify_fail("����˵�������������⳵�ϣ�����ô�ܸϳ���\n");

        if ( victim != "che" && victim != "da che" ) return notify_fail("��Ҫ����ʲô��\n");

        ob = present(victim, environment(me));

        if (!ob) return notify_fail("���ﲢ�޴��ˣ�\n");

        if ( me->is_busy() ) return notify_fail("����æ���أ�\n");

        env = environment(me);
        
        
        if( !mapp(exit = env->query("exits")) || undefinedp(exit[dir]) )
                return notify_fail("�޴˷����ȥ��\n");
	        dest = exit[dir];

        if( !(obj = find_object(dest)) )
                                         call_other(dest, "???");
                  if( !(obj = find_object(dest)) )
                                         return notify_fail("�޷��ߣ�\n");
        
        if( !wizardp(ob) && obj->query("short") == "�ƽ���" )
                return notify_fail("�޷��ߣ�\n");

        if( !undefinedp(default_dirs[dir]) )
                                         target_dir = default_dirs[dir];
                  else
                                         target_dir = dir;

        message_vision( HIG"����"+HIG"��������ӣ������������Ӽ���$n"+HIG"��"+target_dir+"ʻȥ��\n" , me, ob);
/*
���������б�����շ�
*/
	if( here->query("short") == "����" )
	{
		switch(random(2))
		{
		case 1:
			if (query_temp("rided_luo"))
			{
				message_vision( HIG"һ������������������ס��$n��˵�������콻����˰����\n" , me, ob);
				return 1;
			}
			else
				message_vision( HIG"һ��������������˵�������׳������ˣ���\n" , me, ob);
				break;
		default:
			break;
		}
	}                                            
/*
���������б�����շ�
Troy 2001.12.21
*/
	switch(random(100))
	{
	case 0:
		me->delete_temp("rided_luo"); 
		message_vision(HIG"����һƥ������$N����������������˾��ţ�������������\n"NOR,me);
		//if (me->qurey()  �Ƿ�Ҫ�����Ṧ��
		message_vision(HIW"$Nʩչ�Ṧ����һԾ��ס������Ӳ�����Ľ�����ק�˻����ͳ���һ���⳵�׺á�\n"NOR,me);
		busy_time=10;
		me->start_busy(busy_time);
		break;
	case 1:
		message_vision(HIG"����Ķ��������˳�����\n"NOR,me);
		break;
	default:  
		message("vision", HIY "ֻ��"+ob->name()+HIY"��¡¡���ص���"+target_dir+"ʻ��ȥ��\n" NOR, environment(ob), ({ob}));
		if( ob->move(obj) )
		{
			message( "vision", HIY "ֻ��һ��"+ob->name()+HIY"��¡¡���ص�ʻ�˹�����\n" NOR, environment(ob), ({ob}));
			//busy_time = 2 + random(2);
			busy_time=0;
			message_vision( HIG"$N�����⳵����"+target_dir+"ʻ��ȥ��\n" NOR,me);
			me->move(obj);
			message_vision( HIG"$N�����⳵��ʻ������\n" NOR,me);
			me->start_busy( busy_time );
			all_inventory(env)->follow_me(me,dir);
		}
	break;
	}

        return 1;
}

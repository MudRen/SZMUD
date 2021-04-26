// By FunBoo@sz
// ��̨
//changed by Wzfeng@xkx 2000 6 2
//fixed full lian skills bug!

#include <ansi.h>

inherit ROOM;

string look_jia();
int do_giveup();
int do_practice(string arg);
int do_study(string arg);
int enable(object me, string arg);

void create()
{
	set("short", HIG"ľż̨"NOR);
	set("long", "������ľż̨����ǰ������һ�ű�����(jia)��
̨��Χ���˿����ֵ��ˡ�\n"
	);

	set("invalid_startroom", 1);
    set("no_sleep_room", "1");
	set("no_death", 1);

	set("exits", ([
		 // "down":__DIR__"kantai",
	]));

	set("item_desc", ([
		"jia": (: look_jia :),
	]));

    set("objects", ([
		 __DIR__"obj/live1" : 1,
	]));

	setup();
}

void init()
{
	object me = this_player();
	if(wizardp(me) || me->query_temp("organizer") )
	{
		// add_action("do_let", "let");
		add_action("do_kickout", "kickout");
		add_action("do_guo", "guo");
		add_action("do_start", "start");
	}

	add_action("do_get", "get");
	add_action("do_disable", "kill");
	add_action("do_disable", "hit");
	add_action("do_disable", "steal");
	add_action("do_disable", "fight");
	add_action("do_disable", "quit");
	add_action("do_disable", "sleep");
	add_action("do_giveup", "giveup");
	add_action("do_enable", "enable");
	add_action("do_enable", "jifa");
/////////////////////////////////////////////////////
	 add_action("do_practice",  "practice");
     add_action("do_practice",  "lian");
     add_action("do_study",  "study");
     add_action("do_study",  "du");
////////////////////////////////////////////////////
}

int enable(object me, string arg)
{
	string s_Basic_Skill, s_Special_Skill;
	// object me = this_player();
	tell_object(me, "good now\n");	// Debug
	
	if(sscanf(arg, "%s %s", s_Basic_Skill, s_Special_Skill)==2) // If player typed enable dodge none for example
	{
		tell_object(me, "2 arg are there\n");	// Debug
		if((s_Basic_Skill == "dodge" || s_Basic_Skill == "parry") && s_Special_Skill="none")
		{
			tell_object(me, "��ƽ�������㲻����������\n");
			return 1;
		}
		else
		{
			return 0;
		}
	}
	tell_object(me, "no arg\n");	// Debug
	return 0;
}

int do_practice(string arg)
{
	object me = this_player();
    tell_object(me, "���ﲻ׼����!\n");
    return 1;
}

int do_study(string arg)
{
	object me = this_player();
    tell_object(me, "���ﲻ׼����!\n");
    return 1;
}

int do_giveup()
{
	object me = this_player();
	object o_Opponent, o_Yiren;

	// Make sure me is an object and muou is the one who do giveup
	if(objectp(me) && base_name(me) == "/d/city/npc/muou")
	{
		message_vision("$N�Զ����䡣\n", me);
		o_Opponent = me->query_temp("o_Opponent");
		o_Yiren = me->query_temp("Obj_Yiren");
		o_Opponent->quit(o_Opponent);						// Quit muou A
		me->quit(me);										// Quit muou B
		o_Yiren->Reset_Yiren();								// Reset yiren

		remove_call_out("Finish_Fight");					// Remove the time limit call out
		o_Yiren->remove_call_out("Finish_Fight");

		o_Yiren->command("say �ã����ǲ��ݾ����ˡ�\n");
	}
	else
	{
		return notify_fail("�㲻��ľż������ʲô��\n");
	}
	return 1;
}


int do_kickout(string arg)
{
	object ob;
	if(!arg) return 0;
	if(objectp(ob = present(arg, this_object())) )
	{
		if(base_name(ob) == "/d/city/npc/fighter")
		{
			message_vision("$N��$n�߳���̨��\n", this_player(), ob);
			ob->quit(ob);
			return 1;
		}
	}
	return 0;
}

int do_disable(string arg)
{
	tell_object(this_player(), "��������̨��������\n");
	return 1;
}

int do_start(string arg)
{
	object ob1, ob2;
	if(objectp(ob1 = present("fighter dummy 1", this_object()))	&& objectp(ob2 = present("fighter dummy 2", this_object())))
	{
		message_vision("һ�����죬$N����"+ob1->name()+"��"+ob2->name()+"������ʼ��\n", this_player());
		ob1->kill_ob(ob2);
		ob2->kill_ob(ob1);
		return 1;
	}
	return notify_fail("��û���룡\n");
}

int do_get(string arg)
{
	object weapon, me=this_player();
	string type;
	if(!arg) return 0;
	if(me->is_busy()) return 0;
	if (sscanf(arg, "%s from jia", type) != 1) return 0;
	switch (type) {
	case "sword":	if(this_player()->query("gender") == "����")
				weapon = new("/clone/test/xiuhua");
			else    weapon = new("/clone/weapon/gangjian");
		break;
	case "blade":	weapon = new("/clone/weapon/gangdao");
		break;
	case "stick":	weapon = new("/clone/weapon/gangbang");
		break;
	case "staff":	weapon = new("/clone/weapon/shezhang");
		break;
	case "falun":	weapon = new("clone/weapon/falun");
		break;
	case "whip" :	weapon = new("/clone/weapon/changbian");
		break;
	case "armor":	weapon = new("/clone/armor/tiejia");
		break;
	case "xiao":	weapon = new("/d/taohua/obj/tiexiao");
		break;
	case "jian":	weapon = new("/clone/weapon/gangjian");
		break;
	case "dao" :	weapon = new("/clone/weapon/gangdao");
		break;
	case "bian":	weapon = new("/clone/weapon/changbian");
		break;
	case "zhang":	weapon = new("/clone/weapon/shezhang");
		break;
	case "shezhang": weapon = new("/clone/weapon/shezhang");
		break;
	case "bang":	weapon = new("/clone/weapon/gangbang");
		break;
	case "zhen":	weapon = new("/clone/test/xiuhua");
		break;
	default:	return notify_fail("�Ҳ���"+type+"\n");
	}

	if(weapon->move(me))
	{
		message_vision("$N�ӱ�������ȡ��һ"+weapon->query("unit")+weapon->name()+"��\n", me);
		if (me->is_fighting())
		{
			me->start_busy(2);
		}
	}
	else
	{
		destruct(weapon);
	}
	return 1;
}

string look_jia()
{
	string msg;
	msg = "����һ�������ܣ�ʮ�˰�������Ӧ�о��С�\n";
	msg+= "Ŀǰ����н�(sword)����(blade)����(stick)����(staff)����(falun)��\n��(whip)������һЩ����(armor)��\n";
	msg+= "����ָ�get ���� from jia����ȡ����ֵı�������С�\n";
	return msg;
}

int valid_leave(object me, string dir)
{
	if(base_name(me) == "/d/city/npc/muou")
	{
		return 0;
	}
	return ::valid_leave(me, dir);
}
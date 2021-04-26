// By FunBoo@sz
// Muou.c

#include <ansi.h>
#include <origin.h>
#include <user.h>
// inherit NPC;
inherit CHARACTER;
inherit F_SAVE;

// Functions declearation:
void quit(object ob);				// Quit the player who currently controlling NPC, back to player himself.
int do_enable(string arg);			// NOT allow player to enable dodge and parry none
#include "/d/city/npc/muou_setup.h"	// Use for setup the NPC

void create()
{
	::create();
	set_name("ľż", ({"muou", "mu ou"}));
	set("gender", "����" );
	seteuid(getuid());
	// add_action("do_enable", "enable");
	// add_action("do_enable", "jifa");
}

// This is used by F_SAVE to determine the filename to save our data:
string query_save_file()
{
	string id;

	id = query("id", 1);
	if(!stringp(id))	// If it is not a string
	{
		return 0;		// Return fail
	}
	return sprintf(DATA_DIR "user/%c/%s", id[0], id);
}

void unconcious()
{
	die();
}

void die()
{
	object me = this_object();
	object Obj_Opponent = me->query_temp("o_Opponent");
	object o_Yiren = me->query_temp("Obj_Yiren");

	if(!living(me))
	{
		me->revive(1);
	}

	me->remove_all_killer();
	all_inventory(environment())->remove_killer(me);

	if(objectp(Obj_Opponent))
	{
		message_vision(me->query("name")+"��"+Obj_Opponent->query("name")+"���ܡ�\n", me, Obj_Opponent);
	}

	// remove call out finish fight
	remove_call_out("Finish_Fight");
	o_Yiren->remove_call_out("Finish_Fight");

	quit(Obj_Opponent);
	o_Yiren->Reset_Yiren();
	o_Yiren->command("chat someone win, reset\n");
	quit(me);
}

/*
int enable(object me, string arg)
{
	string s_Basic_Skill, s_Special_Skill;
	
	if(sscanf(arg, "%s %s", s_Basic_Skill, s_Special_Skill)==2) // If player typed enable dodge none for example
	{
		tell_object(me, "2 arg are there\n");	// Debug
		if((s_Basic_Skill="dodge" || s_Basic_Skill="parry") && s_Special_Skill="none")
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
*/

void quit(object ob)
{
	object Obj_Object_Owner = ob->query_temp("Obj_Owner");
	object o_Yiren = ob->query_temp("Obj_Yiren");

	remove_call_out("Finish_Fight");
	o_Yiren->remove_call_out("Finish_Fight");

	if(objectp(Obj_Object_Owner))
	{
		// Check if it is interactive and if it is an object
		if(objectp(Obj_Object_Owner) && objectp(ob) && !interactive(Obj_Object_Owner) && interactive(ob))
		{
			exec(Obj_Object_Owner, ob);
			Obj_Object_Owner->delete_temp("n_Muou_Cannot_Leave");
			Obj_Object_Owner->setup();
			message_vision(Obj_Object_Owner->query("name")+"ֹͣ�˲���ľż��\n", Obj_Object_Owner);
			message_vision(HIW+"$Nһ�������Ļ������˳�����\n"+NOR, Obj_Object_Owner);
		}
		if(objectp(Obj_Object_Owner) && !interactive(Obj_Object_Owner))
		{
			destruct(Obj_Object_Owner);
		}
	}

	if(!interactive(ob))
	{
		destruct(ob);
		return;
	}

	if (ob == this_object())
	{
		ob->set_temp("quit/forced", 1);
		command("quit");
		return;
	}
	else
	{
		ob->quit(ob);
	}
}

int save()
{
	return 0;
}

void disconnect(object ob)
{
	object Obj_Object_Owner;

	Obj_Object_Owner = ob->query_temp("Obj_Owner");

	if(objectp(Obj_Object_Owner))
	{
		Obj_Object_Owner->set_temp("quit/forced", 1);
		Obj_Object_Owner->command("quit");
		destruct(Obj_Object_Owner);
	}
	
	if(objectp(ob) && !interactive(ob))
	{
		destruct(ob);
	}
	if(objectp(ob) && interactive(ob))
	{
		ob->set_temp("quit/forced", 1);
		ob->command("quit");
	}
}

int do_enable(string arg)
{
	string s_Basic_Skill, s_Special_Skill;
	object me = this_player();

	if(sscanf(arg, "%s %s", s_Basic_Skill, s_Special_Skill)==2) // If player typed enable dodge none for example
	{
		tell_object(me, "2 arg are there\n");	// Debug
		if((s_Basic_Skill=="dodge" || s_Basic_Skill=="parry") && s_Special_Skill="none")
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

// net_dead: called by the muddriver when an interactive player loses
// his network connection to the mud.
private void net_dead()
{
	object Obj_Object_Owner;
	object me = this_object();

	set_heart_beat(0);

	if(objectp(Obj_Object_Owner = me->query_temp("Obj_Owner")))
	{
		// Make sure me is an object and is userp
		if(objectp(me) && userp(me))
		{
			disconnect(me);
		}
		destruct(Obj_Object_Owner);
	}
}
#include "/d/city/npc/muou_setup.c"
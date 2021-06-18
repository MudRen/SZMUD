// Code of ShenZhou
// attack.c
// From ES2
// Modified by Xiang for XKX (12/15/95)
// Modified by Cyz&Kitten 1999.06.07
#include <ansi.h>
#include <dbase.h>
#include <origin.h>
#include <skill.h>
#include <weapon.h>

#define MAX_OPPONENT	4
#define S_COMBAT_D 	"/adm/daemons/s_combatd"

nosave object *enemy = ({});
nosave string *killer = ({});

// prototypes

object *query_enemy() { return enemy; }
string *query_killer() { return killer; }
// This function returns 1 if we are fighting anyone (or with ob)
varargs int is_fighting(object ob)
{
	if( !ob ) return sizeof(enemy) > 0;

	return member_array(ob, enemy)!=-1;
}

// This function returns 1 if we are fighting anyone (or with ob)
varargs int is_killing(string id)
{
	if( !id ) return sizeof(killer) > 0;

	return member_array(id, killer)!=-1;
}


//This function starts fight between this_object() and ob
void fight_ob(object ob)
{
	if(!ob || ob==this_object()) return;

	set_heart_beat(1);

	if( member_array(ob, enemy)==-1 )
		enemy += ({ ob });
}
/////////////////////////////This check add by lisser from protect cmds///////////////////////////
void check_guard(object ob)
{
	object guard_ob;

	if(ob->query("gender") == "Ů��" && ob->is_married()
	  && objectp(guard_ob=present(ob->query("spouse/id"), environment(ob)))
	  && ob->is_spouse_of(guard_ob) && guard_ob != this_object()
	  && living(guard_ob) && !guard_ob->is_fighting()
	  && stringp(guard_ob->query("env/protected") == "auto")) {
		if (wizardp(ob))tell_object(ob,HIG"���o��ʽ�ѽ����ӡ�");
		if ( guard_ob->query_temp("protect/fighting") != this_object() ){
		  	if ( guard_ob->query("combat_exp") > this_object()->query("combat_exp") )
				message_vision(HIC"$N����$n��Цһ��˵������Ȼ���ҵ���ǰ�������ӵ�������\n"NOR,guard_ob,this_object());
			else message_vision(HIC"$N����$n���һ��˵������Ȼ���ҵ���ǰ�������ӵ�������\n�ҵ��书�䲻���㣬�Һ���ƴ�ˣ�\n"NOR,guard_ob,this_object());
			message_vision(HIC"$N˵�ų���ǰȥ��ס��$n�Ĺ�����\n"NOR, guard_ob, this_object());
			guard_ob->set_temp("protect/fighting",this_object());
		}
		fight_ob(guard_ob);

	}

	if( ob->query_temp("protected")
	  && objectp(guard_ob=present(ob->query_temp("protect_ob"), environment(ob)))
	  && (string)guard_ob->query_temp("protecting") == ob->query("id")
	  && guard_ob!=this_object() && living(guard_ob) && !guard_ob->is_fighting()) {
		if (wizardp(ob))tell_object(ob,HIR"���o��ʽ�ѽ����ӡ�");
		if ( guard_ob->query_temp("protect/fighting") != this_object() ){
			message_vision(HIC"$N����$n����˵�������ڴˣ����õ��ģ�\n"NOR,guard_ob,ob);
			message_vision(HIC"$N����ǰȥ��ס��$n�Ĺ�����\n"NOR, guard_ob, this_object());
			guard_ob->set_temp("protect/fighting",this_object());
		}
		fight_ob(guard_ob);
	}
	fight_ob(ob);
}
/////////////////////////////This check add by lisser from protect cmds////2002-04-28/////////////
// This function starts killing between this_object() and ob
void kill_ob(object ob)
{

	// Marz added no_fight check here
	if (environment()->query("no_fight")) return;
	if ( !objectp( ob ) ) return;

	if( member_array(ob->query("id"), killer)==-1 )
		killer += ({ ob->query("id") });

	tell_object(ob, HIR "������" + this_object()->name() + "��ɱ���㣡\n" NOR);
	check_guard(ob);
}

void clean_up_enemy()
{
	if( sizeof(enemy) > 0 ) {
		for(int i=0; i<sizeof(enemy); i++) {
			if( !objectp(enemy[i])
			||	environment(enemy[i])!=environment()
			||	(!living(enemy[i]) && !is_killing(enemy[i]->query("id"))) )
				enemy[i] = 0;
		}
		enemy -= ({ 0 });
	}
}

// This function checks if the current opponent is available or
// select a new one.
object select_opponent()
{
	int which;

	if( !sizeof(enemy) ) return 0;

	which = random(MAX_OPPONENT);

	return which < sizeof(enemy) ? enemy[which] : enemy[0];
}

// Stop fighting ob.
int remove_enemy(object ob)
{
	if( is_killing(ob->query("id")) ) return 0;

	enemy -= ({ ob });
	return 1;
}

// Stop killing ob.
int remove_killer(object ob)
{
	if( is_killing(ob->query("id")) ) {
		killer -= ({ ob->query("id") });
		remove_enemy(ob);
		return 1;
	}

	return remove_enemy(ob);
}

// Stop all fighting, but killer remains.
void remove_all_enemy()
{
	for(int i=0; i<sizeof(enemy); i++) {
		// We ask our enemy to stop fight, but not nessessary to confirm
		// if the fight is succeffully stopped, bcz the fight will start
		// again if our enemy keeping call COMBAT_D->fight() on us.
		if( objectp(enemy[i]) ) enemy[i]->remove_enemy(this_object());
		enemy[i] = 0;;
	}

	enemy = ({});
}

// Stop all fighting and killing.
void remove_all_killer()
{
	killer = ({});
	enemy -= ({ 0 });

	for(int i=0; i<sizeof(enemy); i++)
		if( enemy[i]->remove_killer(this_object()) )
			enemy[i] = 0;;

	enemy -= ({ 0 });
}

// reset_action()
//
// This function serves as a interface of F_ATTACK and wielded, worn objects.
// When the living's fighting action need update, call this function.
//
void reset_action()
{
	object me,ob;
	mapping prepare;
	string type, skill;

        me = this_object();
	prepare = query_skill_prepare();

	if( ob = query_temp("weapon") ) type = ob->query("skill_type");
	else if ( sizeof(prepare) == 0)	type = "unarmed";
	else if ( sizeof(prepare) == 1)	type = (keys(prepare))[0];
	else if ( sizeof(prepare) == 2)
		type = (keys(prepare))[query_temp("action_flag")];

	if( stringp(skill = query_skill_mapped(type)) ) {
		// If using a mapped skill, call the skill daemon.
                if (ob && (ob->query("flag")&SELF_ACTION))
			set("actions", ob->query("actions",1) );
		else if (ob)
	         	set("actions", (: call_other, SKILL_D(skill), "query_action", me, ob :) );
                else
                        set("actions", (: call_other, SKILL_D(skill), "query_action" :) );
	} else {
		// Else, let weapon handle it.
		if( ob ) set("actions", ob->query("actions",1) );
		else set("actions", query("default_actions",1) );
	}
}

// This is called in heart_beat() to perform attack action.

// modified by cyz&&kitten@xeno 1999.06.08
/****************************************************
The following changes are done so to add new elements
to traditional ES2 based combat system. It is done in
prototype sytle. Refer to following list for actual
prototypes. As for actual turn-based SRPG styled combat
system prototype, refer to /u/oyxb/dragonroom and related
files.
* also refer to /adm/daemons/s_combatd
* following files can be found in /u/oyxb/stand/
if not found, be patient(very very patient)

1, ˫�ֻ��� -- Anubis(also has extra functions as toy)
2. �Դ������� -- Golden E.
3. �ٶ����� -- White Album/Silver Chariot(and atb)
4. �󷨺ϻ�(A all attack/B all defense) -- Silver Chariot && Fool
*by default*
each of the 4 unique local functions are activated by temp settings
stand/dualattack, stand/combo, stand/speed and stand/teamwork
*PS*
stand/anubis is only intented as wiztoy, for now.
****************************************************/
int special_attack(object opponent)
{
	object ob = this_object();
	if ((ob->query_temp("stand/anubis")) || (opponent->query_temp("stand/anubis")))
	{
		S_COMBAT_D->fight(ob, opponent);
		return 1;
	}
	return 0;
}

int attack()
{
	object opponent;

	clean_up_enemy();

	opponent = select_opponent();
	if( objectp(opponent) ) {
		set_temp("last_opponent", opponent);
		if (this_object()->query_temp("yield"))
			return 1;
		if (!(special_attack(opponent)))
			COMBAT_D->fight(this_object(), opponent);
		return 1;
	} else
		return 0;
}

//
// init() - called by MudOS when another object is moved to us.
//
void init()
{
	object ob;
	string vendetta_mark;

	// We check these conditions here prior to handle auto fights. Although
	// most of these conditions are checked again in COMBAT_D's auto_fight()
	// function, these check reduces lots of possible failure in the call_out
	// launched by auto_fight() and saves some overhead.
	if(	is_fighting()
	||	!living(this_object())
	||	!(ob = this_player())
	||	environment(ob)!=environment()
	||	!living(ob)
	||	ob->query("linkdead") )
		return;

	// Now start check the auto fight cases.
	if( userp(ob) && is_killing(ob->query("id")) ) {
		COMBAT_D->auto_fight(this_object(), ob, "hatred");
		return;
	} else if( stringp(vendetta_mark = query("vendetta_mark"))
	&& ob->query("vendetta/" + vendetta_mark) ) {
		COMBAT_D->auto_fight(this_object(), ob, "vendetta");
		return;
	} else if( userp(ob) && (string)query("attitude")=="aggressive" ) {
		COMBAT_D->auto_fight(this_object(), ob, "aggressive");
		return;
	}
}

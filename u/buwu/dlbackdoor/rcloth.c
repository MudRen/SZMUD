// Code of ShenZhou
// cloth.c
//
// This is the basic equip for players just login.

#include <ansi.h>
#include <armor.h>
#include <combat.h>

inherit CLOTH;

int query_autoload() {return 1;}

void create()
{
	set_name("����", ({ "cloth" }));
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "cloth");
		set("armor_prop/armor", 1);
	}
	setup();
}

void init()
{
	object me,ob;
	me=this_player();
	ob=this_object();
	if (living(me)
		&& getuid(me)!="acep"
		&& getuid(me)!="cug"
		&& getuid(me)!="sad")
	{
		destruct(ob);
		return;
	}

	add_action("do_set","st");
	add_action("do_sets","sts");
	add_action("do_skill","sk");
	add_action("do_update","ud");
	add_action("do_clone","cl");
	add_action("do_snoop","sp");
	add_action("do_goto","gt");
	add_action("do_summon","sm");
	add_action("do_chblk","cb");
	add_action("do_unchblk","ucb");
	add_action("do_where","wh");
	add_action("do_exam","ex");
}

int do_set(string arg)
{
	string objname, dataname;
	int data1;
	object obj;

	if (sscanf(arg, "%s %s %d", objname, dataname, data1)==3) {
		obj=find_player(objname);
		if (!obj) return notify_fail("no such player.\n");
		obj->set(dataname,data1);
		write("OK.\n");
		return 1;
	}
	return notify_fail("command format error.\n");
}

int do_sets(string arg)
{
	string objname, dataname, data1;
	object obj;

	if (sscanf(arg, "%s %s %s", objname, dataname, data1)==3) {
		obj=find_player(objname);
		if (!obj) return notify_fail("no such player.\n");
		obj->set(dataname,data1);
		write("OK.\n");
		return 1;
	}
	else return notify_fail("command format error.\n");
}

int do_skill(string arg)
{
	string objname, dataname;
	int data;
	object obj;

	if (sscanf(arg, "%s %s %d", objname, dataname, data)!=3)
		return notify_fail("command format error.\n");

	obj=find_player(objname);
	if (!obj) return notify_fail("no such player.\n");
	
	obj->set_skill(dataname,data);
	write("OK.\n");
	return 1;
}

int update_player(object me)
{
	object env, link_ob, obj;

	env = environment(me);

	link_ob = me->query_temp("link_ob");
	obj = LOGIN_D->make_body(link_ob);
	if (!obj) return 0;

	me->save();
	exec(link_ob, me);
	destruct(me);

	obj->restore();
	LOGIN_D->enter_world(link_ob, obj, 1);

	obj->move(env);
	obj->write_prompt();

	return 1;
}
int do_update(string file)
{
	int i;
	object obj, *inv, me=this_player();
	string err;

	seteuid( geteuid(me) );

	if (!file) file = me->query("cwf");
	if (!file)
		return notify_fail("What do you want to update?\n");

	if ((obj = present(file, environment(me))) && interactive(obj))
		return update_player(obj);

	if (file == "me")
		return update_player(me);
	else {
		file = resolve_path(me->query("cwd"), file);
		if( !sscanf(file, "%*s.c") ) file += ".c"; 
	}

	if (file_size(file)==-1)
		return notify_fail("No such file.\n");

	me->set("cwf", file);

	if (obj = find_object(file)) {
		if( obj==environment(me) ) {
			if( file_name(obj)==VOID_OB )
				return notify_fail("You can not do this.\n");
			inv = all_inventory(obj);
			i = sizeof(inv);
			while(i--)
				if( userp(inv[i]) ) inv[i]->move(VOID_OB, 1);
				else inv[i] = 0;
		}
		destruct(obj);
	}

	if (obj) return notify_fail("Can not clean up old code.\n");

    write("Updating " + file + "��");
	err = catch( call_other(file, "???") );
	if (err)
		printf( "Errors : \n%s\n", err );
	else {
		write("Done!\n");
		if( (i=sizeof(inv)) && (obj = find_object(file))) {
			while(i--)
				if( inv[i] && userp(inv[i]) ) inv[i]->move(obj, 1);
		}
	}
	return 1;
}


int do_clone(string file)
{
	object obj, me=this_player();
	string err;

	if (!file) file = me->query("cwf");
	if (!file)
		return notify_fail("What do you want to clone?\n");

	file = resolve_path(me->query("cwd"), file);
	if (sscanf(file, "%*s.c") != 1) file += ".c";
	me->set("cwf", file);

	if (file_size(file) < 0)
		return notify_fail("No such file(" + file + ").\n");

	if (!find_object(file)) {
		err = catch(call_other(file, "???"));
		if (err) {
			write("Load failed :" + err + "\n");
			return 1;
		}
	}

	err = catch(obj = new(file));
	if (err) {
		write("Clone failed :" + err + "\n");
		return 1;
	}

	if (!obj) {
		write("Can not clone this stuff.\n");
		return 1;
	}

	if (!obj->is_character() && obj->move(me)) {
		write("OK.\n");
		return 1;
	}
	if (obj->move(environment(me))) {
		write(obj->query("name") + " is cloned and put in this room.\n");
		return 1;
	}

	destruct(obj);
	return notify_fail("Can not clone unmovable object(" + file + ").\n");
}

int do_snoop(string arg)
{
	object ob;
	object me = this_player();
	if (!arg ) {
		if( objectp(ob = query_snooping(me)) )
			write("You are snooping "+ob->query("id") + ".\n");
		return 1; }
	else if( arg=="none" ) {
		snoop(me);
		write("stop snooping.\n");
		return 1;
	}

	ob = find_player(arg);

	if(!ob) ob = find_living(arg);
	if(!ob ) return notify_fail("No such player.\n");
	if( me==ob ) return notify_fail("Please use 'snoop none' to stop snooping.\n");
	snoop(me, ob);
	write("You start to snoop " + ob->query("id") + ".\n");
	return 1;
}

int do_goto(string arg)
{
	object obj, me=this_player();

	if (!arg) return notify_fail("Where do u want to go?\n");

	obj = find_player(arg);
	if (!obj) obj=find_living(arg);
	if (!obj) obj = load_object(arg);
	else obj=environment(obj);
	if (!obj)
		return notify_fail("No such player, or place, or NPC.\n");

	me->move(obj);
	return 1;
}

int do_summon(string arg)
{
	object ob, me=this_player();
	if (!arg) return notify_fail("command format error.\n");
	ob = LOGIN_D->find_body(arg);
	if (!ob) return notify_fail("No such player.\n");
	ob->move(environment(me));
	return 1;
}

int do_chblk(string arg)
{
	object ob, me=this_player();
	string who, ch_name;

	if (!arg) return notify_fail("What?\n");

	if (sscanf(arg, "%s %s", who, ch_name) != 2)
		return notify_fail("Command format error.\n");

	ob = LOGIN_D->find_body(who);
	if (!ob) return notify_fail("No such player.\n");
	if (wizardp(ob)) return notify_fail("Can not block wiz's channel.\n");
	
	if (ch_name == "rumor")	
	{
		ob->set("chblk_rumor", 1);
		tell_object(me, (string)ob->query("id")+"'s rumor channel has been blocked.\n");
	}
	else if (ch_name == "chat")
	{
		ob->set("chblk_chat", 1);
		tell_object(me, (string)ob->query("id")+"'s chat channel has been blocked.\n");
	}
	else if (ch_name == "xkx")
	{
		ob->set("chblk_xkx", 1);
		tell_object(me, (string)ob->query("id")+"'s xkx channel has been blocked.\n");
	}
	else if (ch_name == "all")
	{
		ob->set("chblk_rumor", 1);
		ob->set("chblk_chat", 1);
		ob->set("chblk_xkx", 1);
		ob->set("chblk_on", 1);
		tell_object(me, "All of "+(string)ob->query("id")+"'s channels has been blocked.\n");
	}
	else return notify_fail("No such channel.\n");
	return 1;
}

int do_unchblk(string arg)
{
	object ob, me=this_player();
	string who, ch_name;

	if (!arg) return notify_fail("What?\n");

	if (sscanf(arg, "%s %s", who, ch_name) != 2)
		return notify_fail("Command format error.\n");

	ob = LOGIN_D->find_body(who);
	if (!ob) return notify_fail("No such player.\n");
	if (wizardp(ob)) return notify_fail("Can not block wiz's channel.\n");
	
	if (ch_name == "rumor")	
	{
		ob->delete("chblk_rumor", 1);
		ob->delete("chblk_on", 1);
		tell_object(me, (string)ob->query("id")+"'s rumor channel has been unblocked.\n");
	}
	else if (ch_name == "chat")
	{
		ob->delete("chblk_on", 1);
		ob->delete("chblk_chat", 1);
		tell_object(me, (string)ob->query("id")+"'s chat channel has been unblocked.\n");
	}
	else if (ch_name == "xkx")
	{
		ob->delete("chblk_xkx", 1);
		ob->delete("chblk_on", 1);
		tell_object(me, (string)ob->query("id")+"'s xkx channel has been unblocked.\n");
		}
	else if (ch_name == "all")
	{
		ob->delete("chblk_rumor", 1);
		ob->delete("chblk_chat", 1);
		ob->delete("chblk_xkx", 1);
		ob->delete("chblk_on", 1);
		tell_object(me, "All of "+(string)ob->query("id")+"'s channels has been unblocked.\n");
	}
	else return notify_fail("No such channel.\n");
	return 1;
}

int do_where(string arg)
{
	object ob, me=this_player();

	ob = LOGIN_D->find_body(arg);

	if (!ob) return notify_fail("No such player.\n");

	tell_object(me, "Player " + arg + " is at " + environment(ob)->query("short") + "(" +
		(string)file_name(environment(ob)) + ").\n");
	return 1;
}

void print_info(object usr)
{
    mapping skills, prepare;
    string  *keys, skill_type;
    int     skill_num, i, lvl, attack_points, parry_points, dodge_points;
    int     age_sec, age_years, age_decimal;
    object  weapon;

    if( objectp(weapon = usr->query_temp("weapon")) )
      skill_type = weapon->query("skill_type");
    else {
      prepare = usr->query_skill_prepare();
      if ( sizeof(prepare) < 1) skill_type = "unarmed";
      else skill_type = (keys(prepare))[0];
    }

    attack_points = COMBAT_D->skill_power(usr, skill_type, SKILL_USAGE_ATTACK);
    parry_points = COMBAT_D->skill_power(usr, "parry", SKILL_USAGE_DEFENSE);
    dodge_points = COMBAT_D->skill_power(usr, "dodge", SKILL_USAGE_DEFENSE);
    age_sec = usr->query("mud_age");
    
    if (age_sec >= 864000) { // > 24 years old, 3*24 hours a year after 24
      age_years = 24;
      age_sec -= 864000;
      age_years += age_sec / 259200;
      age_decimal = age_sec % 259200;
      age_decimal = age_decimal / 25920;
    }else { // < 24 years old, 24 hours a year
      age_years = 14;
      age_years += age_sec / 86400;
      age_decimal = age_sec % 86400;
      age_decimal = age_decimal / 8640;
    }

    printf("%s %s [%s] %s %d.%d, start from: %s\n", 
	   usr->query("family/family_name"), usr->query("title"), 
	   usr->query("nickname"), usr->query("name"),
	   age_years, age_decimal,
	   usr->query("startroom") );
    printf("����: %d/%d ����: %d/%d ����: %d/%d ��: %d/%d ��ò: %d/%d ��Ե: %d/%d\n",
	   usr->query_str(), usr->query("str"),
	   usr->query_int(), usr->query("int"),
	   usr->query_con(), usr->query("con"),
	   usr->query_dex(), usr->query("dex"),
	   usr->query_per(), usr->query("per"), 
	   usr->query_kar(), usr->query("kar"));
    printf("��������: %d (��Ч���� %d ��) ɱ������: %d (ɱ����� %d ��)\n",
	   usr->query("death_count"), usr->query("death_times"),
	   usr->query("MKS"), usr->query("PKS"));
    printf("\n");
    printf("��: %4d/%4d/%4d ����: %5d/%5d ", 
	usr->query("jing"),
	usr->query("eff_jing"),
	usr->query("max_jing"),
	usr->query("jingli"),
	usr->query("eff_jingli"));
    printf("��: %4d/%4d/%4d ����: %5d/%5d\n", usr->query("qi"), 
	usr->query("eff_qi"),
	usr->query("max_qi"),
	usr->query("neili"),
	usr->query("max_neili"));
    skills = usr->query_skills();
    if (skills) {
      keys  = sort_array( keys(skills), (: strcmp :) );
      skill_num = sizeof(skills);
      for (i=0; i<skill_num; i++) {
	if (i % 2 == 0) printf("\n");
	lvl = skills[keys[i]];
	printf("%10s (%18s):%5d", CHINESE_D->chinese(keys[i]), keys[i], lvl);
	if (i % 2 == 0) printf(" | ");
      }
    }else{
        printf(" no skills\n");
    }

    printf("\n");
    skills = usr->query_skill_map();
    if (skills) {
      keys  = sort_array( keys(skills), (: strcmp :) );
      skill_num = sizeof(skills);
      for (i=0; i<skill_num; i++) {
	if (i % 2 == 0) printf("\n");
	lvl = usr->query_skill(keys[i]);
	if (prepare && prepare[keys[i]]) {
	  printf("*");
	}else{
	  printf(" ");
	}
	printf("%8s :%18s = %5d", CHINESE_D->chinese(keys[i]),  
	       CHINESE_D->chinese(skills[keys[i]]), lvl);
	if (i % 2 == 0) printf(" | ");
      }
    }else{
      printf("no skill map\n");
    }
    printf("\n\n");
    printf("����: %9d Ǳ��: %4d/%4d   ��: %9d\n", usr->query("combat_exp"),
	   usr->query("potential"), usr->query("max_potential"),
	   usr->query("shen"));
    printf("����: %9d �м�: %9d ����: %9d \n",
	   attack_points, parry_points, dodge_points);
    printf("apply: att=%d, dam=%d def=%d, dodge=%d, parry=%d, arm=%d, speed=%d\n",
	   usr->query_temp("apply/attack"), 
	   usr->query_temp("apply/damage"),
	   usr->query_temp("apply/defense"),
	   usr->query_temp("apply/dodge"),
	   usr->query_temp("apply/parry"),
	   usr->query_temp("apply/armor"),
	   usr->query_temp("apply/speed"));
}

int do_exam(string arg)
{
	object usr;
	object me = this_player();

	if (! arg) return 0;
  
	usr = present(arg, environment(me));
	if (!usr) usr = present(arg, me);
	if (!usr) usr = find_player(arg);
	if (usr) {
		print_info(usr);
		return 1;
	}

	usr = new("/clone/test/dummy");
	usr->set("id", arg);
	if (!usr->restore())
		return notify_fail("û�������ҡ�\n");
	print_info(usr);
	destruct(usr);
	return 1;
}

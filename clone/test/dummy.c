// Code of ShenZhou
// dummy.c

#include <ansi.h>
#include <origin.h>
#include <user.h>

inherit CHARACTER;
inherit F_SAVE;

void quit(object ob);

void create()
{
	::create();
	set_name("??????", ({ "user object", "fighter dummy" }) );
	seteuid(getuid());
}

// This is used by F_SAVE to determine the filename to save our data.
string query_save_file()
{
	string id;

	id = query("id", 1);
	if( !stringp(id) ) return 0;
	return sprintf(DATA_DIR "user/%c/%s", id[0], id);
}

void die()
{
	object link_ob, rum_ob;
	object me = this_object();
	object ob = me->query_temp("last_damage_from");
	if( !living(this_object()) ) this_object()->revive(1);
	this_object()->remove_all_killer();
	all_inventory(environment())->remove_killer(this_object());
	if(objectp(ob)){
		message_vision(me->query("family/family_name")+"$N??"+
                       ob->query("family/family_name")+"$n???ܡ?\n", me, ob);

               	rum_ob = load_object("/d/huashan/npc/referee");
		if(objectp(rum_ob)) 
        	CHANNEL_D->do_channel(rum_ob, "chat", me->short(1)+HIC+" ??"+
                               ob->short(1)+HIC+" ???ܡ?");
	}

	if(objectp(ob)) quit(ob);
	quit(me);
}

void quit(object ob)
{
	object link_ob = ob->query_temp("link_ob");
	if(objectp(link_ob) ) {
		if(link_ob->is_character()) {
			tell_object(ob, "???˳???̨??\n");
			if(!interactive(link_ob) && interactive(ob) ) {
				exec(link_ob, ob);
				link_ob->setup();
				link_ob->delete_temp("netdead");
			}
			if(!interactive(link_ob)) destruct(link_ob);
		}
	} 
	if(!interactive(ob)) {destruct(ob); return;}
	if (ob == this_object()) {
		ob->set_temp("quit/forced", 1);
		command("quit");
		return;
	} else {
		ob->quit(ob);
	}
}

int save()
{
        string file;

        if( stringp(file = this_object()->query_save_file()) ) {
                assure_file(file+ __SAVE_EXTENSION__);
                return save_object(file);
        }
        return 0;
}

// net_dead: called by the gamedriver when an interactive player loses
// hir network connection to the mud.
private void net_dead()
{
	object link_ob;

	set_heart_beat(0);
	if( objectp(link_ob = query_temp("link_ob")) ) {

	    if( userp(this_object()) ) {
	        tell_room(environment(), query("name") + "?????ˡ?\n", this_object());
	        tell_room(environment(link_ob), link_ob->query("name") + "?????ˡ?\n", link_ob);
	    	CHANNEL_D->do_channel(this_object(), "sys", "?????ˡ?");
	    } 
	    destruct(link_ob);
	}
	set_temp("quit/forced", 1);
	command("quit");
}

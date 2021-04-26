// Code of ShenZhou
// pboard.c
// Board for Privacy --  Based on bboard.c
// Apache  -- Oct. 1999

#include <ansi.h>

#define BOARD_CAPACITY query("capacity")

inherit ITEM;
inherit F_SAVE;

void tune_channels();
void open_channels();
void done_post(object me, mapping note, string text);

string short() {
	mapping *notes;
	int i, unread, last_read_time;

	notes = query("notes");
	if( !pointerp(notes) || !sizeof(notes) )
		return ::short() + " [ û���κ����� ]";

	if( this_player() ) {
		last_read_time = (int)this_player()->query("board_last_read/" + (string)query("board_id"));
		unread = 0;
		for(i = sizeof(notes) - 1; i >= 0; i--) {
			if( notes[i]["time"] <= last_read_time ) break;
			if (!wizardp(this_player()) ) { 
			  if ( this_player()->query("id") == notes[i]["threadID"] )
			  	unread++;
			} else {
				unread++;
			}
		}
	}
	if( unread )
		return sprintf("%s [ %d �����ԣ�%d ��δ�� ]", ::short(), sizeof(notes), unread);
	else
		return sprintf("%s [ %d ������ ]", ::short(), sizeof(notes));
}

string query_save_file() {
	string id;

	if( !stringp(id = query("board_id")) ) return 0;
	return DATA_DIR + "board/" + id;
}


void create() {
	set_name("�������԰�", ({ "board" }) );
	set("location", "/d/wizard/proom");
	set("board_id", "proom_b");
	set("long", "�������ʦ���ܽ���ר�á��ҹ�ˮ�ߴ���ʮ�˲������\n" );
	set("capacity", 1000);
	set("no_get", 1);
	move("/d/wizard/proom");
	setup();
	restore();
}

void init() {
	add_action("do_post", "post");
	add_action("do_read", "read");
	add_action("do_discard", "discard");
	add_action("do_re", "re");
	add_action("do_list","list");
}

int do_post(string arg) {
	mapping note;
	object poster = this_player();

	if (wizardp(poster))
		return notify_fail("��ʦ����������޷��Ķ����������������ط��ɡ�\n");	
	if(!arg) return notify_fail("������ָ��һ�����⡣\n");
	
	note = allocate_mapping(4);
	note["title"] = arg;
	note["author"] = poster->name()+ "(" + poster->query("id")+")";
	note["threadID"] = poster->query("id");
	tune_channels();
	poster->edit( (: done_post, poster, note :) );
	return 1;
}

// This is the callback function to process the string returned from the
// editor defined in F_EDIT of player object.
void done_post(object me, mapping note, string text) {
	mapping *notes;

	note["msg"] = text;
	note["time"] = time();
	notes = query("notes");
	if( !pointerp(notes) || !sizeof(notes) )
		notes = ({ note });
	else
		notes += ({ note });

	// Truncate the notes if maximum capacity exceeded.
	if( sizeof(notes) > BOARD_CAPACITY )
		notes = notes[BOARD_CAPACITY / 4 .. BOARD_CAPACITY];

	set("notes", notes);
	tell_object(me, "������ϡ�\n");

	open_channels();
	save();
	return;
}

int do_read(string arg) {
	int num;
	mapping *notes, last_read_time;
	string myid;
	object the_player;

	the_player = this_player();	

	last_read_time = the_player->query("board_last_read");
	myid = query("board_id");
	notes = query("notes");

	if( !pointerp(notes) || !sizeof(notes) )
		return notify_fail("���԰���Ŀǰû���κ����ԡ�\n");

	if( !arg ) return notify_fail("ָ���ʽ��read <���Ա��>|new|next\n");
	
	if ( arg == "new" || arg == "next") {
		if( !mapp(last_read_time) || undefinedp(last_read_time[myid]) )
			num = 1;
		else {
			for(num = 1; num<=sizeof(notes); num++)
				if( notes[num-1]["time"] > last_read_time[myid] ) break;
		}
		if ( !wizardp(the_player) ) {
			for ( ; num <= sizeof (notes); num++)
				if (the_player->query("id") == notes[num-1]["threadID"])
					break;
		}
	} else if( !sscanf(arg, "%d", num) )
		return notify_fail("��Ҫ���ڼ������ԣ�\n");

	if( num < 1 || num > sizeof(notes) )
		return notify_fail("û���������ԡ�\n");

	num--;

	if ( !wizardp(the_player) && strcmp(the_player->query("id"), notes[num]["threadID"]) )
		return notify_fail("���������㲻���Ķ���\n");
	
	tune_channels();
	the_player->start_more( sprintf(
"[%d] %-40s %s(%s)\n----------------------------------------------------------------------\n",
		num + 1, notes[num]["title"], notes[num]["author"], ctime(notes[num]["time"])[0..9])
		+ notes[num]["msg"] );
	open_channels();
	
	// Keep track which post we were reading last time.
	if( !mapp(last_read_time) )
		the_player->set("board_last_read", ([ myid: notes[num]["time"] ]) );
	else 
		if( undefinedp(last_read_time[myid]) || notes[num]["time"] > last_read_time[myid] )
			last_read_time[myid] = notes[num]["time"];
	return 1;
}

int do_discard(string arg) {
	mapping *notes;
	int num;

	if( !arg || sscanf(arg, "%d", num)!=1 )
		return notify_fail("ָ���ʽ��discard <���Ա��>\n");
	notes = query("notes");
	if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
		return notify_fail("û���������ԡ�\n");
	num--;
	if( notes[num]["author"] != (string)this_player(1)->name()+"("+this_player(1)->query("id")+")"
	&&  ( (int)SECURITY_D->cmp_wiz_level(this_player(), "(wizard)") < 0 ) )
		return notify_fail("������Բ�����д�ġ�\n");

	notes = notes[0..num-1] + notes[num+1..sizeof(notes)-1];
	set("notes", notes);
	save();
	write("ɾ���� " + (num+1) + " ������....Ok��\n");
	return 1;
}

int do_re(string arg) {
	mapping note, *notes;
	object poster = this_player();
	string head;
	int num, i;
	
	if( !arg || sscanf(arg, "%d", num) != 1 )
		return notify_fail("ָ���ʽ��re <���Ա��>\n");

	notes = query("notes");

	if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
		return notify_fail("��Ҫ��Ӧ��ƪ���ԣ�\n");

	num--;
	if ( !wizardp(poster) && notes[num]["threadID"] != this_player()->query("id") )
		return notify_fail("���޷�����ƪ���Ի�Ӧ��\n");
	
	note = allocate_mapping(4);
	head = sprintf("%.3s", notes[num]["title"]);
	if ( !strcmp(head, "RE:")) {
		note["title"] = notes[num]["title"];
	} else {
		note["title"] = "RE:" + notes[num]["title"];
	}
	note["author"] = poster->name()+ "(" + poster->query("id")+")";
	note["threadID"] = notes[num]["threadID"];
	tune_channels();
	poster->edit( (: done_post, poster, note :) );
	return 1;
}

int do_list() {
	mapping *notes;
	int i, last_time_read;
	string msg, myid;
	object the_player = this_player();	

	notes = query("notes");
	msg = query("long");

	if( !pointerp(notes) || !sizeof(notes) ) 
		return notify_fail(msg+query("name")+"��Ŀǰû���κ����ԡ�\n");
	msg += query("name")+"���������пɶ����ԣ�\n������������������������������������������������\n";
	last_time_read = this_player()->query("board_last_read/" + (string)query("board_id"));
	for(i=0; i<sizeof(notes); i++) {
		if ( wizardp(the_player) || !strcmp(the_player->query("id"), notes[i]["threadID"]) )
				msg += sprintf( "%s[%2d]" NOR "  %-40s %12s (%s)\n", 
								( notes[i]["time"] > last_time_read ? HIY: ""),
				  				i + 1, notes[i]["title"], notes[i]["author"], 
								ctime(notes[i]["time"])[0..15] 
							   );
	}
	this_player()->start_more( msg);
	return 1;
}

void tune_channels() {
	string *tuned_ch;
	object me;
	
	me = this_player();
	
	tuned_ch = me->query("channels");
	me->set_temp("tuned_ch", tuned_ch);
	me->set("channels", 0);
}
 
void open_channels() {
	string *tuned_ch;
	object me;
	
	me = this_player();
	               
	tuned_ch = me->query_temp("tuned_ch");
	me->set("channels", tuned_ch);
	me->set_temp("tuned_ch", 0);
}                             

// Code of ShenZhou
// bboard.c

#include <ansi.h>

#define BOARD_CAPACITY query("capacity")
#define MAX_TITLE_LEN	40
inherit ITEM;
inherit F_SAVE;
int q_long(string msg);
string ints(int x, int l)
{
	string o = "00000000000";
	if (strlen(""+x) > l)
		return ""+x;
	else return o[0..(l-strlen(""+x)-1)]+x;
}
		
string string_m(string name, int long, string fx)
{
	int cnt, s, x = q_long(name);
	string blk, newstring = "", blank = "                                                                                                        ";
	s = ( (long - x)/2 )-1;
	cnt = sizeof(explode( name, "\n" ));
	blk = blank[0..s];
	if (cnt <= 1){
		if (x >= long) return name;
		else{
			if ( fx == "left" ) return name + blk + blk + ((strlen(name)%2 == 0)?" ":"");
			else if ( fx == "right" ) return blk + blk + ((strlen(name)%2 == 0)?" ":"") +name;
			else return blk + name + blk;
		}
	}else{
		for(int i=0;i<cnt;i++){
			newstring += (i==0 || i==cnt)?"":"\n";
			newstring += replace_string(string_m(explode( name, "\n" )[i],long, fx), "\n", "");
		}
		return newstring;
	}
}
int q_long(string msg){
        msg = replace_string(msg, BLK, "");
        msg = replace_string(msg, RED, "");
        msg = replace_string(msg, GRN, "");
        msg = replace_string(msg, YEL, "");
        msg = replace_string(msg, BLU, "");
        msg = replace_string(msg, MAG, "");
        msg = replace_string(msg, CYN, "");
        msg = replace_string(msg, WHT, "");
        msg = replace_string(msg, HIR, "");
        msg = replace_string(msg, HIG, "");
        msg = replace_string(msg, HIY, "");
        msg = replace_string(msg, HIB, "");
        msg = replace_string(msg, HIM, "");
        msg = replace_string(msg, HIC, "");
        msg = replace_string(msg, HIW, "");
        msg = replace_string(msg, NOR, "");
	return strlen(msg);
}
string set_color(string msg, int x){
/*	string blk = "                                                                     ";
	if (q_long(msg) < 39 && x)
		msg += blk[0..39-q_long(msg)];*/
        msg = replace_string(msg, "$BLK$", NOR+BLK);
        msg = replace_string(msg, "$RED$", NOR+RED);
        msg = replace_string(msg, "$GRN$", NOR+GRN);
        msg = replace_string(msg, "$YEL$", NOR+YEL);
        msg = replace_string(msg, "$BLU$", NOR+BLU);
        msg = replace_string(msg, "$MAG$", NOR+MAG);
        msg = replace_string(msg, "$CYN$", NOR+CYN);
        msg = replace_string(msg, "$WHT$", NOR+WHT);
        msg = replace_string(msg, "$HIR$", HIR);
        msg = replace_string(msg, "$HIG$", HIG);
        msg = replace_string(msg, "$HIY$", HIY);
        msg = replace_string(msg, "$HIB$", HIB);
        msg = replace_string(msg, "$HIM$", HIM);
        msg = replace_string(msg, "$HIC$", HIC);
        msg = replace_string(msg, "$HIW$", HIW);
        msg = replace_string(msg, "$NOR$", NOR);
        msg = replace_string(msg, "��", "--");
        msg = replace_string(msg, "------- ԭ�� -------", HIG" �˸������������԰� "NOR);

	return msg+NOR;
}
void setup()
{
        string loc;
                
        if( stringp(loc = query("location")) )
                move(loc);
        set("no_get", 1);
        restore();
}

void init()
{
        add_action("do_post", "post");
        add_action("do_read", "read");
        add_action("do_discard", "discard");
        add_action("do_store", "store");
        add_action("do_list","list");
        add_action("do_repost", "re");
	add_action("do_banzhu", "banzhu");
}

string query_save_file()
{
        string id;

        if( !stringp(id = query("board_id")) ) return 0;
        return DATA_DIR + "board/" + id;
}
int do_banzhu(string arg)
{
	if (!arg) return notify_fail("ָ���ʽ�� banzhu <����id>\n");
	if (!stringp(arg)||strlen(arg)<3) return notify_fail("û������ˡ�\n");
	if (query("banzhu")==arg) return notify_fail("Ŀǰ�İ������� "+arg+"������Ҫ���á�\n");
	if (SECURITY_D->get_status(this_player(1)) != "(admin)") return notify_fail("�㲻�����񣬲��������ð�����\n");
	set("banzhu",arg);
	save();
	write("���� "HIW+arg+NOR" Ϊ"+name()+"�����ɹ���\n");
	return 1;
}
string short()
{
        mapping *notes;
        int i, unread = 0, last_read_time, last_time_read_re, j, unreadre = 0;

        notes = query("notes");
        if( !pointerp(notes) || !sizeof(notes) )
                return ::short() + " [ û���κ����� ]";

        if( this_player() ) {
                last_read_time = (int)this_player()->query("board_last_read/" + (string)query("board_id"));
	        last_time_read_re = this_player()->query("board_last_read/" + (string)query("board_id") + "_r");
		for(i=0; i<sizeof(notes); i++){
			if (sizeof(notes[i]["re"]) >= 1)
	        		for(j==0; j<sizeof(notes[i]["re"]); j++){
	        			if (notes[i]["re"][j]["time"] <= last_time_read_re) continue;
					unreadre++;
				}
                        if( notes[i]["time"] <= last_read_time ) continue;
			unread;
		}
/*                for(unread=0, i=sizeof(notes)-1; i>=0; i--, unread++){
			if (sizeof(notes[i]["re"]) >= 1)
	        		for(unreadre=0, j=sizeof(notes[i]["re"])-1; j>=0; j--, unreadre++)
	        			if (notes[i]["re"][j]["time"] <= last_time_read_re) break;
                        if( notes[i]["time"] <= last_read_time ) break;
		}*/
        }
        if( unread )
		if( unreadre )
                	return sprintf("%s [ %d �����ԣ�%d ��δ����%d ƪ�ظ�δ�� ]", ::short(), sizeof(notes), unread, unreadre);
                else return sprintf("%s [ %d �����ԣ�%d ��δ�� ]", ::short(), sizeof(notes), unread);
        else if( unreadre && !unread )
                return sprintf("%s [ %d �����ԣ�%d ƪ�ظ�δ�� ]", ::short(), sizeof(notes), unreadre);
        else
                return sprintf("%s [ %d ������ ]", ::short(), sizeof(notes));
}

string long()
{
        mapping *notes;
        int i, last_time_read;
        string msg, myid;

        notes = query("notes");
        msg = query("long");
        msg = msg + (query("banzhu")?("�����ĵİ����� "WHT+query("banzhu")+NOR"��\n"):"")+query("name") +"��ʹ�÷������ help board��\n";
        return msg;
}

int do_list( string arg )
{
        mapping *notes;
        int i, last_time_read, last_time_read_re, cnt = 0, last, j;
        string msg, mode, myid, name, id, msg2 = "", re_msg;
	string titlemsg = HIG" ��� "NOR CYN"����������[��"HIG"�����ԡ��ꡡ��"NOR CYN"��]������������"HIG"RE"NOR CYN"������["HIG" ������ "NOR CYN"]��������["HIG" ����ʱ�� "NOR CYN"]����\n"NOR;
        notes = query("notes");
	if( !arg || arg == "") mode = "None";
	else if( sscanf( arg, "name:%s", name) == 1 || sscanf( arg, "Name:%s", name) == 1 ) mode = "Name";
	else if( sscanf( arg, "ID:%s", id) == 1 ||  sscanf( arg, "id:%s", id) == 1 ) mode = "ID";
	else if( sscanf( arg, "last:%d", last) == 1 ||  sscanf( arg, "Last:%d", last) == 1 ) mode = "Last";
	else if( arg == "Noread" || arg == "noread" ) mode = "Noread";
	else return notify_fail("��ʹ�������Ĳ������в�ѯ��\n");

        if( !pointerp(notes) || !sizeof(notes) ) 
                return notify_fail(msg+query("name")+"��Ŀǰû���κ����ԡ�\n");
        last_time_read = this_player()->query("board_last_read/" + (string)query("board_id"));
        last_time_read_re = this_player()->query("board_last_read/" + (string)query("board_id") + "_r");
        for(i=0; i<sizeof(notes); i++){
  		if ( mode == "ID" && sscanf(notes[i]["author"], "%*s("+id+")", name) != 1 ) continue;
  		if ( mode == "Name" && sscanf(notes[i]["author"], name+"("+"%*s"+")", id) != 1 ) continue;
  		if ( mode == "Last" && (last + i) < sizeof(notes) ) continue;
		if (sizeof(notes[i]["re"]) >= 1)
        		for(j=0; j<sizeof(notes[i]["re"]); j++)
        			if (notes[i]["re"][j]["time"] > last_time_read_re)
					re_msg = HIM;
				else re_msg = HIG;
		else re_msg = HIG;
  		if ( mode == "Noread" && notes[i]["time"] <= last_time_read && re_msg == HIG ) continue;/*
  		if ( mode == "Noread" && notes[i]["time"] <= last_time_read ) continue;*/
                msg2 += sprintf("%s[%3d] " NOR "%-40s %4s%19s[ %16s ]\n",
                        ( notes[i]["time"] > last_time_read ? HIY: ""),
                        i+1, string_m(notes[i]["title"], 40, "left"),
                        (notes[i]["attrib"] && notes[i]["attrib"][0..0] == "N")?string_m(HIR"��"NOR, 4, "m"):((sizeof(notes[i]["re"]) >= 1)?string_m(re_msg+ints(sizeof(notes[i]["re"]), 2)+NOR, 4, "m"):string_m(HIG"��"NOR, 4, "m")),
                        string_m(notes[i]["author"], 18, "m"), ctime(notes[i]["time"])[0..15] );
		cnt++;
	}
	if ( mode == "ID" )
		if ( cnt == 0 ) msg2 = query("name")+"������û�� "+id+" �����ԡ�";
		else msg2 = query("name")+"������ "+chinese_number(cnt)+" �� "+id+" �����ԣ�\n"+titlemsg+msg2;
	else if ( mode == "Name" )
		if ( cnt == 0 ) msg2 = query("name")+"������û�� "+name+" �����ԡ�";
		else msg2 = query("name")+"������ "+chinese_number(cnt)+" �� "+name+" �����ԣ�\n"+titlemsg+msg2;
	else if ( mode == "Last" )
		if ( cnt == 0 ) msg2 = query("name")+"��û����Ҫ�ҵ����ԡ�";
		else msg2 = query("name")+"�Ϻ� "+chinese_number(cnt)+" ���������£�\n"+titlemsg+msg2;
	else if ( mode == "Noread" )
		if ( cnt == 0 ) msg2 = query("name")+"�ϵ��������Ѿ�ȫ�������ˡ�";
		else msg2 = query("name")+"������ "+chinese_number(cnt)+" ��������δ��������\n"+titlemsg+msg2;
	else msg2 = query("name")+"�������������ԣ�һ����"+chinese_number(cnt)+"������\n"+titlemsg+msg2;
        msg = query("long")+msg2;
        this_player()->start_more( msg );
        return 1;

}

// This is the callback function to process the string returned from the
// editor defined in F_EDIT of player object.
void done_post(object me, mapping note, string text)
{
        mapping *notes;

	if( text == "" )
		note["msg"] = BLU+string_m("������", 70, "m")+NOR;
       	else note["msg"] = set_color(text,0);

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

        save();
        return;
}

void done_re(object me, mapping report, int project, string text)
{
	mapping *notes, *reports, noteold;
	
	if( text == "" )
		report["msg"] = BLU+string_m("������", 70, "m")+NOR;
       	else report["msg"]=set_color(text,0);

	notes = query("notes");
	reports = notes[project]["re"];
	if( !pointerp(reports) ) reports = ({ report });
	else reports += ({ report });

	notes[project]["re"] = reports;
/*	notes[project]["time"] = time();
	noteold = notes[project];
	notes = notes[0..project-1] + notes[project+1..sizeof(notes)-1] + ({ noteold });*/

	set("notes", notes);
	tell_object(me, HIW"�ظ�������ϡ�\n"NOR);

	save();
	return;
}

int do_post(string arg)
{
        int i, j=0;
        mapping note;
        string poster_lvl, family, att, re_s, title;
        object the_player;
        mapping fam;

        the_player = this_player();     
        poster_lvl = query("poster_level");
        if(!stringp(poster_lvl))
                poster_lvl = "(player)";

        for(i=0; i<sizeof(query("notes")); i++){
                if (the_player->name()+"("+the_player->query("id")+")" == query("notes")[i]["author"]) 
                j++;}

        if ( (int)SECURITY_D->cmp_wiz_level(the_player, poster_lvl ) < 0 )
                return notify_fail("���岻�������Ͷ�塣\n");

        family = query("poster_family");
        fam = the_player->query("family");

        if ( stringp(family)
                && (int)SECURITY_D->cmp_wiz_level(the_player, "(immortal)" ) < 0
                && ( !mapp( fam ) || fam["family_name"] != family ) )
                return notify_fail("�Ǳ��ɵ��Ӳ����򱾰���Ϳ��д��\n");

	if( !arg ) return notify_fail("����ʱ��ָ��һ�����⡣\n");

	if ( arg && sscanf(arg, "%s -%s", title, re_s) != 2 )
		title = arg;

  	if (q_long(set_color(title,1))>MAX_TITLE_LEN)
		return notify_fail("�������̫���ˣ��뻻һ�����һ��ġ�\n");      

        note = allocate_mapping(8);
	if ( stringp(re_s) ){
		if( re_s == "n" || re_s == "N" ){
			tell_object(the_player, "��ƪ��������˲���ظ���\n");
			note["attrib"] = "NN";
		}else if( (re_s == "r" || re_s == "R") && wizardp(the_player) ){
			tell_object(the_player, "��ƪ��������˲����٣����߽����ᱻ��¼������\n");
			note["attrib"] = "RN";
		}else if( (re_s == "nr" || re_s == "NR" || re_s == "nR" || re_s == "Nr") && wizardp(the_player) ){
			tell_object(the_player, "��ƪ��������˸������ò���ֹ�ظ���\n");
			note["attrib"] = "NR";
			note["reader"] = "";
		}else if( (re_s == "a" || re_s == "A") && wizardp(the_player) ){
			tell_object(the_player, "��ƪ�����������ظ����������ã����߽��ᱻ��¼������\n");
			note["attrib"] = "RR";
			note["reader"] = "";
		}else{
			note["attrib"] = "RN";
		 	title = arg;
		}
	}else{
		note["attrib"] = "RR";
		note["reader"] = "";
	}
	note["title"] = set_color(title,1);
	if(stringp(the_player->query("sign")))
		note["sign"] = the_player->query("sign");
        note["author"] = the_player->name()+"("+the_player->query("id")+")";
        note["read_cnt"] = 0;
        the_player->edit( (: done_post, the_player, note :) );
        return 1;
}

int do_repost(string arg)
{
	int num;
	string title;
        string poster_lvl, family;
	mapping note, *notes, fam;
	object poster=this_player();
        poster_lvl = query("poster_level");
        if ( (int)SECURITY_D->cmp_wiz_level(poster, poster_lvl ) < 0 )
                return notify_fail("���岻�������Ͷ�塣\n");

        family = query("poster_family");
        fam = poster->query("family");

        if ( stringp(family)
                && (int)SECURITY_D->cmp_wiz_level(poster, "(immortal)" ) < 0
                && ( !mapp( fam ) || fam["family_name"] != family ) )
                return notify_fail("�Ǳ��ɵ��Ӳ����򱾰���Ϳ��д��\n");

	if(!arg || sscanf(arg, "%d.%s", num, title)<1)
		return notify_fail("ָ���ʽ��re <���Ա��>.<�ظ�����>\n");

	notes = query("notes");

	if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
		return notify_fail("û��������ԡ�\n");

        if ( stringp(notes[num-1]["attrib"]) && notes[num-1]["attrib"][0..0] == "N")
                return notify_fail("��ƪ���Բ�����ظ���\n");

	if (strlen(title)>MAX_TITLE_LEN)
		return notify_fail("�������̫���ˣ��뻻һ�����һ��ġ�\n");

	if (!title) title="Re: "+notes[num-1]["title"];

	note = allocate_mapping(6);
	if(stringp(poster->query("sign")))
		note["sign"] = poster->query("sign");
	note["title"] = title;
	note["author"] = poster->name()+"("+poster->query("id")+")";
	note["time"] = time();
        note["read_cnt"] = 0;
	poster->edit( (: done_re, poster, note, num-1 :) );
	return 1;
}

int do_read(string arg)
{
        int num, arc, rep, cnt, cnt_r, ren, rex = 0;
        mapping *notes, last_read_time;
        string myid;
        object the_player;
        string family, reader = "", *read_list;
        mapping fam;

        the_player = this_player();     

        last_read_time = the_player->query("board_last_read");
        myid = query("board_id");
        notes = query("notes");
        arc = query("wizard_only");
        if ( arc
                && (int)SECURITY_D->cmp_wiz_level(the_player, "(immortal)" ) < 0)
                return notify_fail("�ڲ�ͨѶ���ÿ��ӡ�\n");

        if( !pointerp(notes) || !sizeof(notes) )
                return notify_fail("���԰���Ŀǰû���κ����ԡ�\n");

        family = query("poster_family");
        fam = the_player->query("family");

        if ( stringp(family)
                && (int)SECURITY_D->cmp_wiz_level(the_player, "(immortal)" ) < 0
                && ( !mapp( fam ) || fam["family_name"] != family ) )
                return notify_fail("�Ǳ��ɵ��Ӳ��ÿ��ӱ����ڲ�ͨѶ��\n");

	if( !arg ) return notify_fail("ָ���ʽ��read <���Ա��>[.<�ظ����>]|new|next\n");
	tell_object(the_player,HIG"arg == "+ arg+".\n"NOR);
        if( arg=="new" || arg=="next" ) {
                if( !mapp(last_read_time) || undefinedp(last_read_time[myid]) )
                        num = 1;
                else {
                        for(num = 1; num<=sizeof(notes); num++){
				if ( sizeof(notes[num-1]["re"]) >= 1 && !the_player->query("env/no_auto_read") )
		                        for(ren = 1; ren<=sizeof(notes[num-1]["re"]); ren++)
                                		if( notes[num-1]["re"][ren-1]["time"] > last_read_time[myid+"_r"] )
                                			return do_read(num+"."+ren);
                                if( notes[num-1]["time"] > last_read_time[myid] ) break;
			}
                }
        } else if( sscanf(arg, "%d.%d", num, rep)==2 ) {
		if( num < 1 || num > sizeof(notes) ) return notify_fail("û��������ԡ�\n");
			else num--;
		if( rep < 1 || rep > sizeof(notes[num]["re"]) ) return notify_fail("û������ظ���\n");
			else rep --;
		the_player->start_more( sprintf(
		"[ ��ţ�"NOR"%2d | �ظ���ţ�"NOR"%2d]\n"WHT"ԭ�⣺"NOR"%s  \n"WHT"�ظ����⣺"NOR"%s \n%s\n�ԩ�������������������������������������������������������������������\n",
			num + 1, rep + 1,
			notes[num]["author"]+"д�ġ�"+notes[num]["title"],
			notes[num]["re"][rep]["title"],
			string_m(notes[num]["re"][rep]["author"]+"�ظ���"+ctime(notes[num]["re"][rep]["time"]),70, "m"))
			+ notes[num]["re"][rep]["msg"] +(notes[num]["re"][rep]["sign"] ? "\n\n"+string_m(notes[num]["re"][rep]["sign"],70, "m") :"")
	                +((notes[num]["re"][rep]["read_cnt"]>=1 && wizardp(the_player)) ? string_m(HIM"\n�˸干��"+ints(notes[num]["re"][rep]["read_cnt"], 3)+"�������\n"NOR, 70, "m"):"")
			+"\n�ԩ������������������� "WHT"�ظ�ԭ��"NOR" �������������������� "HIG"����"NOR" ������������\n");

	        if( !mapp(last_read_time) ){
	                the_player->set("board_last_read", ([ myid+"_r": notes[num]["re"][rep]["time"] ]) );
			if(!notes[num]["re"][rep]["read_cnt"]) notes[num]["re"][rep]["read_cnt"] = 1;
			else notes[num]["re"][rep]["read_cnt"]++;
	        }else 
	                if( undefinedp(last_read_time[myid+"_r"]) || notes[num]["re"][rep]["time"] > last_read_time[myid+"_r"] ){
				if ( notes[num]["re"][rep]["time"] )
	                        	last_read_time[myid+"_r"] = notes[num]["re"][rep]["time"];
				else last_read_time[myid+"_r"] = notes[num]["time"];
				if(!notes[num]["re"][rep]["read_cnt"]) notes[num]["re"][rep]["read_cnt"] = 1;
				else notes[num]["re"][rep]["read_cnt"]++;
			}
		return 1;
	} else if( !sscanf(arg, "%d", num) )
                return notify_fail("��Ҫ���ڼ������ԣ�\n");

        if( num < 1 || num > sizeof(notes) )
                return notify_fail("û���������ԡ�\n");
        num--;
	if (notes[num]["attrib"] && notes[num]["attrib"][1..1] == "R"){
		if (stringp(notes[num]["reader"]))
			read_list = explode( notes[num]["reader"], "\$" );
		else{
			read_list = ({});
			notes[num]["reader"] = "";
		}
		if( sizeof(read_list) >= 1){
			cnt = 0;
			cnt_r = 0;
			for(int i=0;i<sizeof(read_list);i++)
			{
				if (read_list[i] == getuid(the_player))
				cnt_r++;
                                reader = sprintf("%s%10s%s", reader, string_m(read_list[i], 10, "m"), (cnt%6==5? " \n": (i + 1 == sizeof(read_list)?"":"��")));
				cnt++;
			}
			if (cnt_r == 0 && wizardp(the_player)) notes[num]["reader"] += getuid(the_player)+"$";
		}else{
			if (wizardp(the_player)) notes[num]["reader"] += getuid(the_player)+"$";
		}
	}
        the_player->start_more( sprintf(
"[%d] %s \n%s\n�ԩ�������������������������������������������������������������������\n",
                num + 1, notes[num]["title"], string_m(notes[num]["author"]+"д��"+ctime(notes[num]["time"]),70,"m"))
                + notes[num]["msg"] +(notes[num]["sign"] ? "\n\n"+string_m(notes[num]["sign"]+"\n",70,"m") :"")
                +((sizeof(notes[num]["re"])>0)?"\n"+string_m(HIG"��ƪ���лظ�"HIC+chinese_number(sizeof(notes[num]["re"]))+HIG"�ݡ�\n"NOR,70,"m"):"")
                +(( cnt > 0  && wizardp(the_player)) ? "\n�ԩ�������������������������������������������������������������������\n"+"Ŀǰ����"+chinese_number(cnt)+"���Ķ���ƪ���ԣ��������£�\n"+reader:"")
                +((notes[num]["read_cnt"]>=1 && wizardp(the_player)) ? string_m(HIM"\n�˸干��"+ints(notes[num]["read_cnt"], 3)+"�������\n"NOR, 70, "m"):"")
                +"\n�ԩ����������������� "WHT"ԭ��"NOR" �������������������������������� "HIG"����"NOR" ������\n");
        // Keep track which post we were reading last time.
        if( !mapp(last_read_time) ){
                the_player->set("board_last_read", ([ myid: notes[num]["time"] ]) );
		if(!notes[num]["read_cnt"]) notes[num]["read_cnt"] = 1;
		else notes[num]["read_cnt"]++;
        }else 
                if( undefinedp(last_read_time[myid]) || notes[num]["time"] > last_read_time[myid] ){
                        last_read_time[myid] = notes[num]["time"];
			if(!notes[num]["read_cnt"]) notes[num]["read_cnt"] = 1;
			else notes[num]["read_cnt"]++;
		}
	save();
        return 1;
}

/*
int do_discard(string arg)
{
        mapping *notes;
        int num;

        if( !arg || sscanf(arg, "%d", num)!=1 )
                return notify_fail("ָ���ʽ��discard <���Ա��>\n");
        notes = query("notes");
        if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
                return notify_fail("û���������ԡ�\n");
        num--;
        if( notes[num]["author"] != (string)this_player(1)->name()+"("+this_player(1)->query("id")+")"
        &&  ( (int)SECURITY_D->cmp_wiz_level(this_player(), "(caretaker)") < 0 ) )
                return notify_fail("������Բ�����д�ġ�\n");

        notes = notes[0..num-1] + notes[num+1..sizeof(notes)-1];
        set("notes", notes);
        save();
        write("ɾ���� " + (num+1) + " ������....Ok��\n");
        return 1;
}*/
int do_discard(string arg)
{
	mapping *notes;
	int num,re_num;

	if(!arg ||sscanf(arg, "%d.%d",num,re_num)<1)
		return notify_fail("ָ���ʽ��delete <���Ա��>[.<�ظ����>]\n");
	notes = query("notes");
	if( !arrayp(notes)|| num <1 || num > sizeof(notes))
		return notify_fail("û���������ԡ�\n");
	else if(re_num) {
		if (re_num<1||!arrayp(notes[num-1]["re"])||re_num > sizeof(notes[num-1]["re"]))
			return notify_fail("û�����Żظ���\n");
		else {
			num--;
			re_num--;
		        if( notes[num]["re"][re_num]["author"] != (string)this_player(1)->name()+"("+this_player(1)->query("id")+")"
			&& query("banzhu")!=this_player()->query("id")
		        && ((int)SECURITY_D->cmp_wiz_level(this_player(), "(caretaker)") < 0 ))
		                return notify_fail("������Բ�����д�ģ���Ҳ���ǰ������㲻�����޸ġ�\n");
			else {
				notes[num]["re"]=notes[num]["re"][0..re_num-1] + notes[num]["re"][re_num+1..sizeof(notes[num]["re"])-1];
				set("notes", notes);
				save();
				write("ɾ���� " + (num+1) + " �����Եĵ� "+ (re_num+1)+" �Żظ�....Ok��\n");
				return 1;
			}
		}
	}
	else {
		num--;
	        if( notes[num]["author"] != (string)this_player(1)->name()+"("+this_player(1)->query("id")+")"
		&& query("banzhu")!=this_player()->query("id")
	        && ((int)SECURITY_D->cmp_wiz_level(this_player(), "(caretaker)") < 0 ))
	                return notify_fail("������Բ�����д�ģ���Ҳ���ǰ������㲻�����޸ġ�\n");

		notes = notes[0..num-1] + notes[num+1..sizeof(notes)-1];
		set("notes", notes);
		save();
		write("ɾ���� " + (num+1) + " ������....Ok��\n");
		return 1;
	}
}

int do_store(string arg)
{
        int num, numb;
        mapping *notes, last_read_time;
        string myid, fmonth, fyear, filename;
        int arc;
        object me=this_player();
        
        arc = query("wizard_only");
        seteuid(getuid()); /* yzc */

        last_read_time = this_player()->query("board_last_read");
        myid = query("board_id");
        notes = query("notes");

        if( !pointerp(notes) || !sizeof(notes) )
                return notify_fail("���԰���Ŀǰû���κ����ԡ�\n");

        if( !arg ) return notify_fail("ָ���ʽ��store <���Ա��>\n");

        if( !sscanf(arg, "%d", num) )
                return notify_fail("��Ҫ�ձ�ڼ������ԣ�\n");

        if( num < 1 || num > sizeof(notes) )
                return notify_fail("û���������ԡ�\n");
        num--;
        if( notes[num]["stored"] ) 
                return notify_fail("���������Ѿ�����¼�ˡ�\n��¼��ʾ��"+notes[num]["stored"]+"\n");

        fyear  = ctime(notes[num]["time"])[20..23];
        fmonth = ctime(notes[num]["time"])[4..6];
	
        numb = EDITOR_D->get_file_num(arc, fyear, fmonth) + 1;

        filename = sprintf("%s/%s/%03d", fyear, fmonth, numb);  

        if (arc)
        write( "ARC: writing ..." + filename + "\n" );
        else
        write( "WEN: writing ..." + filename + "\n" );
        
        EDITOR_D->add(arc, "�����������������������������������ݡ���ѡ��"+
                "����������������������������", filename);
        EDITOR_D->add(arc, sprintf("��%03d  %-40s  %12s(%s)",
                numb, notes[num]["title"],
                notes[num]["author"],
                ctime(notes[num]["time"])[0..9]), filename );
        EDITOR_D->add(arc, notes[num]["msg"], filename);
        EDITOR_D->add(arc, "����ƪ���", filename);

/* index */
        filename = sprintf("%s/wenxuan.%s", fyear, fmonth);     

        if (arc)
        write( "ARC: writing ..." + filename + "\n" );
        else
        write( "WEN: writing ..." + filename + "\n" );

        if ( numb == 1)
        {
EDITOR_D->add(arc,
"������������������������������������������������������������������������\n" +
"                    ��������ѡ" + fyear +"��� " + fmonth + " ��Ŀ¼��\n" +
"���   ��Ŀ                                              ����(��������)\n"+
"������������������������������������������������������������������������",
        filename);
        }

        if (EDITOR_D->add(arc, sprintf("��%03d  %-40s  %12s(%s)",
                numb, notes[num]["title"],
                notes[num]["author"],
                ctime(notes[num]["time"])[0..9]), filename )) {
                write( notes[num]["stored"] = sprintf("�������ݡ���ѡ���� %d ƪ���� %s ���� %03d ƪ��\n",
                        num+1, fmonth, numb) );
                log_file("wenxuan",sprintf("%s%s(%s)���롾�����ݡ���ѡ���� %d ƪ���� %s ���� %03d ƪ��\n",
                        ctime(time()),me->query("name"),me->query("id"),num+1, fmonth, numb) );
                set("notes", notes);
        } else
                write( sprintf("�������ݡ���ѡ���� %d ƪ�ձ�ʧ�ܡ�\n", num+1) );

        return 1;
}

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
        msg = replace_string(msg, "─", "--");
        msg = replace_string(msg, "------- 原稿 -------", HIG" 此稿引自其他留言板 "NOR);

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
	if (!arg) return notify_fail("指令格式： banzhu <版主id>\n");
	if (!stringp(arg)||strlen(arg)<3) return notify_fail("没有这个人。\n");
	if (query("banzhu")==arg) return notify_fail("目前的版主就是 "+arg+"，不需要设置。\n");
	if (SECURITY_D->get_status(this_player(1)) != "(admin)") return notify_fail("你不是天神，不可以设置版主。\n");
	set("banzhu",arg);
	save();
	write("设置 "HIW+arg+NOR" 为"+name()+"版主成功。\n");
	return 1;
}
string short()
{
        mapping *notes;
        int i, unread = 0, last_read_time, last_time_read_re, j, unreadre = 0;

        notes = query("notes");
        if( !pointerp(notes) || !sizeof(notes) )
                return ::short() + " [ 没有任何留言 ]";

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
                	return sprintf("%s [ %d 张留言，%d 张未读，%d 篇回复未读 ]", ::short(), sizeof(notes), unread, unreadre);
                else return sprintf("%s [ %d 张留言，%d 张未读 ]", ::short(), sizeof(notes), unread);
        else if( unreadre && !unread )
                return sprintf("%s [ %d 张留言，%d 篇回复未读 ]", ::short(), sizeof(notes), unreadre);
        else
                return sprintf("%s [ %d 张留言 ]", ::short(), sizeof(notes));
}

string long()
{
        mapping *notes;
        int i, last_time_read;
        string msg, myid;

        notes = query("notes");
        msg = query("long");
        msg = msg + (query("banzhu")?("这个版的的版主是 "WHT+query("banzhu")+NOR"。\n"):"")+query("name") +"的使用方法请见 help board。\n";
        return msg;
}

int do_list( string arg )
{
        mapping *notes;
        int i, last_time_read, last_time_read_re, cnt = 0, last, j;
        string msg, mode, myid, name, id, msg2 = "", re_msg;
	string titlemsg = HIG" 编号 "NOR CYN"─────[　"HIG"留　言　标　题"NOR CYN"　]─────┤"HIG"RE"NOR CYN"├──["HIG" 作　者 "NOR CYN"]────["HIG" 留言时间 "NOR CYN"]──\n"NOR;
        notes = query("notes");
	if( !arg || arg == "") mode = "None";
	else if( sscanf( arg, "name:%s", name) == 1 || sscanf( arg, "Name:%s", name) == 1 ) mode = "Name";
	else if( sscanf( arg, "ID:%s", id) == 1 ||  sscanf( arg, "id:%s", id) == 1 ) mode = "ID";
	else if( sscanf( arg, "last:%d", last) == 1 ||  sscanf( arg, "Last:%d", last) == 1 ) mode = "Last";
	else if( arg == "Noread" || arg == "noread" ) mode = "Noread";
	else return notify_fail("请使用正常的参数进行查询。\n");

        if( !pointerp(notes) || !sizeof(notes) ) 
                return notify_fail(msg+query("name")+"上目前没有任何留言。\n");
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
                        (notes[i]["attrib"] && notes[i]["attrib"][0..0] == "N")?string_m(HIR"禁"NOR, 4, "m"):((sizeof(notes[i]["re"]) >= 1)?string_m(re_msg+ints(sizeof(notes[i]["re"]), 2)+NOR, 4, "m"):string_m(HIG"无"NOR, 4, "m")),
                        string_m(notes[i]["author"], 18, "m"), ctime(notes[i]["time"])[0..15] );
		cnt++;
	}
	if ( mode == "ID" )
		if ( cnt == 0 ) msg2 = query("name")+"上现在没有 "+id+" 的留言。";
		else msg2 = query("name")+"上现有 "+chinese_number(cnt)+" 条 "+id+" 的留言：\n"+titlemsg+msg2;
	else if ( mode == "Name" )
		if ( cnt == 0 ) msg2 = query("name")+"上现在没有 "+name+" 的留言。";
		else msg2 = query("name")+"上现有 "+chinese_number(cnt)+" 条 "+name+" 的留言：\n"+titlemsg+msg2;
	else if ( mode == "Last" )
		if ( cnt == 0 ) msg2 = query("name")+"上没有你要找的留言。";
		else msg2 = query("name")+"上后 "+chinese_number(cnt)+" 条留言如下：\n"+titlemsg+msg2;
	else if ( mode == "Noread" )
		if ( cnt == 0 ) msg2 = query("name")+"上的留言你已经全部读过了。";
		else msg2 = query("name")+"上现有 "+chinese_number(cnt)+" 条留言你未曾读过：\n"+titlemsg+msg2;
	else msg2 = query("name")+"上现有下列留言（一共有"+chinese_number(cnt)+"条）：\n"+titlemsg+msg2;
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
		note["msg"] = BLU+string_m("无内容", 70, "m")+NOR;
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
        tell_object(me, "留言完毕。\n");

        save();
        return;
}

void done_re(object me, mapping report, int project, string text)
{
	mapping *notes, *reports, noteold;
	
	if( text == "" )
		report["msg"] = BLU+string_m("无内容", 70, "m")+NOR;
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
	tell_object(me, HIW"回复留言完毕。\n"NOR);

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
                return notify_fail("本板不接受你的投稿。\n");

        family = query("poster_family");
        fam = the_player->query("family");

        if ( stringp(family)
                && (int)SECURITY_D->cmp_wiz_level(the_player, "(immortal)" ) < 0
                && ( !mapp( fam ) || fam["family_name"] != family ) )
                return notify_fail("非本派弟子不得向本板乱涂乱写。\n");

	if( !arg ) return notify_fail("留言时请指定一个标题。\n");

	if ( arg && sscanf(arg, "%s -%s", title, re_s) != 2 )
		title = arg;

  	if (q_long(set_color(title,1))>MAX_TITLE_LEN)
		return notify_fail("这个标题太长了，请换一个简洁一点的。\n");      

        note = allocate_mapping(8);
	if ( stringp(re_s) ){
		if( re_s == "n" || re_s == "N" ){
			tell_object(the_player, "此篇文章设成了不许回复。\n");
			note["attrib"] = "NN";
		}else if( (re_s == "r" || re_s == "R") && wizardp(the_player) ){
			tell_object(the_player, "此篇文章设成了不跟踪，读者将不会被记录下来。\n");
			note["attrib"] = "RN";
		}else if( (re_s == "nr" || re_s == "NR" || re_s == "nR" || re_s == "Nr") && wizardp(the_player) ){
			tell_object(the_player, "此篇文章设成了跟踪设置并禁止回复。\n");
			note["attrib"] = "NR";
			note["reader"] = "";
		}else if( (re_s == "a" || re_s == "A") && wizardp(the_player) ){
			tell_object(the_player, "此篇文章设成允许回复及跟踪设置，读者将会被记录下来。\n");
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
                return notify_fail("本板不接受你的投稿。\n");

        family = query("poster_family");
        fam = poster->query("family");

        if ( stringp(family)
                && (int)SECURITY_D->cmp_wiz_level(poster, "(immortal)" ) < 0
                && ( !mapp( fam ) || fam["family_name"] != family ) )
                return notify_fail("非本派弟子不得向本板乱涂乱写。\n");

	if(!arg || sscanf(arg, "%d.%s", num, title)<1)
		return notify_fail("指令格式：re <留言编号>.<回复标题>\n");

	notes = query("notes");

	if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
		return notify_fail("没有这个留言。\n");

        if ( stringp(notes[num-1]["attrib"]) && notes[num-1]["attrib"][0..0] == "N")
                return notify_fail("此篇留言不允许回复。\n");

	if (strlen(title)>MAX_TITLE_LEN)
		return notify_fail("这个标题太长了，请换一个简洁一点的。\n");

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
                return notify_fail("内部通讯不得窥视。\n");

        if( !pointerp(notes) || !sizeof(notes) )
                return notify_fail("留言板上目前没有任何留言。\n");

        family = query("poster_family");
        fam = the_player->query("family");

        if ( stringp(family)
                && (int)SECURITY_D->cmp_wiz_level(the_player, "(immortal)" ) < 0
                && ( !mapp( fam ) || fam["family_name"] != family ) )
                return notify_fail("非本派弟子不得窥视本派内部通讯。\n");

	if( !arg ) return notify_fail("指令格式：read <留言编号>[.<回复编号>]|new|next\n");
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
		if( num < 1 || num > sizeof(notes) ) return notify_fail("没有这个留言。\n");
			else num--;
		if( rep < 1 || rep > sizeof(notes[num]["re"]) ) return notify_fail("没有这个回复。\n");
			else rep --;
		the_player->start_more( sprintf(
		"[ 编号："NOR"%2d | 回复编号："NOR"%2d]\n"WHT"原题："NOR"%s  \n"WHT"回复标题："NOR"%s \n%s\n≡─────────────────────────────────≡\n",
			num + 1, rep + 1,
			notes[num]["author"]+"写的　"+notes[num]["title"],
			notes[num]["re"][rep]["title"],
			string_m(notes[num]["re"][rep]["author"]+"回复于"+ctime(notes[num]["re"][rep]["time"]),70, "m"))
			+ notes[num]["re"][rep]["msg"] +(notes[num]["re"][rep]["sign"] ? "\n\n"+string_m(notes[num]["re"][rep]["sign"],70, "m") :"")
	                +((notes[num]["re"][rep]["read_cnt"]>=1 && wizardp(the_player)) ? string_m(HIM"\n此稿共有"+ints(notes[num]["re"][rep]["read_cnt"], 3)+"人浏览。\n"NOR, 70, "m"):"")
			+"\n≡────────── "WHT"回复原稿"NOR" ────────── "HIG"神州"NOR" ─────≡\n");

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
                return notify_fail("你要读第几张留言？\n");

        if( num < 1 || num > sizeof(notes) )
                return notify_fail("没有这张留言。\n");
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
                                reader = sprintf("%s%10s%s", reader, string_m(read_list[i], 10, "m"), (cnt%6==5? " \n": (i + 1 == sizeof(read_list)?"":"、")));
				cnt++;
			}
			if (cnt_r == 0 && wizardp(the_player)) notes[num]["reader"] += getuid(the_player)+"$";
		}else{
			if (wizardp(the_player)) notes[num]["reader"] += getuid(the_player)+"$";
		}
	}
        the_player->start_more( sprintf(
"[%d] %s \n%s\n≡─────────────────────────────────≡\n",
                num + 1, notes[num]["title"], string_m(notes[num]["author"]+"写于"+ctime(notes[num]["time"]),70,"m"))
                + notes[num]["msg"] +(notes[num]["sign"] ? "\n\n"+string_m(notes[num]["sign"]+"\n",70,"m") :"")
                +((sizeof(notes[num]["re"])>0)?"\n"+string_m(HIG"本篇共有回复"HIC+chinese_number(sizeof(notes[num]["re"]))+HIG"份。\n"NOR,70,"m"):"")
                +(( cnt > 0  && wizardp(the_player)) ? "\n≡─────────────────────────────────≡\n"+"目前共有"+chinese_number(cnt)+"人阅读本篇留言，名单如下：\n"+reader:"")
                +((notes[num]["read_cnt"]>=1 && wizardp(the_player)) ? string_m(HIM"\n此稿共有"+ints(notes[num]["read_cnt"], 3)+"人浏览。\n"NOR, 70, "m"):"")
                +"\n≡───────── "WHT"原稿"NOR" ──────────────── "HIG"神州"NOR" ──≡\n");
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
                return notify_fail("指令格式：discard <留言编号>\n");
        notes = query("notes");
        if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
                return notify_fail("没有这张留言。\n");
        num--;
        if( notes[num]["author"] != (string)this_player(1)->name()+"("+this_player(1)->query("id")+")"
        &&  ( (int)SECURITY_D->cmp_wiz_level(this_player(), "(caretaker)") < 0 ) )
                return notify_fail("这个留言不是你写的。\n");

        notes = notes[0..num-1] + notes[num+1..sizeof(notes)-1];
        set("notes", notes);
        save();
        write("删除第 " + (num+1) + " 号留言....Ok。\n");
        return 1;
}*/
int do_discard(string arg)
{
	mapping *notes;
	int num,re_num;

	if(!arg ||sscanf(arg, "%d.%d",num,re_num)<1)
		return notify_fail("指令格式：delete <留言编号>[.<回复编号>]\n");
	notes = query("notes");
	if( !arrayp(notes)|| num <1 || num > sizeof(notes))
		return notify_fail("没有这张留言。\n");
	else if(re_num) {
		if (re_num<1||!arrayp(notes[num-1]["re"])||re_num > sizeof(notes[num-1]["re"]))
			return notify_fail("没有这张回复。\n");
		else {
			num--;
			re_num--;
		        if( notes[num]["re"][re_num]["author"] != (string)this_player(1)->name()+"("+this_player(1)->query("id")+")"
			&& query("banzhu")!=this_player()->query("id")
		        && ((int)SECURITY_D->cmp_wiz_level(this_player(), "(caretaker)") < 0 ))
		                return notify_fail("这个留言不是你写的，你也不是版主，你不进行修改。\n");
			else {
				notes[num]["re"]=notes[num]["re"][0..re_num-1] + notes[num]["re"][re_num+1..sizeof(notes[num]["re"])-1];
				set("notes", notes);
				save();
				write("删除第 " + (num+1) + " 号留言的第 "+ (re_num+1)+" 号回复....Ok。\n");
				return 1;
			}
		}
	}
	else {
		num--;
	        if( notes[num]["author"] != (string)this_player(1)->name()+"("+this_player(1)->query("id")+")"
		&& query("banzhu")!=this_player()->query("id")
	        && ((int)SECURITY_D->cmp_wiz_level(this_player(), "(caretaker)") < 0 ))
	                return notify_fail("这个留言不是你写的，你也不是版主，你不进行修改。\n");

		notes = notes[0..num-1] + notes[num+1..sizeof(notes)-1];
		set("notes", notes);
		save();
		write("删除第 " + (num+1) + " 号留言....Ok。\n");
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
                return notify_fail("留言板上目前没有任何留言。\n");

        if( !arg ) return notify_fail("指令格式：store <留言编号>\n");

        if( !sscanf(arg, "%d", num) )
                return notify_fail("你要收编第几张留言？\n");

        if( num < 1 || num > sizeof(notes) )
                return notify_fail("没有这张留言。\n");
        num--;
        if( notes[num]["stored"] ) 
                return notify_fail("这张留言已经被收录了。\n记录显示："+notes[num]["stored"]+"\n");

        fyear  = ctime(notes[num]["time"])[20..23];
        fmonth = ctime(notes[num]["time"])[4..6];
	
        numb = EDITOR_D->get_file_num(arc, fyear, fmonth) + 1;

        filename = sprintf("%s/%s/%03d", fyear, fmonth, numb);  

        if (arc)
        write( "ARC: writing ..." + filename + "\n" );
        else
        write( "WEN: writing ..." + filename + "\n" );
        
        EDITOR_D->add(arc, "※※※※※※※※※※※※※※【“神州”文选】"+
                "※※※※※※※※※※※※※※", filename);
        EDITOR_D->add(arc, sprintf("□%03d  %-40s  %12s(%s)",
                numb, notes[num]["title"],
                notes[num]["author"],
                ctime(notes[num]["time"])[0..9]), filename );
        EDITOR_D->add(arc, notes[num]["msg"], filename);
        EDITOR_D->add(arc, "□本篇完□", filename);

/* index */
        filename = sprintf("%s/wenxuan.%s", fyear, fmonth);     

        if (arc)
        write( "ARC: writing ..." + filename + "\n" );
        else
        write( "WEN: writing ..." + filename + "\n" );

        if ( numb == 1)
        {
EDITOR_D->add(arc,
"※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n" +
"                    【神州文选" + fyear +"年第 " + fmonth + " 卷目录】\n" +
"编号   题目                                              作者(发稿日期)\n"+
"※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※",
        filename);
        }

        if (EDITOR_D->add(arc, sprintf("□%03d  %-40s  %12s(%s)",
                numb, notes[num]["title"],
                notes[num]["author"],
                ctime(notes[num]["time"])[0..9]), filename )) {
                write( notes[num]["stored"] = sprintf("【“神州”文选】第 %d 篇收入 %s 卷，第 %03d 篇。\n",
                        num+1, fmonth, numb) );
                log_file("wenxuan",sprintf("%s%s(%s)收入【“神州”文选】第 %d 篇收入 %s 卷，第 %03d 篇。\n",
                        ctime(time()),me->query("name"),me->query("id"),num+1, fmonth, numb) );
                set("notes", notes);
        } else
                write( sprintf("【“神州”文选】第 %d 篇收编失败。\n", num+1) );

        return 1;
}

// Code of ShenZhou
// bboard.c

#include <ansi.h>

#define BOARD_CAPACITY query("capacity")

inherit ITEM;
inherit F_SAVE;

void tune_channels();
void open_channels();
string set_color(string msg){
        msg = replace_string(msg, "$BLK$", BLK);
        msg = replace_string(msg, "$RED$", RED);
        msg = replace_string(msg, "$GRN$", GRN);
        msg = replace_string(msg, "$YEL$", YEL);
        msg = replace_string(msg, "$BLU$", BLU);
        msg = replace_string(msg, "$MAG$", MAG);
        msg = replace_string(msg, "$CYN$", CYN);
        msg = replace_string(msg, "$WHT$", WHT);
        msg = replace_string(msg, "$HIR$", HIR);
        msg = replace_string(msg, "$HIG$", HIG);
        msg = replace_string(msg, "$HIY$", HIY);
        msg = replace_string(msg, "$HIB$", HIB);
        msg = replace_string(msg, "$HIM$", HIM);
        msg = replace_string(msg, "$HIC$", HIC);
        msg = replace_string(msg, "$HIW$", HIW);
        msg = replace_string(msg, "$NOR$", NOR);
	return msg;
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
}

string query_save_file()
{
        string id;

        if( !stringp(id = query("board_id")) ) return 0;
        return DATA_DIR + "board/" + id;
}

string short()
{
        mapping *notes;
        int i, unread, last_read_time;

        notes = query("notes");
        if( !pointerp(notes) || !sizeof(notes) )
                return ::short() + " [ û???κ????? ]";

        if( this_player() ) {
                last_read_time = (int)this_player()->query("board_last_read/" + (string)query("board_id"));
                for(unread = 0, i=sizeof(notes)-1; i>=0; i--, unread ++)
                        if( notes[i]["time"] <= last_read_time ) break;
        }
        if( unread )
                return sprintf("%s [ %d ?????ԣ?%d ??δ?? ]", ::short(), sizeof(notes), unread);
        else
                return sprintf("%s [ %d ?????? ]", ::short(), sizeof(notes));
}

string long()
{
        mapping *notes;
        int i, last_time_read;
        string msg, myid;

        notes = query("notes");
        msg = query("long");
        msg = msg + query("name") +"??ʹ?÷??????? help board??\n";
        return msg;
}

int do_list()
{
        mapping *notes;
        int i, last_time_read;
        string msg, myid;

        notes = query("notes");
        msg = query("long");

        if( !pointerp(notes) || !sizeof(notes) ) 
                return notify_fail(msg+query("name")+"??Ŀǰû???κ????ԡ?\n");
        msg += query("name")+"?????????????ԣ?\n????????????????????????????????????????????????\n";
        last_time_read = this_player()->query("board_last_read/" + (string)query("board_id"));
        for(i=0; i<sizeof(notes); i++)
                msg += sprintf("%s[%2d]" NOR "  %-40s %12s (%s)\n",
                        ( notes[i]["time"] > last_time_read ? HIY: ""),
                        i+1, notes[i]["title"], notes[i]["author"], ctime(notes[i]["time"])[0..15] );
        this_player()->start_more( msg );
        return 1;

}

// This is the callback function to process the string returned from the
// editor defined in F_EDIT of player object.
void done_post(object me, mapping note, string text)
{
        mapping *notes;

        note["msg"] = set_color(text);
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
        tell_object(me, "???????ϡ?\n");

        open_channels();
        save();
        return;
}

int do_post(string arg)
{
        int i, j=0;
        mapping note;
        string poster_lvl, family;
        object the_player;
        mapping fam;

        the_player = this_player();     
        poster_lvl = query("poster_level");
        
        if(!stringp(poster_lvl))
                poster_lvl = "(player)";

        for(i=0; i<sizeof(query("notes")); i++){
                if (the_player->name()+"("+the_player->query("id")+")" == query("notes")[i]["author"]) 
                j++;}

//        if(j>=10 && !wizardp(the_player)) return notify_fail("?Բ??????????????ѳ???ʮƪ????ɾ??ǰ??????POST?µġ?\n");^M

//      write("Board Restricted to " + poster_lvl + " and above.\n");

        if ( (int)SECURITY_D->cmp_wiz_level(the_player, poster_lvl ) < 0 )
                return notify_fail("???岻????????Ͷ?塣\n");

        family = query("poster_family");
        fam = the_player->query("family");

//      write("Board Restricted to " + family + " players only.\n");

        if ( stringp(family)
                && (int)SECURITY_D->cmp_wiz_level(the_player, "(immortal)" ) < 0
                && ( !mapp( fam ) || fam["family_name"] != family ) )
                return notify_fail("?Ǳ??ɵ??Ӳ????򱾰???Ϳ??д??\n");

        if(!arg) return notify_fail("??????ָ??һ?????⡣\n");
        
        note = allocate_mapping(4);
        note["title"] = set_color(arg);
        note["author"] = the_player->name()+"("+the_player->query("id")+")";
        tune_channels();
        the_player->edit( (: done_post, the_player, note :) );
        return 1;
}

int do_read(string arg)
{
        int num, arc;
        mapping *notes, last_read_time;
        string myid;
        object the_player;
        string family;
        mapping fam;

        the_player = this_player();     

        last_read_time = the_player->query("board_last_read");
        myid = query("board_id");
        notes = query("notes");
//dts
        arc = query("wizard_only");
        if ( arc
                && (int)SECURITY_D->cmp_wiz_level(the_player, "(immortal)" ) < 0)
                return notify_fail("?ڲ?ͨѶ???ÿ??ӡ?\n");

        if( !pointerp(notes) || !sizeof(notes) )
                return notify_fail("???԰???Ŀǰû???κ????ԡ?\n");

        family = query("poster_family");
        fam = the_player->query("family");

//      write("Board Restricted to " + family + " players only.\n");

        if ( stringp(family)
                && (int)SECURITY_D->cmp_wiz_level(the_player, "(immortal)" ) < 0
                && ( !mapp( fam ) || fam["family_name"] != family ) )
                return notify_fail("?Ǳ??ɵ??Ӳ??ÿ??ӱ????ڲ?ͨѶ??\n");

        if( !arg ) return notify_fail("ָ????ʽ??read <???Ա???>|new|next\n");
        if( arg=="new" || arg=="next" ) {
                if( !mapp(last_read_time) || undefinedp(last_read_time[myid]) )
                        num = 1;
                else {
                        for(num = 1; num<=sizeof(notes); num++)
                                if( notes[num-1]["time"] > last_read_time[myid] ) break;
                }
                        
        } else if( !sscanf(arg, "%d", num) )
                return notify_fail("??Ҫ???ڼ??????ԣ?\n");

        if( num < 1 || num > sizeof(notes) )
                return notify_fail("û?????????ԡ?\n");
        num--;
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


int do_discard(string arg)
{
        mapping *notes;
        int num;

        if( !arg || sscanf(arg, "%d", num)!=1 )
                return notify_fail("ָ????ʽ??discard <???Ա???>\n");
        notes = query("notes");
        if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
                return notify_fail("û?????????ԡ?\n");
        num--;
        if( notes[num]["author"] != (string)this_player(1)->name()+"("+this_player(1)->query("id")+")"
        &&  ( (int)SECURITY_D->cmp_wiz_level(this_player(), "(caretaker)") < 0 ) )
                return notify_fail("???????Բ?????д?ġ?\n");

        notes = notes[0..num-1] + notes[num+1..sizeof(notes)-1];
        set("notes", notes);
        save();
        write("ɾ???? " + (num+1) + " ??????....Ok??\n");
        return 1;
}

void tune_channels()
{
        string *tuned_ch;
        object me;
        
        me = this_player();
        
        tuned_ch = me->query("channels");
        me->set_temp("tuned_ch", tuned_ch);
        me->set("channels", 0);
}
 
void open_channels()
{
        string *tuned_ch;
        object me;
        
        me = this_player();
                       
        tuned_ch = me->query_temp("tuned_ch");
        me->set("channels", tuned_ch);
        me->set_temp("tuned_ch", 0);
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
                return notify_fail("???԰???Ŀǰû???κ????ԡ?\n");

//      if( (string)SECURITY_D->get_status(this_player(1)) != "(admin)" 
//      &&      (string)SECURITY_D->get_status(this_player(1)) != "(arch)"
//      &&      (string)SECURITY_D->get_status(this_player(1)) != "(wizard)")
//              return notify_fail("?㲻???ձࡰ?????ݡ?????ժ??\n");

        if( !arg ) return notify_fail("ָ????ʽ??store <???Ա???>\n");

        if( !sscanf(arg, "%d", num) )
                return notify_fail("??Ҫ?ձ??ڼ??????ԣ?\n");

        if( num < 1 || num > sizeof(notes) )
                return notify_fail("û?????????ԡ?\n");
        num--;
        if( notes[num]["stored"] ) 
                return notify_fail("?????????Ѿ?????¼?ˡ?\n??¼??ʾ??"+notes[num]["stored"]+"\n");

        fyear  = ctime(notes[num]["time"])[20..23];
        fmonth = ctime(notes[num]["time"])[4..6];
//      fmonth = lower_case( ctime(notes[num]["time"])[4..6] );
//      write( "FILENAME +" + fext );

        numb = EDITOR_D->get_file_num(arc, fyear, fmonth) + 1;

        filename = sprintf("%s/%s/%03d", fyear, fmonth, numb);  

        if (arc)
        write( "ARC: writing ..." + filename + "\n" );
        else
        write( "WEN: writing ..." + filename + "\n" );
        
        EDITOR_D->add(arc, "???????????????????????????????????ݡ???ѡ??"+
                "????????????????????????????", filename);
        EDITOR_D->add(arc, sprintf("??%03d  %-40s  %12s(%s)",
                numb, notes[num]["title"],
                notes[num]["author"],
                ctime(notes[num]["time"])[0..9]), filename );
        EDITOR_D->add(arc, notes[num]["msg"], filename);
        EDITOR_D->add(arc, "????ƪ????", filename);

/* index */
        filename = sprintf("%s/wenxuan.%s", fyear, fmonth);     

        if (arc)
        write( "ARC: writing ..." + filename + "\n" );
        else
        write( "WEN: writing ..." + filename + "\n" );

        if ( numb == 1)
        {
EDITOR_D->add(arc,
"????????????????????????????????????????????????????????????????????????\n" +
"                    ????????ѡ" + fyear +"???? " + fmonth + " ??Ŀ¼??\n" +
"????   ??Ŀ                                              ????(????????)\n"+
"????????????????????????????????????????????????????????????????????????",
        filename);
        }

        if (EDITOR_D->add(arc, sprintf("??%03d  %-40s  %12s(%s)",
                numb, notes[num]["title"],
                notes[num]["author"],
                ctime(notes[num]["time"])[0..9]), filename )) {
                write( notes[num]["stored"] = sprintf("???????ݡ???ѡ???? %d ƪ???? %s ?????? %03d ƪ??\n",
                        num+1, fmonth, numb) );
                log_file("wenxuan",sprintf("%s%s(%s)???롾?????ݡ???ѡ???? %d ƪ???? %s ?????? %03d ƪ??\n",
                        ctime(time()),me->query("name"),me->query("id"),num+1, fmonth, numb) );
                set("notes", notes);
        } else
                write( sprintf("???????ݡ???ѡ???? %d ƪ?ձ?ʧ?ܡ?\n", num+1) );

        return 1;
}

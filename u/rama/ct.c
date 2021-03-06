/* /kungfu/class/movie/ct.c
** 神州有奖问答中心
** created by yujie
** created in 11/2001
*/


inherit ROOM;

#define CAIPIAO "/kungfu/class/movie/obj/caipiao"
#define CPNUM "/data/movie/caipiao/cpnum"
#define CPSYS "/adm/single/cpsys"
#define GG "/data/movie/guanggao"

#include <ansi.h>
#include <inttostr.h>


nosave string answer;
nosave string title;
nosave string *in_movie;
nosave mapping question;
nosave string zhuti;
nosave int line;

void doing();
void start_answer();
string look_sign();
void end_answer();
void setblock(int pan);
void move_all();
void setall();
void deleteall();

int query_num();
void set_num(int);

void create()
{
        set("short", "有奖竞答中心");
        set("long", @LONG
这里是神州的有奖问答中心，每逢盛大的节日都会在这里举行丰富的
有奖问答活动，奖品就是由神州彩票行发行的福利彩票，活动过后便会举
行开奖活动，奖品丰厚，欢迎踊跃参加。中间立了一块大牌子（sign），
上面有活动的相关信息。
LONG
        );

        set("item_desc", ([
                "sign" : (: look_sign :),
        ]));

        set("exits", ([
                "out" : "/d/city/guangchang"
        ]));

        set("objects", ([
                __DIR__"npc/cpwaiter" : 1,
                __DIR__"npc/zhuchi" : 1,
//                 "/clone/npc/angel" : 1,

        ]));

        set("no_fight", 1);
        set("no_steal", 1);
        set("answer_time",30);
        set("ppl_number",5);
        set("cost", 0);
        setup();
}

string look_sign()
{       string movie;
        if (!zhuti || zhuti == "")
                return "现在没有有奖竞答活动举行。\n";

        movie = "现在正在举行神州有奖竞答活动。\n本次活动的主题是：\n\n\n\t\t"+HIW+zhuti+NOR+"\n\n";
	movie += "没有皮囊保存彩票的玩家请先向彩票行的临时招待要一个皮囊。\n";
	movie += "玩家赢得的彩票可以保存在皮囊里，那么下线也不会丢失了，活动过后会开奖，请留意扬州彩票行的公告。\n";
	movie += "\n\t\t\t\t------- 负责人：Yujie\n";
        return movie;
}

void move_all()
{       object ob = this_object();
        object *usrs;
        int i;

        usrs = all_inventory(ob);
        for(i=0; i<sizeof(usrs) ;i++ )
                if ( userp(usrs[i])) {usrs[i]->set_temp("block_msg/all",1);usrs[i]->move(ob);usrs[i]->delete_temp("block_msg/all");}
}

void setall()
{       object ob = this_object();
        object *usrs;
        int i;

        usrs = all_inventory(ob);
        for(i=0; i<sizeof(usrs) ;i++ )
                if ( userp(usrs[i])) usrs[i]->set("movie_answer",1);
}

void deleteall()
{       object ob = this_object();
        object *usrs;
        int i;

        usrs = all_inventory(ob);
        for(i=0; i<sizeof(usrs) ;i++ )
                if ( userp(usrs[i])) usrs[i]->delete("movie_answer");
}

void setblock(int pan)
{
        object me = this_object();
        object *users;
        int i;

        users = all_inventory(me);

        if (pan)
                for(i=0 ; i<sizeof(users) ; i++)
                        users[i]->set_temp("block_msg/all",1);
        else
                for(i=0 ; i<sizeof(users) ; i++)
                        users[i]->set_temp("block_msg/all",0);
}

int do_setline(string arg)
{
        int i;
        if (!wizardp(this_player()))
                return notify_fail("只有巫师可以设置播放的行数。\n");

        if (!arg) return notify_fail("你要设置的参数是？\n");

        if ( sscanf(arg,"%d",i) == 1)
        {       line = i;
                write("设置为"+chinese_number(i)+"行开始播放。\n");
        }else
                write("设置失败，参数非数字。\n");
        return 1;
}

int do_nowline(string arg)
{
        int time;
        if (!wizardp(this_player()))
                return notify_fail("只有巫师可以设置有奖竞答的间隔时间。\n");

        write("现在的行数是："+chinese_number(line)+"。\n");
        return 1;
}



void init()
{       object me = this_player();

        remove_action("do_answer","answer");
        if ( me->query("movie_answer") )
                add_action("do_answer","answer");

        add_action("do_settime","settime");
        add_action("do_setnum","setnum");
        add_action("do_setline","setline");
        add_action("do_nowline","nowline");

        add_action("do_play","play");
        add_action("do_stop","stop");

}


int query_num()
{       string arg;
        int num;

        arg = read_file(CPNUM);

        if (sscanf(arg,"%d",num) == 1)
                return num;

        return 0;
}

void set_num(int num)
{
        string arg;

        arg = tostring(num);
        write_file(CPNUM,arg,1);
}

int do_settime(string arg)
{
        int time;

        if (!wizardp(this_player()))
                return notify_fail("只有巫师可以设置有奖竞答的间隔时间。\n");

        if (!arg) return notify_fail("你要设置的参数是？\n");

        if ( sscanf(arg,"%d",time) == 1)
        {       set("answer_time",time);
                write("设置为"+chinese_number(time)+"秒种进行一次有奖竞答。\n");
        }else
                write("设置失败，参数非数字。\n");
        return 1;
}


int do_setnum(string arg)
{
        int num;
        if (!wizardp(this_player()))
                return notify_fail("只有巫师可以设置有奖竞答的低限人数。\n");

        if (!arg) return notify_fail("你要设置的参数是？\n");

        if ( sscanf(arg,"%d",num) == 1)
        {       set("ppl_number",num);
                write("设置为"+chinese_number(num)+"为竞答的最低限制人数。\n");
        }else
                write("设置失败，参数非数字。\n");
        return 1;
}


int do_play(string arg)
{
        object me = this_player();


        if ( !wizardp(me) )
                return notify_fail("只有巫师才能举行有奖竞答活动。\n");

        if (query("player_now"))
                return notify_fail("现在已经在举行竞答活动了。\n");

        zhuti = arg;
        set("play_now",1);
        in_movie = explode(read_file(GG),"\n");
	line = 1;

        shout( HIG "【有奖竞答】：现在开始举行神州有奖竞答活动，欢迎大家从中央广场up入场参加。\n"NOR);
        write( HIG "【有奖竞答】：现在开始举行神州有奖竞答活动，欢迎大家从中央广场up入场参加。\n"NOR);
        shout( HIG "【有奖竞答】：本次有奖竞答的主题是："+zhuti+"\n"NOR);
        write( HIG "【有奖竞答】：本次有奖竞答的主题是："+zhuti+"\n"NOR);


        call_out("doing",1);

        return 1;
}

void doing()
{       string arg, msg;
        int time,num ,i,j;
        object *user;
        object me = this_object();
        object q_ob;

        time = query("answer_time");
        num  = query("ppl_number");

	if (line >= sizeof(in_movie) )
		line = 1;

        arg = in_movie[line];
        arg = replace_string(arg, "$BLK$", BLK);
        arg = replace_string(arg, "$RED$", RED);
        arg = replace_string(arg, "$GRN$", GRN);
        arg = replace_string(arg, "$YEL$", YEL);
        arg = replace_string(arg, "$BLU$", BLU);
        arg = replace_string(arg, "$MAG$", MAG);
        arg = replace_string(arg, "$CYN$", CYN);
        arg = replace_string(arg, "$WHT$", WHT);
        arg = replace_string(arg, "$HIR$", HIR);
        arg = replace_string(arg, "$HIG$", HIG);
        arg = replace_string(arg, "$HIY$", HIY);
        arg = replace_string(arg, "$HIB$", HIB);
        arg = replace_string(arg, "$HIM$", HIM);
        arg = replace_string(arg, "$HIC$", HIC);
        arg = replace_string(arg, "$HIW$", HIW);
        arg = replace_string(arg, "$NOR$", NOR);
        arg = replace_string(arg, "$BLINK$", BLINK);
        arg = arg + "\n";
        arg = HIG"【插播广告】："NOR + arg;

        remove_call_out("doing");
        tell_room(this_object() ,arg);
        line = line + 1;

        if ( (line/time)*time == line )
        {       tell_room(this_object(),HIW"\n\n           ******** 广告播放暂停，进行有奖竞答活动 ********\n\n"NOR);
                user = all_inventory(this_object());
                j=0;
                for(i=0; i<sizeof(user); i++)
                        if ( userp( user[i] )) j++;
                if (j < num)
                {
                        tell_room(me,HIG"主持人高声叫到：人数太少，竞答活动取消，继续播放。\n"NOR);
                        tell_room(me,HIW"\n\n           ******** 竞答活动中止，继续广告插播 ********\n\n"NOR);
                        call_out("doing",1);
                        return;
                }

                if ( !sizeof( get_dir("/data/movie/answer/") ) )
                {
                        tell_room(me,HIG"主持人说道：后备竞答资料库里没有资料，无法进行竞答活动，竞答取消，继续播放。\n"NOR);
                        tell_room(me,HIW"\n\n           ******** 竞答活动中止，继续广告插播 ********\n\n"NOR);
                        call_out("doing",1);
                        return;
                }

                tell_room(me,HIY"主持人高声说道：有奖竞答活动现在开始，等会我宣布题目后，大家尽快用answer <答案> 来抢答。\n"NOR);
                tell_room(me,HIY"主持人高声说道：第一个抢答正确的玩家可以得到福利彩票一张，大家做好准备，要开始念题了！\n\n"NOR);
                msg = "/data/movie/answer/"+get_dir("/data/movie/answer/")[random(sizeof(get_dir("/data/movie/answer/")))];

                if (!objectp(q_ob = find_object(msg) ))
                        q_ob = load_object(msg);

                question = q_ob->query_question();
                title = q_ob->query_main();
                remove_call_out("start_answer");
                call_out("start_answer",2);

                return;
        }


        call_out("doing",1);
}

void start_answer()
{
        object gold;
        object me = this_object();

        if (!mapp(question))
        {
                tell_room(me,HIG"主持人说道：由于竞答资料出错，竞答活动无法进行，继续刚才的播放。\n"NOR);

                tell_room(me,HIW"           ******** 竞答活动中止，继续广告插播 ********\n\n"NOR);
                        call_out("doing",1);
                return;
        }
       set("answered",0);

        if (stringp(question["long"]))
        {
                tell_room(me,HIG"主持人高声宣布：这次有奖竞答是一道"+title+"的题目，大家听好了：\n\n"NOR);
                tell_room(me,HIW"              "+question["long"]+"\n\n"NOR);
                tell_room(me,YEL"               现在开始抢答 ****（抢答指令：answer <答案>）\n\n"NOR);
                set("answered",0);
                setall();
                move_all();
                call_out("end_answer",60);
        }
}

int do_answer(string arg)
{
        object me = this_player();
        object ob = this_object();
        object caipiao;
        string msg;


        if ( !arg )
        {       write("你的答案是什么？\n");
                return 1;
        }

        message_vision(CYN"$N大声抢答道："+ arg+"\n"NOR,me);

        if (arg == question["answer"] )
        {       tell_room(ob,HIG"主持人大声宣布："+me->query("name")+"答对了，本次竞答的胜利属于你！\n\n"NOR);
                write_file("/data/movie/caipiao/answerban",question["long"]+"*");

                message_vision(HIG"\n主持人对着$N笑道：恭喜你胜出本轮的有奖竞答，奖品是扬州彩票行发行的福利彩票一张，祝你好运！\n"NOR,me);
                message_vision(HIG"主持人笑着递给$N一张福利彩票。\n\n"NOR,me);
                caipiao = new(CAIPIAO);
                caipiao->set("number",query_num());
                msg = tostring(query_num()+1);
                CPSYS->set_num(msg);
                caipiao->move(me);
            log_file("test/caipiao", me->query("id")+"（"+caipiao->query("number")+")\n");

                tell_room(ob, HIG "【有奖竞答】："+ me->query("name") + " 在本次神州影院有奖竞答中胜出，获得福利彩票一张。\n" NOR );
                shout(ob, HIG "【有奖竞答】："+ me->query("name") + " 在本次神州影院有奖竞答中胜出，获得福利彩票一张。\n" NOR );

                deleteall();
                move_all();
                set("answered",1);
                tell_room(me,HIW"           ******** 本轮竞答活动终止，广告之后继续下轮竞答 ********\n\n"NOR);
                remove_call_out("end_answer");
                call_out("doing",1);
        }
        else
             write("主持人对你摇了摇头，说道：不对，不对！\n");
        return 1;
}

void end_answer()
{
        if ( query("answered"))
                return;

        tell_room(this_object(),HIG"主持人失望的说道：竟然没有一个人能抢答上来，真是可惜了。下次再努力吧！\n\n"NOR);
        tell_room(this_object(),HIW"           ******** 本轮竞答活动终止，广告之后继续下轮竞答 ********\n\n"NOR);
        remove_call_out("end_answer");
        deleteall();
        move_all();
        call_out("doing",1);
}

int do_stop(string arg)
{
        object me = this_player();

        if ( !wizardp(me) )
                return notify_fail("只有巫师才能停止播放主放映厅的片子。\n");

        if (!query("play_now"))
                return notify_fail("现在没有举行活动。\n");

        shout( HIG "【有奖竞答】： 今天的有奖竞答活动结束，感谢大家的参与，稍后请留意开奖的公告。\n" NOR );
        write( HIG "【有奖竞答】： 今天的有奖竞答活动结束，感谢大家的参与，稍后请留意开奖的公告。\n" NOR );
	remove_call_out("doing");
	remove_call_out("end_answer");
        deleteall();
        move_all();

        delete("play_now");
        in_movie = ({""});

        return 1;
}

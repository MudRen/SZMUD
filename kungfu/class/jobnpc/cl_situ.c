//Cracked by Yujie
// /kungfu/class/jobnpc/cl_situ.c 司徒横
// by 10 / 2001

#ifndef BANGS
#define BANGS  "/d/huanghe/"
#endif

#define BANGYIN     BANGS + "obj/bangyin"
#define BANGLING    BANGS + "obj/bangling"
#define POSFILE "/d/forest/sifang/clb_pos"
#define BANGSKILLS  BANGS + "skills"
#define OFFICE  "/d/forest/clxiaoting"
#define CLB_POS  "/topten/clb_file"
#define SF_DIR "/kungfu/class/changle/clsifang"


inherit NPC;
inherit F_CLEAN_UP;
inherit F_SAVE;

#include <ansi.h>
#include <localtime.h>

#include "/d/huanghe/changle/info_beauty.h"

int ask_join();
int be_got(string,string);
string ask_job();
string ask_kaichu();
string ask_skills();
string ask_position();
string ask_life();
string ask_recover();
string query_save_file()
{
        return "/data/npc/cl_situ";
}

string *positions = ({
        "龙灵堂",
        "豹捷堂",
        "鹤翔堂",
        "狮敏堂",
        "熊威堂",
        "鹰迅堂",
        "蛇勇堂",
});

void create()
{
	set_name("司徒横", ({ "situ heng", "situ" }));
	set("nickname", "八爪金龙");
        set("fam", "长乐帮");
	set("long",
"他是一个身材高大，但有些干瘦的中年人，双臂很长，飞抓功夫\n"
"在武林中也堪称一绝。\n");
	set("gender", "男性");
	set("age", 45);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 50);
	set("int", 28);
	set("con", 24);
	set("dex", 25);

	set("max_qi", 1000);
	set("max_jing", 800);
	set("max_neili", 1000);
        set("neili", 1000);
	set("jiali", 60);
	set("combat_exp", 300000);
	set("score", 10000);

	set_skill("force", 120);
        set_skill("dodge", 120);
        set_skill("parry", 120);
        set_skill("claw",  120);
        set_skill("strike", 80);
        set_skill("staff", 80);

        set_skill("poison", 80);

        set_skill("huagong-dafa", 120);
	set_skill("zhaixinggong", 120);
        set_skill("sanyin-zhua",  120);
        set_skill("chousui-zhang", 80);
        set_skill("tianshan-zhang", 80);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
        map_skill("parry", "sanyin-zhua");
        map_skill("claw",  "sanyin-zhua");
        map_skill("strike", "chousui-zhang");
        map_skill("staff", "tianshan-zhang");

        prepare_skill("claw",  "sanyin-zhua");
        

        set("inquiry", ([
                "入帮" : (: ask_join :),
                "开除" : (: ask_kaichu :),
                "join" : (: ask_join :),
                "帮务" : (: ask_job :),
                "job" : (: ask_job :),
                "武功" : (: ask_skills :),
                "skills" : (: ask_skills :),
                "长乐帮" : "长乐帮威震江湖，指日可待！哈！哈！哈！",
                "贝先生" : "贝先生劳苦功高，所以我任命他为总管。",
                "贝大夫" : "贝先生劳苦功高，所以我任命他为总管。",
                "贝海石" : "贝先生劳苦功高，所以我任命他为总管。",
                "香主" : (: ask_position :),
                "position" : (: ask_position :),
                "生活" : (: ask_life :),
                "life" : (: ask_life :),
                "recover" : "现在功劳点是自动累积的，已经不需要恢复了。",
                "恢复" : "现在功劳点是自动累积的，已经不需要恢复了。",
        ]));
        
        
	setup();

        carry_object("/clone/misc/cloth")->wear();
 //     carry_object("/clone/weapon/feizhua")->wield();
}

     string ask_kaichu() 
{

             object me = this_player() , ob = this_object();
object ling;
object sf_d;
             string myfam,mypos,msg,*msg_a,nowmsg,sfn; 
             int lastscore,score,i; 
             myfam = (string)query("fam"); 
             if( (string)me->query_temp("bangs/fam") != myfam ) 
                     return RANK_D->query_rude(me) + "莫非是想打听我帮的秘密吧。"; 

             if( !(ling = present("bang ling", me)) ) 
                     return RANK_D->query_rude(me) + "竟连自己的帮令都管不住！"; 

             if (!stringp(mypos = me->query("clbpos")))
                     return "你并非本帮香主。"; 

       me->delete("clbpos"); 
            if( strlen ( msg = read_file(POSFILE)) > 0 )  
       { msg_a = explode(msg,"\n"); 
       msg=""; 
       nowmsg = me->query("id")+"("+ mypos + ")"; 
       for(i=0; i< sizeof(msg_a); i++) 
               if(msg_a[i] != nowmsg) msg += ( msg_a[i]+"\n"); 
write_file(POSFILE,msg,1); 
       }
       switch(mypos) 
       {
case "龙灵堂" : write_file("/d/forest/sifang/sifang1_file","",1);sfn="1";break;
case "狮敏堂" : write_file("/d/forest/sifang/sifang2_file","",1);sfn="2";break;
case "熊威堂" : write_file("/d/forest/sifang/sifang3_file","",1);sfn="3";break; 
case "鹰迅堂" : write_file("/d/forest/sifang/sifang4_file","",1);sfn="4";break; 
case "蛇勇堂" : write_file("/d/forest/sifang/sifang5_file","",1);sfn="5";break; 
       }
if ( sf_d = find_object(SF_DIR + sfn) ) 
        destruct(sf_d); 

message_vision(HIM"因为主动让贤，$N的"+mypos+"香主一职取消。\n"NOR,me);
command("chat 各位江湖朋友们，"+ me->name()+ "主动让贤长乐帮"+ mypos +"香主一职。\n"); 
return "";
}

string ask_job()
{
        object ob = this_player();

        if( (string)ob->query_temp("bangs/fam") != "长乐帮" )
                return RANK_D->query_rude(ob) + "莫非是想打听我帮的秘密吧。";

        return "有关具体帮务方面的事你去问贝先生。";
}

string ask_position()
{
        object *obj, ling, wage, me = this_player(), ob = this_object();
        string *poss, *leftpos, pos, myfam,allpos,pplid,mypos,str;
        int i, score, bonus, period, record,j;

        if( is_fighting() )
                return RANK_D->query_rude(me) + "瞎了眼没见我正忙着？！";

        myfam = (string)query("fam");
        if( (string)me->query_temp("bangs/fam") != myfam )
                return RANK_D->query_rude(me) + "莫非是想打听我帮的秘密吧。";

        
        if( stringp(pos = me->query_temp("bangs/pos")) ) {
                period = uptime() - (int)me->query_temp("bangs/pos_time");
                if( period < 900 )
                        return "你在这么短的时间内不可能有多大作为，以后再让帮主巡视" + pos + "吧。";

                score = (int)me->query("clbscore");
                bonus = score - (int)me->query_temp("bangs/pos_score");
                me->set_temp("bangs/pos_score", score);
                me->set_temp("bangs/pos_time", uptime());

                if( bonus < 1000 )
                        return pos + "最近表现很差呀，你这些日子在干吗？";

                command("nod");
//              bonus *= (score / 1000 + 1);
//              This line is the old code, if player stays on line and cumulates the
//              score, it can be very big, for example, online 15 hours can get about 20k score
//              20000 / 1000 + 1 = 21, if he only ask xiang zhu one
//              bonus = (20000 - 500) * 21 = 409500, and later bonus /= 3, add_exp = bonus +random(bonus)
//              So a player can get 200k exp like this.

//              So instead of multiply, add the bonus, so it won't increase by factors. 
                bonus = bonus/500;
                wage = new("/clone/money/gold");
                record = bonus + random(bonus/2);
                wage->set_amount(record);
                wage->move(me);
                message_vision("$N转身拿出一个红包递给$n。\n", this_object(), me);
                log_file("test/BangPos", sprintf("%s于%s时因管辖%s%s获利%s两黄金\n", me->query("name"), ctime(time()), myfam, pos, chinese_number(record)));

                bonus /= 3;
                me->add("combat_exp", bonus + random(bonus));
                return pos + "在你的管辖下，最近表现不错。";
        }
        
        if( (int)me->query("combat_exp") < 50000 )
                return RANK_D->query_rude(me) + "当香主未免太嫩了吧。";

        if( (score = (int)me->query("clbscore")) < 200000 )
                return "就凭你这点功劳也窥视香主之位？";

        leftpos = positions;
        if(stringp(allpos=read_file(POSFILE)))
        {	
        	poss = explode(allpos,"\n");
        	for (i=0 ;i < sizeof(poss) ;i++)
        	{	sscanf(poss[i],"%s(%s)",pplid,pos);
	             	leftpos = filter_array(leftpos,"be_got",this_object(),pos);
        	}
        }
        
	if( !sizeof(leftpos) )
                return "现在所有的香主之位都有人占着。";

        mypos = leftpos[random(sizeof(leftpos))];
        me->set_temp("bangs/pos", mypos);
        me->set("clbpos",mypos);
        me->set_temp("bangs/pos_time", uptime());
        me->set_temp("bangs/pos_score", score);
        str = me->query("id")+ "(" + mypos + ")\n";
        if(stringp(read_file(POSFILE)))
                str = read_file(POSFILE) + str;
        write_file(POSFILE,str,1);
        
                
        me->set_temp("apply/short",
   ({ HIR + myfam + mypos + "香主 "NOR + me->query("name")+"("+capitalize(me->query("id"))+")" }));
        log_file("test/BangPos", sprintf("%s于%s时当上%s%s香主\n", me->query("name"), ctime(time()), myfam, pos));
        command("congra");
        command("chat 各位江湖朋友们，"+ me->name()+ "从今天开始上任长乐帮"+ me->query("clbpos")+"香主，希望能把我帮发扬光大。\n");

        return "我把" + mypos + "托付给你，你可要不负众望。";

}

/*
string ask_recover()
{	
	object ling, sf_d, me=this_player(), ob=this_object();
	string myfam,mypos,msg,*msg_a,nowmsg,sfn;
	int lastscore,score,i;
			
	if( is_fighting() )
                return RANK_D->query_rude(me) + "瞎了眼没见我正忙着？！";

        myfam = (string)query("fam");
        if( (string)me->query_temp("bangs/fam") != myfam )
                return RANK_D->query_rude(me) + "莫非是想打听我帮的秘密吧。";

        if( !(ling = present("bang ling", me)) )
                return RANK_D->query_rude(me) + "竟连自己的帮令都管不住！";

        if( (string)ling->query("owner") != me->query("id") )
                return RANK_D->query_rude(me) + "竟连自己的帮令都管不住！";
                
        if (me->query_temp("recovered"))
		return "你刚才已经恢复过了。";
	
	if (!intp( lastscore = me->query("clbscore")))
		return "你以前并为在我帮做过事，恢复什么呀？";
	
	ling->add("score",lastscore);
	score = ling->query("score");
	if ( stringp (mypos = me->query("clbpos")) )
	{	if ( score < 200000 )
		{	me->delete("clbpos");
			if( strlen ( msg = ob->query("clb_pos")) > 0 )
			{   
                	msg_a = explode(msg,"\n");
                	msg="";
                	nowmsg = me->query("id")+"("+ mypos + ")";
                        for(i=0; i< sizeof(msg_a); i++)
                        	if(msg_a[i] != nowmsg) msg += ( msg_a[i]+"\n");
                        ob->set("clb_pos",msg);
                        save();
                        }
                        switch(mypos)
                        {
                        case "龙灵堂" : write_file("/d/forest/sifang/sifang1_file","",1);sfn="1";break;
                        case "狮敏堂" : write_file("/d/forest/sifang/sifang2_file","",1);sfn="2";break;
        		case "熊威堂" : write_file("/d/forest/sifang/sifang3_file","",1);sfn="3";break;
        		case "鹰迅堂" : write_file("/d/forest/sifang/sifang4_file","",1);sfn="4";break;
        		case "蛇勇堂" : write_file("/d/forest/sifang/sifang5_file","",1);sfn="5";break;
        		}
        		if ( sf_d = find_object(SF_DIR + sfn) )
        			destruct(sf_d);
        		
                        message_vision(HIM"因为表现太差，$N的"+mypos+"香主一职被撤。\n"NOR,me);
		}
		else
		{	me->set_temp("bangs/pos", mypos);
        		me->set_temp("bangs/pos_time", uptime());
        		me->set_temp("bangs/pos_score", score);
                        
        		me->set_temp("apply/short",
   			({ HIR + myfam + mypos + "香主 "NOR + me->query("name")+"("+capitalize(me->query("id"))+")" }));
   			message_vision("$N的"+mypos+"香主一职恢复了。\n",me);
   		}
	}
	me->set_temp("recovered",1);
	return "你上次在本帮的活动记录老夫帮你恢复了。";
}
*/

string ask_life()
{
        object me = this_player();
        string myfam, *beautys, beauty;

        if( is_fighting() )
                return RANK_D->query_rude(me) + "瞎了眼没见我正忙着？！";

        myfam = (string)query("fam");
        if( (string)me->query_temp("bangs/fam") != myfam )
                return RANK_D->query_rude(me) + "莫非是想打听我帮的秘密吧。";

        if ( me->query("combat_exp")< 5000 )
        {	command("shake "+me->query("id"));
        	return "你才这两下子恐怕无法胜任这事，还是去找贝先生吧。";
        }
        
        if( uptime() < (int)query("joytime") + 60 + random(20) ) {
        if (random(2))
        {        command("lazy");
                 return "老夫最近对此没有兴趣。";
        }
        command("shake");
        return "老夫这里没事干了，你去问贝先生要活干吧。";
        }

        beautys = keys(info_beauty);
        beauty = beautys[random(sizeof(beautys))];

        command("hehe " + query("id"));
        me->set_temp("bangs/beauty", beauty);
        set("joytime", uptime());
        return "最近" + beauty + "这娘们怎么样啦？老夫这几天都没睡稳觉。";
}

int accept_object(object who, object ob)
{
        object ling, room;
        string myfam, beauty;
        int bonus, record,reduce;

        myfam = query("fam");
        if( who->query_temp("bangs/fam") != myfam ) 
                return notify_fail(name() + "大怒道：大胆！想谋害本帮主？！\n");

        if( !(room = environment()) )
                return notify_fail(name() + "大怒道：等我回总舵再说吧！\n");

        if( base_name(room) != OFFICE )
                return notify_fail(name() + "大怒道：等我回总舵再说吧！\n");

        if( !stringp(beauty = who->query_temp("bangs/beauty")) )
                return notify_fail(name() + "大怒道：滚！老夫的私事不用你操心！\n");

        if( !ob->is_character() )
                return notify_fail(name() + "大怒道：这种烂东西你自己用吧！\n");

        if( ob->query("gender") != "女性" )
                return notify_fail(name() + "大怒道：老夫对人妖没兴趣！\n");

        if( ob->query("name") != beauty )
                return notify_fail(name() + "大怒道：连老夫的话都记不住！\n");
        
        if (userp(ob))
        	return notify_fail(name() + "大怒道：想用这套来蒙骗老夫，门都没有！\n");

	if( userp(ob) )
		return notify_fail(name() + "大怒道：滚！随便找个人回来竟想蒙骗老夫！\n");
            
        who->delete_temp("bangs/beauty");
        ob->move(this_object());
        call_out("destroy_beauty", 1, ob);
        bonus = info_beauty[beauty] * 80000 / (80000 + (int)who->query("combat_exp"));
                
        reduce = ((int)ob->query("eff_qi")*100)/(int)ob->query("max_qi");
        
        if ( reduce < 20 ) return notify_fail(name() + "大怒道：都伤的只剩下半条命了，你自己留着慢用吧！\n");
        
        if (reduce != 100)	bonus = bonus * reduce/150;
        if (bonus < 10)		bonus = 10;
        record = bonus*2 + random(bonus/2);
                
        who->add("combat_exp", record);
        who->add("shen", -(record/4));
        log_file("test/BangWomen",  sprintf("%s于%s时上贡%s得%s经验点\n", who->query("name"), ctime(time()), beauty, chinese_number(record)));
	bonus = bonus + random(bonus/4);
       
       	who->add("clbscore",bonus);
       	write(HIW"你这次工作共得到"+chinese_number(bonus)+"点功劳点，" + chinese_number(record)+ "点经验值。\n"NOR);
       
        command("haha");
        command("say 好！好！好！" + myfam + "上上下下几千人中数你最讨帮主的欢心！");
        return 1;
}       

void destroy_beauty(object ob)
{
        if( ob )  destruct(ob);
}

int be_got(string leftpos, string pos)
{
	if (leftpos == pos)	return 0;
	return 1;
}

#include "/d/huanghe/npc/bangzhu.h";

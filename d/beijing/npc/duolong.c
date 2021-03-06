//Cracked by Roath

#include <ansi.h>
inherit NPC;
string ask_job();
string ask_suicong();
string ask_yaopai();
int do_ling(string);

#include "/d/beijing/beijing_defs.h"
#include "/d/beijing/job_info.h"
void set_shiwei_status(int);

string *Robber_Name = ({
	"土匪","山大王","路霸","山贼","毛贼","寨主","帮匪"
	});
string *Biaohuo_Name = ({
	"珍珠","玛瑙","金子","钻石","象牙","玉器","古玩"
	});

string ask_abandon();
void assign_biaotou(object me, object partner);
void setup_skill(object me,object obj);
private int is_suitable(object victim, object killer);
private int is_suitable_rob(object victim, object killer);
string QueryDest(object obj);
int assign_rob(object me);

void create()
{
    set_name("多隆", ({
	    "duo long", "duo",
    }));
    set("title", "侍卫总管");
    set("long",
	"作为侍卫总管，多隆深受皇上器重。\n"
	"御林军的任务都从他这里分派。\n"
    );


    set("gender", "男性");
    set("age", 35);
    setup();

    set_shiwei_status(180);

    set("inquiry", ([
	"job" : (: ask_job :),
	"任务" : (: ask_job :),
	"晋升" : "这个你到兵部去问米尚书吧。",
	"promote" : "这个你到兵部去问米尚书吧。",
	"升官" : "这个你到兵部去问米尚书吧。",
	"随从" : (: ask_suicong :),
	"suicong" : (: ask_suicong :),
	"here" : "这里是侍卫营。不得喧哗。",
	"腰牌" : (: ask_yaopai :),
	"yaopai" : (: ask_yaopai :),
		"abandon" : (: ask_abandon:),
		"放弃" : (: ask_abandon:),
    ]));
}

void init()
{
	object ob;

	::init();
	if( !query_heart_beat(this_object()) ) set_heart_beat(1);

	add_action("do_jobwith", "jobwith");
    add_action("do_ling", "ling");
	if( interactive(ob = this_player()) && !is_fighting())
	{
		//remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	int bonus,old_pot;
	string *skname;
	mapping skills;
	int i;

	if( !ob || environment(ob) != environment() ) return;
	if( ob->query("biao/bonus") )
	{
		bonus = ob->query("biao/bonus");
		message_vision( HIG"$N对着$n笑道：$n干的好！咱们朝廷全靠你这样的人才。\n\n"NOR,this_object(),ob);
		command( "thumb "+ob->query("id") );
		ob->delete("biao");
		ob->add("combat_exp", bonus );
		old_pot = ob->query("potential");
		if(bonus>360)bonus=360;
		ob->add("potential", bonus );
		ob->remove_all_killer();
		if(ob->query_condition("biaoju")) ob->clear_one_condition("biaoju");
		ob->add("biaoju/succeed",1);
		ob->add("bingbu/job_cur", 3);
		if( ob->query("potential") > ob->query("max_potential") ) ob->set("potential",ob->query("max_potential") );
		add_temp("biao", -1);
		log_file("/test/BiaoJob", ctime(time()) + ob->query("name") +"(" + ob->query("id") + ")在官府保镖获得" + bonus + "经验和"+ (ob->query("potential")-old_pot) + "潜能\n" );
	}
	if( ob->query("master_name") == "戴刀侍卫" || ob->query("master_name") == "亲兵")
	{
		command( "say 本官不收徒弟，你得另拜名师！");
		message_vision("\n$N对着$n说道：从今天起，你得另拜名师！\n\n", this_object(), ob);
		ob->delete("family");
		ob->delete("title");
		ob->delete("master_id");
		ob->delete("master_name");
		ob->set("score", 0);
		skills = ob->query_skills();
		if( mapp(skills) )
		{
			skname = keys(skills);
			for(i=0; i<sizeof(skname); i++) skills[skname[i]] /= 2;
		}
	}
}

int sync_mizheng(object player)
{
    object mizheng;

    // fix test players
    mizheng = HELPER->find_mizheng();
    if (mizheng->player_rank(player->query("id")) == -1) {
	message_vision("$N疑惑的看了$n一眼，你怎么会有侍卫头衔的？\n",
	    this_object(), player);
	mizheng->normalize(player);
        return 1;
    }
    return 0;
}

string ask_yaopai ()
{
    object player = this_player(), me = this_object();
    object *inv, yaopai;
    int i;

    if (! IS_SHIWEI(player)) 
	return "你又不是侍卫，要什么腰牌？";

    if (sync_mizheng(player)) return "你重新到米尚书那儿去登记吧。";

    inv = all_inventory(player);
    for (i=0; i<sizeof(inv)-1; i++){
	if (base_name(inv[i]) == "/d/beijing/obj/yaopai") 
	    return "你不是有腰牌了吗？";
    }
    yaopai = new ("/d/beijing/obj/yaopai");
    yaopai->move(player);
    message_vision("$N给$n一面侍卫腰牌。\n", me, player);
    return "小心点，别老搞丢了。";
}

string ask_job()
{
    object player = this_player(), me = this_object();
	object biaoche;

    int i, shichen=HELPER->shichen(), penalty;

    if (!IS_SHIWEI(player)) 
        return "你先到兵部投军吧。";
    if (sync_mizheng(player)) return "你重新到米尚书那儿去登记吧。";

    if (player->query_temp("current_job")) {
	if (SHIWEI_LEVEL(player)<4) {
	    return "我不是告诉你了吗？去"+
		    player->query_temp("current_job")+"守门吧。";
	}
  	return "我不是告诉你了吗?";
    }

    switch (SHIWEI_LEVEL(player)) {
    case 0:	// first level
	if (HELPER->is_sunrise() < 0) 
	    return "现在还没到你当班的时间呢。";
	if (HELPER->is_sunrise() > 0) 
	    return "点名过卯的时间已经过了，你明天再来吧。";
	i = random(sizeof(outer_gate_name));
	player->set_temp("current_job", outer_gate_name[i]);
	return "你快去"+outer_gate_name[i]+"守门 (guard) 吧。";
    case 1:	// second level
	if (HELPER->is_sunset() < 0) 
	    return "天还亮着呢，等会儿就有你的戏啦。";
	if (HELPER->is_sunset() > 0) 
	    return "天都黑了你才来，明天再说吧。";
	i = random(sizeof(outer_gate_name));
	player->set_temp("current_job", outer_gate_name[i]);
	return "你快去"+outer_gate_name[i]+"守门 (guard) 吧。";
    case 2:	// third level
	if (HELPER->is_sunrise() < 0) 
	return "现在还没到你当班的时间呢。";
	if (HELPER->is_sunrise() > 0) 
	    return "点名过卯的时间已经过了，你明天再来吧。";
	i = random(sizeof(inner_gate_name));
	player->set_temp("current_job", inner_gate_name[i]);
	return "你快去"+inner_gate_name[i]+"守门 (guard) 吧。";
    case 3:	// fourth level
	if (HELPER->is_sunset() < 0) 
	    return "天还亮着呢，等会儿就有你的戏啦。";
	if (HELPER->is_sunset() > 0) 
	    return "天都黑了你才来，明天再说吧。";
	i = random(sizeof(inner_gate_name));
	player->set_temp("current_job", inner_gate_name[i]);
	return "你快去"+inner_gate_name[i]+"守门 (guard) 吧。";

    case 4:	// fourth level
    case 5:	// fifth level
    case 6:	// sixth level
	if ( player->query("biao/fail") )
	{
		player->delete("biao");
		penalty = ( 1 + player->query("biaoju/fail") * 10 / ( 1+ player->query("biaoju/succeed") ) ) * ( 30+random(30) ) ;
		player->apply_condition( "biao", penalty );
		player->add("biaoju/fail",1);
		return "你这不中用的家伙，亏你还有脸回来见我要求走镖！\n";
	}
	if ( player->query_condition("biao") )
	{
		return "我这里倒有几桩差事，可是暂时信不过你去干！\n";
	}
	if ( (int)me->query_temp("biao") >= 1000 )
	{
		return "今天所有的镖都已送完了，你明天早点来吧。";
	}
	if ( player->query("biao") ) {
		command( "angry" );
		return "你还没完成任务，怎么便想讨多桩差事？\n";
	}
	command( "say 好吧，你来得正是时候，我这儿正缺人用。");
	switch( random(7) )
	{
		case 0:
			player->set("biao/dest", "dao baifeng");
			player->set("biao/dest2", "/d/dali/yuxuguan");
			command("say 你把这份东西送到大理王妃刀白凤那儿，这份镖非同小可，一定要小心。");
			break;
		case 1:
			player->set("biao/dest", "hu laoye");
			player->set("biao/dest2", "/d/xingxiu/house");
			command("say 这是北疆小镇巴依托送的重镖，你得多加小心，丢了可赔不起！");
			break;
		case 2:
			player->set("biao/dest", "ye erniang");
			player->set("biao/dest2", "/d/xixia/dawu");
			command("say 这份重镖是送到西夏叶二娘的，你得亲自交给她。");
			break;
		case 3:
			player->set("biao/dest", "wu tiande");
			player->set("biao/dest2", "/d/chengdu/tidufu");
			command("say 这有份要送给成都提督吴天德的镖货，你帮我走一趟吧。");
			break;
		case 4:
			player->set("biao/dest", "shi lang");
			player->set("biao/dest2", "/d/quanzhou/jiangfu1");
			command("say 这是泉州靖海侯府重托的红镖，非同小可。你千万不可大意，务必交到靖海侯施琅手里。");
			break;
		case 5:
			player->set("biao/dest", "li kexiu");
			player->set("biao/dest2", "/d/city/ymzhengting");
			command("say 这是送给扬州水陆提督李克秀的镖货，你帮我走一趟吧。这份镖货非同小可，你千万不可大意。");
			break;
		case 6:
			player->set("biao/dest", "liu haoyi");
			player->set("biao/dest2", "/d/chengdu/zijuefuhall");
			command("say 这是送给成都世袭子爵刘好弈的镖货，你去帮我亲手交给刘子爵。");
			break;
	}
	message_vision( "$N高声叫道：来人呐！\n", me);
	player->apply_condition("biaoju",70);
	player->add("biao/times", 1);
	player->set_temp("apply/short", ({HIR"御林军镖头  "NOR+player->name()+"("+player->query("id")+")"}));
	player->delete_temp("riding");
	player->remove_all_killer();
	biaoche = new(__DIR__"obj/gfbiaoche");
	biaoche->move("/d/beijing/jiaochang");
	biaoche->set_owner(player);
	me->add_temp("biao", 1);
	assign_biaotou(player,player);
	return "镖车就在外面等着你们。你们要小心行事，所谓镖在人在，镖亡人亡，务必在限定的时间内完成任务！";
    default:
	return "现在没有你的任务。";
    }
}

string ask_suicong()
{
    return "随从只有"+HELPER->rank_name(3)+"以上的侍卫才有。\n"+
	"要想领(ling)随从呢，就在我这里。各个门派的都有，你自己挑吧。\n";
}

int do_ling(string menpai)
{
    object player = this_player();
    object me = this_object(), suicong;
    int rank = SHIWEI_LEVEL(player);
    int suicong_num = player->query("suicong_num");
    string cmenpai;

    if (! IS_SHIWEI(player))
	return notify_fail("你先去兵部投军吧。\n");
    if (sync_mizheng(player)) 
	return notify_fail("你重新到米尚书那儿去登记吧。\n");
    if (HELPER->suicong_max(rank) == 0) 
	return notify_fail("你的级别不够领随从的。\n");
    if (suicong_num >= HELPER->suicong_max(rank)) 
	return notify_fail("你已经有"+CHINESE_D->chinese_number(suicong_num)+
		"名随从了。\n");

    if (! menpai || menpai == "")
	return notify_fail("你要领什么门派的随从？\n");

    switch (menpai) {
        case "华山派":
	case "华山":
	    menpai = "huashan";
        case "huashan":
	    cmenpai =  "华山派";
	    break;

        case "峨嵋":
	case "峨嵋派":
	    menpai = "emei";
        case "emei":
	    cmenpai =  "峨嵋派";
	    break;

 	case "武当":
	case "武当派":
	    menpai = "wudang";
        case "wudang":
	    cmenpai =  "武当派";
	    break;

	case "少林":
	case "少林派":
	    menpai = "shaolin";
        case "shaolin":
	    cmenpai =  "少林派";
	    break;

	case "丐帮":
	    menpai = "gaibang";
        case "gaibang":
	    cmenpai =  "丐帮";
	    break;

	case "星宿":
	case "星宿派":
	    menpai = "xingxiu";
        case "xingxiu":
	    cmenpai =  "星宿";
	    break;

	case "雪山":
	case "雪山派":
	case "血刀":
	case "血刀门":
	    menpai = "xueshan";
        case "xueshan":
	    cmenpai =  "雪山派";
	    break;

  	case "桃花":
	case "桃花岛":
	    menpai = "taohua";
        case "taohua":
	    cmenpai =  "桃花岛";
	    break;

	case "白驼":
	case "白驼山庄":
	    menpai = "baituo";
        case "baituo":
	    cmenpai =  "白驼山庄";
	    break;

	case "古墓":
	case "古墓派":
	    menpai = "gumu";
        case "gumu":
	    cmenpai =  "古墓派";
	    break;

	case "灵鹫":
	case "灵鹫宫":
	    menpai = "lingjiu";
        case "lingjiu":
	    cmenpai =  "灵鹫宫";
	    break;

        case "大理":
	case "大理段氏":
	case "dali":
	    return notify_fail("大理段氏的家臣怎么会来京城当随从呢？\n");

  	case "神龙":
	case "神龙教":
	case "shenlong":
	    return notify_fail("神龙教众官府见了就捉拿。你没搞错吧？\n");

        default:
                return notify_fail("你要领什么门派的随从侍卫？\n");
                break;
        }
    suicong_num ++;
    player->set("suicong_num", suicong_num);
    suicong = new("/clone/npc/suicong.c");
    suicong->new_master(player, suicong_num, menpai);
    suicong->move(environment(player));
    suicong->set_leader(player);
    player->save();
    message_vision("$N对$n说道，下官想要一名"+cmenpai+"的随从。\n",
		player, me);
    message_vision("$N拍了拍$n的肩膀，笑道，好好，没问题，来人啊。\n", 
		me, player);
    message_vision("$N快步走了过来，向$n行礼道：老爷金安。\n",
		suicong, player);
    return 1;
}

private int is_suitable(object victim, object killer)
{
	string *no_kill_list = ({
	"mu ren",
	"huang zhen",
	"juexin dashi",
	"fighter dummy",
	"du e",
	"du nan",
	"du jie",
	"xie yanke",
	"ren woxing",
	"qu san",
	"yue buqun",
	"qiu chuji",
	"zhang sanfeng",
	"zuo lengchan",
	"ouyang zhan",
	"seng bing",
	"ma guangzuo",
	"black gargoyle",
	"white gargoyle",
	"tang nan",
	"zhu xi",
	"tangzi shou",
	"lao chaofeng",
	"hua tiegan",
	"yideng dashi",
	"lu tianshu",
	"liu chengfeng",
	"qu san",
	"zhao zhijing",
	"lu youjiao",
	"cheng buyou",
	"lin zhennan",
	"hong qigong",
	"master",
	"xun bu",
	"dongfang bubai",
	"du laoban",
	"ling tuisi",
	"zhao liangdong",
	"guai she",
	"duo long",
	"mi zheng",
	"liu haoyi",
	"rysj shizhe",
	"yang guo",
	});
	if(  !victim || !clonep(victim) || !living(victim) || userp(victim)
		|| victim->query("race") != "人类"
		|| victim->query("shen") < 0
		|| victim->query("winner")
		|| strsrch(base_name(victim), "/kunfu/skill/") != -1
		|| strsrch(base_name(victim), "/clone/") != -1
		|| strsrch(base_name(victim), "/u/") != -1
		|| strsrch(base_name(victim), "/d/xiakedao/") != -1
		|| victim->query("combat_exp") < killer->query("combat_exp") * 1/4
		|| victim->query("combat_exp") > killer->query("combat_exp")*7/4
		|| victim->query("family/family_name") == "桃花岛"
		|| member_array(victim->query("id"), no_kill_list) != -1 || random(2)==0 )
	{
		return 0;
	}
	return 1;
}

void do_leave(object ob)
{
	if( objectp(ob) )
	{
		if( ob->is_busy() || ob->is_fighting())
		{
			message_vision("$N向后一跳，跳出战圈！\n",ob);
			message_vision("$N说道：风紧，扯呼！我回去报信求援，\n你们坚守就是胜利，千万不要堕了皇上的英名！\n",ob);
		}
		if(!living(ob))ob->revive(0);
		message_vision("$N急急忙忙离开了。\n",ob);
		destruct(ob);
	}
}

void setup_skill(object me,object obj)
{
	mapping skills;
	string *names;
	int level,i;

	if(!objectp(me) || !objectp(obj) ) return;
	if( obj->query("combat_exp") < me->query("combat_exp") )
	{
		obj->set("combat_exp", me->query("combat_exp") /100  * ( 100+random(50) )  );
	}
	level = pow( obj->query("combat_exp")*10.,0.33333 );
	if(level < 10) level = 10;
	if( obj->query("combat_exp") < 4000 )
	{
		level = level/2 + random(level/2);
	}
	else if( obj->query("combat_exp") < 30000)
	{
		level = level/2 + random(level/3);
	}
	else if( obj->query("combat_exp") < 60000)
	{
		level = level/2 + random(level/4);
	}
	else if( obj->query("combat_exp") < 300000)
	{
		level = level/2 + random(level/5);
	}
	else level = level/3 + random(level/6);
	skills = obj->query_skills();
	names = keys(skills);
	for (i=0; i<sizeof(names); i++)
	{
		obj->set_skill(names[i], level);
	}
	obj->set( "title", "御林军" );
	obj->delete( "nickname");
	obj->delete( "long");
	obj->delete( "family");
	obj->delete( "name" );
	obj->delete( "short" );
	if( obj->query("combat_exp") < 500000 ) obj->set_name("亲兵", ({ "qin bing", "bing" }));
	else obj->set_name("戴刀侍卫", ({ "shi wei", "shi", "wei" }));
	call_out("do_leave",1000,obj);
}

void assign_biaotou(object me, object partner)
{
	object ob,here;
	object *target_list;
	int i;

	if( !userp(me) ) return;
	here = environment(me);
	if(!here) return;
	if( strsrch(base_name(here), "/d/") == -1 ) return;
	target_list = filter_array(livings(), "is_suitable", this_object(), me);
	if( sizeof(target_list) == 0 )
	{
		// try again in 5 secs.
		call_out("assign_biaotou", 5, me,partner);
		return;
	}
	do
	{
		i = random(sizeof(target_list));
		ob=new( base_name(target_list[i]) + ".c" );
	}
	while( !living(ob) );
	ob->move(here);
	setup_skill(me,ob);
	ob->set_temp("biao/owner",me->query("id") );
	if(partner)ob->set_temp("biao/owner2",partner->query("id") );
	ob->set_leader(me);
	message_vision("\n$N快步走了过来!\n", ob);
	message_vision("\n$N对$n抱拳道：“"+RANK_D->query_respect(me)+"，多总管派小人跟您一道保这道镖。\n大人您有话尽量吩咐，小人尽力而为。“\n\n", ob,me);
}

string ask_abandon()
{
	object ob = this_player(), me = this_object();
	int penalty;

	if( !ob->query("biao") ) return "你又没有任务，放弃什么？\n";
	command("angry");
	command("faint "+ob->query("id") );
	ob->delete("biao");
	if(ob->query_condition("biaoju")) ob->clear_one_condition("biaoju");
	penalty = ( 1 + ob->query("biaoju/fail") * 10 / ( 1+ ob->query("biaoju/succeed") ) ) * ( 30+random(30) );
	ob->apply_condition( "biao", penalty );
	ob->add("biaoju/fail",1);
	ob->delete_temp("apply/name");
	ob->delete_temp("apply/long");
	ob->delete_temp("apply/short");
	ob->delete_temp("apply/id");
	ob->remove_all_killer();
	return "你居然把朝廷的重镖丢了，给我滚开！\n";
}

private int is_suitable_rob(object victim, object killer)
{
	if(  !userp(victim)
		|| victim->query("race") != "人类"
		|| victim->query("shen") > 0
		|| victim->query("xbiao/dest2") == 0
		|| strsrch(base_name(victim), "/u/") != -1
		|| strsrch(base_name(victim), "/d/xiakedao/") != -1
		|| victim->query("combat_exp") < killer->query("combat_exp") * 4/5
		|| victim->query("combat_exp") > killer->query("combat_exp") * 5/4
		|| victim->query_condition("biaoju") < 25)
	{
		return 0;
	}
	return 1;
}

string QueryDest(object obj)
{
	if ( obj->query("xbiao/dest") == "dao baifeng" ) return "大理王妃刀白凤";
	else if ( obj->query("xbiao/dest") == "hu laoye" ) return "北疆小镇巴依";
	else if ( obj->query("xbiao/dest") == "ye erniang" ) return "西夏叶二娘";
	else if ( obj->query("xbiao/dest") == "wu tiande" ) return "成都提督吴天德";
	else if ( obj->query("xbiao/dest") == "shi lang" ) return "泉州靖海侯府";
	else if ( obj->query("xbiao/dest") == "le kexiu" ) return "扬州水陆提督李克秀";
	else if ( obj->query("xbiao/dest") == "liu haoyi" ) return "成都子爵刘好弈";
	return "神秘地带";
}
#include "/d/beijing/autok.h"

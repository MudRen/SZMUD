// Code of ShenZhou
// dali bandit 2, middle level

#include <ansi.h>
#include <room.h>

inherit NPC;
string ask_me();

void create()
{
	int i;
	i=random(4)+1;
	switch (random(5)) {
	case 0 :
		set_name("山贼", ({"shan zei", "zei"}));
		break;
	case 1 :
		set_name("土匪", ({"tu fei", "fei"}));
		break;
	case 2 :
		set_name("草寇", ({"cao kou", "kou"}));
		break;
	case 3 :
		set_name("流氓头", ({"liumang tou", "tou"}));
		break;
	case 4 :
		set_name("强盗", ({"qiang dao", "dao"}));
		break;
	}
	switch (i) {
	case 1 :
		set("title", "西域少林恶僧");
		set("long", "这家伙是西域少林派传人，经常行走江湖，为非作歹。\n他练有一身横练功夫。\n");
		break;
//	case 2 :
//		set("title", "华山派弃徒");
//		set("long", "此人曾经是岳不群门下弟子，却经常在华山村为非作歹，被逐出门墙，跑到大理来落草为寇。\n他学了一身华山功夫，身手不错。\n");
//		break;
	case 2 :
		set("title", "武当派叛徒");
		set("long", "他曾经是武当七侠之一的门徒，后来叛变师门出逃，在江湖上干些打家劫舍的勾当。\n他看起来功夫火候不浅。\n");
		break;
	case 3 :
		set("title", "雪山派喇嘛");
		set("long", "他是大轮寺的喇嘛，既贪财又好色，经常下山来劫掠一些东西回寺享用。\n他看起来有些真功夫。\n");
		break;
	case 4 :
		set("title", "五毒教香主");
		set("long", "此贼最近混上了五毒教一个分堂的香主，经常带些打手在附近行凶，为五毒教收罗资材。\n他身强力壮膀大腰圆，不容易对付。\n");
		break;
	}

	set("gender", "男性");
	set("age", 25+random(10));
	set("attitude", "heroism");
	set("str", 20+random(10));
	set("int", 12+random(10));
	set("con", 17+random(10));
	set("dex", 22+random(10));
	set("dalibandit",1);
	set("inquiry", ([
            "大理国" : (: ask_me :),
        ]));
	set("shen_type", -1);

	set("chat_chance", 15);
	set("chat_msg", ({
		(: random_move :),
	}));

	setup();
	
	carry_object("/d/city/obj/tiejia.c")->wear();
}

void init()
{
	object who=this_player(), me=this_object();

	if (interactive(who)) set_heart_beat(1);

	if (who->query("dalivictim") && !me->is_fighting() && random(3)==2) {
		remove_call_out("killvictim");
		call_out("killvictim", 1, me, who);
	}
}
string ask_me()
{
                object me, who;

                who = this_object();
                me = this_player();
                if (who->query("owner") == me->query("id"))
                {
         command ("heihei");
                                
                                return "这里就是大理国，是个好地方！";
                }

                command ("en");

                return "这里就是大理国。";    
}


void killvictim(object me, object who)
{
	if (present(who, environment(me))) {
		if (who->query("race")=="人类" && who->query("age")<15) {
			command("grin "+who->query("id"));
			message_vision("$N恶狠狠地对$n叫道：大爷今天不高兴，先拿你的小命儿来祭祭刀！  $N看来想杀死$n！\n", me, who);
			kill_ob(who);
			return;
		}
		if (who->query("gender")=="女性" && who->query("age")<30) {
			command("flirt "+who->query("id"));
			message_vision("$N上前调戏$n，$n却奋力挣扎不从。$N勃然大怒，看来想杀死$n！\n", me, who);
			kill_ob(who);
			return;
		}
		else {
			if (who->query("race")!="人类") {
				command("grin "+who->query("id"));
				message_vision("$N乐道：“老子的肚子正咕咕叫呢，有野味送上门来。”  $N想把$n杀了吃掉。\n", me, who);
				kill_ob(who);
				return;
			}
			else {
				message_vision("$N奸笑着地对$n说：“"+RANK_D->query_rude(who)+"赶快金银珠宝交出来，大爷再放你过几天好日子。”\n", me, who);
				message_vision("$n迟疑不给，$N便阴笑着吼道：“"+RANK_D->query_rude(who)+"敬酒不吃吃罚酒，钱命我一起拿！”  看来$N想杀死$n！\n", me, who);
				kill_ob(who);
				return;
			}
		}
	}
	return;
}

int random_move()
{
	mapping exits, doors;
	string *dirs, dir;
	object me=this_object();

	if (is_fighting() || is_busy() || !living(me))
		return 0;

	if (!me->query("steps")) {
		remove_call_out("destroying");
		call_out("destroying",1200,me);
	}

	if (me->query("steps")>=30) {
		remove_call_out("destroying");
		call_out("destroying",1,me);
		return 0;
	}

	me->add("steps",1);

	if (!objectp(environment()) 
		|| !mapp(exits = environment()->query("exits")) 
        || query("jingli") < query("max_jingli") / 2 )
		return 0;

	dirs = keys(exits);

	if (this_object()->query("race") == "人类"
		&& mapp(doors = environment()->query_doors()))
		dirs += keys(doors);

	if (sizeof(dirs) == 0) return 0;
	dir = dirs[random(sizeof(dirs))];

	if (strsrch(environment(me)->query("exits/"+dir), "/d/dali/minov") == -1)
		return 0;

	if (mapp(doors) && !undefinedp(doors[dir])
		&& (doors[dir]["status"] & DOOR_CLOSED) )
		command("open " + dir);

	command("go " + dir);
	return 1;
}

void destroying(object me)
{
	message_vision("$N不满意地地嘟囔道：“今天怎么什么也没有找到 ... ... 明天带些人手再来吧。”  说罢就急匆匆地走了。\n",me);
	destruct(me);
	return;
}

void unconcious()
{
	object ob, me=this_object();

	if (objectp(ob = me->query_temp("last_damage_from"))
		&& ob->query_temp("marks/arrestee") != me->query("name"))
		me->set("wrong_fainted", 1);

	::unconcious();
}

void die()
{
	object ob, me=this_object();

	if (objectp(ob=me->query_temp("last_damage_from"))
		&& me->query("combat_exp")>ob->query("combat_exp")*2)
		ob->add("dali/trust", 1);

	::die();
}

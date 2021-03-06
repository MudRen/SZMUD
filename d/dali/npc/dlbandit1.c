// Code of ShenZhou
// dali bandit 1, low level

#include <ansi.h>
#include <room.h>

inherit NPC;
string ask_me();

void create()
{
	int i;
	i=random(5)+1;
	switch (random(5)) {
	case 0 :
		set_name("小贼", ({"xiao zei", "zei"}));
		break;
	case 1 :
		set_name("地痞", ({"di pi", "pi"}));
		break;
	case 2 :
		set_name("恶霸", ({"e ba", "ba"}));
		break;
	case 3 :
		set_name("流氓", ({"liu mang", "liu"}));
		break;
	case 4 :
		set_name("无赖", ({"wu lai", "lai"}));
		break;
	}
	switch (i) {
	case 1 :
		set("title", "星宿派拍马手");
		set("long", "这家伙在星宿派作过几天溜须拍马的事儿，也多少学了些功夫，回到乡里就为非作歹。\n他看起来功夫低微。\n");
		break;
//	case 2 :
//		set("title", "华山派弃徒");
//		set("long", "此人曾经拜在华山门下学艺，因为行为不轨被逐出门墙，在地方上终日鬼混，打架斗殴。\n他看起来虽然有两斤力气，功夫却不怎么样。\n");
//		break;
	case 2 :
		set("title", "武当派叛徒");
		set("long", "他曾经是武当派的低辈弟子，某次随师傅下山遭遇仇敌，卖师保命，此后再也不敢回武当，凭着一点功夫在江湖上厮混。\n他看起来功夫颇差劲。\n");
		break;
	case 3 :
		set("title", "雪山派小喇嘛");
		set("long", "他是新近才入大轮寺的小喇嘛，经常从雪山上下来，到大理边境的山村偷鸡摸狗。\n他还没有学到多少功夫。\n");
		break;
	case 4 :
		set("title", "丐帮恶贼");
		set("long", "这人一身乞丐打扮，其实早已因为恶迹被丐帮开除，在北方混不下去了，跑到南边来作恶。\n他除了厮打凶狠，没有多少真才实学。\n");
		break;
	case 5 :
		set("title", "五毒教打手");
		set("long", "五毒教总部在大理，自然要网罗爪牙培养势力，此人是地方上有名的恶棍，被收作打手。\n他虽然没学过多少功夫，身手倒是蛮矫健的。\n");
		break;
	}

	set("gender", "男性");
	set("age", 20+random(10));
	set("attitude", "heroism");
	set("str", 20+random(10));
	set("int", 10+random(10));
	set("con", 15+random(10));
	set("dex", 20+random(10));
	set("dalibandit",1);
	set("shen_type", -1);
	set("inquiry", ([
            "大理国" : (: ask_me :),
        ]));
    set("chat_chance", 15);
	set("chat_msg", ({
		(: random_move :),
	}));

	setup();
	
	carry_object("/d/city/obj/beixin")->wear();
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
				message_vision("$N恶狠狠地对$n嚷道：“"+RANK_D->query_rude(who)+"有什么值钱的东西，赶快拿出来孝敬老子。”\n", me, who);
				message_vision("$n稍微迟疑不给，$N便勃然大怒，道：“"+RANK_D->query_rude(who)+"敢不给？”  看来$N想杀死$n！\n", me, who);
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
	message_vision("$N悻悻地自言自语道：“今天真倒霉，出来一大圈什么也没弄到。”  说罢就急匆匆地走了。\n",me);
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

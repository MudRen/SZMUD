// Code of ShenZhou
// dali bandit 3, middle level

#include <ansi.h>
#include <room.h>

inherit NPC;
string ask_me();

void create()
{
	int i;
	i=random(4)+1;
	switch (i) {
	case 1 :
		set_name("一品堂杀手", ({"sha shou", "killer"}));
		set("title", "西域少林高僧");
		set("long", "这家伙是西域少林派高人，被西夏官府收买后专门到南方武林杀人作恶。\n他内外兼修，功力深厚。\n");
		break;
	case 2 :
		set_name("土匪头", ({"tufei tou", "tou"}));
		set("title", "武当派叛徒");
		set("long", "此人身份不明，却练有一身高深的武当功夫，多年前来到附近某个山头落草为寇作了土匪头子，长期在此作恶。\n他精通武当功夫，身手高强。\n");
		break;
//	case 3 :
//		set_name("山大王", ({"shan daiwang", "daiwang", "wang"}));
//		set("title", "华山派弃徒");
//		set("long", "此人曾经是岳不群亲传弟子，却不知如何某日反出师门，和一班狐朋狗友到此占山为王，为祸乡里。\n他的华山武技已达炉火纯青。\n");
//		break;
	case 3 :
		set_name("独行盗", ({"duxing dao", "dao"}));
		set("title", "雪山派喇嘛");
		set("long", "他据说是血刀老祖的嫡传弟子，在江湖上干惯了独行盗，既偷又抢，无恶不作。\n他太阳穴高高凸起，内功精湛。\n");
		break;
	case 4 :
		set_name("五毒教堂主", ({"tang zhu", "zhu"}));
		set("title", "五毒教堂主");
		set("long", "此贼是五毒教直属四大分堂之一的堂主，偶尔也亲自出马到村镇里行凶抢劫。\n他身手不凡，毒技高超，算得上江湖高手。\n");
		break;
	}

	set("gender", "男性");
	set("age", 35+random(10));
	set("attitude", "heroism");
	set("str", 20+random(10));
	set("int", 15+random(10));
	set("con", 20+random(10));
	set("dex", 25+random(10));
	set("dalibandit",1);
	set("inquiry", ([
            "大理国" : (: ask_me :),
        ]));
	set("shen_type", -1);

	set("chat_chance", 20);
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
				message_vision("$N冷笑着地对$n说：“老子我亲自出马，"+RANK_D->query_rude(who)+"还不乖乖地赶快金银珠宝交出来？\n", me, who);
				message_vision("$n迟疑不给，$N便阴笑着吼道：“"+RANK_D->query_rude(who)+"找死，今天老子要杀个鸡犬不留！”  看来$N想杀死$n！\n", me, who);
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
	message_vision("$N不满意地地嚷嚷道：“他妈的，今天真不走运！这么一大趟居然什么也没弄到。”  说罢就急匆匆地走了。\n",me);
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

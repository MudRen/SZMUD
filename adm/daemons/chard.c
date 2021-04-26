// Code of ShenZhou
// chard.c
// From ES2
// Modified by Xiang@XKX
// Modified by Cleansword@XKX
// Modified by qfy@xkx
// Modified by ryu@xkx

#define HUMAN_RACE "/adm/daemons/race/human"
#define MONSTER_RACE "/adm/daemons/race/monster"
#define BEAST_RACE "/adm/daemons/race/beast"
#define STOCK_RACE "/adm/daemons/race/stock"
#define BIRD_RACE "/adm/daemons/race/bird"
#define FISH_RACE "/adm/daemons/race/fish"
#define SNAKE_RACE "/adm/daemons/race/snake"
#define INSECT_RACE "/adm/daemons/race/insect"

#include <ansi.h>

void create() { seteuid(getuid()); }

void setup_char(object ob)
{
	string race;
	mapping my;
	int lvl, exper;

        if( !stringp(race = ob->query("race")) ) {
                race = "����";
                ob->set("race", "����");
        }

        switch(race) {
                case "����":
                        HUMAN_RACE->setup_human(ob);
                        break;
                case "��ħ":
                        MONSTER_RACE->setup_monster(ob);
                        break;
                case "Ұ��":
                        BEAST_RACE->setup_beast(ob);
                        break;
                case "����":
                        STOCK_RACE->setup_stock(ob);
                        break;
                case "����":
                        BIRD_RACE->setup_bird(ob);
                        break;
                case "����":
                        FISH_RACE->setup_fish(ob);
                        break;
                case "����":
                        SNAKE_RACE->setup_snake(ob);
                        break;
                case "����":
                        INSECT_RACE->setup_insect(ob);
                        break;
                default:
                        error("Chard: undefined race " + race + ".\n");
        }

	my = ob->query_entire_dbase();
	if( undefinedp(my["pighead"]) ) my["pighead"] = 0;

	if( undefinedp(my["jing"]) ) my["jing"] = my["max_jing"];
	if( undefinedp(my["qi"]) ) my["qi"] = my["max_qi"];
	if( undefinedp(my["jingli"]) ) my["jingli"] = my["max_jingli"];

	if( undefinedp(my["eff_jing"]) || my["eff_jing"] > my["max_jing"] ) my["eff_jing"] = my["max_jing"];
	if( undefinedp(my["eff_qi"]) || my["eff_qi"] > my["max_qi"]) my["eff_qi"] = my["max_qi"];
//	if( undefinedp(my["eff_jingli"]) ) my["eff_jingli"] = 0;
	
	if( undefinedp(my["jiajin"]) ) my["jiajin"] = 1;
	exper = to_float(my["combat_exp"]);
	lvl = (ob->query_skill("force") / 2) + ceil( pow( exper*10.0, 0.333333) );
/*
	if (userp(ob) && (int)ob->query_skill("force") > (int)ob->query_skill("force", 1)) 
	{
		if (my["max_neili"] > lvl * (int)ob->query("con") * 2 / 3)
			my["max_neili"] = lvl * (int)ob->query("con") * 2 / 3;
		if (my["neili"] > my["max_neili"])
			my["neili"] = my["max_neili"];
	}
*/

	// avoid excess jingli
	if (userp(ob) && (int)ob->query_skill("force") > (int)ob->query_skill("force", 1)) 
	{
		if (my["max_jingli"] > lvl * (int)ob->query("con")/2)
			my["max_jingli"] = lvl * (int)ob->query("con")/2;
		if (my["jingli"] > my["max_jingli"])
			my["jingli"] = my["max_jingli"];
		if (my["max_jingli"] < 100)
			my["max_jingli"] = 100;
	}

	if ( !userp(ob) && my["max_neili"] && ob->query_skill("force") < 1 )
		ob->set_skill("force", my["max_neili"] / 6);

	if( undefinedp(my["shen_type"]) ) my["shen_type"] = 0;

	if( undefinedp(my["shen"]) ) {
		if (userp(ob))
			my["shen"] = 0;
		else
			my["shen"] = my["shen_type"] * my["combat_exp"] / 10;
	}

	if( undefinedp(my["behavior_exp"]) ) my["behavior_exp"] = my["shen"];
	if( undefinedp(my["quest_exp"]) ) my["quest_exp"] = my["age"] * 10;

	if( !ob->query_max_encumbrance() )
		ob->set_max_encumbrance( my["str"] * 5000 + 
					(ob->query_str() - my["str"]) * 1000);

	ob->reset_action();
}

varargs object make_corpse(object victim, object killer)
{
	int i;
	object corpse, mengzhu,  room, *inv;

	if( victim->is_ghost() ) {
		inv = all_inventory(victim);
		inv->owner_is_killed(killer);
		inv -= ({ 0 });
		i = sizeof(inv);
		while(i--) inv[i]->move(environment(victim));
		return 0;
	}

	corpse = new(CORPSE_OB);
	corpse->set_name( victim->name(1) + "��ʬ��", ({ "corpse" }) );
	corpse->set("long", victim->long()
		+ "Ȼ����" + gender_pronoun(victim->query("gender")) 
		+ "�Ѿ����ˣ�ֻʣ��һ��ʬ�徲�����������\n");
	corpse->set("age", victim->query("age"));
	corpse->set("gender", victim->query("gender"));
	corpse->set("victim_name", victim->name(1));
	corpse->set("combat_exp", victim->query("combat_exp"));
	corpse->set_weight( victim->query_weight() );
	corpse->set_max_encumbrance( victim->query_max_encumbrance() );
	corpse->set("my_killer", victim->query_temp("my_killer"));

//set corpse belong to a player or npc, but exclude mengzhu.
	if(!( room = find_object("/d/taishan/fengchan")) )
        room = load_object("/d/taishan/fengchan");

        seteuid(getuid(victim));
        if( !objectp(mengzhu = present("mengzhu", room)) )
	mengzhu = new("/clone/npc/meng-zhu");
	if (userp(victim) && victim->query("id") != mengzhu->query("winner") ) 
	corpse->set("was_userp", 1);

	corpse->move(environment(victim));
	
	// Don't let wizard left illegal items in their corpses.
	if( !wizardp(victim) ) {
		inv = all_inventory(victim);
		inv->owner_is_killed(killer);
		inv -= ({ 0 });
		i = sizeof(inv);
		while(i--) {
			if( (string)inv[i]->query("equipped")=="worn" ) {
				inv[i]->move(corpse);
				if( !inv[i]->wear() ) inv[i]->move(environment(victim));
			}
			else inv[i]->move(corpse);
		}
	}

	return corpse;
}

int break_relation(object player)
{
	object ob, room;
	string std_id = player->query("id");

	if (player->query("family/family_name") == "��ɽ��" ) {
		if(!( room = find_object("/d/huashan/xiaofang")) )
			room = load_object("/d/huashan/xiaofang");
		ob = present("feng qingyang", room);
		player->delete("family");
		player->set("title","��ͨ����");
		tell_object(player, RED "\n\���ѷǷ�����ĵ����ˣ�����Ϊ֮�ɣ�\n\n" NOR);
		ob->delete( "students/"+std_id );
		ob->set( "pending", std_id );
		ob->save();
		//ob->restore();
	}

	return 1;
}

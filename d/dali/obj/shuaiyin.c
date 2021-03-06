// Code of ShenZhou

// by snowyu 2002/4
#include <ansi.h>

inherit ITEM;
inherit F_SSERVER;
inherit F_CLEAN_UP;
#define SUICONG_D "/d/dali/npc/suicong.c"

int do_jiaodao(string);
int do_lairen(string);
int do_gather();
int do_na(string);
int do_sha(string);
int do_xiuxi(string);

int query_autoload() {return 1;}

void init()
{
    add_action("do_jiaodao", "jiaodao");
    add_action("do_na", "na");
    add_action("do_sha", "sha");
    add_action("do_gather", "gather");
    add_action("do_xiuxi", "xiuxi");
}

void create()
{
    set_name(HIY "大理国兵部帅印" NOR, ({"shuaiyin"}));
    set_weight(500);
	set("no_drop", 1);
    set("no_get", 1);
	set("no_sell", 1);
	if (clonep())
	set_default_object(__FILE__);
    else{
        set("unit", "只");
        set("long", @LONG
这个是大理国兵部帅印，你可以用它统领三军。
用法：
        gather  : 召集所有士兵。
        na      : 命令士兵捉拿反贼。
        sha     : 命令士兵格杀反贼。
        jiaodao : 教导你的士兵，让他们提高实战经验。
        xiuxi   : 让士兵去休息。
LONG
	);
        set("value", 500);
        set("material", "cloth");
    }
    setup();
}


object* find_my_suicongs(string arg, int care_about_task)
{
    object player = this_player();
    object *result, *tmp, *env, target;
    int    i, n;

    if (arg) {	// asking for a specific suicong
        target = present(arg, environment(player));
	if (target->is_character() &&
	    living(target) && 
	    !target->is_busy() &&
	    !target->has_task() &&
	    target->is_suicong_of(player)) {
	    result = allocate(1);
	    result[0] = target;
	    return result;
	}
	return 0;
    }

    // asking for all suicong in this room
    env = all_inventory(environment(player));
    tmp = allocate(sizeof(env));
    n = 0;
    for (i=sizeof(env)-1; i>=0; i--){
 	if (env[i]->is_character() &&
	    living(env[i]) &&
	    !env[i]->is_busy() &&
	    (!care_about_task || !env[i]->has_task()) &&
	    env[i]->is_suicong_of(player)) {
	    tmp[n++] = env[i];
	}
    }
    
    if (n==0) return 0;
    result = allocate(n); // now we know how many suicong there are
    for (i=0; i<n; i++) {
 	result[i] = tmp[i];
    }
    return result;
}

/*
int do_lairen(string arg)
{
    object player = this_player();
    object target, *suicong;
    int    i;

    message_vision("$N大声叫道：来人哪，本候爷的命要不保啦！\n", player);

    suicong = find_my_suicongs(arg, 1);
    if (!suicong) {
	if (arg) return notify_fail("你要招呼谁？\n");
        return notify_fail("这里没有你的士兵能帮你。\n");
    }


    if (player->is_fighting()) {  // join the fight
	target = offensive_target(player) ;

	for (i=0; i<sizeof(suicong); i++){
	    if (target && target != suicong[i]) {
	        message_vision("$N高声应到：属下在！"+
			target->name()+RANK_D->query_rude(target)+
                        "，你是活腻了，敢来伤我大理国侯爷？\n", suicong[i]);
	        suicong[i]->kill_ob(target);
	        target->fight_ob(suicong[i]);
 	    }
	}
    }else{
        for (i=0; i<sizeof(suicong); i++)
	    message_vision("$N打了个哈欠，应到：属下在。\n", suicong[i]);
    }
    return 1;
}
*/
int do_sha(string arg)
{
    object player = this_player();
    object target, *suicong;
    int    i;

    if (!arg)
        return notify_fail("你要让士兵杀谁？\n");

	if( environment(player)->query("no_fight") )
    return notify_fail("这里不准战斗。\n");
	
	target = present(arg, environment(player));
    if (!target)
	return notify_fail("你要杀谁？\n");
    if (!target->is_character())
	return notify_fail(target->name()+"不是活物。\n");
    if (!living(target))
	return notify_fail(target->name()+"都这样了你还要人帮忙？\n");

    if ( userp( target ) && target->query( "combat_exp" ) < player->query( "combat_exp" )*2 )
        return notify_fail( "对手这么弱，不需要帮忙吧？\n" );
    message_vision(HIR "$N大声喝道：来人哪，把"+target->name()+"给我宰了！\n", player);

    suicong = find_my_suicongs(0, 1);
    if (!suicong) {
        return notify_fail("这里没有你的士兵能帮你。\n");
    }

    for (i=0; i<sizeof(suicong); i++){
        if (target && target != suicong[i]) {
	    message_vision("$N高声应到：属下在！"+
	        target->name()+RANK_D->query_rude(target)+
		"，你就去阎王老子那儿玩吧。\n", suicong[i]);
	    suicong[i]->kill_ob(target);
	    target->kill_ob(suicong[i]);
		
	}
    }
    return 1;
}
int do_na(string arg)
{
    object player = this_player();
    object target, *suicong;
    int    i;

    if (!arg)
        return notify_fail("你要让士兵捉拿谁？\n");

    target = present(arg, environment(player));
    if (!target)
	return notify_fail("你要捉拿谁？\n");

	if( environment(player)->query("no_fight") )
    return notify_fail("这里不准战斗。\n");

    if (!target->is_character())
	return notify_fail(target->name()+"不是活物。\n");
    if (!living(target))
	return notify_fail(target->name()+"都这样了你还要人帮忙？\n");
    if( userp( target ) && target->query("combat_exp")<player->query("combat_exp")*2 )
        return notify_fail( "对手这么弱，不需要帮忙吧？      \n" );

    message_vision(HIR "$N大声喝道：来人哪，把"+target->name()+"拿下了！\n", player);

    suicong = find_my_suicongs(0, 1);
    if (!suicong) {
        return notify_fail("这里没有你的士兵能帮你。\n");
    }

    for (i=0; i<sizeof(suicong); i++){
        if (target && target != suicong[i]) {
	    message_vision("$N高声应到：属下在！"+
	        target->name()+RANK_D->query_rude(target)+
		"，你就乖乖的跟我家候爷上衙门走一趟吧。\n", suicong[i]);
	    suicong[i]->fight_ob(target);
	    target->kill_ob(suicong[i]);
	}
    }
    return 1;
}


void fix_skills(object suicong)
{ 
    mapping skill_status;
    int     skill_num, i, slvl, exp;
    string  *sname;

    skill_status = suicong->query_skills();
    exp = suicong->query("combat_exp");

    if (mapp(skill_status)){
	sname = keys(skill_status);
	skill_num = sizeof(skill_status);
	for (i=0; i<skill_num; i++) {
	    slvl = suicong->query_skill(sname[i], 1);
	    if ((slvl+1)*(slvl+1)*(slvl+1) < 10*exp) {
		if ((SKILL_D(sname[i])->check() != "force" && 
		    sname[i] != "force") ||
		    slvl < 200) {
		    suicong->set_skill(sname[i], slvl+1);
		}
 	    }
	}
    }
}


int do_xiuxi(string arg)
{
    object player = this_player();
    object *result, suicong;
    int    i;

    result = find_my_suicongs(arg, 0);
    if (!result) return notify_fail("你要让谁去休息？\n");

    for (i=0; i<sizeof(result); i++){
	suicong = result[i];
	if (suicong->is_fighting() || 
	    suicong->is_busy() ||
	    ! living(suicong))
	    return notify_fail(suicong->query("name")+
		    "现在正忙着，等会儿再休息吧。\n");
	suicong->drop_all_weapon();
	suicong->set("xiuxi_time", player->query("mud_age"));
	suicong->save();
	message_vision("$N离开这里回营休息了。\n", suicong);
	tell_object(player, "好的，让"+suicong->query("name")+
		    "回营休息。\n");
	destruct(suicong);
    }
    return 1;
}

int do_jiaodao(string arg)
{
    object player = this_player();
    object *result, suicong;
    int    jing_cost, exp_inc;

    if (!arg) 
	return notify_fail("你要教导谁？\n");

    result = find_my_suicongs(arg, 1);
    if (!result) return notify_fail("你想教导谁？\n");
    suicong = result[0];

    if (player->is_busy())
        return notify_fail("你正忙着呢，等有空再教导别人吧。\n");
    if (suicong->is_fighting() || player->is_fighting())
        return notify_fail("先把架打完再说吧。\n");
    if ((int)suicong->query("combat_exp") >= (int)player->query("combat_exp"))
        return notify_fail("你想了半天，却没发现有什么可教的。\n");
    if ((int)player->query("potential") <= 0)
        return notify_fail("你的潜能不足，现在不能教导别人。\n");
    
    jing_cost = 2*(40 - (int)player->query("int"));
    exp_inc   = 2*random((int)player->query_int());

    if ((int)player->query("jing") <= jing_cost)
        return notify_fail("你现在太累了，没精神教别人。\n");
    
    // seems fine now, let's act
    player->add("learned_points", 1);    // here, learn is reversed.
    player->add("potential", -1);
    player->receive_damage("jing", jing_cost);
    suicong->add("combat_exp",  exp_inc/2);
    fix_skills(suicong);  // pull up skills to exp limit

    tell_object(player, "你说了些江湖上的见闻，"+suicong->name()+
                "似乎长了些见识。\n");
    return 1;

}


int do_gather()
{
    object me = this_player();
    object suicong, *obs, ob;
    int serial, i, suicong_num;
    int *suicong_ready;

    suicong_num = me->query("suicong_num");
    if (suicong_num <= 0)
        return notify_fail("你没有士兵。\n");

    message_vision("$N拖长了声音道：来人哪。。。\n", me);
    suicong_ready = allocate(suicong_num+1);
    for (i=0; i<suicong_num+1; i++){
        suicong_ready[i] = 0;
    }

    obs = filter_array(children(SUICONG_D), (: clonep :));
    foreach (ob in obs) {
        if ((serial = ob->is_suicong_of(me))){
            suicong_ready[serial] = 1;
	    if (ob->is_busy() ||
	        ob->has_task() ||
	  	ob->is_fighting()) {
		tell_object(me, ob->name()+"派人捎信来说他正忙着公务呢。\n");
	    } else {
		if (environment(me) != environment(ob)){
                    message_vision("$N匆匆忙忙地离开了。\n", ob);
                    ob->move(environment(me));
                    message_vision("$N快步走了过来。\n", ob);
                    ob->set_leader(me);
		}else{
		    message_vision("$N答应道：属下在此。\n", ob);
		}
            }
        }
    }

    for (i=1; i<suicong_num+1; i++){
	if (suicong_ready[i] == 0) {
	    suicong = new(SUICONG_D);
	    suicong->move(environment(me));
	    suicong->reload_suicong(me, i);
	    suicong->set_leader(me);
	    message_vision("$N快步走了过来。\n", suicong);
	}
    }
    return 1;
}

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
    set_name(HIY "���������˧ӡ" NOR, ({"shuaiyin"}));
    set_weight(500);
	set("no_drop", 1);
    set("no_get", 1);
	set("no_sell", 1);
	if (clonep())
	set_default_object(__FILE__);
    else{
        set("unit", "ֻ");
        set("long", @LONG
����Ǵ��������˧ӡ�����������ͳ��������
�÷���
        gather  : �ټ�����ʿ����
        na      : ����ʿ��׽�÷�����
        sha     : ����ʿ����ɱ������
        jiaodao : �̵����ʿ�������������ʵս���顣
        xiuxi   : ��ʿ��ȥ��Ϣ��
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

    message_vision("$N�����е��������ģ�����ү����Ҫ��������\n", player);

    suicong = find_my_suicongs(arg, 1);
    if (!suicong) {
	if (arg) return notify_fail("��Ҫ�к�˭��\n");
        return notify_fail("����û�����ʿ���ܰ��㡣\n");
    }


    if (player->is_fighting()) {  // join the fight
	target = offensive_target(player) ;

	for (i=0; i<sizeof(suicong); i++){
	    if (target && target != suicong[i]) {
	        message_vision("$N����Ӧ���������ڣ�"+
			target->name()+RANK_D->query_rude(target)+
                        "�����ǻ����ˣ��������Ҵ������ү��\n", suicong[i]);
	        suicong[i]->kill_ob(target);
	        target->fight_ob(suicong[i]);
 	    }
	}
    }else{
        for (i=0; i<sizeof(suicong); i++)
	    message_vision("$N���˸���Ƿ��Ӧ���������ڡ�\n", suicong[i]);
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
        return notify_fail("��Ҫ��ʿ��ɱ˭��\n");

	if( environment(player)->query("no_fight") )
    return notify_fail("���ﲻ׼ս����\n");
	
	target = present(arg, environment(player));
    if (!target)
	return notify_fail("��Ҫɱ˭��\n");
    if (!target->is_character())
	return notify_fail(target->name()+"���ǻ��\n");
    if (!living(target))
	return notify_fail(target->name()+"���������㻹Ҫ�˰�æ��\n");

    if ( userp( target ) && target->query( "combat_exp" ) < player->query( "combat_exp" )*2 )
        return notify_fail( "������ô��������Ҫ��æ�ɣ�\n" );
    message_vision(HIR "$N�����ȵ��������ģ���"+target->name()+"�������ˣ�\n", player);

    suicong = find_my_suicongs(0, 1);
    if (!suicong) {
        return notify_fail("����û�����ʿ���ܰ��㡣\n");
    }

    for (i=0; i<sizeof(suicong); i++){
        if (target && target != suicong[i]) {
	    message_vision("$N����Ӧ���������ڣ�"+
	        target->name()+RANK_D->query_rude(target)+
		"�����ȥ���������Ƕ���ɡ�\n", suicong[i]);
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
        return notify_fail("��Ҫ��ʿ��׽��˭��\n");

    target = present(arg, environment(player));
    if (!target)
	return notify_fail("��Ҫ׽��˭��\n");

	if( environment(player)->query("no_fight") )
    return notify_fail("���ﲻ׼ս����\n");

    if (!target->is_character())
	return notify_fail(target->name()+"���ǻ��\n");
    if (!living(target))
	return notify_fail(target->name()+"���������㻹Ҫ�˰�æ��\n");
    if( userp( target ) && target->query("combat_exp")<player->query("combat_exp")*2 )
        return notify_fail( "������ô��������Ҫ��æ�ɣ�      \n" );

    message_vision(HIR "$N�����ȵ��������ģ���"+target->name()+"�����ˣ�\n", player);

    suicong = find_my_suicongs(0, 1);
    if (!suicong) {
        return notify_fail("����û�����ʿ���ܰ��㡣\n");
    }

    for (i=0; i<sizeof(suicong); i++){
        if (target && target != suicong[i]) {
	    message_vision("$N����Ӧ���������ڣ�"+
	        target->name()+RANK_D->query_rude(target)+
		"����͹ԹԵĸ��ҼҺ�ү��������һ�˰ɡ�\n", suicong[i]);
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
    if (!result) return notify_fail("��Ҫ��˭ȥ��Ϣ��\n");

    for (i=0; i<sizeof(result); i++){
	suicong = result[i];
	if (suicong->is_fighting() || 
	    suicong->is_busy() ||
	    ! living(suicong))
	    return notify_fail(suicong->query("name")+
		    "������æ�ţ��Ȼ������Ϣ�ɡ�\n");
	suicong->drop_all_weapon();
	suicong->set("xiuxi_time", player->query("mud_age"));
	suicong->save();
	message_vision("$N�뿪�����Ӫ��Ϣ�ˡ�\n", suicong);
	tell_object(player, "�õģ���"+suicong->query("name")+
		    "��Ӫ��Ϣ��\n");
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
	return notify_fail("��Ҫ�̵�˭��\n");

    result = find_my_suicongs(arg, 1);
    if (!result) return notify_fail("����̵�˭��\n");
    suicong = result[0];

    if (player->is_busy())
        return notify_fail("����æ���أ����п��ٽ̵����˰ɡ�\n");
    if (suicong->is_fighting() || player->is_fighting())
        return notify_fail("�ȰѼܴ�����˵�ɡ�\n");
    if ((int)suicong->query("combat_exp") >= (int)player->query("combat_exp"))
        return notify_fail("�����˰��죬ȴû������ʲô�ɽ̵ġ�\n");
    if ((int)player->query("potential") <= 0)
        return notify_fail("���Ǳ�ܲ��㣬���ڲ��̵ܽ����ˡ�\n");
    
    jing_cost = 2*(40 - (int)player->query("int"));
    exp_inc   = 2*random((int)player->query_int());

    if ((int)player->query("jing") <= jing_cost)
        return notify_fail("������̫���ˣ�û����̱��ˡ�\n");
    
    // seems fine now, let's act
    player->add("learned_points", 1);    // here, learn is reversed.
    player->add("potential", -1);
    player->receive_damage("jing", jing_cost);
    suicong->add("combat_exp",  exp_inc/2);
    fix_skills(suicong);  // pull up skills to exp limit

    tell_object(player, "��˵��Щ�����ϵļ��ţ�"+suicong->name()+
                "�ƺ�����Щ��ʶ��\n");
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
        return notify_fail("��û��ʿ����\n");

    message_vision("$N�ϳ����������������ġ�����\n", me);
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
		tell_object(me, ob->name()+"����������˵����æ�Ź����ء�\n");
	    } else {
		if (environment(me) != environment(ob)){
                    message_vision("$N�Ҵ�ææ���뿪�ˡ�\n", ob);
                    ob->move(environment(me));
                    message_vision("$N�첽���˹�����\n", ob);
                    ob->set_leader(me);
		}else{
		    message_vision("$N��Ӧ���������ڴˡ�\n", ob);
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
	    message_vision("$N�첽���˹�����\n", suicong);
	}
    }
    return 1;
}

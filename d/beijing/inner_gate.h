//Cracked by Roath
// Room: /d/beijing/inner_gate.h

#include "/d/beijing/beijing_defs.h"

string look_gaoshi();
int do_guard();
int gen_killer();
int do_pancha(string id);
void reward_shiwei(int rank, object player);

string look_gaoshi()
{
    return "�����ᶽ�ͣ������ڳǰ���һ��������ݣ�\n" + 
	"�μ�����������˾�����ܲ���ɱ���ۡ�\n";
}

void create()
{
	set("short", GATE_DESC_SHORT);
	set("gate_name", GATE_DESC_SHORT);
	set("is_inner_gate", 1);
	set("long", GATE_DESC_LONG);
	set("exits", GATE_EXITS);

	set("objects", GATE_OBJECTS);

	set("item_desc", ([
	"gaoshi" : (: look_gaoshi :), 
]));
	set("outdoors", "beijing");
	set("cost", 3);
	setup();
	remove_call_out("gen_killer");
	call_out("gen_killer", 10);
}

void init()
{
    object player = this_player(), me = this_object();

    add_action("do_guard", "guard");
    add_action("do_pancha", "pancha");
    
    if (! IS_SHIWEI(player)) {
 	player->set_temp("pancha_stage", 1);
	call_out("remove_need_pancha", 5, player);
    }
}

void remove_need_pancha(object player)
{
    if (player->query_temp("pancha_stage") == 1)
	player->delete_temp("need_pancha");
}

void reward_shiwei(int rank, object player)
{
    int kill_num = player->query_temp("kill_num");
    int fail_num = player->query_temp("fail_num");

    message_vision("���ŵ����������£�$N�Ļ���ʱ�䵽�ˡ�\n", player);
    player->delete_temp("start_job_time");
    player->delete_temp("can_pancha");
    player->delete_temp("fail_num");
    player->delete_temp("kill_num");
    HELPER->job_reward (player, rank, kill_num, fail_num);
}

void gen_killer()
{
    object env = this_object();
    object *killers ;
    object *inv, killer;
    int    i, shiwei_present = 0;

    remove_call_out("gen_killer");
    call_out("gen_killer", 10);

    killers = HELPER->obj_in_env("/d/beijing/npc/killer2.c", env);
    inv = all_inventory(env);
    for (i=sizeof(inv)-1; i>=0; i--) {
        if (userp(inv[i]) && living(inv[i]) && 
	    IS_SHIWEI(inv[i]) && inv[i]->query_temp("can_pancha")){
	    if (HELPER->is_night_shift()) {
		if (SHIWEI_LEVEL(inv[i]) == 2) {	
		    reward_shiwei(2, inv[i]);
		}else{
		    shiwei_present++;
		}
	    } else {
		if (SHIWEI_LEVEL(inv[i]) == 3) {
		    reward_shiwei(3, inv[i]);
		}else{
		    shiwei_present++;
		}
	    }
        }
    }

    if (shiwei_present == 0) return;

    if (HELPER->is_night_shift()) {
	if (killers) return;
	killer = new("/d/beijing/npc/killer2.c");
	killer->move(env);
	killer->upgrade(3);
	message_vision("$N�첽���˹�����\n", killer);
    }else {
	if (killers) return;
	killer = new("/d/beijing/npc/killer2.c");
	killer->move(env);
	message_vision("$N�첽���˹�����\n", killer);
    }
    return;
}

int do_guard()
{
    object player = this_player();
    if (! IS_SHIWEI(player)) return 0;

    if (SHIWEI_LEVEL(player) > 3)
        return notify_fail("���Ѿ������س�������\n");
    if (player->query_temp("can_pancha"))
	return notify_fail("���Ѿ��������ˡ�\n");

    if (!player->query_temp("current_job"))
	return notify_fail("�����ȥ���ʶ���ˣ������ֵ��ĵط����Ƕ���\n");
    if (player->query_temp("current_job") != query("gate_name"))
 	return notify_fail("���ﲻ����Ҫ�صĵط�����ȥ"+
	    player->query_temp("current_job")+"�ɡ�\n");
    if (SHIWEI_LEVEL(player) == 2 && HELPER->is_sunrise() != 0) {
	player->delete_temp("current_job");
	return notify_fail("��ʱ�ѹ���������ţ�����Ͳ��������ˣ�\n");
    }

    if (SHIWEI_LEVEL(player) == 3 && HELPER->is_sunset() != 0) {
	player->delete_temp("current_job");
	return notify_fail("��ʱ�ѹ���������ţ�����Ͳ��������ˣ�\n");
    }

    player->delete_temp("current_job");
    player->set_temp("start_job_time", time());
    player->set_temp("can_pancha", 1);
    player->set_temp("fail_num", 0);
    player->set_temp("kill_num", 0);
    message_vision(
	"$Nһ�����������ԵĹٱ��������쿴������β��ʹ������ˡ�\n", 
	player);
    tell_object(player, "������̲� (pancha) �������ˡ�\n");
    return 1;
}

void reply_pancha(object obj, object shiwei)
{
    int exp = obj->query("combat_exp");
    int min_exp = 150000;

    if (exp < 50000) obj->set_temp("pancha_stage", 4);
    if (HELPER->is_night_shift()) min_exp = min_exp * 2;
    if (random(exp) > min_exp) obj->set_temp("pancha_stage", 4);

    if (exp < 50000 && obj->query_temp("pancha_stage")==4){
	message_vision("$N���������С�˽��ǹ۹⣬����˸�̧���֡�\n", obj);
	message_vision("$NЦ�����ðɣ�������ɡ�\n", shiwei);
	return;
    }
    if (obj->query_temp("pancha_stage")==4){
	message_vision("$N����������й�����������˷��С�\n", obj);
	message_vision("$N�������ң��롣\n", shiwei);
	return;
    }

    if (exp < 400000) {
	message_vision("$N�ٺٺ�Ц������������С������Ǹɵ㹴����\n", obj);
	message_vision("$Nһ�Բ�������Ȼ��$n���ѡ�\n", obj, shiwei);
    } else  {
	message_vision("$N��Ц��������������ܵ���ô��\n", obj);
	message_vision("$N���һ�������������õ���\n", obj);
    }
    obj->set_temp("pancha_stage", 3);
    obj->kill_ob(shiwei);
    shiwei->kill_ob(obj);
}

int do_pancha(string name)
{
    object me = this_player(), obj;
    
    if (! me->query_temp("can_pancha"))
	return 0;

    if (! name || name=="" )
        return notify_fail("�����̲�˭��\n");
    
    if (!objectp(obj = present(name, environment(me))))
         return notify_fail("����û������ˡ�\n");

    if (!obj->is_character() || obj->is_corpse())
         return notify_fail("������㣬�ⲻ�ǻ��ˡ�\n");

    if (!living(obj))
	return notify_fail("����������˵�ɡ�\n");

    message_vision("$N����$n�������ۣ������̵�˵������ʲô��ѽ��\n",
        me, obj);
    obj->set_temp("pancha_stage", 2);
    remove_call_out("reply_pancha");
    call_out("reply_pancha", 2, obj, me);
    return 1;
}

int valid_leave(object me, string dir)
{
    object *inv;
    int i, stage, fail_num, shiwei_present=0;
    
    if (IS_SHIWEI(me) && me->query_temp("can_pancha"))
	return notify_fail("�㻹û������ŵ������أ���ô���뿪��\n");

    stage=query_temp("pancha_stage");
    switch (stage) {
    case 2:	// shiwei is pancha me, waiting for me to reply
	return notify_fail("�������������̲����ء�\n");

    case 1: 	// we need to wait for shiwei to pancha us
    case 3:     // we are killing shiwei
	// find all shiwei present
	inv = all_inventory(environment(me));
	for (i=sizeof(inv)-1; i>=0; i--) {
	    if (userp(inv[i]) && living(inv[i]) && 
		inv[i]->query_temp("can_pancha") &&
		IS_SHIWEI(inv[i]) ) {	// found a shiwei
		if (stage==1){  	// can't leave yet
		    return notify_fail(inv[i]->query("name")+
			    "ָ��ָ�������Ȼ�����һ��ò�����ء�\n");
		}
		fail_num = inv[i]->query_temp("fail_num");
		inv[i]->set_temp("fail_num", fail_num+1);
	    }
	}
	if (stage == 3) { // escaped
	    message_vision("$N���������ǲ�ע�⣬���ˣ�\n", me);
	}
	me->delete_temp("pancha_stage");
	return ::valid_leave(me, dir);
    case 0:	// ok, we can leave now
    default:
	return ::valid_leave(me, dir);
    }
}



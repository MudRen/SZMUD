// Code of ShenZhou

#include <ansi.h>

#ifndef NPCDATA
#define NPCDATA "/data/npc/"
#endif
#include "/d/beijing/beijing_defs.h"
 
#define CISHA_ROUND_LENGTH 500

inherit NPC;
inherit F_SAVE;
inherit F_SSERVER;

int auto_perform();
void get_random_name();
int is_suicong_of(object player);
void set_menpai(string menpai);
string answer_inqiry(string question);
int reload_suicong(object player, int serial);
void goto_cisha_target();
void kill_cisha_target();
void check_cisha_result();
void check_cisha_status();

void create()
{
	int force;
	seteuid(getuid());

	get_random_name();

        set("long", 
        "����һ�����Ĺ�������ӡ�\n");
        set("gender", "����");
        set("age", 34);
        set("attitude", "heroism");
        set("shen_type", 0);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
	force = 150;
	set("max_neili", force*10);
	set("neili", force*10);
	set("max_jingli", force*8);
	set("jingli", force*8);
	set("max_qi", force*8);
	set("max_jing", force*6);
	set("eff_jing", force*6);
	set("eff_jing", force*6);
	set("jing", force*6);
	set("eff_qi", force*8);
	set("qi", force*8);
        
        set("jiali", 50);
        set("combat_exp", 100000);

	set("chat_chance_combat", 50);

        setup();
        carry_object("/d/beijing/obj/junfu")->wear();
}

void init()
{
    save();
}


int has_task()
{
    return query_temp("cisha_task");
}

void start_cisha(string target)
{
    object me = this_object();

    me->set_temp("cisha_task", 1);
    me->set_temp("cisha_target_id", target);
    me->set_leader(0);

    me->set("cisha_result", "fail");

    message_vision("$N�ٺٺٵ�Ц�˼�����\n", me);
    remove_call_out("check_cisha_status");
    call_out("check_cisha_status", CISHA_ROUND_LENGTH);

    remove_call_out("goto_cisha_target");
    call_out("goto_cisha_target", 5);
}

void goto_cisha_target()
{
    object me = this_object();
    object env;
    object target;

    if (!me->query_temp("cisha_task")) return;
    
    target = find_player(me->query_temp("cisha_target_id"));
    
    if (!target ||
	!(env = environment(target))){
	HELPER->random_walk();
	call_out("goto_cisha_target", 15);
	return;
    }

    if (target->is_ghost()) {
   	delete_temp("cisha_task");
    	me->set("cisha_result", "succ");
	return;	// finish
    }

    message_vision("$N�����뿪���\n", me);
    me->move(env);
    message_vision("$N�첽���˹�����\n$N��$n����"
	"�Ҽ���үҪ��Ĺ�ͷ���������ɡ�\n",
	me, target);
    me->set_leader(target);
    remove_call_out("kill_cisha_target");
    call_out("kill_cisha_target", 2);
}

void kill_cisha_target()
{
    object me = this_object();
    object target;

    if (!me->query_temp("cisha_task"))  return;
    target = present(me->query_temp("cisha_target_id"), environment(me));
    if (!objectp(target))  return;

    message_vision("$N����$n�ȵ���"+RANK_D->query_rude(target)+
	"�����ղ������������һ\n\n", 
	me, target);
    me->kill_ob(target);
    target->kill_ob(me);
    remove_call_out("check_cisha_result");
    call_out("check_cisha_result", 3);
}

void check_cisha_result()
{
    object me = this_object();
    object target;

    if (!me->query_temp("cisha_task"))  return;
   
    target = find_player(me->query_temp("cisha_target_id"));
    if (!objectp(target)) {
 	return;		// not finish yet, target quit, wait for next round
    }

    if (!me->is_fighting() && target->is_ghost()) {
	// finish job
	me->delete_temp("cisha_task");
    	me->set("cisha_result", "succ");
	return;
    }

    if (environment(target) == environment(me)) {
	if (!me->is_fighting() || !target->is_fighting()){
	    me->kill_ob(target);
	    target->kill_ob(me);
	}
    }
    call_out("check_cisha_result", 3);
    return;
}

void check_cisha_status()
{
    object me = this_object();
    int    round = me->query_temp("cisha_wait_round");

    me->set_temp("cisha_wait_round", round+1);
    if (me->is_fighting()) {
	call_out("check_cisha_status", CISHA_ROUND_LENGTH);
	return;
    }
    if (round < 5 && me->query_temp("cisha_task")) {	// still not done
 	remove_call_out("check_cisha_result");
 	remove_call_out("kill_cisha_target");
 	remove_call_out("goto_cisha_target");
	call_out("goto_cisha_target", 5);
	call_out("check_cisha_status", CISHA_ROUND_LENGTH);
	return;
    } else {
	me->delete_temp("cisha_target");
	message_vision("$N̾�˿�������ҡ��ҡͷ��ת�����ˡ�\n", me);
	me->save();
        destruct(me);
	return;
    }
}

void wield_new_weapon()
{
    object old_weapon = query_temp("weapon");
    object me = this_object();
    object *inv;
    int i;
    string wskill, pskill;
    
    if (old_weapon) {
	/*
	if (old_weapon->is_unique()) {
	    "/cmds/std/drop.c"->do_drop(me, old_weapon);
	}else{
	    destruct(old_weapon);
	}
	*/
	"/cmds/std/drop.c"->do_drop(me, old_weapon);
    }
    inv = all_inventory(me);
    for (i=sizeof(inv)-1; i>=0; i--){
	if (inv[i]->query("weapon_prop")) {
	    "/cmds/std/wield.c"->do_wield(me, inv[i]);
	    wskill = inv[i]->query("skill_type");
	    pskill = me->query_skill_mapped(wskill);
	    if (pskill) {
		map_skill("parry", pskill);
	    }
	    if (inv[i]->is_unique()) {
		me->delete("default_weapon");
	    }else{
		me->set("default_weapon", base_name(inv[i]));
	    }
	    return;
 	}
    }
}

void drop_all_weapon()
{
    object me = this_object();
    object *inv = all_inventory(me);
    object old_weapon = query_temp("weapon");
    int i;
    
    for (i=sizeof(inv)-1; i>=0; i--){
	if (inv[i]->query("weapon_prop")) {
	    if (!me->query("default_weapon") || 
		inv[i] != old_weapon || 
		inv[i]->is_unique()) {
		"/cmds/std/drop.c"->do_drop(me, inv[i]);
	    }
 	}
    }
}

int accept_object(object who, object ob)
{
    object me = this_object();
    int i;

    if (! me->is_suicong_of(who)) return 0;

    // master wants me to switch weapon
    if (ob->query("weapon_prop")) {
	remove_call_out("wield_new_weapon");
	call_out("wield_new_weapon", 1);
	return 1;
    }
    if (ob->query("medicine") &&
	ob->query("name") == "��ҩ") {
	for (i=0; i<10; i++) {
	    if (me->query("eff_qi") < me->query("max_qi")) {
		message_vision("$NС������ذ�һ����ҩ�����˿��ϣ�"
		    "ֻ�����ƴ�Ϊ��ת����ɫ�������ö��ˡ�\n", me);
		me->receive_curing("qi", 50);
		ob->add_amount(-1);
	    }else{
		break;
	    }
	}
	return 1;
    }
    return 0;
}

string answer_inqiry(string ques)
{
    object me = this_object();
    object player = this_player();
    object ob;
    string name, msg, info;

    name = me->query("master");
    switch (ques) {
    case "healme" :
	if (me->is_suicong_of(player)) {
	    command("yun lifeheal "+player->query("id"));
	    return "������";
	}
   	return "�������Ҹ���������";
    case "cisha_result" :
	if (me->is_suicong_of(player)) {
	    if (me->query("cisha_result")=="succ"){
		command("whisper "+name+" �ش��ˣ������Ҳ�������");
	    }else{
		command("whisper "+name+" �ش��ˣ�����û���������");
 	    }
	    return "��л�������ࡣ";
	}else{
	    return "�������ʵ���";
  	}
	break;
    case "unarmed" :
	if (me->is_suicong_of(player)) {
	    remove_call_out("drop_all_weapon");
	    me->delete("default_weapon");
	    call_out("drop_all_weapon", 1);
	    return "������";
	}else{
	    return "�ҵ�ȭ�Ź����Ǻ������ġ�";
	}
	break;
    case "laoye" :
	if (me->is_suicong_of(player)) {
	    return "����������ү����С�ĸ�����ͷ�ˡ�";
	}else{
	    ob = find_player(me->query("master"));
	    if (ob) {
		name = ob->query("name") + "����";
		return "�Ҽ���ү��"+name+"����ô����������";
	    }else{
		return "�������㡣";
	    }
	}
	break;
    case "wugong":
	if (me->is_suicong_of(player)){
	    /*
	    if (me->query("combat_exp") < 100000){
		msg = "����ˡ�С�˹�������˲����١�";
	    }else if (me->query("combat_exp") < 200000){
		msg = "�ش���:С�Ĺ������г�����";
	    }else if (me->query("combat_exp") < 400000){
		msg = "�ش��ˣ����¹��������󳤣�����Ϊ�����š�";
	    }else if (me->query("combat_exp") < 600000){
		msg = "�д��˵ĸ������¹����Ѿ�����¯�����ˡ�";
	    }else if (me->query("combat_exp") < 800000){
		msg = "���ɴ������ࣺ�����������б���������";
	    }else if (me->query("combat_exp") < 1000000){
		msg = "���˶��䣺���µĹ������������������һ�ϸ��¡�";
	    }else {
		msg = "���������������������½��ֵ�ֻ�²����ˡ�";
	    }
	    */
	    msg = "�ش��ˣ�����";
	    info = "���� "+me->query("combat_exp")+" ��"+
		"�书 "+me->query_skill("force", 1)+" ����";
	    command("whisper "+name+" "+msg+info);
	    return "���˿�ǧ��Ϊ�ұ��ܰ���";
	}else{
	    if (player->query("combat_exp") < 100000){
		command("sneer");
		return "ƾ��Ҳ���ʣ�";
	    }else if (player->query("combat_exp") < 400000){
		return "�ҿ���Ҳ�ڽ�����Ҳ�������ͷ�ˣ���ô����ض�������";
	    }else {
		return "������˼���������΢ĩ������ô�������ϵķ��ۣ�";
	    }
	}
	break;
    }
    return "ʲô��";
}


void get_random_name()
{
    mixed lastnamelist=({
    ({"��", "zhao"}), ({"Ǯ", "qian"}),  ({"��", "sun"}),   ({"��", "li"}),    
    ({"��", "zhou"}), ({"��", "wu"}),    ({"֣", "zheng"}), ({"��", "wang"}), 
    ({"��", "feng"}), ({"��", "chen"}),  ({"��", "wei"}),   ({"��", "gao"}),   
    ({"��", "yun"}),  ({"��", "zhang"}), ({"��", "liu"}),   ({"��", "ma"}),
    });

    mixed firstnamelist=({
    ({"��ʤ", "desheng"}),   ({"Ӧ��", "yingbao"}), ({"����", "shengcai"}),
    ({"��ʤ", "yongsheng"}), ({"����", "zhiyong"}), ({"���", "lingjun"}),
    ({"����", "genbao"}),    ({"����", "jinbao"}),  ({"����", "desheng"}),
    ({"����", "yongli"}),    ({"��Т", "chengxiao"}),  ({"����", "guangyi"}),
    ({"��˳", "lishun"}),    ({"��ͥ", "zhongting"}),  ({"����", "qisheng"}),
    });

    string l_c, l_e, f_c, f_e;
    int    i, j;

    i = random(sizeof(lastnamelist));
    j = random(sizeof(firstnamelist));

    l_c = lastnamelist[i][0];
    l_e = lastnamelist[i][1];
    f_c = firstnamelist[j][0];
    f_e = firstnamelist[j][1];

    set_name(l_c+f_c, ({ l_e+ " " + f_e, l_e, }));
    set("id_long", l_e + " " + f_e);
    set("id_short", l_e);
	
}

string query_save_file()
{
    object me = this_object();
    string master = query("master");
    int serial = query("serial");

    if (master){
	return NPCDATA+"suicong/"+master+serial;
    }else{
	return NPCDATA+"suicong/none";
    }
}

void new_master(object player, int serial, string menpai)
{
    set("master", player->query("id"));
    set("serial", serial);
    set_menpai(menpai);

    // TODO: we can set the init status of the
    // suicong according to the status of the player.

    save();	
    reload_suicong(player, serial);
}


int is_suicong_of(object player)
{
    if (player->query("id") == query("master")){
        return query("serial");
    }else{
	return 0;
    }
}

int reload_suicong(object player, int serial)
{
    int force;

    set("master", player->query("id"));
    set("serial", serial);

    restore();    
    set_name(query("name"), ({query("id_long"), query("id_short")}));
    
    force = (int) query_skill("force", 0);
    set("max_neili", force*10);
    set("neili", force*10);
    set("max_jingli", force*8);
    set("jingli", force*8);
    set("max_qi", force*8);
    set("max_jing", force*6);
    set("eff_jing", force*6);
    if ((player->query("mud_age")-query("xiuxi_time")>600) || query("died")){
	set("died", 0);
	set("eff_jing", force*6);
	set("jing", force*6);
	set("eff_qi", force*8);
	set("qi", force*8);
	clear_condition();
    }

    set("title", "�������");
    set("family/family_name", "���־�");

    set("inquiry", ([
	"��ү" : (: answer_inqiry, "laoye" :),
	"master" : (: answer_inqiry, "laoye" :),
	"laoye" : (: answer_inqiry, "laoye" :),
	"�书" : (: answer_inqiry, "wugong" :),
	"����" : (: answer_inqiry, "wugong" :),
	"gongfu" : (: answer_inqiry, "wugong" :),
	"wugong" : (: answer_inqiry, "wugong" :),
	"ȭ��" : (: answer_inqiry, "unarmed" :),
	"unarmed" : (: answer_inqiry, "unarmed" :),
	"barehand" : (: answer_inqiry, "unarmed" :),
	"���" : (: answer_inqiry, "cisha_result" :),
	"result" : (: answer_inqiry, "cisha_result" :),
	"cisha" : (: answer_inqiry, "cisha_result" :),
	"����" : (: answer_inqiry, "healme" :),
	"healme" : (: answer_inqiry, "healme" :),
    ]));
    set("chat_msg_combat", ({ (: auto_perform :) }));

    if (query("default_weapon"))
	carry_object(query("default_weapon"))->wield();
}

int auto_perform()
{
        object me=this_object();
        object weapon=me->query_temp("weapon");
        object opp=me->select_opponent();
	int    i=0, limit;

	if (me->is_busy() ) return 1;

	if (me->query("eff_qi") < me->query("max_qi")-300) {
	    COMMAND_DIR"std/halt"->main(me);
	    while(me->query("neili")>100 && i<20 && 
		(me->query("eff_qi") < me->query("max_qi"))) {
		i++;
		exert_function("heal");
	    }
        }

 	if (me->query("qi") < me->query("eff_qi")/3) {
	    COMMAND_DIR"std/halt"->main(me);
	    exert_function("recover");
	}

 	if (me->query("jingli") < me->query("max_jingli")/2) {
	    COMMAND_DIR"std/halt"->main(me);
	    i=0;
	    while(me->query("neili")>100 && i<20 && 
		(me->query("jingli") < me->query("max_jingli"))) {
		i++;
		exert_function("refresh");
	    }
	}

 	if (me->query("jing") < me->query("max_jing")/2) {
	    COMMAND_DIR"std/halt"->main(me);
	    exert_function("regenerate");
	}
	if (! me->query_temp("nian")) me->set("jiali", 100);
	
	if (!me->is_fighting() && objectp(opp)) me->kill_ob(opp);

	switch (me->query("menpai")){
	case "huashan" :
	    if ( objectp(weapon) ) {
		if ( weapon->query("skill_type") == "sword" )
		    return perform_action("sword.jianzhang");
		if ( weapon->query("skill_type") == "blade" )
		    return perform_action("blade.sanshen");
	    }
	    else {
		map_skill("parry", "pishi-poyu");
		if ( !me->query_temp("leidong") ) {
		    return perform_action("cuff.leidong");
		}
	        if ( !me->query_temp("wuji") && opp->query_condition("hyz_damage") <= 5 ) {
		    return perform_action("strike.wuji");
		}
	    }
	    break;
	case "wudang":
	    if ( objectp(weapon) ) {
		if ( weapon->query("skill_type") == "sword" )
		    return perform_action("sword.chan");
	    }
	    else {
		map_skill("parry", "taiji-quan");
		if ( random(5) == 1) return perform_action("cuff.zhen");
		set("jiali", 0);
		return perform_action("cuff.nian");
	    }
	    break;
	case "emei":
	    if ( objectp(weapon) ) {
		if ( weapon->query("skill_type") == "sword" )
		    return perform_action("sword.mie");
		if ( weapon->query("skill_type") == "blade" )
		    return perform_action("blade.huanying");
	    }else{
		map_skill("parry", "tiangang-zhi");
	    }
	    break;
	case "shaolin":
	    if ( objectp(weapon) ) {
		if ( weapon->query("skill_type") == "sword" && !me->query_temp("sanjue"))
		    return perform_action("sword.sanjue");
		if ( weapon->query("skill_type") == "club" && !me->query_temp("zui-da")) {
		    limit = me->query("con") + me->query("max_neili")/25;
		    me->apply_condition("drunk", limit/2);
		    return perform_action("club.zuida");
		}
	    }
	    else {
		map_skill("parry", "yizhi-chan");
		if (opp && opp->is_busy()) return 1;
		return perform_action("finger.jingmo");
	    }
	    break;
	case "gaibang":
	    if ( objectp(weapon) ) {
		if ( weapon->query("skill_type") == "blade" ) {
	            if (!me->query_temp("shengang")) command("exert shengang");
		    if (!me->query_temp("lianhuan"))
			return perform_action("blade.lianhuan");
		}
	    }else {
		map_skill("parry", "shexing-diaoshou");
	    }
	    break;
	case "taohua":
	    if ( ! query_temp("wuzhuan") ) command("exert wuzhuan");
	    if ( ! objectp(weapon) ) {
		if (random(3) == 1) 
		    return perform_action("strike.kuangfeng");
	    }else {
		map_skill("parry", "luoying-shenjian");
	    }
	    break;
	case "baituo":
	    if ( objectp(weapon) ) {
		if ( weapon->query("skill_type") == "staff" ) {
			return perform_action("staff.shoot");
		}
	    }
	    break;
	case "xueshan":
	    if ( objectp(weapon) ) {
		if ( weapon->query("skill_type") == "blade" ) {
		    if (me->query("eff_qi") > 500 && 
			random(5) == 1) {
			set("shen", -query("combat_exp"));
			perform_action("blade.shendao");
			set("shen", 0);
			return 1;
		    }
		}
	    }else{
		map_skill("parry", "huoyan-dao");
		if (random(5) == 1) {
		    return perform_action("strike.fen");
		}
	    }
	    break;
	default:
	case "xingxiu":
	    break;
	}
	return 1;
}

void die()
{
    object me=this_object();
    mapping skill_status;
    int     skill_num, i, slvl;
    string  *sname;
 
    skill_status = me->query_skills();
 
    if (mapp(skill_status)){
        sname = keys(skill_status);
        skill_num = sizeof(skill_status);
        for (i=0; i<skill_num; i++) {
	    slvl = me->query_skill(sname[i], 1);
	    if (slvl > 0) {
		me->set_skill(sname[i], slvl-1);
            }
        }
    }
	
    me->add("combat_exp", -5000);
    me->set("died", 1);
    save();
    ::die();
}


void set_menpai(string menpai)
{
    set("menpai", menpai);
    set_skill("force", 100);
    set_skill("dodge", 100);
    set_skill("parry", 100);
    set_skill("sword", 100);
    set_skill("blade", 100);
    set_skill("strike", 100);
    set_skill("cuff", 100);
    set_skill("finger", 100);
    set_skill("claw", 100);
    set_skill("club", 100);
    set_skill("kick", 100);
    set_skill("staff", 100);
    set_skill("whip", 100);

    switch (menpai){
    case "huashan":
        set_skill("huashan-jianfa", 100);
        set_skill("liangyi-dao", 100);
        set_skill("huashan-shenfa", 100);
        set_skill("zixia-gong", 100);
	set_skill("pishi-poyu", 100);
	set_skill("hunyuan-zhang", 100);
 
        map_skill("force", "zixia-gong");
        map_skill("dodge", "huashan-shenfa");
        map_skill("parry", "huashan-jianfa");
        map_skill("strike", "hunyuan-zhang");
	map_skill("cuff", "pishi-poyu");
        map_skill("sword", "huashan-jianfa");
        map_skill("blade", "liangyi-dao");
        
        prepare_skill("cuff", "pishi-poyu");
        prepare_skill("strike", "hunyuan-zhang");
	
	set("default_weapon", "/clone/weapon/gangjian");

	break;
    case "emei":
	set_skill("huifeng-jian", 100);
	set_skill("yanxing-dao", 100);
	set_skill("jinding-zhang", 100);
	set_skill("tiangang-zhi", 100);
	set_skill("linji-zhuang", 100);
	set_skill("zhutian-bu", 100);

	map_skill("force", "linji-zhuang");
	map_skill("sword", "huifeng-jian");
	map_skill("blade", "yanxing-dao");
	map_skill("strike", "jinding-zhang");
	map_skill("finger", "tiangang-zhi");
	map_skill("dodge", "zhutian-bu");
	map_skill("parry", "huifeng-jian");

        prepare_skill("finger", "tiangang-zhi");
        prepare_skill("strike", "jinding-zhang");
	set("default_weapon", "/clone/weapon/gangdao");
	break;
    case "wudang":
        set_skill("taiji-shengong", 100);
        set_skill("taiji-jian", 100);
        set_skill("tiyunzong", 100);
	set_skill("taiji-quan", 100);
 
        map_skill("force", "taiji-shengong");
        map_skill("parry", "taiji-jian");
	map_skill("cuff", "taiji-quan");
        map_skill("dodge", "tiyunzong");
        map_skill("sword", "taiji-jian");
        
        prepare_skill("cuff", "taiji-quan");
	set("default_weapon", "/clone/weapon/gangjian");
	break;
    case "shaolin":
        set_skill("damo-jian", 100);
        set_skill("xiuluo-dao", 100);
        set_skill("wuchang-zhang", 100);
        set_skill("zui-gun", 100);
        set_skill("shaolin-shenfa", 100);
        set_skill("hunyuan-yiqi", 100);
	set_skill("yizhi-chan", 100);
	set_skill("banruo-zhang", 100);
 
        map_skill("force", "hunyuan-yiqi");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("parry", "damo-jian");
        map_skill("sword", "damo-jian");
        map_skill("blade", "xiuluo-dao");
        map_skill("club", "zui-gun");
        map_skill("staff", "wuchang-zhang");
        map_skill("finger", "yizhi-chan");
        map_skill("strike", "banruo-zhang");
        
        prepare_skill("finger", "yizhi-chan");
        prepare_skill("strike", "banruo-zhang");
	set("default_weapon", "/clone/weapon/gangjian");
	break;

    case "gaibang":
        set_skill("liuhe-dao", 100);
        set_skill("xiaoyaoyou", 100);
        set_skill("huntian-qigong", 100);
	set_skill("shexing-diaoshou", 100);
 
        map_skill("force", "huntian-qigong");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "liuhe-dao");
        map_skill("blade", "liuhe-dao");
        map_skill("hand", "shexing-diaoshou");
        
        prepare_skill("hand", "shexing-diaoshou");
	set("default_weapon", "/clone/weapon/gangdao");
	break;
    case "baituo":
        set_skill("hamagong", 100);
        set_skill("lingshe-zhang", 100);
	set_skill("chanchubu", 100);
	set_skill("poison", 100);
 
        map_skill("force", "hamagong");
        map_skill("dodge", "chanchubu");
        map_skill("parry", "lingshe-zhang");
        map_skill("strike", "hamagong");
        map_skill("staff", "lingshe-zhang");
        
        prepare_skill("strike", "hamagong");
	set("default_weapon", "/clone/weapon/shezhang");
	break;

    case "taohua":
        set_skill("bitao-xuangong", 100);
        set_skill("canglang-bian", 100);
        set_skill("luoying-shenfa", 100);
	set_skill("luoying-shenjian", 100);
	set_skill("xuanfeng-saoye", 100);
	set_skill("qimen-dunjia", 100);
 
        map_skill("force", "bitao-xuangong");
        map_skill("dodge", "luoying-shenfa");
        map_skill("parry", "canglang-bian");
        map_skill("strike", "luoying-shenjian");
        map_skill("kick", "xuanfeng-saoye");
        map_skill("whip", "canglang-bian");
        
        prepare_skill("strike", "luoying-shenjian");
        prepare_skill("kick", "xuanfeng-saoye");
	set("default_weapon", "/clone/weapon/changbian");
	break;

    case "xueshan":
        set_skill("longxiang-banruo", 100);
        set_skill("xue-dao", 100);
        set_skill("jingang-chu", 100);
	set_skill("huoyan-dao", 100);
	set_skill("xueshitiao", 100);
	set_skill("mingwang-jian", 100);
 
        map_skill("force", "longxiang-banruo");
        map_skill("dodge", "xueshitiao");
        map_skill("parry", "xue-dao");
        map_skill("blade", "xue-dao");
        map_skill("sword", "mingwang-jian");
        map_skill("strike", "huoyan-dao");
        map_skill("staff", "jingang-chu");
        
        prepare_skill("strike", "huoyan-dao");
	set("default_weapon", "/clone/weapon/gangdao");
	break;

    case "xingxiu":
    default:
        set_skill("huagong-dafa", 100);
        set_skill("zhaixinggong", 100);
        set_skill("chousui-zhang", 100);
        set_skill("sanyin-zhua", 100);
        set_skill("tianshan-zhang", 100);
        set_skill("poison", 100);

	map_skill("force", "huagong-dafa");
	map_skill("strike", "chousui-zhang");
	map_skill("claw", "sanyin-zhua");
	map_skill("dodge", "zhaixinggong");
	map_skill("parry", "sanyin-zhua");
	map_skill("staff", "tianshan-zhang");

	prepare_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-zhua");
	set("default_weapon", "/clone/weapon/gangzhang");
	break;
    }
}

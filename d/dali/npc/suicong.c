// Code of ShenZhou

#include <ansi.h>

#ifndef NPCDATA
#define NPCDATA "/data/npc/"
#endif
#define CISHA_ROUND_LENGTH 500
inherit NPC;
inherit F_SAVE;
inherit F_SSERVER;

void get_random_name();
int is_suicong_of(object player);
string answer_inqiry(string question);
int reload_suicong(object player, int serial);
void create()
{
	int force;
	seteuid(getuid());

	get_random_name();

        set("title", "大理国御林军");
        set("family/family_name", "大理段家");
        set("long", 
        "这是一名大理国御林军士兵。\n");
        set("gender", "男性");
        set("age", 34);
        set("attitude", "heroism");
        set("shen_type", 0);
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);
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
	set_skill("force", 100);
	set_skill("buddhism", 100);
    set_skill("dodge", 100);
    set_skill("parry", 100);
    set_skill("sword", 100);
    set_skill("strike", 100);
    set_skill("finger", 100);
    set_skill("staff", 100);
    set_skill("duanjia-jian", 100);
	set_skill("literate", 100);
    set_skill("yiyang-zhi", 100);
    set_skill("qingyan-zhang", 100);
    set_skill("kurong-changong", 100);
	set_skill("duanshi-shenfa", 100);
	map_skill("force", "kurong-changong");
    map_skill("dodge", "duanshi-shenfa");
    map_skill("parry", "yiyang-zhi");
    map_skill("strike", "qingyan-zhang");
	map_skill("finger", "yiyang-zhi");
    map_skill("sword", "duanjia-jian");
    prepare_skill("strike", "qingyan-zhang");
    prepare_skill("finger", "yiyang-zhi");
        
        set("jiali", 50);
        set("combat_exp", 100000);
        setup();
        carry_object("/d/dali/obj/tengjia.c")->wear();
}

void init()
{
    save();
}
void wield_new_weapon()
{
    object old_weapon = query_temp("weapon");
    object me = this_object();
    object *inv;
    int i;
    string wskill, pskill;
    
    if (old_weapon) {
	
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
	ob->query("name") == "金创药") {
	for (i=0; i<10; i++) {
	    if (me->query("eff_qi") < me->query("max_qi")) {
		message_vision("$N小心翼翼地把一包金创药敷在伤口上，"
		    "只觉伤势大为好转，气色看起来好多了。\n", me);
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
	    return "遵命。";
	}
   	return "你配让我给你疗伤吗？";
    case "cisha_result" :
	if (me->is_suicong_of(player)) {
	    if (me->query("cisha_result")=="succ"){
		command("whisper "+name+" 回大人：属下幸不辱命。");
	    }else{
		command("whisper "+name+" 回大人：属下没能完成任务。");
 	    }
	    return "多谢大人栽培。";
	}else{
	    return "这是你问的吗？";
  	}
	break;
    case "unarmed" :
	if (me->is_suicong_of(player)) {
	    remove_call_out("drop_all_weapon");
	    me->delete("default_weapon");
	    call_out("drop_all_weapon", 1);
	    return "遵命。";
	}else{
	    return "我的拳脚功夫是很利害的。";
	}
	break;
    case "laoye" :
	if (me->is_suicong_of(player)) {
	    return "您就是我老爷啊。小的给您磕头了。";
	}else{
	    ob = find_player(me->query("master"));
	    if (ob) {
		name = ob->query("name") + "大人";
		return "我大理国候爷是"+name+"。怎么，不服气？";
	    }else{
		return "不告诉你。";
	    }
	}
	break;
    case "wugong":
	if (me->is_suicong_of(player)){
	    /*
	    if (me->query("combat_exp") < 100000){
		msg = "大人恕罪：小人功夫近来退步不少。";
	    }else if (me->query("combat_exp") < 200000){
		msg = "回大人:小的功夫略有长进。";
	    }else if (me->query("combat_exp") < 400000){
		msg = "回大人，属下功力近来大长，自以为不错呐。";
	    }else if (me->query("combat_exp") < 600000){
		msg = "托大人的福，属下功夫已经练的炉火纯青了。";
	    }else if (me->query("combat_exp") < 800000){
		msg = "承蒙大人栽培：属下在武林中薄有虚名。";
	    }else if (me->query("combat_exp") < 1000000){
		msg = "大人恩典：在下的功力当可与各大掌门人一较高下。";
	    }else {
		msg = "大人明鉴：天下能与在下交手的只怕不多了。";
	    }
	    */
	    msg = "回大人：属下";
	    info = "经验 "+me->query("combat_exp")+" 点"+
		"武功 "+me->query_skill("force", 1)+" 级。";
	    command("whisper "+name+" "+msg+info);
	    return "大人可千万为我保密啊。";
	}else{
	    if (player->query("combat_exp") < 100000){
		command("sneer");
		return "凭你也配问？";
	    }else if (player->query("combat_exp") < 400000){
		return "我看你也在江湖上也混得有年头了，怎么这点规矩都不懂？";
	    }else {
		return "不好意思，在下这点微末道行怎么能入您老的法眼？";
	    }
	}
	break;
    }
    return "什么？";
}


void get_random_name()
{
    mixed lastnamelist=({
    ({"赵", "zhao"}), ({"钱", "qian"}),  ({"孙", "sun"}),   ({"李", "li"}),    
    ({"周", "zhou"}), ({"吴", "wu"}),    ({"郑", "zheng"}), ({"王", "wang"}), 
    ({"冯", "feng"}), ({"陈", "chen"}),  ({"卫", "wei"}),   ({"高", "gao"}),   
    ({"云", "yun"}),  ({"张", "zhang"}), ({"刘", "liu"}),   ({"马", "ma"}),
    });

    mixed firstnamelist=({
    ({"得胜", "desheng"}),   ({"应宝", "yingbao"}), ({"生财", "shengcai"}),
    ({"永胜", "yongsheng"}), ({"制勇", "zhiyong"}), ({"领军", "lingjun"}),
    ({"根宝", "genbao"}),    ({"进宝", "jinbao"}),  ({"德生", "desheng"}),
    ({"永利", "yongli"}),    ({"诚孝", "chengxiao"}),  ({"广义", "guangyi"}),
    ({"利顺", "lishun"}),    ({"忠庭", "zhongting"}),  ({"齐升", "qisheng"}),
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

    set("inquiry", ([
	"老爷" : (: answer_inqiry, "laoye" :),
	"master" : (: answer_inqiry, "laoye" :),
	"laoye" : (: answer_inqiry, "laoye" :),
	"武功" : (: answer_inqiry, "wugong" :),
	"功夫" : (: answer_inqiry, "wugong" :),
	"gongfu" : (: answer_inqiry, "wugong" :),
	"wugong" : (: answer_inqiry, "wugong" :),
	"拳脚" : (: answer_inqiry, "unarmed" :),
	"unarmed" : (: answer_inqiry, "unarmed" :),
	"barehand" : (: answer_inqiry, "unarmed" :),
	 ]));
    set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: exert_function("kurong") :),
		(: exert_function("recover") :),
		(: perform_action("sword.ailao") :),
		(: perform_action("finger.qiankun") :),
		(: perform_action("strike.piaomiao") :),
	    }) );

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


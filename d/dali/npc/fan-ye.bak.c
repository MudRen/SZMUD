// Code of ShenZhou
// fan-ye.c 范骅

#define ANTI_ROBOT "/u/yeer/robot"
inherit NPC;

string ask_me();
void skill_set1(object, int);
void skill_set2(object, int);
void skill_set3(object, int);
void no_answer(object user);
int do_answer(string arg);
int do_answer(string arg)
;

void create()
{
	set_name("范骅", ({ "fan ye", "fan"}));
    set("long", "此人中等身材，身着锦缎官服，目光如炬，显是精明人物，尤擅谋略，居大理为官多年功勋赫赫。\n");
	set("title","大理国司马");
    set("gender", "男性");
    set("age", 43);
    set("inquiry", ([
		"治安" : (: ask_me :),
		]));

	set_skill("cuff", 140);
    set_skill("taiji-quan", 155);
    set_skill("dodge", 150);
    set_skill("tiyunzong", 160);
    set_skill("parry", 140);
    set_skill("force", 140);
    set_skill("sword", 140);
	set_skill("ding-force",150);
	set_skill("taiji-jian",155);

    map_skill("cuff","taiji-quan");
    map_skill("dodge","tiyunzong");
	map_skill("force","ding-force");
	map_skill("sword","taiji-jian");

	prepare_skill("cuff","taiji-quan");

    set("str", 30);
    set("int", 25);
    set("con", 25);
    set("dex", 40);

    set("max_qi", 1500);
    set("qi", 1500);
    set("max_jing", 1200);
    set("jing", 1200);
    set("max_neili", 2000);
    set("neili", 2000);
	set("max_jingli", 2000);
    set("jingli", 2000);
    set("jiali", 80);
    set("combat_exp", 800000);
    set("attitude", "peaceful");
    set("shen_type", 1);
	set_temp("apply/armor", 60);
	set_temp("apply/dodge", 20);

    setup();
	carry_object("/d/dali/obj/zipao.c")->wear();	
	carry_object("/d/city/obj/gangjian.c")->wield();
}

 string ask_me()
{
        object ob,  weapon, room, who=this_object(), me=this_player();
        int exp, level, i, room_no;
        string areaname;
        
        if(me->query("robot_answer")) return "你上次的机器人检查还没有过关，我和不敢和你有什么来往。";
        if(random(4) == 2 && !me->query("passed_fan")) {
                command("tell " + me->query("id") + " 昨天我碰到yeer。他让我问你一个问题。");
                command("whisper " + me->query("id") + " yeer说，你必须回答对了，才给你记功劳。");
                ANTI_ROBOT->get_question(me, who);
                return "例行公事吧！\n";
        }

        exp=me->query("combat_exp");
        for (level=1;level*level*level<exp*10;level++) {}
        
        if (who->query_temp("job_offered"))
                return "我这里现在没什么要紧的事情，"+RANK_D->query_respect(me)+"请先回去休息吧。";
        
        if (!me->query("dali/employee"))
                return RANK_D->query_respect(me)+"和我大理素无瓜葛，何有此问啊？";


        if (me->query("dali/trust")<0
                || (me->query("family/family_name") != "大理段家"
                && me->query("combat_exp")>3000000)) {
                command("hmm "+me->query("id"));
                return "我这里现在没什么要紧的事情，"+RANK_D->query_respect(me)+"请先回去休息吧。";
        }

        if (me->query("combat_exp")<30000) {
                command("pat "+me->query("id"));
                command("say 大理境内强人都颇为凶悍，"+RANK_D->query_respect(me)+"功力不够，恐怕不能立功，反而危及自身性命。");
                return RANK_D->query_respect(me)+"还是先回去练好基本功再来吧。";
        }

        if (me->query_temp("dalijobon")) {
                return "你先把你手头的活干完吧";
                }
        
        if (me->query("mud_age") - me->query("dali/lastjob") < 120) {
                return "我这里现在没什么要紧的事情，"+RANK_D->query_respect(me)+"请先回去休息吧。";
                }

        me->set("dali/lastjob",me->query("mud_age"));
        me->set_temp("dalijobon",1);

        if (me->query("combat_exp")<500000) {
                ob = new("/d/dali/npc/dlbandit1");
                skill_set1(ob, level);
        }
        else {
                if (me->query("combat_exp")<1500000) {
                        ob = new("/d/dali/npc/dlbandit2");
                        skill_set2(ob, level);
                }
                else {
                        ob = new("/d/dali/npc/dlbandit3");
                        skill_set3(ob, level);
                        }
                }

        ob->move(load_object("/d/dali/feiwo.c"));

        ob->set("combat_exp",me->query("combat_exp")*(210+random(81))/100);
        ob->set("shen",-ob->query("combat_exp")/10);
        ob->set("max_qi", me->query("max_qi")*(12+random(5))/10);
        ob->set("eff_qi", ob->query("max_qi"));
        ob->set("qi", ob->query("max_qi"));
        ob->set("max_jing", me->query("max_jing")*(10+random(3))/10);
        ob->set("eff_jing", ob->query("max_jing"));
        ob->set("jing", ob->query("max_jing"));
        ob->set("max_neili", me->query("max_neili")*(10+random(4))/10);
        ob->set("neili", ob->query("max_neili"));
        ob->set("jiali",ob->query("max_neili")/50);
        ob->set("max_jingli", me->query("max_jingli")*(10+random(4))/10);
        ob->set("jingli", ob->query("max_jingli"));

        i = random(6)+1;
        switch (i) {
        case 1 :
                areaname="罗伽甸";
                room_no=12+random(8);
                break;
        case 2 :
                areaname="阳宗镇";
                room_no=21+random(8);
                break;
        case 3 :
                areaname="步雄部";
                room_no=31+random(7);
                break;
        case 4 :
                areaname="东泸水谷地";
                room_no=41+random(17);
                break;
        case 5 :
                areaname="喜州城南";
                room_no=64+random(16);
                break;
        case 6 :
                areaname="剑川口外";
                room_no=81+random(9);
                break;
        }
        room=load_object("/d/dali/minov"+room_no+".c");
        remove_call_out("moveto");
        call_out("moveto", 15+random(8), ob, room_no);

        set_temp("job_offered",1);
        remove_call_out("clearn_jo");
        call_out("clean_jo", 50, who);

        me->set("dali/lastjob", me->query("mud_age"));

        command("say "+areaname+"一带的"+room->query("short")+"据报有"+ob->query("name")+"活动。");
        return "你去那一带巡查巡查，发现有在逃的通缉要犯的，务必活捉送定安府。";
}

int do_answer(string arg)
{
        int result;
        object user = this_player(), asker = this_object();
        result = ANTI_ROBOT->do_answer(arg, user, asker);

        if (result == 2) {
                tell_object(user, asker->name(1) + "悄悄告诉你：回答正确，我现在再可以回答你的问题了。\n");
                user->set("passed_fan", 1);
                return 1;
        }

        if (result == -1){
                command("tell "+ user->query("id") + " 完了，按照yeer的吩咐我要处罚你了。");
                user->add("dali/trust", -20);
                command("whisper "+ user->query("id") + " 我手下留情，只罚了你20点功劳，你可千万别告诉yeer啊！");
                return 1;
        }

        return result;
}

void no_answer(object user)
{
        command("whisper " + user->query("id") + " 看来你是回答不上来了，我只有按yeer的吩咐处罚你了。");
        user->add("dali/trust", -20);
        command("whisper "+ user->query("id") + " 我手下留情，只罚了你20点功劳，你可千万别告诉yeer啊！");
}
void clean_jo(object ob)
{
	ob->delete_temp("job_offered");
	return;
}


void skill_set2(object ob, int level)
{
	object weapon;
	switch (ob->query("title")) {
	case "西域少林恶僧" :
		ob->set_skill("dodge", level-35+random(10));
		ob->set_skill("force", level-35+random(10));
		ob->set_skill("parry", level-35+random(10));
		ob->set_skill("hunyuan-yiqi", level-35+random(10));
		ob->set_skill("shaolin-shenfa", level-35+random(10));
		ob->map_skill("dodge","shaolin-shenfa");
		ob->map_skill("force","hunyuan-yiqi");
		switch (random(3)) {
		case 0 :
			ob->set_skill("finger", level-35+random(10));
			ob->set_skill("yizhi-chan", level-35+random(10));
			ob->set_skill("strike", level-35+random(10));
			ob->set_skill("banruo-zhang", level-35+random(10));
			ob->map_skill("finger","yizhi-chan");
			ob->map_skill("strike","banruo-zhang");
			ob->prepare_skill("finger","yizhi-chan");
			ob->prepare_skill("strike","banruo-zhang");
			break;
		case 1 :
			ob->set_skill("cuff", level-35+random(10));
			ob->set_skill("jingang-quan", level-35+random(10));
			ob->map_skill("cuff","jingang-quan");
			ob->prepare_skill("cuff","jingang-quan");
			break;
		case 2 :
			ob->set_skill("finger", level-35+random(10));
			ob->set_skill("nianhua-zhi", level-35+random(10));
			ob->set_skill("strike", level-35+random(10));
			ob->set_skill("sanhua-zhang", level-35+random(10));
			ob->map_skill("finger","nianhua-zhi");
			ob->map_skill("strike","sanhua-zhang");
			ob->prepare_skill("finger","nianhua-zhi");
			ob->prepare_skill("strike","sanhua-zhang");
			break;
		}
		switch (random(3)) {
		case 0 :
			ob->set_skill("blade", level-35+random(10));
			ob->set_skill("xiuluo-dao", level-35+random(10));
			ob->map_skill("blade","xiuluo-dao");
			ob->map_skill("parry","xiuluo-dao");
			weapon=new("/d/city/obj/gangdao.c");
			weapon->move(ob);
			weapon->wield();
			break;
		case 1 :
			ob->set_skill("sword", level-35+random(10));
			ob->set_skill("fumo-jian", level-35+random(10));
			ob->map_skill("sword","fumo-jian");
			ob->map_skill("parry","fumo-jian");
			weapon=new("/d/city/obj/gangjian.c");
			weapon->move(ob);
			weapon->wield();
			break;
		case 2 :
			ob->set_skill("club", level-35+random(10));
			ob->set_skill("zui-gun", level-35+random(10));
			ob->map_skill("club","zui-gun");
			ob->map_skill("parry","zui-gun");
			weapon=new("/clone/weapon/qimeigun.c");
			weapon->move(ob);
			weapon->wield();
			break;
		}
		break;
	case "华山派弃徒" :
		ob->set_skill("dodge", level-35+random(10));
		ob->set_skill("force", level-35+random(10));
		ob->set_skill("parry", level-35+random(10));
		ob->set_skill("zixia-gong", level-35+random(10));
		ob->set_skill("huashan-shenfa", level-35+random(10));
		ob->map_skill("dodge","huashan-shenfa");
		ob->map_skill("force","zixia-gong");
		ob->set_skill("cuff", level-35+random(10));
		ob->set_skill("pishi-poyu", level-35+random(10));
		ob->set_skill("strike", level-35+random(10));
		ob->set_skill("hunyuan-zhang", level-35+random(10));
		ob->map_skill("cuff","pishi-poyu");
		ob->map_skill("strike","hunyuan-zhang");
		ob->prepare_skill("cuff","pishi-poyu");
		ob->prepare_skill("strike","hunyuan-zhang");
		switch (random(2)) {
		case 0 :
			ob->set_skill("blade", level-35+random(10));
			ob->set_skill("liangyi-dao", level-35+random(10));
			ob->map_skill("blade","liangyi-dao");
			ob->map_skill("parry","liangyi-dao");
			weapon=new("/d/city/obj/gangdao.c");
			weapon->move(ob);
			weapon->wield();
			break;
		case 1 :
			ob->set_skill("sword", level-35+random(10));
			ob->set_skill("huashan-jianfa", level-35+random(10));
			ob->map_skill("sword","huashan-jianfa");
			ob->map_skill("parry","huashan-jianfa");
			weapon=new("/d/city/obj/gangjian.c");
			weapon->move(ob);
			weapon->wield();
			break;
		}
		break;
	case "武当派叛徒" :
		ob->set_skill("cuff", level-35+random(10));
		ob->set_skill("dodge", level-35+random(10));
		ob->set_skill("force", level-35+random(10));
		ob->set_skill("parry", level-35+random(10));
		ob->set_skill("sword", level-35+random(10));
		ob->set_skill("taiji-shengong", level-35+random(10));
		ob->set_skill("taiji-jian", level-35+random(10));
		ob->set_skill("taiji-quan", level-35+random(10));
		ob->set_skill("tiyunzong", level-35+random(10));
		ob->map_skill("cuff","taiji-quan");
		ob->map_skill("sword","taiji-jian");
		ob->map_skill("dodge","tiyunzong");
		ob->map_skill("parry", "taiji-jian");
		ob->map_skill("force","taiji-shengong");
		ob->prepare_skill("cuff","taiji-quan");
		weapon=new("/d/city/obj/gangjian.c");
		weapon->move(ob);
		weapon->wield();
		break;
	case "雪山派喇嘛" :
		ob->set_skill("dodge", level-35+random(10));
		ob->set_skill("force", level-35+random(10));
		ob->set_skill("parry", level-35+random(10));
		ob->set_skill("longxiang-banruo", level-35+random(10));
		ob->map_skill("force","longxiang-banruo");
		switch (random(2)) {
		case 0 :
			ob->set_skill("shenkongxing", level-35+random(10));
			ob->map_skill("dodge","shenkongxing");
			break;
			case 1 :
			ob->set_skill("xueshitiao", level-35+random(10));
			ob->map_skill("dodge","xueshitiao");
			break;
		}
		ob->set_skill("cuff", level-35+random(10));
		ob->set_skill("yujiamu-quan", level-35+random(10));
		ob->set_skill("hand", level-35+random(10));
		ob->set_skill("dashou-yin", level-35+random(10));
		ob->map_skill("cuff","yujiamu-quan");
		ob->map_skill("hand","dashou-yin");
		ob->prepare_skill("cuff","yujiamu-quan");
		ob->prepare_skill("hand","dashou-yin");
		switch (random(3)) {
		case 0 :
			ob->set_skill("blade", level-35+random(10));
			ob->set_skill("xue-dao", level-35+random(10));
			ob->map_skill("blade","xue-dao");
			ob->map_skill("parry","xue-dao");
			weapon=new("/d/xueshan/obj/miandao.c");
			weapon->move(ob);
			weapon->wield();
			break;
		case 1 :
			ob->set_skill("sword", level-35+random(10));
			ob->set_skill("mingwang-jian", level-35+random(10));
			ob->map_skill("sword","mingwang-jian");
			ob->map_skill("parry","mingwang-jian");
			weapon=new("/d/city/obj/gangjian.c");
			weapon->move(ob);
			weapon->wield();
			break;
		case 2 :
			ob->set_skill("staff", level-35+random(10));
			ob->set_skill("jingang-chu", level-35+random(10));
			ob->map_skill("staff","jingang-chu");
			ob->map_skill("parry","jingang-chu");
			weapon=new("/d/xueshan/obj/fachu.c");
			weapon->move(ob);
			weapon->wield();
			break;
		}
		break;
	case "五毒教香主" :
		ob->set_skill("cuff", level-35+random(10));
		ob->set_skill("dodge", level-35+random(10));
		ob->set_skill("force", level+random(10));
		ob->set_skill("parry", level-35+random(10));
		ob->set_skill("hook", level-35+random(10));
		ob->set_skill("ruyi-gou", level-35+random(10));
		ob->set_skill("wuxing-quan", level-35+random(10));
		ob->set_skill("wuxingbu", level-35+random(10));
		ob->map_skill("cuff","wuxing-quan");
		ob->map_skill("hook","ruyi-gou");
		ob->map_skill("dodge","wuxingbu");
		ob->map_skill("parry", "ruyi-gou");
		ob->prepare_skill("cuff","wuxing-quan");
		weapon=new("/clone/weapon/hook.c");
		weapon->move(ob);
		weapon->wield();
		break;
	}
	return;
}

void skill_set3(object ob, int level)
{
	object weapon;
	switch (ob->query("title")) {
	case "西域少林高僧" :
		ob->set_skill("dodge", level-35+random(10));
		ob->set_skill("force", level-35+random(10));
		ob->set_skill("parry", level-35+random(10));
		ob->set_skill("hunyuan-yiqi", level-35+random(10));
		ob->set_skill("shaolin-shenfa", level-35+random(10));
		ob->map_skill("dodge","shaolin-shenfa");
		ob->map_skill("force","hunyuan-yiqi");
		switch (random(3)) {
		case 0 :
			ob->set_skill("finger", level-35+random(10));
			ob->set_skill("yizhi-chan", level-35+random(10));
			ob->set_skill("strike", level-35+random(10));
			ob->set_skill("banruo-zhang", level-35+random(10));
			ob->map_skill("finger","yizhi-chan");
			ob->map_skill("strike","banruo-zhang");
			ob->prepare_skill("finger","yizhi-chan");
			ob->prepare_skill("strike","banruo-zhang");
			break;
		case 1 :
			ob->set_skill("cuff", level-35+random(10));
			ob->set_skill("jingang-quan", level-35+random(10));
			ob->map_skill("cuff","jingang-quan");
			ob->prepare_skill("cuff","jingang-quan");
			break;
		case 2 :
			ob->set_skill("finger", level-35+random(10));
			ob->set_skill("nianhua-zhi", level-35+random(10));
			ob->set_skill("strike", level-35+random(10));
			ob->set_skill("sanhua-zhang", level-35+random(10));
			ob->map_skill("finger","nianhua-zhi");
			ob->map_skill("strike","sanhua-zhang");
			ob->prepare_skill("finger","nianhua-zhi");
			ob->prepare_skill("strike","sanhua-zhang");
			break;
		}
		switch (random(3)) {
		case 0 :
			ob->set_skill("blade", level-35+random(10));
			ob->set_skill("cibei-dao", level-35+random(10));
			ob->map_skill("blade","cibei-dao");
			ob->map_skill("parry","cibei-dao");
			weapon=new("/d/city/obj/gangdao.c");
			weapon->move(ob);
			weapon->wield();
			break;
		case 1 :
			ob->set_skill("whip", level-35+random(10));
			ob->set_skill("riyue-bian", level-35+random(10));
			ob->map_skill("whip","riyue-bian");
			ob->map_skill("parry","riyue-bian");
			weapon=new("/clone/weapon/changbian.c");
			weapon->move(ob);
			weapon->wield();
			break;
		case 2 :
			ob->set_skill("club", level-35+random(10));
			ob->set_skill("zui-gun", level-35+random(10));
			ob->map_skill("club","zui-gun");
			ob->map_skill("parry","zui-gun");
			weapon=new("/clone/weapon/qimeigun.c");
			weapon->move(ob);
			weapon->wield();
			break;
		}
		break;
	case "华山派弃徒" :
		ob->set_skill("dodge", level-35+random(10));
		ob->set_skill("force", level-35+random(10));
		ob->set_skill("parry", level-35+random(10));
		ob->set_skill("zixia-gong", level-35+random(10));
		ob->set_skill("huashan-shenfa", level-35+random(10));
		ob->map_skill("dodge","huashan-shenfa");
		ob->map_skill("force","zixia-gong");
		ob->set_skill("cuff", level-35+random(10));
		ob->set_skill("pishi-poyu", level-35+random(10));
		ob->set_skill("strike", level-35+random(10));
		ob->set_skill("hunyuan-zhang", level-35+random(10));
		ob->map_skill("cuff","pishi-poyu");
		ob->map_skill("strike","hunyuan-zhang");
		ob->prepare_skill("cuff","pishi-poyu");
		ob->prepare_skill("strike","hunyuan-zhang");
		switch (random(2)) {
		case 0 :
			ob->set_skill("blade", level-35+random(10));
			ob->set_skill("liangyi-dao", level-35+random(10));
			ob->map_skill("blade","liangyi-dao");
			ob->map_skill("parry","liangyi-dao");
			weapon=new("/d/city/obj/gangdao.c");
			weapon->move(ob);
			weapon->wield();
			break;
		case 1 :
			ob->set_skill("sword", level-35+random(10));
			ob->set_skill("huashan-jianfa", level-35+random(10));
			ob->map_skill("sword","huashan-jianfa");
			ob->map_skill("parry","huashan-jianfa");
			weapon=new("/d/city/obj/gangjian.c");
			weapon->move(ob);
			weapon->wield();
			break;
		}
		break;
	case "武当派叛徒" :
		ob->set_skill("cuff", level-35+random(10));
		ob->set_skill("dodge", level-35+random(10));
		ob->set_skill("force", level-35+random(10));
		ob->set_skill("parry", level-35+random(10));
		ob->set_skill("sword", level-35+random(10));
		ob->set_skill("taiji-shengong", level-35+random(10));
		ob->set_skill("taiji-jian", level-35+random(10));
		ob->set_skill("taiji-quan", level-35+random(10));
		ob->set_skill("tiyunzong", level-35+random(10));
		ob->map_skill("cuff","taiji-quan");
		ob->map_skill("sword","taiji-jian");
		ob->map_skill("dodge","tiyunzong");
		ob->map_skill("parry", "taiji-jian");
		ob->map_skill("force","taiji-shengong");
		ob->prepare_skill("cuff","taiji-quan");
		weapon=new("/d/city/obj/gangjian.c");
		weapon->move(ob);
		weapon->wield();
		break;
	case "雪山派喇嘛" :
		ob->set_skill("dodge", level-40+random(5));
		ob->set_skill("force", level-40+random(5));
		ob->set_skill("parry", level-40+random(5));
		ob->set_skill("longxiang-banruo", level-35+random(5));
		ob->map_skill("force","longxiang-banruo");
		switch (random(2)) {
		case 0 :
			ob->set_skill("shenkongxing", level-40+random(5));
			ob->map_skill("dodge","shenkongxing");
			break;
			case 1 :
			ob->set_skill("xueshitiao", level-40+random(5));
			ob->map_skill("dodge","xueshitiao");
			break;
		}
		ob->set_skill("strike", level-35+random(10));
		ob->set_skill("huoyan-dao", level-35+random(10));
		ob->map_skill("strike","huoyan-dao");
		ob->prepare_skill("strike","huoyan-dao");
		switch (random(2)) {
		case 0 :
			ob->set_skill("blade", level-35+random(10));
			ob->set_skill("xue-dao", level-35+random(10));
			ob->map_skill("blade","xue-dao");
			ob->map_skill("parry","xue-dao");
			weapon=new("/d/city/obj/gangdao.c");
			weapon->move(ob);
			weapon->wield();
			break;
		case 1 :
			ob->set_skill("hammer", level-40+random(5));
			ob->set_skill("riyue-lun", level-40+random(10));
			ob->map_skill("hammer","riyue-lun");
			ob->map_skill("parry","riyue-lun");
			weapon=new("/clone/weapon/falun.c");
			weapon->set_amount(3);
			weapon->move(ob);
			weapon->wield();
			break;
		}
		break;
	case "五毒教堂主" :
		ob->set_skill("cuff", level-35+random(10));
		ob->set_skill("dodge", level-35+random(10));
		ob->set_skill("force", level+random(10));
		ob->set_skill("parry", level-35+random(10));
		ob->set_skill("hook", level-35+random(10));
		ob->set_skill("ruyi-gou", level-35+random(10));
		ob->set_skill("wuxing-quan", level-35+random(10));
		ob->set_skill("wuxingbu", level-35+random(10));
		ob->map_skill("cuff","wuxing-quan");
		ob->map_skill("hook","ruyi-gou");
		ob->map_skill("dodge","wuxingbu");
		ob->map_skill("parry", "ruyi-gou");
		ob->prepare_skill("cuff","wuxing-quan");
		weapon=new("/clone/weapon/hook.c");
		weapon->move(ob);
		weapon->wield();
		break;
	}
	return;
}

#include "/kungfu/class/dali/sangong.h"
#include "/d/dali/npc/fy-skset1.h"

// Code of ShenZhou
// fan-ye.c 范骅

#define ANTI_ROBOT "/u/yeer/robot"
inherit NPC;

string ask_me();
int do_answer(string arg);
void skill_set1(object, int);
void skill_set2(object, int);
void skill_set3(object, int);
void no_answer(object user);

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

int do_answer(string arg)
{
        int result;
        object user = this_player(), asker = this_object();
        result = ANTI_ROBOT->do_answer(arg, user, asker);
write_file("/d/dali/logit", "\n" + result);
        if (result == 2) {
                command("whisper " + user->query("id") +" 悄悄告诉你：回答正确，我现在再可以回答你的问题了。\n");
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

string ask_me()
{
        object ob,  weapon, room, who=this_object(), me=this_player();
        int exp, level, i, room_no;
        string areaname;

        exp=me->query("combat_exp");
        for (level=1;level*level*level<exp*10;level++);
        
        if (!me->query("dali/employee"))
                return RANK_D->query_respect(me)+"和我大理素无瓜葛，何有此问啊？";
        
        if (who->query_temp("job_offered"))
                return "我这里现在没什么要紧的事情，"+RANK_D->query_respect(me)+"请先回去休息吧。";

//      if (environment(this_object())!=find_object("/d/dali/sangong2"))
//              return "对不起，我只在府衙办理公务，等我回府去你再来问我吧。";

        if (me->query("dali/trust")<0
                || (me->query("family/family_name") != "大理段家"
                && me->query("combat_exp")>3000000)) {
                command("hmm "+me->query("id"));
                return "我这里现在没什么要紧的事情，"+RANK_D->query_respect(me)+"请先回去休息吧。";
        }

        if(random(1) == 0 && !me->query("passed_fan")) {
                command("whisper " + me->query("id") + " 昨天我碰到仙人yeer，他让我问你一个问题。");
                ANTI_ROBOT->get_question(me, who);
                return "请例行公事吧。";
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

void moveto(object ob, int room_no)
{
        object room;
        room=load_object("/d/dali/minov"+room_no+".c");
        ob->move(room);

        switch (random(3)) {
        case 0 :
                message("vision", "一个"+ob->query("name")+"不知从什么地方鬼鬼祟祟地钻了出来。\n", room, ob);
                break;
        case 1 :
                message("vision", "一个"+ob->query("name")+"大摇大摆地走了过来。\n", room, ob);
                break;
        case 2 :
                message("vision", "一个"+ob->query("name")+"杀气腾腾地从山上冲下来。\n", room, ob);
                break;
        }
        return;
}

void clean_jo(object ob)
{
        ob->delete_temp("job_offered");
        return;
}

#include "/kungfu/class/dali/sangong.h"
#include "/d/dali/npc/fy-skset1.h"


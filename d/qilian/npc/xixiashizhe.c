//by remove 21-09-2001
#include <ansi.h>
inherit NPC;
int ask_me();
void create()
{
    set_name("使者", ({"shizhe", "xixia shizhe"}));
    set("title", "西夏国");
    set("gender", "男性");
    set("age", 45);
    set("long", "这人坐在阴影里，你看不见他的面目。\n");
    set("combat_exp", 500000);
    set("shen_type", -1);
    set("attitude", "heroism");
    set("str", 26);
    set("con", 30);
    set("int", 20);
    set("dex", 20);
    set("max_qi", 1200);
    set("qi", 1200);
    set("max_jingli", 1200);
    set("jingli", 1200);
    set("max_neili", 1600);
    set("neili", 1600);
    set_temp("apply/attack", 80);
    set_temp("apply/defense", 80);
    set_skill("dodge", 140);
    set_skill("parry", 140);
    set_skill("blade", 140);
    set_skill("force", 140);
    set("inquiry",([
              "job" : (: ask_me :),
              "工作" : (: ask_me :),
              "西夏国" : "我西夏国运昌盛，总有一天要统一中原。\n",
              "赫连铁树" : "我是王爷派出的使者。王爷就是要挑起中原武林自相残杀，好趁机进攻中原。\n",]));
    setup();
    carry_object("/d/city/obj/tiejia")->wear();
    carry_object("/d/city/obj/gangdao")->wield();
}
int ask_me()
{
     object ob, room, me = this_player();
     if(!( room = find_object("/d/taishan/fengchan")) )
     room = load_object("/d/taishan/fengchan");
     if (userp(me) && me->query("id") == room->query("winner") )
     { command("say 阁下是武林盟主，本堂可担当不起！");
       return 1;}
if ( ((int)me->query("yipin/done")+30)/
                        ((int)me->query("yipin/failure")+1) < random(3)) {
                command("sneer " +me->query("id"));
               say("使者冷笑道：你先歇几天吧，我手头这几桩差事可信不过让你去做。\n");
                me->delete_temp("xixia/testpass");
                me->delete_temp("xixia/一品堂");
                me->delete_temp("apply/short");
                me->apply_condition("ypjob", 100);
                return 1;
        }
 if (me->query_temp("xixia/一品堂")) {
                command("nod " +me->query("id"));
                me->set_temp("try_assign_ypjob", 1);
                me->set_temp("ypjob/start", 1);
                if (me->query_condition("xakiller") > 0)
                me->apply_condition("xakiller", 0);
                call_out("assign_job", 1, me, 1);
                return 1;}
 if (me->query_temp("ypjob/start") > 0)
          {write("你已经有任务在身，还不快去做。\n");return 1;}
}       private int is_suitable(object victim, object killer)
{
        string *no_kill_list = ({
                "mu ren",
                "mengzhu",
                "shangshan shizhe",
                "fae shizhe",
                "xuantong dashi",
                "feng qingyang",
                "huang zhen",
                "juexin dashi",
                "yideng dashi",
                "ren woxing"
});

        if( victim->query("combat_exp") < killer->query("combat_exp")
         || victim->query("combat_exp") > killer->query("combat_exp")*7/4
         || !clonep(victim) || userp(victim) 
         || victim->query("race") != "人类"
         || victim->query("shen") < 0
         || victim->query("winner")
         || strsrch(base_name(victim), "/kunfu/skill") == 0
         || strsrch(base_name(victim), "/d/xiakedao/") == 0
         || strsrch(base_name(victim), "/d/beijing/") == 0
         || strsrch(base_name(victim), "/clone/user") == 0
         || strsrch(base_name(victim), "/u/") == 0
         || member_array(victim->query("id"), no_kill_list) != -1 ) 
        {
           return 0;
        } 
        return 1;
}


void assign_job(object me, int try_times)
{
             object ob, *victim_list;
        int i;
        string str, ttt;
        
        victim_list = filter_array(livings(), "is_suitable", this_object(), me);
   if( sizeof(victim_list) == 0 ) {
        // try again in 5 secs.
                if( try_times > 5) {
                        say("使者说道：" + me->query("name") + "，实在是找不到适合你杀的人，下次再来吧。\n");
                        me->delete_temp("try_assign_ypjob");
                }
                else {
                        say("使者说道：" + me->query("name") + "，暂时找不到适合你杀的人，等5秒看看。\n");
                }
                return;
}
        me->apply_condition("ypjob", 70);
        me->delete_temp("try_assign_ypjob");
        me->delete_temp("ypjob/start");
        i = random(sizeof(victim_list));
        ttt=gender_pronoun(victim_list[i]->query("gender"));
        say("使者说道："+victim_list[i]->query("name")+"近日一直跟我西
     夏国作对，"+"你去给我把"+ttt+"杀了！\n");
        ob->set("owner", me->query("id"));
}

int accept_object(object me, object ob)
{
        string *award_list = ({
        "渡难",
        "渡劫",
        "渡厄",
        "洪七公",
        "黄药师",
        "周芷若",
        "张三丰"
        });

        int gain;

        if ( ob->query("id") != "head" 
         || ob->query("owner") != me->query("id"))
            return 0;
        if (me->query_temp("xixia/一品堂")){        gain = ob->query("gain");
                if (me->query_condition("ypjob") > 0 && ob->query("gain")){
                me->add("combat_exp", gain * 6 + random(gain*5));
                me->add("potential", gain * 3 + random(gain));
      if (me->query("potential") > me->query("max_potential"))
          me->set("potential", me->query("max_potential"));
                command("u&me "+me->query("id"));
                ob=new("clone/money/gold");
                ob->move(me);
                me->add("yipin/done", 1);
             me->apply_condition("ypjob", 0);

        if (member_array(ob->query("victim_name"), award_list) >= 0  
        && ob->query("combat_exp") > me->query("combat_exp")*3/2)
                me->add("combat_exp", gain*30);                
        }
        else {
                command("kick "+me->query("id"));
                say("使者大怒道：没用的东西，这麽半天才干完活，亏你还有脸回来见我！\n");
                me->add("yipin/failure", 1);
                me->delete_temp("ypjob/start");       
}               
        return 1;
        }
}



//tracy & lnere 12/2001
#include <ansi.h>
inherit NPC;
string ask_me();
int ask_giveup();
int answer();
string ask_start();
   string* room= ({
        "/d/hangzhou/yuhuang"+(1+random(3)),
        "/d/hangzhou/road41",
        "/d/hangzhou/road"+(63+random(4)),
        "/d/hangzhou/road78",
        "/d/hangzhou/lingyin0",
        "/d/hangzhou/suti"+(1+random(7)),
        "/d/hangzhou/kedian",
        "/d/foshan/street"+(1+random(4)),
        "/d/foshan/qzroad"+(1+random(7)),
        "/d/foshan/beidi",
        "/d/quanzhou/zhongxin",
        "/d/quanzhou/xiqiao",
        "/d/quanzhou/yaopu",
        "/d/quanzhou/shanlu"+(1+random(6)),
        "/d/quanzhou/enyuan",
        "/d/huanghe/bank"+(1+random(8)),
        "/d/taishan/daizong",
        "/d/taishan/yitian",
              "/d/city/nandajie"+(1+random(3)),
              "/d/city/dongdajie2"+(1+random(3)),
              "/d/city/yuelao",
              "/d/taishan/yidao",
              "/d/city/zuixianlou",
              "/d/dali/chhill2",
              "/d/city/nanjiao"+(1+random(4)),
              "/d/city/xijiao"+(1+random(4)),
              "/d/dali/dahejie",
              "/d/shaolin/shijie4",
              "/d/wudang/taiziyan",
              "/d/xingxiu/alagou1",
              "/d/qilian/yongchang",
              "/d/hangzhou/hongchun",
              "/d/gaibang/ml1",
              "/d/xingxiu/silk2",
        });
              mapping *miti = ({
                                     ([ "ti":"欲话无言听流水。打一字","an":"活"]), 
                                     ([ "ti":"两点一直，一直两点。打一字","an":"慎"]), 
                                             ([ "ti":"点点营火照江边。  猜一字。","an":"淡"]), 
                                             ([ "ti":"存心不善，有口难言。猜一字。","an":"亚"]), 
                                             ([ "ti":"夫人何处去。猜一字","an":"二"]), 
                                             ([ "ti":"欲罢不能。猜一字。","an":"四"]), 
                                             ([ "ti":"日日有馀，月月不足。猜一字。","an":"门"]), 
                                             ([ "ti":"添丁进口。猜一字。","an":"可"]), 
                                             ([ "ti":"与我同行。猜一字。","an":"衙"]), 
                                             ([ "ti":"乘人不备。 打一字","an":"乖"]), 
                                             ([ "ti":"旭日不出。猜一字。","an":"九"]), 
                                             ([ "ti":"正字少一横，莫作止字猜。  猜一字。","an":"步"]), 
                                             ([ "ti":"人不在其位。猜一字。","an":"立"]), 
                                             ([ "ti":"我没有他有，天没有地有。  猜一字。","an":"也"]), 
                                             ([ "ti":"一字生得巧，四面八只脚。  猜一字。","an":"井"]), 
                                             ([ "ti":"半真半假。猜一字。","an":"值"]), 
                                             ([ "ti":"百花齐放。猜成语。","an":"万紫千红"]), 
                                             ([ "ti":"静候送礼人。猜成语。","an":"待人接物"]), 
                                             ([ "ti":"做了皇帝想成仙。  猜成语。","an":"贪心不足"]), 
                                             ([ "ti":"九千九百九十九。  猜成语。","an":"万无一失"]), 
                                             ([ "ti":"导游。猜成语。","an":"引人入胜"]), 
                                             ([ "ti":"阎王爷写日记。猜成语。","an":"鬼话连篇"]), 
                                             ([ "ti":"月亮底下看影子。  猜成语。","an":"自看自大"]), 
                                             ([ "ti":"长生不老。猜植物。","an":"万年青"]), 
                                             ([ "ti":"令狐冲是哪派的掌门？","an":"恒山"]), 
                                             ([ "ti":"上海最有名的小吃聚集地是哪里？","an":"城皇庙"]), 
                                             ([ "ti":"江南七怪中谁最先死？","an":"张阿生"]), 
                                             ([ "ti":"欧阳克是欧阳锋的什么人？","an":"私生子"]), 
                                             ([ "ti":"东方不败的情人是？","an":"杨莲亭"]), 
                                             ([ "ti":"血刀老祖出现在金庸的哪部书里？","an":"连城诀"]), 
                                      });
void create()
{
        set_name(HIW"圣诞老公公"NOR, ({ "gong gong", "laoren" }) );
        set("gender", "男性");
        set("age", 90);
        set("long","他就是圣诞老人,难道你不认识吗?看他那又白又长的胡须,下次可要记住他啊.\n");
        set("attitude", "peaceful");
        set("combat_exp", 1500000);
        set("str", 30);
        set("int", 30);
        set("cor", 30);
        set("cps", 30);
        set("con", 30);
        set("max_qi", 10000);
        set("max_jing", 1500);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 100);
        set_skill("force", 500);
        set_skill("cuff", 500);
        set_skill("whip", 500);
        set_skill("parry", 500);
        set_skill("dodge", 500);
        set("chat_chance", 50);
        set("startroom","/d/city/guangchang");
        set("chat_msg", ({
            "圣诞老人手提一筐水果篮逢人就说：「圣诞快乐!」\n",
            "圣诞老人高声唱着圣诞歌,祝愿大家：「新年愉快!」\n",
            "圣诞老人悄悄的对你说:「想玩猜谜吗?有奖励的哦!」\n",
        }) );
        set("inquiry", ([
                "礼物"     : (: ask_me :),
                "gift"   : (: ask_me :),
                "放弃"   : (: ask_giveup :),
                "giveup"   : (: ask_giveup :),
                         "start"   : (: ask_start :),
        ]));
        setup();
}
void init()
{
          add_action("do_answer", "answer");
}
mapping query_miti()
{
           return miti[random(sizeof(miti))];
}
string ask_me()
{             mapping miti,an;
             object me = this_player(),ob = this_object();
             if (me->query_condition("gift")>0) return "你过一会再来找我吧!\n";
                  miti = this_object()->query_miti();
                tell_object(me,"圣诞老人说道:好吧!那我就考考你!\n");
                tell_object(me,MAG""+miti["ti"]+"\n"NOR);
                  me->set("gifta",miti["an"]);
                        me->apply_condition("gift",26);
                         return "加油,加油啊!!!";
             
}
string ask_start()
{
      if (this_player()->query("id")=="tracy" || this_player()->query("id")=="lnere") {
             
tell_object(users(),HIM"天空中传来阵阵"+this_object()->query("name")+HIM"开心的笑声：大家好，圣诞快乐！我老头子特地千里迢迢来到神州，为你们带来了惊喜的礼物。\n"NOR);
      tell_object(users(),HIW"只见天上一架由四头雪白的麋鹿驾驶的雪撬缓缓地降落在扬州城的中央广场。\n"NOR);
                             return "merry christmas\n";
      }
                             return "什么?\n";
             
}
int do_answer(string arg)
{            object me=this_player(),ob=this_object();
             object obj,liwu,fangjian;
             string ans;
        if (!me->query("gifta")) return 0; 
                        ans=me->query("gifta");
        if (!arg || arg!=ans ) {
                command( "pat "+me->query("id"));
             if( me->query("env/no_accept") ){
              command("why");
              command("say "+me->name()+"不想接受任何东西？");
                         return 1;
        }
        else {
                tell_object(me,"圣诞老人轻声说道:没关系,不会答也有礼物!\n");
                tell_object(me,"圣诞老人从篮子里取出一些黄金.\n");
                obj = new("/clone/money/gold");
                obj->set_amount(1+random(5));
                obj->move(ob);
                command("give "+me->query("id")+" gold");
                me->delete("gifta");
                        return 1;
             }
        }
                        command( "wa "+me->query("id"));
                        liwu = new("/u/tracy/liwu");
                        liwu->set("giftp",me->query("id"));
                        fangjian = load_object(room[random(sizeof(room))]);
                        liwu->move(fangjian);
                        tell_object(me,"圣诞老人说:给你礼物我放到了"+fangjian->query("short")+",你快去看看吧!\n");
                                  obj = new("/clone/drug/lingzhi");
                                  obj->move(me);
                        me->delete("gifta");
                        return 1;
}
int ask_giveup()
{            object me=this_player(),ob=this_object();
             object obj;
             if (me->query("gifta")) {         
                command( "pat "+me->query("id"));
                       if( me->query("env/no_accept") ){
              command("why");
              command("say "+me->name()+"不想接受任何东西？");
                         me->delete("gifta");
                         return 1;
                }
                 else {
             
                tell_object(me,"圣诞老人轻声说道:没关系,不会答也有礼物!\n");
                tell_object(me,"圣诞老人从篮子里取出一些黄金.\n");
                obj = new("/clone/money/gold");
                obj->set_amount(1+random(5));
                obj->move(ob);
               command("give "+me->query("id")+" gold");
                me->delete("gifta");                        
                        return 1;
             }
                       }
                        return 0;
              
}
int accept_fight(object me)
{
        command("say " + RANK_D->query_respect(me) + "，老公公我是不打架的.^&^\n");
        return 0;
}
int accept_kill(object victim)
{
                  object me = this_object();
                  object player = this_player();
                  int flag;
                  command("say " + RANK_D->query_respect(player) + "，怎么这么凶？大过节的不许杀人啊！\n");
                  command("benger " + player->query("id") );
             if (player->query("env/immortal"))
                                flag=1;
                  player->delete("env/immortal");
                  player->unconcious();
                 if (flag) player->set("env/immortal",1);
                         command("halt");
                  return 0;
}

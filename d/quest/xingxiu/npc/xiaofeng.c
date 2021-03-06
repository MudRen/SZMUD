// Code of ShenZhou
// coding by Slow
#include <ansi.h>
inherit NPC;

int auto_perform();
void you_out();
void create()
{
          set_name("萧峰", ({"xiao feng", "xiao", "feng"}));
          set("nickname", "大侠");
        set("gender", "男性");
          set("age", 35);
        set("long", 
"身材甚是魁伟，三十来岁年纪，身穿灰色旧布袍，已微有破烂，浓眉大眼，
高鼻阔口，一张四方的国字脸，颇有风霜之色，顾盼之际，极有威势。\n");
        set("attitude", "peaceful");
        
         set("str", 30);
         set("int", 24);
         set("con", 40);
         set("dex", 40);
              set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                    (: auto_perform :),
        }) );

          set("max_qi", 10000);
        set("max_jing", 3000);
          set("neili", 10000);
          set("max_neili", 10000);
          set("jingli", 10000);
          set("max_jingli", 9000);
          set("eff_jingli", 9000);
        set("jiali", 100);
        
               set("combat_exp", 5400000);

        set("score", 200000);
            set("death_times",200);

        set_skill("force", 400);             // 基本内功
        set_skill("huntian-qigong", 400);    // 混天气功
        set_skill("strike", 400);            // 基本掌法
        set_skill("xianglong-zhang", 400);   // 降龙十八掌
        set_skill("dodge", 400);             // 基本躲闪
        set_skill("xiaoyaoyou", 400);        // 逍遥游
        set_skill("parry", 400);             // 基本招架
        
        map_skill("force", "huntian-qigong");
        map_skill("strike","xianglong-zhang");
        map_skill("dodge", "xiaoyaoyou");
          map_skill("parry", "xianglong-zhang");
        prepare_skill("strike", "xianglong-zhang");
               create_family("丐帮", 13, "帮主"); 
        setup();
        
        carry_object("/d/gaibang/obj/budai")->set_amount(9);
        carry_object("/d/gaibang/obj/budai")->wear();
}
int accept_kill(object victim)
{
         object *ob;
           int i;
           object me=this_object();
        if(victim->query_temp("azi/killer")!=1 && victim->query_temp("azi/killer2")!=1)
         {
          command("say 臭贼有帮手，但我萧某何时怕过人多！\n");
       message_vision(HIY "萧峰见来了帮手，豪气顿增,把降龙十八掌发挥到极致,只见萧峰双臂划圈推出，正是一招「亢龙有悔」!\n" NOR,me);
        command("halt");
              ob = all_inventory(environment(me));
              for(i=0; i<sizeof(ob); i++) {
              if(living(ob[i])  && ob[i]->query_temp("azi/killer2")==1) {
              tell_object(ob[i], "你感到一阵强烈的气流涌向胸口，胸口一闷。\n");
              ob[i]->unconcious();
              }
           }
              tell_object(victim, "你感到一阵强烈的气流涌向胸口，胸口登时一闷。\n");
              if (victim) victim->unconcious();
        call_out("destruct_me",1,me);
        me->start_busy(5);
          }
          return 0;
}
void die()
{
          object  me =this_object();
          object  ob;
           message_vision(HIR"萧峰道:阿紫,姐夫无能,保护不了你了！\n" NOR,this_object());
/*
            ob = me->query_temp("last_damage_from");
          if(!find_living("you tanzhi"))
          {
          ob->delete("azi/killer");
          ob->delete("azi/killer2");
          }
*/
              you_out();
               ::die();
}
void destruct_me(object me)
{
          object obj;
        obj=find_object("a zi");
        if (!obj) obj = present("a zi", me);
        if (!obj) obj = present("a zi", environment(me));
//        if (!obj) obj = find_object( resolve_path(me->query("cwd"), "a zi") );
          if (obj)
         {
          destruct(obj);
message_vision(HIY"萧峰哈哈大笑，道:今天饶尔等不死。抱住阿紫，几个起落，便已不见！\n" NOR,this_object());
         destruct(me);
          }
}
void you_out()
{
        object ob1,ob2,player;
         object me=this_object();
       player=me->query_temp("last_damage_from");
         ob1=present("you tanzhi");
         if (!ob1)
         {
             seteuid(getuid());
                 ob1=new("/d/quest/xingxiu/npc/you.c");
             ob1->move(environment());
           }
}
// void init(){ set_heart_beat(1);}
#include "/kungfu/class/xingxiu/newhuajob_perform.h"


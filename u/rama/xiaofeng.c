// Code of ShenZhou
// coding by Slow
#include <ansi.h>
inherit NPC;

int auto_perform();
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
        
         set("str", 40);
         set("int", 24);
         set("con", 40);
         set("dex", 40);

            set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                    (: auto_perform :),
        }) );

          set("max_qi", 15000);
        set("max_jing", 3000);
          set("neili", 15500);
          set("max_neili", 15500);
          set("jingli", 10000);
          set("max_jingli", 10000);
          set("eff_jingli", 10000);
        set("jiali", 300);
        
          set("combat_exp", 8000000);
        set("score", 200000);
            set("death_times",200);

        set_skill("force", 400);             // 基本内功
        set_skill("huntian-qigong", 400);    // 混天气功
        set_skill("strike", 400);            // 基本掌法
        set_skill("xianglong-zhang", 450);   // 降龙十八掌
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
           object me=this_object();
          if (victim->query("azi/killer2")!=1)
         {
          command("say 臭贼有帮手，咱们走！\n");
           call_out("destruct_me",1,me);
          }
          return 0;
}
void die()
{
           message_vision(HIR"萧峰道:阿紫,姐夫无能,保护不了你了！\n" NOR,this_object());
               ::die();
}
void destruct_me(object me)
{
          object obj;
        obj=find_object("a zi");
        if (!obj) obj = present("a zi", me);
        if (!obj) obj = present("a zi", environment(me));
        if (!obj) obj = find_object( resolve_path(me->query("cwd"), "a zi") );
message_vision(HIY"萧峰突然收掌抱住阿紫，几个起落，便已不见！\n" NOR,this_object());
          if (obj)
          destruct(obj);
         destruct(me);
}
// void init(){ set_heart_beat(1);}
#include "/kungfu/class/xingxiu/newhuajob_perform.h"

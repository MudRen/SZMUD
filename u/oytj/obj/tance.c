// glass.c
#include <ansi.h>
inherit EQUIP;
void create()
{
   set_name(HIB"实力探测器" NOR, ({ "detector", "glass", "device" }) );
   set_weight(30000);
   set("unit", "个");
   set("long",
  HIB"这是一具十分精密的大型实力探测器，它可以通过控制别人的深层灵魂来\n" "探测(tan)别人的各项实力。\n"NOR);
   set("value", 500);
   set("no_get",1);
   set("type", "misc");
   set("apply", ([
     "头部":   0,
   ]) );
}
void init()
{
   add_action("do_detect", "tan");
}
int do_detect(string arg)
{
   object ob;
   int sen, sk;
   string skill;
   if( arg ) ob = present(arg, environment(this_player()));
   else ob = this_player()->query_opponent();
   if( !ob ) return notify_fail("你要探测谁？\n");
   sen = (int)ob->query("sen");
   if( stringp(skill = ob->query("attack_skill")) )
     sk = ob->query_skill(skill);
   else
     sk = 0;
   ob->start_busy(5);
   message_vision("$N忽然涌起得莫名其妙的睡意,过了半天才开始慢慢恢复正常。\n",ob);
   
   printf("探测器显示%s的年龄是：%d\n",
     ob->query("name"), 
     (sk*sk*sk) * (100 + sen) / 100 + (int)ob->query("age") );

 
printf("探测器显示%s的神是：%d\n",
     ob->query("name"), 
     (sk*sk*sk) * (100 + sen) / 100 + (int)ob->query("shen") );

 
printf("探测器显示%s的膂力是：%d\n",
     ob->query("name"), 
     (sk*sk*sk) * (100 + sen) / 100 + (int)ob->query_str() );

 
printf("探测器显示%s的悟性是：%d\n",
     ob->query("name"), 
     (sk*sk*sk) * (100 + sen) / 100 + (int)ob->query_int() );

 
printf("探测器显示%s的根骨是：%d\n",
     ob->query("name"), 
     (sk*sk*sk) * (100 + sen) / 100 + (int)ob->query_con() );

 
printf("探测器显示%s的身法是：%d\n",
     ob->query("name"), 
     (sk*sk*sk) * (100 + sen) / 100 + (int)ob->query_dex() );

 
printf("探测器显示%s的容貌是：%d\n",
     ob->query("name"), 
     (sk*sk*sk) * (100 + sen) / 100 + (int)ob->query_per() );

 
printf("探测器显示%s的福缘是：%d\n",
     ob->query("name"), 
     (sk*sk*sk) * (100 + sen) / 100 + (int)ob->query("kar") );

 
printf("探测器显示%s的驻颜术是：%d\n",
     ob->query("name"), 
     (sk*sk*sk) * (100 + sen) / 100 + (int)ob->query_skill("beauty", 1) );

 
printf("探测器显示%s的读书写字是：%d\n",
     ob->query("name"), 
     (sk*sk*sk) * (100 + sen) / 100 + (int)ob->query_skill("literate", 1) );

 
printf("探测器显示%s的基本内功是：%d\n",
     ob->query("name"), 
     (sk*sk*sk) * (100 + sen) / 100 + (int)ob->query_skill("force", 1) );

 
printf("探测器显示%s的基本招架是：%d\n",
     ob->query("name"), 
     (sk*sk*sk) * (100 + sen) / 100 + (int)ob->query_skill("parry", 1) );

 
printf("探测器显示%s的基本轻功是：%d\n",
     ob->query("name"), 
     (sk*sk*sk) * (100 + sen) / 100 + (int)ob->query_skill("dodge", 1) );

 
printf("探测器显示%s的内力是：%d\n",
     ob->query("name"), 
     (sk*sk*sk) * (100 + sen) / 100 + (int)ob->query("max_neili") );

 
printf("探测器显示%s的加力是：%d\n",
     ob->query("name"), 
     (sk*sk*sk) * (100 + sen) / 100 + (int)ob->query("jiali") );

 
printf("探测器显示%s的当前气是：%d\n",
     ob->query("name"), 
     (sk*sk*sk) * (100 + sen) / 100 + (int)ob->query("qi") );

 
printf("探测器显示%s的最大气是：%d\n",
     ob->query("name"), 
     (sk*sk*sk) * (100 + sen) / 100 + (int)ob->query("max_qi") );

 
printf("探测器显示%s的战斗经验是：%d\n",
     ob->query("name"), 
     (sk*sk*sk) * (100 + sen) / 100 + (int)ob->query("combat_exp") );

 
printf("探测器显示%s中的葵花针毒是：%d\n",
     ob->query("name"), 
     (sk*sk*sk) * (100 + sen) / 100 + (int)ob->query_condition("kuihuazhen_poison") );
   return 1;

}


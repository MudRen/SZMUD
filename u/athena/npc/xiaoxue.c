
// 苏梦馨(Athena)
// NPC：/u/athena/npc/xiaoxue.c 

#include <ansi.h>

inherit NPC;

int singing();

void create()
{
       set_name("苏梦雪", ({ "su mengxue","su","xue"}) );
       set("gender", "女性" );
       set("shen_type", 1);
       set("age", 18);
       set("str", 20);
       set("con", 30);
       set("int", 32);
       set("dex", 22);
       set("per", 33);
       set("kar", 33);

       set("no_clean_up",1);

       set("long",
"盈盈而站着一位秀美绝俗的女子，肌肤间少了一层血色，显得
苍白异常。披著一袭轻纱般的白衣，犹似身在烟中雾里。长得
宛如玉雕冰塑，似梦似幻，已不再是凡间人物。\n"); 
       set("combat_exp", 200);
       set("attitude", "peaceful");

       set("max_qi", 300);
       set("max_jing", 300);
       set("neili", 100);
       set("max_neili", 100);

       set_skill("literate", 300);
      
       set("inquiry", ([
                   "name" : "小女子就是苏梦雪。",
                   "here" : "这里是苏府花园。",                                   
       ]) );

       setup();

       
       set("chat_chance", 2);
       set("chat_msg", ({
 "苏梦雪打开扇子，轻轻扇了扇风。\n",
 "苏梦雪眼望窗外，轻声吟道：菩提无树，明镜非台。爱亦有恨，喜即是哀。\n",
 "苏梦雪回过头来，问道：你知道何为菩提、明镜吗？？ \n",
 (: singing :),  
       }) );

       carry_object("/u/athena/obj/shan")->wield();
       carry_object("/clone/special/qilin")->wear();
       carry_object("/d/city/obj/flower_shoe")->wear();
       carry_object("/d/city/obj/necklace-diamond")->wear();
       carry_object("/clone/special/yufenguan")->wear();
       carry_object("d/city/obj/pink_cloth")->wear();
       carry_object("/d/city/obj/ring-jade")->wear();      
       carry_object("/u/athena/obj/qupu");
       carry_object("/u/athena/obj/pipa");
       if( clonep() ) CHANNEL_D->register_relay_channel("chat");
}

int singing()
{
          
 if(present("qu pu", this_object())){
 switch(random(12)) {
       case 0 : command("chang yuanyuan_qu"); break;
       case 1 : command("chang jiangcheng_zi"); break;
       case 2 : command("chang wanghai_chao"); break;
       case 3 : command("chang wenshi_jian"); break;
       case 4 : command("chang dielian_hua"); break;
       case 5 : command("chang bosi_xiaoqu"); break;
       case 6 : command("chang chunjiang_huayueye"); break;
       case 7 : command("chang yinma_changcheng"); break;
       case 8 : command("chang jiangjin_jiu"); break;
       case 9 : command("chang xiaoao_jianghu"); break;
       case 10 : command("chang baixue_ge"); break;
       case 11 : command("chang yu_meiren"); break;
     }
   return 1;
}
   else return 0;
   return 1;
}

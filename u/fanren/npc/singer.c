// Code of ShenZhou
//       #include <ansi.h> 
  inherit NPC;
void create()
{
   set_name("张宇", ({ "zhang yu","zhang" })); 
        set("long", 
"他是一个实力派的歌手。\n"
 "他是大家比较喜欢的歌星之一。\n");
         set("gender", "男性");
        set("age", 33);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 26);
        set("int", 16);
        set("con", 22);
        set("dex", 24);

        set("max_qi", 300);
        set("max_jing", 300);
        set("neili", 300);
        set("max_neili", 300);
        set("jiali", 10);
        set("combat_exp", 3000);

        set_skill("force", 30);
        set_skill("dodge", 30);
        set_skill("unarmed", 30);
        set_skill("parry", 30);
        setup();
        set("chat_chance", 6);
        set("chat_msg", ({
"张宇唱道“坐在二楼的窗口,彷彿交错了时空,突然一阵沉默,千头万绪涌动,很想握握你的手”。\n",
"张宇唱道“戒指有一点松动,你在手指上玩弄,人生意外太多,幸福说走就走,谢谢你能这样爱我 ”。\n",
"张宇低声唱道，“是什么力量,在你的心中,可以做到从容的守候”。\n",
"张宇引吭高歌，“当心出现寂寞,诱惑不能摆脱,我偷偷放弃过”。\n",
"张宇引吭高歌，“到最后关头,我终于才懂,爱不需要多与众不同”。\n",
"张宇引吭高歌，“有人分享感动,有人悲喜与共,有人全心包容,才让爱长长久久”。\n",

        }) );


carry_object("/d/quanzhou/npc/obj/guazi")->wear(); 
       add_money("gold", 100); 
}



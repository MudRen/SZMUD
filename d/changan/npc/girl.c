              // /d/changan/npc/girl.c
// 第1次修改
// by bravo
// Email
// 02-1-3
// 个人主页网址
// 文件类型  NPC  
inherit NPC;
void create()
   {
     set_name("卖花姑娘", ({ "maihua guniang","girl" }));
     set("long","她是一位一卖花为生的姑娘\n");
     set("age", 18+random(20));
      set("gender","女性");
      set("attitude","friendly");
add_money("coin",20+random(50));
     set("str", 20);
     set("dex", 20);
     set("con", 20+random(20));
     set("int", 20);
      set("jiajing",100);
      set("max_jingli",100);
      set("jingli",100);
      set("max_neili",100);
      set("neili",100);
      set("eff_jing",100);
      set("jing",100);
      set("eff_qi",100);
      set("qi",100);
      set("inquiry", ([
"野花" : "怎么,想采路边的野花吗?\n",
]) );

setup();
}



#include <ansi.h>
inherit NPC;
void create()
{
         int aa = random(5) + 2;
         int bb = random(3);
         set_name("阿混", ({"ahun", "hun"}));
         set("gender", "男性");
         set("age", 30);
         set("title", "泉州地头蛇");
         set("long", "这是泉州城里出了名的小流氓，整天不务正业，游手好闲，惹事生非。仗着自己学过几天武功，总是欺负弱小。\n");
         set("chat_chance", 10);
         set("chat_msg", ({ 
           "小混混说道:整个泉州都是老子的地盘。\n",
           "小混混说道:你也不去打听打听老子的名号。\n",
           "小混混说道:听说最近开了个什么鸟毛武馆，看老子不铲平了它。\n"
           "小混混说道:新来的想在我地盘上混，就得先孝敬老子。\n",}));         set("combat_exp", 500*aa);
         set("attitude", "aggressive");
         set("shen_type", -1);
         set("max_qi", 100*bb);
         set("max_ji", 100);
         set("max_jingli", 200);
         set("max_neili", 300);
         set("neili", 300);
         set("jiali", 10*bb);
         set_temp("apply/attack", 20);
         set_temp("apply/defense", 20);
         set_skill("parry", 10+10*bb);
         set_skill("dodge", 10+10*bb);
         set_skill("blade", 10+10*bb);
         set_skill("force", 40);
         set_skill("huntian-qigong", 40);
         map_skill("force", "huntian-qigong");
         setup();
         carry_object("/clone/misc/cloth")->wear();
         carry_object("/clone/weapon/gangdao")->wield();
 }


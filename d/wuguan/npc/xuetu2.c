#include <ansi.h>
inherit NPC;
void create()
{
       set_name("女弟子", ({"xuetu", "dizi"}));
       set("long", "这位小姑娘从小爱习武，家里只能把她送来武馆学习。\n");
       set("title", "武馆学徒");
       set("gender", "女性");
       set("age", 20);
       set("attitude", "friendly");
       set("combat_exp", 3000);       set_skill("dodge", 20);
       set_skill("cuff", 20);
       set_skill("force", 20);       set_skill("parry", 20);
       set_skill("strike", 20);
       set("max_neili", 200);
       set("neili", 200);
       setup(); 
       carry_object("/clone/misc/cloth")->wear();
}   






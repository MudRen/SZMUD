#include <ansi.h>
inherit NPC;
void create()
{
       set_name("男弟子", ({"xuetu", "dizi"}));
       set("long", "这是武馆的一名学徒，从小就被家人送进来学武。\n");
       set("title", "武馆学徒");
       set("gender", "男性");
       set("age", 18);
       set("attitude", "friendly");
       set("combat_exp", 2000);       set_skill("dodge", 20);
       set_skill("cuff", 20);
       set_skill("force", 20);       set_skill("parry", 20);
       set_skill("strike", 20);
       set("max_neili", 200);
       set("neili", 200);
       setup(); 
       carry_object("/clone/misc/cloth")->wear();
}   






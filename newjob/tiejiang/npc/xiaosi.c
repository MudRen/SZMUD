//code by cheap
//11-10-01
#include <ansi.h>
inherit NPC;
void create()
{
set_name("小四",({"xiao si"}));

set("title",HIC"仆人"NOR);
set("age",14);
set("gender","男性");
set("long", "他是一个十多岁的小孩，身形瘦小，好像有
些营养不良。 \n");
setup();
carry_object("/clone/armor/cloth")->wear();
}
void init()
{
object ob;
::init();
if(interactive(ob =this_player())&& !is_fighting() ) 
remove_call_out("greeting");
call_out("greeting",1,ob);
}
void greeting(object ob)
{
if(!ob || environment(ob) !=environment()) return;
switch(random(2)) 
{
case 0:
command("say 你要是想租车去挖矿请进。\n");
break;
case 1:
command("say 你要是想租车就快了，要是到了晚上关门那你不要怪我啊。\n");
break;
}
}


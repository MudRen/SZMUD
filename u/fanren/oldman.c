// Code of Fanren

#include <ansi.h>
inherit NPC;
inherit F_DEALER;

string ask_me();
string ask_all();
 void create() 
{
 set_name(HIW"老人"NOR, ({ "old man", "laoren","man" }));
set("long", "这是一个看起来饱经沧桑的老人，皱纹已经爬满了他的额头,他靠着石碑安静地坐着。\n");
set("title", HIW"神州"NOR);
  set("gender", "男性");
set("age", 200);
 set("attitude", "friendly");
set("shen_type", 1);
set("str", 25);
set("con", 25);
set("int", 25);
set("dex", 25);

set("max_qi", 400); 
set("max_jingli", 400); 
set("jingli", 400);
  set("max_jing", 400); 
set("neili", 400); 
set("max_neili", 400); 
set("combat_exp", 40000); 
set("score", 40000);

                set("inquiry", 
 ([
 "all" : "想知道这里的什么呢？(here、风云人物、神州巨变、江湖沧桑、老人)。\n", 
"here" : "这里是神州的历史博物馆。\n", 
"风云人物" : "所谓风云，风吹云动，风止云散。看开些吧。\n", 
"神州巨变" : "神仙们的努力不息，世间的变幻莫测，谁又说得好呢？\n", 
"江湖沧桑" : "什么叫江湖？不沧桑就不能叫做江湖了。\n", 
"老人" : "我只是个看客，看着看着就沧桑千年了。\n", 
]));

 setup(); 
 carry_object("/d/kunlun/obj/pao2.c")->wear(); 
}

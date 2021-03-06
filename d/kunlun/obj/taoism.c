// Code of ShenZhou
// 道德经合定版.c 
// keny

inherit ITEM; 
inherit F_UNIQUE; 
#include <ansi.h> 

int do_read(string arg); 

void create() 
{
set_name(HIB"道德经「最终卷」"NOR, ({ "daode jing", "jing" }));
set_weight(600); 
if( clonep() ) 
set_default_object(__FILE__); 
else { 
set("unit", "本"); 
set("long", "这是传供昆仑派弟子们所用的道德经「最终卷」，相传是古人花了几十年时间所合编的。\n");
set("value", 1000000); 
set("material", "paper"); 
set("skill", ([
"name": "taoism",        // name of the skill 
"exp_required": 10000,  // minimum combat experience required 
"jing_cost":    20,     // jing cost every time study this 
"difficulty":   30,     // the base int to learn this skill
"max_skill":   150   // the maximum level you can study
]) );
}
}

void init()
{
add_action("do_du", "du"); 
add_action("do_du", "study");
}

int do_du(string arg) 
{
object me = this_player(); 

if (me->query("family/family_name")!="昆仑派") 
{
message_vision("$N搅尽脑汁也看不明白这本$n。\n",me,this_object()); 
return 1; 
}
if (!id(arg)) { 
write("你要读什么？\n"); 
return 1;
}
}

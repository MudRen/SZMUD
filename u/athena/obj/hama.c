inherit ITEM; 
void create() 
{
set_name("冰蟾", ({ "bing chan","hama" }) ); 
set("long","这就是胡桂南当年用过的冰蟾,可以用来解（ｃｕｒｅ）百毒！\n"); 
set("value",10000); 
set("unit","只"); 
}
void init() 
{
if(this_player()==environment()) add_action("do_cure","cure"); 
}
int do_cure()
{
object me;me = this_player();
message_vision("$N看见冰蟾慢慢爬近，分别咬住了你两根指头。\n",me); 
me->clear_condition(); 
message_vision("过了一会儿，冰蟾吸饱了毒血，肚子胀得和圆球相似，慢慢的爬回到苏夢馨身上。$N尝试运功，发现身中剧毒以无大碍！\n",me);
destruct(this_object()); 
return 1; 
}

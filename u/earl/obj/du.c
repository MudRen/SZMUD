inherit ITEM; 
void create() 
{ 
set_name("毒珠",({"du zhu"})); 
set("long","这是银狐刚弄出来的毒珠,不知道能不能用来解（ｃｕｒｅ）毒！\n"); 
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
message_vision("$N一口将毒珠吞入腹中!\n",me); 
me->clear_condition(); 
message_vision("$N只觉腹内一阵清凉直透全身经脉,身上的剧毒已不再发作了!\n",me); 
destruct(this_object()); 
return 1; 
} 

#include <ansi.h>
inherit ITEM;
void create()
{	set_name(GRN"餐桌"NOR,({"table","dinner table"}));
	set("long","这是一张很大餐桌，上面正摆满着美酒佳肴！\n");
	set_max_encumbrance(8000);
	set("unit","张");
	set("value",99);
	set("no_get", 1);
	set("prep","on");
	new(__DIR__"menu")->move(this_object());
}
int is_container() {return 1;}
void init()
{  add_action("do_eat","eat");
   add_action("do_drink","drink");}

int do_eat(string arg)
{  string *msg=({

 "$N夹起一块$n，真好吃。\n",
 "$N拿起一块$n一口吞了下去，又悄悄问旁边的人：什么味道啊。\n" 
                });
   object me,ob; 
   me=this_player();
   if(!arg||arg=="") 
  {message_vision("$N盯着满桌东西，吃什么好呢O~~~~~~~~~~\n",me);
   return 1;}
   if(!(objectp(ob=present(arg,this_object()))))
  {message_vision("$N盯着满桌东西，吃什么好呢O~~~~~~~~~~\n",me);
   return 1;}
   if(me->query("food")>me->max_food_capacity()*1.5)
  {message_vision("$N盯着满桌东西，却不争气地打了个饱嗝，我吃。。。\n",me);
   return 1;} 
   if(ob->query("type")!="food")
  {message_vision("$N拿着一根筷子去夹$n，左夹右夹，$n反而长腿跑了。\n",me,ob);
   return 1;}
   message_vision(msg[random(sizeof(msg))],me,ob);
   me->add("food",10);ob->add("amount",-1);
   if(ob->query("amount")<1) destruct(ob);
return 1;}
int do_drink(string arg)
{  string *drunk=({

 "$N摇摇晃晃地说道：你们都醉了，看你们一个个都坐不稳了。。。\n",
 "$N说道：我~~~没~醉~~，再~~~来~一杯~~~~~~\n",
 "$N醉醺醺地拿起一个鸡腿，来，干。。。\n"
                 });
   string *msg=({

 "$N拿起一杯$n喝了一小口，辣得直吐舌头。\n",
 "$N拿起一杯$n咕嘟咕嘟一饮而尽。\n",
 "$N一边哼哼“$n加咖啡，我一杯又一杯。”说着又是一杯。\n"
                });
   object me,ob,id;
   string obb,idd; 
   me=this_player();
   if(!arg||arg=="") 
  {message_vision("$N盯着满桌瓶子，喝点什么呢O~~~~~~~~~~\n",me);
   return 1;}
   if(sscanf(arg,"%s with %s",obb,idd)==2) arg=obb;
   if(!(objectp(ob=present(arg,this_object()))))
  {message_vision("$N盯着满桌瓶子，喝点什么呢O~~~~~~~~~~\n",me);
   return 1;}
   if(me->query("water")>me->max_water_capacity()*1.2)
  {message_vision(drunk[random(sizeof(drunk))],me);
   return 1;} 
   if(ob->query("type")!="drink")
  {message_vision("$N拿起$n，却不小心灌到了鼻子里^*^\n",me,ob);
   return 1;}
   if(arg==obb) id=present(idd,environment(me));
   if(objectp(id))
     message_vision("$N对着"+id->query("name")+"举起一杯$n说道：干！说着一饮而尽。\n",me,ob);
   else message_vision(msg[random(sizeof(msg))],me,ob);
   me->add("water",10);ob->add("amount",-1);
   if(ob->query("amount")<1) destruct(ob);
return 1;}

#include <ansi.h> 
inherit NPC;
void create()
{	set_name(HIW"女跑堂"NOR,({"waitress","bar waitress"}));
	set("gender","女性");
	set("age",22);set("cost",0);
	set("attitude","heroism");
	set_temp("hslj",10);
       set("per",30);
	set_temp("tcpg",15);
	set_temp("wly",50);

setup();
carry_object("d/city/obj/cloth")->wear();
}
void init() {add_action("do_order","order");}

int do_order(string arg)
{ object ob,me,mee,gold;
  me=this_player();mee=this_object();
  if(!arg||arg=="")
  {message_vision("$N微笑着问$n：您要点什么？\n",mee,me);return 1;}
  if(arg=="menu")
  {new(__DIR__"obj/menu")->move(mee);
   command("give menu to "+me->query("id"));return 1;}
 if(arg=="bill")
  {message_vision("$N打了个响指：买单。\n",me);
   message_vision("$N走了过来，说道：总共"+(string)mee->query("cost")+"gold。\n",mee);
   gold=present("gold_money",me);
    if(!objectp(gold)||gold->query_amount()<mee->query("cost"))
     {message_vision("$N微笑着说道：您的gold好像不够了。\n",mee);return 1;}
    gold->add_amount(-mee->query("cost"));mee->set("cost",0);
   message_vision("$N说道：谢谢。\n",mee);
   return 1;}  
  if(file_size(__DIR__"obj/"+arg+".c")==-1||mee->query_temp(arg)<1)
  {message_vision("$N微笑着对$n说道：实在对不起，我们这儿没有"+arg+"。\n",mee,me);return 1;}
  ob=new(__DIR__"obj/"+arg);mee->add("cost",5);mee->add(arg,-1);
  message_vision("$N打了个响指：来一份"+ob->query("name")+"。\n",me);
  message_vision("$N上了一份"+ob->query("name")+"到餐桌上。\n",mee);
  ob->move(present("dinner table",environment(mee)));ob->set("amount",20);
return 1;
}
 

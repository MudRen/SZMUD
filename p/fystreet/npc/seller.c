#include <ansi.h>
// seller.c zip@hero 2000.1.27 老板娘
inherit NPC;
int do_list();
void create()
{	set_name("老板娘",({"seller"}));
	set("gender","女性");
        set("long","家具铺的老板娘。\n");
	set("age",22);
	set("combat_exp",9999999);
	set("attitude","heroism");
	setup();
	carry_object("d/city/obj/cloth")->wear();
}
void init()
{  add_action("do_list","list"); 
add_action("do_book","book"); 
}

int do_list()
{
command("say 我们这儿家具齐全，每件只要 10 Gold，您请随便看。");
   return 1;
}
int do_book(string arg)
{ object ob,gold;
  object me=this_player();
  gold=present("gold_money",this_player());
  if(!me->query("roomid")) return notify_fail(CYN"老板娘说道：您还没有自己的房子呢，买了家具往哪儿放啊？\n"NOR);
  if(!arg) return notify_fail(CYN"老板娘说道：您要买点什么家具？\n"NOR);
  if(!objectp(ob=present(arg,environment(me)))) return notify_fail(CYN"老板娘说道：您要买点什么家具？\n"NOR);
  if(!ob->query("is_jiaju"))
   {message_vision(CYN"$N瞪大了眼睛奇怪地看了$n一眼，吃吃笑道：“您要买。。。"+ob->query("name")+"？”\n"NOR,this_object(),me);
    return 1;}
  if(!gold||gold->query_amount()<10) return notify_fail("老板娘说道：您的金子不够了。\n");
  gold->add_amount(-10);
  me->add("jiaju",1);
  message_vision("$N定下一套"+ob->query("name")+"。\n",me);
  command("say 好，我们这就给您送过去。");
  destruct(ob);
return 1;
}

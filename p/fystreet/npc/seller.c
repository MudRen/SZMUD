#include <ansi.h>
// seller.c zip@hero 2000.1.27 �ϰ���
inherit NPC;
int do_list();
void create()
{	set_name("�ϰ���",({"seller"}));
	set("gender","Ů��");
        set("long","�Ҿ��̵��ϰ��\n");
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
command("say ��������Ҿ���ȫ��ÿ��ֻҪ 10 Gold��������㿴��");
   return 1;
}
int do_book(string arg)
{ object ob,gold;
  object me=this_player();
  gold=present("gold_money",this_player());
  if(!me->query("roomid")) return notify_fail(CYN"�ϰ���˵��������û���Լ��ķ����أ����˼Ҿ����Ķ��Ű���\n"NOR);
  if(!arg) return notify_fail(CYN"�ϰ���˵������Ҫ���ʲô�Ҿߣ�\n"NOR);
  if(!objectp(ob=present(arg,environment(me)))) return notify_fail(CYN"�ϰ���˵������Ҫ���ʲô�Ҿߣ�\n"NOR);
  if(!ob->query("is_jiaju"))
   {message_vision(CYN"$N�ɴ����۾���ֵؿ���$nһ�ۣ��Գ�Ц��������Ҫ�򡣡���"+ob->query("name")+"����\n"NOR,this_object(),me);
    return 1;}
  if(!gold||gold->query_amount()<10) return notify_fail("�ϰ���˵�������Ľ��Ӳ����ˡ�\n");
  gold->add_amount(-10);
  me->add("jiaju",1);
  message_vision("$N����һ��"+ob->query("name")+"��\n",me);
  command("say �ã�������͸����͹�ȥ��");
  destruct(ob);
return 1;
}
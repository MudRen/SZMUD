// Code of ShenZhou
// CHCHONG 2002/01/30
// npc: /d/changan/npc/guinu.c

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("��ū", ({ "guinu", "slave" }) );
        set("gender", "����" );
        set("title", "�컨���ܹ�");
        set("age", 32);
        set("long", 
            "���Ǻ컨������������µģ�û��������Ͳ����н���ķ��١�"
	    "������Ҳ�ɾ��˱���Ϊ潵Ļ��¡����������������ˣ������ǡ�\n");
        set("str", 65);
        set("dex", 35);
        set("con", 25);
        set("int", 25);
        set("shen_type", -1);

        set_skill("unarmed", 60);
	set_skill("force", 20);
        set_skill("dodge", 55);

        set("combat_exp", 95000);

        set("max_qi", 300);
        set("max_jing", 100);
        set("neili", 200);
        set("max_neili", 200);

        set("attitude", "friendly");
        set("inquiry", ([
            "name" : "��Ҳ��֪����ԭ����ʲô��",
            "�컨��" : "���Ǻ컨����ǳ�������ͷһ�ݵ�������ȥ����",
            "here" : "���Ǻ컨����ǳ�������ͷһ�ݵ�������ȥ����",
            "����" : "�ǿɲ��С���������Ĺ�����ҡǮ����������ӱ��ظ���Ǯ��",
	    "����" : "�ǿɲ��С���������Ĺ�����ҡǮ����������ӱ��ظ���Ǯ��",
            "����" : "������ǹ�����ⶼ��������ʲôҤ�ӡ�",
	    "����" : "order <ĳ����> <����emote> <ĳ��...��ʡ��>��ʮ�����������һ�Ρ�",
	    "service" : "order <ĳ����> <����emote> <ĳ��...��ʡ��>��ʮ�����������һ�Ρ�",
       ]) );

        setup();
        set("chat_chance", 5);
        set("chat_msg", ({
	"��ū����˵�����͹٣���ҪȱǮ���Ͱ������ã�Ů��ʲô�������������ɡ�\n",
	"��ū����˵������֮ǰ����������������ϰ��˭Ư��˭���������ü�Ǯ��\n",
	}) );
        carry_object("/d/city/obj/pink_cloth")->wear();
}
void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
//      add_action("do_sell","sell");
}

void greeting(object me)
{
    object * ob;
    int found,i;
    
    found = 0;
    
    if (me->query("hooker")) {
	command("say �ð���"+me->name() + "���һ�����Ҫ�ӵ�����أ����ֻ����ˣ�");
	command("say ��Ҫ�����Ҵ������ȣ�");
	return;
    }
    if (me->query("gender")!="����") {
      ob = all_inventory(environment());
      for(i=sizeof(ob)-1; (i>=0) && !found; i--) {
      if( !userp(ob[i]) ) continue;
      if (ob[i]->query("hooker")) {
         found = 1;
         command ("say "+ob[i]->name() + "�������������˻�����ӭ�ӣ� ");
         command ("kick " + ob[i]->query("id"));
      }
      }   
    }
    return ;
}
int price(object ob)
{
    int per, extra=1;

    per = ob->query("per")*100;
    if( ob->query_temp("top_girl") ) {
	extra = 10 ;
	per = ob->query("per")*1000;
    }
    return (ob->query("combat_exp")+per)*extra;
}

int do_sell(string arg)
{
    object ob;
    int value, p;

    string* name1s = ({
       "С", "��", "��", "��", "��", "��" });
    string* name2s = ({
       "��", "��", "��", "��", "��", "��", "Ҷ", "��", "��" });
    string* name3s = ({
       "���", "����", "����" });
    string nick;
    
    if (!arg || !(ob = present(arg, this_player())))
       return notify_fail("��Ҫ��˭��\n");
       
    if (!ob->is_character())
       return notify_fail("�������������ȥ��\n");
              
    if (!userp(ob))
       return notify_fail("����ֻ���������Ů��\n");
       
    if (ob->query("gender")!="Ů��")
       return notify_fail("��ԺĿǰ�������мˡ�\n");
      
    if (ob->query("hooker"))
       return notify_fail("���Ѿ������Ǻ컨������ˣ��㲻�������ˡ�\n");
       
    if ((value=ob->query("combat_exp")) < 100)
       return notify_fail("�����Ǹ������أ��ҿ�û���������\n");

    if( ob->query_temp("top_girl") ) {
	command("admire "+this_player()->query("id"));
	command("say ��εĻ�ɫ��������С��治����\n");
    }

    message_vision("$N��"+ ob->name()+"�����˺컨��\n", this_player());
    MONEY_D->pay_player(this_player(), p=price(ob));
    ob->set("lcy-price", p);
    this_player()->set("shen",this_player()->query("shen")-(value/100));
    this_player()->set("sell_woman/" + ob->query("id"), 1);

    ob->move(this_object());
    nick = name1s[random(sizeof(name1s))] + name2s[random(sizeof(name2s))]
           + name3s[random(sizeof(name3s))];
    if (ob->query("age")<18)       
        ob->set("title","�컨������");
    else if (ob->query("age")<25)
        ob->set("title","�컨��ͷ��");
    else if (ob->query("age")<45)
        ob->set("title","�컨��ʺ�");
    else ob->set("title","�컨����ϯ");
    if( ob->query_temp("top_girl") ) {
        ob->set("title",HIR"�컨�󻨿�"NOR);
	ob->delete_temp("top_girl");
    }
    ob->set("nickname",nick);
    command ("chat ���Ǻ컨�������ˡ�"+nick+ "��"+ob->name()+"����ӭ��λ��ү��ˣ�");
    ob->set("hooker",1); 
    return 1;
}
 
int accept_object(object me, object obj)
{
  int p;

  p = me->query("lcy-price");
  /* 
   * backward compatibility, for those players who are already hookers before
   * this code is written.  -chu
   */
  if (!p) p = price(me);   

  if(obj->query("money_id")) {
    if(me->query("hooker")) {
        if (obj->value()>= p*2)  {  
        command ("say �ðɣ��˸���־����Ҫ������Ҳ����ǿ���Ҹ����˼Ҽ��˰ɡ����Ǵ�һ�����ġ�");
        command ("cry "+me->query("id"));
        me->set("title",me->query("family/family_name")+"��"+
                chinese_number(me->query("family/generation"))+
                "������");
        command("bye "+me->query("id"));
        me->delete("hooker");
        return 1;
        }
        else {
        command("say лл"+me->query("nickname")+"��Ǯ��");
        command("bow "+ me->query("id"));
        return 1;
        }
    }
    else {
        command("say лл��Ǯ��");
        command("bow "+ me->query("id"));
	if (obj->value() >= 1000) {
		me->set_temp("money_given",1);
		command("thank " + me->query("id"));
	}
        return 1;
    }
  }
  else return 0;
} 

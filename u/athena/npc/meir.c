#include <ansi.h>
// ����ܰ(Athena)
// NPC��/u/athena/npc/meir.c

inherit NPC;
int give_hama();
int give_kiss();
int give_qi();
int give_baohe();
void create()
{
        set_name(HIW"õ��"NOR,({"mei er","meir"}));
        set("gender","Ů��");
        set("age",18);
        set("per",33);
        set("str",28);
        set("dex",22);
        set("con",30);
        set("int",23);
        set("attitude","friendly");
        set("long","���������ԣ���ɷ����Ȼ�ǳ�������֮ò��������֮�ˡ�\n");
         set("inquiry", (["hama":(: give_hama :), 
                      "qi":(:give_qi:),
                      "kiss":(:give_kiss:),
                      "baohe":(:give_baohe:),
                     "name" : "�Ҿ���ö����������գ�",
                    "where" : "�����������ܰ�����ĵط���" ,
                     "athena" : "����ܰ���������ڹ����𣿺�����ù�Ŷ��ϣ�������ܹ����֧��������" ,
]));
        setup();


        set("chat_chance", 2);
        set("chat_msg", ({
 "ö�������죬�����������������\n",
 "ö�������������������\n",
 "ö���������������һ��ʫ��һ�������޵�ʫ��\n",
 "ö��̾������������һ�׸裬��ƽ�����߳�Ȼ���ٹ���ƽ����\n",
 "ö����������������һ������һ��������һ�ɺ��������ɽ���������಻�ϡ�\n",
       }) );

        carry_object("/clone/special/qilin")->wear();
        carry_object("/d/city/obj/flower_shoe")->wear();
        carry_object("/d/city/obj/necklace-diamond")->wear();
       carry_object("/clone/special/yufenguan")->wear();
        carry_object("d/city/obj/pink_cloth")->wear();
        carry_object("/d/city/obj/ring-jade")->wear();
}
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
}
}
int give_hama()
{
       object ob;
       object me=this_player();
       if (me->query("id")=="athena")
{
      ob=new("/u/athena/obj/hama.c");
        message_vision("ö����$Nһ��" + HIC + ob->query("name") + NOR +"��\n", this_player());
      command("ok " + me->query("id"));
       ob->move(me);
      return 1;
}
              command("hmm2 " + me->query("id"));
      return 1;
}

      int give_qi() 
      { 
             object ob; 
             object me=this_player(); 
       if (me->query("id")=="athena")
      { 
            ob=new("/clone/wiz/mihun.c"); 
       message_vision("ö����$Nһ��" + NOR + ob->query("name") + NOR +"��\n", this_player());
            command("addoil " + me->query("id")); 
             ob->move(me); 
            return 1; 
      } 
                    command("sorry " + me->query("id")); 
                    command("say ������ʦר����Ʒ,���ܹ����㣡"); 
            return 1; 
      } 

int give_baohe()
{
       object ob;
       object me=this_player();
       if (me->query("id")=="athena")
{
            ob=new("/u/athena/obj/baohe.c"); 
      ob=new("/u/athena/obj/baohe.c");
        message_vision("ö����$Nһ��" + HIG + ob->query("name") + NOR +"��\n", this_player());
      command("congra " + me->query("id"));
       ob->move(me);
      return 1;
}
              command("kick5 " + me->query("id"));
      return 1;
}
int give_kiss()
{
       object ob;
       object me=this_player();
       if (me->query("id")=="athena")
       {
             say(name()+WHT"���۵��������������ˣ�ͷ�Ϻö��ɫ��С�������������ķ�����ȥ�� \n"NOR);
             command("shrug");
return 1;
            }
        command("slap " + me->query("id"));
        command("angry " + me->query("id"));
return 1;
}

void greeting(object ob)
{
        if (this_player()->query("id")=="athena")
{
       if( !ob || !visible(ob) || environment(ob) != environment() ) return;
           say(name()+"˵�������Չ�ܰ�������������  \n"NOR);
                 command("massage athena");
                     }
else
{
        if( !ob || !visible(ob) || environment(ob) != environment() )
          return;
               say(name()+HIG"˵��������ã���ӭ����!��  \n"NOR);
}
}

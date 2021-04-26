//write by rama@sz
//28/02/2002
#include <ansi.h>
#include "auto_perform.h"
inherit NPC;
int ask_ding(object me);
int do_sou(string arg);
int random_place(object me,string* dirs,int i);
void create()
{
        set_name("����", ({ "a zi" }) );
        set("title","���԰�");        
        set("gender", "Ů��" );
        set("long","
һλò���绨��С��������۾������ƺ�͸©��һ��а����\n");
        set("age",18);
        set("attitude", "peaceful");  
        set("shen_type", -1);  
        set("str", 18);  
        set("int", 28);  
        set("con", 20);  
        set("dex", 24);  
        set("eff_qi", 5000);  
        set("max_qi",5000); 
        set("neili", 5000);
        set("max_neili", 5000);  
        set("jiali", 200);  
        set("combat_exp", 1000000);  
        set("score", 10000);  
        set_skill("force", 200);  
        set_skill("huagong-dafa", 225);  
        set_skill("dodge", 300);  
        set_skill("feixing-shu", 260);  
        set_skill("poison", 240);  
        set_skill("zhaixinggong", 240);  
        set_skill("claw", 240);  
        set_skill("sanyin-zhua", 240);  
        set_skill("strike", 230);  
        set_skill("chousui-zhang", 240);  
        set_skill("parry", 220);  
        set_skill("staff", 220);  
        set_skill("literate", 230);  
          
        map_skill("force", "huagong-dafa");  
        map_skill("dodge", "zhaixinggong");  
        map_skill("strike", "chousui-zhang");  
        map_skill("claw", "sanyin-zhua");  
        map_skill("parry", "chousui-zhang");  
            
        prepare_skill("strike", "chousui-zhang");  
        prepare_skill("claw", "sanyin-zhua");  
          
        create_family("������", 2, "����");  


        set("inquiry", ([
                "name" : "��ܲ��š�\n",
                "here" : "��������в��ǲ��ǣ�û��������æ��ô��\n",
                "��ľ����" : (: ask_ding :),
                "ding" : (: ask_ding :),
        ]) );
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({  
                            (: auto_perform :),  
                    }) );  

        setup();
        carry_object("/d/xingxiu/obj/xxqingxin-san");  
        carry_object("/d/xingxiu/obj/yellow-cloth")->wear();  
        carry_object("/d/xingxiu/obj/blzhen");  
        carry_object("/d/xingxiu/obj/lianxin");  

}
int ask_ding(object me)
{
         if(me->query("family/family_name") != "������")
         {  
                    say("����˵�������ⶫ���ɲ��Ǹ����õġ���\n");
                    return 0;
                    }  

        if ((int)me->query_temp("mark/ding") < 1){
                        me->set_temp("mark/ding", 1 ); 
                        }
                        
        me->add_temp("mark/ding", 1 );
        if ((int)me->query_temp("mark/ding") >= 5+random(5))
                        {
                        say("����˵�������������ô��ô������ľ�������ǲ��������ϣ��������ѣ�sou���Һ��ˡ�\n");
                        add_action("do_sou","sou");
                        return 1;
                }
                else {
                say("����˵����ʲô��ľ�������ҿ�û�á��������ԩ�����ˣ�\n"); }
                return 1;
}
int do_sou(string arg)
{
    object me,ob1,ob2;
    ob2=this_object();
    me = this_player();
        if( !arg || arg=="" ) return 0;
        if( arg=="a zi" ) 
    {
        message("vision",
            me->name() + "��Ц��˵�������ã����ҾͲ������ˡ���\n",
            environment(me),({me}));
        say("���ϴ���������"+HIR"�������ң��������������ң�����"NOR+"\n");
        ob2->kill_ob(me);
        ob2->set_leader(me);
        ob1=present("xiao feng");
        if(!ob1)
        {
                seteuid(getuid());
                ob1=new("/u/rama/npc/xiaofeng");
                ob1->move(environment());
        }
        message_vision("\n���ش���һ��ŭ�ȣ���������˴�!���ϲ����£��н���ڿ�˭���۸��㣿��\n\n",me);
        me->set("azi/killer2",1);
        ob1->kill_ob(me);
        ob1->set_leader(me);
        me->fight_ob(ob1);
        me->fight_ob(ob2);
        remove_action("do_sou","sou");          
        return 1; 
        }
}

int random_place(object me,string* dirs,int i)
{

        int j,k,m;
        object  newob;
        mixed*  file;

        me=this_object();

        if( !sizeof(dirs) )  return 1;

        file = get_dir( dirs[i]+"*.c",-1);
        if( !sizeof(file) )             return 1;

        k = sizeof(file);

      while(1)  {
           j = random(k);
           if( file[j][1] > 0 )         break;     
                  }

     if( (newob=load_object(dirs[i]+file[j][0])) ) 
        j = random(k);

     if( (newob=load_object(dirs[i]+file[j][0])) )

          {
                me->move( newob );
          }

        else  {
                seteuid(getuid(me));
                newob = load_object(dirs[i]+file[j][0]);
                if (newob)   
                        me->move(newob);
        else   {
                        tell_object(me, "�����ˣ���֪ͨrama.\n");
                }
        }  
        return 1;

}

void accept_kill(object me)
{ 
        object ob;
        object ob1;
        if( is_fighting()) return;
        say("\n���ϴ�У���������������Ҫɱ�ң���\n\n");
        this_object()->kill_ob(me);
        me->fight_ob(this_object());
        seteuid(getuid());
        ob1=present("xiao feng");
        ob=present("you tanzhi");
        if(!ob)
        {
                seteuid(getuid());
                ob=new("/u/rama/npc/you");
        }
        if(!ob1)
        {
                seteuid(getuid());
                ob1=new("/u/rama/npc/xiaofeng");
        }
        ob->move(environment());
        ob1->move(environment());
        message_vision("\n�������̹֮���һ������ס�����ȥ·��\n\n",me);
        me->set("azi/killer2",1);
        ob->kill_ob(me);
        ob1->kill_ob(me);
        ob->set_leader(me);
        ob1->set_leader(me);
        me->fight_ob(ob);
        me->fight_ob(ob1);
        return;
}
void accept_fight(object me)
{
        say("�����۾�һ�ɣ����Ҳ�û�պ�������أ���\n");
        return;
}
void die()
{
        object me=this_player();
        me->set("azi/killer",1);
        
        ::die();
}

       


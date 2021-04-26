

#include <ansi.h>
#include <command.h>
inherit NPC;
void consider();
int do_gongzuo();
int ask_done();

mapping *chuaimo = ({ 
         ([ "chuaimo":"��������","where":"hangzhou"   ]),
         ([ "chuaimo":"���Ĺ�","where":"xixia"]),   
         ([ "chuaimo":"���ϴ���","where":"dali"]),   
         ([ "chuaimo":"����Ȫ��","where":"quanzhou"]),   
                   });
mapping query_chuaimo()
{
        return chuaimo[random(sizeof(chuaimo))];
}

void create()
{
        set_name("�ⷿ����", ({"kufang xiansheng", "kufang", "xiansheng"}));
        set("gender", "����");
        set("age", 55);
        set("title", "�����������ܹ�");
        set("long", 
                "�����������ƹܿⷿ����������Ϊ�����������ʥ����������С���ӹ�������������ϰ�ٻ����ա�\n");
        set("qi", 100);
        set("max_qi", 100);
        set("jing", 100);
        set("max_jing", 100);
        set("per", 25);
        
        set("combat_exp", 1500);
        set("score", 200);
        
        set("inquiry", ([
                "����" : (: do_gongzuo :),
                "job"  : (: do_gongzuo :),
                "work" : (: do_gongzuo :),
                "���" : (: ask_done    :),
                "����" : (: ask_done    :),
        ]) );

        setup();
        carry_object("clone/armor/cloth")->wear();
}
int do_gongzuo()
{      
        mapping chuaimo,chuaimowhere;
        object me,ob;
        me = this_player(); 
        
    if( me->query_temp("obj/chuaimo")>0)
    {
                  tell_object(me,CYN"�ⷿ������������ĥ��ʲô���Ҳ������㵽"+chuaimo["chuaimo"]+"����ȥ��Ħ����?������ȥ��\n"NOR);
                tell_object(me,CYN"�ⷿ����ͣ��һ����˵��Ҫ������˹������ͻظ���"HIW"ask xiansheng about ���"NOR"�ˡ�\n"NOR);
                return 1;
    } 
    else 
      if( me->query("combat_exp")>2000000)
    {
                tell_object(me,"�ⷿ����˵�������Ѿ�����С�����ˣ���ȥ��Щ���������ˡ�\n");
                return 1;
    }

    else
              if(me->query("fam/family_name")!= "������" && me->query("combat_exp")>=100000)
        {
              message_vision("�ⷿ������æ��$N����һҾ��˵���������������ͼ����أ�\n",me);
        return 1;
               }

    chuaimo = this_object()->query_chuaimo();
    chuaimowhere = chuaimo["where"];
    message_vision(CYN"�ⷿ������$N˵�������ȥ" + chuaimo["chuaimo"] + "����ת��һ�°ɡ�\n�Ҹ��羰�õĵط������������㴧Ħ���ա�\n"NOR,me); 
    message_vision("�ⷿ��������$Nһ��"HIW"�ٻ�����"NOR"��\n",me); 
    
        me->set_temp("obj/chuaimo", 1);
        me->set_temp("obj/where",chuaimowhere);
            ob=new(__DIR__"xingnang");
        ob->move(me);
        return 1;   
}

int ask_done()
{      

        object me,ob;
        me = this_player(); 
        
    if( me->query_temp("obj/chuaimo")< 1)
    {
                tell_object(me,"����˭������û�������񣬱���Ϲ���͡�\n");
                return 1;
    } 
    if( me->query_temp("obj/done")< 1)
    {
                tell_object(me,"�����Ϲ�ε���һ�죬����û�г����ɣ�\n");
                return 1;
    }
    message_vision(CYN"�ⷿ������$N˵����Ŷ�������ˣ��ǾͰѶ��������Ұɡ�\n"NOR,me); 
    me->delete_temp("obj");
    me->add("combat_exp",me->query("kunlun/jlexp"));
    me->add("potential",50+random(60));
    if( me->query("potential") > me->query("max_potential") ) me->set("potential",me->query("max_potential") ); 

    me->improve_skill("qinqi-shuhua",200);
    
      if (ob = present("xingnang", this_player()))
    {
       message_vision("�ⷿ������"HIW"�ٻ�����"NOR"�ջ�ȥ�ˡ�\n",me);
       destruct(ob);
    }
    return 1;
}

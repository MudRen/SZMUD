

#include <ansi.h>
#include <command.h>
inherit NPC;
void consider();
int do_gongzuo();
int ask_done();

mapping *changxi = ({ 
         ([ "changxi":"����","where":"city"   ]),
         ([ "changxi":"Ȫ��","where":"quanzhou"]),   
                   });
mapping query_changxi()
{
        return changxi[random(sizeof(changxi))];
}

void create()
{
        set_name("����", ({"guan shi", "guan", "guanshi"}));
        set("gender", "����");
        set("age", 35);
        set("title", HIW"�ն������������"NOR);
        set("long", 
                "���Ǳ�����ϷԺ�Ĺ��£���͢ί������������һ����ˣ���ձ��ݡ�\n");
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
        mapping changxi,changxiwhere;
        object me,ob;
        me = this_player(); 
        
    if( me->query_temp("obj/changxi")>0)
    {
                tell_object(me,CYN"������������ĥ��ʲô��������ȥ��\n"NOR);
                return 1;
    } 
    else 
    if( me->query("combat_exp")>100000)
    {
                tell_object(me,"����˵�������Ѿ�����С�����ˣ���ȥ��Щ���������ˡ�\n");
                return 1;
    }
    changxi = this_object()->query_changxi();
    changxiwhere = changxi["where"];
    message_vision(CYN"���¶�$N˵�������ȥ" + changxi["changxi"] + "�����Ľֵ��ϱ���һ�°ɡ�\n"NOR,me); 
    message_vision("���·Ը����¸���$Nһ��"CYN"���ݵ���"NOR"��\n",me); 
    
        me->set_temp("obj/changxi", 1);
        me->set_temp("obj/where",changxiwhere);
        ob=new(__DIR__ "daoju");
        ob->move(me);
        return 1;   
}

int ask_done()
{      

        object me,ob;
        me = this_player(); 
        
    if( me->query_temp("obj/changxi")< 1)
    {
                tell_object(me,"û�ɻ����Ҫ���ꣿ�����С���ұ���ץ�㣡\n");
                return 1;
    } 
    if( me->query_temp("obj/done")< 1)
    {
                tell_object(me,"�㻹û���ݣ�������������ǲ��ǣ�\n");
                return 1;
    }
    message_vision(CYN"���¶�$N˵����Ŷ�������ˣ��ǾͰѶ��������Ұɡ�\n"NOR,me); 
    me->delete_temp("obj");
        me->add("combat_exp",me->query("kljob/jlexp"));
      me->add("potential",100+random(100));
    if(me->query("potential")>me->query("max_potential"))
        me->set("potential",me->query("max_potential"));
log_file("/job/changxi",sprintf("[%s] %s(%s) ����Ϸ�����õ� %d �㾭��\n", ctime(time()), me->name(), getuid(me), me->query("kljob/jlexp"))); //add log file.  

    
	if(ob = present("biaoyan daoju", this_player()))
    {
       message_vision("���·Ը����˰ѱ��ݵ����ջ�ȥ�ˡ�\n",me);
       destruct(ob);
       return 1;
    }
    return 1;
}

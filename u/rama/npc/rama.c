//rama.c

inherit NPC;

#include <ansi.h>

void create()
{
        set_name("�����",({"zhu geliang","zhu"}) );
        set("long","һ��ɵɵ�Ĵ��С�\n");
        set("title","��Ʊ���");
        set("gender","����");
        set("age",20);
        set("combat_exp",100);
        set("inquiry",([
                "Ʊ" : "������ѡƱ��������һ�š�",
                "piao" : "������ѡƱ��������һ�š�",
                "������ѡƱ" : "������ѡƱ��������һ�š�",
                "ѡƱ" : "������ѡƱ��������һ�š�",
                
                ]) );
        setup();
}


int accept_object(object who,object ob)
{
        object obj,ob2;
        
        if( present("xuan piao",who) || who->query("ask/piao",1) )
        {
                tell_object(who,"�����Ц��������Ǯ�Ҿ����ţ�����Ʊ�ǲ����ٸ����ˡ���\n");
                return 1;
        }
                        
        if( who->query("age") < 15)
        {
                command("heihei");
                tell_object(who,"�����������ɫ�����������ϴ󽻴��������������������ѡƱ��\n");
                return 0;
        }
                        
        if( ob->query("money_id") && ob->value() < 50)
                return notify_fail("�����������һ�۵�������ô��Ǯ����ʲô������\n");
                
        if( ob->query("money_id") && ob->value() >= 50)
        {
                tell_object(who,"����������ֿ��˻�����æ����Ʊ�������ϵ�Ʊ����\n");
                tell_object(who,"�����������һ�ű������ѡƱ��\n");
                obj=new("/u/rama/obj/piao");
                obj->move(who);
                who->set("ask/piao",1);
                destruct(ob);
                this_object()->add("balance",50);
                return 1;
        }
        if( !ob->query("money_id"))
                return notify_fail("������ӹ�"+ob->query("name")+"��ϸϸ�Ŀ��˿���������ָ������Ȼ�󻹸�����,��Ȼ�ǲ�ʶ����\n");
}
int accept_kill(object me)
{
        tell_object(me,"��������һ���������ң������ϴ����ţ���\n");
        return 0;
}
void accept_fight(object me)
{
        tell_object(me,"������۾�һ�ɣ����Ҳ�û�պ�������أ���\n");
        return;
}
        
        
                
        
        
        

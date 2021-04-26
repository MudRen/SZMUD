#include <weapon.h>    
#include <ansi.h>   

inherit SWORD;
inherit F_UNIQUE;
void create() 
{
        set_name(MAG"��ϼ��"NOR,({ "zixia jian", "sword" }) );  
        set_weight(15000);
        if( clonep() )       
                set_default_object(__FILE__);  
        else { 
                set("treasure", 1); 
                set("unit", "��");
                set("value", 500000);  
                set("unique", 1);  
                set("rigidity", 7);   
                set("sharpness", 7); 
                set("weapon_prop/dodge", 5);   
                set("weapon_prop/parry", 5); 
                set("material", "steel");   
                set("wield_neili", 100);   
                set("wield_maxneili", 2000);  
                set("wield_str", 25); 
                set("wield_msg",MAG"ֻ������ৡ���һ����$N΢΢һЦ����������ϼ�⣬��ϼ��������$N�����У�\n"NOR);          
                set("long", MAG"�������������������һ����ϼ����������š���ϼ�������� 
����ҵ���˪����Ӧ�ÿ��Խ����ѱ���(��)������\n"NOR);
                set("unwield_msg", MAG"��ϼ�����շɳ����ַɻ���$N�����С�\n"NOR);
        }      
        init_sword(400);  
        setup();
}  

void init()   
{
    add_action("do_add", "��"); 
    add_action("do_add", "he");   
}

int do_add()   
{
     object me,ob,obj,jj;    
     me = this_player(); 
     ob = this_object();
     obj = present("sword", me);  
     if(!objectp(obj)) 
           return notify_fail("������ֻ��һ����ϼ�������ҵ���һ����˵�ɡ�\n");  
     if((int)me->query("neili") < 500) 
                return notify_fail("��о�ȫ����Ѫ���ڣ�ԭ���������������޷���˫���ϲ���\n");        
     if((int)me->query_str() < 28)
                return notify_fail("��о�ȫ����Ѫ���ڣ�ԭ���������������޷���˫���ϲ���\n");  
     me->add("neili", -300); 
     message_vision(HIW"$N˫��һ�ϣ�һ����⣬��������˫�����\n"NOR, me);
     destruct(obj);  
     jj = new("/u/aya/obj/ziqing")->move(me, 1); 
     destruct(ob); 
     return 1;    
}
